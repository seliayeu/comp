#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>> g(4, vector<int>(4));

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> g[i][j];
        }
    }

    auto merge{ [](vector<int>& row) {
        // for (int pass = 0; pass < 3; ++pass) {
            // move all left
            for (int i = 0; i < 4; ++i) {
                if (row[i] == 0) {
                    for (int j = i + 1; j < 4; ++j) {
                        if (row[j] == 0)
                            continue;
                        swap(row[i], row[j]);
                        break;
                    }
                }
            }

            // merge
            for (int i = 0; i < 4; ++i) {
                if (row[i] == row[i + 1]) {
                    row[i] += row[i + 1];
                    row[i + 1] = 0;
                }
            }

            for (int i = 0; i < 4; ++i) {
                if (row[i] == 0) {
                    for (int j = i + 1; j < 4; ++j) {
                        if (row[j] == 0)
                            continue;
                        swap(row[i], row[j]);
                        break;
                    }
                }
            }
        // }
    }};

    int m;
    cin >> m;

    if (m == 0) {
        for (auto& row : g)
            merge(row);
    } else if (m == 2) {
        for (auto& row : g) {
            std::reverse(row.begin(), row.end());
            merge(row);
            std::reverse(row.begin(), row.end());
        }
    } else if (m == 1) {
        for (int i = 0; i < 4; ++i) {
            vector<int> row(4);
            for (int j = 0; j < 4; ++j) {
                row[j] = g[j][i];
            }
            merge(row);
            for (int j = 0; j < 4; ++j) {
                g[j][i] = row[j];
            }

        }
    } else {
        for (int i = 0; i < 4; ++i) {
            vector<int> row(4);
            for (int j = 0; j < 4; ++j) {
                row[j] = g[3 - j][i];
            }
            merge(row);
            for (int j = 0; j < 4; ++j) {
                g[3 - j][i] = row[j];
            }

        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
}
