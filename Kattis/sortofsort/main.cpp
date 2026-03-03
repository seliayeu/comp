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
    
    int m;
    cin >> m;

    cout << m << " ";

    for (int i = 0; i < n - 1; ++i) {
        int tmp;
        cin >> tmp;
        if (tmp >= m) {
            m = tmp;
            cout << tmp << " ";
        }
    }
    cout << "\n";
}
