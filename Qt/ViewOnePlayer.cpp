#include "ViewOnePlayer.h"
#include <QPainter>
#include <QString>
#include <QStaticText>
#include <QLabel>
#include <QColor>
#include <QLayout>
#include <QFont>
#include "../game/game.h"
#include "../game/game.h"
#include "../game/controller/control.h"

/*void ViewOnePlayer::paintOnePlayer(Player player)
{
    QLabel *playerName = new QLabel(this);
    playerName->setText(QString::fromStdString(player.getUsername()));

    QLabel *playerMoney = new QLabel(this);
    playerMoney->setNum(static_cast<int>(Controller::getInstance().getGame()->getBank()->getAccount(player.getId())->getSolde()));
}*/
