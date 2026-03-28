#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    while (true) {
        int n;
        cin >> n;

        if (n == 0)
            break;

        vector<pair<pair<string, int>, string>> students(n);

        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            pair<string, int> key{ { s.substr(0, 2) }, i };
            students[i] = { key, s };
        }

        sort(students.begin(), students.end());

        for (int i = 0; i < n; ++i) {
            cout << students[i].second << "\n";
        }
        cout << "\n";
    }
}
