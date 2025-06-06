/********************************************************************************
** Form generated from reading UI file 'grabaraudio.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRABARAUDIO_H
#define UI_GRABARAUDIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GrabarAudio
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lblEstado;
    QPushButton *btnIniciar;
    QPushButton *btnPausar;
    QPushButton *btnDetener;
    QPushButton *btnGuardar;
    QPushButton *btnCancelar;

    void setupUi(QWidget *GrabarAudio)
    {
        if (GrabarAudio->objectName().isEmpty())
            GrabarAudio->setObjectName("GrabarAudio");
        GrabarAudio->setWindowModality(Qt::WindowModality::ApplicationModal);
        GrabarAudio->resize(350, 260);
        GrabarAudio->setStyleSheet(QString::fromUtf8("background-color: #444444;"));
        verticalLayout = new QVBoxLayout(GrabarAudio);
        verticalLayout->setObjectName("verticalLayout");
        lblEstado = new QLabel(GrabarAudio);
        lblEstado->setObjectName("lblEstado");
        lblEstado->setStyleSheet(QString::fromUtf8("color: lightgray; font-weight: bold;"));
        lblEstado->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(lblEstado);

        btnIniciar = new QPushButton(GrabarAudio);
        btnIniciar->setObjectName("btnIniciar");
        btnIniciar->setStyleSheet(QString::fromUtf8("background-color: #888888; color: white;"));

        verticalLayout->addWidget(btnIniciar);

        btnPausar = new QPushButton(GrabarAudio);
        btnPausar->setObjectName("btnPausar");
        btnPausar->setStyleSheet(QString::fromUtf8("background-color: #888888; color: white;"));

        verticalLayout->addWidget(btnPausar);

        btnDetener = new QPushButton(GrabarAudio);
        btnDetener->setObjectName("btnDetener");
        btnDetener->setStyleSheet(QString::fromUtf8("background-color: #888888; color: white;"));

        verticalLayout->addWidget(btnDetener);

        btnGuardar = new QPushButton(GrabarAudio);
        btnGuardar->setObjectName("btnGuardar");
        btnGuardar->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; color: white;"));

        verticalLayout->addWidget(btnGuardar);

        btnCancelar = new QPushButton(GrabarAudio);
        btnCancelar->setObjectName("btnCancelar");
        btnCancelar->setStyleSheet(QString::fromUtf8("background-color: #d32f2f; color: white;"));

        verticalLayout->addWidget(btnCancelar);


        retranslateUi(GrabarAudio);

        QMetaObject::connectSlotsByName(GrabarAudio);
    } // setupUi

    void retranslateUi(QWidget *GrabarAudio)
    {
        GrabarAudio->setWindowTitle(QCoreApplication::translate("GrabarAudio", "Grabar Audio", nullptr));
        lblEstado->setText(QCoreApplication::translate("GrabarAudio", "Listo para grabar", nullptr));
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
