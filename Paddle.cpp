#include "Paddle.h"

Paddle::Paddle(float x, float y, int width, int height,SDL_Surface *image,SDL_Surface *screen, Dot *dot)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->screen = screen;
    this->image = image;
    this->dot = dot;
    this->isColliding = false;
    this->wasColliding = false;
    this->life = 2;
    this->time = 0;
}

Paddle::~Paddle()
{
    //dtor
}

void Paddle::logic()
{
    int collision = collisionType();
        if(!wasColliding)
        {
            switch(collision){
            case 0:
            break;

            case TOP:
                dot->angle = -dot->angle;
                dot->angle += rand()%10 - 20;
                break;
            case BOT:
                dot->angle = -dot->angle;
                dot->angle += rand()%10 - 20;
                break;

            case RIGHT: case LEFT:
                dot->angle = -dot->angle+180;
                dot->angle += rand()%10 - 20;
                break;
             case CORNERUL:
                 dot->velocity = abs(dot->velocity);
                 dot->angle = 315;
                 dot->angle += rand()%5-10;
                 break;
            case CORNERUR:
                dot->velocity = abs(dot->velocity);
                 dot->angle = 225;
                 dot->angle += rand()%5-10;
                 break;
            case CORNERDR:
                dot->velocity = abs(dot->velocity);
                 dot->angle = 135;
                 dot->angle += rand()%5-10;
                 break;
            case CORNERDL:
                dot->velocity = abs(dot->velocity);
                 dot->angle = 45;
                 dot->angle += rand()%5-10;
            }
    }
}

void Paddle::control()
{
    Uint8 *keystates = SDL_GetKeyState( NULL );
    if( keystates[ SDLK_LEFT ] && x >=0  )
        x-=5;

        //If right is pressed
    if( keystates[ SDLK_RIGHT ] && x <= 730  && width >= 170 )
        x+=5;
    else if( keystates[ SDLK_RIGHT ] && x <= 800 && width <= 100){
         x+=5;
    }


}
