#ifndef EXCHANGMONEY_H
#define EXCHANGMONEY_H

#include"Result.h"
void ExchMonRieltoUSA(Money obj[])
{
    double tem,tem2;
tem=obj[1].GetMon()+obj[2].GetMon();

            {tem2=ExchRIELtoUSA(tem);
                obj[1].SetNum(tem2/2);
                obj[2].SetNum(tem2-obj[1].GetMon());
            }
}
void ExchMonUSAtoRiel(Money obj[])
{double tem,tem2;
tem=obj[1].GetMon()+obj[2].GetMon();
            {
             tem2=ExchUSAtoRIEL(tem);
                obj[1].SetNum(tem2/2);
                obj[2].SetNum(tem2-obj[1].GetMon());
            }
}

class ExchangMonay
{
    private:
            int Exy;
            int X,Y;
            int Py;
            int ExchX,ExchY;
            int over;
            int overMon;
            int SelMon;
            bool BackExch;
            bool Mclick;
            int overY;
            int Lnum;
            bool Mbutton,Sbutton;
            SDL_Rect clip[1];

    public:
            ExchangMonay();
            void MouseMove();
            void MouseSelect();
            void MouseScrol();
            void MouseButton();
            void ChioceMoney(Money obj[]);
            void LockMoney(Money obj[]);
            void Show(Money obj[]);
            void SetBack(bool b){BackExch=b;}
            bool GetBack(){return BackExch;}
            void OverBack();
            void Set_Form(int x,int y){X=x;Y=y;}
            void UnChioceMoney();
            void setMonSel(int s){SelMon=s;}
            int getMonSel(){return SelMon;}
};
void ExchangMonay::UnChioceMoney()
{
    if(Lnum<2&&((74-Exy*4+(Y+80)+37)>=(Y+80)&&(74-Exy*4+(Y+80))<=(Y+280)))
        set_display(X+70,(Y+80+74-Exy*4),MonLock,screen);
    if(Lnum<3&&((131-Exy*4+(Y+80)+37)>=(Y+80)&&(131-Exy*4+(Y+80))<=(Y+280)))
        set_display(X+70,(Y+80+131-Exy*4),MonLock,screen);
    if(Lnum<4&&((187-Exy*4+(Y+80)+37)>=(Y+80)&&(187-Exy*4+(Y+80))<=(Y+280)))
        set_display(X+70,(Y+80+187-Exy*4),MonLock,screen);
    if(Lnum<5&&((241-Exy*4+(Y+80)+37)>=(Y+80)&&(241-Exy*4+(Y+80))<=(Y+280)))
        set_display(X+70,(Y+80+241-Exy*4),MonLock,screen);
    if(Lnum<6&&((295-Exy*4+(Y+80)+37)>=(Y+80)&&(295-Exy*4+(Y+80))<=(Y+280)))
        set_display(X+70,(Y+80+295-Exy*4),MonLock,screen);
    if(Lnum<7&&((350-Exy*4+(Y+80)+37)>=(Y+80)&&(350-Exy*4+(Y+80))<=(Y+280)))
        set_display(X+70,(Y+80+350-Exy*4),MonLock,screen);
    if(Lnum<8&&((408-Exy*4+(Y+80)+37)>=(Y+80)&&(408-Exy*4+(Y+80))<=(Y+280)))
        set_display(X+70,(Y+80+408-Exy*4),MonLock,screen);
    if(Lnum<9&&((459-Exy*4+(Y+80)+37)>=(Y+80)&&(459-Exy*4+(Y+80))<=(Y+280)))
        set_display(X+70,(Y+80+459-Exy*4),MonLock,screen);
    if(Lnum<10&&((513-Exy*4+(Y+80)+37)>=(Y+80)&&(513-Exy*4+(Y+80))<=(Y+280)))
        set_display(X+70,(Y+80+513-Exy*4),MonLock,screen);
    if(Lnum<11&&((568-Exy*4+(Y+80)+37)>=(Y+80)&&(568-Exy*4+(Y+80))<=(Y+280)))
        set_display(X+70,(Y+80+568-Exy*4),MonLock,screen);
    if(Lnum<12&&((623-Exy*4+(Y+80)+37)>=(Y+80)&&(623-Exy*4+(Y+80))<=(Y+280)))
        set_display(X+70,(Y+80+623-Exy*4),MonLock,screen);
    if(Lnum<13&&((679-Exy*4+(Y+80)+37)>=(Y+80)&&(679-Exy*4+(Y+80))<=(Y+280)))
        set_display(X+70,(Y+80+679-Exy*4),MonLock,screen);
    if(Lnum<14&&((734-Exy*4+(Y+80)+37)>=(Y+80)&&(734-Exy*4+(Y+80))<=(Y+280)))
        //MessageGame(X+20,(Y+80+734-Exy*4), "$1000",font,textColor);
        set_display(X+70,(Y+80+734-Exy*4),MonLock,screen);
}
void ExchangMonay::LockMoney(Money obj[])
{double mon;
    if(Money::MonType==USAs){mon=ExchUSAtoRIEL(obj[1].GetMon()+obj[2].GetMon());}
    else {mon=obj[1].GetMon()+obj[2].GetMon();}

    //if(mon<50)
         //100
      //   Lnum=1;
     if(mon<80/2)//&&(Exy<&&Exy>))
        //200
        Lnum=1;
    else if(mon<200/2)
        //500
        Lnum=2;
    else if(mon<500/2)
        //1000
        Lnum=3;
    else if(mon<800/2)
        //2000
        Lnum=4;
    else if(mon<1500/2)
        //1
        Lnum=5;
    else if(mon<2000/2)
        //5000
        Lnum=6;
    else if(mon<3200/2)
        //2
        Lnum=7;
    else if(mon<5000/2)
        //10000
        Lnum=8;
    else if(mon<8000/2)
        //5
        Lnum=9;
    else if(mon<15000/2)
        //10
        Lnum=10;
    else if(mon<32000/2)
        //20
        Lnum=11;
    else if(mon<80000/2)
        //50
        Lnum=12;
    else if(mon<200000/2)

        //100
        Lnum=13;
    else Lnum=14;
}
void ExchangMonay::ChioceMoney(Money obj[])
{   int Bx,By;
     if(even.button.button==SDL_BUTTON_LEFT)
                {
                    Bx=even.button.x;
                    By=even.button.y;

                if((By-Y)>=80&&(By-Y)<=285){
                    if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=19&&((By-Y)+Exy*4-80<=55))&&Lnum>=1)
                    {
                        //100
                        SelMon=0;
                      Money::kind=1;
                      if(Money::MonType==USAs){ExchMonUSAtoRiel(obj);}
                      Money::MonType=RIELS;
                    }
                    else if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=76&&((By-Y)+Exy*4-80<=109))&&Lnum>=2)
                    {
                        //200
                        SelMon=1;
                     Money::kind=2;
                     if(Money::MonType==USAs){ExchMonUSAtoRiel(obj);}
                     Money::MonType=RIELS;
                    }
                    else if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=128&&((By-Y)+Exy*4-80<=170))&&Lnum>=3)
                    {
                      //  500
                      SelMon=2;
                     Money::kind=5;
                     if(Money::MonType==USAs){ExchMonUSAtoRiel(obj);}
                     Money::MonType=RIELS;
                    }
                    else if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=187&&((By-Y)+Exy*4-80<=224))&&Lnum>=4)
                    {
                        //1000
                        SelMon=3;
                     Money::kind=10;
                     if(Money::MonType==USAs){ExchMonUSAtoRiel(obj);}
                     Money::MonType=RIELS;
                    }
                    else if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=242&&((By-Y)+Exy*4-80<=277))&&Lnum>=5)
                    {
                        //2000
                        SelMon=4;
                     Money::kind=20;
                     if(Money::MonType==USAs){ExchMonUSAtoRiel(obj);}
                     Money::MonType=RIELS;
                    }
                    else if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=406&&((By-Y)+Exy*4-80<=443))&&Lnum>=6)
                    {
                        //1
                        SelMon=7;
                        if(Money::MonType==RIELS){ExchMonRieltoUSA(obj);}
                     Money::kind=1;
                     Money::MonType=USAs;
                    }

                    else if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=297&&((By-Y)+Exy*4-80<=334))&&Lnum>=7)
                    {
                        //5000
                        SelMon=5;
                        if(Money::MonType==USAs){ExchMonUSAtoRiel(obj);}
                     Money::kind=50;
                     Money::MonType=RIELS;
                    }
                    else if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=460&&((By-Y)+Exy*4-80<=497))&&Lnum>=8)
                    {
                        //2
                        SelMon=8;
                        if(Money::MonType==RIELS){ExchMonRieltoUSA(obj);}
                     Money::kind=2;
                     Money::MonType=USAs;
                    }
                    else if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=351&&((By-Y)+Exy*4-80<=388))&&Lnum>=9)
                    {
                        //10000
                        SelMon=6;
                     Money::kind=100;
                     if(Money::MonType==USAs){ExchMonUSAtoRiel(obj);}
                     Money::MonType=RIELS;
                    }

                    else if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=515&&((By-Y)+Exy*4-80<=551))&&Lnum>=10)
                    {
                        //5
                        SelMon=9;
                      Money::kind=5;
                      if(Money::MonType==RIELS){ExchMonRieltoUSA(obj);}
                      Money::MonType=USAs;
                    }
                    else if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=569&&((By-Y)+Exy*4-80<=607))&&Lnum>=11)
                    {
                     //10
                     SelMon=10;
                     Money::kind=10;
                     if(Money::MonType==RIELS){ExchMonRieltoUSA(obj);}
                     Money::MonType=USAs;
                    }
                    else if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=622&&((By-Y)+Exy*4-80<=659))&&Lnum>=12)
                    {
                        //20
                        SelMon=11;
                      Money::kind=20;
                      if(Money::MonType==RIELS){ExchMonRieltoUSA(obj);}
                      Money::MonType=USAs;
                    }
                    else if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=678&&((By-Y)+Exy*4-80<=715))&&Lnum>=13)
                    {
                     //50
                     SelMon=12;
                     Money::kind=50;
                     if(Money::MonType==RIELS){ExchMonRieltoUSA(obj);}
                     Money::MonType=USAs;
                    }
                    else if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=732&&((By-Y)+Exy*4-80<=770))&&Lnum>=14)
                    {
                        //100
                        SelMon=13;
                      Money::kind=100;
                      if(Money::MonType==RIELS){ExchMonRieltoUSA(obj);}
                      Money::MonType=USAs;
                    }
                }
                }
}
ExchangMonay::ExchangMonay()
{   Py=110;
    Exy=0;
    X=280;
    overY=0;
    Y=50;
    over=0;
    ExchX=0;
    ExchY=0;
    ////KindMon
    SelMon=TypeMon(Money::kind);
    overMon=-1;
    Set_Mon();
    Set_MonOver();
    BackExch=false;
    clip[0].x=0;
    clip[0].y=Exy;
    clip[0].w=225;
    clip[0].h=205;
    Mbutton=false;
    Mclick=false;
    Sbutton=false;
}
void ExchangMonay::MouseScrol()
{
    int Bx,By;
    int Mx,My;
//if(evenbut.type==SDL_MOUSEBUTTONDOWN)
{
    if(even.type=SDL_MOUSEMOTION&&Sbutton==true )
                        {
                            Mx=even.motion.x;
                            My=even.motion.y;
                        if(My<Y+80)My=1;
                        else if(My>Y+280)My=Y+279;
                        if(My>Y+105&&My<Y+255)
                        {

                        Exy=My-Y-105;

                        }
                        }
    if(even.type=SDL_MOUSEBUTTONDOWN)
            if(even.button.button==SDL_BUTTON_LEFT)
                {
                    Bx=even.button.x;
                    By=even.button.y;

                    if((Bx>=X+205&&Bx<=X+225)&&(By>=Y+90&&By<=Y+280))
                    {
                        Sbutton=true;

                        }
                    }
    else
        {
            Sbutton=false;
        }

}

}
void ExchangMonay::MouseSelect()
{//static int Py;
int Bx,By;
int Mx,My;
//if(evenbut.type==SDL_MOUSEBUTTONDOWN)
{
    if(even.type=SDL_MOUSEMOTION&&Mbutton==true )
                        {
                            Mx=even.motion.x;
                            My=even.motion.y;
                        if(My<Y+80)My=1;
                        else if(My>Y+280)My=Y+279;
                        if(My>Y+105&&My<Y+255)
                        {

                        Exy=My-Y-105;

                        }
                        }
    if(even.type=SDL_MOUSEBUTTONDOWN)
            if(even.button.button==SDL_BUTTON_LEFT)
                {
                    Bx=even.button.x;
                    By=even.button.y;

                    if((Bx>=X+205&&Bx<=X+225)&&(By>=Y+90&&By<=Y+280))
                    {
                        Mbutton=true;

                        }
                    }
    else
        {
            Mbutton=false;
        }

}
}
void ExchangMonay::OverBack()
{
        int Bx,By;
    if(even.type=SDL_MOUSEMOTION)
            {
            Bx=even.motion.x;
            By=even.motion.y;
                    if((Bx>=X+176&&Bx<=X+202)&&(By>=Y+23&&By<=Y+52))
                    {
                    over=1;
                    }
                    else over=0;
            if((By-Y)>=80&&(By-Y)<=285){
                    if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=19&&((By-Y)+Exy*4-80<=55)))
                    {
                        //100
                        overMon=0;
                        overY=Y+80+(18-Exy*4);
                    }
                    else if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=76&&((By-Y)+Exy*4-80<=109))&&Lnum>1)
                    {
                        //200
                        overMon=1;
                        overY=Y+80+(74-Exy*4);
                    }
                    else if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=128&&((By-Y)+Exy*4-80<=170))&&Lnum>2)
                    {
                      //  500
                       overMon=2;
                       overY=Y+80+(129-Exy*4);
                    }
                    else if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=187&&((By-Y)+Exy*4-80<=224))&&Lnum>3)
                    {
                        //1000
                        overMon=3;
                        overY=Y+80+(183-Exy*4);
                    }
                    else if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=242&&((By-Y)+Exy*4-80<=277))&&Lnum>4)
                    {
                        //2000
                        overMon=4;
                        overY=Y+80+(237-Exy*4);
                    }
                    else if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=297&&((By-Y)+Exy*4-80<=334))&&Lnum>6)
                    {
                        //5000
                        overMon=5;
                        overY=Y+80+(293-Exy*4);
                    }
                    else if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=351&&((By-Y)+Exy*4-80<=388))&&Lnum>8)
                    {
                        //10000
                        overMon=6;
                        overY=Y+80+(347-Exy*4);
                    }
                    else if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=406&&((By-Y)+Exy*4-80<=443))&&Lnum>5)
                    {
                        //1
                       overMon=7;
                       overY=Y+80+(402-Exy*4);
                    }
                    else if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=460&&((By-Y)+Exy*4-80<=497))&&Lnum>7)
                    {
                        //2
                        overMon=8;
                        overY=Y+80+(457-Exy*4);
                    }
                    else if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=515&&((By-Y)+Exy*4-80<=551))&&Lnum>9)
                    {
                        //5
                        overMon=9;
                        overY=Y+80+(511-Exy*4);
                    }
                    else if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=569&&((By-Y)+Exy*4-80<=607))&&Lnum>10)
                    {
                     //10
                     overMon=10;
                     overY=Y+80+(565-Exy*4);
                    }
                    else if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=622&&((By-Y)+Exy*4-80<=659))&&Lnum>11)
                    {
                        //20
                        overMon=11;
                        overY=Y+80+(620-Exy*4);
                    }
                    else if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=678&&((By-Y)+Exy*4-80<=715))&&Lnum>12)
                    {
                     //50
                     overMon=12;
                     overY=Y+80+(674-Exy*4);
                    }
                    else if((Bx>=X+41&&Bx<=X+177)&&((By-Y)+Exy*4-80>=732&&((By-Y)+Exy*4-80<=770))&&Lnum>13)
                    {
                        //100
                        overMon=13;
                        overY=Y+80+(730-Exy*4);
                    }
                    else {overMon=-1;
                            overY=0;
                            }
            }
            else overMon=-1;
            }
}
void ExchangMonay::Show(Money obj[])
{
            LockMoney(obj);
            MouseSelect();
            MouseButton();
            OverBack();
std::string h;
    clip[0].y=Exy*4;
        set_display(0,0,home,screen);

        set_display(X,Y+80,MonExchang,screen,&clip[0]);

        if(overMon!=-1){set_display(X+41,overY,MoneyOver,screen,&monOver[overMon]);}
UnChioceMoney();
        set_display(X,Y,ExchangHead,screen);
        set_display(X,Y+285,ExchangBotton,screen);
        set_display(X+209,Y+85+Exy,Bscrol,screen);

        if(over==1)set_display(X+175,Y+24,ExitAbout,screen);
        set_display(X+50,Y+313,MoneyExSelect,screen,&monSel[SelMon]);
                    if(Money::MonType==RIELS)
                        {
                        h=Tostring(obj[1].GetMon()+obj[2].GetMon());
                        h=h+"00¹";
                        message = TTF_RenderText_Solid( kfont,h.c_str(), textColorRED );
                        set_display(X+40,Y+345,message,screen);
                        }
                    else if(Money::MonType==USAs)
                        {
                            h=Tostring(obj[1].GetMon()+obj[2].GetMon());
                        h=h+"$";
                        message = TTF_RenderText_Solid( font,h.c_str(), textColorRED );
                        set_display(X+70,Y+355,message,screen);
                        }



}
void ExchangMonay::MouseButton()
{   int Bx,By;
    int My,Mx;
    {
    if(even.type=SDL_MOUSEMOTION&&Mclick==true )
                        {
                            Mx=even.motion.x;
                            My=even.motion.y;
                                X=Mx-ExchX;
                                Y=My-ExchY;
                        }
    if(even.type=SDL_MOUSEBUTTONDOWN)
        if(even.button.button==SDL_BUTTON_LEFT)
                {
                    Bx=even.button.x;
                    By=even.button.y;
                   if((Bx>=X+176&&Bx<=X+202)&&(By>=Y+23&&By<=Y+52))
                        {
                          BackExch=true;
                          Mclick=false;
                        }
                    else if((Bx>=X&&Bx<=X+225)&&(By>=Y&&By<=Y+70))
                    {
                        if(Mclick==false)
                        {
                            ExchX=Bx-X;
                            ExchY=By-Y;
                        }
                        Mclick=true;
                    }
                    else if((Bx>=X&&Bx<=X+225)&&(By>=Y+280&&By<=Y+400))
                    {
                        if(Mclick==false)
                        {
                            ExchX=Bx-X;
                            ExchY=By-Y;
                        }
                        Mclick=true;
                    }
                }
        else
        {
            Mclick=false;
            ExchX=0;
            ExchY=0;
        }

    }
}
#endif
