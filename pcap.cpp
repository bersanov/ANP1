#include "pcap.h"
#include "ui_pcap.h"
#include "QFileDialog"
#include <QFile>
#include <QDebug>
//#include PCAP_T





PCAP::PCAP(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PCAP)
{
    ui->setupUi(this);
}

PCAP::~PCAP()
{
    delete ui;
}
QString Name;
OnePacket op;
PacketStream ph;

void PCAP::on_pushButton_clicked()
{
    int max=0,min=65000,i=0,len=0;
    Name = QFileDialog::getOpenFileName(0,"Open File","","PCAP files(*.cap)");
    qDebug()<< Name;
    if ( Name == "")
        return;

    QFile file(Name);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"eror open file";
    }
    file.read((char *)&ph.ps,24);
    ui->textEdit->append("Заголовок файла: ");
    ui->textEdit->append("Magic: "+QString::number(ph.ps.magic));
    ui->textEdit->append("Version Major: "+QString::number(ph.ps.version_major));
    ui->textEdit->append("Version Minor: "+QString::number(ph.ps.version_minor));
    ui->textEdit->append("Thiszone: "+QString::number(ph.ps.thiszone));
    ui->textEdit->append("Sigfigs: "+QString::number(ph.ps.sigfigs));
    ui->textEdit->append("Snaplen: "+QString::number(ph.ps.snaplen));
    ui->textEdit->append("Linktype: "+QString::number(ph.ps.linktype));

    while(file.pos()<file.size())
    {
        i++;
        file.read((char *)&op.ph,16);
        len=len+op.ph.caplen;
        file.read((char *)&op.data,op.ph.caplen);
        ph.packets.append(op);
        qDebug() << ph.packets[0].ph.caplen;
        if (max<op.ph.caplen)
            max=op.ph.caplen;
        if (min>op.ph.caplen)
            min=op.ph.caplen;
    }
    ui->textEdit->append("Количество пакетов: "+QString::number(i));
    len=len / i ;
    ui->lineEdit->setText(QString::number(max));
    ui->lineEdit_2->setText(QString::number(min));
    ui->lineEdit_3->setText(QString::number(len));
}



void PCAP::on_pushButton_2_clicked()
{
    QString Line;
    Line = ui->lineEdit_8->text();
    int Num;
    Num = Line.toInt();
        ui->textEdit->append("Пакет № "+QString::number(Num));
    ui->textEdit->append("t1: "+QString::number(ph.packets[Num].ph.t1));
    ui->textEdit->append("t2: "+QString::number(ph.packets[Num].ph.t2));
    ui->textEdit->append("Длина пакета: "+QString::number(ph.packets[Num].ph.len));
    ui->textEdit->append("Захваченная длина пакета: "+QString::number(ph.packets[Num].ph.caplen));
    ui->textEdit->append("Данные: ");
    ui->textEdit->append("");
    for (int j=0;j<ph.packets[Num].ph.caplen;j++)
    {
        QString dec;
        dec=QString::number(ph.packets[Num].data[j]);
        int d=dec.toInt();
        QString s=QString::number(d,16).toUpper();
        ui->textEdit->insertPlainText(" " +s+ " ");
       // qDebug()<<hex<<(ph.data[j]&0xff);
    }

int p = 0;
    ui->textEdit->append("");
    ui->textEdit->insertPlainText("Destination MAC-adress:");
    for (int j = p ; j < 6 ;j++)
    {
        QString dec;
        dec=QString::number(ph.packets[Num].data[j]);
        int d=dec.toInt();
        QString s=QString::number(d,16).toUpper();

       if (d < 16)
            ui->textEdit->insertPlainText(" 0"+s);
       else
            ui->textEdit->insertPlainText(" " + s);
    }
    p=6;
    ui->textEdit->append("");
    ui->textEdit->insertPlainText("Source MAC-adress:");
    for (int j = p ; j < 12 ;j++)
    {
        QString dec;
        dec=QString::number(ph.packets[Num].data[j]);
        int d=dec.toInt();
        QString s=QString::number(d,16).toUpper();
       if (d < 16)
            ui->textEdit->insertPlainText(" 0"+s);
       else
            ui->textEdit->insertPlainText(" " + s);
    }
    p=12;
    ui->textEdit->append("");
    ui->textEdit->insertPlainText("Type:");
    for (int j = p ; j < 14 ;j++)
    {
        QString dec;
        dec=QString::number(ph.packets[Num].data[j]);
        int d=dec.toInt();
        QString s=QString::number(d,16).toUpper();
       if (d < 16)
            ui->textEdit->insertPlainText(" 0"+s);
       else
            ui->textEdit->insertPlainText(" " + s);
    }
    p=14;
    QString dec=QString::number(ph.packets[Num].data[p]);
    int d=dec.toInt();
    QString s=QString::number(d,16).toUpper();

    ui->textEdit->append("");

    ui->textEdit->insertPlainText("Length:"+s[1]);
    int k=s.toInt();
    k=k%10;
    k=k*4;
    k=k-20;
    p=23;
    dec=QString::number(ph.packets[Num].data[p]);
    d=dec.toInt();
    s=QString::number(d,16).toUpper();
    ui->textEdit->append("");
    if (d < 16)
         ui->textEdit->insertPlainText("Protocol: 0"+ s);
    else
         ui->textEdit->insertPlainText("Protocol: " + s);

    p=26;
    ui->textEdit->append("");
    ui->textEdit->insertPlainText("Source:");
    for (int j=p;j<p+4;j++)
    {
        ui->textEdit->insertPlainText(QString::number(ph.packets[Num].data[j])+".");
    }

    p=30;
    ui->textEdit->append("");
    ui->textEdit->insertPlainText("Destination:");
    for (int j=p;j<p+4;j++)
    {
        ui->textEdit->insertPlainText(QString::number(ph.packets[Num].data[j])+".");
    }
    p=34+k;
    ui->textEdit->append("");
    s=QString::number(ph.packets[Num].data[p]);
    d=s.toInt();
    s=QString::number(d,16).toUpper();
    QString z=QString::number(ph.packets[Num].data[p+1]);
    d=z.toInt();
    z=QString::number(d,16).toUpper();
    s=s+z;
    ui->textEdit->insertPlainText("Source Port:"+s);
    ui->textEdit->append("");
    p=36+k;
    s=QString::number(ph.packets[Num].data[p]);
    d=s.toInt();
    s=QString::number(d,16).toUpper();
    z=QString::number(ph.packets[Num].data[p+1]);
    d=z.toInt();
    z=QString::number(d,16).toUpper();
    s=s+z;
    ui->textEdit->insertPlainText("Destination Port:"+s);
}


//int main(int argc, char *argv[])
//{
//    PCAP_T handle;
//    char *dev;
//    char errbuf[PCAP_ERRBUF_SIZE];
//    dev = pcap_lookupdev(errbuf);
//    if (dev == NULL)
//    {
//        fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
//               return(2);
//           }
//           printf("Device: %s\n", dev);
//           return(0);

//           handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
//           if (handle == NULL) {
//               fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
//               return(2);
//           }


//       }




