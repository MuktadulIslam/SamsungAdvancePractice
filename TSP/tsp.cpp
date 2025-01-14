#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;
int n;

// Function to solve TSP using Dynamic Programming (Held-Karp)
int heldKarp(int n, vector<vector<int>> &dist) {
    // dp[mask][i]: Minimum cost to visit all nodes in 'mask' and end at node 'i'
    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));

    // Base case: Starting from node 0
    dp[1][0] = 0;

    // Iterate through all subsets of nodes
    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i))) continue; // Skip if 'i' is not in 'mask'

            for (int j = 0; j < n; ++j) {
                if (i == j || !(mask & (1 << j))) continue; // Skip invalid transitions

                int prevMask = mask ^ (1 << i); // Remove 'i' from the current mask
                dp[mask][i] = min(dp[mask][i], dp[prevMask][j] + dist[j][i]);
            }
        }
    }

    // Find the minimum cost of completing the tour
    int minCost = INT_MAX;
    for (int i = 1; i < n; ++i) {
        minCost = min(minCost, dp[(1 << n) - 1][i] + dist[i][0]);
    }

    return minCost;
}

int main() {
    cout << "Enter the number of nodes (N): ";
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));
    cout << "Enter the distance matrix (NxN):\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
        }
    }

    int result = heldKarp(n, dist);
    cout << "The minimum cost of the TSP tour is: " << result << endl;

    return 0;
}

