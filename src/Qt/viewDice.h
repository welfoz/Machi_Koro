#pragma once
#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPushButton>
#include <QVBoxLayout>
#include "../game/game.h"

class ViewDice : public QPushButton
{
    Q_OBJECT
public:
    ViewDice(const size_t dice, QWidget *parent = nullptr);
    //explicit ViewDice(QWidget *parent = nullptr);
    void setDice();
    const size_t getDice() const {return dice;}
private:
    const size_t dice=0;
    void clearLayout(QLayout* layout);
    QVBoxLayout* layoutDice;
signals:
    void diceClicked(ViewDice*);
private slots:
    void clickedEvent() {emit diceClicked(this);}
};
