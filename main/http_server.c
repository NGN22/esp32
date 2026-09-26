#include "http_server.h"

#include "esp_http_server.h"
#include "esp_log.h"

static const char *TAG = "HTTP_SERVER";

static esp_err_t root_get_handler(httpd_req_t *req)
{
    const char *html =
       "<!DOCTYPE html>"
        "<html>"
        "<head>"
        "<title>ESP32 LAB</title>"
        "</head>"
        "<body>"
        "<h1>ESP32 LAB</h1>"
        "<p>Servidor HTTP ESP32 funcionando</p>"
        "<p>mira Ethan esto es lo qeu tenes que hacer para hacer un servidor</p>"
        "</body>"
        "</html>";

    httpd_resp_send(req, html, HTTPD_RESP_USE_STRLEN);

    return ESP_OK;
}

static const httpd_uri_t root = {
    .uri = "/",
    .method = HTTP_GET,
    .handler = root_get_handler,
    .user_ctx = NULL
};

void start_webserver(void)
{
    httpd_handle_t server = NULL;

    httpd_config_t config =
        HTTPD_DEFAULT_CONFIG();

    ESP_LOGI(TAG, "Iniciando servidor HTTP");

    if (httpd_start(&server, &config) == ESP_OK)
    {
        httpd_register_uri_handler(
            server,
            &root);

        ESP_LOGI(
            TAG,
            "Servidor HTTP iniciado");
    }
}