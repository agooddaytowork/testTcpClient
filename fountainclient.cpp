#include "fountainclient.h"



fountainClient::fountainClient(QObject *parent): QObject(parent), tcpSocket(new QTcpSocket(this)), m_Connected(false)
{

    in.setDevice(tcpSocket);
    in.setVersion(QDataStream::Qt_5_8);


    QObject::connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readyReadHandler()));
    QObject::connect(tcpSocket,&QTcpSocket::connected,[=](){

        m_Connected = true
        qDebug() << "connected";
        sendProgram("asdjklaskdljskla");
    });


}

void fountainClient::connect(const QString &ip, const quint16 &port)
{

    tcpSocket->connectToHost(ip, port);
}

void fountainClient::connect()
{
    tcpSocket->connectToHost(m_ip, m_port);
}

void fountainClient::readyReadHandler()
{

}

void fountainClient::sendProgram(const QByteArray &program)
{
   QByteArray block;

    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_8);

    out << program;

    tcpSocket->write(block);


}

void fountainClient::setHostName(const QString &hostName)
{
    m_ip = hostName;
}

void fountainClient::setPort(const quint16 &port)
{

    m_port = port;
}

bool fountainClient::isConnectedToServer()
{
    return m_Connected;
}
