#include "indicatorswitcher.h"
#include <iostream>

#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>
#include <X11/XKBlib.h>

#include <chrono>
#include <thread>

IndicatorSwitcher::IndicatorSwitcher()
{

}

void IndicatorSwitcher::setCapsLock(){
    Display* display = XOpenDisplay(NULL);

    // Get the keycode for XK_Caps_Lock keysymbol
    unsigned int keycode = XKeysymToKeycode(display, XK_Caps_Lock);
    std::cout<< "Macro: " << XK_Caps_Lock << std::endl;
    std::cout << "Keycode to Keysym: " << XkbKeycodeToKeysym(display, keycode, 0, 0) << std::endl;
    //keycode = 58;
    std::cout << "Caps Keycode: "<<  keycode << std::endl;


    // Simulate Press
    XTestFakeKeyEvent(display, keycode, True, CurrentTime);
    XFlush(display);

    // Simulate Release
    XTestFakeKeyEvent(display, keycode, False, CurrentTime);
    XFlush(display);
}

void IndicatorSwitcher::setScrollLock(){
    Display* display = XOpenDisplay(NULL);
    unsigned int keycode = XKeysymToKeycode(display, XK_Scroll_Lock);
    //keycode = 70;
    std::cout << "Scroll Keycode: "<<  keycode << std::endl;
    // Simulate Press
    XTestFakeKeyEvent(display, keycode, True, CurrentTime);
    XFlush(display);

    // Simulate Release
    XTestFakeKeyEvent(display, keycode, False, CurrentTime);
    XFlush(display);
}

void IndicatorSwitcher::setNumLock(){
    Display* display = XOpenDisplay(NULL);
    unsigned int keycode = XKeysymToKeycode(display, XK_Num_Lock);
    //keycode = 69;
    std::cout << "Num Keycode: "<<  keycode << std::endl;

    // Simulate Press
    XTestFakeKeyEvent(display, keycode, True, CurrentTime);
    XFlush(display);

    // Simulate Release
    XTestFakeKeyEvent(display, keycode, False, CurrentTime);
    XFlush(display);

}

void IndicatorSwitcher::pressAllIndicators(){
    IndicatorSwitcher::setCapsLock();
    IndicatorSwitcher::setScrollLock();
    IndicatorSwitcher::setNumLock();
}

bool IndicatorSwitcher::getCapsLockStatus(){
    Display* d = XOpenDisplay(NULL);
    bool caps_state = false;
    unsigned n;
    //std::this_thread::sleep_for(std::chrono::milliseconds(250));
    if (d)
    {
        XkbGetIndicatorState(d, XkbUseCoreKbd, &n);
        caps_state = (n & 0x01) == 1;
    }
    std::cout << caps_state << std::endl;
    return caps_state;
}

bool IndicatorSwitcher::getScrollLockStatus(){
    Display* d = XOpenDisplay(NULL);
    bool scroll_state = false;
    unsigned n;
    //std::this_thread::sleep_for(std::chrono::milliseconds(250));
    if (d)
    {
        XkbGetIndicatorState(d, XkbUseCoreKbd, &n);
        scroll_state = (n & 3) == 3;
    }
    std::cout << scroll_state << std::endl;
    return scroll_state;
}

bool IndicatorSwitcher::getNumLockStatus(){
    Display* d = XOpenDisplay(NULL);
    bool num_state = false;
    unsigned n;
    //std::this_thread::sleep_for(std::chrono::milliseconds(250));
    if (d)
    {
        XkbGetIndicatorState(d, XkbUseCoreKbd, &n);
        num_state = (n & 2) == 2;
    }
    std::cout << num_state << std::endl;
    return num_state;
}

void IndicatorSwitcher::lightAllIndicators(){
    bool isCaps, isScroll, isNum;
    isCaps = getCapsLockStatus();
    isScroll = getScrollLockStatus();
    isNum = getNumLockStatus();

    if(!isCaps){
        setCapsLock();
    }
    if(!isScroll){
        setScrollLock();
    }
    if(!isNum){
        setNumLock();
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    pressAllIndicators();
}
