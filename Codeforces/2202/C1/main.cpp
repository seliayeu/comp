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

    set<int> a;
    while (t--) {
        int n;
        cin >> n;
        a.clear();
        int res{ 0 };
        int prev{ 0 };
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            if (a.count(tmp - 1) == 0 || (i > 0 && prev < tmp - 1)) {
                a.clear();
                a.insert(tmp);
                res += 1;
            } else {
                a.insert(tmp);
            }
            prev = tmp;
        }

        cout << res << "\n";
    }
}
