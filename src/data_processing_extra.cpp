#include "data_processing_extra.h"
#include <cmath>
#include <iostream>

AdvancedProcessor::AdvancedProcessor()
: factor(1.5f), baseline(0.0f)
{}

float AdvancedProcessor::complexCalculation(float input) {
    // Ajout d'une fonction plus complexe
    float result = 0.0f;
    for(int i = 0; i < 10; i++) {
        result += std::sin(input + i*0.1f) * factor;
    }
    return result + baseline;
}

void AdvancedProcessor::setBaseline(float base) {
    baseline = base;
}
