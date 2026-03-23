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
        int n, m;
        cin >> n >> m;
        vector<int> counts(m, 0);

        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < m; ++j)
                counts[j] += s[j] == '0' ? -1 : 1;
        }

        for (int i = 0; i < m; ++i) {
            cout << (counts[i] < 0 ? '0' : '1');
        }
        cout << "\n";
    }
}
