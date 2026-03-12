#pragma once

#include <QWidget>
#include "ui_Signin.h"

class Signin : public QWidget
{
    Q_OBJECT

public:
    Signin(QWidget *parent = nullptr);
    ~Signin();

private:
    void on_close_toolButton_clicked();

    Ui::SigninClass ui;
};

