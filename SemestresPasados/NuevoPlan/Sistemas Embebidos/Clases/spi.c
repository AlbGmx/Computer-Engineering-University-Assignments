// Code to initialize SPI :)

esp_err_t spi_master_init(void) {
   spi_bus_config_t buscfg = {
       .miso_io_num = PIN_NUM_MISO,
       .mosi_io_num = PIN_NUM_MOSI,
       .sclk_io_num = PIN_NUM_CLK,
       .quadwp_io_num = -1,
       .quadhd_io_num = -1,
   };

   esp_err_t ret = spi_bus_initialize(SPI_MASTER_NUM, &config, SPI_DMA_CH_AUTO);

   spi_device_interface_config_t devconfig = {

       .mode = <MODO>, // Deinido por el device
       .spics_io_num = 1,
       .queue_size = 1,
       .clock_speed_hz = 1.6,
       .pre_cb = NULL,
       .address_bits = 8,

   };

   spi_bus_add_device(SPI_MASTER_NUM, &dev_config, &spi);
}

// Write from device
esp_err_t device_register_write(uint8_t reg_addr, uint8_t data) {
   spi_transaction_t t;
   memset(&t, 0, sizeof(t));
   t.addr = reg_addr & 0x7F;
   t.length = 8;
   t.tx_buffer = &data;

   esp_err_t ret = spi_device_transmit(spi, &t);
   return ret;
}

// Read from device
esp_err_t device_register_read(uint8_t reg_addr, uint8_t *data, size_t len) {
   spi_transaction_t t;
   memset(&t, 0, sizeof(t));
   t.addr = reg_addr & 0x80;
   t.length = 8;
   t.rx_buffer = &data;
   esp_err_t ret = spi_device_transmit(spi, &t);
   return ret;
}
