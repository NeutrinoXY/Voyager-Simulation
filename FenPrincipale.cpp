#include "FenPrincipale.h"
#include "FenPreferences.h"

FenPrincipale::FenPrincipale()
{
    fenetrePreferences = new FenPreferences;

    //menus
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
    QAction *actionQuitter = new QAction("&Quitter", this);
    actionQuitter->setIcon(QIcon("quitter.png"));
    menuFichier->addAction(actionQuitter);
    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    QMenu *menuAffichage = menuBar()->addMenu("&Affichage");
    QAction *actionExecuter = new QAction("&Exécuter", this);
    actionExecuter->setIcon(QIcon("play.png"));
    menuAffichage->addAction(actionExecuter);
    connect(actionExecuter, SIGNAL(triggered()), this, SLOT(lancerSimulation()));

    QMenu *menuAide = menuBar()->addMenu("&Aide");
    QAction *actionAPropos = new QAction("&A propos...", this);
    actionAPropos->setIcon(QIcon("a propos.png"));
    menuAide->addAction(actionAPropos);
    connect(actionAPropos, SIGNAL(triggered()), this, SLOT(ouvrirFenetreAPropos()));

    //toolbar
    QToolBar *toolBarFichier = addToolBar("Fichier");
    toolBarFichier->addAction(actionQuitter);
    toolBarFichier->setFloatable(false);
    toolBarFichier->setMovable(false);
    QToolBar *toolBarAffichage = addToolBar("Affichage");
    toolBarAffichage->addAction(actionExecuter);
    toolBarAffichage->setFloatable(false);
    toolBarAffichage->setMovable(false);

    /*QStatusBar *statusBar = new QStatusBar();
    QLabel *label = new QLabel(QCoreApplication::applicationDirPath());
    statusBar->addWidget(label);
    setStatusBar(statusBar);*/

    setCentralWidget(fenetrePreferences);
}

FenPrincipale::~FenPrincipale()
{

}

void FenPrincipale::ouvrirFenetreAPropos()
{
    QMessageBox::information(this, "A propos", "Logiciel développé par : "
    "Gaëtan Cavaillès, Antoine Delbèque, Maxime Guiblin et Francis Shih");
}

void FenPrincipale::lancerSimulation()
{
    //recuperer et ecrire les valeurs des variables modifiables
    ecrireFichier();

    //on lance le programme (compilé avec la SDL)
   QProcess::startDetached("Projet Voyager.exe");
}

void FenPrincipale::ecrireFichier()
{
    QFile fichier("donnees.txt");
    if (!fichier.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return;
    }
    QTextStream out(&fichier);
    out << "zoom = " << fenetrePreferences->getZoom() << endl;
    out << "pas = " << fenetrePreferences->getPas() << endl;
    out << "angleTerre = " << fenetrePreferences->getAngleTerre() << endl;
    out << "angleJupiter = " << fenetrePreferences->getAngleJupiter() << endl;
    out << "angleSaturne = " << fenetrePreferences->getAngleSaturne() << endl;
    out << "angleUranus = " << fenetrePreferences->getAngleUranus() << endl;
    out << "PositionX = " << fenetrePreferences->getPositionX() << endl;
    out << "PositionY = " << fenetrePreferences->getPositionY() << endl;
    out << "vitesseX = " << fenetrePreferences->getVitesseX() << endl;
    out << "vitesseY = " << fenetrePreferences->getVitesseY() << endl;
}
