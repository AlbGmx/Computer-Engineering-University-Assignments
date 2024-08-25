#include "myFunctions.h"
static const char *TAG = "BME280";

#define BME280_NUMBER_OF_SENSORS 3

esp_err_t device_register_read(uint8_t reg_addr, uint8_t *data, size_t len) {
    int8_t rslt = 0;

    spi_transaction_t t;
    memset(&t, 0, sizeof(t));       
    t.length = 8+8*len;
    t.rxlength = 8*len;
    t.tx_buffer = &reg_addr;

    char * buf = malloc(len+1);
    memset(buf, 0, len+1);
    t.rx_buffer = buf;

    rslt = spi_device_polling_transmit(spi2, &t);
   
    memmove(reg_data, &buf[1], len);
    free(buf);
    
    if (rslt ==  ESP_OK) return 0;
    return rslt;
}

esp_err_t device_register_write_byte(uint8_t reg_addr, const uint8_t *data, uint32_t len, void *intf_ptr) {
    int8_t rslt = 0; 

    spi_transaction_t t;
    memset(&t, 0, sizeof(t));       
    t.length = 8*len+8;

    char * buf = malloc(len+1);
    buf[0] = reg_addr;
    memcpy(&buf[1], reg_data, len);
    t.tx_buffer = buf;
    rslt = spi_device_polling_transmit(spi2, &t);
    free(buf);   
    vTaskDelay(pdMS_TO_TICKS(10)); 
    
    if (rslt ==  ESP_OK)
        return 0;
    return rslt;
}

esp_err_t spi_master_init(void) {
   int i2c_master_port = I2C_MASTER_NUM;

   i2c_config_t conf = {
       .mode = I2C_MODE_MASTER,
       .sda_io_num = I2C_MASTER_SDA_IO,
       .scl_io_num = I2C_MASTER_SCL_IO,
       .sda_pullup_en = GPIO_PULLUP_ENABLE,
       .scl_pullup_en = GPIO_PULLUP_ENABLE,
       .master.clk_speed = I2C_MASTER_CLK,
       .clk_flags = 0,
   };

   esp_err_t err = spi_master_init(i2c_master_port, &conf);
   if (err != ESP_OK) {
      return err;
   }
   return i2c_driver_install(i2c_master_port, conf.mode, 0, 0, 0);
}

void bme280_delay_us(uint32_t period, void *intf_ptr) { vTaskDelay(period / portTICK_PERIOD_MS); }

void bme280_config_init(struct bme280_dev *dev, struct bme280_settings *settings) {
   int8_t rslt = BME280_OK;

   dev->chip_id = BME280_I2C_ADDR_SEC;
   dev->intf = BME280_SPI_INTF;
   dev->read = (bme280_read_fptr_t)device_register_read;
   dev->write = (bme280_write_fptr_t)device_register_write_byte;
   dev->delay_us = (bme280_delay_us_fptr_t)bme280_delay_us;
   rslt = bme280_init(dev);

   settings->osr_h = BME280_OVERSAMPLING_1X;
   settings->osr_p = BME280_OVERSAMPLING_16X;
   settings->osr_t = BME280_OVERSAMPLING_2X;
   settings->filter = BME280_FILTER_COEFF_16;
   settings->standby_time = BME280_STANDBY_TIME_0_5_MS;
   rslt = bme280_set_sensor_settings(BME280_SEL_ALL_SETTINGS, settings, dev);
}

uint8_t readRegisters(struct bme280_data *sensor_data, struct bme280_dev *dev) {
   uint8_t rslt = BME280_OK;
   uint8_t reg_data[BME280_LEN_P_T_H_DATA] = {0};
   rslt = bme280_get_sensor_data(BME280_ALL, sensor_data, dev);
   return rslt;
}

void printRegisters(struct bme280_data *sensor_data, uint8_t who_am_i, int8_t rslt) {
   if (rslt != BME280_OK) {
      ESP_LOGE(TAG, "\n\nError reading sensor data: %d", rslt);
   } else {
      ESP_LOGI(TAG, "WHO_AM_I: 0x%2x", who_am_i);
      ESP_LOGI(TAG, "Temperature: %.2f °C", sensor_data->temperature);
      ESP_LOGI(TAG, "Pressure: %.2f Pa", sensor_data->pressure);
      ESP_LOGI(TAG, "Humidity: %.2f %%\n", sensor_data->humidity);
   }
}