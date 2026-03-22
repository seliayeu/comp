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

    int s, n, m;
    cin >> s >> n >> m;
    
    vector<int> prices(s + 1);

    for (int i = 1; i <= s; ++i)
        cin >> prices[i];

    auto checkPeak{ [&](int i) {
        auto s1{ prices.begin() };
        advance(s1, i);
        auto e1{ s1 };
        advance(e1, n);
        auto s2{ e1 - 1 };
        auto e2{ s2 };
        advance(e2, n);

        if (is_sorted(s1, e1) && is_sorted(s2, e2, std::greater<>())) {
            return true;
        }
        return false;
    }};

    auto checkValley{ [&](int i) {
        auto s1{ prices.begin() };
        advance(s1, i);
        auto e1{ s1 };
        advance(e1, m);
        auto s2{ e1 - 1 };
        auto e2{ s2 };
        advance(e2, m);
        if (is_sorted(s1, e1, std::greater<>()) && is_sorted(s2, e2)) {
            return true;
        }
        return false;
    }};

    int nP{ 0 }, nV{ 0 };
    for (int i = 1; i <= s; ++i) {
        int valleyE{ i + 2 * m - 2 }, peakE{ i + 2 * n - 2 };

        if (peakE > s && valleyE > s)
            break;
        if (peakE <= s)
            nP += checkPeak(i);
        if (valleyE <= s)
            nV += checkValley(i);
    }

    cout << nP << " " << nV << "\n";
}
