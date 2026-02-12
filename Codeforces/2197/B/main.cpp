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

    vector<int> p(2 * 100000);
    vector<int> a(2 * 100000);
    while (t--) {
        int n;
        cin >> n;
        a.resize(n);
        p.resize(n);

        for (int i = 0; i < n; ++i)
            cin >> p[i];
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        int ind{ 0 };
        bool y{ true };
        int prev{ 0 };
        while (ind < n) {
            while (ind < n - 1 && a[ind] == a[ind + 1])
                ind++;
            auto pI{ find(p.begin() + prev, p.end(), a[ind]) };

            if (pI == p.end()) {
                y = false;
                break;
            }
            prev = distance(p.begin(), pI);

            ind++;
        }

        if (y)
            cout << "YES\n";
        else if (n)
            cout << "NO\n";
    }
}
// 227777777
// 222227777
