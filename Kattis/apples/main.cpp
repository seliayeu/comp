#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int R, C;
    cin >> R >> C;

    vector<string> input(R);
    for (int i = 0; i < R; ++i) {
        cin >> input[i];
    }

    vector<char> col;
    col.resize(R);
    for (int c = 0; c < C; ++c) {
        col.clear();
        for (int r = 0; r < R; ++r) {
            if (input[r][c] == '.')
                continue;
            if (input[r][c] == 'a') {
                input[r][c] = '.';
                col.push_back('a');
                continue;
            }

            for (int i = r - 1; i >= 0 && col.size() > 0; --i) {
                input[i][c] = 'a';
                col.pop_back();
            }
        }
        if (col.size() > 0) {
            for (int r = R - 1; r >= 0 && col.size() > 0; --r) {
                input[r][c] = 'a';
                col.pop_back();
            }
        }
    }

    for (int i = 0; i < R; ++i)
        cout << input[i] << "\n";
}
