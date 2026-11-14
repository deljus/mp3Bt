#include <functional>
#include "abstract_screen.h"

class MainScreen : public AbstractScreen
{
public:
    using CallbackType = std::function<void()>;

    MainScreen(/* args */);
    ~MainScreen();

    void initDisplay() override;
    void destroyDisplay() override;

    void upKeyPress() override;
    void downKeyPress() override;
    void rightKeyPress() override;
    void leftKeyPress() override;
    void enterKeyPress() override;
    void backKeyPress() override;

    void addGotoPlayerListener(void (*cb)());
    void addGotoWifiListener(void (*cb)());
private:
    CallbackType gotoPlayerCallback;
    CallbackType gotoWifiCallback;
};