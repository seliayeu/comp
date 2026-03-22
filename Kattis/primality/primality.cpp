#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <random>
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

long long binpower(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    if (n < 4) {
        if (n == 2 || n == 3) {
            cout << "YES";
            return 0;
        }
    }

    std::mt19937_64 gen64;
    gen64.discard(123941);

    for (int i = 0; i < 8; ++i) {
        ll a = 2 + (gen64()) % (n - 3);
        if (binpower(a, n - 1, n) != 1) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}
