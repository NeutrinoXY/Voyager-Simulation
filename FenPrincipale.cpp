#include "FenPrincipale.h"
#include "FenPreferences.h"
#include "FenSimu.h"
#define HAUTEUR 1080
#define LARGEUR 1920
#define ZOOM 25


/***************************************/
/*                                     */
/*                                     */
/*                                     */
/*   PLANETES ACTIVES :                */
/*       0 ,3, 5, 6, 7                 */
/*                                     */
/*                                     */
/*                                     */
/***************************************/
void delay(int n)
{
    QTime dieTime= QTime::currentTime().addSecs(n);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

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
    connect(actionExecuter,SIGNAL(triggered()), this, SLOT(ouvrirFenetreSimulation()));

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


    //zone centrale
      QWidget *zoneCentrale = new QWidget;
      QLayout *layout = new QVBoxLayout();
      QPixmap image;

      double t=0, pas=0.0001;

      Astre* astres = new Astre[5];
      astres[0].Definir(0);
      astres[1].Definir(3);
      astres[2].Definir(5);
      astres[3].Definir(6);
      astres[4].Definir(7);


      Sonde sonde(astres, 1);

      // load an image
      //QGraphicsItem *jupiter;
     // image.load("jupiter.bmp", 0, Qt::AutoColor);
      //jupiter = scene->addPixmap(image);

      /*QGraphicsItem *saturne;
      image.load("saturne.bmp", 0, Qt::AutoColor);
      saturne = scene->addPixmap(image);

      QGraphicsItem *uranus;
      image.load("uranus.bmp", 0, Qt::AutoColor);
      uranus = scene->addPixmap(image);

      QGraphicsItem *sde;
      image.load("sonde.bmp", 0, Qt::AutoColor);
      sde = scene->addPixmap(image);

      QGraphicsItem *soleil;
      image.load("soleil.bmp", 0, Qt::AutoColor);
      soleil = scene->addPixmap(image);*/
    
    QGraphicsPixmapItem *jupiter = new QGraphicsPixmapItem(*(new QPixmap("jupiter.bmp")));
      QTimeLine *timer = new QTimeLine(5000);
      timer->setFrameRange(0,100);

      QGraphicsItemAnimation * animation = new QGraphicsItemAnimation;
      animation ->setItem(jupiter);
      animation ->setTimeLine(timer);

      for(int i=0; i<200; i++){
          animation->setPosAt(i/200.0, QPointF(astres[2].GetX(0),astres[2].GetY(0) ));
         // astres[i].Update(t);
      }

      QGraphicsScene *scene;
      scene->setSceneRect(0,0,1280,720);
      jupiter = scene->addPixmap(image);
      scene->addItem(jupiter);

      QGraphicsView *view = new QGraphicsView(scene);
      view->show();

      timer->start();

      view->setScene(scene);
      layout->addWidget(view);
      zoneCentrale->setLayout(layout);
      setCentralWidget(zoneCentrale);

      //delay(2);

      // program main loop

          // DRAWING STARTS HERE

          /*if(!((int)(t/pas)%60))
          {
              // move bitmap
              //sde->setPos(ZOOM*  sonde.GetX(0,0)+ (LARGEUR - 3) / 2, ZOOM*  sonde.GetY(0,0)+ (HAUTEUR - 3) / 2);
              //soleil->setPos((LARGEUR - 3) / 2 +   ZOOM*  astres[0].GetX(0), (HAUTEUR - 3) / 2 +   ZOOM*  astres[0].GetY(0));

              //jupiter->setPos((LARGEUR - 3) / 2 +   ZOOM*  astres[2].GetX(0), (HAUTEUR - 3) / 2 +   ZOOM*  astres[2].GetY(0));
              //saturne->setPos((LARGEUR - 3) / 2 +   ZOOM*  astres[3].GetX(0), (HAUTEUR - 3) / 2 +   ZOOM*  astres[3].GetY(0));
             // uranus->setPos((LARGEUR - 3) / 2 +   ZOOM*  astres[4].GetX(0), (HAUTEUR - 3) / 2 +   ZOOM*  astres[4].GetY(0));

          }
          t+=pas;
          for (int i=0; i<5; i++)
          {
              astres[i].Update(t);
          }
          sonde.Update(pas);




      } // end main loop
*/










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
    QMessageBox::information(this, "A propos", "Logiciel développé par : Gaëtan Cavaillès, Antoine Delbèque, Delphine Guiblin et Francis Shih");
}

void FenPrincipale::ouvrirFenetreSimulation()
{
   /*     FenSimu *fenetreSimulation = new FenSimu;
        fenetreSimulation->setWindowIcon(QIcon("play"));
        fenetreSimulation->show();*/

}


