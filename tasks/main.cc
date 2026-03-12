#include "ui/Login.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Login login;
    login.show();

    return app.exec();
}
