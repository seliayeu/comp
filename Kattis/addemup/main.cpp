#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s;
    cin >> n >> s;

    vector<int> v;
    map<int, int> m;
    v.reserve(2 * n);

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back(x);
        vector<int> digs;
        int y{ x };
        while (y) {
            digs.push_back(y % 10);
            y /= 10;
        }
    
        bool flip{ true };
        vector<int> newNum;
        newNum.reserve(digs.size());
        for (int i = digs.size() - 1; i >= 0; --i) {
            if (digs[i] == 3 || digs[i] == 4 || digs[i] == 7) {
                flip = false;
                break;
            } else if (digs[i] == 6)
                newNum.push_back(9);
            else if (digs[i] == 6)
                newNum.push_back(9);
            else
                newNum.push_back(digs[i]);
        }
        int curr{ 1 };
        for (int i = 0; i < digs.size(); ++i) {
            y += curr * newNum[i];
            curr *= 10;
        }
        if (x != y)
            v.push_back(y);
        if (m.count(x) != 0) { // the unflipped number appears
            m.erase(x);
            m.erase(y);
        } else {
            m[x] = y;
            m[y] = x;
        }
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); ++i) {
        int a{ v[i] };
        auto bIter{ lower_bound(v.begin() + i, v.end(), s - a) };
        if (bIter == v.end())
            continue;
        int b{ *bIter };
        if (b + a != s || m.count(a) != 0 && m[a] == b)
            continue;
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
}
