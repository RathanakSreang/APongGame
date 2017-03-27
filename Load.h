#ifndef LOAD_H
#define LOAD_H

#include"myHeader.h"
bool load_file()
{
     Bstar=load_image("Photo/button/startb.png");
     BOp=load_image("Photo/button/option.png");
     BIn=load_image("Photo/button/int.png");
     BHe=load_image("Photo/button/help.png");
     BQu=load_image("Photo/button/quit.png");

    pic=load_image("Photo/Background.png");
    pic1=load_image("Photo/MoneyThree.png");//100riel
    pic2=load_image("Photo/PlayerMoney.png");//Money
    pic3=load_image("Photo/Money two.png");//100riels

    //start=load_image("Photo/start1.png");
    home=load_image("Photo/Main Background.png");
    //gohome=load_image("Photo/Home.png");
    BHome=load_image("Photo/button/Home1.png");
    BExchang=load_image("Photo/button/ExchangButton.png");
    Bscrol=load_image("Photo/button/Scroll Point.png");

    MonExchang=load_image("Photo/Money Exchang.jpg");
    ExchangHead=load_image("Photo/Header choose money.png");
    ExchangBotton=load_image("Photo/Footer choose money.png");
    OptionB=load_image("Photo/option form1.png");
    CheckB=load_image("Photo/button/CheckButton.png");
    CheckOver=load_image("Photo/button/overcheck.png");
    ExitCheck=load_image("Photo/button/Ok.png");
    Quitform=load_image("Photo/Quit Progam.png");
    OverNo=load_image("Photo/button/OverNo.png");
    OverYes=load_image("Photo/button/OverYes.png");
    AboutG=load_image("Photo/About Game.png");
    InstructionG=load_image("Photo/Instruction Form.png");
    ExitAbout=load_image("Photo/button/Exit Button.png");
    Next=load_image("Photo/button/Next.png");
    Previouse=load_image("Photo/button/Previouse.png");
    //ExitChoiceMon=load_image("Photo/button/Exit Button.png");
    MoneyExSelect=load_image("Photo/Money Box.png");
    MoneyOver=load_image("Photo/overMoney.png");
    MonLock=load_imageColorKeyBlack("Photo/button/Lock.png");
    //Skip=load_image("Photo/button/skip button.png");
    //OverSkip=load_image("Photo/button/over skip button.png");
    //Usercreate=load_image("Photo/button/Create user button.png");
    if(pic==NULL||pic1==NULL||pic2==NULL||pic3==NULL||home==NULL)//||gohome==NULL)
        return false;
    if(InstructionG==NULL||Bstar==NULL||BOp==NULL||BIn==NULL||BHe==NULL||BQu==NULL||BExchang==NULL)
    return false;
    if(MonLock==NULL||MonExchang==NULL||ExchangHead==NULL||ExchangBotton==NULL||Bscrol==NULL||OptionB==NULL||CheckB==NULL||CheckOver==NULL||ExitCheck==NULL)
    return false;
    if(Quitform==NULL||OverNo==NULL||OverYes==NULL||AboutG==NULL||Next==NULL||Previouse==NULL)
    return false;
    if(MoneyExSelect==NULL||MoneyOver==NULL)
    return false;
    font = TTF_OpenFont( "font/Time New.ttf", 20 );
    fontsmall = TTF_OpenFont( "font/Time New.ttf", 18 );
    kfont = TTF_OpenFont( "font/Lmnf1.ttf", 36 );
    fontsupersmall=TTF_OpenFont( "font/Time New.ttf", 14 );
    if(font==NULL||kfont==NULL||fontsmall==NULL||fontsupersmall==NULL)
        return false;
    Plat1=load_imageColorKeyApong("Photo/plat piont 1.png");
    Plat2=load_imageColorKeyApong("Photo/plat piont 2.png");
    Plat3=load_imageColorKeyApong("Photo/plat piont 3.png");
    Plat4=load_imageColorKeyApong("Photo/plat piont 4.png");
    Plat5=load_imageColorKeyApong("Photo/plat piont 5.png");
    Plat6=load_imageColorKeyApong("Photo/plat piont 6.png");
    ResultPic=load_imageColorKeyApong("Photo/Result.png");
    ScrolPower=load_image("Photo/ScrolPower.png");
    Cpower=load_image("Photo/power.png");
    Cover=load_imageColorKeyApong("Photo/cover.png");

    if(ResultPic==NULL||Cpower==NULL||ScrolPower==NULL||Plat1==NULL||Plat2==NULL||Plat3==NULL||Plat4==NULL||Plat5==NULL||Plat6==NULL||Cover==NULL)
        return false;
    ApongSleep=load_imageColorKeyApong("Photo/12 Plat.png");
    frontApong=load_imageColorKey("Photo/button/Front.png");
    reaeApong=load_imageColorKey("Photo/button/Rear.png");
    OverfrontApong=load_imageColorKey("Photo/button/OverFront.png");
    OverreaeApong=load_imageColorKey("Photo/button/OverRear.png");

    loadingPic=load_image("Photo/Loading.png");
    loadingKey=load_imageColorKeyBlack("Photo/load.png");
    if(ApongSleep==NULL||frontApong==NULL||reaeApong==NULL||OverfrontApong==NULL||OverreaeApong==NULL||loadingKey==NULL||loadingPic==NULL)
        {
            return false;
        }
        for(int i=0;i<12;i++)sound1[i]=NULL;
        //loadingSound=NULL;

        //loadingSound=Mix_LoadWAV("Sound/mouse over.wav");
        sound1[0] = Mix_LoadWAV("Sound/1one.wav");
        sound1[1] = Mix_LoadWAV( "Sound/2two.wav" );
        sound1[2] = Mix_LoadWAV( "Sound/3three.wav" );
        sound1[3] = Mix_LoadWAV( "Sound/4four.wav" );
        sound1[4] = Mix_LoadWAV( "Sound/5five.wav" );
        sound1[5] = Mix_LoadWAV( "Sound/6six.wav" );
        sound1[6] = Mix_LoadWAV( "Sound/one1.wav" );
        sound1[7] = Mix_LoadWAV( "Sound/two2.wav" );
        sound1[8] = Mix_LoadWAV( "Sound/three3.wav" );
        sound1[9] = Mix_LoadWAV( "Sound/four4.wav" );
        sound1[10] = Mix_LoadWAV( "Sound/five5.wav" );
        sound1[11] = Mix_LoadWAV( "Sound/six6.wav" );
        //if(loadingSound==NULL)return false;
        for(int i=0;i<12;i++)
        if(sound1[i]==NULL){
            return false;
        }

    return true;
}
bool decl()
{
    if(SDL_Init(SDL_INIT_EVERYTHING)==-1)
        return false;
    screen=SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_SWSURFACE);//SDL_SWSURFACE,SDL_FULLSCREEN
    if(screen==NULL)
        return false;
    if(TTF_Init()==-1)
        return false;
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;
    }
    return true;
}
int my_thread( void *data)
{
    //While the program is not over
    while( 1 )
    {
        //Do the caption animation
        SDL_WM_SetCaption("Game Khmer Programing\"Apong Game.",NULL);
        SDL_Delay( 250 );

        SDL_WM_SetCaption("Game Khmer Programing\"Apong Game..",NULL);
        SDL_Delay( 250 );

        SDL_WM_SetCaption("Game Khmer Programing\"Apong Game....",NULL);
        SDL_Delay( 250 );

        SDL_WM_SetCaption("Game Khmer Programing\"Apong Game........",NULL);
        SDL_Delay( 250 );
    }

    return 0;
}
void MessageGame(int x,int y, std::string s,TTF_Font *Ffont, SDL_Color TColor)
{
    message = TTF_RenderText_Solid( Ffont,s.c_str(), TColor );
                set_display(x,y,message,screen);
}
#endif
