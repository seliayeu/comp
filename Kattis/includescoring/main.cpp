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

    vector<array<int, 5>> v(n);
    for (int i = 0; i < n; ++i) {
        array<int, 5>& a{ v[i] };
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        a[4] = i;
    }
    
    auto c1{ [](array<int, 5>& a, array<int, 5>& b) {
        if (a[0] > b[0])
            return true;
        if (b[0] > a[0])
            return false;
        if (a[1] < b[1])
            return true;
        if (b[1] < a[1])
            return false;
        if (a[2] < b[2])
            return true;
        if (b[2] < a[2])
            return false;
        return false;
    }};

    auto e1{ [](array<int, 5>& a, array<int, 5>& b) {
        if (a[0] > b[0])
            return true;
        if (b[0] > a[0])
            return false;
        if (a[1] < b[1])
            return true;
        if (b[1] < a[1])
            return false;
        if (a[2] < b[2])
            return true;
        if (b[2] < a[2])
            return false;
        return false;
    }};
       
}
