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
        vector<ll> a(n), b(n);
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (ll i = 0; i < n; ++i) {
            cin >> b[i];
        }

        ll res{ 0 };

        ll g{ gcd(a[0], a[1]) };
        if (g != a[0]) {
            a[0] = g;
            res++;
        }
        g =  gcd(a[n - 2], a[n - 1]);
        if (a[n - 1] != g) {
            a[n - 1] = g;
            res++;
        }

        for (ll i = 1; i < n - 1; ++i) {
            if (a[i] == a[i - 1] || a[i] == a[i + 1])
                continue;
            auto g1{ gcd(a[i], a[i - 1]) };
            auto g2{ gcd(a[i], a[i + 1]) };
            
            auto l{ lcm(g1, g2) };
            if (a[i] == l)
                continue;
            a[i] = l;
            res++;
        }
        cout << res << "\n";
    }
}
