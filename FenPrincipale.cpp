#include "FenPrincipale.h"
#include "FenPreferences.h"

FenPrincipale::FenPrincipale() : soleil(new QGraphicsPixmapItem(*(new QPixmap("soleil.png")))),
    terre(new QGraphicsPixmapItem(*(new QPixmap("terre.png")))),jupiter(new QGraphicsPixmapItem(*(new QPixmap("jupiter.png")))),
    saturne(new QGraphicsPixmapItem(*(new QPixmap("saturne.png")))),uranus(new QGraphicsPixmapItem(*(new QPixmap("uranus.png")))),
    sonde(new QGraphicsPixmapItem(*(new QPixmap("sonde.png"))))
{
    fenetrePreferences = new FenPreferences;
    fenetrePreferences->setWindowTitle("Préférences");
    fenetrePreferences->setWindowIcon(QIcon("setting"));
    fenetrePreferences->setFixedSize(400,500);
    //fenetrePreferences->setWindowFlags(Qt::Tool);

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
    QAction *actionArreter = new QAction("&Arrêter", this);
    actionArreter->setIcon(QIcon("stop.png"));
    menuAffichage->addAction(actionArreter);

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
    toolBarAffichage->addAction(actionArreter);
    toolBarAffichage->setFloatable(false);
    toolBarAffichage->setMovable(false);

    //statusbar    
    statusBar->addWidget(progressBar);
    statusBar->addWidget(vitesseSondeLabel);
    statusBar->addWidget(zoomLabel);
    setStatusBar(statusBar);

    //zone centrale
    view->setScene(scene);
    view->show();
    view->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));
    layout->addWidget(view);
    zoneCentrale->setLayout(layout);
    setCentralWidget(zoneCentrale);
    connect(actionExecuter, SIGNAL(triggered()), this, SLOT(lancerSimulation()));
    connect(actionArreter, SIGNAL(triggered()), this, SLOT(arreterSimulation()));
}

void FenPrincipale::ouvrirFenetrePreferences()
{    
    fenetrePreferences->show();
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
    int zoom = fenetrePreferences->getZoom();
    double pas = fenetrePreferences->getPas();
    int nbEtape = fenetrePreferences->getNbrEtapes();
    int dureeAnimation = fenetrePreferences->getDureeAnimation();

    astres = new Astre[5];
    ssonde = new Sonde(astres, 1);

    vitesseSonde = (double*) calloc(nbEtape,sizeof(*vitesseSonde));
    terreEllipse = new QGraphicsEllipseItem(-1*zoom+32,-1*zoom+32,1*zoom*2,1*zoom*2);
    jupiterEllipse = new QGraphicsEllipseItem(-5.20336301*zoom+32,-5.20336301*zoom+32,5.20336301*zoom*2,5.20336301*zoom*2);
    saturneEllipse = new QGraphicsEllipseItem(-9.554909*zoom+32,-9.554909*zoom+32,9.554909*zoom*2,9.554909*zoom*2);
    uranusEllipse = new QGraphicsEllipseItem(-19.189165*zoom+32,-19.189165*zoom+32,19.189165*zoom*2,19.189165*zoom*2);
    timer = new QTimeLine(dureeAnimation);
    timer->setFrameRange(0, 100);
    timer->setUpdateInterval(17);
    timer->setCurveShape(QTimeLine::LinearCurve);
    timer->start();
    connect(timer, SIGNAL(frameChanged(int)), progressBar, SLOT(setValue(int)));
    connect(timer, SIGNAL(frameChanged(int)), this, SLOT(getVitSonde(int)));

    animationSoleil = new QGraphicsItemAnimation;
    animationTerre = new QGraphicsItemAnimation;
    animationJupiter = new QGraphicsItemAnimation;
    animationSaturne = new QGraphicsItemAnimation;
    animationUranus = new QGraphicsItemAnimation;
    animationSonde = new QGraphicsItemAnimation;

    animationSoleil->setItem(soleil);
    animationSoleil->setTimeLine(timer);

    animationTerre->setItem(terre);
    animationTerre->setTimeLine(timer);

    animationJupiter->setItem(jupiter);
    animationJupiter->setTimeLine(timer);

    animationSaturne->setItem(saturne);
    animationSaturne->setTimeLine(timer);

    animationUranus->setItem(uranus);
    animationUranus->setTimeLine(timer);

    animationSonde->setItem(sonde);
    animationSonde->setTimeLine(timer);

    double t=0;

    astres[0].Definir(0);
    astres[1].Definir(3);
    astres[2].Definir(5);
    astres[3].Definir(6);
    astres[4].Definir(7);

    terreEllipse->setPen(QPen(Qt::white,3));
    jupiterEllipse->setPen(QPen(Qt::white,3));
    saturneEllipse->setPen(QPen(Qt::white,3));
    uranusEllipse->setPen(QPen(Qt::white,3));

    scene->setSceneRect(0,0,1,1);
    scene->addItem(terreEllipse);
    scene->addItem(jupiterEllipse);
    scene->addItem(saturneEllipse);
    scene->addItem(uranusEllipse);
    scene->addItem(soleil);
    scene->addItem(terre);
    scene->addItem(jupiter);
    scene->addItem(saturne);
    scene->addItem(uranus);
    scene->addItem(sonde);
    
    soleil->setPos(-20,-20);

    for (int i=0;i<nbEtape;i++)
    {
         animationTerre->setPosAt(i / (double)nbEtape, QPointF(-5+zoom*astres[1].GetX(0),-5+zoom*astres[1].GetY(0)));
        animationJupiter->setPosAt(i / (double)nbEtape, QPointF(zoom*astres[2].GetX(0)-42,zoom*astres[2].GetY(0)-42));
        animationSaturne->setPosAt(i / (double)nbEtape, QPointF(zoom*astres[3].GetX(0)-85,zoom*astres[3].GetY(0)-44));
        animationUranus->setPosAt(i / (double)nbEtape, QPointF(zoom*astres[4].GetX(0)-20,zoom*astres[4].GetY(0)-20));
        animationSonde->setPosAt(i / (double)nbEtape, QPointF(zoom*ssonde->GetX(0,0)-23,zoom*ssonde->GetY(0,0)-23));
        vitesseSonde[i]=sqrt(pow(ssonde->GetX(1,0),2)+pow(ssonde->GetY(1,0),2));
        t+=pas;
        for (int j=0; j<5; j++)
        {
            astres[j].Update(t);
        }
        ssonde->Update(pas);
    }
}

void FenPrincipale::arreterSimulation()
{
    /*scene->removeItem(terreEllipse);
    scene->removeItem(jupiterEllipse);
    scene->removeItem(saturneEllipse);
    scene->removeItem(uranusEllipse);*/
    scene->removeItem(soleil);
    scene->removeItem(terre);
    scene->removeItem(jupiter);
    scene->removeItem(saturne);
    scene->removeItem(uranus);
    scene->removeItem(sonde);
    progressBar->setValue(0);
    vitesseSondeLabel->clear();
    timer->stop();
    delete timer;
    delete terreEllipse;
    delete jupiterEllipse;
    delete saturneEllipse;
    delete uranusEllipse;
    delete animationSoleil;
    delete animationTerre;
    delete animationJupiter;
    delete animationSaturne;
    delete animationUranus;
    delete animationSonde;
    delete astres;
    delete ssonde;
    delete vitesseSonde;
}

void FenPrincipale::getVitSonde(int i)
{
    int nbEtape = fenetrePreferences->getNbrEtapes();
    vitesseSondeLabel->setText(QString("Vitesse de la sonde = ")+QString::number(vitesseSonde[i*nbEtape/100]));
}
