#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif
#include <iostream>
#include "Astre.h"
#include "Sonde.h"

#include <QApplication>
#include <QtWidgets>
#include "FenPrincipale.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    FenPrincipale fenetrePrincipale;
    fenetrePrincipale.setWindowTitle("Projet Sonde Voyager");
    fenetrePrincipale.setWindowIcon(QIcon("nasa.png"));
    fenetrePrincipale.showMaximized();
    return app.exec();
}
