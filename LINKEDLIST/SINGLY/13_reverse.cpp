#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <string>
#include <netinet/in.h>
#include <unistd.h>

std::queue<std::string> taskQueue;
std::mutex queueMutex;
std::condition_variable taskAvailable;

void handleWorker(int workerSocket)
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(queueMutex);
        taskAvailable.wait(lock, []
                           { return !taskQueue.empty(); });

        std::string task = taskQueue.front();
        taskQueue.pop();
        lock.unlock();

        send(workerSocket, task.c_str(), task.size(), 0);

        char buffer[1024] = {0};
        read(workerSocket, buffer, 1024);
        std::cout << "Received result from worker: " << buffer << std::endl;
    }
}

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    std::vector<std::thread> workerThreads;

    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) >= 0)
    {
        workerThreads.emplace_back(handleWorker, new_socket);
    }

    for (auto &th : workerThreads)
    {
        if (th.joinable())
        {
            th.join();
        }
    }

    return 0;
}