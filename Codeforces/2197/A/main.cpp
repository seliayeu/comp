#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int c(int num) {
    int res{ 0 };
    while (num > 0) {
        res += num % 10;
        num /= 10;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // for (int i = 1; i < 1000000001; ++i) {
    //     total[i] += c(i);
    // }


    int t;
    cin >> t;
    while (t--) {
        unsigned x;
        cin >> x;
        // cout << total[x] << "\n";
        if (x == 90 || x == 990 || x == 9990 || x == 99990 || x == 999900 || x == 9000000 
                || x == 90000000 || x == 900000000) {
            cout << "0\n";
            continue;
        }
        cout << ((x % 9u == 0) ? 10 : 0) << "\n";
    }

    // 5 + ? = 
    // 10 - 1 = 9
    // 11 - 2 = 9
    // 13 - 4 = 9
    // 14 - 5 = 9
    // ...
    // 19 - 10 = 9
    // 20 - 2 = 18
    // 30 - 3 = 27
    // 31 - 4 = 27
    //
    // 40 - 4 = 36
    // 99 - 18 = 81
    // 100 - 1 = 99
    // 123401 - 11
    //
}
