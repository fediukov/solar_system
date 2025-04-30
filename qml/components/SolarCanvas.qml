import QtQuick

Item {
    id: canvasRoot

    // ====== cosmos view rectangle ======
    Rectangle {
        anchors.fill: parent
        //color: "#cc000080"
        color: "transparent"
        //border.color: "#cc000080"
        //radius: 8
    }

    property var objectModel: SolarSystem.GetList()

    // ====== Визуализация объектов ======
    Repeater {
        id: objectRepeater
        model: objectModel

        delegate: Rectangle {
            width: 3
            height: 3
            color: "yellow"
            radius: 3

            property real objX: modelData.x
            property real objY: modelData.y

            x: canvasRoot.width / 2 + objX * 30
            y: canvasRoot.height / 2 - objY * 30
        }
    }

    Connections {
        target: SolarSystem
        function onDateChanged() {
            objectModel = SolarSystem.GetList();
        }
    }
}