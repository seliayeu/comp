#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> M >> N;

    vector<vector<int>> T(M + 1, vector<int>(N + 1));
    for (int i = 1; i <= M; ++i)
        for (int j = 1; j <= N; ++j)
            cin >> T[i][j];

    vector<int> end(N + 1, 0);

    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            end[j] = max(end[j - 1], end[j]) + T[i][j];
        }
        cout << end[N] << " ";
    }
    cout << "\n";
    

}
