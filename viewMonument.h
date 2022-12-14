#ifndef VIEWMONUMENT_H
#define VIEWMONUMENT_H

#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPushButton>

class ViewMonument : public QPushButton
{
    Q_OBJECT
public:
    explicit ViewMonument(QWidget *parent = nullptr);
    void paintMonument();
private:
    std::string name="Train Station";
    int price=4;
    std::string effect="You may roll 1 or 2 dice.";
    int nbMonument=1;
};



#endif // VIEWMONUMENT_H
