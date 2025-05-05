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
    // ============================================================================================

    // ===== close button =========================================================================
    Rectangle {
        width: 40
        height: 40
        anchors.top: parent.top
        anchors.right: parent.right
        color: "transparent"
        border.color: "transparent"
        
        Text {
            id: closeButton
            anchors.centerIn: parent
            text: "x"
            font.pixelSize: 20
            color: "#cccccc"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: Qt.quit()
            hoverEnabled: true
            onEntered: closeButton.color = "#999999"
            onExited: closeButton.color = "#cccccc"
        }
    }
    // ============================================================================================

    // ====== text and buttons field ==============================================================
    Row {
        spacing: 20
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 20

        // ===== prev button =====
        Rectangle {
            width: 100
            height: 40
            radius: 8
            color: "#333333"

            Text {
                anchors.centerIn: parent
                text: "Prev"
                color: "lightblue"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    SolarSystem.PrevDate();
                }
            }
        }

        // ===== date text ======
        Rectangle {
            width: 100
            height: 40
            color: "transparent"

            Text {
                id: dateText
                anchors.centerIn: parent
                text: SolarSystem.GetDateString()
                color: "lightblue"
            }
        }

        // ===== next button =====
        Rectangle {
            width: 100
            height: 40
            radius: 8
            color: "#333333"

            Text {
                anchors.centerIn: parent
                text: "Next"
                color: "lightblue"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    SolarSystem.NextDate();
                }
            }
        }
    }
    // ============================================================================================

    // ===== star system canvas ===================================================================
    SolarCanvas {
        anchors.fill: parent
        anchors.margins: 10
    }
    // ============================================================================================

    // ====== universe center =====================================================================
    Rectangle {
        anchors.centerIn: parent
        width: 1
        height: 1
        radius: 5
        color: "#77bbbbbb"
    }
    // ============================================================================================

    // ===== connections ==========================================================================
    Connections {
        target: SolarSystem
        function onDateChanged () {
            dateText.text = SolarSystem.GetDateString();
        }
    }
    // ============================================================================================
  
}