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
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; ++i)
            cin >> a[i];
        sort(a.begin(), a.end());
        
        ll numOps{ 0 };
        bool print{ true };
        for (ll i = 1; i <= n; ++i) {
            if (a[i - 1] == i)
                continue;
            ll back{ a[n - 1] };
            if ((back % (back - i)) == i) {
                numOps++;
                continue;
            }
            cout << -1 << "\n";
            print = false;
            break;
        }
        if (print)
            cout << numOps << "\n";
    }

}

// 1 2 5 6 7 8 11
