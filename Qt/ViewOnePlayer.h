#pragma once
#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include "../game/game.h"

class ViewOnePlayer : public QVBoxLayout
{
    Q_OBJECT
public:
    explicit ViewOnePlayer(QWidget *parent = nullptr) : QVBoxLayout(parent){}
    void setOnePlayer(Player player);
};