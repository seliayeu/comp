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
        string s;
        cin >> s;

        auto ones{ count(s.begin(), s.end(), '1') };
        if ((n - ones) % 2 == 1) {
            cout << n - ones << "\n";
            auto iter{ s.begin() };
            while ((iter = find(iter, s.end(), '0')) != s.end()) {
                cout << distance(s.begin(), iter) + 1 << " ";
                iter++;
            }
            cout << "\n";
            continue;
        } else if (ones % 2 == 0) {
            cout << ones << "\n";
            auto iter{ s.begin() };
            while ((iter = find(iter, s.end(), '1')) != s.end()) {
                cout << distance(s.begin(), iter) + 1 << " ";
                iter++;
            }
            if (ones != 0)
                cout << "\n";
            continue;
        } else {
            cout << "-1\n";
            continue;
        }
    }
}
