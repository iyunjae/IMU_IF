/*
 * adis16488a.c
 *
 *  Created on: 2026. 5. 6.
 *      Author: Admin
 */

#include "main.h"
#include "adis16488a.h"

extern SPI_HandleTypeDef hspi1;

uint16_t buf_spi1_rx[7];

uint16_t buf_spi1_tx[7] = {
		addr_gyro_x << 8, addr_gyro_y << 8, addr_gyro_z << 8,
		addr_accl_x << 8, addr_accl_y << 8, addr_accl_z << 8,
		0x0000
};

void adis16488a_burst_read(void) {
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	HAL_SPI_TransmitReceive_DMA(&hspi1, (uint8_t*)buf_spi1_tx, (uint8_t*)buf_spi1_rx, 7);
}

void adis16488a_convert(adis16488a_raw_t *raw, adis16488a_converted_t *converted_data) {
	converted_data->gyro_x = raw->X_GYRO_OUT * 0.02f;
	converted_data->gyro_y = raw->Y_GYRO_OUT * 0.02f;
	converted_data->gyro_z = raw->Z_GYRO_OUT * 0.02f;

	converted_data->accl_x = raw->X_ACCL_OUT * 0.0008f * 9.81f;
	converted_data->accl_y = raw->Y_ACCL_OUT * 0.0008f * 9.81f;
	converted_data->accl_z = raw->Z_ACCL_OUT * 0.0008f * 9.81f;
}
