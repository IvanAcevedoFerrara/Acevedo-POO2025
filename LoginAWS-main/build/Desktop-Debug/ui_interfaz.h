/********************************************************************************
** Form generated from reading UI file 'interfaz.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFAZ_H
#define UI_INTERFAZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Interfaz
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayoutExport;
    QPushButton *exportWordButton;
    QPushButton *exportPdfButton;
    QPushButton *exportTxtButton;
    QPlainTextEdit *transcriptionEdit;
    QHBoxLayout *horizontalLayoutBotonesAudio;
    QPushButton *loadButton;
    QPushButton *recordButton;
    QLabel *labelTranscripcion;
    QWidget *verticalWidget;
    QGridLayout *gridLayout_2;
    QToolButton *toolButton;
    QListView *listView;

    void setupUi(QWidget *Interfaz)
    {
        if (Interfaz->objectName().isEmpty())
            Interfaz->setObjectName("Interfaz");
        Interfaz->resize(795, 500);
        Interfaz->setStyleSheet(QString::fromUtf8("background-color: #444444;"));
        gridLayout = new QGridLayout(Interfaz);
        gridLayout->setObjectName("gridLayout");
        horizontalLayoutExport = new QHBoxLayout();
        horizontalLayoutExport->setObjectName("horizontalLayoutExport");
        exportWordButton = new QPushButton(Interfaz);
        exportWordButton->setObjectName("exportWordButton");

        horizontalLayoutExport->addWidget(exportWordButton);

        exportPdfButton = new QPushButton(Interfaz);
        exportPdfButton->setObjectName("exportPdfButton");

        horizontalLayoutExport->addWidget(exportPdfButton);

        exportTxtButton = new QPushButton(Interfaz);
        exportTxtButton->setObjectName("exportTxtButton");

        horizontalLayoutExport->addWidget(exportTxtButton);


        gridLayout->addLayout(horizontalLayoutExport, 3, 1, 1, 1);

        transcriptionEdit = new QPlainTextEdit(Interfaz);
        transcriptionEdit->setObjectName("transcriptionEdit");

        gridLayout->addWidget(transcriptionEdit, 2, 1, 1, 1);

        horizontalLayoutBotonesAudio = new QHBoxLayout();
        horizontalLayoutBotonesAudio->setObjectName("horizontalLayoutBotonesAudio");
        loadButton = new QPushButton(Interfaz);
        loadButton->setObjectName("loadButton");

        horizontalLayoutBotonesAudio->addWidget(loadButton);

        recordButton = new QPushButton(Interfaz);
        recordButton->setObjectName("recordButton");

        horizontalLayoutBotonesAudio->addWidget(recordButton);


        gridLayout->addLayout(horizontalLayoutBotonesAudio, 0, 1, 1, 1);

        labelTranscripcion = new QLabel(Interfaz);
        labelTranscripcion->setObjectName("labelTranscripcion");

        gridLayout->addWidget(labelTranscripcion, 1, 1, 1, 1);

        verticalWidget = new QWidget(Interfaz);
        verticalWidget->setObjectName("verticalWidget");
        verticalWidget->setMinimumSize(QSize(50, 0));
        verticalWidget->setMaximumSize(QSize(200, 16777215));
        verticalWidget->setStyleSheet(QString::fromUtf8("background-color: #2A2A2A;"));
        gridLayout_2 = new QGridLayout(verticalWidget);
        gridLayout_2->setObjectName("gridLayout_2");
        toolButton = new QToolButton(verticalWidget);
        toolButton->setObjectName("toolButton");

        gridLayout_2->addWidget(toolButton, 0, 0, 1, 1);

        listView = new QListView(verticalWidget);
        listView->setObjectName("listView");

        gridLayout_2->addWidget(listView, 1, 0, 1, 1);


        gridLayout->addWidget(verticalWidget, 0, 0, 4, 1);


        retranslateUi(Interfaz);

        QMetaObject::connectSlotsByName(Interfaz);
    } // setupUi

    void retranslateUi(QWidget *Interfaz)
    {
        Interfaz->setWindowTitle(QCoreApplication::translate("Interfaz", "Form", nullptr));
        exportWordButton->setText(QCoreApplication::translate("Interfaz", "\360\237\223\203 Exportar WORD", nullptr));
        exportPdfButton->setText(QCoreApplication::translate("Interfaz", "\360\237\223\225 Exportar PDF", nullptr));
        exportTxtButton->setText(QCoreApplication::translate("Interfaz", "\360\237\223\204 Exportar TXT", nullptr));
        loadButton->setText(QCoreApplication::translate("Interfaz", "\360\237\223\201 Cargar Archivo", nullptr));
        recordButton->setText(QCoreApplication::translate("Interfaz", "\360\237\216\231\357\270\217 Grabar Audio", nullptr));
        labelTranscripcion->setText(QCoreApplication::translate("Interfaz", "Transcripcion:", nullptr));
        toolButton->setText(QCoreApplication::translate("Interfaz", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Interfaz: public Ui_Interfaz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFAZ_H
