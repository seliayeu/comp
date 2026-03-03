#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

void u_s(vector<vector<int>>& dp, int val) {
    static unordered_map<int, vector<int>> m{
        { 1, { 2, 3, 4, 5} },
        { 2, { 1, 3, 4, 6} },
        { 3, { 1, 2, 5, 6} },
        { 4, { 1, 2, 5, 6} },
        { 5, { 1, 3, 4, 6} },
        { 6, { 2, 3, 4, 5} },
    };

    for (int i = 1; i <= 6; ++i) {
        int mn{ numeric_limits<int>::max() };
        for (auto& s : m[i])
            mn = min(mn, dp[0][s]);
        if (i != val)
            mn += 1;
        dp[1][i] = mn;
    }
    for (int i = 0; i <= 6; ++i) {
        dp[0][i] = dp[1][i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> dp(2, vector<int>(7, 1));
        
        int tmp;
        cin >> tmp;
        dp[0][tmp] = 0;

        for (int i = 1; i < n; ++i) {
            int val;
            cin >> val;
            u_s(dp, val);
        }

        int mn{ numeric_limits<int>::max() };
        for (int i = 1; i <= 6; ++i)
            mn = min(mn, dp[0][i]);
        cout << mn << "\n";
    }
}
