#ifndef BLOCKBIGPADDLE_H
#define BLOCKBIGPADDLE_H
#include "block.h"


class BlockBigPaddle : public Block
{
    public:
        BlockBigPaddle();
        BlockBigPaddle(float x, float y, int width, int height,SDL_Surface *image,SDL_Surface *screen, Dot *dot);
        void logic();

        virtual ~BlockBigPaddle();
    protected:
    private:
};

#endif // BLOCKBIGPADDLE_H
