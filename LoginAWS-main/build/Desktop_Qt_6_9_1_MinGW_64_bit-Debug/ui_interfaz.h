/********************************************************************************
** Form generated from reading UI file 'interfaz.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFAZ_H
#define UI_INTERFAZ_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Interfaz
{
public:
    QGridLayout *gridLayout;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayoutLeft;
    QToolButton *toolButton;
    QLabel *labelTranscripciones;
    QListView *listView;
    QHBoxLayout *horizontalLayoutBotonesAudio;
    QPushButton *loadButton;
    QPushButton *recordButton;
    QLabel *labelTranscripcion;
    QPlainTextEdit *transcriptionEdit;
    QVBoxLayout *vboxLayout;
    QPushButton *saveTranscriptionButton;
    QHBoxLayout *horizontalLayoutExport;
    QPushButton *exportWordButton;
    QPushButton *exportPdfButton;
    QPushButton *exportTxtButton;

    void setupUi(QWidget *Interfaz)
    {
        if (Interfaz->objectName().isEmpty())
            Interfaz->setObjectName("Interfaz");
        Interfaz->resize(795, 500);
        Interfaz->setStyleSheet(QString::fromUtf8("background-color: #444444;"));
        gridLayout = new QGridLayout(Interfaz);
        gridLayout->setObjectName("gridLayout");
        verticalWidget = new QWidget(Interfaz);
        verticalWidget->setObjectName("verticalWidget");
        verticalWidget->setMinimumSize(QSize(50, 0));
        verticalWidget->setMaximumSize(QSize(220, 16777215));
        verticalWidget->setStyleSheet(QString::fromUtf8("background-color: #2A2A2A;"));
        verticalLayoutLeft = new QVBoxLayout(verticalWidget);
        verticalLayoutLeft->setObjectName("verticalLayoutLeft");
        toolButton = new QToolButton(verticalWidget);
        toolButton->setObjectName("toolButton");
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("go-home")));
        toolButton->setIcon(icon);
        toolButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
        toolButton->setIconSize(QSize(32, 32));

        verticalLayoutLeft->addWidget(toolButton);

        labelTranscripciones = new QLabel(verticalWidget);
        labelTranscripciones->setObjectName("labelTranscripciones");
        labelTranscripciones->setAlignment(Qt::AlignCenter);
        labelTranscripciones->setStyleSheet(QString::fromUtf8("color: #AAAAAA; font-weight: bold; margin-top: 10px"));

        verticalLayoutLeft->addWidget(labelTranscripciones);

        listView = new QListView(verticalWidget);
        listView->setObjectName("listView");

        verticalLayoutLeft->addWidget(listView);


        gridLayout->addWidget(verticalWidget, 0, 0, 4, 1);

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
        labelTranscripcion->setStyleSheet(QString::fromUtf8("color: #EEEEEE; font-weight: bold;"));

        gridLayout->addWidget(labelTranscripcion, 1, 1, 1, 1);

        transcriptionEdit = new QPlainTextEdit(Interfaz);
        transcriptionEdit->setObjectName("transcriptionEdit");
        transcriptionEdit->setStyleSheet(QString::fromUtf8("font-size: 15px; background-color: #f9f9f9; color: #222; border-radius: 6px; padding: 8px;"));

        gridLayout->addWidget(transcriptionEdit, 2, 1, 1, 1);

        vboxLayout = new QVBoxLayout();
        vboxLayout->setObjectName("vboxLayout");
        saveTranscriptionButton = new QPushButton(Interfaz);
        saveTranscriptionButton->setObjectName("saveTranscriptionButton");
        saveTranscriptionButton->setStyleSheet(QString::fromUtf8("background-color: #3a6ea5; color: white; padding: 6px; border-radius: 6px; font-weight: bold;"));

        vboxLayout->addWidget(saveTranscriptionButton);

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


        vboxLayout->addLayout(horizontalLayoutExport);


        gridLayout->addLayout(vboxLayout, 3, 1, 1, 1);


        retranslateUi(Interfaz);

        QMetaObject::connectSlotsByName(Interfaz);
    } // setupUi

    void retranslateUi(QWidget *Interfaz)
    {
        Interfaz->setWindowTitle(QCoreApplication::translate("Interfaz", "Transcriptor de conversaciones", nullptr));
        toolButton->setText(QCoreApplication::translate("Interfaz", "Casa", nullptr));
        labelTranscripciones->setText(QCoreApplication::translate("Interfaz", "Historial de transcripciones", nullptr));
        loadButton->setText(QCoreApplication::translate("Interfaz", "\360\237\223\201 Cargar Archivo", nullptr));
        recordButton->setText(QCoreApplication::translate("Interfaz", "\360\237\216\231\357\270\217 Grabar Audio", nullptr));
        labelTranscripcion->setText(QCoreApplication::translate("Interfaz", "Transcripci\303\263n:", nullptr));
        saveTranscriptionButton->setText(QCoreApplication::translate("Interfaz", "Guardar transcripci\303\263n", nullptr));
        exportWordButton->setText(QCoreApplication::translate("Interfaz", "\360\237\223\203 Exportar WORD", nullptr));
        exportPdfButton->setText(QCoreApplication::translate("Interfaz", "\360\237\223\225 Exportar PDF", nullptr));
        exportTxtButton->setText(QCoreApplication::translate("Interfaz", "\360\237\223\204 Exportar TXT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Interfaz: public Ui_Interfaz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFAZ_H
