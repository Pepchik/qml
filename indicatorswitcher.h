#ifndef INDICATORSWITCHER_H
#define INDICATORSWITCHER_H

#include <QObject>

class IndicatorSwitcher : public QObject
{
    Q_OBJECT
public:
    IndicatorSwitcher();
    Q_INVOKABLE void setCapsLock();
    Q_INVOKABLE void setScrollLock();
    Q_INVOKABLE void setNumLock();
    Q_INVOKABLE void pressAllIndicators();

    Q_INVOKABLE bool getCapsLockStatus();
    Q_INVOKABLE bool getScrollLockStatus();
    Q_INVOKABLE bool getNumLockStatus();

    Q_INVOKABLE void lightAllIndicators();

};

#endif // INDICATORSWITCHER_H
