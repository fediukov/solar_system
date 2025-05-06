import QtQuick
import QtQuick.Controls

import "components"

ApplicationWindow {
    
    flags: Qt.FramelessWindowHint           // убрать оконную рамку
           | Qt.WA_TranslucentBackground    // добавить возможность transparent

    // ===== windows settings =====================================================================
    visibility: "FullScreen"
    visible: true
    title: "Solar System"
    color: "black"

    // ===== close button =========================================================================
    CloseButton {
        anchors.top: parent.top
        anchors.right: parent.right
        onClicked: Qt.quit()
    }

    // ====== labels and buttons field ============================================================
    Row {
        spacing: 20
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 20

        // ===== prev button =====
        ActionButton {
            label: "Prev"
            onClicked: SolarSystem.PrevDate();
        }

        // ===== date text ======
        DateLabel {
            id: dateLabel
            text: SolarSystem.GetDateString()
        }

        // ===== next button =====
       ActionButton {
            label: "Next"
            onClicked: SolarSystem.NextDate();
        }
    }

    // ===== star system canvas ===================================================================
    SolarCanvas {
        anchors.fill: parent
        anchors.margins: 10
    }

    // ====== universe center =====================================================================
    Rectangle {
        anchors.centerIn: parent
        width: 1
        height: 1
        color: "#77bbbbbb"
    }

    // ===== connections ==========================================================================
    Connections {
        target: SolarSystem
        function onDateChanged () {
            dateLabel.text = SolarSystem.GetDateString();
        }
    }
}