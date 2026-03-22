#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    set<char> chs;
    for (ll i = 0; i < k; ++i) {
        char tmp;
        cin >> tmp;
        chs.insert(tmp);
    }

    ll res{ 0 };
    ll curr{ 0 };

    for (auto c : s) {
        if (chs.count(c) > 0) {
            curr++;
            res += curr;
        } else {
            curr = 0;
        }
    }


    cout << res << "\n";
}
