/********************************************************************************
** Form generated from reading UI file 'registrar.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRAR_H
#define UI_REGISTRAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Registrar
{
public:
    QGridLayout *gridLayout;
    QLineEdit *nameEdit;
    QLineEdit *surnameEdit;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QLineEdit *mailEdit;
    QPushButton *cancelButton;
    QPushButton *signupButton;

    void setupUi(QWidget *Registrar)
    {
        if (Registrar->objectName().isEmpty())
            Registrar->setObjectName("Registrar");
        Registrar->resize(300, 400);
        gridLayout = new QGridLayout(Registrar);
        gridLayout->setObjectName("gridLayout");
        nameEdit = new QLineEdit(Registrar);
        nameEdit->setObjectName("nameEdit");

        gridLayout->addWidget(nameEdit, 0, 0, 1, 2);

        surnameEdit = new QLineEdit(Registrar);
        surnameEdit->setObjectName("surnameEdit");

        gridLayout->addWidget(surnameEdit, 1, 0, 1, 2);

        usernameEdit = new QLineEdit(Registrar);
        usernameEdit->setObjectName("usernameEdit");

        gridLayout->addWidget(usernameEdit, 2, 0, 1, 2);

        passwordEdit = new QLineEdit(Registrar);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setEchoMode(QLineEdit::EchoMode::Password);

        gridLayout->addWidget(passwordEdit, 3, 0, 1, 2);

        mailEdit = new QLineEdit(Registrar);
        mailEdit->setObjectName("mailEdit");

        gridLayout->addWidget(mailEdit, 4, 0, 1, 2);

        cancelButton = new QPushButton(Registrar);
        cancelButton->setObjectName("cancelButton");

        gridLayout->addWidget(cancelButton, 5, 0, 1, 1);

        signupButton = new QPushButton(Registrar);
        signupButton->setObjectName("signupButton");

        gridLayout->addWidget(signupButton, 5, 1, 1, 1);


        retranslateUi(Registrar);

        QMetaObject::connectSlotsByName(Registrar);
    } // setupUi

    void retranslateUi(QWidget *Registrar)
    {
        Registrar->setWindowTitle(QCoreApplication::translate("Registrar", "Form", nullptr));
        nameEdit->setPlaceholderText(QCoreApplication::translate("Registrar", "Nombre", nullptr));
        surnameEdit->setPlaceholderText(QCoreApplication::translate("Registrar", "Apellido", nullptr));
        usernameEdit->setPlaceholderText(QCoreApplication::translate("Registrar", "Nombre de usuario", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("Registrar", "Contrasena", nullptr));
        mailEdit->setPlaceholderText(QCoreApplication::translate("Registrar", "Correo Electronico", nullptr));
        cancelButton->setText(QCoreApplication::translate("Registrar", "Cancelar", nullptr));
        signupButton->setText(QCoreApplication::translate("Registrar", "Registrarse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Registrar: public Ui_Registrar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRAR_H
