#pragma once
#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "../game/controller/control.h"

class ViewCard : public QPushButton
{
    Q_OBJECT
public:
    ViewCard(EstablishmentCard* card, QWidget *parent = nullptr);
//    explicit ViewCard(QWidget *parent = nullptr);
    void setCardOnlyName();
    void setCard();
    const EstablishmentCard* getCard() const {return card;}
protected:
private:
    EstablishmentCard* card = nullptr;
    void clearLayout(QLayout* layout);
    QVBoxLayout* layoutCard;
signals:
    void cardClicked(ViewCard*);
private slots:
    void clickedEvent() {emit cardClicked(this);}
};
