#ifndef HEADER_FENPRINCIPALE
#define HEADER_FENPRINCIPALE

#include <QtWidgets>
#include "Astre.h"
#include "Sonde.h"
#include "FenPreferences.h"

class FenPrincipale : public QMainWindow
{
    Q_OBJECT
    public:
        FenPrincipale();
        ~FenPrincipale();

    public slots:
        void ouvrirFenetrePreferences();
        void ouvrirFenetreAPropos();
        void lancerSimulation();
        void arreterSimulation();
        void getVitSonde(int i);

    private:
        FenPreferences *fenetrePreferences;

        Astre* astres;
        Sonde* ssonde;

        QWidget *zoneCentrale = new QWidget;
        QLayout *layout = new QVBoxLayout();
        QGraphicsScene *scene = new QGraphicsScene();
        QGraphicsView *view = new QGraphicsView(scene);

        QGraphicsEllipseItem *terreEllipse;
        QGraphicsEllipseItem *jupiterEllipse;
        QGraphicsEllipseItem *saturneEllipse;
        QGraphicsEllipseItem *uranusEllipse;

        QGraphicsPixmapItem *soleil;
        QGraphicsPixmapItem *terre;
        QGraphicsPixmapItem *jupiter;
        QGraphicsPixmapItem *saturne;
        QGraphicsPixmapItem *uranus;
        QGraphicsPixmapItem *sonde;

        QGraphicsItemAnimation *animationSoleil;
        QGraphicsItemAnimation *animationTerre;
        QGraphicsItemAnimation *animationJupiter;
        QGraphicsItemAnimation *animationSaturne;
        QGraphicsItemAnimation *animationUranus;
        QGraphicsItemAnimation *animationSonde;

        QStatusBar *statusBar = new QStatusBar;
        QTimeLine *timer; //durée de l'animation
        QProgressBar *progressBar = new QProgressBar;
        QLabel *vitesseSondeLabel = new QLabel;
        double *vitesseSonde;
};
#endif
