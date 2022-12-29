#pragma once
#include "../game/controller/control.h"
#include <QMessageBox>

class ViewMessage : public QMessageBox
{
    Q_OBJECT
public:
    explicit ViewMessage(QWidget *parent = nullptr);
    void viewWelcomingMessage();
    void viewBasicMessage(QString);
};
