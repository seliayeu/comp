#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_set<ll> vals;

    int t;
    cin >> t;
    while (t--) {
        int n, m, h;
        cin >> n >> m >> h;
        vector<int> arr(n, 0);

        for (int i = 0; i < n; ++i)
            cin >> arr[i];
    
        vector<pair<int, int>> queries(m);

        for (int i = 0; i < m; ++i) {
            cin >> queries[i].first >> queries[i].second;
            // add to current -> > h -> what do? resetting is too expensive
        }


    }
}

