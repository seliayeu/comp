#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int iH, iW;
    cin >> iH >> iW;
    int kH, kW;
    cin >> kH >> kW;

    vector<vector<int>> image(iH, vector<int>(iW));

    for (int i = 0; i < iH; ++i) {
        for (int j = 0; j < iW; ++j) {
            cin >> image[i][j];
        }
    }

    vector<vector<int>> kernel(kH, vector<int>(kW));

    for (int i = kH - 1; i >=0; --i) {
        for (int j = kW - 1; j >= 0; --j) {
            cin >> kernel[i][j];
        }
    }

    for (int i = 0; i < iH - kH + 1; ++i) {
        for (int j = 0; j < iW - kW + 1; ++j) {
            int sum{ 0 };
            for (int k = 0; k < kH; ++k) {
                for (int l = 0; l < kW; ++l) {
                    sum += kernel[k][l] * image[i + k][j + l];
                }
            }
            cout << sum << " ";
        }
        cout << "\n";
    }
}
