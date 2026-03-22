#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    string a, b;
    cin >> a >> b;

    vector<int> alphA(26, 0);
    vector<int> alphB(26, 0);

    int r{ 0 }, s{ 0 };
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == b[i]) {
            r++;
            continue;
        }

        alphA[a[i] - 'A']++;
        alphB[b[i] - 'A']++;
    }

    for (int i = 0; i < 26; ++i) {
        s += min(alphA[i], alphB[i]);
    }

    cout << r << " " << s << "\n";
}
