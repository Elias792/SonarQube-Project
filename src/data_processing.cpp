#include "data_processing.h"
#include <cmath>
#include <iostream>

DataProcessor::DataProcessor() : lastValue(0.0f), threshold(5.0f) {}

float DataProcessor::applyFilter(float inputValue) {
    // Exemple d’un mini-filtre pass bas
    float alpha = 0.8f;
    lastValue = alpha * lastValue + (1.0f - alpha) * inputValue;
    return lastValue;
}

bool DataProcessor::isAboveThreshold(float value) const {
    return (value >= threshold);
}
