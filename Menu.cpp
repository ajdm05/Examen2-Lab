#include "Menu.h"


Menu::~Menu()
{
    SDL_FreeSurface( image[0] );
    SDL_FreeSurface( image[1] );
    SDL_FreeSurface( image[2] );
}

#include <string>

Menu::Menu(SDL_Surface *screen)
{
    this->screen = screen;
    this->image[0] = IMG_Load( "Menu.png" );
    this->image[1] = IMG_Load( "game-over.png" );
    this->image[2] = IMG_Load( "Info.png" );
    this->x = 0;
    this->numPantalla = 0;
    this->active = true;
}

void Menu::render()
{
    SDL_Rect offset;

    if (this->getNumPantalla() == 0){

        offset.x = 0;
        offset.y = 0;

        SDL_BlitSurface( image[0], NULL, screen, &offset );
    }

    if (this->getNumPantalla() == 1)
    {

        SDL_BlitSurface( image[1], NULL, screen, &offset );

        offset.x = 0;
        offset.y = 0;

        SDL_BlitSurface( image[1], NULL, screen, &offset );

    }
    if (this->getNumPantalla() == 2)
    {
        SDL_BlitSurface( image[2], NULL, screen, &offset );

        offset.x = 0;
        offset.y = 0;

        SDL_BlitSurface( image[2], NULL, screen, &offset );
    }

}

void Menu::setNumPantalla(int p)
{
    this->numPantalla = p;
}

bool Menu::getActive()
{
    return this->active;
}

int Menu::getNumPantalla()
{
    return this->numPantalla;
}
