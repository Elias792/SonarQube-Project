#ifndef DATA_PROCESSING_EXTRA_H
#define DATA_PROCESSING_EXTRA_H

class AdvancedProcessor {
private:
    float factor;
    float baseline;

public:
    AdvancedProcessor();
    float complexCalculation(float input);
    void setBaseline(float base);
};

#endif /* DATA_PROCESSING_EXTRA_H */
