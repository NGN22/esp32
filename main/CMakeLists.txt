idf_component_register(
    SRCS
        "main.c"
        "led_manager.c"
        "http_server.c"

    INCLUDE_DIRS "."

    REQUIRES
        esp_driver_gpio
        esp_wifi
        esp_netif
        esp_event
        nvs_flash
        esp_http_server
)