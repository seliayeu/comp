#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //
    // int n{ 10000 };

    // vector<bool> is_valid(n + 1, true);
    // is_valid[0] = is_valid[1] = false;
    // for (int i = 2; i <= n; i++) {
    //     if (!is_valid[i])
    //         continue;
    //     for (int j = i * i; j < n; j *= i) {
    //         is_valid[j] = false;
    //     }
    // }
    
    ll lim{ 1'000'000'000'000 };
    int t;
    cin >> t;
    while (t--) {
        int n, og;
        cin >> n;
        og = n;
        
        ll curr{ 1 };
        ll factor{ 2 };
        
        set<ll> w;
        while (n > 0) {
            while (n > 0 || w.count(gcd(curr, curr * factor))) {
                cout << curr << " ";
                n--;
                ll newNum{ curr * factor };
                w.insert(gcd(curr, newNum));
                curr = newNum;
                if (curr > lim)
                    break;
            }

            if (n == 0)
                break;

            factor++;
            while (w.count(gcd(curr, curr * factor)) > 0 || w.count(gcd(curr * factor, factor * factor)) > 0)
                factor++;

            w.insert(gcd(curr, curr * factor));
            curr *= (factor);
            cout << curr << " ";
            n--;
            if (n == 0)
                break;
            w.insert(gcd(factor * factor, curr));
            curr = factor * factor;
        }
        cout << "\n";
    }
}
