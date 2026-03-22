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

    int N, M;
    cin >> N >> M;
    vector<string> dance(N);
    for (int i = 0; i < N; ++i)
        cin >> dance[i];

    int moves{ 0 };
    bool d{ false };
    for (int i = 0; i < M; ++i) { 
        d = false;
        for (int j = 0; j < N; ++j) {
            if (dance[j][i] == '$') {
                d = true;
                break;
            }
        }
        if (!d)
            moves++;
    }

    cout << moves + d <<"\n";
}
