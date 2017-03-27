#ifndef MYHEADER_H
#define MYHEADER_H

#include "SDL_mixer.h"
#include<sdl_image.h>
#include<sdl_ttf.h>
#include<iostream>
#include<conio.h>
#include "SDL_thread.h"
#include<sdl.h>
#include<sdl_image.h>
#include<sstream>
#include<windows.h>
 const int RIELS=1,USAs=2;
SDL_Event even;
SDL_Thread *thread = NULL;
int x=0,y,boxx=2,boxy=0;
 static int xpre,ypre;
    SDL_Surface* BOp=NULL;
    SDL_Surface* BIn=NULL;
    SDL_Surface* BHe=NULL;
    SDL_Surface* BQu=NULL;
    SDL_Surface* BExchang=NULL;
    SDL_Surface* MonExchang=NULL;
    SDL_Surface* MonLock=NULL;
    SDL_Surface* BCreate=NULL;
    SDL_Surface* ExchangHead=NULL;
    SDL_Surface* ExchangBotton=NULL;
    SDL_Surface* BNoExit=NULL;
    SDL_Surface* Bscrol=NULL;
    SDL_Surface* Usercreate=NULL;
    SDL_Surface* Bstar=NULL;
    SDL_Surface* OptionB=NULL;
    SDL_Surface* CheckB=NULL;
    SDL_Surface* CheckOver=NULL;
    SDL_Surface* ExitCheck=NULL;
    SDL_Surface* OverNo=NULL;
    SDL_Surface* OverYes=NULL;
    SDL_Surface* Quitform=NULL;
    SDL_Surface* AboutG=NULL;
    SDL_Surface* InstructionG=NULL;
    SDL_Surface* ExitAbout=NULL;
    SDL_Surface* ResultPic=NULL;
    SDL_Surface* Next=NULL;
    SDL_Surface* Previouse=NULL;
    SDL_Surface* BHome=NULL;
    //SDL_Surface* gohome=NULL;
    SDL_Surface* home=NULL;
    SDL_Surface* pic=NULL;
    SDL_Surface* pic1=NULL;
    SDL_Surface* pic2=NULL;//[20];
    SDL_Surface* pic3=NULL;//[20];
    //SDL_Surface* start=NULL;
    SDL_Surface* screen=NULL;
    SDL_Surface* message=NULL;
    SDL_Surface* MoneyExSelect=NULL;
    SDL_Surface* MoneyOver=NULL;
   // SDL_Surface* Skip=NULL;
   // SDL_Surface* OverSkip=NULL;
    SDL_Rect monSel[15];
    SDL_Rect monOver[15];

    SDL_Surface* ApongSleep=NULL;
    SDL_Rect sleepPoint[12];

    SDL_Surface* ScrolPower=NULL;
    SDL_Surface* Plat1=NULL;
    SDL_Surface* Plat2=NULL;
    SDL_Surface* Plat3=NULL;
    SDL_Surface* Plat4=NULL;
    SDL_Surface* Plat5=NULL;
    SDL_Surface* Plat6=NULL;
    SDL_Surface* Cover=NULL;

    SDL_Surface* frontApong=NULL;
    SDL_Surface* reaeApong=NULL;
    SDL_Surface* OverreaeApong=NULL;
    SDL_Surface* OverfrontApong=NULL;

    SDL_Surface* loadingPic=NULL;
    SDL_Surface* loadingKey=NULL;
    //Mix_Chunk* loadingSound;
    SDL_Rect loadingWidth[1];

    SDL_Rect oneMon[15];
    SDL_Rect twoMon[15];
    SDL_Rect threeMon[15];

    SDL_Surface* Cpower=NULL;
    SDL_Rect CCpower[1];
    Mix_Chunk* sound1[12];

    Uint8 *keystate=SDL_GetKeyState(NULL);
    TTF_Font *font = NULL;
    TTF_Font *fontsmall = NULL;
    TTF_Font *fontsupersmall = NULL;
    TTF_Font *kfont = NULL;
    SDL_Color textColor = { 0, 0, 0 };
    SDL_Color textColorRED = { 0xFF, 0, 0xFF };
    SDL_Color textColorBLInk = { 33,66, 0xFF};
    SDL_Color textblue = { 15,30, 0xFF};
    SDL_Color textgreen = { 35, 218, 31};
    const int SCREEN_WIDTH=800;
    const int SCREEN_HEIGHT=500;
    const int SCREEN_BPP=32;
const int XMoneyPlay1=21;
const int XMoneyPlay2=654;
const int YMoneyPlay12=400;

const int XMoneyComputer=553;
const int YMoneyComputer=103;

const int XMoney1=204;
const int XMoney2=321;
const int XMoney3=447;
const int XMoney4=571;
const int YMoney1234=427;

const int XMoney5=249;
const int XMoney6=368;
const int XMoney7=496;
const int YMoney567=393;

const int XMoney8=512;
const int XMoney9=264;
const int YMoney89=311;

const int XMoney10=177;
const int XMoney11=369;
const int XMoney12=574;
const int YMoney101112=279;
void set_display(int x,int y,SDL_Surface * source,SDL_Surface *Des,SDL_Rect* clip = NULL)
{
	 SDL_Rect regster;
	 regster.x=x;
	 regster.y=y;
	 SDL_BlitSurface(source,clip,Des,&regster);
}


std::string Tostring(int number)
{
std::ostringstream ss;//create a stringstream
ss << number;//add number to the stream
std::string result =  ss.str();//return a string with the contents of the stream

 return result;
//return *c;
}

/*void convertInt(char * c,int number)
{
std::ostringstream ss;//create a stringstream
ss << number;//add number to the stream
std::string result =  ss.str();//return a string with the contents of the stream

 strcpy(c ,result.c_str());
//return *c;
}*/
SDL_Surface *load_imageColorKeyBlack( std::string filename )
{
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    loadedImage = IMG_Load( filename.c_str() );
    if( loadedImage != NULL )
    {
        optimizedImage = SDL_DisplayFormat( loadedImage );
        SDL_FreeSurface( loadedImage );
        if( optimizedImage != NULL )
        {
           // SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );

            Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 0x00, 0x00, 0x00 );
            //Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );

        }
    }
    return optimizedImage;
}
SDL_Surface *load_imageColorKeyApong( std::string filename )
{
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    loadedImage = IMG_Load( filename.c_str() );
    if( loadedImage != NULL )
    {
        optimizedImage = SDL_DisplayFormat( loadedImage );
        SDL_FreeSurface( loadedImage );
        if( optimizedImage != NULL )
        {
           // SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );

            Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 25, 176, 183 );
            //Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );

        }
    }
    return optimizedImage;
}
SDL_Surface *load_imageColorKey( std::string filename )
{
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    loadedImage = IMG_Load( filename.c_str() );
    if( loadedImage != NULL )
    {
        optimizedImage = SDL_DisplayFormat( loadedImage );
        SDL_FreeSurface( loadedImage );
        if( optimizedImage != NULL )
        {
           // SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );

            Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 0xff, 0xff, 0xff );
            //Set all pixels of color R 0, G 0xFF, B 0xFF to be transparent
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );

        }
    }
    return optimizedImage;
}

SDL_Surface *load_image( std::string filename )
{
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    loadedImage = IMG_Load( filename.c_str() );
    if( loadedImage != NULL )
    {
        optimizedImage = SDL_DisplayFormat( loadedImage );
        SDL_FreeSurface( loadedImage );
        if( optimizedImage != NULL )
        {
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
        }
    }
    return optimizedImage;
}
void ClearScreen()
{
    SDL_FreeSurface(Cpower);
    SDL_FreeSurface(ResultPic);
    SDL_FreeSurface(ApongSleep);
    SDL_FreeSurface(BOp);
    SDL_FreeSurface(BIn);
    SDL_FreeSurface(BHe);
    SDL_FreeSurface(BQu);
    SDL_FreeSurface(BExchang);
    SDL_FreeSurface(MonExchang);
    SDL_FreeSurface(MonLock);
    SDL_FreeSurface(BCreate);
    SDL_FreeSurface(ExchangHead);
    SDL_FreeSurface(ExchangBotton);
    SDL_FreeSurface(BNoExit);
    SDL_FreeSurface(Bscrol);
    SDL_FreeSurface(Usercreate);
    SDL_FreeSurface(Bstar);
    SDL_FreeSurface(OptionB);
    SDL_FreeSurface(CheckB);
    SDL_FreeSurface(CheckOver);
    SDL_FreeSurface(ExitCheck);
    SDL_FreeSurface(OverNo);
    SDL_FreeSurface(OverYes);
    SDL_FreeSurface(Quitform);
    SDL_FreeSurface(AboutG);
    SDL_FreeSurface(ExitAbout);
    //SDL_FreeSurface(ExitChoiceMon);
    SDL_FreeSurface(Next);
    SDL_FreeSurface(Previouse);
    SDL_FreeSurface(BHome);
    //SDL_FreeSurface(gohome);
    SDL_FreeSurface(home);
    SDL_FreeSurface(pic);
    SDL_FreeSurface(pic1);
    SDL_FreeSurface(pic2);//[20];
    SDL_FreeSurface(pic3);//[20];
//    SDL_FreeSurface(start);
    SDL_FreeSurface(screen);
    SDL_FreeSurface(message);
    TTF_CloseFont(font);
    TTF_CloseFont(fontsmall);

    TTF_CloseFont(fontsupersmall);
    TTF_CloseFont(kfont);
    TTF_Quit();
    SDL_KillThread( thread );
    Mix_CloseAudio();
    for(int i=0;i<12;i++)
    Mix_FreeChunk(sound1[i]);
    //Mix_FreeChunk(loadingSound);
    SDL_Quit();
}
void setLoadingWidth(){
    loadingWidth[0].x=0;
    loadingWidth[0].y=0;
    loadingWidth[0].w=0;
    loadingWidth[0].h=12;
}
void SetCpower(){
    CCpower[0].x=0;
    CCpower[0].y=0;
    CCpower[0].w=0;
    CCpower[0].h=15;
}
void Set_oneMon()
{
    for(int i=0;i<14;i++)
    {
    oneMon[i].x=0;
    oneMon[i].y=33*i;
    oneMon[i].w=125;
    oneMon[i].h=32;
    }

}
void Set_twoMon()
{
    for(int i=0;i<14;i++)
    {
    twoMon[i].x=0;
    twoMon[i].y=21*i;
    twoMon[i].w=50;
    twoMon[i].h=20;
    }
}
void Set_threeMon()
{
    for(int i=0;i<14;i++)
    {
    threeMon[i].x=0;
    threeMon[i].y=49*i;
    threeMon[i].w=20;
    threeMon[i].h=48;
    }
}

void Set_Mon()
{
    for(int i=0;i<15;i++)
    {
        monSel[i].x=0;
        monSel[i].w=131;
        monSel[i].h=30;
        monSel[i].y=31*i;
    }
}
void Set_MonOver()
{
    for(int i=0;i<15;i++)
    {
        monOver[i].w=140;
        monOver[i].x=0;
        monOver[i].h=40;
        monOver[i].y=42*i;
    }
}
void setSleepPoint(int k,int x,int y){
    sleepPoint[k].h=60;
    sleepPoint[k].w=190;
    sleepPoint[k].x=x;
    sleepPoint[k].y=y;
}
void SetsleepPoint()
{//int k=0;
/*for(int i=0;i<4;i++)
    for(int j=0;j<3;j++)
    {
    //w=190, h=90
    sleepPoint[k].h=60;
    sleepPoint[k].w=185;
    sleepPoint[k].x=185*j+5;
    sleepPoint[k].y=60*i+5;
    k++;
    }
  */

    setSleepPoint(0,3,1);
    setSleepPoint(1,193,1);
    setSleepPoint(2,384,1);
    setSleepPoint(3,3,61);
    setSleepPoint(4,193,61);
    setSleepPoint(5,384,61);
    setSleepPoint(6,3,123);
    setSleepPoint(7,193,123);
    setSleepPoint(8,384,123);
    setSleepPoint(9,3,183);
    setSleepPoint(10,193,183);
    setSleepPoint(11,384,183);
}

int TypeMon(int n)
{
if(n==1)return 0;
else if(n==2)return 1;
else if(n==5)return 2;
else if(n==10)return 3;
else if(n==20)return 4;
else if(n==50)return 5;
else if(n==100)return 6;
}
int KindMon(int n,int m)
{
if(m==RIELS)
{
        if(n==1)return 0;
        else if(n==2)return 1;
        else if(n==5)return 2;
        else if(n==10)return 3;
        else if(n==20)return 4;
        else if(n==50)return 5;
        else if(n==100)return 6;
}
else if(m==USAs)
{
        if(n==1)return 7;
        else if(n==2)return 8;
        else if(n==5)return 9;
        else if(n==10)return 10;
        else if(n==20)return 11;
        else if(n==50)return 12;
        else if(n==100)return 13;
}
}

double ExchRIELtoUSA(double m)
{
    return m/40;
}
double ExchUSAtoRIEL(double m)
{
    return m*40;
}
#endif
