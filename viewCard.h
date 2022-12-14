#ifndef VIEWCARD_H
#define VIEWCARD_H

#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPushButton>

class ViewCard : public QPushButton
{
    Q_OBJECT
public:
    explicit ViewCard(QWidget *parent = nullptr);
    void setPrice(int p){price=p;}
    void setDice(int d){dice=d;}
    void paintCard();
    void paintCardOnlyName();
protected:
private:
    int dice=1;
    QPen pen;
    QBrush brush;
    std::string name="WheatField";
    std::string icon="wheat";
    std::string color="blue";
    int price=1;
    int activationNumber=1;
    int cardRemaining = 6;
    std::string effect="You get one coin from the bank, on anyone's turn";
};

class CardExample
{
private :
    std::string name="WheatField";
    std::string icon="wheat";
    std::string color="blue";
    int price=1;
    int activationNumber=1;
    std::string effect="You get 1 coin from the bank, on anyone's turn.";
public:
    std::string getName() const {return name;}
    std::string getIcon() const {return icon;}
    std::string getColor() const {return color;}
    int getPrice()const{return price;}
    int getActivationNumber()const{return activationNumber;}
    std::string getEffect() const {return effect;}
};

#endif // VIEWCARD_H
