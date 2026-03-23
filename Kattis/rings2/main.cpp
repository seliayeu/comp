#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(m, 0));
    vector<string> input(n);

    for (int i = 0; i < n; ++i) {
        cin >> input[i];
        for (int j = 0; j < m; ++j) {
            if (input[i][j] == 'T') {
                g[i][j] = 1;
            }
        }
    }

    bool change{ true };
    int ring{ 1 };
    while (change) {
        change = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int N{ i - 1 }, S{ i + 1 }, E{ j + 1 }, W{ j - 1 };
                if (N >= 0 && S < n && E < m && W >= 0) {
                    if (g[N][j] >= ring && g[S][j] >= ring && g[i][E] >= ring && g[i][W] >= ring) {
                        g[i][j] = ring + 1;
                        change = true;
                    }
                }
            }
        }
        if (change)
            ring++;
    }

    string pre{ ring >= 10 ? "." : "" };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << pre;
            if (g[i][j] == 0)
                cout << "..";
            else
                cout << (g[i][j] < 10 ? "." : "") << g[i][j];
        }
        cout << "\n";
    }
}
