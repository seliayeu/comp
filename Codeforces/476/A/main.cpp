#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int maxSteps{ n }, minSteps{ n % 2 == 0 ? n / 2 : n / 2 + 1 };

    for (int i = minSteps; i <= maxSteps; ++i) {
        if (i % m == 0) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
}

// 10, 4 -> 10 / 2 is 5. 10 / 1 is 10. is there a multiple of 4 between 5 and 10? yes -> yes
