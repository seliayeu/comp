#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    string s1, s2;
    cin >> s1 >> s2;

    if (N % 2 == 0) { // same
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                cout << "Deletion failed\n";
                return 0;
            }
        }

        cout << "Deletion succeeded\n";
        return 0;
    }

    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] == s2[i]) {
            cout << "Deletion failed\n";
            return 0;
        }
    }

    cout << "Deletion succeeded\n";
}
