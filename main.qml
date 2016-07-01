import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Window.Dock 1.0

Window {
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

        title: "dock01"
    }

    DockWindow {
        id: dock02
        visible: true
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
