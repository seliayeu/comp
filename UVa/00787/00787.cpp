#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        long long prod = 1;
        int temp;
        long long best = -999999;

        vector<int> nums;

        while (ss >> temp) {
            if (temp == -999999)
                break;
            nums.push_back(temp);
        }

        for (auto num : nums) {
            prod *= num;
            best = max(prod, best);

            if (prod == 0)
                prod = 1;
        }

        prod = 1;

        for (int i = nums.size() - 1; i >= 0; --i) {
            prod *= nums[i];
            best = max(prod, best);
            if (prod == 0)
                prod = 1;
        }

        cout << best << endl;
    }
}
