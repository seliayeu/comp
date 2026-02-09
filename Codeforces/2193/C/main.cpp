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
    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> a(n), b(n), sum(n + 1, 0);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n; ++i)
            cin >> b[i];

        a[n - 1] = max(a[n - 1], b[n - 1]);
        for (int i = 1; i < n; ++i)
            a[n - i - 1] = max(b[n - i - 1], max(a[n - i - 1], a[n - i]));

        // cout << " a!! \n";
        // for (int i = 0; i < n; ++i)
        //     cout << a[i] << " \n"[i == n - 1];
            

        for (int i = 0; i < n; ++i) {
            // cout << "sum[i+1] " << sum[i] << " plus " << a[i] << "wow!" << endl;
            sum[i + 1] = sum[i] + a[i];
        }
    
        for (int i = 0; i < q; ++i) {
            int l, r;
            cin >> l >> r;
            // int sum{0};
            // for (int j = l - 1; j < r; ++j)
            //     sum += a[j];
            // cout << sum << " \n"[i == q - 1];
            cout << sum[r] - sum[l - 1] << " \n"[i == q - 1];


            // cout << l << " !! " << r << endl;
            // cout << accumulate(best.begin() + l - 1, best.begin() + l + r - 1, 0) << " \n"[i == q - 1];
        }
    }
}
