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
    cin >>t;
    while (t--) {
        ull p, q;
        cin >> p >> q;

        if (p >= q) {
            cout << "Alice\n";
            continue;
        }

        ull diff(q - p);
        if (diff * 2 <= p) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    }
}
