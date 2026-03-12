#include "Login.h"
#include "MainWindow.h"
#include "Signin.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    setWindowFlag(Qt::FramelessWindowHint);

    //ui.close_toolButton->setCursor(Qt::PointingHandCursor);
    ui.register_pushButton->setCursor(Qt::PointingHandCursor);

    connect(ui.close_toolButton, &QToolButton::clicked,
        this, &Login::on_close_toolButton_clicked);

    connect(ui.register_pushButton, &QToolButton::clicked,
        this, &Login::on_register_pushButton_clicked);

    connect(ui.login_pushButton, &QToolButton::clicked,
        this, &Login::on_login_pushButton_clicked);
}

Login::~Login()
{}

void Login::on_close_toolButton_clicked()
{
    this->close();
}


void Login::on_register_pushButton_clicked()
{
    Signin* regWindow = new Signin();
    regWindow->setAttribute(Qt::WA_DeleteOnClose); // 关闭自动释放
    regWindow->show();
}

void Login::on_login_pushButton_clicked()
{
    MainWindow* mainWindow = new MainWindow();
    mainWindow->setAttribute(Qt::WA_DeleteOnClose); // 关闭自动释放
    mainWindow->show();
}
