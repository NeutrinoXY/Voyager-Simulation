#include <QApplication>
#include <QtWidgets>
#include "FenPrincipale.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    FenPrincipale fenetrePrincipale;
    fenetrePrincipale.setWindowTitle("Projet Sonde Voyager");
    fenetrePrincipale.setWindowIcon(QIcon("nasa.png"));
    fenetrePrincipale.show();
    return app.exec();
}
