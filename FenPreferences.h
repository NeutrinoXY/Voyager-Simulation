#ifndef FENPREFERENCES_H
#define FENPREFERENCES_H

#include <QtWidgets>
#include <math.h>

class FenPreferences : public QWidget
{
    Q_OBJECT

public:
    FenPreferences(QWidget *parent = 0);
    ~FenPreferences();
    int getZoom();
    int getDureeAnimation();
    int getNbrEtapes();
    double getPas();
    double getAngleTerre();
    double getAngleJupiter();
    double getAngleSaturne();
    double getAngleUranus();
    double getVitesseX();
    double getVitesseY();

signals:

public slots:
    void setZoom(int val);
    void setDureeAnimation(int val);
    void setNbrEtapes(int val);
    void setPas(double val);
    void setAngleTerre(int val);
    void setAngleJupiter(int val);
    void setAngleSaturne(int val);
    void setAngleUranus(int val);
    void setVitesseX(double val);
    void setVitesseY(double val);

private:
        QSpinBox *spinBoxAngleTerre;
        QSpinBox *spinBoxAngleJupiter;
        QSpinBox *spinBoxAngleSaturne;
        QSpinBox *spinBoxAngleUranus;
        QDoubleSpinBox *spinBoxPas;
        QSpinBox *spinBoxZoom;
        QDoubleSpinBox *vitX;
        QDoubleSpinBox *vitY;
        QSpinBox *spinBoxDureeAnimation;
        QSpinBox *spinBoxNbrEtapes;
        QRadioButton *euler;
        QRadioButton *runge;
        // paramètres par défaut
        int zoom=20;
        int dureeAnimation=20000;
        int nbrEtapes=100000;
        double pas=0.0001;
        double angleTerre=0;
        double angleJupiter=0;
        double angleSaturne=0;
        double angleUranus=0;
        double vitesseX=0;
        double vitesseY=9;
};

#endif // FENPREFERENCES_H
