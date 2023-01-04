#pragma once
#include "../game/controller/control.h"
#include <QMessageBox>
#include <QCloseEvent>

class ViewMessage : public QMessageBox
{
    Q_OBJECT
public:
    explicit ViewMessage(QWidget *parent = nullptr);
    void viewWelcomingMessage();
    void viewBasicMessage(QString message);
    void closeEvent(QCloseEvent *event) override;
};

