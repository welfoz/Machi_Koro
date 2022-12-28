#pragma once
#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPushButton>
#include "../game/controller/control.h"

class ViewCard : public QPushButton
{
    Q_OBJECT
public:
    ViewCard(const EstablishmentCard* card, QWidget *parent = nullptr);
    explicit ViewCard(QWidget *parent = nullptr);
    void setCardOnlyName(EstablishmentCard* card);
    void setCard(EstablishmentCard* card);
    const EstablishmentCard* getCard() const {return card;}
protected:
private:
    const EstablishmentCard* card = nullptr;
signals:
    void cardClicked(ViewCard*);
private slots:
    void clickedEvent() {emit cardClicked(this);}
};
