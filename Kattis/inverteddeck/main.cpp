#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int startInd{ numeric_limits<int>::max() };
    for (int i = 0; i < n - 1; ++i) {
        if (v[i] <= v[i + 1])
            continue;
        startInd = i;
        while (startInd >= 0 && v[startInd] == v[i]) {
            startInd--;
        }
        break;
    }
    
    if (startInd != numeric_limits<int>::max())
        startInd += 1;

    int endInd{ numeric_limits<int>::max() };
    for (int i = n - 1; i > 0; --i) {
        if (v[i - 1] <= v[i])
            continue;

        endInd = i;
        while (endInd <= n - 1 && v[endInd] == v[i])
            endInd++;
        break;
    }

    if (endInd != numeric_limits<int>::max())
        endInd--;

    if (endInd == numeric_limits<int>::max() && startInd == numeric_limits<int>::max()) {
        cout << "1 1\n";
        return 0;
    }

    if (!is_sorted(v.begin() + startInd, v.begin() + endInd + 1, [](int x, int y) {return y < x;})) {
        cout << "impossible\n";
        return 0;
    }

    sort(v.begin() + startInd, v.begin() + endInd + 1);
    if (is_sorted(v.begin(), v.end())) {
        cout << startInd + 1 << " " << endInd + 1 << "\n";
    } else {
        cout << "impossible\n";
    }
}
