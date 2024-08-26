
#include <driver/i2c.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "mpu.h"


void initI2C(int sdapin, int sclpin){
	i2c_config_t conf = {
	.mode = I2C_MODE_MASTER,
	.sda_io_num = sdapin,
	.scl_io_num = sclpin,
	.sda_pullup_en = GPIO_PULLUP_ENABLE,
	.scl_pullup_en = GPIO_PULLUP_ENABLE,
	.master.clk_speed = 100000,
    .clk_flags = 0,
    };

	ESP_ERROR_CHECK(i2c_param_config(I2C_NUM_0, &conf));
	ESP_ERROR_CHECK(i2c_driver_install(I2C_NUM_0, I2C_MODE_MASTER, 0, 0, 0));
    
}

void writeI2C(uint8_t address, uint8_t reg, uint8_t data){
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
	ESP_ERROR_CHECK(i2c_master_start(cmd));
	ESP_ERROR_CHECK(i2c_master_write_byte(cmd, (address << 1) | I2C_MASTER_WRITE, data));
	ESP_ERROR_CHECK(i2c_master_write_byte(cmd, reg, data));
	ESP_ERROR_CHECK(i2c_master_stop(cmd));
	ESP_ERROR_CHECK(i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000/portTICK_PERIOD_MS));
	i2c_cmd_link_delete(cmd);
}


void readI2C(uint8_t address, uint8_t reg, uint8_t *buffer, int len){
    len -= 1;
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
	ESP_ERROR_CHECK(i2c_master_start(cmd));
	ESP_ERROR_CHECK(i2c_master_write_byte(cmd, (address << 1) | I2C_MASTER_READ, 1));

    for(int i = 0; i <= len-1; i++){
        ESP_ERROR_CHECK(i2c_master_read_byte(cmd, buffer+i,   0));
    }
	ESP_ERROR_CHECK(i2c_master_read_byte(cmd, buffer+(len), 1));
		
	ESP_ERROR_CHECK(i2c_master_stop(cmd));
	ESP_ERROR_CHECK(i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000/portTICK_PERIOD_MS));
	i2c_cmd_link_delete(cmd);
}