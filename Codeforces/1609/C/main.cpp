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

    vector<bool> isPrime(1000001, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= 1000001; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= 1000001; j += i)
                isPrime[j] = false;
        }
    }
    vector<int> a;
    a.reserve(2 * 100000);
    vector<bool> visited;
    visited.reserve(2 * 100000);

    while (t--) {
        ull n, e;
        cin >> n >> e;

        a.resize(n);
        visited.resize(n);
        ull numPairs{ 0 };
        for (ull i = 0; i < n; ++i)
            cin >> a[i];
        for (ull i = 0; i < n; ++i) {
            if (visited[i])
                continue;
            if (a[i] != 1 && !isPrime[a[i]])
                continue;

            ull prod{ static_cast<ull>(a[i]) };
            ull k{ 1 };
            int ind{ isPrime[a[i]] ? 0 : -1 };

            while (i + e * k < n) {
                auto next{ a[i + e * k] };
                if (next == 1) {
                    prod *= next;
                } else {
                    if (!isPrime[next] || prod != 1)
                        break;
                    prod *= next;
                    ind = k;
                    visited[i + e * k] = true;
                }
                if (ind == -1)
                    visited[i + e * k] = true;
                // cout << "WOW " << i + e * k << endl;
                k++;
            }
            // cout << ind << "no way" << endl;
            k -= 1;
            if (ind == -1)
                continue;
            ull pref{ static_cast<ull>(ind) };
            ull post{ k - ind + 1 };
            // cout << "pref " << pref << " post " << post << " ind " << ind << "\n";
            numPairs += pref * post;
            numPairs += k - ind;
        }

        cout << numPairs << "\n";
        a.clear();
        visited.clear();
    }
}
