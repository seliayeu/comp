#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 676767677;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        

        vector<int> b(n);
        vector<pair<int, int>> bS(n);
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            bS[i].second = i;
            bS[i].first = b[i];
        }

        sort(bS.begin(), bS.end());

        ll total{ 1 };
        int prevA{ 0 };
        ll nums{ 0 };
        ll prevNums{ 0 };

        for (int i = 0; i < n; ++i) {
            auto [a, ind] = bS[i];

            if (a != prevA) {
                prevNums = nums;
                nums = i;
                prevA = a;
            }

            if (a == 0) {
                total *= 1LL;
            } else {
                int prev, next;
                if (ind == 0) { 
                    prev = m;
                    next = b[ind + 1];
                } else if (ind == n - 1) {
                    prev = b[ind - 1];
                    next = m;
                } else {
                    prev = b[ind - 1];
                    next = b[ind + 1];
                }

                if (prev >= a && next >= a) {
                    total = 0;
                    break;
                } else if (a - prev > 1 || a - next > 1) {
                    total *= (nums - prevNums);
                } else {
                    total *= nums;
                }
                total %= MOD;
            }
        }

        cout << total << "\n";
    }
}
