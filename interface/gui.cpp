#include <QInputDialog>
#include <QComboBox>
#include "gui.h"
#include "../game/game.h"
#include "../game/controller/control.h"
#include "../Qt/viewMessage.h"
#include "../Qt/viewSetting.h"
#include "../Qt/viewSet.h"

void Gui::init() const {
    ViewSet* viewSet = new ViewSet;
    viewSet->setSet();
    viewSet->show();
}

void Gui::printWelcomingMessage(){
    ViewMessage* viewMessage = new ViewMessage;
    viewMessage->viewWelcomingMessage();
}

void Gui::printBasicMessage(string message){
    ViewMessage* viewMessage = new ViewMessage;
    viewMessage->viewBasicMessage(QString::fromStdString(message));
}

string Gui::getInputText() const {
    ViewSetting* viewSetting = new ViewSetting;
    viewSetting->viewInputText();
    viewSetting->exec();
    return (viewSetting->getText()).toStdString();
}

size_t Gui::getInputNumber() {
    ViewSetting* viewSetting = new ViewSetting;
    viewSetting->viewInputNumber();
    viewSetting->exec();
    return static_cast<size_t>(viewSetting->getNumber());
}

bool Gui::confirmationDialog(string message, string firstOption, string secondOption){
    ViewSetting* viewSetting = new ViewSetting;
    viewSetting->viewConfirmationDialog(QString::fromStdString(message), QString::fromStdString(firstOption), QString::fromStdString(secondOption));
    viewSetting->exec();
    if((viewSetting->getMessage()).toStdString() == secondOption)
        return false;
    return true;
}

void Gui::printBoard() const {
    ViewSet* viewSet = new ViewSet;
    viewSet->setSet();
    viewSet->show();
}

void Gui::printBalances(Player** players) const {
    ViewSet* viewSet = new ViewSet;
    viewSet->setSet();
    viewSet->show();
}

void Gui::printTurnCounter(size_t turnCounter) {
    ViewMessage* viewMessage = new ViewMessage;
    QString message = "Turn count : " + QString::number(static_cast<int>(turnCounter));
    viewMessage->viewBasicMessage(message);
}

void Gui::printError(const exception &message) const {
    ViewMessage* viewMessage = new ViewMessage;
    viewMessage->viewBasicMessage(message.what());
}

// WRONG IMPLEMENTATION
// JUST NEED TO RETURN SOMETHING TO COMPILE
EstablishmentCard* Gui::selectOneCardOwnedByAnyPlayer(string message) const {
    return Controller::getInstance().getGame()->getCardByName(message);
}

Interface::Extension Gui::chooseExtension() const {
    QStringList list = {
        "Base",
        "Marina",
        "Green Valley",
        "Deluxe"
    };

    QInputDialog *dialog = new QInputDialog();
    bool accepted;
    QString choice = dialog->getItem(0, "Choose The Extension", "Extensions:", list, 0, false, &accepted);

    if (accepted && !choice.isEmpty()) {
        if (choice == "Base") {
            return Extension::Base;
        } else if (choice == "Marina"){
            return Extension::Marina;
        } else if (choice == "Green Valley") {
            return Extension::GreenValley;
        } else if (choice == "Deluxe") {
            return Extension::Deluxe;
        }
    }
    throw "error";
}
