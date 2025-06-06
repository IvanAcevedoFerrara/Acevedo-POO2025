/********************************************************************************
** Form generated from reading UI file 'grabaraudio.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRABARAUDIO_H
#define UI_GRABARAUDIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GrabarAudio
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *btnIniciar;
    QPushButton *btnPausar;
    QPushButton *btnDetener;
    QPushButton *btnGuardar;
    QPushButton *btnCancelar;

    void setupUi(QWidget *GrabarAudio)
    {
        if (GrabarAudio->objectName().isEmpty())
            GrabarAudio->setObjectName("GrabarAudio");
        GrabarAudio->resize(350, 200);
        verticalLayout = new QVBoxLayout(GrabarAudio);
        verticalLayout->setObjectName("verticalLayout");
        btnIniciar = new QPushButton(GrabarAudio);
        btnIniciar->setObjectName("btnIniciar");

        verticalLayout->addWidget(btnIniciar);

        btnPausar = new QPushButton(GrabarAudio);
        btnPausar->setObjectName("btnPausar");

        verticalLayout->addWidget(btnPausar);

        btnDetener = new QPushButton(GrabarAudio);
        btnDetener->setObjectName("btnDetener");

        verticalLayout->addWidget(btnDetener);

        btnGuardar = new QPushButton(GrabarAudio);
        btnGuardar->setObjectName("btnGuardar");

        verticalLayout->addWidget(btnGuardar);

        btnCancelar = new QPushButton(GrabarAudio);
        btnCancelar->setObjectName("btnCancelar");

        verticalLayout->addWidget(btnCancelar);


        retranslateUi(GrabarAudio);

        QMetaObject::connectSlotsByName(GrabarAudio);
    } // setupUi

    void retranslateUi(QWidget *GrabarAudio)
    {
        GrabarAudio->setWindowTitle(QCoreApplication::translate("GrabarAudio", "Grabar Audio", nullptr));
        btnIniciar->setText(QCoreApplication::translate("GrabarAudio", "Iniciar grabaci\303\263n", nullptr));
        btnPausar->setText(QCoreApplication::translate("GrabarAudio", "Pausar", nullptr));
        btnDetener->setText(QCoreApplication::translate("GrabarAudio", "Detener", nullptr));
        btnGuardar->setText(QCoreApplication::translate("GrabarAudio", "Guardar", nullptr));
        btnCancelar->setText(QCoreApplication::translate("GrabarAudio", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GrabarAudio: public Ui_GrabarAudio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRABARAUDIO_H
