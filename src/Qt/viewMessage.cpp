#include "viewMessage.h"

ViewMessage::ViewMessage(QWidget *parent) : QMessageBox(parent) {
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}

void ViewMessage::viewWelcomingMessage(){
    setText("MACHI KORO - LO21");
    setInformativeText("Made with ❤ by MICHEL Fabien - BROSSARD Felix - TAVERNE Jules - CORTY Pol - LEMERLE Xavier");
    exec();
}

void ViewMessage::viewBasicMessage(QString message){
    setText(message);
    exec();
}

void ViewMessage::closeEvent(QCloseEvent *event) {
    if (event->spontaneous()) {
        event->ignore();
    } else {
        event->accept();
    }
}
