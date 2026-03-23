#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int W, L;

    int house{ 1 };
    vector<vector<char>> g(20, vector<char>(20));
    while (cin >> W >> L) {
        if (W == 0 && L == 0)
            break;

        int sX, sY;
        char dir;

        g.resize(L);
        for (int i = 0; i < L; ++i) {
            g[i].resize(W);
            string s;
            cin >> s;
            for (int j = 0; j < W; ++j) {
                g[i][j] = s[j];
                if (s[j] == '*') {
                    sY = i;
                    sX = j;
                    if (sY == 0)
                        dir = 'S';
                    else if (sY == L - 1)
                        dir = 'N';
                    else if (sX == 0)
                        dir = 'E';
                    else if (sX == W - 1)
                        dir = 'W';
                    else
                        assert(false);
                }
            }
        }
    
        int x{ sX }, y{ sY };
        while (true) {
            if (g[sY][sX] == 'x') {
                g[sY][sX] = '&';
                break;
            } else if (g[sY][sX] == '/') {
                if (dir == 'N') dir = 'E';
                else if (dir == 'S') dir = 'W';
                else if (dir == 'E') dir = 'N';
                else dir = 'S';
            } else if (g[sY][sX] == '\\') {
                if (dir == 'N') dir = 'W';
                else if (dir == 'S') dir = 'E';
                else if (dir == 'E') dir = 'S';
                else dir = 'N';
            }

            if (dir == 'N') sY--;
            else if (dir == 'S') sY++;
            else if (dir == 'E') sX++;
            else sX--;
        }

        cout << "HOUSE " << house++ << "\n";
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < W; ++j) {
                cout << g[i][j];
            }
            cout << "\n";
        }
    }
}
