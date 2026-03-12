#include "Signin.h"

Signin::Signin(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    setWindowFlag(Qt::FramelessWindowHint);

    connect(ui.close_toolButton, &QToolButton::clicked,
        this, &Signin::on_close_toolButton_clicked);
}

Signin::~Signin()
{}

void Signin::on_close_toolButton_clicked()
{
    this->close();
}
