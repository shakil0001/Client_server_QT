#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QTcpSocket>
namespace Ui {
class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT
public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();
   QTcpSocket  *m_pClientSocket;
private slots:
 void on_pushButtonConnect_clicked();

 void on_pushButtonSend_clicked();
private slots:
 void displayError(QAbstractSocket::SocketError SocketError);


private:
    Ui::Client *ui;
};

#endif // CLIENT_H
