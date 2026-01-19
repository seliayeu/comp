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
    while (t--) {

        int n;
        cin >> n;

        vector<ll> vals(n);
        ll minPos{MOD};

        for (int i = 0; i < n; ++i) {
            ll tmp;
            cin >> tmp;
            vals[i] = tmp;
        }
        sort(vals.begin(), vals.end());
        
        int ind{ 1 };

        int currStretch{ 1 };
        int currStart{ 0 };
        int maxStretch{ 1 };
        int maxStart{ 0 };
        
        while (ind < n) {
            if (vals[ind] == vals[ind - 1]) {
                ind++;
                continue;
            }
            if (vals[ind] == vals[ind - 1] + 1) {
                currStretch += 1;
                if (currStretch > maxStretch) {
                    maxStretch = currStretch;
                    maxStart = currStart;
                }
            } else {
                currStretch = 1;
                currStart = ind;
            }
            ind++;
        }

        cout << maxStretch << "\n";
    }
}

