#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

unsigned query(const vector<unsigned>& cows, unsigned n, int cowInd, unsigned newVal) {
    unsigned numAbove{ 0 };
    unsigned subtreeSize{ 1 };
    unsigned subtreeLevel{ 1 };
    
    cowInd = (2 * (1U << n) - 1) - cowInd;
    while (true) {
        if (cowInd == 0)
            break;
        if (cowInd % 2 == 0) {
            if (newVal < cows[cowInd - 1]) {
                numAbove += subtreeSize;
            }
            newVal = newVal ^ cows[cowInd - 1];
        } else {
            if (newVal <= cows[cowInd + 1]) {
                numAbove += subtreeSize;
            }
            newVal = newVal ^ cows[cowInd + 1];
        }
        cowInd = (cowInd - 1) / 2;
        subtreeSize = 1 << subtreeLevel;
        subtreeLevel += 1;
    }

    return numAbove;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    vector<unsigned> cows(2 * (1U << 18) - 1);
    while (t--) {
        unsigned n, q;
        cin >> n >> q;
        unsigned numCows{ 1U << n };
        cows.resize(2 * numCows - 1);
        
        for (unsigned i = 0; i < numCows; ++i)
            cin >> cows[2 * numCows - 2 - i];

        for (unsigned i = numCows; i < 2 * numCows - 1; ++i) {
            auto ind{ 2U * numCows - 2 - i };
            cows[ind] = cows[2 * ind + 1] ^ cows[2 * ind + 2];
        }

        for (unsigned i = 0; i < q; ++i) {
            unsigned b, c;
            cin >> b >> c;
            cout << query(cows, n, b, c) << "\n";
        }
    }
}
