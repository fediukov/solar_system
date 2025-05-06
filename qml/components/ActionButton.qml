import QtQuick

Rectangle {
	id: button
	width: 100
	height: 40
	radius: 8
	color: "#333333"

	property string label: "button"
	signal clicked

	Text {
		id: text
		anchors.centerIn: parent
		text: button.label
		color: "lightblue"
	}

	MouseArea {
		id: mouse
		anchors.fill: parent
		hoverEnabled: true

		function stopTimers() {
			initTimer.stop()
			holdTimer.stop()
		}

        onEntered: text.color = "#cccccc"
        onExited: text.color = "lightblue"

		onPressed: {
			button.clicked()
			initTimer.start()
		}
		onReleased: {
			stopTimers()
		}
		onCanceled: {
			stopTimers()
		}
	}

	Timer {
		id: initTimer
		interval: 400
		repeat: false
		running: false
		onTriggered: holdTimer.start()
	}
	
	Timer {
		id: holdTimer
		interval: 100
		repeat: true
		running: false
		onTriggered: button.clicked()
	}
}