#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    auto lastNonZ{ s1.size() - 1 };

    while (lastNonZ != 0) {
        if (s1[lastNonZ] == '0') {
            lastNonZ--;
        } else {
            break;
        }
    }

    auto zeros{ s2.size() - 1 };
    auto nums{ s1.size() };

    int s1Ind{ 0 };

    while (s1Ind < nums && nums - s1Ind > zeros) {
        cout << s1[s1Ind];
        s1Ind++;
    }

    if (s1Ind == nums || s1Ind > lastNonZ) {
        cout << "\n";
        return 0;
    }

    if (s1Ind == 0)
        cout << "0";
    cout << ".";

    while ((nums - s1Ind) < zeros) {
        cout << "0";
        zeros--;
    }

    while (s1Ind < nums && s1Ind <= lastNonZ) {
        cout << s1[s1Ind];
        s1Ind++;
    }
    cout << "\n";
}

