import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Window.Dock 1.0

DockWindow {
    id: rootWindow

    visible: true
    width: 200
    height: 200

    property var visibleWindows

    onVisibleWindowsChanged: {
        console.log("visibleWindowsChanged: ", visibleWindows.length);

        for (var i = 0; i < visibleWindows.length; i++) {
            console.log("  ", visibleWindows[i].title);
        }
    }

    function focusTo(dockWindow) {
        console.log("onDockWindowFocused");

        if (!visibleWindows) {
            visibleWindows = [];
        }

        var idx = visibleWindows.indexOf(dockWindow);
        if (idx >= 0) {
            visibleWindows.splice(idx, 1);
        }

        visibleWindows.unshift(dockWindow);
        console.log("  visibleWindows.length: ", visibleWindows.length);


        visibleWindowsChanged();
    }

    //property list<DockableWindow> visibleWindows;

    DockWindow {
        id: dock01
        visible: true
        width: 400
        height: 300
        x: 0

        title: "dock01"
    }

    DockWindow {
        id: dock02
        visible: true
        x: 400
        width: 300
        height: 200

        title: "dock02"

        Rectangle {
            anchors.centerIn: parent
            width: 100
            height: 30

            color: "blue"

            MouseArea {
                anchors.fill: parent

                onClicked: {
                    dock02.test01();
                }
            }
        }
    }

    Window {
        id: draggingTab
        visible: false;

        width: tabHeader.width
        height: tabHeader.height

        flags: Qt.SplashScreen

        property alias title: title.text

        Rectangle {
            id: tabHeader

            width: 100
            height: 30

            color: "orange"

            Text {
                id: title
                anchors.centerIn: parent
            }
        }

        MouseArea {
            anchors.fill: parent

            property point orgPos: "0, 0"

            onPressed: {
                console.log("onPressed");
                orgPos.x = mouse.x;
                orgPos.y = mouse.y;
            }

            onPositionChanged: {
                if (cancelDragging) {
                    return;
                }

                //console.log(mouse.x, mouse.y);

                stateManager.state = "freeDragging";

                draggingTab.x += mouse.x - orgPos.x;
                draggingTab.y += mouse.y - orgPos.y;

            }

            onReleased: {
                //stateManager.state = "";
            }
        }
    }


//    DockableWindow {
//        id: dock02
//        visible: true

//        width: 200
//        height: 200

//        color: "yellow"


//    }

    Component.onCompleted: {
        console.log("on compledted rootWindow");

    }
}
