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

        tm t{};

        vector<long> s;
        vector<long> e;
        s.resize(b);
        e.resize(b);
        for (int i = 0; i < b; ++i) {
            string tmp, d, h;
            cin >> tmp >> d >> h;
            stringstream sss(d + " " + h);
            cin >> d >> h;
            stringstream sse(d + " " + h);
            sss >> get_time(&t, "%Y-%m-%d %H:%M");
            long start{ mktime(&t) };
            sse >> get_time(&t, "%Y-%m-%d %H:%M");
            long end{ mktime(&t) + c * 60 };

            s[i] = start;
            e[i] = end;
        }

        sort(s.begin(), s.end());
        sort(e.begin(), e.end());

        int curr{ 0 };
        int res{ 0 };

        auto sIter{ s.begin() };
        auto eIter{ e.begin() };
        while (eIter != e.end()) {
            if (sIter != s.end() && *sIter < *eIter) {
                curr++;
                sIter++;
            } else {
                curr--;
                eIter++;
            }
            res = max(curr, res);
        }

        cout << res << "\n";;

    }
}
