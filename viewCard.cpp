#include "viewCard.h"
#include <QPainter>
#include <QString>
#include <QStaticText>
#include <QLabel>
#include <QColor>
#include <QLayout>
#include <QFont>

ViewCard::ViewCard(QWidget *parent): QPushButton(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(113,150);
    //connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(false);
}

void ViewCard::paintCard()
{
    setStyleSheet("background-color:white; color:black; font-size: 5pt");

    QLabel *cardName = new QLabel(this);
    cardName->setWordWrap(true);
    cardName->setText(QString::fromStdString(name));
    cardName->setStyleSheet("font-weight: bold; color:blue; font-size: 8pt");

    QLabel *cardRemainingText = new QLabel(this);
    cardRemainingText->setText("Cards remaining : ");
    QLabel *cardRemainingValue = new QLabel(this);
    cardRemainingValue->setNum(cardRemaining);

    QLabel *activationNumberText = new QLabel(this);
    activationNumberText->setText("Activation number : ");
    QLabel *activationNumberValue = new QLabel(this);
    activationNumberValue->setNum(activationNumber);

    QLabel *priceText = new QLabel(this);
    priceText->setText("Price : ");
    QLabel *priceValue = new QLabel(this);
    priceValue->setNum(price);

    QLabel *iconText = new QLabel(this);
    iconText->setText("Icon : ");
    QLabel *iconValue = new QLabel(this);
    iconValue->setText(QString::fromStdString(icon));

    QLabel *effectText = new QLabel(this);
    effectText->setText("Effect : ");
    QLabel *effectValue = new QLabel(this);
    effectValue->setWordWrap(true);
    effectValue->setText(QString::fromStdString(effect));

    QVBoxLayout *layoutCard = new QVBoxLayout(this);

    QHBoxLayout *layoutCardRemaining = new QHBoxLayout(this);
    layoutCardRemaining->addWidget(cardRemainingText);
    layoutCardRemaining->addWidget(cardRemainingValue);

    QHBoxLayout *layoutActivationNumber = new QHBoxLayout(this);
    layoutActivationNumber->addWidget(activationNumberText);
    layoutActivationNumber->addWidget(activationNumberValue);

    QHBoxLayout *layoutPrice = new QHBoxLayout(this);
    layoutPrice->addWidget(priceText, 0, Qt::AlignLeft);
    layoutPrice->addWidget(priceValue, 0, Qt::AlignLeft);

    QHBoxLayout *layoutIcon = new QHBoxLayout(this);
    layoutIcon->addWidget(iconText);
    layoutIcon->addWidget(iconValue);

    QHBoxLayout *layoutEffect = new QHBoxLayout(this);
    layoutEffect->addWidget(effectText);
    layoutEffect->addWidget(effectValue);

    layoutCard->addWidget(cardName, 0, Qt::AlignHCenter);
    layoutCard->addLayout(layoutCardRemaining);
    layoutCard->addLayout(layoutActivationNumber);
    layoutCard->addLayout(layoutPrice);
    layoutCard->addLayout(layoutIcon);
    layoutCard->addLayout(layoutEffect);
}

void ViewCard::paintCardOnlyName(){
    setStyleSheet("background-color:white; color:black; font-size: 5pt");
    setFixedSize(113,40);

    QLabel *cardName = new QLabel(this);
    cardName->setWordWrap(true);
    cardName->setText(QString::fromStdString(name));
    cardName->setStyleSheet("font-weight: bold; color:blue; font-size: 8pt");
    QVBoxLayout *layoutCard = new QVBoxLayout(this);
    layoutCard->addWidget(cardName, 0, Qt::AlignHCenter);
}
