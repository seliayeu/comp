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

    int A{ 0 }, B{ 0 };

    char team{ 0 };
    for (auto c : s) {
        if (team == 'A') {
            A += c == '1' ? 1 : 2;
            team = 0;
        } else if (team == 'B') {
            B += c == '1' ? 1 : 2;
            team = 0;
        } else {
            team = c;
        }
    }

    cout << (A > B ? 'A' : 'B') << "\n";
}
