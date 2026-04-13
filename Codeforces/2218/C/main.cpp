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
        int n;
        cin >> n;
        vector<int> v(3 * n), res( 3 * n);

        for (int i = 1; i <= 3 * n; ++i) 
            v[i - 1] = i;

        int ind{ 1 };
        for (int i = 3 * n - 1; i > n; i -= 2) {
            res[ind] = v[i - 1];
            res[ind + 1] = v[i];
            ind += 3;
        }
        ind = 0;
        for (int i = 0; i < n; ++i) {
            res[ind] = v[i];
            ind += 3;
        }

        for (int i = 0; i < 3 * n; ++i)
            cout << res[i] << " " ;
        cout << endl;
    }
}
