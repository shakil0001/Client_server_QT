#ifndef SERVER_H
#define SERVER_H
#include <QMainWindow>
#include"helloworldserver.h"
namespace Ui{
class Server;
}
class Helloworldserver;
class Server : public QMainWindow
{
    Q_OBJECT

public:
    explicit Server(QWidget *parent = nullptr);
    ~Server();
    void addmessage(QString Msg);
    Helloworldserver * m_pBoxServer;

private slots:
    void on_pushButtonStart_clicked();

private:
    Ui::Server*ui;
};

#endif // SERVER_H
