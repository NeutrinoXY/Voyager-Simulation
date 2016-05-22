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

void cercle(long const rayon, long const x, long const y, SDL_Surface *const ecran)
{
   double const pi = 3.141592;
   double const pixels = pi*2*rayon;
   double compteur = 0.0;
   long coups = 0;
   SDL_Rect position = {
                          0
                       };

   while (coups < pixels)
   {
      SDL_Surface *rectangle = SDL_CreateRGBSurface (SDL_HWSURFACE,1,1,32,0,0,0,0);
      if (rectangle != NULL)
      {
         SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
         position.x = x+rayon* cos(compteur * pi / 180);
         position.y = y+rayon* sin(compteur * pi / 180);
         SDL_BlitSurface(rectangle, NULL, ecran, &position);
         SDL_FreeSurface(rectangle), rectangle = NULL;
      }

      compteur += 360/pixels;
      coups ++;
   }
}


int main ( int argc, char** argv )
{
    int C=0, I=0;
    double t=0, pas0, pas=0.00005, tampon=0, zoom=25, zoom0=25, dmin=100, distance, a;
    double ancienX=0, ancienY=0, taille=10;

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
                i >> zoom0;
                cerr << "zoom0 modifié" << endl;
            }

                found = ligne.find("pas = ");
            if (found!=string::npos){
                ligne.erase(0,6);
                istringstream i(ligne);
                i >> pas0;
                pas=pas0;
                cerr << "pas0 modifié" << endl;
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

    SDL_Surface *rectangle = NULL;
    SDL_Rect position;
    SDL_Rect trajectoire[2000];
    SDL_Rect approximation[500];

    for(int i=0;i<100;i++){
        trajectoire[i].x=10000000;
        trajectoire[i].y=10000000;
    }

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


    rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, 2, 2, 32, 0, 0, 0, 0);


    // centre the bitmap on screen
    SDL_Rect dstrect;
    SDL_Rect dstrect2;
    SDL_Rect dstrect3;
    SDL_Rect dstrect5;
    SDL_Rect dstrect6;
    SDL_Rect dstrect7;




    SDL_Delay(500);


    // program main loop
    bool done = false;
    while (!done){


        I++;
        distance = sqrt(pow(sonde.GetX(0,0)-astres[2].GetX(0),2) + pow(sonde.GetY(0,0)-astres[2].GetY(0),2));
        C = 50*(2-distance);
        if(C<0) C=0;
        else if(C>50) C=50;
        else {
            //if(!(I%(100-C))) SDL_Delay(1);
        }

        C*=2;

        pas=pas0/(2-distance);
        if(pas>pas0) pas=pas0;
        if(pas<0) pas=pas0;

        zoom = 50*zoom0*pow(1.2-distance,3);
        if(zoom<zoom0) zoom=zoom0;

        if(!(I%3000)&&I/3000<2000){
            trajectoire[I/3000].x=sonde.GetX(0,0)*1000;
            trajectoire[I/3000].y=sonde.GetY(0,0)*1000;
            taille++;
        }

        double x=sonde.GetX(0,0), X=sonde.GetX(1,0), XX=(X-ancienX)/pas, y=sonde.GetY(0,0), Y=sonde.GetY(1,0), YY=(Y-ancienY)/pas;
        ancienX=X;
        ancienY=Y;
        for(int i=0; i<500; i++){
            approximation[i].x=1000*(x+i*X/80+i*i*XX/13500);
            approximation[i].y=1000*(y+i*Y/80+i*i*YY/13500);
        }









        dstrect.x = screen->w/2 - zoom*  C*sonde.GetX(0,0)/100.0 - sondeBMP->w/2 + zoom*  sonde.GetX(0,0);
        dstrect.y = screen->h/2 - zoom*  C*sonde.GetY(0,0)/100.0 - sondeBMP->h/2 + zoom*  sonde.GetY(0,0);

        dstrect2.x = screen->w/2 - zoom*  C*sonde.GetX(0,0)/100.0 - soleil->w/2;
        dstrect2.y = screen->h/2 - zoom*  C*sonde.GetY(0,0)/100.0 - soleil->h/2;

        dstrect3.x = screen->w/2 - zoom*  C*sonde.GetX(0,0)/100.0 - terre->w/2 +   zoom*  astres[1].GetX(0);
        dstrect3.y = screen->h/2 - zoom*  C*sonde.GetY(0,0)/100.0 - terre->h/2 +   zoom*  astres[1].GetY(0);

        dstrect5.x = screen->w/2 - zoom*  C*sonde.GetX(0,0)/100.0 - jupiter->w/2 +   zoom*  astres[2].GetX(0);
        dstrect5.y = screen->h/2 - zoom*  C*sonde.GetY(0,0)/100.0 - jupiter->h/2 +   zoom*  astres[2].GetY(0);

        dstrect6.x = screen->w/2 - zoom*  C*sonde.GetX(0,0)/100.0 - saturne->w/2 +   zoom*  astres[3].GetX(0);
        dstrect6.y = screen->h/2 - zoom*  C*sonde.GetY(0,0)/100.0 - saturne->h/2 +   zoom*  astres[3].GetY(0);

        dstrect7.x = screen->w/2 - zoom*  C*sonde.GetX(0,0)/100.0 - uranus->w/2 +   zoom*  astres[4].GetX(0);
        dstrect7.y = screen->h/2 - zoom*  C*sonde.GetY(0,0)/100.0 - uranus->h/2 +   zoom*  astres[4].GetY(0);


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

            cercle(zoom*astres[1].Getradius(), dstrect2.x + soleil->w/2, dstrect2.y + soleil->w/2, screen);
            cercle(zoom*astres[2].Getradius(), dstrect2.x + soleil->w/2, dstrect2.y + soleil->w/2, screen);
            cercle(zoom*astres[3].Getradius(), dstrect2.x + soleil->w/2, dstrect2.y + soleil->w/2, screen);
            cercle(zoom*astres[4].Getradius(), dstrect2.x + soleil->w/2, dstrect2.y + soleil->w/2, screen);


            // draw bitmap
            SDL_BlitSurface(soleil,0, screen, &dstrect2);
            SDL_BlitSurface(terre, 0, screen, &dstrect3);
            SDL_BlitSurface(saturne, 0, screen, &dstrect6);
            SDL_BlitSurface(jupiter, 0, screen, &dstrect5);
            SDL_BlitSurface(uranus, 0, screen, &dstrect7);
            SDL_BlitSurface(sondeBMP, 0, screen, &dstrect);



            SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 200, 100, 255));

            for(int i=0;i<2000;i++){
                if(i>taille) i=2000;
                position.x=screen->w/2 - zoom*  C*sonde.GetX(0,0)/100.0 - 1 + zoom*  trajectoire[i].x/1000.0;
                position.y=screen->h/2 - zoom*  C*sonde.GetY(0,0)/100.0 - 1 + zoom*  trajectoire[i].y/1000.0;

                SDL_BlitSurface(rectangle, NULL, screen, &position); // Collage de la surface sur l'écran
            }


            SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 100, 255, 200));

            for(int i=0;i<500;i++){
                position.x=screen->w/2 - zoom*  C*sonde.GetX(0,0)/100.0 - 1 + zoom*  approximation[i].x/1000.0;
                position.y=screen->h/2 - zoom*  C*sonde.GetY(0,0)/100.0 - 1 + zoom*  approximation[i].y/1000.0;

                SDL_BlitSurface(rectangle, NULL, screen, &position); // Collage de la surface sur l'écran
            }

            SDL_FillRect(rectangle, NULL, SDL_MapRGB(screen->format, 255, 0, 0));
            position.x = screen->w/2 - zoom*  C*sonde.GetX(0,0)/100.0 - 2 +   zoom*  sonde.GetX(0,0);
            position.y = screen->h/2 - zoom*  C*sonde.GetY(0,0)/100.0 - 2 +   zoom*  sonde.GetY(0,0);
            SDL_BlitSurface(rectangle, NULL, screen, &position); // Collage de la surface sur l'écran

            position.x = screen->w/2 - zoom*  C*sonde.GetX(0,0)/100.0 - 2 +   zoom*  astres[2].GetX(0);
            position.y = screen->h/2 - zoom*  C*sonde.GetY(0,0)/100.0 - 2 +   zoom*  astres[2].GetY(0);
            SDL_BlitSurface(rectangle, NULL, screen, &position); // Collage de la surface sur l'écran


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
