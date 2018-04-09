#ifndef FOUNTAINCLIENT_H
#define FOUNTAINCLIENT_H

#include <QTcpSocket>
#include <QDataStream>
#include <QIODevice>
#include <QtNetwork>

class fountainClient: public QObject
{

    Q_OBJECT

    QString m_ip;
    quint16 m_port;
    QDataStream in;

    QTcpSocket *tcpSocket = nullptr;

    bool m_Connected;
public:
    fountainClient(QObject *parent = nullptr);


    Q_INVOKABLE void connect(const QString &ip, const quint16 &port);
    Q_INVOKABLE void connect();
    Q_INVOKABLE void sendProgram(const QByteArray &program);
    Q_INVOKABLE void setHostName(const QString &hostName);
    Q_INVOKABLE void setPort(const quint16 &port);
    Q_INVOKABLE bool isConnectedToServer();

private slots:
    void readyReadHandler();

};

#endif // FOUNTAINCLIENT_H
