#ifndef MENU_H
#define MENU_H

#include "SDL.h"
#include "SDL_image.h"
#include <string>
#include "SDL_mixer.h"
#include "SDL_ttf.h"


class Menu
{
    public:
        Menu();
        Menu(SDL_Surface * screen);
        void logic();
        void render();
        bool init();
        bool getActive();
        void setNumPantalla(int p);
        int getNumPantalla();
        virtual ~Menu();
    protected:
    private:
        int x;
        int numPantalla;
        bool active;
        SDL_Surface *image[3];
        SDL_Surface *screen;
};

#endif // MENU_H
