#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i)
            cin >> a[i];

        int swap{ -1 };
        for (int i = 0; i < n; ++i) {
            if (a[i] == n - i)
                continue;
            swap = i;
            break;
        }       

        int target{ -1 };
        if (swap != -1) {
            for (int i = swap + 1; i < n; ++i) {
                if (a[i] == n - swap) {
                    target = i;
                }
            }
        }

        // cout << "swap " << swap << " target " << target <<endl;
        
        int ind{ 0 };
        while (ind < n) {
            if (swap == -1 || ind < swap || ind > target) {
                cout << a[ind];
                cout << " \n"[ind == (n - 1)];
                ind++;
                continue;
            }
    
            int diff{ 0 };
            while (ind + diff <= target) {
                cout << a[target - diff];
                cout << " \n"[ind + diff == (n - 1)];
                diff++;
            }
            ind = target + 1;
        }

    }
}
