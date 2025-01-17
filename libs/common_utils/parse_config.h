#ifndef PARSE_CONFIG_H
#define PARSE_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

int load_config_file(const char* filename);
const char* get_config_value(const char* key);

#ifdef __cplusplus
}
#endif

#endif /* PARSE_CONFIG_H */
