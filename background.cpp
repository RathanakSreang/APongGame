#include"Button.h"
#include"Timer.h"
#include"save.h"
#include <fstream>
//#include"SDL_net.h"
void DoLoading(int i){
        loadingWidth[0].w=i;
        set_display(0,0,loadingPic,screen);
        set_display(155,470,loadingKey,screen,&loadingWidth[0]);
        MessageGame(655,466, Tostring((int)i*100/488)+"%",fontsupersmall, textgreen);
}
void Freeing(){
    SDL_FreeSurface(loadingPic);
    SDL_FreeSurface(loadingKey);
}

int Money::kind=1;
int Money::MonType=1;
using namespace std;
int main( int argc, char* args[])
{
    bool goHome1=true;
    bool click=false;
    bool loop=false;
    bool loadingTime=true;
    bool loopLost=false;
    static bool FULL_SCREEN=false;
    int countLoading=1;
    bool isfirsttime=false;
    Timer fps,fps1;
    //int frame = 0;
    //bool cap = true;

    Money Mon[16];
    Mon[0]=Money(XMoneyComputer,YMoneyComputer,100001,1);//Computer1
    Mon[1]=Money(XMoneyPlay1,YMoneyPlay12,50,1);//Player1
    Mon[2]=Money(XMoneyPlay2,YMoneyPlay12,50,1);//Player2

    Mon[3]=Money(XMoney1,YMoney1234,0,2);//1
    Mon[4]=Money(XMoney2,YMoney1234,0,2);//2
    Mon[5]=Money(XMoney3,YMoney1234,0,2);//3
    Mon[6]=Money(XMoney4,YMoney1234,0,2);//4

    Mon[7]=Money(XMoney5,YMoney567,0,3);//5
    Mon[8]=Money(XMoney6,YMoney567,0,3);//6
    Mon[9]=Money(XMoney7,YMoney567,0,3);//7

    Mon[10]=Money(XMoney8,YMoney89,0,2);//8
    Mon[11]=Money(XMoney9,YMoney89,0,2);//9

    Mon[12]=Money(XMoney10,YMoney101112,0,3);//10
    Mon[13]=Money(XMoney11,YMoney101112,0,3);//11
    Mon[14]=Money(XMoney12,YMoney101112,0,3);//12
    Mon[1].SetLocat(1);
    Mon[2].SetLocat(2);
    Mouse rate;
    BackGround back;
    Result res;
    ExchangMonay exch;
    Option opt;
    Quit qui;
    AboutGame Abo;
    Instruction Inst;
    Sound soun;
    Apong apon;
     Money::kind=1;
      Money::MonType=1;
    if(decl()==false)
        return 1;
    if(load_file()==false)
        return 1;
  // double usermon=0;
        Save sav;
          ifstream fp1;
          fp1.open("saving.dat",ios::binary);
          if(!fp1.fail()&&fp1!=NULL){
            fp1.read((char*)&sav,sizeof(Save));
            Mon[1].SetNum(sav.getUserMon()/2);
            Mon[2].SetNum(sav.getUserMon()/2);
            Money::kind=sav.getMonKind();
            Money::MonType=sav.getMonTyp();
            exch.setMonSel(sav.getMonSel());
            fp1.close();
          }else{
                isfirsttime=true;
          }


    //default width
    setLoadingWidth();

        thread = SDL_CreateThread( my_thread, NULL );

    while(1){
            fps.start();
    while(SDL_PollEvent(&even)||loop==true||click==true||loadingTime==true||loopLost==true)
    {   fps1.start();
        if(even.type==SDL_QUIT){loadingTime==false;goto ex;}
        if(loadingTime==true){
            DoLoading(countLoading);
            if(even.type==SDL_QUIT){loadingTime==false;goto ex;}
            if(countLoading>488)
            {
                ShellExecute(NULL, "open", "Sound\\welcome.vbs",NULL, NULL, SW_SHOWNORMAL);

                loadingTime=false;
                Freeing();
                back.BackShow();
            }
        countLoading+=3;
        }
        else{


                            back.BackShow();


                            if(even.type==SDL_QUIT)goto ex;
                            if((even.type==SDL_KEYDOWN)&&((even.key.keysym.sym==SDLK_ESCAPE)||(even.key.keysym.sym==SDLK_BACKSPACE)))back.SetStar(0);

                           if((even.type==SDL_MOUSEBUTTONDOWN))
                            {//Mix_PlayChannel( -1, soundMouse, 0 );
                                back.ResultMouse();
                               if(back.GetStar()==1)
                                    {
                                        apon.SelectFrontReae();
                                        if(rate.GohomeClick(Mon)==true&&back.GetStar()==1)back.SetStar(0);
                                    }
                                    else if(back.GetStar()==7)exch.ChioceMoney(Mon);
                                    else if(back.GetStar()==5)qui.Select();
                                    else if(back.GetStar()==3)opt.Check();
                                    else if(back.GetStar()==4)Abo.SelectButton();
                                    else if(back.GetStar()==2)Inst.SelectButton();
                            }

                            if(even.type=SDL_MOUSEMOTION)
                            {
                                back.MouseOver();
                            if(back.GetStar()==1)
                                {
                                    Refresh(Mon,apon);
                                    apon.ApongResult(soun,Money::kind);
                                    apon.Show(Money::MonType);
                                    rate.OverGoHome();
                                    if(apon.Getstart()){loop=true;}
                                    if(apon.Getstend()&&!apon.getSelectCover())
                                    {
                                        loop=false;
                                        click=true;
                                            rate.ShowMouseMoney();
                                            rate.MouseMoveMon(Mon);
                                           /* if(rate.GetResult()>0)
                                            {//char tem[3];
                                              //  convertInt(tem,rate.GetResult());
                                               // MessageGame(300,150,tem,font,textColor);
                                            }*/

                                    }
                                     if(click==true&& apon.Getstend()==false)
                                        {
                                            if(res.ShowResult(Mon,apon.GetResultA(),apon))click=false;
                                        }
                                }
                            else if(back.GetStar()==7)
                                {
                                exch.Show(Mon);
                                if(exch.GetBack()==true)
                                    {
                                        exch.SetBack(false);
                                        back.SetStar(0);
                                        exch.Set_Form(280,50);}
                                }
                            else if(back.GetStar()==3)
                                {
                                    opt.Show();
                                    if(opt.GetExit()==true)
                                        {
                                            back.SetStar(0);
                                            opt.SetExit(false);
                                            opt.SetFormXY(250,150);
                                        }

                                    if(opt.Getscreen()==true)FULL_SCREEN=true;
                                    else if(opt.Getscreen()==false)FULL_SCREEN=false;
                                }
                            else if(back.GetStar()==5)
                                {
                                    qui.Show();
                                    if(qui.GetQuit()==1){goto ex;}
                                    else if(qui.GetQuit()==2){qui.SetFormXY(250,150);qui.SetQuit(0);back.SetStar(0);}

                                }
                            else if(back.GetStar()==4)
                                {
                                    Abo.Show();
                                    if(Abo.GetExitB()==true){Abo.SetExitB(false);back.SetStar(0);Abo.SetFormXY(294,100);}

                                }
                            else if(back.GetStar()==2)
                                {
                                    Inst.Show();
                                    if(Inst.GetExitB()==true){Inst.SetExitB(false);back.SetStar(0);Inst.SetFormXY(294,100);}
                                }
                            }
                        if(LossGame(Mon))
                            {loopLost=true;
                                message = TTF_RenderText_Solid( font,"You Loss Game ", textblue );
                            set_display(350,150,message,screen);
                            //MessageGame();
                            MessageGame(320,180, "This Game will reset in "+Tostring((int)countLoading*100/488),fontsmall, textblue);
                            countLoading--;
                            if(countLoading<1)
                            {
                                Mon[1].SetNum(50);
                                Mon[2].SetNum(50);
                                loopLost=false;
                            }
                            }
    }
SDL_Flip(screen);
    if(( fps1.get_ticks() < 1000 / FRAMES_PER_SECOND ))
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps1.get_ticks() );
        }
    }
    if(keystate[SDLK_F5])
        {
        if(FULL_SCREEN==false)
        {
            screen=SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_FULLSCREEN);//SDL_SWSURFACE,SDL_FULLSCREEN
        FULL_SCREEN=true;
        opt.Setscreen(true);
        }
        else if(FULL_SCREEN==true)
        {
            screen=SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_SWSURFACE);//SDL_SWSURFACE,SDL_FULLSCREEN
        FULL_SCREEN=false;
        opt.Setscreen(false);
        }
        }
    if((fps.get_ticks() < 1000 / FRAMES_PER_SECOND))
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
        }
    }
    ex:
            //usermon=Mon[1].GetMon()+Mon[2].GetMon();
            sav.setUsermon(Mon[1].GetMon()+Mon[2].GetMon());
            sav.setKindMon(Money::kind);
            sav.setMonSel(exch.getMonSel());
            sav.setMonTyp(Money::MonType);
         ofstream fp2;
          fp2.open("saving.dat",ios::binary);
          if(!fp2.fail()){
            fp2.write((char*)&sav,sizeof(Save));
            fp2.close();
          }
    ClearScreen();
    if(isfirsttime){
        ShellExecute(NULL, "open", "https://docs.google.com/spreadsheet/ccc?key=0AoTsdcYUsHLrdGdBWUJ1UFU1WDhpUHhERzdWRmxpUUE&usp=sharing#gid=0",NULL, NULL, SW_SHOWNORMAL);
    }
    return 0;

}

