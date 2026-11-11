#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include "Config.h" // Подключаем наш конфиг

struct Button {
    ButtonId id;    // Идентификатор кнопки вместо пина
    uint8_t pin;
    bool lastState;
    bool currentState;
    unsigned long lastDebounceTime;
};

class EventManager {
public:
    EventManager();


    void init();
    void tick();

private:
    std::vector<Button> buttons;
    void (*globalCallback)(ButtonId id);
    const unsigned long debounceDelay = 200;
};

#endif // EVENT_MANAGER_H