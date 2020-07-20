import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id: mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Column {
       anchors.centerIn: parent
       spacing: 16
       Column {
         spacing: 4
         Text { text: "Username" }
         TextField { focus: true }
       }
       Column {
         spacing: 4
         Text { text: "Password" }
         TextField  { echoMode: TextInput.Password }
       }
       Row {
         spacing: 16
         anchors.horizontalCenter: parent.horizontalCenter
         Button { text: "Login"; onClicked: {

                 request('https://localhost:44321/weatherforecast', function(o) {

                     console.log(o.responseText);

                 })
             }
         }
         Button { text: "Close"; onClicked: mainWindow.close() }
       }
       Row {
         spacing: 10
         anchors.horizontalCenter: parent.horizontalCenter
         Button { text: "Test"; onClicked: {

                 request('https://localhost:44321/weatherforecast', function(o) {

                     console.log(o.responseText);

                 })
             } }
       }
     }


    function request(url, callback) {
        var xhr = new XMLHttpRequest();

        xhr.onreadystatechange = function() {
            if (xhr.readyState === XMLHttpRequest.DONE) {
                callback(xhr)
            }
        }

//        xhr.onreadystatechange = (function(myxhr) {
//            return function() {
//                callback(myxhr);
//            }
//        })(xhr);
        xhr.open('GET', url, true);
        xhr.send('');
    }
}
