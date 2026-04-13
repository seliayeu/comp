#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

struct Contestant {
    int probs;
    int penalty;
    int lastTime;
    int onSite;
    int ind;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Contestant> v(n);
    for (int i = 0; i < n; ++i) {
        auto& c{ v[i] };
        cin >> c.probs >> c.penalty >> c.lastTime >> c.onSite;
        c.ind = i;
    }
    
    auto c1{ [](auto& a, auto& b) {
        if (a.probs == b.probs) {
            if (a.penalty == b.penalty) {
                return a.lastTime < b.lastTime;
            }
            return a.penalty < b.penalty;
        }
        return a.probs > b.probs;
    }};

    sort(v.begin(), v.end(), c1);

    array<int, 30> ranks;
    ranks[0] = 100; ranks[1] = 75; ranks[2] = 60; ranks[3] = 50;
    ranks[4] = 45; ranks[5] = 40; ranks[6] = 36; ranks[7] = 32;
    ranks[8] = 29; ranks[9] = 26; ranks[10] = 24; ranks[11] = 22;
    ranks[12] = 20; ranks[13] = 18; ranks[14] = 16;

    for (int i = 15; i < 30; ++i)
        ranks[i] = 30 - i;

    int score{ 100 };
    vector<pair<int, int>> res(n);
    int start{ 0 };

    for (int i = 1; i < n; ++i) {
        if (v[i].probs == v[i - 1].probs && v[i].penalty == v[i - 1].penalty && v[i].lastTime == v[i - 1].lastTime) {
            score += i < 30 ? ranks[i] : 0;
        } else {
            for (int j = start; j < i; ++j) {
                res[j] = { v[j].ind, (score + (i - start - 1)) / (i - start) + v[j].onSite } ;
            }
            start = i;
            score = i < 30 ? ranks[i] : 0;
        }
    }
    for (int j = start; j < n; ++j) {
        res[j] = { v[j].ind, (score + (n - start - 1)) / (n - start) + v[j].onSite } ;
    }

    sort(res.begin(), res.end());
    for (int i = 0; i < n; ++i)
        cout << res[i].second << "\n";
}
