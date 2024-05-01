#include <algorithm>
#include <cassert>
#include <climits>
#include <deque>
#include <iostream>
#include <limits.h>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        vector<int> arr1(n), arr2(n);
        for (int i = 0; i < n; ++i)
            cin >> arr1[i];
        for (int i = 0; i < n; ++i)
            cin >> arr2[i];
        vector<int> sortedArr1 = arr1, sortedArr2 = arr2;
        sort(sortedArr1.begin(), sortedArr1.end());
        sort(sortedArr2.begin(), sortedArr2.end());

        for (int i = 0; i < n; ++i) {
            int ind = find(sortedArr1.begin(), sortedArr1.end(), arr1[i]);
            cout << sortedArr2[ind];
        }
    }
}
