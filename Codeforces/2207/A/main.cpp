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

        string s;
        cin >> s;

        int most{ 0 };
        int ogleast{ 0 };

        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '1') {
                most++;
                ogleast++;
            } else if (i < s.size() - 1 && s[i] == '0' && s[i - 1] == '1' && s[i + 1] == '1') {
                most++;
                s[i] = '1';
            }
        }

        most += s[0] == '1';
        ogleast += s[0] == '1';

        // cout << most << endl; return 0;
        //
        int least{ most };
        for (int i = 1; i < s.size(); ++i) {
            if (i < s.size() - 1 && s[i - 1] == '1' && s[i] == '1' && s[i + 1] == '1') {
                s[i] = '0';
                least--;
            }
        }

        cout << min(least, ogleast) << " " << most << "\n";
    }
}
