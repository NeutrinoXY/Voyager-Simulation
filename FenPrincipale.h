#ifndef HEADER_FENPRINCIPALE
#define HEADER_FENPRINCIPALE

#include <QtWidgets>
#include "FenPreferences.h"

class FenPrincipale : public QMainWindow
{
    Q_OBJECT

    public:
        FenPrincipale();
        ~FenPrincipale();
        void ecrireFichier();

    public slots:
        void ouvrirFenetreAPropos();
        void lancerSimulation();

    private:
        FenPreferences *fenetrePreferences;
        QWidget *zoneCentrale = new QWidget;
        QLayout *layout = new QVBoxLayout();
        QGraphicsScene *scene = new QGraphicsScene();
        QGraphicsView *view = new QGraphicsView(scene);
};
#endif
