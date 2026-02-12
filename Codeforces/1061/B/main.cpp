#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> c(n);

    int highest{ 0 };
    long long total{ 0 };
    for (int i = 0; i < n; ++i) {
        int tmp;
        cin >> tmp;
        total += tmp;
        tmp -= 1;
        c[i] = tmp;
        highest = max(highest, c[i]);
    }
    vector<bool> rv(highest, 0);

    sort(c.begin(), c.end());

    auto np{ 0 };
    auto last{ rv.begin() };
    for (int i = 0; i < n; ++i) {
        np += 1;
        if (rv[c[i]] == 0) {
            rv[c[i]] = 1;
            continue;
        }
        auto ind{ find(last, rv.end(), 0) };
        if (last == rv.end() || distance(rv.begin(), ind) > c[i])
            continue;
        last = ind;
        *ind = 1;
    }
    
    cout << (total - (np + count(rv.begin(), rv.end(), 0))) << "\n";
}
