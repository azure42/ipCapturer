#ifndef DEVSELECT_H
#define DEVSELECT_H

#include <QDialog>

namespace Ui {
class devselect;
}

class DevSelect : public QDialog
{
    Q_OBJECT

public:
    explicit DevSelect(QWidget *parent = 0);
//    explicit DevSelect(QString devName);
    ~DevSelect();

private slots:

    void on_ipButton_clicked();

    void on_ARPButton_clicked();

    void on_icmpButton_clicked();

    void on_tcpBox_clicked();

    void on_udpBox_clicked();

//    void on_buttonBox_rejected();

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::devselect *ui;
    bool ipFlag,arpFlag,icmpFlag,tcpFlag,udpFlag;

};

#endif // DEVSELECT_H
