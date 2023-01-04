#pragma once
#include <vector>
#include <set>
#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QMessageBox>

#include "viewCard.h"
#include "viewMonument.h"
#include "viewDice.h"
#include "viewOnePlayer.h"
#include "chatwindow.h"

class QLabel;
class QLineEdit;
class QPushButton;
class QHBoxLayout;
class QVBoxLayout;
class QGridLayout;
class QProgressBar;
class QLCDNumber;


class ViewSet : public QWidget
{
    Q_OBJECT
public:
    explicit ViewSet(QWidget *parent = nullptr);
    void setSet();
    void sendMessageToChat(string message);
private:
    QHBoxLayout* couche;
    QGridLayout* layoutCards;
    QVBoxLayout* layoutPlayer;
    QGridLayout* layoutPlayerMonuments;
    QVBoxLayout* layoutPlayerCards;
    QGridLayout* layoutAllPlayers;
    QVBoxLayout* layoutDice;
    QHBoxLayout* layoutPlayerMoney;

    ChatWindow* chat;
    ViewCard* cards;
    std::vector<ViewCard*> viewEstablishments;
    std::vector<ViewCard*> cardsOnlyName;
    ViewMonument* monuments;
    std::vector<ViewMonument*> viewmonuments;
    ViewOnePlayer* player;
    std::vector<ViewOnePlayer*> viewPlayers;
    ViewDice* dice;
    void clearLayout(QLayout* layout);
    void setAllPlayers();
private slots:
    void cardClick(ViewCard* vc);
    void monumentClick(ViewMonument* vm);
    void diceClick(ViewDice* vd);
};
