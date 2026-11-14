#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();
AsyncWebServer server(80); // Создаем асинхронный сервер на 80 порту

const char* apSSID = "LILYGO_S3_ASYNC";
const char* apPassword = "password123";

// HTML-страница (хранится во флеш-памяти PROGMEM, чтобы экономить RAM)
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>LILYGO S3 Async</title>
  <style>
    body { font-family: Arial, sans-serif; text-align: center; margin-top: 40px; }
    button { padding: 15px 30px; font-size: 18px; cursor: pointer; background: #007BFF; color: white; border: none; border-radius: 8px; }
    button:active { background: #0056b3; }
  </style>
</head>
<body>
  <h2>LILYGO T-Display S3</h2>
  <p>Асинхронный веб-сервер работает!</p>
  <button onclick="sendPing()">Отправить сигнал на экран</button>
  <p id="status"></p>

  <script>
    function sendPing() {
      fetch('/ping')
        .then(response => response.text())
        .then(data => {
          document.getElementById('status').innerText = "Ответ платы: " + data;
        });
    }
  </script>
</body>
</html>
)rawliteral";

void setup() {
  Serial.begin(115200);

  // 1. Инициализация экрана
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(2);
  tft.drawString("Starting Async AP...", 10, 10);

  // 2. Поднятие точки доступа
  WiFi.softAP(apSSID, apPassword);
  IPAddress IP = WiFi.softAPIP();

  tft.fillScreen(TFT_BLACK);
  tft.drawString("AP Active!", 10, 10);
  tft.setTextSize(1);
  tft.drawString("Wi-Fi: " + String(apSSID), 10, 40);
  tft.drawString("IP: " + IP.toString(), 10, 60);

  // 3. Настройка маршрутов (обработчиков запросов)
  
  // Главная страница
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", index_html);
  });

  // Фоновый API-запрос при нажатии кнопки на сайте
  server.on("/ping", HTTP_GET, [](AsyncWebServerRequest *request){
    // Внимание: в обработчиках AsyncWebServer нельзя напрямую рисовать на TFT (может вызвать краш).
    // Вместо этого отправляем ответ браузеру, а отрисовку лучше делать через флаг в loop().
    Serial.println("Получен запрос /ping с сайта!");
    request->send(200, "text/plain", "OK (Время работы: " + String(millis() / 1000) + " сек)");
  });

  // Обработка ошибки 404
  server.onNotFound([](AsyncWebServerRequest *request){
    request->send(404, "text/plain", "Страница не найдена");
  });

  // 4. Запуск сервера
  server.begin();
}

void loop() {
  // Здесь ничего вызывать не нужно! Сервер работает в фоне.
}
