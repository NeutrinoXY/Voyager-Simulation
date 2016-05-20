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
    double getPas();
    double getAngleTerre();
    double getAngleJupiter();
    double getAngleSaturne();
    double getAngleUranus();
    double getPositionX();
    double getPositionY();
    double getVitesseX();
    double getVitesseY();

signals:

public slots:
    void setZoom(int val);
    void setPas(double val);
    void setAngleTerre(double val);
    void setAngleJupiter(double val);
    void setAngleSaturne(double val);
    void setAngleUranus(double val);
    void setPositionX(double val);
    void setPositionY(double val);
    void setVitesseX(double val);
    void setVitesseY(double val);

private:
        QDoubleSpinBox *spinBoxAngleTerre;
        QDoubleSpinBox *spinBoxAngleJupiter;
        QDoubleSpinBox *spinBoxAngleSaturne;
        QDoubleSpinBox *spinBoxAngleUranus;
        QDoubleSpinBox *spinBoxPas;
        QSpinBox *spinBoxZoom;
        QDoubleSpinBox *posX;
        QDoubleSpinBox *posY;
        QDoubleSpinBox *vitX;
        QDoubleSpinBox *vitY;
        QRadioButton *euler;
        QRadioButton *runge;

        // paramètres par défaut
        int zoom=20;
        double pas=0.0001;
        double angleTerre=0;
        double angleJupiter=0;
        double angleSaturne=0;
        double angleUranus=0;
        double positionX=1;
        double positionY=0;
        double vitesseX=0;
        double vitesseY=3;
};

#endif // FENPREFERENCES_H
