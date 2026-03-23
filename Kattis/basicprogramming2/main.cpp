#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, t;
    cin >> N >> t;

    vector<int> v(N);

    for (int i = 0; i < N; ++i) 
        cin >> v[i];

    sort(v.begin(), v.end());

    if (t == 5) {
        for (int i = 0; i < N; ++i) {
            if (v[i] >= 100 && v[i] <= 999)
                cout << v[i] << " ";
        }
        cout << "\n";
    } else if (t == 4) {
        if (N % 2 == 0) {
            cout << v[(N / 2) - 1] << " " << v[N/2] << "\n";
        } else 
            cout << v[N / 2] << "\n";
    } else if (t == 3) {
        int count{ 1 };
        for (int i = 1; i < N; ++i) {
            if (v[i] == v[i - 1])
                count++;
            else
                count = 1;

            if (count > N / 2) {
                cout << v[i] << "\n";
                return 0;
            }
        }
        cout << "-1\n";
    } else if (t == 2) {
        if (std::set(v.begin(), v.end()).size() == v.size())
            cout << "Unique\n";
        else
            cout << "Contains duplicate\n";
    } else {
        for (int i = 0; i < N; ++i) {
            if (binary_search(v.begin() + i + 1, v.end(), 7777 - v[i])) {
                cout << "Yes\n";
                return 0;
            }
        }
        cout << "No\n";
    }

}
