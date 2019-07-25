#ifndef FENETRE_H
#define FENETRE_H

#include <QMainWindow>

namespace Ui {
class fenetre;
}

class fenetre : public QMainWindow
{
    Q_OBJECT

public:
    explicit fenetre(QWidget *parent = nullptr);
    ~fenetre();

private:
    Ui::fenetre *ui;
};

#endif // FENETRE_H
