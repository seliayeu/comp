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
        if (n == 1) {
            cout << "NO\n";
            int tmp;
            cin >> tmp;
            continue;
        }
        map<int, int> s;
        for (int i = 0; i < n * n; ++i) {
            int tmp;
            cin >> tmp;
            s[tmp]++;
        }

        bool poss{ true };
        for (auto& [k, v] : s) {
            if (v > (n - 1) * n) {
                poss = false;
                break;
            }
        }
        if (poss)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
}
