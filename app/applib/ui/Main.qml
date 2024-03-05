import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480

    property int value: 0

    Column {
        spacing: 10
        anchors.centerIn: parent

        Text {
            objectName: "text"
            text: value
        }

        Button {
            objectName: "button"
            text: "Button"
            onClicked: {
                value++
            }
        }
    }
}
