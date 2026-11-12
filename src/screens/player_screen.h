#include "abstract_screen.h"
#include <functional>

class PlayerScreen : public AbstractScreen
{
public:
    using CallbackType = std::function<void()>;

    PlayerScreen(/* args */);
    ~PlayerScreen();

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
};