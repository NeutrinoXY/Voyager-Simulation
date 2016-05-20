#include "FenPreferences.h"

FenPreferences::FenPreferences(QWidget *parent) : QWidget(parent)
{
    //bloc planètes
    QLabel *labelPosIni1 = new QLabel("Angle initial (en degrés)");
    QLabel *labelPosIni2 = new QLabel("Angle initial (en degrés)");
    QLabel *labelPosIni3 = new QLabel("Angle initial (en degrés)");
    QLabel *labelPosIni4 = new QLabel("Angle initial (en degrés)");
    QLabel *labelPosIniX = new QLabel("Position initiale en X");
    QLabel *labelPosIniY = new QLabel("Position initiale en Y");
    QLabel *labelVitIniX = new QLabel("Vitesse initiale en X");
    QLabel *labelVitIniY = new QLabel("Vitesse initiale en Y");

    spinBoxAngleTerre = new QDoubleSpinBox();
    spinBoxAngleTerre->setRange(0,359);
    QFormLayout *terreLayout = new QFormLayout;
    terreLayout->addRow(labelPosIni1);
    terreLayout->addRow(spinBoxAngleTerre);
    QGroupBox *groupTerre = new QGroupBox("Terre");
    groupTerre->setLayout(terreLayout);
    groupTerre->setCheckable(true);
    groupTerre->setChecked(true);
    connect(spinBoxAngleTerre,SIGNAL(valueChanged(double)),this, SLOT(setAngleTerre(double)));

    spinBoxAngleJupiter = new QDoubleSpinBox();
    spinBoxAngleJupiter->setRange(0,359);
    QFormLayout *jupiterLayout = new QFormLayout;
    jupiterLayout->addRow(labelPosIni2);
    jupiterLayout->addRow(spinBoxAngleJupiter);
    QGroupBox *groupJupiter = new QGroupBox("Jupiter");
    groupJupiter->setLayout(jupiterLayout);
    groupJupiter->setCheckable(true);
    groupJupiter->setChecked(true);
    connect(spinBoxAngleJupiter,SIGNAL(valueChanged(double)),this, SLOT(setAngleJupiter(double)));

    spinBoxAngleSaturne = new QDoubleSpinBox();
    spinBoxAngleSaturne->setRange(0,359);
    QFormLayout *saturneLayout = new QFormLayout;
    saturneLayout->addRow(labelPosIni3);
    saturneLayout->addRow(spinBoxAngleSaturne);
    QGroupBox *groupSaturne = new QGroupBox("Saturne");
    groupSaturne->setLayout(saturneLayout);
    groupSaturne->setCheckable(true);
    groupSaturne->setChecked(true);
    connect(spinBoxAngleSaturne,SIGNAL(valueChanged(double)),this, SLOT(setAngleSaturne(double)));

    spinBoxAngleUranus = new QDoubleSpinBox();
    spinBoxAngleUranus->setRange(0,359);
    QFormLayout *uranusLayout = new QFormLayout;
    uranusLayout->addRow(labelPosIni4);
    uranusLayout->addRow(spinBoxAngleUranus);
    QGroupBox *groupUranus = new QGroupBox("Uranus");
    groupUranus->setLayout(uranusLayout);
    groupUranus->setCheckable(true);
    groupUranus->setChecked(true);
    connect(spinBoxAngleUranus,SIGNAL(valueChanged(double)),this, SLOT(setAngleUranus(double)));

    //bloc pas
    spinBoxPas = new QDoubleSpinBox();
    spinBoxPas->setDecimals(4);
    spinBoxPas->setSingleStep(0.0001);
    spinBoxPas->setValue(0.0001);
    QVBoxLayout *pasLayout = new QVBoxLayout;
    pasLayout->addWidget(spinBoxPas);
    connect(spinBoxPas,SIGNAL(valueChanged(double)),this, SLOT(setPas(double)));
    QGroupBox *groupPas = new QGroupBox("Pas");
    groupPas->setLayout(pasLayout);

    //bloc animation
    //QLabel *labelZoom = new QLabel("Zoom :");
    //QLabel *labelDureeAnimation = new QLabel("Durée de l'animation (en secondes):");
    //QLabel *labelNbrEtapes = new QLabel("Nombre d'étapes :");
    spinBoxZoom = new QSpinBox();
    spinBoxZoom->setValue(20);
    /*spinBoxDureeAnimation = new QSpinBox();
    spinBoxDureeAnimation->setValue(20);
    spinBoxNbrEtapes = new QSpinBox();
    spinBoxNbrEtapes->setRange(0,300000);
    spinBoxNbrEtapes->setValue(100000);
    spinBoxNbrEtapes->setSingleStep(10000);*/
    /*QVBoxLayout *animationLayout = new QVBoxLayout;
    animationLayout->addWidget(labelZoom);
    animationLayout->addWidget(spinBoxZoom);*/
    /*animationLayout->addWidget(labelDureeAnimation);
    animationLayout->addWidget(spinBoxDureeAnimation);
    animationLayout->addWidget(labelNbrEtapes);
    animationLayout->addWidget(spinBoxNbrEtapes);*/
    QGroupBox *groupZoom = new QGroupBox("Zoom");
    connect(spinBoxZoom,SIGNAL(valueChanged(int)),this, SLOT(setZoom(int)));
    /*connect(spinBoxDureeAnimation,SIGNAL(valueChanged(int)),this, SLOT(setDureeAnimation(int)));
    connect(spinBoxNbrEtapes,SIGNAL(valueChanged(int)),this, SLOT(setNbrEtapes(int)));*/
    QVBoxLayout *zoomLayout = new QVBoxLayout;
    zoomLayout->addWidget(spinBoxZoom);
    groupZoom->setLayout(zoomLayout);

    //bloc conditions initiales de la sonde
    posX = new QDoubleSpinBox();
    posY = new QDoubleSpinBox();
    posX->setDecimals(1);
    posX->setSingleStep(0.1);
    posX->setValue(1);
    posY->setDecimals(1);
    posY->setSingleStep(0.1);
    posY->setValue(0);
    vitX = new QDoubleSpinBox();
    vitY = new QDoubleSpinBox();
    vitX->setDecimals(1);
    vitX->setSingleStep(0.1);
    vitX->setValue(0);
    vitY->setDecimals(1);
    vitY->setSingleStep(0.1);
    vitY->setValue(3);
    connect(posX,SIGNAL(valueChanged(double)),this, SLOT(setPositionX(double)));
    connect(posY,SIGNAL(valueChanged(double)),this, SLOT(setPositionY(double)));
    connect(vitX,SIGNAL(valueChanged(double)),this, SLOT(setVitesseX(double)));
    connect(vitY,SIGNAL(valueChanged(double)),this, SLOT(setVitesseY(double)));
    QHBoxLayout *sondeLayout = new QHBoxLayout;
    QFormLayout *posLayout = new QFormLayout;
    posLayout->addRow(labelPosIniX);
    posLayout->addRow(posX);
    posLayout->addRow(labelPosIniY);
    posLayout->addRow(posY);
    QFormLayout *vitLayout = new QFormLayout;
    vitLayout->addRow(labelVitIniX);
    vitLayout->addRow(vitX);
    vitLayout->addRow(labelVitIniY);
    vitLayout->addRow(vitY);
    sondeLayout->addLayout(posLayout);
    sondeLayout->addLayout(vitLayout);
    QGroupBox *groupSonde = new QGroupBox("Sonde");
    groupSonde->setLayout(sondeLayout);

    //bloc méthode d'intégration
    euler = new QRadioButton("Euler");
    runge = new QRadioButton("Runge-Kutta");
    euler->setChecked(true);
    QVBoxLayout *methodeLayout = new QVBoxLayout;
    methodeLayout->addWidget(euler);
    methodeLayout->addWidget(runge);
    QGroupBox *groupMethode = new QGroupBox("Méthode d'intégration");
    groupMethode->setLayout(methodeLayout);

    //onglets
    //QTabWidget *onglets = new QTabWidget();
    QWidget *page1 = new QWidget;
    QWidget *page2 = new QWidget;

    //page 1
    QVBoxLayout *page1Layout = new QVBoxLayout;
    page1Layout->addWidget(groupZoom);
    page1Layout->addWidget(groupPas);
    page1Layout->addWidget(groupMethode);
    page1->setLayout(page1Layout);

    //page 2
    QVBoxLayout *page2Layout = new QVBoxLayout;
    QGridLayout *planeteLayout = new QGridLayout;
    planeteLayout->addWidget(groupTerre,0,0);
    planeteLayout->addWidget(groupJupiter,0,1);
    planeteLayout->addWidget(groupSaturne,1,0);
    planeteLayout->addWidget(groupUranus,1,1);
    page2Layout->addLayout(planeteLayout);
    page2Layout->addWidget(groupSonde);
    page2->setLayout(page2Layout);

    /*onglets->addTab(page1, "Général");
    onglets->addTab(page2, "Conditions initiales");*/

    QHBoxLayout *layoutPrincipal = new QHBoxLayout;
    layoutPrincipal->addWidget(page1);
    layoutPrincipal->addWidget(page2);
    setLayout(layoutPrincipal);
}

int FenPreferences::getZoom()
{
    return zoom;
}

void FenPreferences::setZoom(int val)
{
    zoom=val;
}

double FenPreferences::getPas()
{
    return pas;
}

void FenPreferences::setPas(double val)
{
    pas=val;
}

FenPreferences::~FenPreferences()
{

}

double FenPreferences::getAngleTerre()
{
    return angleTerre;
}

double FenPreferences::getAngleJupiter()
{
    return angleJupiter;
}

double FenPreferences::getAngleSaturne()
{
    return angleSaturne;
}

double FenPreferences::getAngleUranus()
{
    return angleUranus;
}

void FenPreferences::setAngleTerre(double val)
{
    angleTerre=val*M_PI/180;
}

void FenPreferences::setAngleJupiter(double val)
{
    angleJupiter=val*M_PI/180;
}

void FenPreferences::setAngleSaturne(double val)
{
    angleSaturne=val*M_PI/180;
}

void FenPreferences::setAngleUranus(double val)
{
    angleUranus=val*M_PI/180;
}

double FenPreferences::getPositionX()
{
    return positionX;
}

double FenPreferences::getPositionY()
{
    return positionY;
}

double FenPreferences::getVitesseX()
{
    return vitesseX;
}

double FenPreferences::getVitesseY()
{
    return vitesseY;
}

void FenPreferences::setPositionX(double val)
{
    positionX=val;
}

void FenPreferences::setPositionY(double val)
{
    positionY=val;
}

void FenPreferences::setVitesseX(double val)
{
    vitesseX=val;
}

void FenPreferences::setVitesseY(double val)
{
    vitesseY=val;
}
