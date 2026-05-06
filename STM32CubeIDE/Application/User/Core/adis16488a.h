/*
 * adis16488a.h
 *
 *  Created on: 2026. 5. 6.
 *      Author: Admin
 */

#ifndef APPLICATION_USER_CORE_ADIS16488A_H_
#define APPLICATION_USER_CORE_ADIS16488A_H_

#include <stdint.h>

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

#endif /* APPLICATION_USER_CORE_ADIS16488A_H_ */
