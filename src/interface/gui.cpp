#include <QInputDialog>
#include <QComboBox>
#include "gui.h"
#include "../game/game.h"
#include "../game/controller/control.h"
#include "../Qt/viewMessage.h"
#include "../Qt/viewSetting.h"
#include "../Qt/viewSet.h"
#include <QTimer>

void Gui::init() {
    this->board = new ViewSet;
    this->board->show();
}

void Gui::printWelcomingMessage()const {
    ViewMessage* viewMessage = new ViewMessage();
    viewMessage->viewWelcomingMessage();
}

void Gui::printBasicMessage(string message)const {
    if (board != nullptr) {
        board->sendMessageToChat(message);
    } else {
        ViewMessage* viewMessage = new ViewMessage();
        viewMessage->viewBasicMessage(QString::fromStdString(message));
    }
}

string Gui::getInputText(vector<string> context) const {
    ViewSetting* viewSetting = new ViewSetting;
    viewSetting->viewInputText();
    viewSetting->exec();
    return (viewSetting->getText()).toStdString();
}

size_t Gui::getInputNumber(size_t min,size_t max) const {
    ViewSetting* viewSetting = new ViewSetting;
    viewSetting->viewInputNumber();
    viewSetting->exec();
    return static_cast<size_t>(viewSetting->getNumber());
}

bool Gui::confirmationDialog(string message, string firstOption, string secondOption)const {
    ViewSetting* viewSetting = new ViewSetting;
    viewSetting->viewConfirmationDialog(QString::fromStdString(message), QString::fromStdString(firstOption), QString::fromStdString(secondOption));
    viewSetting->exec();
    if((viewSetting->getMessage()).toStdString() == secondOption)
        return false;
    return true;
}

void Gui::printTurnCounter(size_t turnCounter) const{
    board->sendMessageToChat("Turn count : " + std::to_string(turnCounter));
    // ancien code
    //    ViewMessage* viewMessage = new ViewMessage;
    //    QString message = "Turn count : " + QString::number(static_cast<int>(turnCounter));
    //    viewMessage->viewBasicMessage(message);
}

void Gui::printError(const exception &message) const {
    ViewMessage* viewMessage = new ViewMessage;
    // TO DO: handle the error message
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
    QString choice = dialog->getItem(0, "Welcome to Machi Koro", "Choose an edition:", list, 0, false, &accepted);

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

void Gui::update() const {
    if (board != nullptr) {
        this->board->setSet();
    }
}

void Controller::updateGui() const {
    if (dynamic_cast<Gui*>(Controller::getInstance().getInterface(true)) != nullptr)
        dynamic_cast<Gui*>(Controller::getInstance().getInterface(true))->update();
};

void Gui::delay() const {
    QEventLoop loop;
    QTimer t;
    t.connect(&t, &QTimer::timeout, &loop, &QEventLoop::quit);
    t.start(100);
    loop.exec();
}
