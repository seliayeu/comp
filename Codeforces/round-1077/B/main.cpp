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
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> seats;
        seats.reserve(n);

        for (int i = 0; i < n; ++i) {
            if (s[i] == '1')
                seats.push_back(i);
        }

        if (seats.size() == 0) 
            cout << max(1, static_cast<int>((n - 1) / 3) + 1) << "\n";
        else {
            int total{ 0 };
            total += max(0, (seats[0] + 1) / 3);
            for (int i = 1; i < seats.size(); ++i) {
                total += max(0, (seats[i] - (seats[i - 1] + 1)) / 3);
            }
            total += max(0, (n - seats[seats.size() - 1]) / 3);
            total += seats.size();
            cout << total << "\n";;
        }
    }
}

// 2 -> 1
// 3 -> 1
// 4 -> 1
// 5 -> 2
