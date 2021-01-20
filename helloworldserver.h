#ifndef HELLOWORLDSERVER_H
#define HELLOWORLDSERVER_H


#include<QTcpServer>

#include"server.h"
class Server;

class Helloworldserver : public QTcpServer
{
public:
    Q_OBJECT

public:


    Helloworldserver(Server* pHelloServer,QObject *parent=0);
    Server* m_pHelloWindow;


           private slots:
               void readyRead();
               void disconnect();

           protected:
               void incomingConnection(int socketfd);

           private:
               QSet<QTcpSocket*> clients;

};

#endif // HELLOWORLDSERVER_H
