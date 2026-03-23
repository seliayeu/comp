#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<string, int> ids;
    
    string s;
    getline(cin, s);
    int n;
    cin >> n;
    getline(cin, s);

    vector<vector<int>> g(n);
    vector<string> as(n);

    int id{ 0 };
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        as[i] = s;
    
        auto sIter{ s.begin() }, eIter{ s.begin() };
        while ((eIter = find(sIter, s.end(), ',')) != s.end()) {
            auto subs{ string(sIter, eIter) };
            if (ids.count(subs) == 0)
                ids[subs] = id++;
            sIter = eIter + 1;
            g[i].push_back(ids[subs]);
        }
        auto subs{ string(sIter, eIter) };
        if (ids.count(subs) == 0)
            ids[subs] = id++;
        g[i].push_back(ids[subs]);
    }

    vector<int> changes(n, 0);

    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < g[0].size(); ++j) {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    for (int i = 0; i < n; ++i) {
        int c{ 0 };
        for (int j = i + 1; j < n; ++j) {
            c = 0;
            for (int k = 0; k < g[0].size(); ++k) {
                if (g[i][k] != g[j][k])
                    c++;
            }
            changes[i] = max(c, changes[i]);
            changes[j] = max(changes[j], c);

            // cout << "changes of " << i << " is now " << changes[i] << endl;
        }
    }

    auto iter{ std::min_element(changes.begin(), changes.end()) };
    auto minC{ *iter };

    while (iter != changes.end() && *iter == minC) {
        auto diff{ iter - changes.begin() };
        cout << as[diff] << "\n";
        iter = std::min_element(iter + 1, changes.end());
    }

}
