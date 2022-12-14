#include "viewSet.h"
#include "viewCard.h"
#include "viewMonument.h"
#include <QPainter>
#include <QString>
#include <QStaticText>
#include <QLabel>
#include <QWidget>
#include <QGridLayout>



ViewSet::ViewSet(QWidget *parent) : QWidget(parent), viewcards(20, nullptr)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(1400,800);
    setWindowTitle("Machi Koro");
}

void ViewSet::printCarte()
{
    couche = new QHBoxLayout;

    layoutCards = new QGridLayout;
    //cards = new ViewCard;
    for(int i=0; i<15; i++){
        viewcards[i] = new ViewCard;
        viewcards[i]->setPrice(i);
        viewcards[i]->setDice(i);
    }
    for(int i=0; i<15; i++){
        viewcards[i]->paintCard();
        layoutCards->addWidget(viewcards[i], i/5, i%5, Qt::AlignTop);
    }

    layoutPlayerMonuments = new QGridLayout;
    monuments = new ViewMonument;
    monuments->paintMonument();
    for(int i=0; i<4; i++){
        monuments = new ViewMonument;
        monuments->paintMonument();
        layoutPlayerMonuments->addWidget(monuments, i/2, i%2);
    }
    /*}
    for(int i=0; i<4; i++){
        viewMonuments[i]->paintMonument();
        layourOnePlayer->addWidget(viewMonuments[i], i/2, i%2, Qt::AlignTop);
    }*/

    layoutPlayerCards = new QVBoxLayout;
    for(int i=0; i<5; i++){
        viewcards[i] = new ViewCard;
        viewcards[i]->setPrice(i);
        viewcards[i]->setDice(i);
    }
    for(int i=0; i<5; i++){
        viewcards[i]->paintCardOnlyName();
        layoutPlayerCards->addWidget(viewcards[i]);
    }
    cards = new ViewCard;
    cards->paintCard();
    layoutPlayerCards->addWidget(cards);
    layoutPlayerCards->setSpacing(0);


    layoutPlayer = new QVBoxLayout;
    layoutPlayer->addLayout(layoutPlayerMonuments);
    layoutPlayer->addLayout(layoutPlayerCards);


    layoutAllPlayers = new QHBoxLayout;
    layoutAllPlayers->addLayout(layoutPlayer);
    /*for(int i=0; i<4; i++){

        layoutAllPlayers->addLayout(layoutPlayer, i, i);
    }*/

    layoutDice = new QVBoxLayout;
    viewdice = new ViewDice;
    viewdice->paintDice();
    layoutDice->addWidget(viewdice);


    couche->addLayout(layoutCards);
    couche->addLayout(layoutDice);
    couche->addLayout(layoutAllPlayers);
    setLayout(couche);
}

