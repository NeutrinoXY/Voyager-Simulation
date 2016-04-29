#include "FenPreferences.h"

FenPreferences::FenPreferences(QWidget *parent) : QWidget(parent)
{
    //bloc planètes
    terre = new QCheckBox("Inclure la Terre");
    terre->setChecked(true);
    posXT = new QSpinBox();
    posYT = new QSpinBox();
    QFormLayout *terreLayout = new QFormLayout;
    terreLayout->addRow("X :", posXT);
    terreLayout->addRow("Y :", posYT);
    QGroupBox *groupTerre = new QGroupBox("Position initiale de la Terre");
    groupTerre->setLayout(terreLayout);
    groupTerre->setCheckable(true);
    groupTerre->setChecked(true);

    jupiter = new QCheckBox("Inclure Jupiter");
    jupiter->setChecked(true);
    posXJ = new QSpinBox();
    posYJ = new QSpinBox();
    QFormLayout *jupiterLayout = new QFormLayout;
    jupiterLayout->addRow("X :", posXJ);
    jupiterLayout->addRow("Y :", posYJ);
    QGroupBox *groupJupiter = new QGroupBox("Position initiale de Jupiter");
    groupJupiter->setLayout(jupiterLayout);
    groupJupiter->setCheckable(true);
    groupJupiter->setChecked(true);

    saturne = new QCheckBox("Inclure Saturne");
    saturne->setChecked(true);
    posXS = new QSpinBox();
    posYS = new QSpinBox();
    QFormLayout *saturneLayout = new QFormLayout;
    saturneLayout->addRow("X :", posXS);
    saturneLayout->addRow("Y :", posYS);
    QGroupBox *groupSaturne = new QGroupBox("Position initiale de Saturne");
    groupSaturne->setLayout(saturneLayout);
    groupSaturne->setCheckable(true);
    groupSaturne->setChecked(true);

    uranus = new QCheckBox("Inclure Uranus");
    uranus->setChecked(true);
    posXU = new QSpinBox();
    posYU = new QSpinBox();
    QFormLayout *uranusLayout = new QFormLayout;
    uranusLayout->addRow("X :", posXU);
    uranusLayout->addRow("Y :", posYU);
    QGroupBox *groupUranus = new QGroupBox("Position initiale d'Uranus");
    groupUranus->setLayout(uranusLayout);
    groupUranus->setCheckable(true);
    groupUranus->setChecked(true);

    //bloc pas
    pas = new QDoubleSpinBox();
    pas->setDecimals(4);
    pas->setSingleStep(0.0001);
    QVBoxLayout *pasLayout = new QVBoxLayout;
    pasLayout->addWidget(pas);
    QGroupBox *groupPas = new QGroupBox("Définir le pas");
    groupPas->setLayout(pasLayout);

    //bloc zoom
    zoom = new QSpinBox();
    QVBoxLayout *zoomLayout = new QVBoxLayout;
    zoomLayout->addWidget(zoom);
    QGroupBox *groupZoom = new QGroupBox("Définir le zoom");
    groupZoom->setLayout(zoomLayout);

    //bloc conditions initiales de la sonde
    posX = new QSpinBox();
    posY = new QSpinBox();
    vit = new QSpinBox();
    QFormLayout *condLayout = new QFormLayout;
    condLayout->addRow("X :", posX);
    condLayout->addRow("Y :", posY);
    condLayout->addRow("Vitesse :", vit);
    QGroupBox *groupPosition = new QGroupBox("Conditions initiales de la sonde");
    groupPosition->setLayout(condLayout);

    //bloc méthode d'intégration
    euler = new QRadioButton("Euler");
    runge = new QRadioButton("Runge-Kutta");
    euler->setChecked(true);
    QVBoxLayout *methodeLayout = new QVBoxLayout;
    methodeLayout->addWidget(euler);
    methodeLayout->addWidget(runge);
    QGroupBox *groupMethode = new QGroupBox("Méthode d'intégration");
    groupMethode->setLayout(methodeLayout);


    //boutons
    boutonValider = new QPushButton("Valider");
    boutonAnnuler = new QPushButton("Annuler");
    QHBoxLayout *boutonsLayout = new QHBoxLayout;
    boutonsLayout->addWidget(boutonValider);
    boutonsLayout->addWidget(boutonAnnuler);
    QGroupBox *groupBoutons = new QGroupBox("");
    groupBoutons->setLayout(boutonsLayout);

    //connexions
    connect(boutonAnnuler, SIGNAL(clicked()), this, SLOT(close()));

    //onglets
    QTabWidget *onglets = new QTabWidget();
    QWidget *page1 = new QWidget;
    QWidget *page2 = new QWidget;

    //page 1
    QVBoxLayout *page1Layout = new QVBoxLayout;
    page1Layout->addWidget(groupPas);
    page1Layout->addWidget(groupZoom);
    page1Layout->addWidget(groupMethode);
    page1Layout->addWidget(groupBoutons);
    page1->setLayout(page1Layout);

    //page 2
    QGridLayout *page2Layout = new QGridLayout;
    page2Layout->addWidget(groupTerre,0,0);
    page2Layout->addWidget(groupJupiter,0,1);
    page2Layout->addWidget(groupSaturne,1,0);
    page2Layout->addWidget(groupUranus,1,1);
    page2->setLayout(page2Layout);

    onglets->addTab(page1, "Général");
    onglets->addTab(page2, "Planètes");

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(onglets);
    setLayout(layoutPrincipal);
}
