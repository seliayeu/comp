#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int l;
    cin >> l;
    vector<int> A(l);
    for (int i = 0; i < l; ++i) {
        cin >> A[i];
    }

    vector<int> g;
    g.reserve(l);
    g.push_back(A[0]);
    for (int i = 1; i < l; ++i) {
        if (A[i] <= g.back())
            continue;
        g.push_back(A[i]);
    }

    cout << g.size() << "\n";
    for (int i = 0; i < g.size(); ++i) {
        cout << g[i] << " ";
    }
    cout << "\n";
}

