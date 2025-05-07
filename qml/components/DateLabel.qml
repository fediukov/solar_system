import QtQuick

Rectangle {
    id: label
	width: 80
    height: 36
    color: "transparent"

    property string text: "-"

    Text {
        id: dateText
        anchors.centerIn: parent
        text: label.text
        color: "#508cd0"
    }
}