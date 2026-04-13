#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    ll total{ 0 };
    vector<pair<ll, string>> songs(n);
    vector<pair<pair<long long, string>, int>> qSongs(n);
    for (int i = 0; i < n; ++i) {
        cin >> songs[i].first >> songs[i].second;
        total += songs[i].first;
    }
    for (int i = 1; i <= n; ++i) {
        qSongs[i - 1] = { { songs[i - 1].first * i , songs[i - 1].second }, i };
    }

    sort(qSongs.begin(), qSongs.end(), [](auto& a, auto& b) {
        if (a.first.first == b.first.first)
            return a.second < b.second;
        return a.first.first > b.first.first;
    });

    for (int i = 0; i < m; ++i)
        cout << qSongs[i].first.second << "\n";
    
}
