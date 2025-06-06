import QtQuick

Rectangle {
	id: button
	width: 80
	height: 36
	radius: 8
	color: "#306cb0"
	opacity: 0.6

	property string label: "button"
	property int pressedOffsetX: 0
	property int pressedOffsetY: 0
	signal clicked

	Text {
		id: text
		x: (button.width - width) / 2 + button.pressedOffsetX
		y: (button.height - height) / 2 + button.pressedOffsetY
		text: button.label
		color: "#cccccc"
	}

	MouseArea {
		id: mouse
		anchors.fill: parent
		hoverEnabled: true

		function stopTimers() {
			initTimer.stop()
			holdTimer.stop()
		}

		function setEnteredCondition() {
			button.color = "#2864a8"
			text.color = "#cccccc"
			button.pressedOffsetX = 0
			button.pressedOffsetY = 0
		}

		function setExitedCondition() {
			button.color = "#306cb0"
			text.color = "#dddddd"
		}

		function setPressedCondition() {
			button.color = "#205ca0"
			text.color = "#aaaaaa"
			button.pressedOffsetX = 1
			button.pressedOffsetY = 1
		}

        onEntered: {
			setEnteredCondition()
		}
		onExited: {
			setExitedCondition()
		}

		onPressed: {
			setPressedCondition()
			button.clicked()
			initTimer.start()
		}
		onReleased: {
			setEnteredCondition()
			stopTimers()
		}
		onCanceled: {
			setEnteredCondition()
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