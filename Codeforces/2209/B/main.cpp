#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <map>
#include <vector>
#include <unordered_map>
#include <set>
#include <string>
#include <unordered_set>

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
    vector<int> a;
    a.reserve(5000);
    while (t--) {
        int n;
        cin >> n;
        a.resize(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i) {
            int totalLess{ 0 }, totalMore{ 0 };
            for (int j = i + 1; j < n; ++j) {
                if (a[j] < a[i]) {
                    totalLess++;
                } else if (a[i] < a[j]) {
                    totalMore++;
                }

            }
            cout << max(totalLess, totalMore) << " ";
        }
        cout << "\n";
    }
}
