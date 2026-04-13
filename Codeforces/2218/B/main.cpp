#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        vector<int> v(7);
        for (int i = 0;i < 7; ++i)
            cin >> v[i];

        sort(v.begin(), v.end());
        for (int i = 0; i < 6; ++i)
            v[i] *= -1;


        cout << accumulate(v.begin(), v.end(), 0) <<"\n";
    }
}
