#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<unsigned> arr(2 * 100000);
    vector<unsigned> og(2 * 100000);
    vector<unsigned> lastChange(2 * 100000);
    int t;
    cin >> t;
    while (t--) {
        int n, m, h;
        cin >> n >> m >> h;
        arr.resize(n);
        og.resize(n);
        lastChange.resize(n);

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            og[i] = arr[i];
            lastChange[i] = 0;
        }
    
        int currUpdates{ 0 };
        for (int i = 0; i < m; ++i) {
            unsigned ind, c;
            cin >> ind >> c;
            ind--;
            if (lastChange[ind] < currUpdates) {
                arr[ind] = og[ind];
                lastChange[ind] = currUpdates;
            }
            auto newVal{ arr[ind] + c };
            if (newVal > h)
                currUpdates++;
            else
                arr[ind] = newVal;
        }

        for (int i = 0; i < n; ++i) {
            if (lastChange[i] < currUpdates) {
                cout << og[i] << " ";
            } else {
                cout << arr[i] << " ";
            }
        }
        cout << "\n";
    }
}

