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

    vector<int> mag(2 * 100000);
    vector<int> big(2 * 100000);
    vector<int> sm(2 * 100000);

    while (t--) {
        ll n, h, k;
        cin >> n >> h >> k;
        mag.resize(n);
        big.resize(n - 1);
        sm.resize(n);
        
        cin >> mag[0];
        sm[0] = mag[0];
        for (int i = 1; i < n; ++i) {
            cin >> mag[i];
            sm[i] = min(sm[i - 1], mag[i]);
        }

        big[n - 2] = mag[n - 1];
        for (int i = n - 3; i >= 0; --i)
            big[i] = max(mag[i + 1], big[i + 1]);

        ll res{ 0 };
        ll rem{ 0 };
        res = accumulate(mag.begin(), mag.end(), 0LL);
        rem = h % res;
        res = (h / res) * (k + n);
    
        if (rem == 0) {
            res -= k;
            cout << res << "\n";
            continue;
        }

        ll t{ 0 };
        bool kill{ false };
        for (int i = 0; i < n - 1; ++i) {
            t += mag[i];
            res += 1;
            if (rem - (t - sm[i] + big[i]) <= 0 || rem - t <= 0) {
                kill = true;
                break;
            }
        }
        if (kill)
            cout << res << "\n";
        else
            cout << res + 1 << "\n";
    }
}
