#include <algorithm>
#include <cassert>
#include <climits>
#include <deque>
#include <iostream>
#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll a, b, n;
    cin >> a >> b >> n;

    vector<ll> aCache(n), bCache(n);

    for (ll i = 0; i < min(n, MOD); ++i) {
        a = (a + b) % MOD;
        b = (a + b) % MOD;
        aCache[i] = a;
        bCache[i] = b;
    }

    if ((n / MOD) % 2 == 0) {
        cout << "aye"
             << " " << n % MOD << endl;
        cout << aCache[n % MOD] << " " << bCache[b % MOD] << endl;
    } else {
        cout << MOD - aCache[n % MOD] << " " << MOD - bCache[b % MOD] << endl;
    }
}
