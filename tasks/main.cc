#include "tasks/TalkyClient.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    TalkyClient talkyClient;
    talkyClient.launch();

    return app.exec();
}
