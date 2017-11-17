#ifndef PCAP_H
#define PCAP_H
#define PCAP_T
#include <QList>
#include <QMainWindow>

namespace Ui
{
class PCAP;
}
class PCAP : public QMainWindow
{
    Q_OBJECT

public:
    explicit PCAP(QWidget *parent = 0);
    ~PCAP();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::PCAP *ui;
};

struct PcapFHeader
{
    qint32 magic;
    qint16 version_major;
    qint16 version_minor;
    qint32 thiszone;     /* gmt to local correction */
    qint32 sigfigs;    /* accuracy of timestamps */
    qint32 snaplen;    /* max length saved portion of each pkt */
    qint32 linktype;   /* data link type (LINKTYPE_*) */
};

struct PcapHeader
{
    qint32 t1;
    qint32 t2;
    qint32 caplen;
    qint32 len;
};


class OnePacket
{
public:
    PcapHeader ph;
    unsigned char data[4000];
};



class PacketStream
{
public:
    PcapFHeader ps;
    QList <OnePacket> packets;
};










#endif // PCAP_H
