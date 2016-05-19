#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif
#include <iostream>
#include "Astre.h"
#include "Sonde.h"
#include <SDL/SDL.h>

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

int main ( int argc, char** argv )
{

    int a=0;
    double t=0, pas=0.0001;

    Astre* astres = new Astre[5];
    astres[0].Definir(0);
    astres[1].Definir(3);
    astres[2].Definir(5);
    astres[3].Definir(6);
    astres[4].Definir(7);


    Sonde sonde(astres, 1);
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

    // load an image
    SDL_Surface* bmp = SDL_LoadBMP("planete.bmp");
    if (!bmp)
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

    SDL_Surface* voyager = SDL_LoadBMP("sonde.bmp");
    if (!bmp)
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

  SDL_Delay(2000);
    // program main loop
    bool done = false;
    while (!done){

        dstrect.x =   ZOOM*  sonde.GetX(0,0)+ (screen->w - bmp->w) / 2;
        dstrect.y =   ZOOM*  sonde.GetY(0,0)+ (screen->h - bmp->h) / 2;




        dstrect3.x = (screen->w - bmp->w) / 2 +   ZOOM*  astres[1].GetX(0);
        dstrect3.y = (screen->h - bmp->h) / 2 +   ZOOM*  astres[1].GetY(0);

        dstrect5.x = (screen->w - bmp->w) / 2 +   ZOOM*  astres[2].GetX(0);
        dstrect5.y = (screen->h - bmp->h) / 2 +   ZOOM*  astres[2].GetY(0);

        dstrect6.x = (screen->w - bmp->w) / 2 +   ZOOM*  astres[3].GetX(0);
        dstrect6.y = (screen->h - bmp->h) / 2 +   ZOOM*  astres[3].GetY(0);

        dstrect7.x = (screen->w - bmp->w) / 2 +   ZOOM*  astres[4].GetX(0);
        dstrect7.y = (screen->h - bmp->h) / 2 +   ZOOM*  astres[4].GetY(0);



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


        if(!((int)(t/pas)%60))
        {
            // clear screen
            SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));

            // draw bitmap
            SDL_BlitSurface(soleil,0, screen, &dstrect2);
            SDL_BlitSurface(voyager, 0, screen, &dstrect);
            SDL_BlitSurface(bmp, 0, screen, &dstrect3);
            SDL_BlitSurface(bmp, 0, screen, &dstrect5);
            SDL_BlitSurface(bmp, 0, screen, &dstrect6);
            SDL_BlitSurface(bmp, 0, screen, &dstrect7);

            // finally, update the screen :)
            SDL_Flip(screen);

        }// DRAWING ENDS HERE


        t+=pas;
        for (int i=0; i<5; i++)
        {
            astres[i].Update(t);
        }
        sonde.Update(pas);
    } // end main loop

    // free loaded bitmap
    SDL_FreeSurface(bmp);
    SDL_FreeSurface(soleil);

    return 0;
}
