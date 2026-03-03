#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ull MOD = 1e9 + 7;

ll exp(ll x, ll n, ll m) {
    x %= m;
    ll res{ 1 };
    while (n > 0) {
        if (n % 2 == 1) res = res * x % m;
        x = x * x % m;
        n /= 2;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<ll> factorial(1e6 + 1);
    vector<ll> inverses(1e6 + 1);
    factorial[0] = 1;

    for (int i = 1; i <= 1e6; ++i)
        factorial[i] = factorial[i - 1] * i % MOD;

    inverses[1e6] = exp(factorial[1e6], MOD - 2, MOD);
    for (int i = 1e6 - 1; i >= 0; --i)
        inverses[i] = inverses[i + 1] * (i + 1) % MOD;

    ull n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        ull a, b;
        cin >> a >> b;

        cout << factorial[a] * inverses[b] % MOD * inverses[a - b] % MOD << "\n";
    }
}
