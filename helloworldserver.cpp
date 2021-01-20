#include"server.h"
#include<QTcpSocket>
#include"helloworldserver.h"
Helloworldserver::Helloworldserver(Server *pHelloserver, QObject *parent) : QTcpServer(parent)

{
    m_pHelloWindow=pHelloserver;
}
void Helloworldserver::incomingConnection(int socketfd)
{

    QTcpSocket *client = new QTcpSocket(this);
    client->setSocketDescriptor(socketfd);
    clients.insert(client);

    m_pHelloWindow->addmessage("New client from: "+client->peerAddress().toString());

    connect(client, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(client, SIGNAL(disconnected()), this, SLOT(disconnected()));
}
void Helloworldserver::readyRead()
{
    QTcpSocket *client = (QTcpSocket*)sender();
       while(client->canReadLine())
       {
           QString line = QString::fromUtf8(client->readLine()).trimmed();
           //qDebug() << "Read line:" << line;
           m_pHelloWindow->addmessage(line);

       }
}
void Helloworldserver::disconnect()
{
    QTcpSocket *client = (QTcpSocket*)sender();
       qDebug() << "Client disconnected:" << client->peerAddress().toString();

       clients.remove(client);


}



