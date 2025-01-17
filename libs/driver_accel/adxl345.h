#ifndef ADXL345_H
#define ADXL345_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int accel_x;
    int accel_y;
    int accel_z;
} adxl345_data_t;

int adxl345_init(void);
int adxl345_read_accel(adxl345_data_t* data);
int adxl345_configure_range(int range);

// Nouveau prototype
int adxl345_self_test(void);

#ifdef __cplusplus
}
#endif

#endif /* ADXL345_H */
