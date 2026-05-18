/*
 * adis16488a.h
 *
 *  Created on: 2026. 5. 6.
 *      Author: Admin
 */

#ifndef APPLICATION_USER_CORE_ADIS16488A_H_
#define APPLICATION_USER_CORE_ADIS16488A_H_

#include <stdint.h>

#define addr_gyro_x 0x12
#define addr_gyro_y 0x16
#define addr_gyro_z 0x1A
#define addr_accl_x 0x1E
#define addr_accl_y 0x22
#define addr_accl_z 0x26

#define GYRO_SCALE  0.02f
#define ACCL_SCALE (0.0008f * 9.81f)

extern uint16_t buf_spi1_rx[7];

typedef struct {
	int16_t X_GYRO_OUT;
	int16_t Y_GYRO_OUT;
	int16_t Z_GYRO_OUT;
	int16_t X_ACCL_OUT;
	int16_t Y_ACCL_OUT;
	int16_t Z_ACCL_OUT;
} adis16488a_raw_t;

typedef struct {
	float gyro_x;
	float gyro_y;
	float gyro_z;
	float accl_x;
	float accl_y;
	float accl_z;
} adis16488a_converted_t;

void adis16488a_burst_read(void);

#endif /* APPLICATION_USER_CORE_ADIS16488A_H_ */
