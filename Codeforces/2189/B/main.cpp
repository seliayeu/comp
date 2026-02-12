#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t{ 0 };
    cin >> t;

    while (t--) {
        int n; ull x;
        cin >> n >> x;

        tuple<ull, ull, ull> best{ -1, -1, -1 };

        ull start{ 0 };

        for (int i = 0; i < n; ++i) {
            ull a, b, c;
            cin >> a >> b >> c;
            
            start = max(start, start + (a * (b - 1)));
            if (a * b <= c)
                continue;
            if ((get<0>(best) == -1) || (get<0>(best) * get<1>(best) - get<2>(best) < a * b -c))
                best = { a, b, c };
        }

        if (start >= x) {
            cout << "0\n";
            continue;
        }

        x -= start;

        if (get<0>(best) == -1) {
            cout << "-1\n";
            continue;
        }

        ull dist{ get<0>(best) * get<1>(best) - get<2>(best) };
        
        if (dist <= 0) {
            cout << "-1\n";
            continue;
        }

        ull res{ 0 };

        res += (x + dist - 1) / dist; // x / dist + (x % dist == 0 ? 0 : 1);

        cout << res << "\n";
    }
}
