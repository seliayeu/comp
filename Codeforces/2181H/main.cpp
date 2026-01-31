#include <iostream>
#include <vector>

int main() {
    unsigned long long w, h, d;
    std::cin >> w >> h >> d;
    unsigned long long n;
    std::cin >> n;
    
    auto cakeVolume{ w * h * d };

    if (cakeVolume % n != 0) {
        std::cout << -1 << "\n";
        return 0;
    }

    auto sliceVolume{ cakeVolume / n };
    
    // 10 * 20 * 6
    // wPrimeFactor{ 2 5 }
    // hPrimeFactors{ 2 5 }
    // dPrimeFactors{ 2 3 }
    // 5  2  2
 
    auto wCopy{ w };
    std::vector<unsigned long long> wFactorization;
    for (unsigned long long v{ 2 }; v * v <= wCopy; ++v) {
        while (wCopy % v == 0) {
            wCopy /= v;
            wFactorization.push_back(v);
        }
    }

    auto hCopy{ h };
    std::vector<unsigned long long> hFactorization;
    for (unsigned long long v{ 2 }; v * v <= hCopy; ++v) {
        while (hCopy % v == 0) {
            hCopy /= v;
            hFactorization.push_back(v);
        }
    }

    auto dCopy{ d };
    std::vector<unsigned long long> dFactorization;
    for (unsigned long long v{ 2 }; v * v <= dCopy; ++v) {
        while (dCopy % v == 0) {
            dCopy /= v;
            dFactorization.push_back(v);
        }
    }

    auto sliceVolumeCopy{ sliceVolume };
    std::vector<unsigned long long> sliceFactorization;
    for (unsigned long long v{ 2 }; v * v <= sliceVolumeCopy; ++v) {
        while (sliceVolumeCopy % v == 0) {
            sliceVolumeCopy /= v;
            sliceFactorization.push_back(v);
        }
    }

    // 

}
