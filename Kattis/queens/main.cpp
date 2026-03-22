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

    vector<int> rows(n, -1);
    vector<int> cols(n, -1);

    for (int i = 0; i < n; ++i) {
        int r, c;
        cin >> c >> r;
        if (rows[r] != -1 || cols[c] != -1) {
            cout << "INCORRECT\n";
            return 0;
        }
        rows[r] = c;
        cols[c] = r;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int diff{ j - i };
            if (abs(rows[j] - rows[i]) == diff) {
                cout << "INCORRECT\n";
                return 0;
            }
        }
    }

    cout << "CORRECT\n";
    return 0;
}
