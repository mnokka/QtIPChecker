#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets>
#include <QDebug>
#include <QHostAddress>
#include <QNetworkInterface>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    qDebug() << "SW Started";

    // from stackoverflow
    const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
    //qDebug() << localhost.toString();
    QString IPAddress;
    for (const QHostAddress &address: QNetworkInterface::allAddresses()) {
          if (address.protocol() == QAbstractSocket::IPv4Protocol && address != localhost) {
             IPAddress = address.toString();
             qDebug() << "Found local IP address:" << IPAddress;
          }

    }

    QString title;
    QTextStream(&title) << "IP ADDRESS: " << IPAddress;
    w.setWindowTitle(title);
    w.resize(350,30);
    w.show();
    return a.exec();
}
