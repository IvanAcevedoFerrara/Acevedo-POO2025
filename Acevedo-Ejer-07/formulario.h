#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QString>

class QLineEdit;
class QLabel;

class Formulario : public QWidget {
    Q_OBJECT

public:
    Formulario();
    void generarNuevoCaptcha();  // Genera y actualiza el captcha


private slots:
    void verificarCaptcha();

private:
    QString captchaGenerado;
    QLineEdit* leCaptcha;
    QLabel* lblCaptcha;
};

#endif // FORMULARIO_H
