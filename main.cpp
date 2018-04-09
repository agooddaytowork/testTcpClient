#include <QCoreApplication>
#include "fountainclient.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    fountainClient aClient;

    aClient.connect("192.168.1.37", 8080);
    return a.exec();
}
