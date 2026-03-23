#include <bits/stdc++.h>

using namespace std;

typedef __uint128_t ulll;
typedef unsigned long long ull;
typedef long long ll;

ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> M >> N;

    string cs;
    cin >> cs;

    char c;
    c = cs[1];

    vector<string> f1(M);
    vector<string> f2(M);
    vector<string> f3(M);

    int posX{ -1 }, posY{ -1 };

    for (int i = 0; i < M; ++i) {
        cin >> f1[i];
        f3[i] = f1[i];
        
        auto iter{ find(f1[i].begin(), f1[i].end(), c) };
        if (iter != f1[i].end() && posX == -1) {
            posY = i;
            posX = distance(f1[i].begin(), iter);
        }
    }

    int deltaX{ numeric_limits<int>::max() }, deltaY{ numeric_limits<int>::max() };
    for (int i = 0; i < M; ++i) {
        cin >> f2[i];
        for (int j = 0; j < N; ++j) {
            if (f2[i][j] != c) {
                f3[i][j] = f2[i][j];
            }
        }
        auto iter{ find(f2[i].begin(), f2[i].end(), c) };
        if (iter != f2[i].end() && deltaX == numeric_limits<int>::max()) {
            int x{ static_cast<int>(distance(f2[i].begin(), iter)) };
            deltaX = x - posX;
            deltaY = i - posY;
        }
    }

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (f2[i][j] != c)
                continue;

            if (i + deltaY >= 0 && i + deltaY < M && j + deltaX >= 0 && j + deltaX < N)
                f3[i + deltaY][j + deltaX] = c;
        }
    }

    for (int i = 0; i < M; ++i) {
        cout << f3[i] << "\n";
    }

}
