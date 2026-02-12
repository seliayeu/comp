#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;

    size_t ind{ 0 };

    while ((ind = s.find(s[0], ind + 1)) != string::npos) {
        size_t l{ 0 };
        size_t r{ ind };

        while (s[l] == s[r] && l < ind && r < s.size()) {
            l++;
            r++;
            if (r == s.size()) {
                cout << "NO\n";
                return 0;
            }
        }

        if (l == ind) {
            cout << "YES\n" << s.substr(ind) << "\n";
            return 0;
        }
    }
    cout << "NO\n";
}

