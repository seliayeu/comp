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
    cin >> n;

    int l = 0, r = n - 1;
    map<int, int> valToInd;
    map<int, int> indToVal;

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        val -= 1;
        indToVal[i] = val;
        valToInd[val] = i;
    }

    for (int i = 0; i < n; ++i) {
        int ind, val;
        if (i % 2 == 0) {
            ind = valToInd[l];
            val = l;
            l++;
        } else {
            ind = valToInd[r];
            val = r;
            r--;
        }

        // cout << "current " << ind << " " << val << endl;

        cout << abs(val - ind) << endl;

        if (val == ind)
            continue;
        else if (val < ind) {
            int prev = val;
            for (int j = val; j <= ind; ++j) {
                int v = indToVal[j];
                valToInd[v]++;
                indToVal[j] = prev;
                prev = v;
            }
        } else {
            int prev = val;
            for (int j = val; j >= ind; --j) {
                int v = indToVal[j];
                valToInd[v]--;
                indToVal[j] = prev;
                prev = v;
            }
        }
    }
}
