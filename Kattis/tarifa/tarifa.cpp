#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int X, N;
    cin >> X >> N;
    int P;
    int res = 0;
    while (cin >> P) {
        res += X - P;
    }
    cout << res + X;
}
