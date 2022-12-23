#include "viewCard.h"
#include <QPainter>
#include <QString>
#include <QStaticText>
#include <QLabel>
#include <QColor>
#include <QLayout>
#include <QFont>
#include "../game/game.h"

ViewCard::ViewCard(const EstablishmentCard* card, QWidget *parent): QPushButton(parent), card(card)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(113,150);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(false);
}


ViewCard::ViewCard(QWidget *parent): QPushButton(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(113,150);
    connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(false);
}

void ViewCard::setCardOnlyName(EstablishmentCard* card){
    setStyleSheet("background-color:white; color:black; font-size: 5pt");
    setFixedSize(113,40);

    QLabel *cardName = new QLabel(this);
    cardName->setWordWrap(true);
    cardName->setText(QString::fromStdString(card->getName()));

    switch (card->getType()) {
    case Type::primaryIndustry:
        cardName->setStyleSheet("font-weight: bold; color: blue; font-size: 8pt");
        break;
    case Type::secondaryIndustry:
        cardName->setStyleSheet("font-weight: bold; color: green; font-size: 8pt");
        break;
    case Type::restaurants:
        cardName->setStyleSheet("font-weight: bold; color: red; font-size: 8pt");
        break;
    case Type::majorEstablishment:
        cardName->setStyleSheet("font-weight: bold; color: purple; font-size: 8pt");
        break;
    }
    QVBoxLayout *layoutCard = new QVBoxLayout(this);
    layoutCard->addWidget(cardName, 0, Qt::AlignHCenter);
}

void ViewCard::setCard(EstablishmentCard* card){
    setStyleSheet("background-color:white; color:black; font-size: 5pt");

    QLabel* cardname= new QLabel(this);
    cardname->setWordWrap(true);
    cardname->setText(QString::fromStdString(card->getName()));

    switch (card->getType()) {
    case Type::primaryIndustry:
        cardname->setStyleSheet("font-weight: bold; color: blue; font-size: 8pt");
        break;
    case Type::secondaryIndustry:
        cardname->setStyleSheet("font-weight: bold; color: green; font-size: 8pt");
        break;
    case Type::restaurants:
        cardname->setStyleSheet("font-weight: bold; color: red; font-size: 8pt");
        break;
    case Type::majorEstablishment:
        cardname->setStyleSheet("font-weight: bold; color: purple; font-size: 8pt");
        break;
    }

    QLabel *cardRemainingText = new QLabel(this);
    cardRemainingText->setText("Cards remaining : ");
    QLabel *cardRemainingValue = new QLabel(this);
    cardRemainingValue->setNum(static_cast<int>(card->getQuantity()));

    QLabel *activationNumberText = new QLabel(this);
    activationNumberText->setText("Activation number : ");
    string activationNumbers;
    size_t* actNumbers = card->getActivationNumbers();
    for(size_t i = 0; i < card->getNumberActivation(); i++){
        activationNumbers += std::to_string(*actNumbers) + ' ';
        actNumbers++;
    }
    QLabel *activationNumberValue = new QLabel(this);
    activationNumberValue->setText(QString::fromStdString(activationNumbers));

    QLabel *priceText = new QLabel(this);
    priceText->setText("Price : ");
    QLabel *priceValue = new QLabel(this);
    priceValue->setNum(static_cast<int>(card->getPrice()));

    QLabel *iconText = new QLabel(this);
    iconText->setText("Icon : ");
    QLabel *iconValue = new QLabel(this);
    iconValue->setText(QString::fromStdString(card->getIcon()->getName()));

    QLabel *effectText = new QLabel(this);
    effectText->setText("Effect : ");
    QLabel *effectValue = new QLabel(this);
    effectValue->setWordWrap(true);
    effectValue->setText(QString::fromStdString(card->getEffetDescription()));

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

    layoutCard->addWidget(cardname, 0, Qt::AlignHCenter);
    layoutCard->addLayout(layoutCardRemaining);
    layoutCard->addLayout(layoutActivationNumber);
    layoutCard->addLayout(layoutPrice);
    layoutCard->addLayout(layoutIcon);
    layoutCard->addLayout(layoutEffect);
}