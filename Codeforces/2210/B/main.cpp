#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> v(n + 1);
        for (int i = 1; i <= n; ++i )
            cin >> v[i];

        vector<int> scores(n + 1, 1);
        int res{ 1 };
        for (int i = n - 1; i >= 1; --i) {
            auto take{ scores[i + 1] + 1 };
            if (v[i] > i)
                take -= scores[v[i]];
            scores[i] = max(take, scores[i + 1]);
            res = max(res, scores[i]);
        }

        cout << res << "\n";
    }
}
