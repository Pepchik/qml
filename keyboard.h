#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QObject>
#include <string>
#include <X11/Xlib.h>
#include <X11/XKBlib.h>
#include <chrono>
#include <thread>

class ProcRec:public QObject {
    Q_OBJECT
public:
    //Q_PROPERTY(int fileID)
    explicit ProcRec(QObject* parent = 0) : QObject(parent) {}

    Q_INVOKABLE void calldmesg(){
        system("dmesg > test.txt");
    }
    Q_INVOKABLE void ledononff(QString in){
        using namespace std::this_thread;
        using namespace std::chrono;
        if (in[0]=='1'){
            system("xset led named \"Caps Lock\"");
            system("xset led named \"Num Lock\"");
            system("xset led named \"Scroll Lock\"");
            sleep_for(seconds(1));
            system("xset -led named \"Caps Lock\"");
            system("xset -led named \"Num Lock\"");
            system("xset -led named \"Scroll Lock\"");
        }

    };
    Q_INVOKABLE void controlleds(QString in){
        for (int i=0; i<in.length(); i++)
        {
            if(in[i] == "C"||in[i] == "c") {
                system("xset led named \"Caps Lock\"");
            }
            if(in[i] == "N"||in[i] == "n") {
                system("xset led named \"Num Lock\"");
            }
            if(in[i] == "S"||in[i] == "s") {
                system("xset led named \"Scroll Lock\"");
            }
        }
    }
    Q_INVOKABLE void invert(){
        system("xdotool key Caps_Lock");
        system("xdotool key Insert");
        system("xdotool key Num_Lock");
    }
    Q_INVOKABLE void ledselect(int ID, QString command){
        switch (ID)
        {
            case 0: ledononff(command); break;
            case 1: controlleds(command); break;
            case 2: invert(); break;
        }
    }
};

#endif // KEYBOARD_H
