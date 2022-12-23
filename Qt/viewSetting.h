#ifndef VIEWSETTINGS_H
#define VIEWSETTINGS_H

#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPushButton>
#include <QLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include "../game/game.h"
#include "../game/controller/control.h"

class ViewSetting : public QWidget
{
    Q_OBJECT
public:
    ViewSetting(QWidget *parent = nullptr);
    void viewInputText();
    QString getPlayerName() {return playerName;}
private:
    QPushButton* validateButton;
    QPushButton* cancelButton;
    QHBoxLayout* layoutButtons;
    QLineEdit* editPlayer;
    QLabel* labelPlayer;
    QGridLayout* layer;

    QString playerName;
public slots:
    void clickValidate();
};


#endif // VIEWSETTINGS_H
