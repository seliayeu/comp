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

        for (int i = 1; i <= n; ++i) {
            cout << i;
            if (i != n) cout << " ";
        }
        cout << "\n";
    }
}

