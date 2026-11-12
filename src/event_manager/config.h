#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

// Понятные имена для кнопок в коде
enum ButtonId : uint8_t {
    BUTTON_UNKNOWN,
    BUTTON_UP,
    BUTTON_DOWN,
    BUTTON_ENTER,
    BUTTON_LEFT,
    BUTTON_RIGHT,
    BUTTON_BACK,
    BUTTON_BOOT
};

// Структура для связи ID кнопки с физическим пином ESP32
struct ButtonConfig {
    ButtonId id;
    uint8_t pin;
    const char* name; // Строковое имя для удобного вывода в Serial
};

// Массив конфигурации всех кнопок устройства
const ButtonConfig CONFIG_BUTTONS[] = {
    {BUTTON_UP,     17, "Вверх"},
    {BUTTON_DOWN,   21, "Вниз"},
    {BUTTON_ENTER,  16, "Выбор"},
    {BUTTON_LEFT,   18, "Назад"},
    {BUTTON_RIGHT,  44, "Вправо"},
    {BUTTON_BACK,   14, "Назад"},
};

// Вычисляем количество кнопок автоматически
const uint8_t BUTTONS_COUNT = sizeof(CONFIG_BUTTONS) / sizeof(CONFIG_BUTTONS[0]);

#endif // CONFIG_H