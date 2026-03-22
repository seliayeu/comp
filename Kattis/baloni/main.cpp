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
    vector<int> c(1e6 + 1, 0);

    int res{ n };
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        c[tmp]++;
        if (c[tmp + 1] > 0) {
            c[tmp + 1]--;
            res--;
        }
    }


    cout << res << "\n";
}
