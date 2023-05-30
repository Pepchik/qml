#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QString>
#include <iostream>
#include <fstream>
#include <string>
#include <xcb/xcb.h>
#include <X11/XKBlib.h>
#include <linux/uinput.h>
#include <fcntl.h>
#include <unistd.h>
#include <keyboard.h>

//#include <QQuickItem>



//class ProjectorInfo {
//public:
//    QString lcdInfo = "LCD-проектор (ЖК-проектор) - это проектор, который использует технологию жидкокристаллического дисплея (ЖКД) для создания изображения.\n Принцип работы LCD-проектора основан на использовании трех ЖКД-матриц, каждая из которых отвечает за цветное изображение (красный, зеленый и синий).\nОсновными преимуществами LCD-проекторов являются высокая яркость и контрастность изображения, а также относительно низкая стоимость по сравнению с другими типами проекторов.\n Кроме того, LCD-проекторы обычно имеют длительный срок службы и могут работать в течение нескольких тысяч часов без необходимости замены лампы.\n Недостатками LCD-проекторов могут быть проблемы с 'эффектом размытия' или 'сеткой', что приводит к низкому качеству изображения, а также необходимость регулярной очистки фильтров для предотвращения перегрева и повреждения лампы. \nLCD-проекторы широко используются в сфере образования, бизнеса и развлечений для отображения изображений на больших экранах.";
//    QString dlpInfo = "<b>DLP проектор</b> - использует микрозеркальное устройство для отображения изображения. "
//                      "Обеспечивает высокую контрастность, глубокие черные тона и быструю смену кадров. Недостаток - эффект радужной "
//                      "россыпи может привести к неоднородности цвета.";
//    QString lcosInfo = "<b>LCoS проектор</b> - использует жидкокристаллическую панель, управляемую с помощью микрозеркального устройства. "                       "Объединяет преимущества LCD и DLP: широкие углы обзора, глубокие черные тона и высокую контрастность. Дорогостоящая технология.";
//};


//class KeyboardIndicator {
//public:
//    void turnOnAllIndicators() {
//        // Открываем uinput устройство
//        int fd = open("/dev/uinput", O_WRONLY | O_NONBLOCK);
//        if (fd < 0) {
//            // Обработка ошибки
//            return;
//        }

//        // Создаем виртуальное устройство клавиатуры
//        struct uinput_user_dev uidev;
//        memset(&uidev, 0, sizeof(uidev));
//        snprintf(uidev.name, UINPUT_MAX_NAME_SIZE, "Virtual Keyboard");
//        uidev.id.bustype = BUS_USB;
//        uidev.id.vendor = 0x1;
//        uidev.id.product = 0x1;
//        write(fd, &uidev, sizeof(uidev));

//        ioctl(fd, UI_SET_EVBIT, EV_LED);
//        ioctl(fd, UI_SET_LEDBIT, LED_CAPSL);
//        ioctl(fd, UI_SET_LEDBIT, LED_NUML);
//        ioctl(fd, UI_SET_LEDBIT, LED_SCROLLL);
//        ioctl(fd, UI_DEV_CREATE);

//        // Эмулируем нажатие клавиши 1 и отпускание клавиши
//        struct input_event ev;
//        memset(&ev, 0, sizeof(ev));
//        ev.type = EV_KEY;
//        ev.code = KEY_1;
//        ev.value = 1;
//        write(fd, &ev, sizeof(ev));
//        ev.value = 0;
//        write(fd, &ev, sizeof(ev));

//        // Удаляем виртуальное устройство
//        ioctl(fd, UI_DEV_DESTROY);
//        close(fd);
//    }
//};

class ProcDevices {
public:
    QString getFileContent(const QString& filePath) {
        std::ifstream infile(filePath.toStdString());
        std::string devices((std::istreambuf_iterator<char>(infile)), (std::istreambuf_iterator<char>()));
        return QString::fromStdString(devices);
    }
};

class CpuInfo {
public:
    QString getFileContent(const QString& filePath) {
        std::ifstream infile(filePath.toStdString());
        std::string cpuI((std::istreambuf_iterator<char>(infile)), (std::istreambuf_iterator<char>()));
        return QString::fromStdString(cpuI);
    }
};

class MemInfo {
public:
    QString getFileContent(const QString& filePath) {
        std::ifstream infile(filePath.toStdString());
        std::string memI((std::istreambuf_iterator<char>(infile)), (std::istreambuf_iterator<char>()));
        return QString::fromStdString(memI);
    }
};

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);


    // Создайте объект класса FileContent
    ProcDevices procDevices;
    CpuInfo cpuInfo;
    MemInfo memInfo;
//    ProjectorInfo projectorInfo;
    qmlRegisterType<ProcRec>("com.myself", 1, 0, "ProcRec");

    // Получите содержимое файла
    QString devices = procDevices.getFileContent("/proc/devices");
    QString cpuI = cpuInfo.getFileContent("/proc/cpuinfo");
    QString memI = memInfo.getFileContent("/proc/meminfo");

    // Создайте qml engine
    QQmlApplicationEngine engine;

    // Зарегистрируйте содержимое файла в контексте qml
    engine.rootContext()->setContextProperty("procDevices", devices);
    engine.rootContext()->setContextProperty("cpuInfo", cpuI);
    engine.rootContext()->setContextProperty("memInfo", memI);
//    engine.rootContext()->setContextProperty("lcdInfo", projectorInfo.lcdInfo);
//    engine.rootContext()->setContextProperty("dlpInfo", projectorInfo.dlpInfo);
//    engine.rootContext()->setContextProperty("lcosInfo", projectorInfo.lcosInfo);


    // Подключаемсобытие нажатия на клавишу 1
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &app, [&keyboardIndicator](QObject *obj, const QUrl &objUrl) {
//        if (obj && objUrl == QUrl(QStringLiteral("qrc:/main.qml"))) {
//            QObject::connect(obj, &QObject::destroyed, &app, &QCoreApplication::quit, Qt::DirectConnection);
//            QObject::connect(obj, &QQuickItem::keyPressed, &keyboardIndicator, &KeyboardIndicator::turnOnAllIndicators);
//        }
//    }, Qt::QueuedConnection);

    // Загрузите qml файл
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
