#include "fenetre.h"
#include "ui_fenetre.h"

int correspond[5] = {0x10,0x08,0x04,0x02,0x01};
int dataHex[7] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00};
int dataBin[7][5] = {
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0}
};

fenetre::fenetre(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fenetre)
{
    ui->setupUi(this);
    x = 0;
    y = 0;

    createStrings();
}

fenetre::~fenetre()
{
    delete ui;
}

void fenetre::pixelPress()
{
    //update data when button pressed
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    QString text = buttonSender->objectName();
    x = QString(text[1]).toInt()-1;
    y = QString(text[3]).toInt()-1;

    //qDebug()<<x<<y;

    dataBin[x][y] = int(buttonSender->isChecked());
    dataHex[x] += buttonSender->isChecked() ? correspond[y] : -correspond[y];

    createStrings();
}
void fenetre::createStrings()
{
    //create a string with data
    QString result = "byte customChar[] = {";
    if (ui->radioBin->isChecked())
    {
        result += "\n";
        for (int x = 0; x < 7; ++x) {
            result += "\tB";
            for (int y = 0; y < 5; ++y) {
                result += QString::number(dataBin[x][y]);

            }
            if (x != 6)
                result += ",\n";
        }
        result += "\n";
    }
    else{
        for (int x = 0; x < 5; ++x) {
            result += "0x"+QString::number(dataHex[x],16).toUpper();
            if (x != 4)
                result += ", ";
        }
    }
    result += "}";

    ui->result->setPlainText(result);
}
void fenetre::on_clear_clicked()
{
    qDebug()<<"clear";
}

void fenetre::on_invert_clicked()
{
    qDebug()<<"invert";

}

void fenetre::on_radioHex_clicked()
{
    createStrings();
}

void fenetre::on_radioBin_clicked()
{
    createStrings();
}

void fenetre::on_result_textChanged()
{
    ui->result->undo();
}
