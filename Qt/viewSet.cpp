#include "viewSet.h"
#include "viewCard.h"
#include "viewMonument.h"
#include <QPainter>
#include <QString>
#include <QStaticText>
#include <QLabel>
#include <QWidget>
#include <QGridLayout>

#include "../game/game.h"
#include "../game/controller/control.h"



ViewSet::ViewSet(QWidget *parent) : QWidget(parent), viewcards(20, nullptr), viewmonuments(6, nullptr), viewPlayers(4, nullptr), viewDices(2, nullptr)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(1400,800);
    setWindowTitle("Machi Koro");
}

void ViewSet::setSet()
{
    couche = new QHBoxLayout;

    layoutCards = new QGridLayout;
    int i=0;
    for(auto it=Controller::getInstance().getGame()->getBoard()->getCards().begin(); it != Controller::getInstance().getGame()->getBoard()->getCards().end(); it++){
        viewcards[i] = new ViewCard(it->first);
        viewcards[i]->setCard(it->first);
        layoutCards->addWidget(viewcards[i], i/5, i%5, Qt::AlignTop);
        connect(viewcards[i], SIGNAL(cardClicked(ViewCard*)), this, SLOT(cardClick(ViewCard*)));
        i++;
    }

    layoutAllPlayers = new QGridLayout;

    i=0;
    for(size_t j = 0; j<Controller::getInstance().getGame()->getNbPlayers(); j++){
        Player player = Controller::getInstance().getGame()->getPlayer(j);
        viewPlayers[i] = new ViewOnePlayer;
        layoutPlayer = new QVBoxLayout;

        QLabel *playerName = new QLabel(this);
        playerName->setText(QString::fromStdString(player.getUsername()));

        QLabel *playerMoneyText = new QLabel(this);
        playerMoneyText->setText("Money : ");
        QLabel *playerMoney = new QLabel(this);
        playerMoney->setNum(static_cast<int>(Controller::getInstance().getGame()->getBank()->getAccount(player.getId())->getSolde()));
        layoutPlayerMoney = new QHBoxLayout;
        layoutPlayerMoney->addWidget(playerMoneyText);
        layoutPlayerMoney->addWidget(playerMoney);


        int k=0;
        layoutPlayerMonuments = new QGridLayout;
        for (auto it = player.getMonuments().begin(); it!=player.getMonuments().end(); it++){
            viewmonuments[k] = new ViewMonument(it->first);
            viewmonuments[k]->setMonument(it->first);
            layoutPlayerMonuments->addWidget(viewmonuments[k], k/2, k%2);
            connect(viewmonuments[k], SIGNAL(monumentClicked(ViewMonument*)), this, SLOT(monumentClick(ViewMonument*)));
            k++;
        }

        k=0;
        layoutPlayerCards = new QVBoxLayout;
        for (auto it = player.getCards().begin(); it != player.getCards().end(); it++){
            if (it->second>0){
                viewcards[k] = new ViewCard(it->first);
                viewcards[k]->setCardOnlyName(it->first);
                layoutPlayerCards->addWidget(viewcards[k]);
                connect(viewcards[k], SIGNAL(cardClicked(ViewCard*)), this, SLOT(cardClick(ViewCard*)));
                k++;
            }
        }


        layoutPlayer->addWidget(playerName);
        layoutPlayer->addLayout(layoutPlayerMoney);
        layoutPlayer->addLayout(layoutPlayerMonuments);
        layoutPlayer->addLayout(layoutPlayerCards);

        layoutAllPlayers->addLayout(layoutPlayer, 0, i, Qt::AlignTop);
        i++;
    }

    layoutDice = new QVBoxLayout;
    for (i=0; i<2; i++){
        viewDices[i] = new ViewDice(Controller::getInstance().getGame()->getDiceValue());
        viewDices[i]->setDice();
        layoutDice->addWidget(viewDices[i], Qt::AlignTop);
        connect(viewDices[i], SIGNAL(diceClicked(ViewDice*)), this, SLOT(diceClick(ViewDice*)));

    }

    couche->addLayout(layoutCards);
    couche->addLayout(layoutDice);
    couche->addLayout(layoutAllPlayers);
    setLayout(couche);
}

void ViewSet::cardClick(ViewCard* vc)
{
    QMessageBox qmsgbox;
    qmsgbox.setText(QString::fromStdString(vc->getCard()->getName()));
    qmsgbox.exec();
}

void ViewSet::diceClick(ViewDice *vd)
{
    QMessageBox qmsgbox;
    qmsgbox.setText(QString::number(static_cast<int>(vd->getDice())));
    qmsgbox.exec();
}

void ViewSet::monumentClick(ViewMonument *vm)
{
    QMessageBox qmsgbox;
    qmsgbox.setText(QString::fromStdString(vm->getMonument()->getName()));
    qmsgbox.exec();
}

