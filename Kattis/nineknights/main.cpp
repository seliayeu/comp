#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<bool>> ks(5, vector<bool>(5, false));
    int count{ 0 };
    for (int i = 0; i < 5; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < 5; ++j) {
            if (s[j] == 'k') {
                ks[i][j] = 1;
                count++;
            }
        }
    }

    if (count != 9) {
        cout << "invalid\n";
        return 0;
    }

    for (int y = 0; y < 5; ++y) {
        // check above if possible
        for (int x = 0; x < 5; ++x) {
            if (!ks[y][x]) continue;
            vector<pair<int, int>> moves{ { y - 2, x + 1 }, { y - 2, x - 1 }, { y + 2, x + 1 }, { y - 2, x - 1 }, { y - 1, x + 2 }, { y + 1, x + 2 }, { y - 1, x - 2 }, { y + 1, x - 2 } };
            for (auto& [mY, mX] : moves) {
                if (0 <= mY && mY < 5 && 0 <= mX && mX < 5) {
                    if (ks[mY][mX]) {
                        cout << "invalid\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "valid\n";
}
