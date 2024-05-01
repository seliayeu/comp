#include <algorithm>
#include <cassert>
#include <climits>
#include <deque>
#include <iostream>
#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

// void bfs(vector<vector<int>> &graph, set<int> &possible, const int &goal) {
//     vector<int> q, tmp;
//     q.push_back(0);
//
//     int dist = -1;
//
//     while (q.size() > 0) {
//         dist += 1;
//         tmp.clear();
//         while (q.size() > 0) {
//             int node = q.back();
//             q.pop_back();
//             if (node == goal)
//                 possible.insert(dist);
//             for (int neighbor : graph[node])
//                 tmp.push_back(neighbor);
//         }
//         q = tmp;
//     }
// }

set<int> &dumbDfs(vector<vector<int>> &graph, unordered_map<int, set<int>> &dp,
                  int curr, const int &goal) {
    if (dp.find(curr) != dp.end()) {
        return dp[curr];
    }

    set<int> dists = {};
    for (auto neigh : graph[curr]) {
        for (auto dist : dumbDfs(graph, dp, neigh, goal)) {
            dists.insert(dist + 1);
        }
    }

    dp[curr] = dists;
    return dp[curr];
}

// bool dfs(vector<vector<int>> &graph, set<int> &possible, set<int> &badNodes,
//          int dist, int curr, const int &goal) {
//     if (curr == goal) {
//         possible.insert(dist);
//         return true;
//     }
//     if (badNodes.find(curr) != badNodes.end())
//         return false;
//
//     bool found = false;
//     for (auto neigh : graph[curr])
//         found |= dfs(graph, possible, badNodes, dist + 1, neigh, goal);
//
//     if (found)
//         return true;
//     else {
//         badNodes.insert(curr);
//         return false;
//     }
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n1, n2, m1, m2;
    cin >> n1 >> n2 >> m1 >> m2;

    vector<vector<int>> graph1(n1, vector<int>()), graph2(n2, vector<int>());

    for (int i = 0; i < m1; ++i) {
        int a, b;
        cin >> a >> b;
        graph1[a - 1].push_back(b - 1);
    }

    for (int i = 0; i < m2; ++i) {
        int a, b;
        cin >> a >> b;
        graph2[a - 1].push_back(b - 1);
    }

    // set<int> possible1, possible2;

    // bfs(graph1, possible1, n1 - 1);
    // bfs(graph2, possible2, n2 - 1);
    //
    // set<int> badNodes1, badNodes2;
    // dfs(graph1, possible1, badNodes1, 0, 0, n1 - 1);
    // dfs(graph2, possible2, badNodes2, 0, 0, n2 - 1);
    unordered_map<int, set<int>> dp1, dp2;
    dp1[n1 - 1] = {0};
    dp2[n2 - 1] = {0};
    dumbDfs(graph1, dp1, 0, n1 - 1);
    dumbDfs(graph2, dp2, 0, n2 - 1);

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int steps;
        cin >> steps;

        for (int j = 0; j <= steps; ++j) {
            if (dp1[0].find(j) != dp1[0].end() &&
                dp2[0].find(steps - j) != dp2[0].end()) {
                cout << "Yes" << endl;
                break;
            } else if (j == steps) {
                cout << "No" << endl;
            }
        }
    }
}
