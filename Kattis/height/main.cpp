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
    vector<int> h(20);
    while (t--) {
        int k;
        cin >> k;

        for (int i = 0; i < 20; ++i)
            cin >> h[i];

        int res{ 0 };

        for (int i = 1; i < 20; ++i) {
            int ind{ i };

            while (ind >= 1 && h[ind - 1] > h[ind]) {
                swap(h[ind - 1], h[ind]);
                ind--;
            }

            res += i - ind;
        }
        
        cout << k << " " << res << "\n";

    }
}
