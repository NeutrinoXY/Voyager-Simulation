#ifndef HEADER_FENPRINCIPALE
#define HEADER_FENPRINCIPALE

#include <QtWidgets>

class FenPrincipale : public QMainWindow
{
    Q_OBJECT
    public:
    FenPrincipale();
    ~FenPrincipale();

    public slots:
    void ouvrirFenetrePreferences();
    void ouvrirFenetreAPropos();
    void ouvrirFenetreSimulation();

    private:



};
#endif
