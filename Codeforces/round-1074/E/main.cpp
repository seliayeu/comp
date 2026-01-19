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
    cin >>t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        vector<ll> robots(n), spikes(m);
        unordered_map<ll, int> dieAt;

        for (int i = 0; i < n; ++i)
            cin >> robots[i];
        for (int i = 0; i < m; ++i)
            cin >> spikes[i];

        sort(robots.begin(), robots.end());
        sort(spikes.begin(), spikes.end());

        string instructions;
        cin >> instructions;
    
        int p1{}, p2{};

        while (p1 < n) {
            while (p2 < m && spikes[p2] < robots[p1])
                p2++;
            // cout << " HUHH " << p2 << spikes[p2] << endl;
            // cout << " HUHH " << p2 << robots[p1] << endl;
            if (p2 == m) {
                dieAt[spikes[p2 - 1] - robots[p1]] += 1;
                // cout << spikes[p2 - 1] << " WOW <<"
                //     << robots[p1] << endl;
            } else if (p2 == 0) {
                dieAt[spikes[p2] - robots[p1]] += 1;
            } else {
                dieAt[spikes[p2 - 1] - robots[p1]] += 1;
                dieAt[spikes[p2] - robots[p1]] += 1;
            }
            p1++;
        }

        ll curr{0};
        for (auto& c : instructions) {
            if (c == 'L')
                curr--;
            else 
                curr++;
            cout << max(n -= dieAt[curr], 0) << " ";
        }
        cout << "\n";
    }
}

