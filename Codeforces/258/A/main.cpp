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

    bool deleted{ false };
    
    for (int i = 0; i < s.size(); ++i) {
        if (i == s.size() - 1 && !deleted)
            continue;
        if (s[i] == '1')
            cout << s[i];
        else {
            if (deleted)
                cout << s[i];
            else {
                deleted = true;
            }
        }
    }
}

// 10, 4 -> 10 / 2 is 5. 10 / 1 is 10. is there a multiple of 4 between 5 and 10? yes -> yes
