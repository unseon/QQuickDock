import QtQuick 2.7
import QtQuick.Window.Dock 1.0

DockableWindow {
    id: dockWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    //flags: Qt.Tool
    flags: Qt.SubWindow

    color: "transparent"
    property alias title: title.text

    onFocusIn: {
        console.log("Focus in : ", title.text);

        console.log("calling dockWindowFocused");
        rootWindow.focusTo(this);
    }

    onVisibleChanged: {
        console.log("visible changed ", title.text, visible);
        rootWindow.dockWindowVisibleChanged(this, visible);
    }

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
            onClicked: {
                //Qt.quit();
                //window.x = 0;
            }

            property point orgPos: "0, 0"

            onPressed: {
                console.log("onPressed");
                orgPos.x = mouse.x;
                orgPos.y = mouse.y;
            }

            onPositionChanged: {
                //console.log(mouse.x, mouse.y);

                stateManager.state = "freeDragging";

                dockWindow.x += mouse.x - orgPos.x;
                dockWindow.y += mouse.y - orgPos.y;
            }

            onReleased: {
                stateManager.state = "";
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
