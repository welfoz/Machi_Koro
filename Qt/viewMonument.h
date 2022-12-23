#ifndef VIEWMONUMENT_H
#define VIEWMONUMENT_H

#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPushButton>
#include "../game/game.h"
#include "../game/controller/control.h"

class ViewMonument : public QPushButton
{
    Q_OBJECT
public:
    ViewMonument(const Monument* monument, QWidget *parent = nullptr);
    explicit ViewMonument(QWidget *parent = nullptr);
    void setMonument(Monument* monument);
    const Monument* getMonument() const {return monument;}
private:
    const Monument* monument = nullptr;
signals:
    void monumentClicked(ViewMonument*);
private slots:
    void clickedEvent() {emit monumentClicked(this);}
};



#endif // VIEWMONUMENT_H
