import QtQuick

Rectangle {
	id: button
	width: 80
	height: 36
	radius: 8
	color: "#306cb0"
	opacity: 0.6

	property bool isRunning: false
	property int pressedOffsetX: 0
	property int pressedOffsetY: 0

	signal toggled(bool running)

	Text {
		id: text
		x: (button.width - width) / 2 + button.pressedOffsetX
		y: (button.height - height) / 2 + button.pressedOffsetY
		text: button.isRunning ? "Stop" : "Start"
		color: "#cccccc"
	}

	MouseArea {
		id: mouse
		anchors.fill: parent
		hoverEnabled: true

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
		}
		onReleased: {
			setEnteredCondition()
		}
		onCanceled: {
			setEnteredCondition()
		}
		onClicked: {
			isRunning = !isRunning;
			toggled(isRunning);
		}
	}
}