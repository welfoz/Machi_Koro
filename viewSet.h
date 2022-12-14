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
#include "viewCard.h"
#include "viewMonument.h"
#include "viewDice.h"

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
    void printCarte();
private:
    QHBoxLayout* couche;
    QGridLayout* layoutCards;
    QVBoxLayout* layoutPlayer;
    QGridLayout* layoutPlayerMonuments;
    QVBoxLayout* layoutPlayerCards;
    QHBoxLayout* layoutAllPlayers;
    QVBoxLayout* layoutDice;

    ViewCard* cards;
    std::vector<ViewCard*> viewcards;
    ViewMonument* monuments;
    std::vector<ViewMonument*> viewmonuments;
    ViewDice* viewdice;

};

#endif // VIEWSET_H
