#include "BlockSlow.h"

BlockSlow::BlockSlow(float x, float y, int width, int height,SDL_Surface *image,SDL_Surface *screen, Dot *dot){
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

BlockSlow::~BlockSlow()
{
    //dtor
}

void BlockSlow::logic()
{
    this->time++;

    /*if (this->time%60 == 0)
    {
        this->x+=10;
        this->time = 0;
    }*/
    int collision = collisionType();
        if(!wasColliding){
        switch(collision){
        case 0:
        break;

        case TOP:
            dot->angle = -dot->angle;
            dot->angle += rand()%10 - 20;
            this->life--;
            break;
        case BOT:
            dot->angle = -dot->angle;
            dot->angle += rand()%10 - 20;
            this->life--;
            break;

        case RIGHT: case LEFT:
            dot->angle = -dot->angle+180;
            dot->angle += rand()%10 - 20;
            this->life--;
            break;
         case CORNERUL:
             dot->velocity = abs(dot->velocity);
             dot->angle = 315;
             dot->angle += rand()%5-10;
             this->life--;
             break;
        case CORNERUR:
            dot->velocity = abs(dot->velocity);
             dot->angle = 225;
             dot->angle += rand()%5-10;
             this->life--;
             break;
        case CORNERDR:
            dot->velocity = abs(dot->velocity);
             dot->angle = 135;
             dot->angle += rand()%5-10;
             this->life--;
             break;
        case CORNERDL:
            dot->velocity = abs(dot->velocity);
             dot->angle = 45;
             dot->angle += rand()%5-10;
             this->life--;
        }

        if (this->life <=0)
        {
            dot->velocity/=2;
        }

    }
}
