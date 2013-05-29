#ifndef PADDLE_H
#define PADDLE_H
#include "block.h"


class Paddle : public Block
{
    public:
        Paddle();
        Paddle(float x, float y, int width, int height,SDL_Surface *image,SDL_Surface *screen, Dot *dot);
        void logic();
        void control();
        virtual ~Paddle();
    protected:
    private:
};

#endif // PADDLE_H
