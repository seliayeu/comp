#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> moves(43201, 0);

    int n;
    cin >> n;

    int maxTime{ 0 };
    for (int i = 0; i < n; ++i) {
        int d, t;
        cin >> d >> t;

        moves[t]++;
        moves[t - d]++;
        moves[t - 2 * d]++;
        maxTime = max(maxTime, t);
    }

    int minCooks{ 0 };
    for (int i = 1; i <= maxTime; ++i) {
        if (moves[i] == 0)
            continue;
        minCooks = max(minCooks, (moves[i] + 2 - 1) / 2);
    }

    cout << minCooks << "\n";
}
