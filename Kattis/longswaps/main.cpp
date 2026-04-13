#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    int k;
    cin >> s >> k;

    if (is_sorted(s.begin(), s.end()) || s.size() >= 2 * k) {
        cout << "Yes\n";
        return 0;
    }

    string sorted{ s };
    sort(sorted.begin(), sorted.end());

    if (equal(sorted.begin() + s.size() - k, sorted.begin() + k, s.begin() + s.size() - k)) {
        cout << "Yes\n";
    } else
        cout << "No\n";
}
