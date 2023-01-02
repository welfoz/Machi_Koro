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



// à quoi servent cardsOnlyName -> de setCardOnlyName
// attention les cartes des joueurs ne s'affichent plus
ViewSet::ViewSet(QWidget *parent) : QWidget(parent),
    viewEstablishments(Controller::getInstance().getGame()->getBoard()->getCards().size(), nullptr),
    viewmonuments(Controller::getInstance().getGame()->getPlayer(0).getMonuments().size(), nullptr),
    viewPlayers(Controller::getInstance().getGame()->getNbPlayers(), nullptr),
    cardsOnlyName(20, nullptr), layoutAllPlayers(nullptr)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    setFixedSize(1400,800);
    setWindowTitle("Machi Koro");

    couche = new QHBoxLayout;

    layoutCards = new QGridLayout;
    int i=0;
    for(auto it=Controller::getInstance().getGame()->getBoard()->getCards().begin(); it != Controller::getInstance().getGame()->getBoard()->getCards().end(); it++){
        viewEstablishments[i] = new ViewCard(it->first);
        viewEstablishments[i]->setCard();
        layoutCards->addWidget(viewEstablishments[i], i/5, i%5, Qt::AlignTop);
        connect(viewEstablishments[i], SIGNAL(cardClicked(ViewCard*)), this, SLOT(cardClick(ViewCard*)));
        i++;
    }

    // setPlayers
    this->layoutAllPlayers = new QGridLayout;
    this->setAllPlayers();


    layoutDice = new QVBoxLayout;
    QLabel* diceText = new QLabel(this);
    diceText->setText("Dice value :");
    diceText->setStyleSheet("font-weight: bold; font-size: 10pt");
    dice = new ViewDice(Controller::getInstance().getGame()->getDiceValue());
    dice->setDice();
    layoutDice->addWidget(diceText);
    layoutDice->addWidget(dice);
    layoutDice->setAlignment(Qt::AlignTop);
    connect(dice, SIGNAL(diceClicked(ViewDice*)), this, SLOT(diceClick(ViewDice*)));

    couche->addLayout(layoutCards);
    couche->addLayout(layoutDice);
    couche->addLayout(layoutAllPlayers);
    setLayout(couche);

}

void ViewSet::setSet()
{
    // update Establishment Cards
    for (auto cards: viewEstablishments) {
        if (cards != nullptr) {
            cards->setCard();
        }
    }

    //update Dice
    dice->setDice();

    // update money
    // update monuments
    // update player cards
    // update player
    this->setAllPlayers();

    layoutDice->update();
    layoutAllPlayers->update();
    couche->update();
    update();
}

void ViewSet::setAllPlayers() {

    // clear all layouts & widgets relative to layoutCard
    clearLayout(this->layoutAllPlayers);

    int i=0;
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
        layoutPlayerMoney = new QHBoxLayout();
        layoutPlayerMoney->addWidget(playerMoneyText);
        layoutPlayerMoney->addWidget(playerMoney);


        int k=0;
        layoutPlayerMonuments = new QGridLayout;
        for (auto it = player.getMonuments().begin(); it!=player.getMonuments().end(); it++){
            viewmonuments[k] = new ViewMonument(it->first);
            viewmonuments[k]->setMonument(it->first, it->second);
            layoutPlayerMonuments->addWidget(viewmonuments[k], k/2, k%2);
            connect(viewmonuments[k], SIGNAL(monumentClicked(ViewMonument*)), this, SLOT(monumentClick(ViewMonument*)));
            k++;
        }

        k=0;
        layoutPlayerCards = new QVBoxLayout;
        for (auto it = player.getCards().begin(); it != player.getCards().end(); it++){
            if (it->second>0){
                cardsOnlyName[k] = new ViewCard(it->first);
                cardsOnlyName[k]->setCardOnlyName();
                layoutPlayerCards->addWidget(cardsOnlyName[k]);
                connect(cardsOnlyName[k], SIGNAL(cardClicked(ViewCard*)), this, SLOT(cardClick(ViewCard*)));
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

void ViewSet::clearLayout(QLayout* layout)
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
