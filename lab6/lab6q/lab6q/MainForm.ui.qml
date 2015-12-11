import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    width: 640
    height: 480

    property alias button3: button3
    property alias button2: button2
    property alias button1: button1

    RowLayout {
        anchors.centerIn: parent
    }

    Image {
        id: image1
        x: 114
        y: 122
        width: 397
        height: 331
        source: "../temp.jpg"
    }

    TextEdit {
        id: textEdit1
        x: 124
        y: 64
        width: 80
        height: 20
        text: qsTr("Text Edit")
        font.pixelSize: 12
    }

    TextEdit {
        id: textEdit2
        x: 305
        y: 96
        width: 80
        height: 20
        text: qsTr("Text Edit")
        font.pixelSize: 12
    }
}
