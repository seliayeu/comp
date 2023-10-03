#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;

    while (cin >> N) {
        if (N == 0)
            return 0;

        int curr = 0, temp, best = 0;

        for (int i = 0; i < N; ++i) {
            cin >> temp;
            curr += temp;
            best = max(curr, best);

            if (curr < 0)
                curr = 0;
        }
        if (best > 0)
            cout << "The maximum winning streak is " << best << ".\n";
        else
            cout << "Losing streak.\n";
    }
}
