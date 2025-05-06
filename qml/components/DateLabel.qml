import QtQuick

Rectangle {
    id: label
	width: 100
    height: 40
    color: "transparent"

    property string text: "-"

    Text {
        id: dateText
        anchors.centerIn: parent
        text: label.text
        color: "lightblue"
    }
}