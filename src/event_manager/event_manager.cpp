#include "config.h"
#include "event_manager.h"

void EventManager::init() {
    for(int i = 0; i < BUTTONS_COUNT; i++) {
        pinMode(CONFIG_BUTTONS[i].pin, INPUT_PULLUP); 
        buttons.push_back({
            id: CONFIG_BUTTONS[i].id,
            pin: CONFIG_BUTTONS[i].pin,
            lastState: HIGH,
            currentState: HIGH,
            lastDebounceTime: 0
        });
    }
}

void EventManager::addListener(ButtonId id, void (*callback)()) {
    for (auto& btn : buttons) {
        if(btn.id == id) {
            btn.callback = callback;
        }
    }
}

void EventManager::tick() {
    unsigned long currentTime = millis();

    for (auto& btn : buttons) {
        bool reading = digitalRead(btn.pin);

        if (reading != btn.lastState) {
            btn.lastDebounceTime = currentTime;
        }

        if ((currentTime - btn.lastDebounceTime) > debounceDelay) {
            if (reading != btn.currentState) {
                btn.currentState = reading;

                if (btn.currentState == LOW) {
                    btn.callback();
                }
            }
        }

        btn.lastState = reading;
    }
}