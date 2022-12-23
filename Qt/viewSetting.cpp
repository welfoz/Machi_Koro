#include "viewSetting.h"
#include <QPainter>
#include <QString>
#include <QStaticText>
#include <QLabel>
#include <QColor>
#include <QLayout>
#include <QFont>
#include "../game/game.h"
#include "../game/controller/control.h"

ViewSetting::ViewSetting(QWidget *parent) : QWidget(parent){
    setWindowTitle("Machi Koro Settings");
}

void ViewSetting::viewInputText(){
    validateButton = new QPushButton("Validate");
    cancelButton = new QPushButton("Cancel");
    layoutButtons = new QHBoxLayout;
    layoutButtons->addWidget(validateButton);

    editPlayer = new QLineEdit;
    editPlayer->setFixedWidth(180);
    labelPlayer = new QLabel;
    labelPlayer->setText("Enter the player name : ");

    layer = new QGridLayout;
    layer->addWidget(labelPlayer, 0, 0);
    layer->addWidget(editPlayer, 0, 1);
    layer->addLayout(layoutButtons, 1, 0);

    setLayout(layer);

    connect(validateButton, &QPushButton::released, this, &ViewSetting::clickValidate);
    show();
}


void ViewSetting::clickValidate(){
    playerName = editPlayer->text();
    close();
}

