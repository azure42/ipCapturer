#include "proselect.h"
#include "ui_proselect.h"
//从devSelect跳过来，由界面中的checkbox构造过滤器字符串（格式见P269），然后传给pcapThread
proSelect::proSelect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::proSelect)
{
    ui->setupUi(this);
    ipFlag=arpFlag=icmpFlag=tcpFlag=udpFlag = false;

}

proSelect::~proSelect()
{
    delete ui;
}

void proSelect::on_ipButton_clicked()
{
    if(ui->ipButton->checkState() == 0)
        ipFlag = false;
    else
        ipFlag = true;
}

void proSelect::on_ARPButton_clicked()
{
    if(ui->ARPButton->checkState() == 0)
        arpFlag = false;
    else
        arpFlag = true;
}

void proSelect::on_icmpButton_clicked()
{
    if(ui->icmpButton->checkState() == 0)
        icmpFlag = false;
    else
        icmpFlag = true;
}

void proSelect::on_tcpBox_clicked()
{
    if(ui->tcpBox->checkState() == 0)
        tcpFlag = false;
    else
        tcpFlag = true;
}

void proSelect::on_udpBox_clicked()
{
    if(ui->udpBox->checkState() == 0)
        udpFlag = false;
    else
        udpFlag = true;
}

void proSelect::on_buttonBox_rejected()
{
    exit(0);
}

void proSelect::on_buttonBox_accepted()
{
    QString boolExp;
    if(ipFlag || arpFlag || icmpFlag) {
        QString tmp;
        tmp += "(";
        if(ipFlag)
            tmp += "ip ";
        if(arpFlag)
            tmp += "or arp ";
        if(icmpFlag)
            tmp += "or icmp";
        tmp += ")";
        boolExp += tmp;
    }
    if(!ui->sipLineEdit->text().isEmpty() && !ui->dipLineEdit->text().isEmpty()) {
        QString tmp;
        tmp += "and (src host ";
        tmp += ui->sipLineEdit->text();
        tmp += " and dst host ";
        tmp += ui->dipLineEdit->text();
        tmp += ") ";
        boolExp += tmp;
    }
    if(!ui->portEdit->text().isEmpty()) {
        QString tmp;
        tmp += "and (port ";
        tmp += ui->portEdit->text();
        tmp += ") ";
        boolExp += tmp;
    }
    if(!ui->smacLineEdit->text().isEmpty() && !ui->dmacLineEdit->text().isEmpty()) {
        QString tmp;
        tmp += "and (ether src ";
        tmp += ui->smacLineEdit->text();
        tmp += " and ether dst ";
        tmp += ui->dmacLineEdit->text();
        tmp += ") ";
        boolExp += tmp;
    }
    qDebug() << boolExp;

}
