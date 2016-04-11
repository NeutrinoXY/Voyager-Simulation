#include "FenPrincipale.h"
#include "FenPreferences.h"

FenPrincipale::FenPrincipale()
{
    //menus
    QMenu *menuFichier = menuBar()->addMenu("&Fichier");
    QAction *actionQuitter = new QAction("&Quitter", this);
    actionQuitter->setIcon(QIcon("quitter.png"));
    menuFichier->addAction(actionQuitter);
    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    QMenu *menuEdition = menuBar()->addMenu("&Edition");
    QAction *actionPreferences = new QAction("&Préférences...", this);
    actionPreferences->setIcon(QIcon("setting.png"));
    menuEdition->addAction(actionPreferences);
    connect(actionPreferences, SIGNAL(triggered()), this, SLOT(ouvrirFenetrePreferences()));

    QMenu *menuAffichage = menuBar()->addMenu("&Affichage");
    QAction *actionExecuter = new QAction("&Exécuter", this);
    actionExecuter->setIcon(QIcon("play.png"));
    menuAffichage->addAction(actionExecuter);
    // action qui lance l'interface graphique

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
    QToolBar *toolBarEdition = addToolBar("Edition");
    toolBarEdition->addAction(actionPreferences);
    toolBarEdition->setFloatable(false);
    toolBarEdition->setMovable(false);
    QToolBar *toolBarAffichage = addToolBar("Affichage");
    toolBarAffichage->addAction(actionExecuter);
    toolBarAffichage->setFloatable(false);
    toolBarAffichage->setMovable(false);


    QMdiArea *zoneCentrale = new QMdiArea;
    setCentralWidget(zoneCentrale);

}

void FenPrincipale::ouvrirFenetrePreferences()
{
        FenPreferences *fenetrePreferences = new FenPreferences;
        fenetrePreferences->setWindowTitle("Préférences");
        fenetrePreferences->setWindowIcon(QIcon("setting"));
        fenetrePreferences->show();
}

FenPrincipale::~FenPrincipale()
{

}

void FenPrincipale::ouvrirFenetreAPropos()
{
    QMessageBox::information(this, "A propos", "Logiciel développé par : Gaëtan Cavaillès, Antoine Delbèque, Maxime Guiblin et Francis Shih");
}

