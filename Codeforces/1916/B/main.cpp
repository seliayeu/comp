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
    cin >>t ;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (lcm(a, b) != b) {
            cout << lcm(a, b) << "\n";
        } else if (a == 1) {
            cout << b * b << "\n";
        } else {
            cout << b * 2 << "\n";
        }
    }
}
