#include "viewMessage.h"

ViewMessage::ViewMessage(QWidget *parent) : QMessageBox(parent) {
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

void ViewMessage::viewWelcomingMessage(){
    //setFixedSize(500, 500);
    setText("MACHI KORO - LO21\n\nMade with ❤️ by MICHEL Fabien - BROSSARD Felix - TAVERNE Jules - CORTY Pol - LEMERLE Xavier");
    exec();
}

void ViewMessage::viewBasicMessage(QString message){
    setText(message);
    exec();
}
