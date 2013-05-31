/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/

//The headers
#include "Utility.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Timer.h"
#include "Particle.h"
#include "Dot.h"
#include <string>
#include <cstdlib>
#include "block.h"
#define PI 3.14159265
#include <list>
#include "BlockSlow.h"
#include "BlockNormal.h"
#include "Paddle.h"
#include "BlockBigPaddle.h"
#include "SuperBlock.h"
#include "BlockPunishDot.h"
#include "Menu.h"
#include "BlockFast.h"

using namespace std;
//The surfaces

const int SCREEN_BPP = 32;

//The surfaces
SDL_Surface *screen = NULL;

//The event structure
SDL_Event event;

bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }

    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;
    }
    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //If there was an error in setting up the screen
    if( screen == NULL )
    {
        return false;
    }

    //Set the window caption
    SDL_WM_SetCaption( "Semana 5", NULL );

    //Seed random
    srand( SDL_GetTicks() );

    //If everything initialized fine
    return true;
}

void clean_up()
{
    SDL_Quit();
}

int main( int argc, char* args[] )
{
    //Quit flag
    bool quit = false;

    //The frame rate regulator
    Timer fps;

    //Initialize
    if( init() == false )
    {
        return 1;
    }

    Mix_Chunk *pantalla = Mix_LoadWAV( "pantalla.wav" );

    //The dot that will be used
    Dot myDot(screen);

    list <Block*> block_list;
    //Images
    SDL_Surface *paddle_image = load_image("paddle.png");
    SDL_Surface *block_big_paddle = load_image("blockBigPaddle.png");
    SDL_Surface *big_paddle_image = load_image("bigPaddle.png");
    SDL_Surface *block_image = load_image("block.png");
    SDL_Surface *block_slow_image = load_image("blockSlow.png");
    SDL_Surface *super_block_image = load_image("superBlock.png");
    SDL_Surface *block_punisch_dot_image = load_image("blockPunishDot.png");
    SDL_Surface *block_fast_image = load_image("blockFast.png");

    Paddle *paddle = new Paddle(320,576,100,25,paddle_image,screen,&myDot);

    Block *block1 = new BlockNormal(130,50,100,25,block_image,screen,&myDot);
    Block *block2 = new BlockSlow(231,50,100,25,block_slow_image,screen,&myDot);
    Block *block3 = new BlockBigPaddle(332,50,100,25,block_big_paddle,screen,&myDot);
    Block *block4 = new SuperBlock(433,50,100,25,super_block_image,screen,&myDot);
    Block *block5 = new BlockPunishDot(534,50,100,25,block_punisch_dot_image,screen,&myDot);
    Block *block6 = new BlockNormal(635,50,100,25,block_image,screen,&myDot);

    Block *block7 = new BlockNormal(30,76,100,25,block_image,screen,&myDot);
    Block *block8 = new BlockSlow(30,102,100,25,block_slow_image,screen,&myDot);
    Block *block9 = new BlockNormal(30,128,100,25,block_image,screen,&myDot);
    Block *block10 = new BlockNormal(30,154,100,25,block_image,screen,&myDot);
    Block *block11 = new BlockBigPaddle(30,180,100,25,block_big_paddle,screen,&myDot);
    Block *block12 = new BlockNormal(30,206,100,25,block_image,screen,&myDot);
    Block *block13 = new BlockFast(30,232,100,25,block_fast_image,screen,&myDot);

    Block *block14 = new SuperBlock(130,308,100,25,super_block_image,screen,&myDot);
    Block *block15 = new BlockNormal(231,308,100,25,block_image,screen,&myDot);
    Block *block16 = new BlockNormal(332,308,100,25,block_image,screen,&myDot);
    Block *block17 = new BlockPunishDot(433,308,100,25,block_punisch_dot_image,screen,&myDot);
    Block *block18 = new BlockNormal(534,308,100,25,block_image,screen,&myDot);
    Block *block19 = new BlockNormal(635,308,100,25,block_image,screen,&myDot);

    Block *block20 = new BlockSlow(736,76,100,25,block_slow_image,screen,&myDot);
    Block *block21 = new BlockFast(736,102,100,25,block_fast_image,screen,&myDot);
    Block *block22 = new BlockNormal(736,128,100,25,block_image,screen,&myDot);
    Block *block23 = new BlockBigPaddle(736,154,100,25,block_big_paddle,screen,&myDot);
    Block *block24 = new BlockNormal(736,180,100,25,block_image,screen,&myDot);
    Block *block25 = new BlockNormal(736,206,100,25,block_image,screen,&myDot);
    Block *block26 = new BlockSlow(736,232,100,25,block_slow_image,screen,&myDot);

    Block *block27 = new BlockNormal(225,100,100,25,block_image,screen,&myDot);
    Block *block28 = new BlockNormal(425,100,100,25,block_image,screen,&myDot);
    Block *block29 = new BlockBigPaddle(232,190,100,25,block_big_paddle,screen,&myDot);
    Block *block30 = new BlockBigPaddle(332,216,100,25,block_big_paddle,screen,&myDot);
    Block *block31 = new BlockBigPaddle(432,190,100,25,block_big_paddle,screen,&myDot);

    block_list.push_back(block1);
    block_list.push_back(block2);
    block_list.push_back(block3);
    block_list.push_back(block4);
    block_list.push_back(block5);
    block_list.push_back(block6);
    block_list.push_back(block7);
    block_list.push_back(block8);
    block_list.push_back(block9);
    block_list.push_back(block10);
    block_list.push_back(block11);
    block_list.push_back(block12);
    block_list.push_back(block13);
    block_list.push_back(block14);
    block_list.push_back(block15);
    block_list.push_back(block16);
    block_list.push_back(block17);
    block_list.push_back(block18);
    block_list.push_back(block19);
    block_list.push_back(block20);
    block_list.push_back(block21);
    block_list.push_back(block22);
    block_list.push_back(block23);
    block_list.push_back(block24);
    block_list.push_back(block25);
    block_list.push_back(block26);
    block_list.push_back(block27);
    block_list.push_back(block28);
    block_list.push_back(block29);
    block_list.push_back(block30);
    block_list.push_back(block31);
    //Menu
    Menu menu(screen);
    menu.render();
    SDL_Flip(screen);
    Mix_PlayChannel( -1, pantalla, 5 );
    bool quite = false;
    while( quite == false )
    {
        //If there's an event to handle
        if( SDL_PollEvent( &event ) )
        {
            //If a key was pressed
            if( event.type == SDL_KEYDOWN )
            {
                //Set the proper message surface
                switch( event.key.keysym.sym )
                {
                    case SDLK_ESCAPE: quite = true; break;
                    case SDLK_0:
                        menu.setNumPantalla(0);
                        menu.render();
                        SDL_Flip(screen);
                        break;
                    case SDLK_1:
                        while( quit == false )
                        {
                                myDot.dotMoves();
                                paddle->logic();
                                paddle->control();

                                if (block3->life <= 0 || block11->life <=0 || block23->life <=0
                                    || block29->life <=0 || block30->life <=0 || block31->life <= 0)
                                {
                                    paddle->image = big_paddle_image;
                                    paddle->width = 170;
                                }

                                //Start the frame timer
                                fps.start();

                                //While there's events to handle
                                while( SDL_PollEvent( &event ) )
                                {
                                    //Handle events for the dot
                                    myDot.handle_input();

                                    //If the user has Xed out the window
                                    if( event.type == SDL_QUIT )
                                    {
                                        //Quit the program
                                        quit = true;
                                    }
                                }


                                //Move the dot
                                myDot.move();
                                if (myDot.life <= 0)
                                {
                                    menu.setNumPantalla(1);
                                    menu.render();
                                    SDL_Flip(screen);
                                    if( SDL_Flip( screen ) == -1 )
                                    {
                                        return 1;
                                    }

                                    SDL_Delay(2000);
                                    break;
                                }

                                list<Block*>::iterator block_iterator = block_list.begin();
                                while(block_iterator != block_list.end())
                                {
                                    Block* block_temp = *block_iterator;
                                    block_temp->logic();
                                    //((Block*)(*block_iterator))->logic();
                                    if (block_temp->life <= 0)
                                    {
                                        block_list.erase(block_iterator);
                                        block_iterator--;
                                    }
                                    block_iterator++;
                                }

                                //Fill the screen white
                                SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );

                                //Show the dot on the screen
                                myDot.show();
                                paddle->show();

                                block_iterator = block_list.begin();
                                while(block_iterator != block_list.end())
                                {
                                    Block* block_temp = *block_iterator;
                                    block_temp->show();
                                    block_iterator++;
                                }

                                //Update the screen
                                if( SDL_Flip( screen ) == -1 )
                                {
                                    return 1;
                                }

                                //Cap the frame rate
                                if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
                                {
                                    SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
                                }
                            }
                            break;
                    case SDLK_2:
                        menu.setNumPantalla(2);
                        menu.render();
                        SDL_Flip(screen);
                        break;
                    case SDLK_3:
                        quite = true;
                        break;
                }
            }
            //If the user has Xed out the window
            else if( event.type == SDL_QUIT )
            {
                //Quit the program
                 quite = true;
            }
        }



    //While the user hasn't quit
   /* while( quit == false )
    {
        if (menu.getActive())
        {
            menu.setNumPantalla(0);
            menu.render();
            SDL_Flip(screen);
        } else {
            myDot.dotMoves();
            paddle->logic();
            paddle->control();

            if (block3->life <= 0 || block11->life <=0 || block23->life <=0
                || block29->life <=0 || block30->life <=0 || block31->life <= 0)
            {
                paddle->image = big_paddle_image;
                paddle->width = 170;
            }

            //Start the frame timer
            fps.start();

            //While there's events to handle
            while( SDL_PollEvent( &event ) )
            {
                //Handle events for the dot
                myDot.handle_input();

                //If the user has Xed out the window
                if( event.type == SDL_QUIT )
                {
                    //Quit the program
                    quit = true;
                }
            }
        //}

            //Move the dot
            myDot.move();
            if (myDot.life <= 0)
            {
                apply_surface( 490, 100, game_over, screen );
                if( SDL_Flip( screen ) == -1 )
                {
                    return 1;
                }

                SDL_Delay(2000);
                break;
            }


            list<Block*>::iterator block_iterator = block_list.begin();
            while(block_iterator != block_list.end())
            {
                Block* block_temp = *block_iterator;
                block_temp->logic();
                //((Block*)(*block_iterator))->logic();
                if (block_temp->life <= 0)
                {
                    block_list.erase(block_iterator);
                    block_iterator--;
                }
                block_iterator++;
            }

            //Fill the screen white
            SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );

            //Show the dot on the screen
            myDot.show();
            paddle->show();

            block_iterator = block_list.begin();
            while(block_iterator != block_list.end())
            {
                Block* block_temp = *block_iterator;
                block_temp->show();
                block_iterator++;
            }

            //Update the screen
            if( SDL_Flip( screen ) == -1 )
            {
                return 1;
            }

            //Cap the frame rate
            if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
            {
                SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
            }
        }*/
    }

    //Clean up
    clean_up();

    return 0;



}
