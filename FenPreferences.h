#ifndef FENPREFERENCES_H
#define FENPREFERENCES_H

#include <QtWidgets>

class FenPreferences : public QWidget
{
    Q_OBJECT
public:
    FenPreferences(QWidget *parent = 0);

signals:

public slots:


private:
        QCheckBox *terre;
        QSpinBox *posXT;
        QSpinBox *posYT;
        QCheckBox *jupiter;
        QSpinBox *posXJ;
        QSpinBox *posYJ;
        QCheckBox *saturne;
        QSpinBox *posXS;
        QSpinBox *posYS;
        QCheckBox *uranus;
        QSpinBox *posXU;
        QSpinBox *posYU;
        QDoubleSpinBox *pas;
        QSpinBox *zoom;
        QSpinBox *posX;
        QSpinBox *posY;
        QSpinBox *vit;
        QRadioButton *euler;
        QRadioButton *runge;
        QPushButton *boutonValider;
        QPushButton *boutonAnnuler;
};

#endif // FENPREFERENCES_H
