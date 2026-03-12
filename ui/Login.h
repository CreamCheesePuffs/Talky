#pragma once

#include <QWidget>
#include "ui_Login.h"

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

private:
    void on_close_toolButton_clicked();
    void on_register_pushButton_clicked();
    void on_login_pushButton_clicked();

    Ui::LoginClass ui;
};

