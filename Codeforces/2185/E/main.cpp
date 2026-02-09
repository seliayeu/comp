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
    vector<ll> robots(2 * 100000), spikes(2 * 100000);

    int t;
    cin >>t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        robots.resize(n);
        spikes.resize(m);

        for (int i = 0; i < n; ++i)
            cin >> robots[i];
        for (int i = 0; i < m; ++i)
            cin >> spikes[i];

        sort(robots.begin(), robots.end());
        sort(spikes.begin(), spikes.end());

        string instructions;
        cin >> instructions;
        unordered_map<int, int> times;
        int curr{ 0 };
        int time{ 0 };

        for (auto& inst : instructions) {
            if (inst == 'L')
                curr -= 1;
            else
                curr += 1;
            if (times.find(curr) == times.end())
                times[curr] = time;
            times[curr] = min(time, times[curr]);
            time++;
            // cout << "curr " << curr << "time " << time - 1 << endl;
        }

        vector<int> dieAt(k, 0);

        int p1{ 0 }, p2{ 0 };
        while (p1 < n) {
            int l, r;
            while (p2 < m && spikes[p2] < robots[p1])
                p2++;
            if (p2 < m)
                r = spikes[p2] - robots[p1];
            else
                r = numeric_limits<int>::max();
            if (p2 > 0)
                l = spikes[p2 - 1] - robots[p1];
            else
                l = numeric_limits<int>::min();

            // cout << p1 << " dists " << l << " " << r <<endl;
            time = numeric_limits<int>::max();
            if (times.find(r) != times.end())
                time = min(time, times[r]);
            if (times.find(l) != times.end())
                time = min(time, times[l]);
            if (time != numeric_limits<int>::max())
                dieAt[time]++;
            p1++;
        }

        for (int i = 0; i < k; ++i) {
            n -= dieAt[i];
            cout << n << " ";
        }
        cout << "\n";
    }
}

