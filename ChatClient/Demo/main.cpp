//#include "demodialog.h"

#include <QApplication>
#include "ckernel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    DemoDialog w;
//    w.show();

    CKernel::getInstance();

    return a.exec();
}
