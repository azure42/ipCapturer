#include "devselect.h"
#include "ui_devselect.h"
#include <stdlib.h>
#include <time.h>
#include <pcap.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <QDebug>
#include "dialog.h"
//extern QString devName;
DevSelect::DevSelect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::devselect)
{
    ui->setupUi(this);

    pcap_if_t *alldevs;
    pcap_if_t *d;
    int i=0;
    char errbuf[PCAP_ERRBUF_SIZE];
    /* 获取当前计算机的所有网络设备 */
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        qDebug()<<"1!";

        ui->devList->insertItem(0,"");
        qDebug()<<"未找到设备，请确认此程序在root权限下运行!";
    }
    /* 打印列表 */
    for(d=alldevs; d; d=d->next) {
        qDebug()<<QString(d->name);
        ui->devList->insertItem(i++,d->name);
    }
    pcap_freealldevs(alldevs);


}

DevSelect::~DevSelect()
{
    delete ui;
}

void DevSelect::on_closeButton_clicked()
{
    close();
}

void DevSelect::on_okButton_clicked()
{
    qDebug()<<"0";
    Dialog mainWin(0,ui->devList->currentItem()->text());
    qDebug()<<"1";
    mainWin.exec();
    qDebug()<<"2";
    close();
}