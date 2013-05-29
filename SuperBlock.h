#ifndef SUPERBLOCK_H
#define SUPERBLOCK_H
#include "block.h"


class SuperBlock : public Block
{
    public:
        SuperBlock();
        SuperBlock(float x, float y, int width, int height,SDL_Surface *image,SDL_Surface *screen, Dot *dot);
        void logic();
        virtual ~SuperBlock();
    protected:
    private:
};

#endif // SUPERBLOCK_H
