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
#include <QDialog>
#include <QSpinBox>
#include "../game/game.h"
#include "../game/controller/control.h"

class ViewSetting : public QDialog
{
    Q_OBJECT
public:
    ViewSetting(QWidget *parent = nullptr);
    void viewInputText();
    void viewInputNumber();
    void viewConfirmationDialog(QString message, QString firstOption, QString secondOption);

    QString getText() {return text;}
    int getNumber() {return number;}
    QString getMessage() {return message;}
private:
    QPushButton* validateButtonText;
    QHBoxLayout* layoutButtons;
    QLineEdit* editText;
    QLabel* labelText;
    QGridLayout* layer;

    QPushButton* validateButtonNumber;
    QSpinBox* spinBoxNumber;
    QLabel* labelNumber;

    QPushButton* validateFirstOption;
    QPushButton* validateSecondOption;

    QString text;
    int number;
    QString message;
public slots:
    void clickValidateText();
    void clickValidateNumber();
    void clickFirstOption();
    void clickSecondOption();
};


#endif // VIEWSETTINGS_H
