#ifndef BACKGROUND_H
#define BACKGROUND_H

#include"Load.h"
class BackGround
{
private:
    int x;
    int y;
    int star;
    int NumOn;
    bool onover;
public:
    BackGround();
    void BackShow();
    void SetStar(int s){star=s;}
    void MouseOver();
    int MouseSelect();
    int GetStar(){return star;}
    int GetNumOn(){return NumOn;}
    void ResultMouse();
};
void BackGround::ResultMouse()
{
                if(MouseSelect()==1&&star==0)
                    {
                        star=1;
                    }
                else if (MouseSelect()==2&&star==0)star=2;
                else if (MouseSelect()==3&&star==0)star=3;
                else if(MouseSelect()==4&&star==0)star=4;
                else if(MouseSelect()==5&&star==0)star=5;
                //else if(MouseSelect()==6&&star==0)star=6;
                else if(MouseSelect()==7&&star==0)star=7;



}
BackGround::BackGround()
{
    star=0;
    NumOn=0;
    onover=false;
}
void BackGround::BackShow()
{   /*if(NumOn!=0&&onover==false)
        {
            Mix_PlayChannel( -1, soundMouse, 0 );
            onover=true;
        }*/
   // if(NumOn==0)onover=false;

    if(star==0)set_display(0,0,home,screen);
    else if(star==1)set_display(0,0,pic,screen);
    if(star==0)
    {
    if(NumOn==1)set_display(60,190,Bstar,screen);
    else if(NumOn==2)set_display(60,243,BIn,screen);
    else if(NumOn==3)set_display(83,296,BOp,screen);
    else if(NumOn==4)set_display(107,348,BHe,screen);
    else if(NumOn==5)set_display(107,398,BQu,screen);
    else if (NumOn==7)set_display(60,134,BExchang,screen);
    }

}
int BackGround::MouseSelect()
{
    int xB,yB;
    if(even.button.button==SDL_BUTTON_LEFT)
                {
                    xB=even.button.x;
                    yB=even.button.y;
                    if((xB>=60&&xB<=260)&&(yB>=200&&yB<=223))
                    {
                    return 1;
                    }
                    else if((xB>=60&&xB<=260)&&(yB>=243&&yB<=278))
                    {
                    return 2;
                    }
                    else if((xB>=83&&xB<=235)&&(yB>=296&&yB<=327))
                    {
                    return 3;
                    }
                    else if((xB>=112&&xB<=205)&&(yB>=342&&yB<=378))
                    {
                    return 4;
                    }
                    else if((xB>=112&&xB<=205)&&(yB>=395&&yB<=434))
                    {
                    return 5;
                    }

                    else if((xB>=60&&xB<=260)&&(yB>=134&&yB<=173))
                    {
                    return 7;
                    }
                }
    return 0;
}
void BackGround::MouseOver()
{
    int xB,yB;
    if(even.type=SDL_MOUSEMOTION)
            {
                xB=even.motion.x;
                yB=even.motion.y;
                if((xB>=60&&xB<=260)&&(yB>=200&&yB<=223))
                    {

                    NumOn=1;
                    /*if(star==0&&onover==false)
                        {
                            Mix_PlayChannel( -1, soundMouse, 0 );
                            onover=true;
                        }*/
                    }
                    else if((xB>=60&&xB<=260)&&(yB>=243&&yB<=278))
                    {
                    NumOn=2;
                    }
                    else if((xB>=83&&xB<=235)&&(yB>=296&&yB<=327))
                    {
                    NumOn=3;
                    }

                    else if((xB>=112&&xB<=205)&&(yB>=342&&yB<=378))
                    {
                    NumOn=4;
                    }

                    else if((xB>=112&&xB<=205)&&(yB>=395&&yB<=434))
                    {
                    NumOn=5;
                    }


                    else if((xB>=60&&xB<=260)&&(yB>=134&&yB<=173))
                    {
                    NumOn=7;
                    }
                    else
                        NumOn=0;

            }
}
#endif
