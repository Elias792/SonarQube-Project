#ifndef DS18B20_H
#define DS18B20_H

#ifdef __cplusplus
extern "C" {
#endif

int ds18b20_init(void);
float ds18b20_read_temp(void);
int ds18b20_set_resolution(int bits);

#ifdef __cplusplus
}
#endif

#endif /* DS18B20_H */
