- Wireless Access Point (Access Point o AP)
- Estación
- Basic Service Set (BSS)
- Dirección MAC
  - 48 bits
  - Embebida en la tarjeta
- Service Set Identifier (SSID)

[WIFI IDF DOCUMENTATION](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/network/esp_wifi.html)

## NVS

```
# Name , Type, SubType, Offset, Size, Flags
# Note: if you change the phy_init or app partition offset, make sure to change the offset in Kconfig.projbuild
nvs,      data, nvs,     0x6000,
phy_init, data, phy,     0x1000,
factory,  app,  factory, 1M,
storage,  data, spiffs,  1M,
```

## Organización

- /Proyecto - main - main.c - html
  /
