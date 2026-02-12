#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<ll> x(n);
    ll biggest{ -1 };

    for (int i = 0; i < n;++i) {
        cin >> x[i];
        biggest = max(biggest, x[i]);
    }

    biggest /= 2;

    unordered_set<int> prime;
    prime.reserve(biggest);
    for (int i = 2; i <= biggest; ++i)
        prime.insert(i);

    for (int i = 1; i * i <= biggest; ++i) {
        if (prime.find(i) != prime.end()) {
            for (int j = i * i; j <= biggest; j += i) {
                if (j % i == 0)
                    prime.erase(j);
            }
        }
    }

    // cout << prime.size() << " size\n";

    for (auto& num : x) {
        int count{ 0 };
        if (prime.find(num) != prime.end()) {
            cout << "NO" << "\n";
            continue;
        }
        for (auto& p : prime) {
            // cout << p << " is prim\n";
            count += (num % p == 0);
            if (count > 2) {
                cout << "NO" << "\n";
                break;
            }
        }
        if (count == 1)
            cout << "YES\n";
        else if (count < 0)
            cout << "NO\n";
    }
}
