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

    vector<int> a(2e5);
    while (t--) {
        int n, m, l;
        cin >> n >> m >> l;

        int numAtMin1{ 0 };
        int min1{ 0 };
        int numAtMin2{ 0 };
        int min2{ 0 };
        int numAtMax{ 0 };
        int max{ 0 };

        a.resize(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < m; ++i) {
            int delta{ a[i] };
            if (numAtMin2 > 0) {

            }
        }

    }
}
