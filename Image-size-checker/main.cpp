#include "imagesizechecker.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageSizeChecker w;
    w.show();
    return QCoreApplication::exec();
}
