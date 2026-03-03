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
    cin >>t;
    vector<int> a(2 * 100000 + 1);

    while (t--) {
        int n;
        cin >> n;
        a.resize(n);
        unordered_map<int, int> inds;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            inds[a[i]] = i;
        }

        bool no{ false };
        for (int i = 1; i <= n; ++i) {
            if (a[i] == i)
                continue;

            bool d{ (inds[i] % i) == 0 };
            auto num{ inds[i] / i };
            auto m{ (num & (num - 1)) == 0 };
            if (!(d && m)) {
                cout << "NO\n";
                no = true;
                break;
            }
            int tmp{ inds[i] };
            int old{ a[i] };
            swap(a[i], a[inds[i]]);
            inds[old] = tmp;
        }

        if (!no)
            cout << "YES\n";
        
    }
}// 4 1 3 2 5
 // find 1 -> index ?, k
