#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    float res = 0, q, y;

    while (cin >> q >> y) {
        res += q * y;
    }
    cout << res;
}
