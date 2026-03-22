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
    while (cin >> n) {
        if (n == 1) {
            int tmp;
            cin >> tmp;
            cout << "Jolly\n";
            continue;
        }

        vector<bool> a(n, false);
        a[0] = true;
        int prev;
        cin >> prev;
        for (int i = 1; i < n; ++i) {
            int curr;
            cin >> curr;
            int diff{ abs(curr - prev) };
            prev = curr;
            if (diff > n - 1)
                continue;
            a[diff] = true;
        }

        if (count(a.begin(), a.end(), true) == a.size()) {
            cout << "Jolly\n";
        } else {
            cout << "Not jolly\n";
        }
    }
}
