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
        list<int> a;
        int n, k, p, m;
        cin >> n >> k >> p >> m;

        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            a.push_back(tmp);
        }

        p--;
        auto res{ 0 };
        while (m > 0) {
            if (p < k) {
                auto iter{ a.begin() };
                advance(iter, p);
                auto val{ *iter };
                if (val <= m) {
                    res++;
                    m -= val;
                    a.erase(iter);
                    a.push_back(val);
                    p = n - 1;
                    continue;
                }
                break;
            } 
            
            auto minIter{ a.begin() };
            auto curIter{ a.begin() };
            auto curMin{ numeric_limits<int>::max() };

            for (int i = 0; i < k; ++i) {
                if (*curIter < curMin) {
                    minIter = curIter;
                    curMin = *curIter;
                }
                curIter++;
            }

            auto val{ *minIter };
            if (val > m)
                break;
            
            m -= val;
            p--;
            a.erase(minIter);
            a.push_back(val);
        }

        cout << res << "\n";
    }
}
