#include "viewDice.h"
#include <QPainter>
#include <QString>
#include <QStaticText>
#include <QLabel>
#include <QColor>
#include <QLayout>
#include <QFont>

ViewDice::ViewDice(QWidget *parent): QPushButton(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(100,100);
}

void ViewDice::paintDice()
{
    setStyleSheet("background-color:white; color:black; font-size: 20pt; font-weight:bold");

    QLabel *diceText = new QLabel(this);
    diceText->setText("3");
    diceText->setAlignment(Qt::AlignHCenter);
    QVBoxLayout *layoutDice = new QVBoxLayout;
    layoutDice->addWidget(diceText, 0, Qt::AlignHCenter);
}
