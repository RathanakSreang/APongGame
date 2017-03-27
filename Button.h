#ifndef BUTTON_H
#define BUTTON_H

#include"ExchangMoney.h"
class Option
{
  private: int Ox,Oy;
            int BUx,BUy;
            bool checkscreen;
            bool exit;
            int over;
            bool Mbutton;
  public:
        Option();
        void Show();
        void Check();
        void MoveForm();
        void SetFormXY(int x,int y){Ox=x;Oy=y;}
        void SetExit(bool e){exit=e;}
        bool GetExit(){return exit;}
        void OnOver();
        bool Getscreen(){return checkscreen;}
        void Setscreen(bool s){checkscreen=s;}
};
void Option::OnOver()
{ int Bx,By;
    if(even.type=SDL_MOUSEMOTION)
            {
            Bx=even.motion.x;
            By=even.motion.y;
                    //over box check
                    if((Bx>=Ox+61&&Bx<=Ox+118)&&(By>=Oy+89&&By<=Oy+130))
                    {//89, 94-53=41->89+41=
                    over=1;
                    }
                    //over ok button
                    else if((Bx>=Ox+120&&Bx<=Ox+200)&&(By>=Oy+153&&By<=Oy+181))
                    {
                           over=3;
                    }
                    else over=0;
            }
}
void Option::MoveForm()
{   int Bx,By;
    int My,Mx;
    {
    if(even.type=SDL_MOUSEMOTION&&Mbutton==true )
                        {
                            Mx=even.motion.x;
                            My=even.motion.y;
                                Ox=Mx-BUx;
                                Oy=My-BUy;
                        }
    // mouse is click
    if(even.type=SDL_MOUSEBUTTONDOWN)
            if(even.button.button==SDL_BUTTON_LEFT)
                {
                    Bx=even.button.x;
                    By=even.button.y;
                    // On ok Button
                    if((Bx>=Ox+115&&Bx<=Ox+210)&&(By>=Oy+145&&By<=Oy+190))
                        {
                            Mbutton=false;
                        }
                    /*else if((Bx>=Ox+50&&Bx<=Ox+125)&&(By>=Oy+80&&By<=Oy+180))
                        {
                            Mbutton=false;
                        }*/
                        //on Full screen

                    else if((Bx>=Ox+50&&Bx<=Ox+125)&&(By>=Oy+60&&By<=Oy+150))
                        {
                            Mbutton=false;
                        }
                        // beside all button but in form
                    else if((Bx>=Ox&&Bx<=Ox+300)&&(By>=Oy&&By<=Oy+200))
                    {
                        if(Mbutton==false)
                        {
                            BUx=Bx-Ox;
                            BUy=By-Oy;
                        }
                        Mbutton=true;
                        }
                    }
    // is not click
    else
        {
            Mbutton=false;
            BUx=0;
            BUy=0;
        }

    }
}
Option::Option()
{
    checkscreen=false;
    //checksound=false;
    Mbutton=false;
    exit=false;
    over=0;
    Ox=250;Oy=150;
    BUx=0;BUy=0;

}
void Option::Show()
{
                OnOver();
                MoveForm();
    set_display(0,0,home,screen);
    set_display(Ox,Oy,OptionB,screen);
    //full screen check

    if(checkscreen==true)set_display(Ox+61,Oy+89,CheckB,screen);
    //if(checksound==true)set_display(Ox+61,Oy+105,CheckB,screen);
    if(over==1&& checkscreen==false)set_display(Ox+61,Oy+89,CheckOver,screen);
    //else if(over==2&&checksound==false)set_display(Ox+61,Oy+105,CheckOver,screen);
    else if(over==3)set_display(Ox+120,Oy+151,ExitCheck,screen);

}
void Option::Check()
{   int By,Bx;
     if(even.button.button==SDL_BUTTON_LEFT)
                {
                    Bx=even.button.x;
                    By=even.button.y;
                    // check full screen
                    //89, 94-53=41->89+41=
                    if((Bx>=Ox+61&&Bx<=Ox+118)&&(By>=Oy+89&&By<=Oy+130))
                    {
                        if(checkscreen==false)
                        {

                            checkscreen=true;
                        }
                        else if(checkscreen==true)
                        {

                            checkscreen=false;
                        }
                    }
                   /* else if((Bx>=Ox+61&&Bx<=Ox+118)&&(By>=Oy+110&&By<=Oy+151))
                    {
                        if(checksound==false)checksound=true;
                        else if(checksound==true)checksound=false;
                    }*/
                    else if((Bx>=Ox+120&&Bx<=Ox+200)&&(By>=Oy+153&&By<=Oy+181))
                    {
                            if(checkscreen==true)screen=SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_FULLSCREEN);//SDL_SWSURFACE,SDL_FULLSCREEN
                            else screen=SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_SWSURFACE);//SDL_SWSURFACE,SDL_FULLSCREEN

                         //   if(checksound==true)
                         //   else
                            exit=true;

                    }
                }
}
class Quit
{
  private: int Qx,Qy;
    int exit;
    bool Mbutton;
    int BUx,BUy;
    int over;
  public:
        Quit();
        void Show();
        void Select();
        void SetFormXY(int x,int y){Qx=x;Qy=y;}
        void MoveForm();
        void OverButton();
        void SetQuit(int e){exit=e;}
        int GetQuit(){return exit;}
};
Quit::Quit()
{   over=0;
    Qx=250;
    Qy=150;
    exit=0;
    Mbutton=false;
    BUx=0;BUy=0;

}
void Quit::MoveForm()
{
    int Bx,By;
    int My,Mx;

    {
    if(even.type=SDL_MOUSEMOTION&&Mbutton==true )
                        {
                            Mx=even.motion.x;
                            My=even.motion.y;
                                Qx=Mx-BUx;
                                Qy=My-BUy;
                        }
    if(even.type=SDL_MOUSEBUTTONDOWN)
            if(even.button.button==SDL_BUTTON_LEFT)
                {
                    Bx=even.button.x;
                    By=even.button.y;
                     if((Bx>=Qx+62&&Bx<=Qx+150)&&(By>=Qy+130&&By<=Qy+178))
                    {
                            Mbutton=false;
                    }
                    else if((Bx>=Qx+150&&Bx<=Qx+230)&&(By>=Qy+130&&By<=Qy+178))
                    {
                            Mbutton=false;
                    }
                    else if((Bx>=Qx&&Bx<=Qx+300)&&(By>=Qy&&By<=Qy+200))
                    {
                        if(Mbutton==false)
                        {
                            BUx=Bx-Qx;
                            BUy=By-Qy;
                        }
                        Mbutton=true;
                        }
                    }
    else
        {
            Mbutton=false;
            BUx=0;
            BUy=0;
        }

    }
}
void Quit::OverButton()
{
    int Bx,By;
    if(even.type=SDL_MOUSEMOTION)
            {
            Bx=even.motion.x;
            By=even.motion.y;
                    if((Bx>=Qx+65&&Bx<=Qx+145)&&(By>=Qy+135&&By<=Qy+173))
                    {
                    over=1;
                    }
                    else if((Bx>=Qx+150&&Bx<=Qx+230)&&(By>=Qy+135&&By<=Qy+173))
                    {
                    over=2;
                    }

                    else over=0;
            }
}
void Quit::Select()
{
    int By,Bx;
     if(even.button.button==SDL_BUTTON_LEFT)
                {
                    Bx=even.button.x;
                    By=even.button.y;
                    if((Bx>=Qx+65&&Bx<=Qx+145)&&(By>=Qy+135&&By<=Qy+173))
                    {
                     exit=1;
                    }
                    else if((Bx>=Qx+150&&Bx<=Qx+230)&&(By>=Qy+135&&By<=Qy+173))
                    {
                       exit=2;
                    }
                }
}
void Quit::Show()
{
                MoveForm();
                OverButton();
    set_display(0,0,home,screen);
    set_display(Qx,Qy,Quitform,screen);
    if(over==1)set_display(Qx+65,Qy+135,OverYes,screen);
    else if(over==2)set_display(Qx+151,Qy+135,OverNo,screen);

}
class AboutGame
{
  private:int Ax,Ay;
            int BUx,BUy;
            bool Mbutton;
            int over;
            int Babout;
            bool Eabout;
  public:
        AboutGame();
        void Show();
        void OverButton();
        void SelectButton();
        void SetFormXY(int x,int y){Ax=x;Ay=y;}
        void MoveForm();
        void SetExitB(bool e){Eabout=e;}
        bool GetExitB(){return Eabout;}
};
AboutGame::AboutGame()
{
Ax=294;Ay=100;over=0;
Babout=0;
Eabout=false;
BUx=0;BUy=0;
Mbutton=false;
}
void AboutGame::MoveForm()
{
    int Bx,By;
    int My,Mx;
    {
    if(even.type=SDL_MOUSEMOTION&&Mbutton==true )
                        {
                            Mx=even.motion.x;
                            My=even.motion.y;
                                Ax=Mx-BUx;
                                Ay=My-BUy;
                        }
    if(even.type=SDL_MOUSEBUTTONDOWN)
            if(even.button.button==SDL_BUTTON_LEFT)
                {
                    Bx=even.button.x;
                    By=even.button.y;
                     if((Bx>=Ax+450&&Bx<=Ax+503)&&(By>=Ay-2&&By<=Ay+45))
                    {
                    Mbutton=false;
                    }
                    else if((Bx>=Ax+213&&Bx<=Ax+253)&&(By>=Ay+275&&By<=Ay+304))
                    {
                        Mbutton=false;

                    }
                    else if((Bx>=Ax+245&&Bx<=Ax+285)&&(By>=Ay+275&&By<=Ay+304))
                    {
                     Mbutton=false;
                    }
                    else if((Bx>=Ax+185&&Bx<=Ax+470)&&(By>=Ay+170&&By<=Ay+230))
                    {
                        Mbutton=false;
                    }
                    else if((Bx>=Ax+45&&Bx<=Ax+480)&&(By>=Ay+125&&By<=Ay+260)&&Babout==3)
                    {
                     Mbutton=false;
                    }
                    else if((Bx>=Ax&&Bx<=Ax+500)&&(By>=Ay&&By<=Ay+300))
                    {
                        if(Mbutton==false)
                        {
                            BUx=Bx-Ax;
                            BUy=By-Ay;
                        }
                        Mbutton=true;
                        }
                    }
    else
        {
            Mbutton=false;
            BUx=0;
            BUy=0;
        }

    }
}
void AboutGame::OverButton()
{
    int Bx,By;
    if(even.type=SDL_MOUSEMOTION)
            {
                Bx=even.motion.x;
                By=even.motion.y;
                    if((Bx>=Ax+455&&Bx<=Ax+497)&&(By>=Ay+3&&By<=Ay+40))
                    {
                    over=1;
                    }
                    else if((Bx>=Ax+215&&Bx<=Ax+245)&&(By>=Ay+277&&By<=Ay+298))
                    {
                    over=3;
                    }
                    else if((Bx>=Ax+249&&Bx<=Ax+276)&&(By>=Ay+277&&By<=Ay+298))
                    {
                        over=2;
                    }
                    else if((Bx>=Ax+190&&Bx<=Ax+465)&&(By>=Ay+173&&By<=Ay+190))
                    {
                        over=4;
                    }
                    else if((Bx>=Ax+190&&Bx<=Ax+465)&&(By>=Ay+193&&By<=Ay+207))
                    {
                        over=5;
                    }
                    else if((Bx>=Ax+190&&Bx<=Ax+465)&&(By>=Ay+213&&By<=Ay+228))
                    {
                        over=6;
                    }
                    else if((Bx>=Ax+60&&Bx<=Ax+465)&&(By>=Ay+138&&By<=Ay+158))
                    {
                        over=7;
                    }
                     else if((Bx>=Ax+60&&Bx<=Ax+465)&&(By>=Ay+188&&By<=Ay+228))
                    {
                        over=8;
                    }
                     else if((Bx>=Ax+60&&Bx<=Ax+465)&&(By>=Ay+233&&By<=Ay+253))
                    {
                        over=9;
                    }
                    else over=0;
            }
}
void AboutGame::SelectButton()
{
 int Bx,By;
    if(even.button.button==SDL_BUTTON_LEFT)
            {
            Bx=even.button.x;
            By=even.button.y;

                    if((Bx>=Ax+455&&Bx<=Ax+497)&&(By>=Ay+3&&By<=Ay+40))
                    {
                    Eabout=true;
                    Babout=0;
                    }
                    else if((Bx>=Ax+215&&Bx<=Ax+245)&&(By>=Ay+277&&By<=Ay+298))
                    {
                    Babout=Babout-1;
                    if(Babout<0)Babout=4;
                    }
                    else if((Bx>=Ax+249&&Bx<=Ax+276)&&(By>=Ay+277&&By<=Ay+298))
                    {
                     Babout=Babout+1;
                     if(Babout>4)Babout=0;
                    }

                    else if((Bx>=Ax+190&&Bx<=Ax+465)&&(By>=Ay+173&&By<=Ay+190))
                    {
                        if(Babout==1)ShellExecute(NULL, "open", "https://www.sreangrathanak@yahoo.com",NULL, NULL, SW_SHOWNORMAL);
                        else if(Babout==2)ShellExecute(NULL, "open", "https://www.sunrith2012@gmail.com",NULL, NULL, SW_SHOWNORMAL);
                    }
                    else if((Bx>=Ax+190&&Bx<=Ax+465)&&(By>=Ay+193&&By<=Ay+207))
                    {
                        if(Babout==1)ShellExecute(NULL, "open", "https://www.sreangrathanak@gmail.com",NULL, NULL, SW_SHOWNORMAL);
                        else if(Babout==2)ShellExecute(NULL, "open", "https://www.sunrithriya@gmail.com",NULL, NULL, SW_SHOWNORMAL);
                    }
                    else if((Bx>=Ax+190&&Bx<=Ax+465)&&(By>=Ay+213&&By<=Ay+228))
                    {
                        if(Babout==1)ShellExecute(NULL, "open", "https://www.facebook.com/sreang.rathanak",NULL, NULL, SW_SHOWNORMAL);
                        else if(Babout==2)ShellExecute(NULL, "open", "https://www.facebook.com/sunrith.heng",NULL, NULL, SW_SHOWNORMAL);
                    }
                    else if((Bx>=Ax+60&&Bx<=Ax+465)&&(By>=Ay+138&&By<=Ay+158))
                    {
                     if(Babout==3)ShellExecute(NULL, "open", "https://docs.google.com/spreadsheet/ccc?key=0AoTsdcYUsHLrdGdBWUJ1UFU1WDhpUHhERzdWRmxpUUE&usp=sharing#gid=0",NULL, NULL, SW_SHOWNORMAL);
                    }
                    else if((Bx>=Ax+60&&Bx<=Ax+465)&&(By>=Ay+188&&By<=Ay+228))
                    {
                     if(Babout==3)ShellExecute(NULL, "open", "https://www.facebook.com/groups/1394845080757570/",NULL, NULL, SW_SHOWNORMAL);
                    }
                    else if((Bx>=Ax+60&&Bx<=Ax+465)&&(By>=Ay+233&&By<=Ay+253))
                    {
                     if(Babout==3)ShellExecute(NULL, "open", "video\\introduction.wmv",NULL, NULL, SW_SHOWNORMAL);
                    }


            }
}
void AboutGame::Show()
{
    MoveForm();
    OverButton();
    set_display(0,0,home,screen);
    set_display(Ax,Ay,AboutG,screen);
    if(over==1)set_display(Ax+452,Ay+6,ExitAbout,screen);
    else if(over==2)set_display(Ax+249,Ay+279,Next,screen);
    else if(over==3)set_display(Ax+216,Ay+279,Previouse,screen);
    if(Babout==0)
        {
                message = TTF_RenderText_Solid( fontsmall," This game call Apong and it is built by ", textColor );
                set_display(Ax+80,Ay+70,message,screen);
                message = TTF_RenderText_Solid( fontsmall," year 3 students who studying Computer Science at RUPP.   ", textColor );
                set_display(Ax+40,Ay+90,message,screen);
                message = TTF_RenderText_Solid( fontsmall," We built this game by using C++ language and SDL graphic ", textColor );
                set_display(Ax+40,Ay+110,message,screen);
                message = TTF_RenderText_Solid( fontsmall," library. ", textColor );
                set_display(Ax+40,Ay+130,message,screen);
                message = TTF_RenderText_Solid( fontsmall," It is the first game that we build, so it might have some  ", textColor );
                set_display(Ax+80,Ay+150,message,screen);
                message = TTF_RenderText_Solid( fontsmall," mistake. Therefore, we glad for every comment you", textColor );
                set_display(Ax+40,Ay+170,message,screen);
                message = TTF_RenderText_Solid( fontsmall," suggest to us by following here:", textColor );
                set_display(Ax+40,Ay+190,message,screen);
        }
    else if(Babout==1)
        {
                message = TTF_RenderText_Solid( fontsmall," For Any suggestion or comment ", textblue );
                set_display(Ax+130,Ay+80,message,screen);
                message = TTF_RenderText_Solid( fontsmall," Name in Khmer:", textColor );
                set_display(Ax+40,Ay+110,message,screen);
                message = TTF_RenderText_Solid( fontsmall," Name:", textColor );
                set_display(Ax+40,Ay+130,message,screen);
                message = TTF_RenderText_Solid( fontsmall," Phone Number:", textColor );
                set_display(Ax+40,Ay+150,message,screen);
                message = TTF_RenderText_Solid( fontsmall," E-mail:", textColor );
                set_display(Ax+40,Ay+170,message,screen);
                message = TTF_RenderText_Solid( fontsmall," Or:", textColor );
                set_display(Ax+40,Ay+190,message,screen);
                message = TTF_RenderText_Solid( fontsmall," Facebook:", textColor );
                set_display(Ax+40,Ay+210,message,screen);

                message = TTF_RenderText_Solid( kfont,"eRsog rtn³", textColor );
                set_display(Ax+190,Ay+95,message,screen);
                message = TTF_RenderText_Solid( fontsmall," Sreang Rathanak", textColor );
                set_display(Ax+190,Ay+130,message,screen);
                message = TTF_RenderText_Solid( fontsmall," 016-921-007", textColor );
                set_display(Ax+190,Ay+150,message,screen);
                message = TTF_RenderText_Solid( fontsmall," sreangrathanak@yahoo.com",(over==4? textgreen:textblue) );
                set_display(Ax+190,Ay+170,message,screen);
                message = TTF_RenderText_Solid( fontsmall," sreangrathanak@gmail.com", (over==5? textgreen:textblue) );
                set_display(Ax+190,Ay+190,message,screen);
                message = TTF_RenderText_Solid( fontsmall," www.facebook.com/sreang.rathanak", (over==6? textgreen:textblue) );
                set_display(Ax+190,Ay+210,message,screen);

        }
    else if(Babout==2)
        {
               message = TTF_RenderText_Solid( fontsmall," For Any suggestion or comment ", textblue );
                set_display(Ax+130,Ay+80,message,screen);
                message = TTF_RenderText_Solid( fontsmall," Name in Khmer:", textColor );
                set_display(Ax+40,Ay+110,message,screen);
                message = TTF_RenderText_Solid( fontsmall," Name:", textColor );
                set_display(Ax+40,Ay+130,message,screen);
                message = TTF_RenderText_Solid( fontsmall," Phone Number:", textColor );
                set_display(Ax+40,Ay+150,message,screen);
                message = TTF_RenderText_Solid( fontsmall," E-mail:", textColor );
                set_display(Ax+40,Ay+170,message,screen);
                message = TTF_RenderText_Solid( fontsmall," Or:", textColor );
                set_display(Ax+40,Ay+190,message,screen);
                message = TTF_RenderText_Solid( fontsmall," Facebook:", textColor );
                set_display(Ax+40,Ay+210,message,screen);

                message = TTF_RenderText_Solid( kfont,"ehg sunriT§i", textColor );
                set_display(Ax+190,Ay+95,message,screen);
                message = TTF_RenderText_Solid( fontsmall," Heng Sunrith", textColor );
                set_display(Ax+190,Ay+130,message,screen);
                message = TTF_RenderText_Solid( fontsmall," 093-297-352", textColor );
                set_display(Ax+190,Ay+150,message,screen);
                message = TTF_RenderText_Solid( fontsmall," sunrith2012@gmail.com", (over==4?  textgreen:textblue) );
                set_display(Ax+190,Ay+170,message,screen);
                message = TTF_RenderText_Solid( fontsmall," sunrithriya@gmail.com", (over==5? textgreen:textblue) );
                set_display(Ax+190,Ay+190,message,screen);
                message = TTF_RenderText_Solid( fontsmall," www.facebook.com/sunrith.heng", (over==6? textgreen:textblue) );
                set_display(Ax+190,Ay+210,message,screen);

        }
        else if(Babout==3)
        {
                message = TTF_RenderText_Solid( fontsmall," For Any suggestion or comment ", textblue );
                set_display(Ax+130,Ay+80,message,screen);
                message = TTF_RenderText_Solid( fontsmall," You can write your coment throw google Doc:", textColor );
                set_display(Ax+80,Ay+110,message,screen);
                message = TTF_RenderText_Solid( fontsmall,"https://docs.google.com/spreadsheet/ccc?key=0AoTsd.... ", (over==7? textgreen:textblue) );
                set_display(Ax+60,Ay+135,message,screen);
                message = TTF_RenderText_Solid( fontsmall," You can comment on our game on Facebook:", textColor );
                set_display(Ax+70,Ay+160,message,screen);
                message = TTF_RenderText_Solid( fontsmall,"https://www.facebook.com/groups/1394845080757570/", (over==8? textgreen:textblue) );
                set_display(Ax+60,Ay+185,message,screen);
                message = TTF_RenderText_Solid( fontsmall," For Video How to Play our Game:", textColor );
                set_display(Ax+110,Ay+210,message,screen);
                message = TTF_RenderText_Solid( fontsmall,"Click Here  ", (over==9? textgreen:textblue));
                set_display(Ax+220,Ay+230,message,screen);

        }
        else if(Babout==4)
        {
                message = TTF_RenderText_Solid( fontsmall," Finally, we want to say thank to you that play our game,", textColor );
                set_display(Ax+60,Ay+90,message,screen);
                message = TTF_RenderText_Solid( fontsmall," and hoping that you are enjoy playing our game. And don't", textColor );
                set_display(Ax+40,Ay+110,message,screen);
                message = TTF_RenderText_Solid( fontsmall," you forget tell your friends.  ", textColor );
                set_display(Ax+40,Ay+130,message,screen);
                message = TTF_RenderText_Solid( fontsmall," Thanks You! ", textColor );
                set_display(Ax+245,Ay+150,message,screen);
                message = TTF_RenderText_Solid( fontsmall," Phnom Penh 17/Feb/2014", textColor );
               // set_display(Ax+230,Ay+170,message,screen);
               // message = TTF_RenderText_Solid( fontsmall," Game Khmer Programming", textColor );
                set_display(Ax+270,Ay+200,message,screen);
                message = TTF_RenderText_Solid( fontsmall," © Copyright by GKP ", textColor );
                set_display(Ax+180,Ay+230,message,screen);

        }
}
class Instruction
{
private:int Ix,Iy;
            int over;
            int Binstr;
            bool Einstr;
            int BUx,BUy;
            bool Mbutton;
  public:
        Instruction();
        void Show();
        void OverButton();
        void SetFormXY(int x,int y){Ix=x;Iy=y;}
        void SelectButton();
        void MoveForm();
        void SetExitB(bool e){Einstr=e;}
        bool GetExitB(){return Einstr;}
};
Instruction::Instruction()
{
    Ix=294;Iy=100;over=0;
Binstr=0;
Einstr=false;
BUx=0;
BUy=0;
Mbutton=false;
}
void Instruction::MoveForm()
{
  int Bx,By;
    int My,Mx;

    if(even.type=SDL_MOUSEMOTION&&Mbutton==true )
                        {
                            Mx=even.motion.x;
                            My=even.motion.y;
                                Ix=Mx-BUx;
                                Iy=My-BUy;
                        }
    if(even.type=SDL_MOUSEBUTTONDOWN)
            if(even.button.button==SDL_BUTTON_LEFT)
                {
                    Bx=even.button.x;
                    By=even.button.y;
                     if((Bx>=Ix+450&&Bx<=Ix+503)&&(By>=Iy-2&&By<=Iy+45))
                    {
                    Mbutton=false;
                    }
                    else if((Bx>=Ix+213&&Bx<=Ix+253)&&(By>=Iy+275&&By<=Iy+304))
                    {
                        Mbutton=false;

                    }
                    else if((Bx>=Ix+245&&Bx<=Ix+285)&&(By>=Iy+275&&By<=Iy+304))
                    {
                     Mbutton=false;
                    }
                    else if((Bx>=Ix&&Bx<=Ix+500)&&(By>=Iy&&By<=Iy+300))
                    {
                        if(Mbutton==false)
                        {
                            BUx=Bx-Ix;
                            BUy=By-Iy;
                        }
                        Mbutton=true;
                        }
                    }
    else
        {
            Mbutton=false;
            BUx=0;
            BUy=0;
        }


}
void Instruction::OverButton()
{
    int Bx,By;
    if(even.type=SDL_MOUSEMOTION)
            {
                Bx=even.motion.x;
                By=even.motion.y;
                    if((Bx>=Ix+455&&Bx<=Ix+497)&&(By>=Iy+3&&By<=Iy+40))
                    {
                    over=1;
                    }
                    else if((Bx>=Ix+215&&Bx<=Ix+245)&&(By>=Iy+281&&By<=Iy+298))
                    {
                    over=3;
                    }
                    else if((Bx>=Ix+249&&Bx<=Ix+276)&&(By>=Iy+281&&By<=Iy+298))
                    {
                        over=2;
                    }

                    else over=0;
            }
}
void Instruction::SelectButton()
{
    int Bx,By;
    if(even.button.button==SDL_BUTTON_LEFT)
            {
            Bx=even.button.x;
            By=even.button.y;

                    if((Bx>=Ix+455&&Bx<=Ix+497)&&(By>=Iy+3&&By<=Iy+40))
                    {
                    Einstr=true;
                    Binstr=0;
                    }
                    else if((Bx>=Ix+215&&Bx<=Ix+245)&&(By>=Iy+277&&By<=Iy+298))
                    {
                    Binstr=Binstr-1;
                    if(Binstr<0)Binstr=4;
                    }
                    else if((Bx>=Ix+249&&Bx<=Ix+276)&&(By>=Iy+277&&By<=Iy+298))
                    {
                     Binstr=Binstr+1;
                     if(Binstr>4)Binstr=0;
                    }


            }
}
void Instruction::Show()
{
    MoveForm();
    OverButton();

     set_display(0,0,home,screen);
    set_display(Ix,Iy,InstructionG,screen);
    if(over==1)set_display(Ix+452,Iy+6,ExitAbout,screen);
    else if(over==2)set_display(Ix+250,Iy+277,Next,screen);
    else if(over==3)set_display(Ix+216,Iy+277,Previouse,screen);
    if(Binstr==0)
        {
                message = TTF_RenderText_Solid( fontsmall," To Play A Pong game you have to follow us step: ", textblue );
                set_display(Ix+80,Iy+80,message,screen);
                message = TTF_RenderText_Solid( fontsmall," 1. (Start) Scroll Button Power ", textColor );
                set_display(Ix+40,Iy+110,message,screen);
                message = TTF_RenderText_Solid( fontsmall," 2. (Play) Listen the A pong sound ", textColor );
                set_display(Ix+40,Iy+130,message,screen);
                message = TTF_RenderText_Solid( fontsmall," 3. Put money on what number you are heard ", textColor );
                set_display(Ix+40,Iy+150,message,screen);
                message = TTF_RenderText_Solid( fontsmall," 4. (Open) Mouse click on Cover", textColor );
                set_display(Ix+40,Iy+170,message,screen);
                message = TTF_RenderText_Solid( fontsmall," 5. Mover up step by step to take a look", textColor );
                set_display(Ix+40,Iy+190,message,screen);
                message = TTF_RenderText_Solid( fontsmall," 6. Move cover to any part and release mouse", textColor );
                set_display(Ix+40,Iy+210,message,screen);
                message = TTF_RenderText_Solid( fontsmall," 7. The result show and calculate ", textColor );
                set_display(Ix+40,Iy+230,message,screen);

        }
    else if(Binstr==1)
        {
                message = TTF_RenderText_Solid( fontsmall," How to Play? ", textblue );
                set_display(Ix+180,Iy+80,message,screen);
                message = TTF_RenderText_Solid( fontsmall,"1.If you heard the sound clearly, ", textColor );
                set_display(Ix+40,Iy+110,message,screen);
                message = TTF_RenderText_Solid( fontsmall,"you can put money on Middle(Eye) 1 get 4", textColor );
                set_display(Ix+40,Iy+130,message,screen);
                message = TTF_RenderText_Solid( fontsmall,"2. If you cannot heard the sound clearly, ", textColor );
                set_display(Ix+40,Iy+150,message,screen);
                message = TTF_RenderText_Solid( fontsmall,"you can put money on Line(Double) 1 get 2", textColor );
                set_display(Ix+40,Iy+170,message,screen);
                message = TTF_RenderText_Solid( fontsmall,"3. You can guess part big(6,5,4) or small(1,2,3) ", textColor );
                set_display(Ix+40,Iy+190,message,screen);
                message = TTF_RenderText_Solid( fontsmall,"It call the Three point(Triple) 1 get 1", textColor );
                set_display(Ix+40,Iy+210,message,screen);

        }
         else if(Binstr==2)
        {
                message = TTF_RenderText_Solid( fontsmall," Any option: ", textblue );
                set_display(Ix+180,Iy+80,message,screen);
                message = TTF_RenderText_Solid( fontsmall,"1.Exchang Money to Exchange your Money ", textColor );
                set_display(Ix+40,Iy+110,message,screen);
                message = TTF_RenderText_Solid( fontsmall,"2. Stat game to Play", textColor );
                set_display(Ix+40,Iy+130,message,screen);
                message = TTF_RenderText_Solid( fontsmall,"3. Scroll power to Move A pong", textColor );
                set_display(Ix+40,Iy+150,message,screen);
                message = TTF_RenderText_Solid( fontsmall,"4. Front/Rear to show A pong at Front and Rear", textColor );
                set_display(Ix+40,Iy+170,message,screen);
                message = TTF_RenderText_Solid( fontsmall,"5. Home Button to go to main ", textColor );
                set_display(Ix+40,Iy+190,message,screen);
                message = TTF_RenderText_Solid( fontsmall,"6. Other: Option, About Game, and Exit Program", textColor );
                set_display(Ix+40,Iy+210,message,screen);

        }
    else if(Binstr==3)
        {       message = TTF_RenderText_Solid( fontsmall," Money Ex-changes up to money you have: ", textblue );
                set_display(Ix+80,Iy+80,message,screen);
                message = TTF_RenderText_Solid( fontsmall,"1.To 200R if  more then 4000R", textColor );
                set_display(Ix+40,Iy+110,message,screen);
                message = TTF_RenderText_Solid( fontsmall,"2.To 500R if more then 10000R", textColor );
                set_display(Ix+40,Iy+130,message,screen);
                message = TTF_RenderText_Solid( fontsmall,"3.To 1000R if more then 25000R", textColor );
                set_display(Ix+40,Iy+150,message,screen);
                message = TTF_RenderText_Solid( fontsmall,"4.To 2000R if more then 40000R", textColor );
                set_display(Ix+40,Iy+170,message,screen);
                message = TTF_RenderText_Solid( fontsmall,"5.To 5000R if more then 100000R", textColor );
                set_display(Ix+40,Iy+190,message,screen);
                message = TTF_RenderText_Solid( fontsmall,"6.To 10000R if more then 250000R", textColor );
                set_display(Ix+40,Iy+210,message,screen);
        }
    else if(Binstr==4)
        {

               message = TTF_RenderText_Solid( fontsmall,"7.To 1$ if more then 19$ or 75000R", textColor );
                set_display(Ix+40,Iy+90,message,screen);
                message = TTF_RenderText_Solid( fontsmall,"8.To 2$ if more then 40$ or 160000R", textColor );
                set_display(Ix+40,Iy+110,message,screen);
                message = TTF_RenderText_Solid( fontsmall,"9.To 5$ if more then 100$ or 400000R", textColor );
                set_display(Ix+40,Iy+130,message,screen);
                message = TTF_RenderText_Solid( fontsmall,"10.To 10$ if more then 188$ or 750000R", textColor );
                set_display(Ix+40,Iy+150,message,screen);
                message = TTF_RenderText_Solid( fontsmall,"11.To 20$ if more then 400$ or 1600000R", textColor );
                set_display(Ix+40,Iy+170,message,screen);
                message = TTF_RenderText_Solid( fontsmall,"12.To 50$ if more then 1000$ or 4000000R", textColor );
                set_display(Ix+40,Iy+190,message,screen);
                message = TTF_RenderText_Solid( fontsmall,"13.To 100$ if more then 2500$ or 10000000R", textColor );
                set_display(Ix+40,Iy+210,message,screen);

        }
}
#endif
