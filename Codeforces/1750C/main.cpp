#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <utility>

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
        string as, bs;
        cin >> as >> bs;
    
        bool allSame{ as[0] == bs[0] };
        auto no{ false };
        for (int i = 0; i < n; ++i) {
            if (allSame && as[i] != bs[i]) {
                no = true;
                break;
            } else if (!allSame && as[i] == bs[i]) {
                no = true;
                break;
            }
        }

        if (no) {
            cout << "NO\n";
            continue;
        }

        unsigned l{ 0 }, r;
        vector<pair<unsigned, unsigned>> moves;

        while (l < n) {
            if (as[l] == '0') {
                l++;
                continue;
            }
            r = l;
            while (as[r] == '1') {
                r++;
            }
            moves.push_back({ l + 1, r });
            l = r;
        }

        if ((allSame && moves.size() % 2 == 1) || (!allSame && moves.size() % 2 == 0)){
            moves.push_back({ 1, n });
            moves.push_back({ 1, 1 });
            moves.push_back({ 2, n });
        }
        cout << "YES\n" << moves.size() << "\n";
        for (auto& p : moves)
            cout << p.first << " " << p.second << "\n";
    }
}
