#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<bool>> g(n, vector<bool>(n));

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        int count{ 0 };
        for (int j = 0; j < n; ++j) {
            g[i][j] = (s[j] == 'W' ? true : false);
            count += (s[j] == 'W' ? 1 : -1);
            
            if (j > 2 && s[j] == s[j - 1] && s[j] == s[j - 2]) {
                cout << "0\n";
                return 0;
            }
        }
        if (count != 0) {
            cout << "0\n";
            return 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        int count{ 0 };
        for (int j = 0; j < n; ++j) {
            count += g[j][i] ? 1 : -1;
            if (j > 2 && g[j][i] == g[j - 1][i] && g[j][i] == g[j - 2][i]) {
                cout << "0\n";
                return 0;
            }

        }

        if (count != 0) {
            cout << "0\n";
            return 0;
        }
    }

    cout << "1\n";
}
