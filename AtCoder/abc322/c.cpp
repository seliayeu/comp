#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int M, N;

    cin >> N >> M;
    int day;
    int currDay = 1;

    while (cin >> day)
        while (currDay <= day) {
            cout << day - currDay << endl;
            currDay += 1;
        }
}
