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

    // ====== date labels and date buttons field ==================================================
    Row {
        id: dateRow
        spacing: 20
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 20

        // ===== prev button =====
        ActionButton {
            label: "Prev"
            onClicked: {
                if (startStopButton.isRunning)
                {
                    startStopButton.isRunning = false
                    runningTimer.stop()
                }
                SolarSystem.PrevDate();
            }
        }

        // ===== date text ======
        DateLabel {
            id: dateLabel
            text: SolarSystem.GetDateString()
        }

        // ===== next button =====
       ActionButton {
            label: "Next"
            onClicked: {
                if (startStopButton.isRunning)
                {
                    startStopButton.isRunning = false
                    runningTimer.stop()
                }
                SolarSystem.NextDate();
            }
        }
    }

    // ===== start/stop row =======================================================================
    Row {
        id: startRow
        spacing: 20
        anchors.left: dateRow.right
        anchors.verticalCenter: dateRow.verticalCenter
        anchors.leftMargin: 20

        // ===== start/stop button =====
        StartStopButton {
            id: startStopButton
            onToggled: (running) => {
                if (running) {
                    runningTimer.start()
                } else {
                    runningTimer.stop()
                }
            }
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

    // ===== timers ===============================================================================
    Timer {
        id: runningTimer
        interval: 100
        repeat: true
        running: false
        onTriggered: SolarSystem.NextDate()
    }
    
    // ===== connections ==========================================================================
    Connections {
        target: SolarSystem
        function onDateChanged () {
            dateLabel.text = SolarSystem.GetDateString();
        }
    }
}