import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id: mainWindow
    width: 1280
    height: 720
    visible: true

    Button {
        anchors.centerIn: parent
        text: "Settings"
        onClicked: openSettings()
    }

    Dialog {
        id: settingsDialog
        title: "Settings menu"
        height: 150
        width: 300
        standardButtons: StandardButton.Ok | StandardButton.Discard
        property int players: 2

        Row {
            anchors.fill: parent
            spacing: 20
            Text {
                text: "Amount of Players"
                height: 40
            }
            SpinBox {
                id: playersSpinbox
                value: 50
                minimumValue: 2
                maximumValue: 5
            }
        }
        onAccepted: {
            console.log("debug: asetukset tallennettu")
            settingsDialog.players = playersSpinbox.value
        }
    }

    function openSettings() {
        console.log("debug: asetukset klikattu")
        playersSpinbox.value =  settingsDialog.players
        settingsDialog.visible = true
        settingsDialog.open()
    }
}
