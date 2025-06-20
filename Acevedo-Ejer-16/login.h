#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QSettings>
#include "admindb.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Login;
}
QT_END_NAMESPACE

class Login : public QWidget {
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void slot_validarUsuario();

private:
    Ui::Login *ui;
    AdminDB *admindb;
};

#endif // LOGIN_H
