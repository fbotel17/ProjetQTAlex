#include "Premier_Pas_Qt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Premier_Pas_Qt w;
    w.show();
    return a.exec();
}
