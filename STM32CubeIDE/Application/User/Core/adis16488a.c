/*
 * adis16488a.c
 *
 *  Created on: 2026. 5. 6.
 *      Author: Admin
 */
#include "adis16488a.h"

void adis16488a_convert(adis16488a_raw_t *raw, adis16488a_converted_t *converted_data) {
	converted_data->gyro_x = raw->X_GYRO_OUT * 0.02f;
	converted_data->gyro_y = raw->Y_GYRO_OUT * 0.02f;
	converted_data->gyro_z = raw->Z_GYRO_OUT * 0.02f;

	converted_data->accl_x = raw->X_ACCL_OUT * 0.0008f * 9.81f;
	converted_data->accl_y = raw->Y_ACCL_OUT * 0.0008f * 9.81f;
	converted_data->accl_z = raw->Z_ACCL_OUT * 0.0008f * 9.81f;
}
