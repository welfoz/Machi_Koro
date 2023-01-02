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
#include "../interface/gui.h"

ViewSetting::ViewSetting(QWidget *parent) : QDialog(parent){
    setWindowTitle("Machi Koro Settings");
}

void ViewSetting::viewInputText(){
    validateButtonText = new QPushButton("Validate");
    layoutButtons = new QHBoxLayout;
    layoutButtons->addWidget(validateButtonText);

    editText = new QLineEdit;
    editText->setFixedWidth(180);
    labelText = new QLabel;
    labelText->setText("Enter the text : ");

    layer = new QGridLayout;
    layer->addWidget(labelText, 0, 0);
    layer->addWidget(editText, 0, 1);
    layer->addLayout(layoutButtons, 1, 0);

    setLayout(layer);

    connect(validateButtonText, &QPushButton::released, this, &ViewSetting::clickValidateText);
}

void ViewSetting::viewInputNumber(){
    validateButtonNumber = new QPushButton("Validate");
    layoutButtons = new QHBoxLayout;
    layoutButtons->addWidget(validateButtonNumber);

    spinBoxNumber = new QSpinBox;
    spinBoxNumber->setMinimum(0);
    spinBoxNumber->setMaximum(100);
    labelNumber = new QLabel;
    labelNumber->setText("Enter the number");

    layer = new QGridLayout;
    layer->addWidget(labelNumber, 0, 0);
    layer->addWidget(spinBoxNumber, 0, 1);
    layer->addLayout(layoutButtons, 1, 0);

    setLayout(layer);

    connect(validateButtonNumber, &QPushButton::released, this, &ViewSetting::clickValidateNumber);
}

void ViewSetting::viewConfirmationDialog(QString message, QString firstOption, QString secondOption){
    validateFirstOption = new QPushButton(firstOption);
    validateSecondOption = new QPushButton(secondOption);
    layoutButtons = new QHBoxLayout;
    layoutButtons->addWidget(validateFirstOption);
    layoutButtons->addWidget(validateSecondOption);

    labelText = new QLabel;
    labelText->setText(message);

    layer = new QGridLayout;
    layer->addWidget(labelText, 0, 0);
    layer->addLayout(layoutButtons, 0, 1);

    setLayout(layer);

    connect(validateFirstOption, &QPushButton::released, this, &ViewSetting::clickFirstOption);
    connect(validateSecondOption, &QPushButton::released, this, &ViewSetting::clickSecondOption);
}


void ViewSetting::clickValidateText(){
    text = editText->text();
    if (dynamic_cast<Gui*>(Controller::getInstance().getInterface(true)) != nullptr)
        dynamic_cast<Gui*>(Controller::getInstance().getInterface(true))->update();
    close();
}

void ViewSetting::clickValidateNumber(){
    number = spinBoxNumber->value();
    if (dynamic_cast<Gui*>(Controller::getInstance().getInterface(true)) != nullptr)
        dynamic_cast<Gui*>(Controller::getInstance().getInterface(true))->update();
    close();
}

void ViewSetting::clickFirstOption(){
    message = validateFirstOption->text();
    if (dynamic_cast<Gui*>(Controller::getInstance().getInterface(true)) != nullptr)
        dynamic_cast<Gui*>(Controller::getInstance().getInterface(true))->update();
    close();
}

void ViewSetting::clickSecondOption(){
    message = validateSecondOption->text();
    if (dynamic_cast<Gui*>(Controller::getInstance().getInterface(true)) != nullptr)
        dynamic_cast<Gui*>(Controller::getInstance().getInterface(true))->update();
    close();
}

