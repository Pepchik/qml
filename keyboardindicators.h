#ifndef KEYBOARDINDICATORS_H
#define KEYBOARDINDICATORS_H

#endif // KEYBOARDINDICATORS_H
KeyboardIndicator::KeyboardIndicator(QObject *parent)
    : QObject(parent)
{
}

void KeyboardIndicator::turnOnAllIndicators()
{
    qDebug() << "Turning on all indicators";
    // здесь можно включить индикаторы клавиатуры
}
