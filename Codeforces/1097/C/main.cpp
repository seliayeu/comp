#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    unordered_map<int, int> cs;
    vector<bool> ps(5 * 100000);

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ps.resize(0);
        for (auto& c : s) {
            if (c == '(') {
                ps.push_back(true);
                continue;
            }
            if (ps.size() > 0 && ps.back() == true) {
                ps.pop_back();
            } else
                ps.push_back(false);
        }

        auto numOpen{ static_cast<int>(count(ps.begin(), ps.end(), true)) };
        auto numClose{ static_cast<int>(ps.size()) - numOpen };

        if (numOpen != 0 && numClose != 0)
            continue;
       
        if (numOpen != 0) {
            cs[numOpen]++;
            // cout << "added to map [" <<numOpen<< "]: " << cs[numOpen] << endl;
        } else {
            cs[-numClose]++;
            // cout << "added to map [" <<-numClose<< "]: " << cs[-numClose] << endl;
        }
    }
    
    int total{ 0 };
    for (auto& [k, v] : cs) {
        if (k == 0) {
            total += v / 2;
            continue;
        }
        if (v == 0)
            continue;
        if (cs.find(-k) == cs.end())
            continue;
        int m{ min(v, cs[-k]) };
        total += m;
        cs[k] -= m;
        cs[-k] -= m;
    }

    cout << total << "\n";
}
// )()()()(((((()))))))
