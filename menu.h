#ifndef MENU_H
#define MENU_H

#include <QMainWindow>

class Menu: public QMainWindow
{
    Q_OBJECT
public:
    Menu(QWidget *parent = nullptr);
    ~Menu() override;         //Override non necessaire

private slots:
    void positionSelected(const QString &position);
};

#endif // MENU_H
