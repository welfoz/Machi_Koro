#ifndef VIEWSET_H
#define VIEWSET_H

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
#include "ViewOnePlayer.h"

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
private:
    QHBoxLayout* couche;
    QGridLayout* layoutCards;
    QVBoxLayout* layoutPlayer;
    QGridLayout* layoutPlayerMonuments;
    QVBoxLayout* layoutPlayerCards;
    QGridLayout* layoutAllPlayers;
    QVBoxLayout* layoutDice;
    QHBoxLayout* layoutPlayerMoney;

    ViewCard* cards;
    std::vector<ViewCard*> viewcards;
    ViewMonument* monuments;
    std::vector<ViewMonument*> viewmonuments;
    ViewDice* viewdice;
    ViewOnePlayer* player;
    std::vector<ViewOnePlayer*> viewPlayers;
    ViewDice* dice;
    std::vector<ViewDice*> viewDices;
private slots:
    void cardClick(ViewCard* vc);
    void monumentClick(ViewMonument* vm);
    void diceClick(ViewDice* vd);

};

#endif // VIEWSET_H
