#include "login.h"
#include "ventana.h"
#include "admindb.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

Login::Login(QWidget *parent) : QWidget(parent) {
    setupUI();
    AdminDB::getInstancia()->conectar(); // Conectar a la base de datos
}

void Login::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Campos de usuario y contraseña
    QLineEdit *txtUsuario = new QLineEdit(this);
    txtUsuario->setObjectName("txtUsuario");
    txtUsuario->setPlaceholderText("Usuario");
    layout->addWidget(txtUsuario);

    QLineEdit *txtPassword = new QLineEdit(this);
    txtPassword->setObjectName("txtPassword");
    txtPassword->setPlaceholderText("Contraseña");
    txtPassword->setEchoMode(QLineEdit::Password);
    layout->addWidget(txtPassword);

    // Botón de inicio de sesión
    QPushButton *btnLogin = new QPushButton("Iniciar Sesión", this);
    layout->addWidget(btnLogin);

    connect(btnLogin, &QPushButton::clicked, this, &Login::onLoginClicked);

    setLayout(layout);
    setWindowTitle("Login");
    resize(300, 150);
}

void Login::onLoginClicked() {
    QLineEdit *txtUsuario = findChild<QLineEdit *>("txtUsuario");
    QLineEdit *txtPassword = findChild<QLineEdit *>("txtPassword");

    QString usuario = txtUsuario->text();
    QString password = txtPassword->text();
    QString ultimoIngreso;

    if (AdminDB::getInstancia()->validarUsuario(usuario, password, ultimoIngreso)) {
        AdminDB::getInstancia()->actualizarUltimoIngreso(usuario);

        // Abrir la ventana principal
        Ventana *ventanaPrincipal = new Ventana(usuario, ultimoIngreso);
        ventanaPrincipal->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Error", "Usuario o contraseña incorrectos.");
    }
}
