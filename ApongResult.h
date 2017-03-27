#ifndef APONGRESULT_H
#define APONGRESULT_H

#include"Backgroung.h"
void ShowMSG(int x)
{
    if(x==1)message = TTF_RenderText_Solid( font,"Start", textblue );
    else if(x==2)message = TTF_RenderText_Solid( font,"Play", textblue );
    else if(x==3)message = TTF_RenderText_Solid( font,"Open", textblue );
    set_display(380,85,message,screen);
}

int NoteSound(int num,int kind)
{   for(int i=0;i<2;i++){
            if((kind-1)==i){
            if(num==1)return 0+i;
            else if(num==2) return 1+i;
            else if(num==3) return 2+i;
            else if(num==4) return 3+i;
            else if(num==5) return 4+i;
            else if(num==6) return 5+i;
            }
            }
        if(kind==5){
            if(num==1)return 11;
            else if(num==2) return 6;
            else if(num==3) return 7;
            else if(num==4) return 8;
            else if(num==5) return 9;
            else if(num==6) return 10;
        }
        else if(kind==10){
            if(num==1)return 2;
            else if(num==2) return 5;
            else if(num==3) return 0;
            else if(num==4) return 4;
            else if(num==5) return 3;
            else if(num==6) return 1;
        }
        else if(kind==20){
            if(num==1)return 6;
            else if(num==2) return 11;
            else if(num==3) return 10;
            else if(num==4) return 7;
            else if(num==5) return 8;
            else if(num==6) return 9;
        }
        else if(kind==50){
            if(num==1)return 0;
            else if(num==2) return 10;
            else if(num==3) return 9;
            else if(num==4) return 2;
            else if(num==5) return 8;
            else if(num==6) return 5;
        }
        else if(kind==100){
            if(num==1)return 11;
            else if(num==2) return 4;
            else if(num==3) return 7;
            else if(num==4) return 2;
            else if(num==5) return 9;
            else if(num==6) return 0;
        }
    return -1;
}
class Sound
{
  private:
    int NumSound;

  public:
    Sound();


    void PlaySound(int num,int kind);
};

Sound::Sound()
{
    NumSound=0;

}
void Sound::PlaySound(int num,int kind)
{
    // if(t==0)Mix_PlayMusic( sound1[num], -1 );
            Mix_PlayChannel( -1, sound1[NoteSound(num,kind)], 0 );
}
class Apong
{
private:
        int move;
        int first;
        int Num;
        int round;
        int Cox,Coy;
        int SrcX;
        int CoverPlace;
        bool Sbutton,Cbutton;
        int run;
        int temx,temy;
        int ResultA;
        bool MovCo;
        bool start,Apongend;
        bool selectCover;
        bool frontreae;
        int NumOn;
        bool FRbutton;
        int top;
public:
        Apong();
        bool GetMovCo(){return MovCo;}
        void SetMovCo(bool m){MovCo=m;}
        int GetNum(){return Num;}
        void SetNum(int n){Num=n;}
        void Show(int montype);
        void MoveCover();
        void CoverSel();
        void ConRun();
        void SetResultA(int r){ResultA=r;}
        int GetResultA(){return ResultA;}
        int GetCovPl(){return CoverPlace;}
    int GetRun(){return run;}
    void SetRun(int r){run=r;}
    void ApongResult(Sound so,int kind);
    void Setstart(bool s){start=s;}
    bool Getstart(){return start;}
    void Setend(bool s){Apongend=s;}
    bool Getstend(){return Apongend;}
    void setSelectCover(bool s){selectCover=s;}
    bool getSelectCover(){return selectCover;}
    void OverFrontReae();
    void SelectFrontReae();
};

Apong::Apong()
    {
        SetsleepPoint();
        SetCpower();
    round=0;
    Num=0;
    Cox=100;
    Coy=115;
    SrcX=220;
    CoverPlace=0;
    run=0;
    Sbutton=false;
    Cbutton=false;
    temx=0;temy=0;
    ResultA=1;
    MovCo=false;
    start=false;
    Apongend=false;
    first=1;
    selectCover=false;
    frontreae=false;
    NumOn=0;
    FRbutton=false;
    top=0;
    }
void Apong::Show(int montype)
{   std::string h;
    OverFrontReae();
        if(Apongend==false&& run!=0){

        if(Num==0)set_display(300,115,Plat1,screen);
        else if(Num==1)set_display(300,115,Plat2,screen);
        else if(Num==2)set_display(300,115,Plat3,screen);
        else if(Num==3)set_display(300,115,Plat4,screen);
        else if(Num==4)set_display(300,115,Plat5,screen);
        else if(Num==5)set_display(300,115,Plat6,screen);
        }


    if(frontreae==false)set_display(583,153,frontApong,screen);
    else set_display(583,153,reaeApong,screen);

    if(NumOn==1)
    {
        if(frontreae==false)set_display(583,153,OverfrontApong,screen);
        else set_display(583,153,OverreaeApong,screen);
    }
    int startplay=0;
    if(Getstend()==false&&run==0)
    {   startplay=1;
        ShowMSG(startplay);
        h=Tostring(ResultA);
        if(montype==1)MessageGame(727,111,h,kfont,textColor);
        else if(montype==2)MessageGame(727,122,h,font,textColor);
        if(frontreae==false)set_display(300,142,ApongSleep,screen,&sleepPoint[ResultA-1]);
        else set_display(300,142,ApongSleep,screen,&sleepPoint[ResultA-1+6]);

    }
    else if(Getstend()&&getSelectCover()==false){
            startplay=2;
            ShowMSG(startplay);
            set_display(300,105,ResultPic,screen);
    }
    else if(Getstend()){
            startplay=3;
            ShowMSG(startplay);
            if(frontreae==false)set_display(300,142,ApongSleep,screen,&sleepPoint[ResultA-1]);
            else set_display(300,142,ApongSleep,screen,&sleepPoint[ResultA-1+6]);
    }

    if(startplay!=2)set_display(Cox,Coy,Cover,screen);
    set_display(SrcX,222,ScrolPower,screen);
    CCpower[0].w=SrcX-220;
    set_display(/*SrcX*/220,223,Cpower,screen,&CCpower[0]);

            if(ResultA==1)
            {
                MessageGame(0,0,".",font,textgreen);
                MessageGame(790,450,".",font,textgreen);
            }
            if(ResultA==2)
            {
                MessageGame(790,450,".",font,textgreen);
                MessageGame(790,0,".",font,textgreen);
            }
            if(ResultA==3)
            {
                MessageGame(792,1,".",font,textgreen);
                MessageGame(1,450,".",font,textgreen);
            }
            if(ResultA==4)
            {
                MessageGame(1,450,".",font,textgreen);
                MessageGame(1,0,".",font,textgreen);
            }
            if(ResultA==5)
            {
                MessageGame(1,450,".",font,textgreen);
                MessageGame(792,450,".",font,textgreen);
                MessageGame(1,0,".",font,textgreen);
            }
            if(ResultA==6)
            {
                MessageGame(1,450,".",font,textgreen);
                MessageGame(792,450,".",font,textgreen);
                MessageGame(792,0,".",font,textgreen);
            }


if(run>0)ConRun();
}
void Apong::CoverSel()
{ int Bx,By;
    int Mx;
{
    if(even.type=SDL_MOUSEMOTION&&Sbutton==true )
                        {
                            Mx=even.motion.x;
                        {
                        SrcX=Mx-25;//-SrcX;
                        }
                        if(SrcX<220)SrcX=220;
                        else if(SrcX>529)SrcX=529;
                        }
    if(even.type=SDL_MOUSEBUTTONDOWN)
            if(even.button.button==SDL_BUTTON_LEFT)
                {
                    Bx=even.button.x;
                    By=even.button.y;

                    if((Bx>=SrcX&&Bx<=SrcX+55)&&(By>=223&&By<=247))
                    {
                        Sbutton=true;

                        }
                    }
    else
        {

            if(Sbutton==true)
            {
            if(SrcX<300)run=1;
            else if(SrcX<350)run=2;
            else if(SrcX<400)run=3;
            else if(SrcX<450)run=4;
            else if(SrcX<=512)run=5;
            else run=6;
            ResultA=(Mx%6)+1;
            }
            Sbutton=false;
            SrcX=220;
        }

}

}
void Apong::ConRun()
{
if(Num==5)round=round+1;
if(Cox<=330&&round>run*3)
    {
        Cox=Cox+3;
        if(top<100/2){Coy=Coy-2;top+=1;}
        else if(top>=100/2){Coy=Coy+3;top+=1;}
    }

    Num=Num+1;
    if(Num>5)Num=0;
if(Cox>330)
    {
        run=0;
        round=0;
        CoverPlace=1;
        SrcX=220;
        first=1;
        top=0;
        Coy=115;
    }
else if(Cox>=327&&Cox<=330)
    {
    first=0;
    }
}
void Apong::MoveCover()
{
int Bx,By;
    int Mx,My;

{
    if(even.type=SDL_MOUSEMOTION&&Cbutton==true )
                        {
                            Mx=even.motion.x;
                            My=even.motion.y;

                        Cox=Mx-temx;//-SrcX;
                        Coy=My-temy;//-SrcX;
                        }

    if(even.type=SDL_MOUSEBUTTONDOWN)
            if(even.button.button==SDL_BUTTON_LEFT)
                {
                    Bx=even.button.x;
                    By=even.button.y;

                    if((Bx>=Cox&&Bx<=Cox+130)&&(By>=Coy&&By<=Coy+80)&&CoverPlace==1)
                    {
                        if(Cbutton==false)
                            {
                            temx=Bx-Cox;
                            temy=By-Coy;
                            }
                        Cbutton=true;
                        selectCover=true;

                        }
                    }
    else
        {

            if((Cox>240&&Cox<450)&&(Coy>50&&Coy<190)&&Cbutton==true)
                {
                    Cox=330;
                    Coy=115;
                    MovCo=false;
                }
            else if(Cbutton==true)
                {
                    Cox=100;
                    Coy=115;
                    CoverPlace=0;
                    MovCo=true;
                }

            Cbutton=false;
        }

}
}
void Apong::ApongResult(Sound so,int kind)
{
        if(run>0){start=true;Apongend=false;}
        else if(run==0){start=false;}
        if(run==0&& CoverPlace==0)Apongend=false;
        if(CoverPlace==0)CoverSel();
        if(CoverPlace==1)MoveCover();
        if(MovCo==true)
            {
            MovCo=false;
            }
        if(first==0)
            {
            //if(Apongend==false)so.SetT();
            selectCover=false;
//SDL_Delay(50);
            so.PlaySound(ResultA,kind);
            Apongend=true;
            }
}
void Apong::OverFrontReae()
{
    int xB,yB;
    if(even.type=SDL_MOUSEMOTION)
            {
                xB=even.motion.x;
                yB=even.motion.y;
                //583+77,153+32
                if((xB>=583&&xB<=583+77)&&(yB>=153&&yB<=153+32))
                    {
                    NumOn=1;
                    }
                else
                    NumOn=0;

            }
}
void Apong::SelectFrontReae()
{
 int xB,yB;
    if(even.button.button==SDL_BUTTON_LEFT)
                {
                    xB=even.button.x;
                    yB=even.button.y;

                    if((xB>=583&&xB<=583+77)&&(yB>=153&&yB<=153+32))
                    {
                                if(frontreae==false)frontreae=true;
                                else frontreae=false;
                   }
                }

}
#endif
