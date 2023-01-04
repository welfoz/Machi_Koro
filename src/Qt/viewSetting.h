#pragma once
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
#include <QCloseEvent>

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
    void closeEvent(QCloseEvent *event) override;
public slots:
    void clickValidateText();
    void clickValidateNumber();
    void clickFirstOption();
    void clickSecondOption();
};
