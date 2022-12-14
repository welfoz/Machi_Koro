#include "viewMonument.h"
#include <QPainter>
#include <QString>
#include <QStaticText>
#include <QLabel>
#include <QColor>
#include <QLayout>
#include <QFont>


ViewMonument::ViewMonument(QWidget *parent): QPushButton(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(75,100);
    //connect(this,SIGNAL(clicked()),this,SLOT(clickedEvent()));
    setCheckable(false);
}

void ViewMonument::paintMonument()
{
    setStyleSheet("background-color:grey; color:black; font-size: 5pt");

    QLabel *cardName = new QLabel(this);
    cardName->setWordWrap(true);
    cardName->setText(QString::fromStdString(name));
    cardName->setStyleSheet("font-weight: bold; font-size: 7pt");

    QLabel *priceText = new QLabel(this);
    priceText->setText("Price : ");
    QLabel *priceValue = new QLabel(this);
    priceValue->setNum(price);

    QLabel *effectText = new QLabel(this);
    effectText->setText("Effect : ");
    QLabel *effectValue = new QLabel(this);
    effectValue->setWordWrap(true);
    effectValue->setText(QString::fromStdString(effect));

    QVBoxLayout *layoutCard = new QVBoxLayout(this);

    QHBoxLayout *layoutPrice = new QHBoxLayout(this);
    layoutPrice->addWidget(priceText, 0, Qt::AlignLeft);
    layoutPrice->addWidget(priceValue, 0, Qt::AlignLeft);

    QHBoxLayout *layoutEffect = new QHBoxLayout(this);
    layoutEffect->addWidget(effectText);
    layoutEffect->addWidget(effectValue);

    layoutCard->addWidget(cardName, 0, Qt::AlignHCenter);
    layoutCard->addLayout(layoutPrice);
    layoutCard->addLayout(layoutEffect);
}
