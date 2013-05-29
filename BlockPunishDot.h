#ifndef BLOCKPUNISHDOT_H
#define BLOCKPUNISHDOT_H
#include "block.h"

class BlockPunishDot : public Block
{
    public:
        BlockPunishDot();
        BlockPunishDot(float x, float y, int width, int height,SDL_Surface *image,SDL_Surface *screen, Dot *dot);
        void logic();
        virtual ~BlockPunishDot();
    protected:
    private:
};

#endif // BLOCKPUNISHDOT_H
