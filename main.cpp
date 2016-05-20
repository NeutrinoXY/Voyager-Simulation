#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif
#include <iostream>
#include <fstream>
#include "Astre.h"
#include "Sonde.h"
#include <SDL/SDL.h>

#include <sstream>
#include <string>
#include <stdexcept>



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

int main ( int argc, char** argv )
{
    double a=0;
    double t=0, pas=0.00005, tampon=0, zoom=25, dmin=100, distance;

    Astre* astres = new Astre[5];
    astres[0].Definir(0);
    astres[1].Definir(3);
    astres[2].Definir(5);
    astres[3].Definir(6);
    astres[4].Definir(7);


    Sonde sonde(astres, 5);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ifstream fichier("donnees.txt", ios::in);  // on ouvre en lecture

    if(fichier)  // si l'ouverture a fonctionné
    {
        string ligne;
        while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
        {
            size_t found = ligne.find("zoom = ");
            if (found!=string::npos){
                ligne.erase(0,7);
                istringstream i(ligne);
                i >> zoom;
                cerr << "zoom modifié" << endl;
            }

                found = ligne.find("pas = ");
            if (found!=string::npos){
                ligne.erase(0,6);
                istringstream i(ligne);
                i >> pas;
                cerr << "pas modifié" << endl;
            }

                found = ligne.find("angleTerre = ");
            if (found!=string::npos){
                ligne.erase(0,13);
                istringstream i(ligne);
                i >> a;
                astres[1].Settheta0(a);
                cerr << "angle de la Terre modifié" << endl;
            }

                found = ligne.find("angleJupiter = ");
            if (found!=string::npos){
                ligne.erase(0,15);
                cerr << ligne << endl;
                a = strtod(ligne.c_str(), NULL);
                astres[2].Settheta0(a);
                cerr << "angle de Jupiter modifié " << endl;
            }

                found = ligne.find("angleSaturne = ");
            if (found!=string::npos){
                ligne.erase(0,15);
                istringstream i(ligne);
                i >> a;
                astres[3].Settheta0(a);
                cerr << "angle de Saturne modifié" << endl;
            }

                found = ligne.find("angleUranus = ");
            if (found!=string::npos){
                ligne.erase(0,14);
                istringstream i(ligne);
                i >> a;
                astres[4].Settheta0(a);
                cerr << "angle d'Uranus modifié" << endl;
            }

                found = ligne.find("positionX = ");
            if (found!=string::npos){
                ligne.erase(0,12);
                istringstream i(ligne);
                i >> a;
                sonde.SetX(0,0,a);
                cerr << "positionX modifié" << endl;
            }

                found = ligne.find("positionY = ");
            if (found!=string::npos){
                ligne.erase(0,12);
                istringstream i(ligne);
                i >> a;
                sonde.SetY(0,0,a);
                cerr << "positionY modifié" << endl;
            }

                found = ligne.find("vitesseX = ");
            if (found!=string::npos){
                ligne.erase(0,11);
                istringstream i(ligne);
                i >> a;
                sonde.SetX(1,0,a);
                cerr << "vitesseX modifié" << endl;
            }

                found = ligne.find("vitesseY = ");
            if (found!=string::npos){
                ligne.erase(0,11);
                istringstream i(ligne);
                i >> a;
                sonde.SetY(1,0,a);
                cerr << "vitesseY modifié" << endl;
            }
        }

        fichier.close();
    }
    else
            cerr << "Impossible d'ouvrir le fichier !" << endl;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    // initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Unable to init SDL: %s\n", SDL_GetError() );
        return 1;
    }

    // make sure SDL cleans up before exit
    atexit(SDL_Quit);

    // create a new window
    SDL_Surface* screen = SDL_SetVideoMode(1280, 1024, 32,
                                           SDL_HWSURFACE|SDL_DOUBLEBUF);
    if ( !screen )
    {
        printf("Unable to set 640x480 video: %s\n", SDL_GetError());
        return 1;
    }

    // load an image
    SDL_Surface* sondeBMP = SDL_LoadBMP("sonde.bmp");
    if (!sondeBMP)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Surface* soleil = SDL_LoadBMP("soleil.bmp");
    if (!soleil)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Surface* terre = SDL_LoadBMP("terre.bmp");
    if (!terre)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Surface* jupiter = SDL_LoadBMP("jupiter.bmp");
    if (!jupiter)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Surface* saturne = SDL_LoadBMP("saturne.bmp");
    if (!saturne)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
        return 1;
    }
    SDL_Surface* uranus = SDL_LoadBMP("uranus.bmp");
    if (!uranus)
    {
        printf("Unable to load bitmap: %s\n", SDL_GetError());
        return 1;
    }


    // centre the bitmap on screen
    SDL_Rect dstrect;
    SDL_Rect dstrect2;
    SDL_Rect dstrect3;
    SDL_Rect dstrect5;
    SDL_Rect dstrect6;
    SDL_Rect dstrect7;


    dstrect2.x = (screen->w - soleil->w) / 2;
    dstrect2.y = (screen->h - soleil->h) / 2;

  SDL_Delay(500);
    // program main loop
    bool done = false;
    while (!done){



        dstrect.x =   zoom*  sonde.GetX(0,0)+ (screen->w - sondeBMP->w) / 2;
        dstrect.y =   zoom*  sonde.GetY(0,0)+ (screen->h - sondeBMP->h) / 2;



        dstrect3.x = (screen->w - terre->w) / 2 +   zoom*  astres[1].GetX(0);
        dstrect3.y = (screen->h - terre->h) / 2 +   zoom*  astres[1].GetY(0);

        dstrect5.x = (screen->w - jupiter->w) / 2 +   zoom*  astres[2].GetX(0);
        dstrect5.y = (screen->h - jupiter->h) / 2 +   zoom*  astres[2].GetY(0);

        dstrect6.x = (screen->w - saturne->w) / 2 +   zoom*  astres[3].GetX(0);
        dstrect6.y = (screen->h - saturne->h) / 2 +   zoom*  astres[3].GetY(0);

        dstrect7.x = (screen->w - uranus->w) / 2 +   zoom*  astres[4].GetX(0);
        dstrect7.y = (screen->h - uranus->h) / 2 +   zoom*  astres[4].GetY(0);



        // message processing loop
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                done = true;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
                {
                    // exit if ESCAPE is pressed
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        done = true;
                    break;
                }
            } // end switch
        } // end of message processing

        // DRAWING STARTS HERE


        if(!((int)(t/pas)%600)){
            // clear screen
            SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));

            // draw bitmap
            SDL_BlitSurface(soleil,0, screen, &dstrect2);
            SDL_BlitSurface(terre, 0, screen, &dstrect3);
            SDL_BlitSurface(jupiter, 0, screen, &dstrect5);
            SDL_BlitSurface(saturne, 0, screen, &dstrect6);
            SDL_BlitSurface(uranus, 0, screen, &dstrect7);
            SDL_BlitSurface(sondeBMP, 0, screen, &dstrect);

            // finally, update the screen :)
            SDL_Flip(screen);

        }// DRAWING ENDS HERE


        t+=pas;
        for (int i=0; i<5; i++){
            astres[i].Update(t);
        }
        sonde.Update(pas);
    } // end main loop



    // free loaded bitmap
    SDL_FreeSurface(sondeBMP);
    SDL_FreeSurface(soleil);
    SDL_FreeSurface(terre);
    SDL_FreeSurface(jupiter);
    SDL_FreeSurface(saturne);
    SDL_FreeSurface(uranus);

    return 0;
}
