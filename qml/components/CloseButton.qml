import QtQuick

Rectangle {
    id: closeButton
    width: 40
    height: 40
    color: "transparent"
    border.color: "transparent"
        
    signal clicked

    Text {
        id: cross
        anchors.centerIn: parent
        text: "x"
        font.pixelSize: 20
        color: "#cccccc"
    }

    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        onEntered: cross.color = "#999999"
        onExited: cross.color = "#cccccc"
        
        onPressed: closeButton.opacity = 0.6
        onReleased: closeButton.opacity = 1.0
        onCanceled: closeButton.opacity = 1.0

        onClicked: closeButton.clicked()
    }
}