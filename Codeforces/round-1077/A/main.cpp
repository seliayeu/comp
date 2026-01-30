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
        // 1
        // 12
        // 2
        // 11
        // 3
        // 10
        // 4
        // 9
        // 5
        // 3
        // 4

        // 1
        // 11
        // 2
        // 10
        // 3
        //
        // 1
        // 3
        // 2
        int increasing{ 1 };
        int decreasing{ n };
        int prev;
        vector<int> p;
        p.reserve(n);
        while (p.size() < n) {
            if (p.size() % 2 == 0) {
                p.push_back(increasing++);
            } else {
                p.push_back(decreasing--);
            }
        }

        for (int i = n - 1; i >= 0; i--)
            cout << p[i] << " \n"[i == 0];
    }
}
