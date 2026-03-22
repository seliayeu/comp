#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> rs(n);
    for (int i = 0; i < n; ++i)
        cin >> rs[i];

    int l{ 0 }, r{ 0 };
    int maxRq{ 0 };
    int currRq{ 0 };
    while (l < rs.size()) {
        while (r < rs.size() && rs[r] - rs[l] < 1000) {
            r++;
        }
        maxRq = max(maxRq, r - l);
        l++;
    }

    cout << (maxRq + k - 1) / k << "\n";
}
