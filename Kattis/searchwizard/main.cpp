#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n;
    cin >> n;

    int res{ 0 };
    for (int i = 0; i < n; ++i) {
        string tmp;
        cin >> tmp;
        auto ind{ -1 };
        while ((ind = tmp.find(s, ind + 1)) != string::npos)
            res++;
    }

    cout << res << "\n";

}
