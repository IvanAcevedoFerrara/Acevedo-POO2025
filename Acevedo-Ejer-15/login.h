#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

class Login : public QWidget {
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);

private slots:
    void onLoginClicked();

private:
    void setupUI();
};

#endif // LOGIN_H
