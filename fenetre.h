#ifndef FENETRE_H
#define FENETRE_H

#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QDebug>

namespace Ui {
class fenetre;
}

class fenetre : public QMainWindow
{
    Q_OBJECT

public:
    explicit fenetre(QWidget *parent = nullptr);
    ~fenetre();
    void createStrings();

public Q_SLOTS:
    void pixelPress();

private slots:
    void on_clear_clicked();
    void on_invert_clicked();

    void on_radioHex_clicked();

    void on_radioBin_clicked();

private:
    Ui::fenetre *ui;
    int x,y;
};

#endif // FENETRE_H
