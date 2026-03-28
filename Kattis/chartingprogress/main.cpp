#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int prev{ -1 };
    int total{ -1 };
    string l;
    while (getline(cin, l)) {
        if (l.empty()) {
            prev = -1;
            total = -1;
            cout << "\n";
            continue;
        }
            
        if (total == -1) {
            total = l.size();
            prev = l.size();
        }
        int s{ static_cast<int>(count(l.begin(), l.end(), '*')) };
        for (int i = 0; i < total; ++i) {
            if (i >= prev - s && i < prev) {
                cout << '*';
            } else
                cout << '.';
        }
        prev -= s;
        cout << "\n";
    }
}
