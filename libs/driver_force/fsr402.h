#ifndef FSR402_H
#define FSR402_H

#ifdef __cplusplus
extern "C" {
#endif

int fsr402_init(void);
float fsr402_read_force(void);
int fsr402_configure(int sensitivity);

#ifdef __cplusplus
}
#endif

#endif /* FSR402_H */
