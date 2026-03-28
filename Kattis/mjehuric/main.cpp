#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> p(5);
    for (int i = 0; i < 5; ++i)
        cin >> p[i];

    while (!is_sorted(p.begin(), p.end())) {
        if (p[0] > p[1]) {
            swap(p[0], p[1]);
            for (int i = 0; i < 5; ++i)
                cout << p[i] << " ";
            cout << "\n";
        }
        if (p[1] > p[2]) {
            swap(p[1], p[2]);
            for (int i = 0; i < 5; ++i)
                cout << p[i] << " ";
            cout << "\n";
        }
        if (p[2] > p[3]) {
            swap(p[2], p[3]);
            for (int i = 0; i < 5; ++i)
                cout << p[i] << " ";
            cout << "\n";
        }
        if (p[3] > p[4]) {
            swap(p[3], p[4]);
            for (int i = 0; i < 5; ++i)
                cout << p[i] << " ";
            cout << "\n";
        }
    }
}
