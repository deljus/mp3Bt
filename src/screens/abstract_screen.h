
#pragma once

class AbstractScreen
{
public:
    AbstractScreen() = default;
    virtual ~AbstractScreen() = default; 

    virtual void initDisplay() = 0;
    virtual void destroyDisplay() = 0;

    virtual void upKeyPress() = 0;     
    virtual void downKeyPress() = 0;
    virtual void rightKeyPress() = 0;
    virtual void leftKeyPress() = 0;
    virtual void enterKeyPress() = 0;
    virtual void backKeyPress() = 0;
};