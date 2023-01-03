#include "chatwindow.h"
#include "ui_chatwindow.h"
#include <QStandardItemModel>
#include <QInputDialog>
#include <QMessageBox>

ChatWindow::ChatWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChatWindow) // create the elements defined in the .ui file
    , m_chatModel(new QStandardItemModel(this)) // create the model to hold the messages
{
    ui->setupUi(this);
    m_chatModel->insertColumn(0);
    ui->chatView->setModel(m_chatModel);
}

ChatWindow::~ChatWindow()
{
    delete ui;
}

void ChatWindow::messageReceived(const QString &text)
{
    int newRow = m_chatModel->rowCount();
    m_chatModel->insertRow(newRow);
    m_chatModel->setData(m_chatModel->index(newRow, 0), text);
    m_chatModel->setData(m_chatModel->index(newRow, 0), int(Qt::AlignLeft | Qt::AlignVCenter), Qt::TextAlignmentRole);
    ui->chatView->scrollToBottom();
}
