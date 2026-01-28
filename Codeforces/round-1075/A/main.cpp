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
        int n, h, l;
        cin >> n >> h >> l;

        vector<int> v(n);

        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        int res{ 0 };
        int maxX{ -1 }, maxY{ -1 };
        for (int i = 0; i < n; ++i) {
            if (maxX == -1 && v[i] > h)
                maxX = i; 
            if (maxY == -1 && v[i] > l)
                maxY = i;
        }
        // 3 6
        // 1 3 4 4 5 6 10
        // 2 6
        // cout << "===" << maxX << " " << maxY << endl;

        if (maxX == -1)
            maxX = n;
        if (maxY == -1)
            maxY = n;
        if (maxX < 1 || maxY < 1) {
            cout << 0 << "\n";
            continue;
        }

        res += min(max(maxX, maxY) - min(maxX, maxY), min(maxX, maxY));
        if ((min(maxX, maxY) - res) > 1)
            res += (min(maxX, maxY) - res) / 2;
        cout << res << "\n";

        // n! / (n - r)!

        // maxX is 3, maxY is 6.  -> added 3 to res.
        // we haev array. choose 2k<=n . find number of pairs where x<=h, y<=l.
        // 2 2 2 2 x 3 4 4 y
        // 4,2
        // 2 3, 2 4, 2 4
        // sum of bigger - smaller, 

        // int total{ 0 };
        //
        // int prevX{ -1 };
        // for (int i = 0; i < n; ++i) {
        //     cout << "i: " << i << " v[i]: " << v[i] << " prevX: " << prevX << endl;
        //     if (v[i] > h) break;
        //     if (v[i] == prevX) continue;
        //     int prevY{ -1 };
        //     for (int j = 0; j < n; ++j) {
        //         cout << "j: " << j << " v[j]: " << v[j] << " prevY: " << prevY << " total: " << total << endl;
        //         if (i == j) continue;
        //         if (v[j] > l) break;
        //         if (v[j] == prevY) continue;
        //         total += 1;
        //         prevY = v[j];
        //     }
        //     prevX = v[i];
        // }
    // 2 2 2 2 3 4 4 7
        // cout << total << "\n";
    }
}
