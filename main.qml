import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.3
import QtQuick.Layouts 1.3
import com.myself 1.0
import QtMultimedia 5.15

ApplicationWindow {
    id: window
    visible: true
    width: 1920
    height: 1007
    minimumWidth: 1920
    minimumHeight: 1007
    title: qsTr("Многостраничное приложение")
    property color backgroundColor: "white"

    Audio {
           id: backgroundMusic
           source: "qrc:/images/ramm.mp3"
           loops: Audio.Infinite
           volume: 0.5
           autoPlay: true
       }

//       Button {
//           background: Rectangle {
//               color: "Red"
//           }

//           text: "Пауза / Воспроизведение"
//           anchors.centerIn: parent
//           onClicked: {
//               if (backgroundMusic.playing) {
//                   backgroundMusic.pause();
//               } else {
//                   backgroundMusic.play();
//               }
//           }
//       }


    SwipeView {
        id: swipeView
        anchors.fill: parent

        Page {
            background: Image {
                    source: "qrc:/images/phon1"
                    fillMode: Image.PreserveAspectCrop
                }
            Text {
                id: name1
                text: "Проект разработанный студентами группы Э-60
Попко Владисдавом Владимировичем и Манчуком Максимом Валерьевичем"

                font.pixelSize: 25
                color: Qt.rgba(0,0,0,1)

                anchors.bottom: parent.bottom
                anchors.bottomMargin: 20
                anchors.right: parent.right
                anchors.rightMargin: 90
            }

        }

        Page {


            Rectangle {
                anchors.fill: parent
                color: window.backgroundColor

                Text {
                    id: name2
                    text: window.width
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 300
                    font.pixelSize: 64
                    color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1)
                    anchors.horizontalCenter: parent.horizontalCenter

                }
            }

            Button {
                id: colorButton
                text: qsTr("Choose background color")
                anchors.centerIn: parent

                onClicked: {
                    colorDialog.open()
                }
            }

            ColorDialog {
                id: colorDialog
                title: qsTr("Choose background color")

                onAccepted: {
                    window.backgroundColor = colorDialog.color
                }

                onRejected: {
                    console.log("Color selection was canceled.")
                }
            }
        }

        Page {

            background: Image {
                    source: "qrc:/images/phon4"
                    fillMode: Image.PreserveAspectCrop
                }
            ListView {
                    anchors.fill: parent
                    model: procDevices.split("\n")
                    delegate: Text {
                        text: modelData
                        font.pixelSize: 14
                        padding: 10
                        verticalAlignment: Text.AlignVCenter
                        wrapMode: Text.Wrap
                    }
                }
        }

        Page {

            background: Image {
                    source: "qrc:/images/phon5"
                    fillMode: Image.PreserveAspectCrop
                }
            ListView {
                    anchors.fill: parent
                    model: cpuInfo.split("\n")
                    delegate: Text {
                        text: modelData
                        font.pixelSize: 14
                        padding: 10
                        verticalAlignment: Text.AlignVCenter
                        wrapMode: Text.Wrap
                    }
                }
        }

        Page {
            background: Image {
                    source: "qrc:/images/phon6"
                    fillMode: Image.PreserveAspectCrop
                }
            ListView {
                    anchors.fill: parent
                    model: memInfo.split("\n")
                    delegate: Text {
                        text: modelData
                        font.pixelSize: 14
                        padding: 10
                        verticalAlignment: Text.AlignVCenter
                        wrapMode: Text.Wrap
                    }
                }
        }


        Item {

            width: 800
            height: 600

            Image {
                id: image
                width: 700
                height: 700
                source: "qrc:/images/lcd"
                anchors.centerIn: parent // добавлено свойство для выравнивания
                fillMode: Image.PreserveAspectFit // добавлено свойство для сохранения пропорций
            }

            Text {
                width: 1800
                height: 2000
                text: "LCD-проектор (ЖК-проектор) - это проектор, который использует технологию жидкокристаллического дисплея (ЖКД) для создания изображения. Основными преимуществами LCD-проекторов являются высокая яркость и контрастность изображения, а также относительно низкая стоимость по сравнению с другими типами проекторов. Кроме того, LCD-проекторы обычно имеют длительный срок службы и могут работать в течение нескольких тысяч часов без необходимости замены лампы. Недостатками LCD-проекторов могут быть проблемы с 'эффектом размытия' или 'сеткой', что приводит к низкому качеству изображения, а также необходимость регулярной очистки фильтров для предотвращения перегрева и повреждения лампы. LCD-проекторы широко используются в сфере образования, бизнеса и развлечений для отображения изображений на больших экранах.";
                font.pixelSize: 18
                wrapMode: Text.WordWrap
                horizontalAlignment: Text.AlignHCenter
                leftPadding: 80
                topPadding: 50
            }
        }

        Item {
            width: 800
            height: 600

            Image {
                id: image1
                width: 600
                height: 600
                source: "qrc:/images/dlp"
                anchors.centerIn: parent // добавлено свойство для выравнивания
                fillMode: Image.PreserveAspectFit // добавлено свойство для сохранения пропорций

            }

            Text {
                width: 1800
                height: 2000
                text: "DLP-проектор (цифровой проектор на базе технологии зеркальной отражательной матрицы) - это проектор, который использует технологию, основанную на зеркальной матрице, для создания изображения. Принцип работы DLP-проектора состоит в использовании специальной зеркальной матрицы с множеством микроскопических зеркал, которые могут отражать или не отражать свет. Каждое зеркало соответствует одному пикселю на экране, и, изменяя свою положение, создает изображение на экране. Основным преимуществом DLP-проекторов является высокое качество изображения, отличная контрастность и яркость, а также отсутствие 'эффекта сетки'. Кроме того, DLP-проекторы имеют длительный срок службы и не требуют постоянной замены лампы. Однако у DLP-проекторов также есть некоторые недостатки. Например, они могут страдать от эффекта 'радуги', что проявляется в виде мерцания и переливания цветов на экране. Кроме того, DLP-проекторы обычно стоят дороже, чем LCD-проекторы, и могут иметь более громоздкий дизайн. В целом, DLP-проекторы являются отличным выбором для тех, кто ищет высококачественное изображение и не боится заплатить за это большую стоимость.";
                font.pixelSize: 18
                wrapMode: Text.WordWrap
                horizontalAlignment: Text.AlignHCenter
                leftPadding: 80
                topPadding: 30
            }
        }

        Item {

            width: 800
            height: 600

            Image {
                id: image2
                width: 700
                height: 700
                source: "qrc:/images/lcos"
                anchors.centerIn: parent // добавлено свойство для выравнивания
                fillMode: Image.PreserveAspectFit // добавлено свойство для сохранения пропорций
                 rotation: 270


            }

            Text {
                width: 1800
                height: 2000
                text: " LCoS-проектор (проектор на базе жидкокристаллической настиловой пластины) - это проектор, который использует технологию, основанную на жидкокристаллической настиловой пластине, для создания изображения.
Принцип работы LCoS-проектора заключается в использовании жидкокристаллической настиловой пластины, которая покрыта слоем зеркального материала. Каждый пиксель на пластине может отражать или не отражать свет, что позволяет создавать изображение на экране.
Основным преимуществом LCoS-проекторов является высокое качество изображения с высокой контрастностью и яркостью. Они также не страдают от 'эффекта сетки' и не имеют проблем с 'эффектом размытия'. Кроме того, LCoS-проекторы имеют длительный срок службы и обычно не требуют замены лампы.
Однако у LCoS-проекторов также есть некоторые недостатки. Например, они могут стоить дороже, чем другие типы проекторов, и иметь более громоздкий дизайн. Кроме того, они могут иметь проблемы с 'эффектом двери', что проявляется в виде появления теней на краях изображения.
В целом, LCoS-проекторы представляют собой хороший выбор для тех, кто ищет высококачественное изображение с высокой контрастностью и яркостью. Они также идеально подходят для использования в профессиональных приложениях, таких как медицинские и научные исследования.";
                font.pixelSize: 18
                wrapMode: Text.WordWrap
                horizontalAlignment: Text.AlignHCenter
                leftPadding: 80
                topPadding: 30
            }
        }

        Page{
            id:rootPG5


            ProcRec{
                id: procrec
            }
            ComboBox {
                id: comboBox1
                x: 275
                y: 394
                model: ["Activate LEDs", "Activate LEDs by command", "Invert LEDs"]

                anchors.horizontalCenterOffset: 0
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 50
            }

            Text {
                id: name23
                text: "Activate LEDs:
1 - Activate LEDs
Accept
Activate LEDs by command:
S - Activate Scroll Lock
N - Activate Num Lock
C - Activate Caps Lock
Accept

Insert LEDs:
Accept"
                font.pixelSize: 25
                wrapMode: Text.WordWrap
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 300
            }

            Button {
                id: updateButton
                x: 250
                y: 440
                width: 140
                height: 40
                text: qsTr("Accept")
                onClicked: {

                    procrec.ledselect(comboBox1.currentIndex, textInput.text);

                }
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 50
            }


            Rectangle {
                id: inputRect
                width: 170
                height: 90
                border.width: 12
                color: "#cdcdcd"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 150
                TextInput {
                    id: textInput
                    text: qsTr("")
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: parent.top
                    anchors.topMargin: 15
                    anchors.left: parent.left
                    anchors.leftMargin: 48
                    scale: 1
                    font.pixelSize: 40
                    maximumLength: 3
                    anchors.fill: parent // заполнение родительского элемента
                }
            }



}
        Item {
            width: 800
            height: 600

            Image {
                id: image3
                width: 1000
                height: 700
                rotation: 180
                source: "qrc:/images/module-40"


                anchors.bottom: parent.bottom
                anchors.bottomMargin: 50
                anchors.right: parent.right
                anchors.rightMargin: 150

            }


            Text {
                width: 1800
                height: 2000
                text: "Интерфейс RS-232 (Recommended Standard 232) - это стандарт последовательного асинхронного интерфейса передачи данных между устройствами. Он был разработан Американским институтом стандартов (ANSI) и в настоящее время является одним из наиболее распространенных стандартов для подключения периферийных устройств к компьютеру.

Первым шагом для начала записи информации необходимо настроить делитель частоты: в регистр БА+3 занести 1 в 7 бит и настроить режим передачи, после данного шага в БА+1 заносятся старшие байты коэфф. передча, в БА+0 младшие. Для начала передчаси в БА+3 в 7 бит заносится 0 и задается режим передачи. Ждем пока 5 бит БА+5 не будет равен 1, после чего переносим данные в БА+0

Для вывода информации первым делом нужно проверить прошли ли данные, для чего мы проверяем 6, 5 и 0 биты БА+5. Если все нормально, то в БА+0 будут пересланные данные

";
                font.pixelSize: 15
                wrapMode: Text.WordWrap
                horizontalAlignment: Text.AlignHCenter
                leftPadding: 80
                topPadding: 30
            }

            Label {

                anchors.bottom: parent.bottom
                anchors.bottomMargin: 20
                anchors.left: parent.left
                anchors.leftMargin: 180
                text: "Программа для 'Module-40':
B080
E623
BA20F8
B01F
EE          разрешаем расширенные адреса
BA22F8
B0E0
EE
BA24F8
B080
EE
BA36F8
B000
EE
BAFBF4      разрешение доступак регистру делителя частоты
B083
EE
BAF9F4      настройка предделителя частоты
B000
EE
BAF8F4
B001
EE
BAFBF4      передача и прием
B003
EE
BAFDF4      считывание линии состояния до загрузки данных в буфер передатчика
EC
2420
74F8
BAF8F4      загрузка данных в буфер передатчика из ячейки 4100h
A0041
EE
BAFDF4      передача данных с тактированием от кнопки
EC
3C61
75F8
BAF8F4      чтение данных из буфера приемника и помещение в ячейку 4200h
EC
A20042
EBE0"
            }
        }
    }
//        Page {
//            ListView {
//                model: 4   // заменяем 3 на 4
//                spacing: 10

//                delegate: Item {
//                    id: delegateRoot
//                    width: parent.width
//                    height: column.height + image.height + spacing

//                    Column {
//                        id: column
//                        anchors.top: parent.top
//                        anchors.left: parent.left
//                        anchors.right: parent.right

//                        Text {
//                            text: {
//                                switch (model.index) {
//                                case 0:
//                                    return lcdInfo
//                                case 1:
//                                    return dlpInfo
//                                case 2:
//                                    return lcosInfo
//                                }
//                            }
//                        }
//                    }

//                    Image {
//                        id: image
//                        anchors.top: column.bottom
//                        width: 200
//                        height: 200
//                        anchors.horizontalCenter:parent.horizontalCenter
//                        source: {
//                            switch (model.index) {
//                            case 0:
//                                return "qrc:/images/LCD"
//                            case 1:
//                                return "qrc:/images/DLP"
//                            case 2:
//                                return "qrc:/images/300px-Lcos.svg"
//                            }
//                        }
//                    }
//                }
//            }
//        }}

    footer: TabBar {
        id: tabBar
        anchors.horizontalCenter: parent.horizontalCenter
        currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("Main")
        }

        TabButton {
            text: qsTr("Background and Property")
        }

        TabButton {
            text: qsTr("Information about devices")
        }

        TabButton {
            text: qsTr("CPU information")
        }

        TabButton {
            text: qsTr("Mem information")
        }

        TabButton {
            text: qsTr("LCD information")
        }

        TabButton {
            text: qsTr("DLP information")
        }

        TabButton {
            text: qsTr("LCoS information")
        }

        TabButton {
            text: qsTr("Work with Keyboard")
        }

        TabButton {
            text: qsTr("Rs-232 and Module-40")
        }
    }

    Connections {
        target: tabBar
        onCurrentIndexChanged: swipeView.currentIndex = tabBar.currentIndex
    }
}
