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
    
        vector<int> res(n);
        unordered_map<int, bool> contains;
        res[n - 1] = 1;
        contains[1] = true;

        for (int i = 1; i < n - 1; ++i) {
            res[i] = res[n - 1] ^ (i + 1);
            contains[res[i]] = true;
        }
        for (int i = 2; i <= n; ++i) {
            if (contains.find(i) == contains.end()) {
                res[0] = i;
                break;
            }
        }
        for (int i = 0; i < n; ++i)
            cout << res[i] << " \n"[i == n - 1];
    }
}
