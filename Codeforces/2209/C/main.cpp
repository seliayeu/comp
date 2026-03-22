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
    
    auto guess{ [](int i, int j) {
        cout <<  "? " << i << " " << j << "\n";
        cout.flush();
        int tmp;
        cin >> tmp;
        return tmp;
    }};

    auto answer{ [](int i) {
        cout << "! " << i << "\n";
        cout.flush();
    }};

    while (t--) {
        int n;
        cin >> n;

        if (n == 2) {
            if (guess(1, 2)) {
                answer(1);
                continue;
            }
            if (guess(1, 3)) {
                answer(1);
                continue;
            }
            if (guess(2, 3)) {
                answer(2);
                continue;
            }
            answer(4);
            continue;
        }

        int g{ n - 1 };
        bool done{ false };

        for (int i = 0; i < g - 2; ++i) {
            int ind1{ i * 2 + 1 }, ind2{ i * 2 + 2 };
            if (guess(ind1, ind2)) {
                answer(ind1);
                done = true;
                break;
            }
        }

        if (done)
            continue;
        
        int ind1{ (g - 2) * 2 + 1 }, ind2{ (g - 2) * 2 + 2 }, ind3{ (g - 2) * 2 + 3 };
        if (guess(ind1, ind2)) {
            answer(ind1);
            done = true;
            continue;
        }
        if (guess(ind1, ind3)) {
            answer(ind1);
            done = true;
            continue;
        }
        if (guess(ind2, ind3)) {
            answer(ind2);
            done = true;
            continue;
        }

        if (done)
            continue;
        
        ind1 += 3;
        ind2 += 3;
        ind3 += 3;
        if (guess(ind1, ind2)) {
            answer(ind1);
            done = true;
            continue;
        }
        answer(ind3);
    }
}
