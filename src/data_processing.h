#ifndef DATA_PROCESSING_H
#define DATA_PROCESSING_H

class DataProcessor {
private:
    float lastValue;
    float threshold;
public:
    DataProcessor();
    float applyFilter(float inputValue);
    bool isAboveThreshold(float value) const;
};

#endif /* DATA_PROCESSING_H */
