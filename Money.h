#ifndef MONEY_H
#define MONEY_H

#include"ApongResult.h"
class Money
{
    private:
        int monx,mony;
        double Num;
        int Locat;
        int im;
        bool move;


    public:
        static int kind;
        static int MonType;
        Money(int x=0,int y=0,double mone=0,int m=1);
        void Show();
        void SetMove(bool m){move= m;}
        void SetNum(double mone)
            {Num=mone;
            if(Num>0)move=true;
            else move=false;
            }
        int GetLocat(){return Locat;}
        void SetLocat(int L){Locat=L;}
        bool GetMove(){return move;}
        double GetMon(){return Num;}

       // void GiveMoney();

};
Money::Money(int x,int y,double mone,int m)
{
Set_oneMon();
Set_twoMon();
Set_threeMon();
move=false;
monx=x;mony=y;
Num=mone;
Locat=0;
im=m;
if(Num>=kind)move=true;
}
void Money::Show()
{
    if(Num>=kind)
    {
    if(im==1)set_display(monx,mony,pic2,screen,&oneMon[KindMon(Money::kind,Money::MonType)]);
    else if(im==2)set_display(monx,mony,pic1,screen,&threeMon[KindMon(Money::kind,Money::MonType)]);
    else set_display(monx,mony,pic3,screen,&twoMon[KindMon(Money::kind,Money::MonType)]);
    }
}

class Mouse:public Money
{
    private:
        int Mousex,Mousey;
        int button;
        int place;
        int oldPlace;
        int result;
        int Px,Py;

    public:
        Mouse()
        {
            place=0;Mousex=0;Mousey=0;button=0;oldPlace=0;
        }

        int GetResult(){return result;}
        int GetX(){return Mousex;}
        int GetY(){return Mousey;}
        int GetButton(){return button;}
        int GetPlace(){return place;}
        int GetOldPlace(){return oldPlace;}
        void OverGoHome();
        void ShowMouseMoney();
       // void GiveMoney(int xG,int yG,int xR,int yR,Money obj[]);
      //  bool StartClick();
        bool GohomeClick(Money obj[]);

        void MouseMoveMon(Money obj[]);
};
void Mouse::OverGoHome()
{
    int x,y;
    if(even.type=SDL_MOUSEMOTION)
            {
                x=even.motion.x;
                y=even.motion.y;
                if((x>=689&&x<=770)&&(y>=25&&y<=55))
                set_display(690,26,BHome,screen);
            }
}
bool Mouse::GohomeClick(Money obj[])
{int xB,yB;

    if(even.button.button==SDL_BUTTON_LEFT)
                {
                    xB=even.button.x;
                    yB=even.button.y;
                    if((xB>=689&&xB<=770)&&(yB>=25&&yB<=55))
                    {
                for(int i=3;i<15;i++)
                        {
                    if(obj[i].GetMon()>=Money::kind)
                            {
                            if(obj[i].GetLocat()==1)
                                {
                            obj[1].SetNum(obj[1].GetMon()+obj[i].GetMon());
                                obj[i].SetNum(0);
                                obj[i].SetLocat(0);
                                }
                            else if(obj[i].GetLocat()==2)
                                {
                                obj[2].SetNum(obj[2].GetMon()+obj[i].GetMon());
                                obj[i].SetNum(0);
                                obj[i].SetLocat(0);
                                }
                            }
                        }
                    return true;
                    }
                }
    return false;
}

/*bool Mouse::StartClick()
{   int i=0;
result=0;

    char tem[3];
  int xB=0,yB=0;
    if(even.button.button==SDL_BUTTON_LEFT)
                {
                    xB=even.button.x;
                    yB=even.button.y;
                    if((xB>=50&&xB<=80)&&(yB>=150&&yB<=180))
                    {

                        i=rand()%6+1;
                        result=i;
                        convertInt(tem,i);
                        message = TTF_RenderText_Solid( font,tem, textColor );
                        set_display(150,150,message,screen);
                    }
                        return true;

                }

    return false;
}*/
void Mouse::ShowMouseMoney()
{
    if(button==1)
   {
    if((Mousex>154&&Mousex<638)&&(Mousey>251&&Mousey<480))set_display(Mousex,Mousey,pic3,screen,&twoMon[KindMon(Money::kind,Money::MonType)]);
    else set_display(Mousex-30,Mousey-15,pic2,screen,&oneMon[KindMon(Money::kind,Money::MonType)]);
   }
}
void Mouse::MouseMoveMon(Money obj[])
{//static int Px,Py;
int x,y;
    if(even.type=SDL_MOUSEMOTION)
            {
                x=even.motion.x;
                y=even.motion.y;
            if(button==1)
                {
                    if(Px>x)Mousex=Mousex+(x-Px);
                    else if(Px<=x)Mousex=x-25;
                    if(Py>y)Mousey=Mousey+(y-Py);
                    else if(Py<=y)Mousey=y-10;
                    Py=y;
                    Px=x;

                }
            else if(button==0)
                {
                std::string h;
                int mw,mh,i=0;
                        if((x>=XMoneyPlay1&& x<=XMoneyPlay1+125)&&(y>=YMoneyPlay12&&y<=YMoneyPlay12+35))
                       {
                        i=1;
                        mw=XMoneyPlay1+40;
                        mh=YMoneyPlay12+15;
                        }
                        else if((x>=XMoneyPlay2&& x<=XMoneyPlay2+125)&&(y>=YMoneyPlay12&&y<=YMoneyPlay12+35))
                       {
                        i=2;
                        mw=XMoneyPlay2+40;
                        mh=YMoneyPlay12+15;
                        }
                        else if((x>=XMoney1&& x<=XMoney1+20)&&(y>=YMoney1234&&y<=YMoney1234+48))
                       {
                        i=3;
                        mw=XMoney1;
                        mh=YMoney1234;
                        }
                        else if((x>=XMoney2&& x<=XMoney2+20)&&(y>=YMoney1234&&y<=YMoney1234+48))
                       {
                        i=4;
                        mw=XMoney2;
                        mh=YMoney1234;
                        }
                        else if((x>=XMoney3&& x<=XMoney3+20)&&(y>=YMoney1234&&y<=YMoney1234+48))
                       {
                        i=5;
                        mw=XMoney3;
                        mh=YMoney1234;
                        }
                        else if((x>=XMoney4&& x<=XMoney4+20)&&(y>=YMoney1234&&y<=YMoney1234+48))
                       {
                        i=6;
                        mw=XMoney4;
                        mh=YMoney1234;
                        }
                        else if((x>=XMoney5&& x<=XMoney5+50)&&y>=YMoney567&&y<=(YMoney567+20))
                       {
                        i=7;
                        mw=XMoney5;
                        mh=YMoney567;
                        }
                        else if((x>=XMoney6&& x<=XMoney6+50)&&(y>=YMoney567&&y<=(YMoney567+20)))
                       {
                        i=8;
                        mw=XMoney6;
                        mh=YMoney567;
                        }
                        else if((x>=XMoney7&& x<=(XMoney7+50))&&(y>YMoney567&&y<=(YMoney567+20)))
                       {
                        i=9;
                        mw=XMoney7;
                        mh=YMoney567;
                        }
                        else if((x>=XMoney8&& x<=(XMoney8+20))&&(y>=YMoney89&&y<=(YMoney89+48)))
                       {
                        i=10;
                        mw=XMoney8;
                        mh=YMoney89;
                        }
                        else if((x>=XMoney9&& x<=(XMoney9+20))&&(y>=YMoney89&&y<=(YMoney89+48)))
                       {
                        i=11;
                        mw=XMoney9;
                        mh=YMoney89;
                        }
                        else if((x>=XMoney10&& x<=(XMoney10+50))&&(y>=YMoney101112&&y<=(YMoney101112+20)))
                       {
                        i=12;
                        mw=XMoney10;
                        mh=YMoney101112;
                        }

                       else if((x>=XMoney11&& x<=((XMoney11+50))&&(y>=YMoney101112&&y<=(YMoney101112+20))))
                       {
                        i=13;
                        mw=XMoney11;
                        mh=YMoney101112;
                        }
                        else if((x>=XMoney12&& x<=(XMoney12+50))&&(y>=YMoney101112&&y<=(YMoney101112+20)))
                       {
                        i=14;
                        mw=XMoney12;
                        mh=YMoney101112;
                        }
                        if(i>0&&obj[i].GetMon()>0)
                        {

                        if(Money::MonType==RIELS)
                        {   //Show Money Number Khmer
                            h=Tostring(obj[i].GetMon())+"00¹";
                            message = TTF_RenderText_Solid( kfont,h.c_str(), textColorRED );
                            set_display(mw-37,mh+19,message,screen);
                        }

                        else if(Money::MonType==USAs)
                        {//Show Money Number Khmer
                            h=Tostring(obj[i].GetMon())+"$";
                            message = TTF_RenderText_Solid( font,h.c_str(), textColorRED );
                            set_display(mw-37,mh+29,message,screen);
                        }
                            set_display(mw-40,mh-10,pic2,screen,&oneMon[KindMon(Money::kind,Money::MonType)]);

                        }

                }

            }

    if(even.type=SDL_MOUSEBUTTONDOWN)
        if(even.button.button==SDL_BUTTON_LEFT)
                {

                   // x1=even.button.x;
                   // y1=even.button.y;
                   if(button==0)
                    { x=even.button.x;
                      y=even.button.y;
                    if((x>XMoneyPlay1&&x<XMoneyPlay1+125)&&(y>YMoneyPlay12&&y<YMoneyPlay12+35)&&obj[1].GetMove()==true)
                       {
                        oldPlace=1;
                        Mousex=XMoneyPlay1;
                        Mousey=YMoneyPlay12;
                        if(button==0)
                       button=1;
                        }
                    else if((x>XMoneyPlay2&&x<XMoneyPlay2+125)&&(y>YMoneyPlay12&&y<YMoneyPlay12+35)&&obj[2].GetMove()==true)
                        {
                            oldPlace=2;
                            Mousex=XMoneyPlay2;
                            Mousey=YMoneyPlay12;
                        if(button==0)
                       button=1;
                        }
                    else if((x>XMoney1&&x<XMoney1+20)&&(y>YMoney1234&&y<YMoney1234+48)&&obj[3].GetMove()==true)
                        {
                            oldPlace=3;
                            Mousex=XMoney1;
                            Mousey=YMoney1234;
                        if(button==0)
                       button=1;
                        }
                    else if((x>XMoney2&&x<XMoney2+20)&&(y>YMoney1234&&y<YMoney1234+48)&&obj[4].GetMove()==true)
                        {
                            oldPlace=4;
                            Mousex=XMoney2;
                            Mousey=YMoney1234;;
                        if(button==0)
                       button=1;
                        }
                    else if((x>XMoney3&&x<XMoney3+20)&&(y>YMoney1234&&y<YMoney1234+48)&&obj[5].GetMove()==true)
                        {
                            oldPlace=5;
                            Mousex=XMoney3;
                            Mousey=YMoney1234;;
                            if(button==0)
                       button=1;
                        }
                    else if((x>XMoney4&&x<XMoney4+20)&&(y>YMoney1234&&y<YMoney1234+48)&&obj[6].GetMove()==true)
                        {
                            oldPlace=6;
                            Mousex=XMoney4;
                            Mousey=YMoney1234;;
                            if(button==0)
                       button=1;
                        }
                    else if((x>XMoney5&&x<XMoney5+50)&&(y>YMoney567&&y<YMoney567+20)&&obj[7].GetMove()==true)
                        {
                            oldPlace=7;
                            Mousex=XMoney5;
                            Mousey=YMoney567;
                            if(button==0)
                       button=1;
                        }
                    else if((x>XMoney6&&x<XMoney6+50)&&(y>YMoney567&&y<YMoney567+20)&&obj[8].GetMove()==true)
                        {
                            oldPlace=8;
                            Mousex=XMoney6;
                            Mousey=YMoney567;
                            if(button==0)
                       button=1;
                        }
                    else if((x>XMoney7&&x<XMoney7+50)&&(y>YMoney567&&y<YMoney567+20)&&obj[9].GetMove()==true)
                        {
                            oldPlace=9;
                            Mousex=XMoney7;
                            Mousey=YMoney567;
                            if(button==0)
                       button=1;
                        }
                    else if((x>XMoney8&&x<XMoney8+20)&&(y>YMoney89&&y<YMoney89+48)&&obj[10].GetMove()==true)
                        {
                            oldPlace=10;
                            Mousex=XMoney8;
                            Mousey=YMoney89;
                            if(button==0)
                       button=1;
                        }
                    else if((x>XMoney9&&x<XMoney9+20)&&(y>YMoney89&&y<YMoney89+48)&&obj[11].GetMove()==true)
                        {
                            oldPlace=11;
                            Mousex=XMoney9;
                            Mousey=YMoney89;
                        if(button==0)
                       button=1;
                        }
                    else if((x>XMoney10&&x<XMoney10+50)&&(y>YMoney101112&&y<YMoney101112+20)&&obj[12].GetMove()==true)
                        {
                            oldPlace=12;
                            Mousex=XMoney10;
                            Mousey=YMoney101112;
                            if(button==0)
                       button=1;
                        }
                    else if((x>XMoney11&&x<XMoney11+50)&&(y>YMoney101112&&y<YMoney101112+20)&&obj[13].GetMove()==true)
                        {
                            oldPlace=13;
                            Mousex=XMoney11;
                            Mousey=YMoney101112;
                            if(button==0)
                       button=1;
                        }
                    else if((x>XMoney12&&x<XMoney12+50)&&(y>YMoney101112&&y<YMoney101112+20)&&obj[14].GetMove()==true)
                        {
                            oldPlace=14;
                            Mousex=XMoney12;
                            Mousey=YMoney101112;
                            if(button==0)
                       button=1;
                        }

                    else button=0;
                }

            }
       else
           {

                        if((Mousex>(XMoneyPlay1-50)&& Mousex<XMoneyPlay1+125)&&(Mousey>(YMoneyPlay12-20)&&Mousey<YMoneyPlay12+35))
                       {
                           place=1;
                            Px=0;Py=0;
                        }
                        else if((Mousex>(XMoneyPlay2-50)&& Mousex<XMoneyPlay2+125)&&(Mousey>(YMoneyPlay12-20)&&Mousey<YMoneyPlay12+35))
                        {
                            place=2;
                            Px=0;Py=0;
                        }
                       else if((Mousex>(XMoney9-50)&& Mousex<(XMoney9+20))&&(Mousey>(YMoney89-20)&&Mousey<(YMoney89+48)))
                       {
                           place=11;//Number 9
                            Px=0;Py=0;
                        }
                        else if((Mousex>(XMoney8-50)&& Mousex<(XMoney8+20))&&(Mousey>(YMoney89-20)&&Mousey<(YMoney89+48)))
                       {
                           place=10;// Number8
                            Px=0;Py=0;
                        }
                        else if((Mousex>=(388-50)&& Mousex<=(388))&&(Mousey>(255)&&Mousey<(255+80)-20))
                       {
                           place=13;
                            Px=0;Py=0;
                        }
                        else if((Mousex>=(268-50)&& Mousex<(268))&&(Mousey>(335)&&Mousey<(335+149)-20))
                       {
                           place=7;
                            Px=0;Py=0;
                        }
                        else if((Mousex>(388-50)&& Mousex<(388))&&Mousey>335&&Mousey<((335+149)-20))
                       {
                           place=8;
                            Px=0;Py=0;
                        }
                        else if((Mousex>(519-50)&& Mousex<(519))&&(Mousey>(335)&&Mousey<(335+149)-20))
                       {
                           place=9;
                            Px=0;Py=0;
                        }
                        else if((Mousex>157&& Mousex<((157+233)-50))&&(Mousey>255&&Mousey<((255+80)-20)))
                       {
                           place=12;//Number 11
                            Px=0;Py=0;
                        }
                        else if((Mousex>388&& Mousex<((388+250)-50))&&(Mousey>255&&Mousey<((255+80)-20)))
                       {
                           place=14;//Number 12
                            Px=0;Py=0;
                        }
                        else if((Mousex>157&& Mousex<((157+113)-50))&&(Mousey>335&&Mousey<((335+149)-20)))
                       {
                           place=3;//Number 1
                            Px=0;Py=0;
                        }
                        else if((Mousex>268&& Mousex<((268+122)-50))&&(Mousey>335&&Mousey<((335+149)-20)))
                       {
                           place=4;
                            Px=0;Py=0;
                        }

                       else if((Mousex>388&& Mousex<((388+130)-50))&&(Mousey>335&&Mousey<((335+149)-20)))
                       {
                           place=5;
                            Px=0;Py=0;
                        }
                        else if((Mousex>519&& Mousex<((519+120)-50))&&(Mousey>335&&Mousey<((335+149)-20)))
                       {
                           place=6;
                            Px=0;Py=0;
                        }
                        else
                        {
                            place=oldPlace;
                            Px=0;Py=0;
                        }
                        if(oldPlace!=place&&button==1)
                        {

                        obj[oldPlace].SetNum(obj[oldPlace].GetMon()-kind);
                        obj[place].SetLocat(obj[oldPlace].GetLocat());
                        obj[place].SetNum(obj[place].GetMon()+kind);
                        if(place==1&&oldPlace==2)obj[1].SetLocat(1);
                        if(place==2&&oldPlace==1)obj[2].SetLocat(2);
                        //obj[place].SetMove(true);
                        }
                        button=0;

                    }
}

void PlayerMoney(Money obj[])
{std::string total;

                        if(Money::MonType==RIELS)
                        {total=Tostring(obj[1].GetMon())+"00¹";
                        message = TTF_RenderText_Solid( kfont,total.c_str(), textColor );
                        set_display(22,435,message,screen);
                        }
                        else if(Money::MonType==USAs)
                        {
                            total=Tostring(obj[1].GetMon())+"$";
                        message = TTF_RenderText_Solid( font,total.c_str(), textColor );
                        set_display(22,445,message,screen);
                        }


                        if(Money::MonType==RIELS)
                        {
                        total=Tostring(obj[2].GetMon())+"00¹";
                        message = TTF_RenderText_Solid( kfont,total.c_str(), textColor );
                        set_display(660,435,message,screen);
                        }
                        else if(Money::MonType==USAs)
                        {
                            total=Tostring(obj[2].GetMon())+"$";
                        message = TTF_RenderText_Solid( font,total.c_str(), textColor );
                        set_display(660,445,message,screen);
                        }

}
/*void PlayerName(Money obj[])
{std::string player1,player2;
player1="Sreang rathanak";
player2="Soun Rith";

                    if(player1.length()>10)
                    {
                         player1.erase( player1.length() - (player1.length()-10) );
                    }
                        message = TTF_RenderText_Solid( font,player1.c_str(), textColorBLInk );
                        set_display(22,345,message,screen);
                    if(player2.length()>10)
                    {
                         player2.erase( player2.length() - (player2.length()-10) );
                    }
                        message = TTF_RenderText_Solid( font,player2.c_str(), textColorBLInk );
                        set_display(660,345,message,screen);
}*/
bool LossGame(Money obj[])
{bool Loss=true;
    for(int i=1;i<16;i++)
    if(obj[i].GetMon()>0)
            Loss=false;
    return Loss;
}
void Refresh(Money obj[],Apong Ap)
{
        set_display(0,0,pic,screen);
       for(int loop=0;loop<16;loop++)
           obj[loop].Show();
        //set_display(50,150,start,screen);

        //set_display(700,100,help,screen);
        Ap.Show(Money::MonType);
        //PlayerName(obj);
        PlayerMoney(obj);
        //set_display(633,30,gohome,screen);

}
#endif
