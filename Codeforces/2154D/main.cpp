#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

bool dfs(const unordered_map<int, vector<int>>& tree, unordered_map<int, int>& heightMap, vector<int>& path, int parent, int start, int target, int height) {
    if (start == target) {
        path.push_back(start);
    }

    auto& nodes{ tree.at(start) };
    bool hadTrue{ false };

    for (auto& node : nodes) {
        if (node == parent)
            continue;
        hadTrue |= dfs(tree, heightMap, path, start, node, target, height + 1);
    }

    if (hadTrue) {
        path.push_back(start);
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int k{};
    cin >> k;

    while (k-- > 0) {
        int n{};
        unordered_map<int, vector<int>> tree;
        unordered_map<int, int> heights;
        cin >> n;
        
        for (int i = 0; i < n - 1; ++i) {
            int u{}, v{};
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        vector<int> path{}, destroy{};
        dfs(tree, heights, path, -1, 1, n, 0);

        int ind{ 0 };
        while (true) {
            
            // if ind < maxheight - 1
            //  delete biggest sub tree not containing target
            //  move 
            // else
            //  delete biggest 
        }
    }
}

/* 2
 * 1 2
 * 2 1
 * 3 2 // repeated
 * 3
 * 1: 2
 * 2: 1, 3
 * 3: 2 // repeated
 * 4
 * 1: 2,
 * 2: 1, 3
 * 3: 2, 4
 * 4: 1, 3 // repeated
 * 5
 * 1: 2,
 * 2: 1, 3
 * 3: 2, 4
 * 4: 1, 3, 5
 * 5: 2, 4 // repeated
 * 6
 * 1: 2,
 * 2: 1, 3
 * 3: 2, 4
 * 4: 1, 3, 5
 * 5: 2, 4, 6
 * 6: 1, 3, 5 // repeated
 * 7
 * 1: 2,
 * 2: 1, 3
 * 3: 2, 4
 * 4: 1, 3, 5
 * 5: 2, 4, 6
 * 6: 1, 3, 5, 7
 * 7: 2, 4, 6 // repeated
 * case: height 10 with each node having 4 children -> assume cat on height 2
 * bottom one: 4^9 nodes -> gotta get rid of all of them -> need 2x 1 between each -> need 1x 2 to destroy -> 3x 4^9 to get rid of height 10. 
 * next -> 4^8 -> gotta kill all 3x4^8
 * next -> ...
 * finally have tree of height 2. pretty easy now: when move to 1: kill 
 *
 * harder case: 
 */
