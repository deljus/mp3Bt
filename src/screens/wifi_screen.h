#include "abstract_screen.h"
#include "ui.h"
#include <functional>

class WiFiScreen : public AbstractScreen
{
public:
    using CallbackType = std::function<void()>;

    WiFiScreen(/* args */);
    ~WiFiScreen();

    void initDisplay() override;
    void destroyDisplay() override;

    void upKeyPress() override;
    void downKeyPress() override;
    void rightKeyPress() override;
    void leftKeyPress() override;
    void enterKeyPress() override;
    void backKeyPress() override;

    void addGotoMainListener(void (*cb)());
private:
    CallbackType gotoMainCallback;
    void toggleWiFi();
};