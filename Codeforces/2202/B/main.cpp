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
    cin >>t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        bool even{ n % 2 == 0 };

        vector<vector<bool>> prev{ { false, false }, { false, false } };
        vector<vector<bool>> curr{ { false, false }, { false, false } };

        if (s[0] == 'a') {
            prev[1][even] = true;
        } else if (s[0] == 'b') {
            if (n == 1 || !even) {
                cout << "NO\n";
                continue;
            }
            prev[0][0] = true;
        } else {
            if (even) {
                prev[1][1] = true;
                prev[0][0] = true;
            } else {
                prev[1][0] = true;
                prev[0][1] = true;
            }
        }

        bool poss{ true };
        for (int i = 1; i < s.size(); ++i) {
            curr = { { false, false }, { false, false } };
            auto& c{ s[i] };

            if (c == 'a') {
                curr[1][1] = prev[1][0] || prev[0][1];
                curr[1][0] = prev[0][0];
                if (!curr[1][1] && !curr[1][0]) {
                    poss = false;
                    break;
                }
            } else if (c == 'b') {
                curr[0][0] = prev[1][0] || prev[0][1];
                curr[0][1] = prev[1][1];
                if (!curr[0][0] && !curr[0][1]) {
                    poss = false;
                    break;
                }
            } else {
                curr[0][0] = prev[0][1] || prev[1][0];
                curr[1][1] = prev[0][1] || prev[1][0];
                curr[0][1] = prev[1][1] || prev[0][0];
                curr[1][0] = prev[1][1] || prev[0][0];
            }

            prev = curr;
        }

        if (!poss || (prev[0][0] == false && prev[1][1] == false && prev[0][1] == false && prev[1][0] == false)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}
