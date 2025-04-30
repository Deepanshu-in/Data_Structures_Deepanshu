#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <iomanip>
#include <optional>
#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>

// Order structure
struct Order
{
    std::string id;
    double price;
    int quantity;
    bool isBuy; // To know if an order is of type buy or sell
    std::chrono::system_clock::time_point timestamp;

    Order(std::string id, double price, int quantity, bool isBuy)
        : id(std::move(id)), price(price), quantity(quantity), isBuy(isBuy),
          timestamp(std::chrono::system_clock::now()) {}
};

class OrderBook
{
private:
    // Price to total quantity maps (sorted for price-time priority)
    std::map<double, int, std::greater<>> buyLevels; // Descending for buys
    std::map<double, int, std::less<>> sellLevels;   // Ascending for sells

    // Order ID to Order mapping for fast lookup
    std::unordered_map<std::string, Order> orders;

    // Cache best prices for O(1) access
    std::optional<double> bestBidPrice;
    std::optional<double> bestAskPrice;

    // Statistics
    int totalOrders = 0;
    int totalVolume = 0;
    double highestPrice = 0.0;
    double lowestPrice = std::numeric_limits<double>::max();
    std::vector<std::pair<std::string, double>> executedTrades;

public:
    // Add new order - O(log n)
    bool addOrder(std::string id, double price, int quantity, bool isBuy)
    {
        if (price <= 0 || quantity <= 0)
            return false;

        // Check for matching orders and execute trades
        if (isBuy && bestAskPrice.has_value() && price >= bestAskPrice.value())
        {
            executeTrade(price, quantity, isBuy);
            return true;
        }
        else if (!isBuy && bestBidPrice.has_value() && price <= bestBidPrice.value())
        {
            executeTrade(price, quantity, isBuy);
            return true;
        }

        // Store new order with isBuy flag
        orders.emplace(id, Order(id, price, quantity, isBuy));
        totalOrders++;
        totalVolume += quantity;

        // Update price levels
        if (isBuy)
        {
            buyLevels[price] += quantity;
            if (!bestBidPrice.has_value() || price > bestBidPrice.value())
            {
                bestBidPrice = price;
            }
        }
        else
        {
            sellLevels[price] += quantity;
            if (!bestAskPrice.has_value() || price < bestAskPrice.value())
            {
                bestAskPrice = price;
            }
        }

        // Update price range
        highestPrice = std::max(highestPrice, price);
        lowestPrice = std::min(lowestPrice, price);

        return true;
    }

    // Cancel order - O(log n)
    bool cancelOrder(const std::string &id)
    {
        auto it = orders.find(id);
        if (it == orders.end())
            return false;

        const auto &order = it->second;

        if (order.isBuy)
        {
            // Update buy levels
            buyLevels[order.price] -= order.quantity;
            if (buyLevels[order.price] <= 0)
            {
                buyLevels.erase(order.price);
            }
        }
        else
        {
            // Update sell levels
            sellLevels[order.price] -= order.quantity;
            if (sellLevels[order.price] <= 0)
            {
                sellLevels.erase(order.price);
            }
        }

        // Update order count and volume
        totalOrders--;
        totalVolume -= order.quantity;

        // Remove order
        orders.erase(id);

        // Update best prices
        updateBestPrices();

        return true;
    }

    // Execute trade between matching orders
    void executeTrade(double price, int quantity, bool isBuy)
    {
        if (isBuy)
        {
            // Buy order matching with sell orders
            if (sellLevels.empty())
                return;

            auto execPrice = sellLevels.begin()->first;
            auto execQty = std::min(quantity, sellLevels.begin()->second);

            // Update sell level
            sellLevels[execPrice] -= execQty;
            if (sellLevels[execPrice] <= 0)
            {
                sellLevels.erase(execPrice);
            }

            // Record the trade
            std::string tradeId = "T" + std::to_string(executedTrades.size() + 1);
            executedTrades.emplace_back(tradeId, execPrice);

            std::cout << "EXECUTED: " << tradeId << " | Price: " << execPrice
                      << " | Quantity: " << execQty << " | Side: BUY" << std::endl;
        }
        else
        {
            // Sell order matching with buy orders
            if (buyLevels.empty())
                return;

            auto execPrice = buyLevels.begin()->first;
            auto execQty = std::min(quantity, buyLevels.begin()->second);

            // Update buy level
            buyLevels[execPrice] -= execQty;
            if (buyLevels[execPrice] <= 0)
            {
                buyLevels.erase(execPrice);
            }

            // Record the trade
            std::string tradeId = "T" + std::to_string(executedTrades.size() + 1);
            executedTrades.emplace_back(tradeId, execPrice);

            std::cout << "EXECUTED: " << tradeId << " | Price: " << execPrice
                      << " | Quantity: " << execQty << " | Side: SELL" << std::endl;
        }

        // Update best prices
        updateBestPrices();
    }

    // O(1) access to best prices
    std::optional<double> getBestBid() const { return bestBidPrice; }
    std::optional<double> getBestAsk() const { return bestAskPrice; }

    // Calculate spread - O(1)
    double getSpread() const
    {
        if (!bestBidPrice.has_value() || !bestAskPrice.has_value())
            return -1.0;
        return bestAskPrice.value() - bestBidPrice.value();
    }

    // Print market depth
    void displayMarketDepth(int levels = 5) const
    {
        std::cout << "\n===== MARKET DEPTH =====\n";

        // Display sell levels (ascending)
        std::cout << "SELL LEVELS:\n";
        int count = 0;
        for (auto it = sellLevels.begin(); it != sellLevels.end() && count < levels; ++it, ++count)
        {
            std::cout << std::fixed << std::setprecision(2)
                      << it->first << " | " << it->second << "\n";
        }

        // Display spread
        std::cout << "-------------------\n";
        if (bestBidPrice.has_value() && bestAskPrice.has_value())
        {
            std::cout << "Spread: " << std::fixed << std::setprecision(2) << getSpread() << "\n";
        }
        else
        {
            std::cout << "Spread: N/A\n";
        }
        std::cout << "-------------------\n";

        // Display buy levels (descending)
        std::cout << "BUY LEVELS:\n";
        count = 0;
        for (auto it = buyLevels.begin(); it != buyLevels.end() && count < levels; ++it, ++count)
        {
            std::cout << std::fixed << std::setprecision(2)
                      << it->first << " | " << it->second << "\n";
        }
    }

    // Display order book statistics
    void displayStats() const
    {
        std::cout << "\n===== ORDER BOOK STATS =====\n";
        std::cout << "Total orders: " << totalOrders << "\n";
        std::cout << "Total volume: " << totalVolume << "\n";
        std::cout << "Price range: " << lowestPrice << " - " << highestPrice << "\n";
        std::cout << "Total trades executed: " << executedTrades.size() << "\n";
    }

private:
    // Update best prices cache
    void updateBestPrices()
    {
        bestBidPrice = buyLevels.empty() ? std::nullopt : std::make_optional(buyLevels.begin()->first);
        bestAskPrice = sellLevels.empty() ? std::nullopt : std::make_optional(sellLevels.begin()->first);
    }
};

int main()
{
    OrderBook book;

    std::cout << "Simulating market data feed...\n\n";

    // 1. Initial orders - Bullish sentiment
    book.addOrder("B1", 100.50, 200, true);
    book.addOrder("B2", 100.25, 150, true);
    book.addOrder("S1", 100.75, 100, false);
    book.addOrder("S2", 101.00, 300, false);

    std::cout << "Initial market state (bullish):\n";
    book.displayMarketDepth();

    // Simulate time delay
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    // 2. More selling pressure - Bearish shift
    book.addOrder("S3", 100.60, 250, false); // Tighter spread
    book.cancelOrder("B1");                  // Remove best bid
    book.addOrder("S4", 100.55, 100, false); // Even lower ask

    std::cout << "\nUpdated market state (bearish):\n";
    book.displayMarketDepth();

    // Simulate time delay
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    // 3. Matching trade execution
    std::cout << "\nExecuting matching trades:\n";
    book.addOrder("B3", 100.60, 150, true); // This will match with S3

    // 4. Final market state
    std::cout << "\nFinal market state:\n";
    book.displayMarketDepth();
    book.displayStats();

    return 0;
}