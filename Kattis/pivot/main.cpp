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
    vector<int> A(n);
    vector<int> preMax(n, numeric_limits<int>::min());
    vector<int> postMin(n, numeric_limits<int>::max());

    int currMax{ numeric_limits<int>::min() };
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        if (i > 0) {
            currMax = max(currMax, A[i - 1]);
            preMax[i] = currMax;
        }
    }

    int currMin{ numeric_limits<int>::max() };
    for (int i = n - 2; i >= 0; --i) {
        currMin = min(currMin, A[i + 1]);
        postMin[i] = currMin;
    }

    int res{ 0 };
    for (int i = 0; i < n; ++i) {
        if (i == 0 && postMin[i] > A[i]) {
            res++;
        } else if (i == n - 1 && preMax[i] < A[i]) {
            res++;
        } else if (i > 0 && i < n - 1 && preMax[i] < A[i] && postMin[i] > A[i]) {
            res++;
        }
    }

    cout << res << "\n";
}
