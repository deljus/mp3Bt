#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include "Config.h" 

struct Button {
    ButtonId id;   
    uint8_t pin;
    bool lastState;
    bool currentState;
    unsigned long lastDebounceTime;
    void (*callback)();
};

class EventManager {
public:
    void init();
    void tick();
    void addListener(ButtonId id, void (*callback)());


private:
    std::vector<Button> buttons;
    const unsigned long debounceDelay = 100;
};

#endif // EVENT_MANAGER_H


// Мика-мик, шлю вам лучи добра!
// Я вам тоже! Люблю вас
