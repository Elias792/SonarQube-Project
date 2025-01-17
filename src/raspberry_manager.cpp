#include <iostream>
#include <cmath>
#include "data_processing.h"
#include "data_processing_extra.h"

int handleIncomingAccelData(int x, int y, int z) {
    static DataProcessor dp;
    float magnitude = std::sqrt((float)(x*x + y*y + z*z));
    float filteredVal = dp.applyFilter(magnitude);
    if(dp.isAboveThreshold(filteredVal)) {
        std::cout << "[RPi] Movement above threshold: " << filteredVal << std::endl;
        return 1;
    }
    return 0;
}

int handleComplexData(float input) {
    static AdvancedProcessor ap;
    float val = ap.complexCalculation(input);
    ap.setBaseline(10.0f);
    if(val > 20.0f) {
        std::cout << "[RPi] Complex data exceed limit: " << val << std::endl;
        return 1;
    }
    return 0;
}
