import QtQuick 2.7
import QtQuick.Window.Dock 1.0

DockableWindow {
    id: dockWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    flags: Qt.FramelessWindowHint

    color: "transparent"
    property alias title: title.text

    Item {
        id: stateManager
        states: [
            State {
                name: ""
            },
            State {
                name: "freeDragging"
                PropertyChanges {
                    target: dockWindow
                    width: tabHeader.width
                    height: tabHeader.height
                }
                PropertyChanges {
                    target: closeButton
                    visible: false
                }
                PropertyChanges {
                    target: dockWindow
                }
            }
        ]
    }

    Rectangle {
        width: parent.width
        height: parent.height

        radius: 10

        color: "red"
    }

    Rectangle {
        id: titleBar
        width: parent.width
        height: 30

        color: "orange"

        MouseArea {
            anchors.fill: parent

            property point orgPos: "0, 0"

            onPressed: {
                console.log("onPressed");
                orgPos.x = mouse.x;
                orgPos.y = mouse.y;


            }

            onPositionChanged: {
                dockWindow.x += mouse.x - orgPos.x;
                dockWindow.y += mouse.y - orgPos.y;
            }
        }
    }

    Rectangle {
        id: tabHeader

        width: 100
        height: 30

        color: "yellow"

        Text {
            id: title
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent

            hoverEnabled: true

            property point orgPos: "0, 0"
            property bool cancelDragging: false

            onPressed: {
                console.log("onPressed");
                orgPos.x = mouse.x;
                orgPos.y = mouse.y;

                cancelDragging = false;
            }

            onEntered: {
                //console.log("onEntered");
                startDrag();
            }

            onReleased: {
                //stateManager.state = "";
            }
        }
    }

    Rectangle {
        id: closeButton

        anchors.right: parent.right

        width: 30
        height: 30

        color: "black"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                Qt.quit();
            }
        }
    }

    Component.onCompleted: {
        console.log("on compledted ", title.text);
    }
}
