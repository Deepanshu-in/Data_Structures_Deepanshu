#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<vector<int>> v;
vector<int> vis, par, tmp;

int solve(vector<int> &maze, int n) {
    int maxSum = -1;

    for (int i = 0; i < n; i++) {
        int node = i;
        int sum = 0;
        unordered_set<int> visited;

        while (node < n && node >= 0 && i != maze[node] && visited.count(node) == 0) {
            visited.insert(node);
            sum += node;
            node = maze[node];
        }

        if (node >= 0 && node < n && i == maze[node]) {
            maxSum = max(maxSum, sum);
        }
    }

    return maxSum;
}

void solution_function()
{
    int N;
    cin >> N;
    vector<int> Edge(N);
    for (int i = 0; i < N; i++) {
        cin >> Edge[i];
    }
    int ans = solve(Edge, N);
    cout << ans;
}
int main() {
    solution_function();
    return 0;
}
