#include "client.h"
#include "ui_client.h"

#include <QMessageBox>

Client::Client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Client)
{
   m_pClientSocket=new QTcpSocket(this);
    ui->setupUi(this);
}

Client::~Client()
{
    delete ui;
}

void Client::on_pushButtonConnect_clicked()
{
    m_pClientSocket->connectToHost(ui->textEditIPAddress->toPlainText(),quint16(ui->textEditPort->toPlainText().toInt()) );
        connect(m_pClientSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));

}

void Client::on_pushButtonSend_clicked()
{
    QString message = ui->textEditMessage->toPlainText().trimmed();

    // Only send the text to the chat server if it's not empty:
    if(!message.isEmpty())
    {
        m_pClientSocket->write(QString(message + "\n").toUtf8());
    }

    // Clear out the input box so they can type something else:
    ui->textEditMessage->clear();

    // Put the focus back into the input box so they can type again:
     ui->textEditMessage->setFocus();
}



void Client::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError)
    {
           case QAbstractSocket::RemoteHostClosedError:
               break;
           case QAbstractSocket::HostNotFoundError:
               QMessageBox::information(this, tr("Fortune Client"),
                                        tr("The host was not found. Please check the "
                                           "host name and port settings."));
               break;
           case QAbstractSocket::ConnectionRefusedError:
               QMessageBox::information(this, tr("Fortune Client"),
                                        tr("The connection was refused by the peer. "
                                           "Make sure the fortune server is running, "
                                           "and check that the host name and port "
                                           "settings are correct."));
               break;
           default:
               QMessageBox::information(this, tr("Fortune Client"),
                                        tr("The following error occurred: %1.")
                                        .arg(m_pClientSocket->errorString()));
           }

}
