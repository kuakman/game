import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import com.nahuelio.game.view.welcome 1.0

ApplicationWindow {
    id: mainWindow
    title: qsTr("Hello QTQuicks")
    height: 420
    width: 420
    visibility: Window.AutomaticVisibility
    visible: true

    Welcome {
        id: welcome
    }

    TextField {
        text: welcome.greeting
        placeholderText: qsTr("Greeting")
        anchors.centerIn: parent

        onTextChanged: welcome.greeting = text
    }

}
