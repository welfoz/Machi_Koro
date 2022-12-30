#include "viewMonument.h"
#include <QPainter>
#include <QString>
#include <QStaticText>
#include <QLabel>
#include <QColor>
#include <QLayout>
#include <QFont>
#include "../game/game.h"

ViewMonument::ViewMonument(const Monument* monument, QWidget *parent): QPushButton(parent), monument(monument)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(75,100);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(false);
}

ViewMonument::ViewMonument(QWidget *parent): QPushButton(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(75,100);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(false);
}

void ViewMonument::setMonument(Monument* monument)
{
    setStyleSheet("background-color:grey; color:black; font-size: 5pt");
    QLabel *cardName = new QLabel(this);
    cardName->setWordWrap(true);
    cardName->setText(QString::fromStdString(monument->getName()));
    cardName->setStyleSheet("font-weight: bold; font-size: 7pt");

    QLabel *priceText = new QLabel(this);
    priceText->setText("Price : ");
    QLabel *priceValue = new QLabel(this);
    priceValue->setNum(static_cast<int>(monument->getPrice()));

    QLabel *effectValue = new QLabel(this);
    effectValue->setWordWrap(true);
    effectValue->setText(QString::fromStdString(monument->getEffetDescription()));

    QVBoxLayout *layoutCard = new QVBoxLayout(this);

    QHBoxLayout *layoutPrice = new QHBoxLayout(this);
    layoutPrice->addWidget(priceText, 0, Qt::AlignLeft);
    layoutPrice->addWidget(priceValue, 0, Qt::AlignLeft);

    layoutCard->addWidget(cardName, 0, Qt::AlignHCenter);
    layoutCard->addLayout(layoutPrice);
    layoutCard->addWidget(effectValue);
}
