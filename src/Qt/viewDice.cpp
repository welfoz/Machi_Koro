#include "viewDice.h"
#include <QPainter>
#include <QString>
#include <QStaticText>
#include <QLabel>
#include <QColor>
#include <QLayout>
#include <QFont>
#include "../game/game.h"
#include "../game/controller/control.h"


ViewDice::ViewDice(const size_t dice, QWidget *parent): QPushButton(parent), dice(dice),
    layoutDice(nullptr)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(100,100);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(false);

}

/*ViewDice::ViewDice(QWidget *parent): QPushButton(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(100,100);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(false);
}*/

void ViewDice::setDice()
{
    clearLayout(this->layoutDice);

    delete layoutDice;
    this->layoutDice = new QVBoxLayout(this);

    setStyleSheet("background-color:white; color:black; font-size: 20pt; font-weight:bold");

    QLabel *diceText = new QLabel(this);
    diceText->setNum(static_cast<int>(Controller::getInstance().getGame()->getDiceValue()));
    diceText->move(40, 30);

    layoutDice->addWidget(diceText);
}

void ViewDice::clearLayout(QLayout *layout)
{
    if (layout == nullptr) {
        return;
    }
    QLayoutItem *vpItem;
       while ((vpItem = layout->takeAt(0)) != 0)  {
           if (vpItem->layout()) {
               clearLayout(vpItem->layout());
               vpItem->layout()->deleteLater();
           }
           if (vpItem->widget()) {
               vpItem->widget()->deleteLater();
           }
           delete vpItem;
       }
}
