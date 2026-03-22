#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>
#include <unordered_set>

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

    vector<ll> a;
    a.reserve(100);
    while (t--) {
        ll n, c, k;
        cin >> n >> c >> k;
        a.resize(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        for (int i = 0; i < a.size(); ++i) {
            if (a[i] > c)
                break;
            ll diff{ 0 };
            if (k > 0) {
                diff = min(k, c - a[i]);
                k -= diff;
                a[i] += diff;
            }
            c += a[i];
        }

        cout << c << "\n";
    }
}
