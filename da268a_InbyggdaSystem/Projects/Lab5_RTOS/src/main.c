#include <stdio.h>
#include <driver/i2c.h>
#include <esp_pm.h>
#include "mpu.h"

#define SDA_PIN 33
#define SCL_PIN 32
#define MPU6050_ADDR 0x68
#define MPU6050_ACCEL_XOUT_H 0x3B
#define MPU6050_PWR_MGMT_1 0x6B
#define READ_NBR_OF_REG 6

void app_main() {
	// initialise the I2C bus and the MPU6050
	//initI2C(SDA_PIN, SCL_PIN);

	esp_pm_config_esp32_t conf = {
        .max_freq_mhz = 240, //Should work with these Hz
        .min_freq_mhz = 80,
        .light_sleep_enable = 1,
        
    };
    ESP_ERROR_CHECK(esp_pm_configure(&conf));

	/*
	i2c_cmd_handle_t cmd = i2c_cmd_link_create();
	ESP_ERROR_CHECK(i2c_master_start(cmd));
	ESP_ERROR_CHECK(i2c_master_write_byte(cmd, (MPU6050_ADDR << 1) | I2C_MASTER_WRITE, 1));
	ESP_ERROR_CHECK(i2c_master_write_byte(cmd, MPU6050_PWR_MGMT_1, 1));
	ESP_ERROR_CHECK(i2c_master_write_byte(cmd, 0, 1));
	ESP_ERROR_CHECK(i2c_master_stop(cmd));
	ESP_ERROR_CHECK(i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000/portTICK_PERIOD_MS));
	i2c_cmd_link_delete(cmd);
	*/


	 ets_delay_us(2000000);

	/*
	uint8_t buffer[14];
	short accel_x;
	short accel_y;
	short accel_z;
	
	while(1){

		// get acceleration
		writeI2C(MPU6050_ADDR, MPU6050_ACCEL_XOUT_H, 1);
		readI2C(MPU6050_ADDR, 0, buffer, READ_NBR_OF_REG);

		// print acceleration
		accel_x = (buffer[0] << 8) | buffer[1];
		accel_y = (buffer[2] << 8) | buffer[3];
		accel_z = (buffer[4] << 8) | buffer[5];
		printf("accel_x: %d, accel_y: %d, accel_z: %d\n", accel_x, accel_y, accel_z);

		vTaskDelay(pdMS_TO_TICKS(500));
	}
	*/
}