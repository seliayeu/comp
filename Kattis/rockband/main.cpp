#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, S;
    cin >> M >> S;

    vector<pair<int, int>> songs(S + 1);

    for (int i = 1; i <= S; ++i) {
        songs[i] = { 0, i };
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < S; ++j) {
            int song;
            cin >> song;
            songs[song].first = max(songs[song].first, j + 1);
        }
    }

    sort(songs.begin() + 1, songs.end());
    vector<int> res;
    res.reserve(S);
    for (int i = 1; i <= S; ++i) {
        res.push_back(songs[i].second);
        if (songs[i].first == i)
            break;
    }

    sort(res.begin(), res.end());
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << "\n";
}
