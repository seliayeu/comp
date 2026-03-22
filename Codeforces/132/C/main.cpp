#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n;
    cin >> n;
    
    vector<vector<vector<int>>> maxDist(2, vector<vector<int>>(n + 1, vector<int>(s.size() + 1, -999)));
    vector<vector<vector<int>>> minDist(2, vector<vector<int>>(n + 1, vector<int>(s.size() + 1, 999)));

    maxDist[0][0][0] = 0;
    minDist[0][0][0] = 0;

    for (int i = 1; i <= s.size(); ++i) {
        bool move{ s[i - 1] == 'F' };
        
        // cout << "i = " << i << endl;
        for (int j = 0; j <= n; ++j) { // make j changes
            for (int k = 0; k <= n - j; ++k) { // starting at *Dist[*][k][i]
                // cout << "j = " << j << ", k = " << k << endl;
                // cout << "j % 2 == 0 is " << (j % 2 == 0) << endl;
                // cout << move << endl;
                if (((j % 2 == 0) && move) || ((j % 2 == 1) && !move)) {
                    // cout << "here " << endl;
                    // cout << maxDist[0][k][i - 1] << endl;
                    maxDist[0][k + j][i] = max(maxDist[0][k][i - 1] + 1, maxDist[0][k + j][i]);
                    maxDist[1][k + j][i] = max(maxDist[1][k][i - 1] - 1, maxDist[1][k + j][i]);
                    minDist[0][k + j][i] = min(minDist[0][k][i - 1] + 1, minDist[0][k + j][i]);
                    minDist[1][k + j][i] = min(minDist[1][k][i - 1] - 1, minDist[1][k + j][i]);

                    // cout << "updated minDist[" << 0 << "][" << k + j << "][" << i << "] to " << minDist[0][k +j][i] << endl;
                    // cout << "updated maxDist[" << 0 << "][" << k + j << "][" << i <<"] to " << maxDist[0][k +j][i] << endl;
                    // cout << "updated minDist[" << 1 << "][" << k + j << "][" << i << "] to " << minDist[1][k +j][i] << endl;
                    // cout << "updated maxDist[" << 1 << "][" << k + j << "][" << i <<"] to " << maxDist[1][k +j][i] << endl;
                }
                else {
                    maxDist[0][k + j][i] = max(maxDist[1][k][i - 1], maxDist[0][k + j][i]);
                    maxDist[1][k + j][i] = max(maxDist[0][k][i - 1], maxDist[1][k + j][i]);
                    minDist[0][k + j][i] = min(minDist[1][k][i - 1], minDist[0][k + j][i]);
                    minDist[1][k + j][i] = min(minDist[0][k][i - 1], minDist[1][k + j][i]);
                }


                // cout << "maxDist at [0]: " << maxDist[0][k + j][i] << ", at [1]: " << maxDist[1][k + j][i] << endl;
                // cout << "minDist at [0]: " << minDist[0][k + j][i] << ", at [1]: " << minDist[1][k + j][i] << endl;
            }
        }

    }

    cout << max(max(maxDist[0][n][s.size()], maxDist[1][n][s.size()]), min(minDist[0][n][s.size()], minDist[1][n][s.size()]) * -1) << "\n";
}
