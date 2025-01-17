CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -I./libs/driver_accel -I./libs/driver_force \
         -I./libs/driver_temp -I./libs/common_utils -I./src -I./utils
CXXFLAGS = -Wall -Wextra -I./src
LDFLAGS =
BIN_DIR = bin

SRC_C = \
  src/main.c \
  src/sensor_manager.c \
  src/communication.c \
  src/memory_manager.c \
  libs/driver_accel/adxl345.c \
  libs/driver_accel/adxl345_utils.c \
  libs/driver_force/fsr402.c \
  libs/driver_force/fsr402_utils.c \
  libs/driver_temp/ds18b20.c \
  libs/common_utils/parse_config.c \
  libs/common_utils/string_helper.c \
  libs/common_utils/insecure_utils.c \
  utils/calibration_common.c \
  utils/calibration_copy.c

SRC_CPP = \
  src/data_processing.cpp \
  src/data_processing_extra.cpp \
  src/raspberry_manager.cpp

OBJ_C = $(SRC_C:.c=.o)
OBJ_CPP = $(SRC_CPP:.cpp=.o)

all: directories main tests

directories:
	mkdir -p $(BIN_DIR)

main: $(OBJ_C) $(OBJ_CPP)
	$(CC) $(CFLAGS) -o $(BIN_DIR)/main $(OBJ_C) $(OBJ_CPP) $(LDFLAGS)

tests: 
	$(CC) $(CFLAGS) -o $(BIN_DIR)/test_accel tests/test_accel.c \
	    libs/driver_accel/adxl345.c libs/driver_accel/adxl345_utils.c
	$(CC) $(CFLAGS) -o $(BIN_DIR)/test_force tests/test_force_sensor.c \
	    libs/driver_force/fsr402.c libs/driver_force/fsr402_utils.c
	$(CC) $(CFLAGS) -o $(BIN_DIR)/test_comm tests/test_communication.c \
	    src/communication.c src/sensor_manager.c \
	    libs/driver_accel/adxl345.c libs/driver_accel/adxl345_utils.c \
	    libs/driver_force/fsr402.c libs/driver_force/fsr402_utils.c \
	    libs/driver_temp/ds18b20.c
	$(CXX) $(CXXFLAGS) -o $(BIN_DIR)/test_data_processing tests/test_data_processing.cpp \
	    src/data_processing.cpp src/data_processing_extra.cpp
	$(CC) $(CFLAGS) -o $(BIN_DIR)/test_temp tests/test_temp_sensor.c \
	    libs/driver_temp/ds18b20.c
	$(CC) $(CFLAGS) -o $(BIN_DIR)/test_mem tests/test_memory_manager.c \
	    src/memory_manager.c
	$(CC) $(CFLAGS) -o $(BIN_DIR)/test_dup tests/test_duplicate_utils.c \
         utils/duplicate_utils.c
	$(CC) $(CFLAGS) -o $(BIN_DIR)/test_insecure tests/test_insecure_utils.c \
	     libs/common_utils/insecure_utils.c

clean:
	rm -f src/*.o libs/driver_*/**.o libs/common_utils/*.o utils/*.o
	rm -f $(BIN_DIR)/*

.PHONY: clean tests
