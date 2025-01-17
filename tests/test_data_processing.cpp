#include <iostream>
#include "../src/data_processing.h"
#include "../src/data_processing_extra.h"

int main() {
    DataProcessor dp;
    float inputValue = 10.0f;
    float filtered = dp.applyFilter(inputValue);

    std::cout << "[TEST] Filtered value: " << filtered << std::endl;
    if(dp.isAboveThreshold(filtered)) {
        std::cout << "[TEST] Threshold exceeded!" << std::endl;
    }

    AdvancedProcessor ap;
    float cVal = ap.complexCalculation(5.0f);
    std::cout << "[TEST] Complex val => " << cVal << std::endl;
    return 0;
}
