#include <cmath>
#include <iostream>

using namespace std;

int main() {
    long long m;
    cin >> m;

    while (cin >> m) {
        cout << (long long)floor((-1 + sqrt(1 + 8 * m)) / 2) << endl;
    }
}
