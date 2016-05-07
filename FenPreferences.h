#ifndef FENPREFERENCES_H
#define FENPREFERENCES_H

#include <QtWidgets>

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

signals:

public slots:
    void setZoom(int val);
    void setDureeAnimation(int val);
    void setNbrEtapes(int val);
    void setPas(double val);

private:
        QSpinBox *posXT;
        QSpinBox *posYT;
        QSpinBox *posXJ;
        QSpinBox *posYJ;
        QSpinBox *posXS;
        QSpinBox *posYS;
        QSpinBox *posXU;
        QSpinBox *posYU;
        QDoubleSpinBox *spinBoxPas;
        QSpinBox *spinBoxZoom;
        QSpinBox *posX;
        QSpinBox *posY;
        QSpinBox *vit;
        QSpinBox *spinBoxDureeAnimation;
        QSpinBox *spinBoxNbrEtapes;
        QRadioButton *euler;
        QRadioButton *runge;
        // paramètres par défaut
        int zoom=20;
        int dureeAnimation=20000;
        int nbrEtapes=100000;
        double pas=0.0001;
};

#endif // FENPREFERENCES_H
