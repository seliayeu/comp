#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long double t, h;
    cin >> t >> h;

    if (h / 2.0 < t) {
        cout << std::setprecision(10) << (h + t) - (h / 2.0) << "\n";
        return 0;
    }
    
    cout << std::setprecision(10) << (sqrt((2.0 * t) / h) * h) << "\n";
}
