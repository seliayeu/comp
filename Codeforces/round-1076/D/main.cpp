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
        
        vector<ll>a(n), b(n);
        for (ll i = 0; i < n; ++i)
            cin >> a[i];
        for (ll i = 0; i < n; ++i)
            cin >> b[i];

        sort(a.begin(), a.end(), greater<>());
        
        ll res{ 0 };
        ll ind{ 0 };

        for (ll i = 0; i < n; ++i) {
            ll num{ b[i] };
            if (ind + num - 1 >= n)
                break;
            // cout << " a " << a[ind + num - 1] << " " << i + 1 << endl;
            res = max(res, a[ind + num - 1] * (i + 1));
            // cout << " res" << res << " ?? " << a[ind + num - 1] * (ind + 1) << endl;
            ind += num;
        }
        
        cout << res << endl;
    }

}
