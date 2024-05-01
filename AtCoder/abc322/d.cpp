
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void rotate(vector<string> &v) {
    vector<string> w = v;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            w[i][j] = v[3 - j][i];
        }
    }
    v = w;
}

bool tryPlace(vector<string> &grid, int di, int dj, const vector<string> &p) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (p[i][j] != '#')
                continue;
            int ni = di + i;
            int nj = dj + j;

            if (ni < 0 || nj < 0 || nj > 3 || ni > 3 || grid[ni][nj] == '#')
                return false;

            grid[ni][nj] = '#';
        }
    }
    return true;
}

bool dfs(int ind, const vector<string> &grid, vector<vector<string>> &ps) {
    if (ind == 3) {
        return true;
    }

    for (int i = -3; i < 4; ++i) {
        for (int j = -3; j < 4; ++j) {
            vector<string> newGrid = grid;

            if (tryPlace(newGrid, i, j, ps[ind])) {
                if (dfs(ind + 1, newGrid, ps))
                    return true;
            }
        }
    }

    return false;
}

int main() {
    string tmp;
    vector<vector<string>> ps;
    int filled = 0;

    for (int i = 0; i < 3; ++i) {
        vector<string> p;
        for (int j = 0; j < 4; ++j) {
            string l;
            cin >> l;
            filled += count(l.begin(), l.end(), '#');
            p.push_back(l);
        }
        ps.push_back(p);
    }

    if (filled != 16) {
        cout << "No";
        return 0;
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (dfs(0, vector<string>(4, "...."), ps)) {
                cout << "Yes";
                return 0;
            }
            rotate(ps[2]);
        }
        rotate(ps[1]);
    }
    cout << "No";
}
