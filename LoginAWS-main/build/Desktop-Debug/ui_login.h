/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QGridLayout *gridLayout;
    QPushButton *loginButton;
    QLineEdit *passwordEdit;
    QLineEdit *usernameEdit;
    QPushButton *signupButton;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(250, 200);
        gridLayout = new QGridLayout(Login);
        gridLayout->setObjectName("gridLayout");
        loginButton = new QPushButton(Login);
        loginButton->setObjectName("loginButton");

        gridLayout->addWidget(loginButton, 2, 1, 1, 1);

        passwordEdit = new QLineEdit(Login);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setEchoMode(QLineEdit::EchoMode::Password);

        gridLayout->addWidget(passwordEdit, 1, 0, 1, 2);

        usernameEdit = new QLineEdit(Login);
        usernameEdit->setObjectName("usernameEdit");

        gridLayout->addWidget(usernameEdit, 0, 0, 1, 2);

        signupButton = new QPushButton(Login);
        signupButton->setObjectName("signupButton");

        gridLayout->addWidget(signupButton, 2, 0, 1, 1);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Login", nullptr));
        loginButton->setText(QCoreApplication::translate("Login", "Iniciar Sesion", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("Login", "Contrasena", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("Login", "Usuario", nullptr));
        signupButton->setText(QCoreApplication::translate("Login", "Registrarse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
