#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> P(N);
        vector<int> postMin(N, numeric_limits<int>::max());
        vector<int> res;
        res.reserve(N);

        int curr{ 1 };
        for (int i = 0; i < N; ++i) {
            cin >> P[i];
        }

        if (N == 1) {
            cout << "0\n";
            continue;
        }

        postMin[N - 2] = P[N - 1];

        for (int i = N - 3; i >= 0; --i)
            postMin[i] = min(postMin[i + 1], P[i + 1]);

        for (int i = 0; i < N - 1; ++i) {
            if (postMin[i] < P[i]) {
                res.push_back(P[i]);
            }
        }
        
        sort(res.begin(), res.end());
        cout << res.size() << "\n";
        for (int i = 0; i < res.size(); ++i) {
            cout << res[i] << "\n";
        }
    }
}
