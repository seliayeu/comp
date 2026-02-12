#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll m, n, k;
    cin >> n >> m >> k;
    //
    // ll prev{ 0 };
    // for (ll i = 0; i < m; ++i) {
    //     ll tmp;
    //     cin >> tmp;
    //     nP[i] = tmp - prev - 1;
    //     if (i > 0)
    //         nP[i] += nP[i - 1];
    //     prev = tmp;
    // }

    ll l{ 0 }, r;
    ll numOps{ 0 };

    ll npCurr;
    ll npPrev{ 0 };
    ll prev{ 0 };
    ll tmp;
    cin >> tmp;
    npCurr = tmp - prev - 1 + npPrev;
    npPrev = npCurr;
    prev = tmp;
    while (l < m) {
        r = l;

        auto cPg{ npCurr / k };
        auto fPg{ cPg };
        while (r < m && fPg == cPg) {
            r++;
            if (r == m)
                break;
            cin >> tmp;
            npCurr = tmp - prev - 1 + npPrev;
            npPrev = npCurr;
            prev = tmp;
            cPg = (npCurr + r - l) / k;
        }
        numOps++;
        l = r;
    }

    // while (l < m) {
    //     r = l;
    //     auto cPg{ (nP[l] + r - l) / k };
    //     auto fPg{ cPg };
    //     while (r < m && fPg == cPg) {
    //         r++;
    //         cPg = (nP[r] + r - l) / k;
    //     }
    //     numOps++;
    //     l = r;
    // }
    //

    cout << numOps << "\n";
}
