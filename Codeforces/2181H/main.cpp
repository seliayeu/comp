#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    unsigned long long w, h, d;
    std::cin >> w >> h >> d;
    unsigned long long n;
    std::cin >> n;
    auto cakeVolume{ static_cast<__uint128_t>(w) * h * d };

    if (cakeVolume % n != 0) {
        std::cout << -1 << "\n";
        return 0;
    }
    
    auto wCopy{ w };
    std::vector<unsigned long long> wFactorization;
    for (unsigned long long v{ 2 }; v * v <= wCopy; ++v) {
        while (wCopy % v == 0) {
            wCopy /= v;
            wFactorization.push_back(v);
        }
    }
    if (wCopy > 1)
        wFactorization.push_back(wCopy);

    auto hCopy{ h };
    std::vector<unsigned long long> hFactorization;
    for (unsigned long long v{ 2 }; v * v <= hCopy; ++v) {
        while (hCopy % v == 0) {
            hCopy /= v;
            hFactorization.push_back(v);
        }
    }
        if (hCopy > 1)
            hFactorization.push_back(hCopy);

    auto dCopy{ d };
    std::vector<unsigned long long> dFactorization;
    for (unsigned long long v{ 2 }; v * v <= dCopy; ++v) {
        while (dCopy % v == 0) {
            dCopy /= v;
            dFactorization.push_back(v);
        }
    }
    if (dCopy > 1) {
        dFactorization.push_back(dCopy);
    }

    auto sliceVolumeCopy{ cakeVolume / n };
    std::vector<unsigned long long> sliceFactorization;
    for (unsigned long long v{ 2 }; v * v <= sliceVolumeCopy; ++v) {
        while (sliceVolumeCopy % v == 0) {
            sliceVolumeCopy /= v;
            sliceFactorization.push_back(v);
        }
    }
        if (sliceVolumeCopy > 1)
            sliceFactorization.push_back(sliceVolumeCopy);


    unsigned long long resW{ 1 }, resH{ 1 }, resD{ 1 };
    while (sliceFactorization.size() > 0) {
        auto top{ sliceFactorization.back() };
        sliceFactorization.pop_back();

        while (wFactorization.size() != 0 && wFactorization.back() > top) {
            resW *= wFactorization.back();
            wFactorization.pop_back();
        }
        while (hFactorization.size() != 0 && hFactorization.back() > top) {
            resH *= hFactorization.back();
            hFactorization.pop_back();
        }
        while (dFactorization.size() != 0 && dFactorization.back() > top) {
            resD *= dFactorization.back();
            dFactorization.pop_back();
        }

        if (wFactorization.size() != 0 && wFactorization.back() == top) {
            wFactorization.pop_back();
        } else if (hFactorization.size() != 0 && hFactorization.back() == top) {
            hFactorization.pop_back();
        } else if (dFactorization.size() != 0 && dFactorization.back() == top) {
            dFactorization.pop_back();
        }
    }

    while (!wFactorization.empty()) {
        resW *= wFactorization.back();
        wFactorization.pop_back();
    }
    while (!hFactorization.empty()) {
        resH *= hFactorization.back();
        hFactorization.pop_back();
    }
    while (!dFactorization.empty()) {
        resD *= dFactorization.back();
        dFactorization.pop_back();
    }

    std::cout << resW - 1 << " " << resH - 1 << " " << resD - 1 << "\n";
}
