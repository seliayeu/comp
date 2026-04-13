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
    while (n != 0) {
        int s1{ 0 }, s2{ 0 };

        for (int i = 0; i < n; ++i) {
            string dir;
            int num;
            cin >> dir >> num;

            if (dir == "DROP") {
                s2 += num;
                cout << "DROP 2 " << num << "\n";
            } else {
                if (s1 < num) {
                    if (s1 > 0) {
                        cout << "TAKE 1 " << s1 << "\n";
                        num -= s1;
                    }
                    cout << "MOVE 2->1 " << s2 << "\n";
                    s1 = 0;
                    s1 = s2;
                    s2 = 0;
                }

                cout << "TAKE 1 " << num << "\n";
                s1 -= num;
            }
        }
        cout << "\n";
        cin >> n;
    }
}
