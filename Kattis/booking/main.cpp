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
        int b, c;
        cin >> b >> c;

        tm t;

        vector<pair<long, long>> v;
        v.reserve(b);
        for (int i = 0; i < b; ++i) {
            string s, d, h;
            cin >> s >> d >> h;
            stringstream sss(d + " " + h);
            cin >> d >> h;
            stringstream sse(d + " " + h);
            sss >> get_time(&t, "%Y-%m-%d %H:%M");
            long start{ mktime(&t) };
            sse >> get_time(&t, "%Y-%m-%d %H:%M");
            long end{ mktime(&t) + c * 60 };

            v.push_back({start, end} );
        }

        sort(v.begin(), v.end());

        int maxOverlap{ 0 };

        for (int i = 0; i < b; ++i) {
            auto [si, ei]{  v[i] };
            int overlap{ 0 };
            for (int j = 1; j < b; ++j) {
                auto [sj, ej]{  v[j] };
                if (sj < ei) {
                    overlap++;
                }
            }
            
        }
    }
}
