#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int x, y;
        cin >> x >> y;

        if (x > y || (x == 0 && (y % 2 == 0))) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";


        int total{ y + x + 1};
        
        int curr{ 1 };

        if (y > x) {
            if ((y - x) % 2 == 1) {
                int root{ y - x };
                for (int i = 1; i < root; ++i)
                    cout << (total - i) << " " << (total - root) << "\n";
                curr = root;
            } else {
                int root{ y - x + 1 };
                for (int i = 1; i < root; ++i)
                    cout << (total - i) << " " << (total - root) << "\n";
                curr = root;
            }
        } 

        y -= curr;

        while (x > 0 && y > 0) {
            cout << (total - curr) << " " << (total - (curr + 1)) << "\n"; // E
            curr++;
            cout << (total -curr) << " " << (total - (curr + 1)) << "\n"; // O
            curr++;
            x--;
            y--;
        }

        if (x > 0)
            cout << (total -curr) << " " << (total - (curr + 1)) << "\n"; // E
    }
}
