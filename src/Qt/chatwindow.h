#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QWidget>

class QStandardItemModel;

namespace Ui { class ChatWindow; }

class ChatWindow : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(ChatWindow)
public:
    explicit ChatWindow(QWidget *parent = nullptr);
    ~ChatWindow();
    void messageReceived(const QString &text);
private:
    Ui::ChatWindow *ui;
    QStandardItemModel *m_chatModel;
};

#endif // CHATWINDOW_H
