#ifndef VIEWMESSAGE_H
#define VIEWMESSAGE_H

#include "../game/game.h"
#include "../game/controller/control.h"
#include <QMessageBox>

class ViewMessage : public QMessageBox
{
    Q_OBJECT
public:
    explicit ViewMessage(QWidget *parent = nullptr);
    void viewWelcomingMessage();
    void viewBasicMessage(QString message);
};


#endif // VIEWMESSAGE_H
