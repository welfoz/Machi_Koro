#ifndef VIEWDICE_H
#define VIEWDICE_H

#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPushButton>

class ViewDice : public QPushButton
{
    Q_OBJECT
public:
    explicit ViewDice(QWidget *parent = nullptr);
    void paintDice();
};

#endif // VIEWDICE_H
