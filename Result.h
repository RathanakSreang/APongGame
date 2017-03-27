#ifndef RESULT_H
#define RESULT_H

#include"Money.h"
class Result
{
private:
        int Num1[15];
        bool all;
        bool take,Ret,win;
        int sce;
        int ReX,ReY;
        int first;
        int RexFin,ReyFin;
        bool skipdo;
        //int over;
public:

    void SetSce(int c){sce=c;}
    int GetSce(){return sce;}
Result(){
        all=false;
        sce=0;
        ReX=0;ReY=0;
        first=0;
        //over=0;
        RexFin=0;ReyFin=0;
        skipdo=false;
        take=false;Ret=false;win=false;
        for(int i=0;i<15;i++)
        Num1[i]=0;}
        bool GetAll(){return all;}
        void SetAll(bool a){all=a;}
    bool ShowResult(Money obj[],int Num,Apong Ap);
    bool ReturnMoney(Money obj[],int Num,Apong Ap);
    bool TakeMoney(Money obj[],int Num,Apong Ap);
    bool WinMoney(Money obj[],int Num,Apong Ap);
    void PlaceRecieve(int n,Money obj[],Apong Ap);
    void GiveMoney(int xG,int yG,int xR,int yR,Money obj[],Apong Ap);

};

bool Result::ShowResult(Money obj[],int Num,Apong Ap)
{
    if(TakeMoney(obj,Num,Ap))
            {
                take=true;
            }
            if(take==true)
                if(ReturnMoney(obj,Num,Ap))
              {
                  Ret=true;
              }
            if(Ret==true)
                    {
                        if(WinMoney(obj,Num,Ap))
                    {
                        win=true;
                    }
                    }
            if(win==true)
                {
                    take=false;
                    Ret=false;
                    win=false;
                    sce=0;
                return true;
                }
        return false;
}
void Result::GiveMoney(int xG,int yG,int xR,int yR,Money obj[],Apong Ap)
{int i=0,j=0,st=0;
int x,y;

x=xG;y=yG;
    for(;;)
    {

            if(xR<xG)
            {x=x-15;
            if(x<=xR){i=3;x=xR;}
            }
            else if(xR>xG)
            {x=x+15;
            if(x>=xR){i=3;x=xR;}
            }
            if(yR<yG)
                {y=y-10;
                if(y<=yR){j=3;y=yR;}
                }
            else if(yR>yG)
                {y=y+10;
                if(y>=yR){j=3;y=yR;}
                }

     if(i==3&&j==3)break;

        Refresh(obj,Ap);

        if((x>154&&x<638)&&(y>251&&y<480))
            {
            if((xR==XMoney1||xR==XMoney2||xR==XMoney3||xR==XMoney4||xR==XMoney8||xR==XMoney9)&&(yR==YMoney1234||yR==YMoney89))
                set_display(x,y,pic1,screen,&threeMon[KindMon(Money::kind,Money::MonType)]);
            else
                set_display(x,y,pic3,screen,&twoMon[KindMon(Money::kind,Money::MonType)]);
            }
        else set_display(x,y,pic2,screen,&oneMon[KindMon(Money::kind,Money::MonType)]);
        SDL_Flip( screen );
// SDL_Delay(5);
    }
}

void Result::PlaceRecieve(int n,Money obj[],Apong Ap)
{
    if(n==1)GiveMoney(XMoneyComputer,YMoneyComputer,XMoney1,YMoney1234,obj,Ap);//computer to 1
    else if(n==2)GiveMoney(XMoneyComputer,YMoneyComputer,XMoney2,YMoney1234,obj,Ap);//computer to 2
    else if(n==3)GiveMoney(XMoneyComputer,YMoneyComputer,XMoney3,YMoney1234,obj,Ap);//computer to 3
    else if(n==4)GiveMoney(XMoneyComputer,YMoneyComputer,XMoney4,YMoney1234,obj,Ap);//computer to 4
    else if(n==5)GiveMoney(XMoneyComputer,YMoneyComputer,XMoney5,YMoney567,obj,Ap);//computer to 5
    else if(n==6)GiveMoney(XMoneyComputer,YMoneyComputer,XMoney6,YMoney567,obj,Ap);//computer to 6
    else if(n==7)GiveMoney(XMoneyComputer,YMoneyComputer,XMoney7,YMoney567,obj,Ap);//computer to 7
    else if(n==8)GiveMoney(XMoneyComputer,YMoneyComputer,XMoney8,YMoney89,obj,Ap);//computer to 8
    else if(n==9)GiveMoney(XMoneyComputer,YMoneyComputer,XMoney9,YMoney89,obj,Ap);//computer to 9
    else if(n==10)GiveMoney(XMoneyComputer,YMoneyComputer,XMoney10,YMoney101112,obj,Ap);//computer to 10
    else if(n==11)GiveMoney(XMoneyComputer,YMoneyComputer,XMoney11,YMoney101112,obj,Ap);//computer to 11
    else if(n==12)GiveMoney(XMoneyComputer,YMoneyComputer,XMoney12,YMoney101112,obj,Ap);//computer to 12

    else if(n==13)GiveMoney(XMoney1,YMoney1234,XMoneyComputer,YMoneyComputer,obj,Ap);
    else if(n==14)GiveMoney(XMoney2,YMoney1234,XMoneyComputer,YMoneyComputer,obj,Ap);
    else if(n==15)GiveMoney(XMoney3,YMoney1234,XMoneyComputer,YMoneyComputer,obj,Ap);
    else if(n==16)GiveMoney(XMoney4,YMoney1234,XMoneyComputer,YMoneyComputer,obj,Ap);
    else if(n==17)GiveMoney(XMoney5,YMoney567,XMoneyComputer,YMoneyComputer,obj,Ap);
    else if(n==18)GiveMoney(XMoney6,YMoney567,XMoneyComputer,YMoneyComputer,obj,Ap);
    else if(n==19)GiveMoney(XMoney7,YMoney567,XMoneyComputer,YMoneyComputer,obj,Ap);
    else if(n==20)GiveMoney(XMoney8,YMoney89,XMoneyComputer,YMoneyComputer,obj,Ap);
    else if(n==21)GiveMoney(XMoney9,YMoney89,XMoneyComputer,YMoneyComputer,obj,Ap);
    else if(n==22)GiveMoney(XMoney10,YMoney101112,XMoneyComputer,YMoneyComputer,obj,Ap);
    else if(n==23)GiveMoney(XMoney11,YMoney101112,XMoneyComputer,YMoneyComputer,obj,Ap);
    else if(n==24)GiveMoney(XMoney12,YMoney101112,XMoneyComputer,YMoneyComputer,obj,Ap);

    else if(n==25)GiveMoney(XMoney1,YMoney1234,XMoneyPlay1,YMoneyPlay12,obj,Ap);
    else if(n==26)GiveMoney(XMoney2,YMoney1234,XMoneyPlay1,YMoneyPlay12,obj,Ap);
    else if(n==27)GiveMoney(XMoney3,YMoney1234,XMoneyPlay1,YMoneyPlay12,obj,Ap);
    else if(n==28)GiveMoney(XMoney4,YMoney1234,XMoneyPlay1,YMoneyPlay12,obj,Ap);
    else if(n==29)GiveMoney(XMoney5,YMoney567,XMoneyPlay1,YMoneyPlay12,obj,Ap);
    else if(n==30)GiveMoney(XMoney6,YMoney567,XMoneyPlay1,YMoneyPlay12,obj,Ap);
    else if(n==31)GiveMoney(XMoney7,YMoney567,XMoneyPlay1,YMoneyPlay12,obj,Ap);
    else if(n==32)GiveMoney(XMoney8,YMoney89,XMoneyPlay1,YMoneyPlay12,obj,Ap);
    else if(n==33)GiveMoney(XMoney9,YMoney89,XMoneyPlay1,YMoneyPlay12,obj,Ap);
    else if(n==34)GiveMoney(XMoney10,YMoney101112,XMoneyPlay1,YMoneyPlay12,obj,Ap);
    else if(n==35)GiveMoney(XMoney11,YMoney101112,XMoneyPlay1,YMoneyPlay12,obj,Ap);
    else if(n==36)GiveMoney(XMoney12,YMoney101112,XMoneyPlay1,YMoneyPlay12,obj,Ap);

    else if(n==37)GiveMoney(XMoney1,YMoney1234,XMoneyPlay2,YMoneyPlay12,obj,Ap);
    else if(n==38)GiveMoney(XMoney2,YMoney1234,XMoneyPlay2,YMoneyPlay12,obj,Ap);
    else if(n==39)GiveMoney(XMoney3,YMoney1234,XMoneyPlay2,YMoneyPlay12,obj,Ap);
    else if(n==40)GiveMoney(XMoney4,YMoney1234,XMoneyPlay2,YMoneyPlay12,obj,Ap);
    else if(n==41)GiveMoney(XMoney5,YMoney567,XMoneyPlay2,YMoneyPlay12,obj,Ap);
    else if(n==42)GiveMoney(XMoney6,YMoney567,XMoneyPlay2,YMoneyPlay12,obj,Ap);
    else if(n==43)GiveMoney(XMoney7,YMoney567,XMoneyPlay2,YMoneyPlay12,obj,Ap);
    else if(n==44)GiveMoney(XMoney8,YMoney89,XMoneyPlay2,YMoneyPlay12,obj,Ap);
    else if(n==45)GiveMoney(XMoney9,YMoney89,XMoneyPlay2,YMoneyPlay12,obj,Ap);
    else if(n==46)GiveMoney(XMoney10,YMoney101112,XMoneyPlay2,YMoneyPlay12,obj,Ap);
    else if(n==47)GiveMoney(XMoney11,YMoney101112,XMoneyPlay2,YMoneyPlay12,obj,Ap);
    else if(n==48)GiveMoney(XMoney12,YMoney101112,XMoneyPlay2,YMoneyPlay12,obj,Ap);
}

bool Result::ReturnMoney(Money obj[],int Num,Apong Ap)
{int i,tem;
if(sce==0)
    {           if(obj[11].GetMon()>=Money::kind)
                    Num1[11]=obj[11].GetMon()+obj[11].GetMon();
                if(obj[12].GetMon()>=Money::kind)
                   Num1[12]=obj[12].GetMon()+obj[12].GetMon()*4;
                if(obj[13].GetMon()>=Money::kind)
                   Num1[13]=obj[13].GetMon()+obj[13].GetMon()*2;
                if(obj[3].GetMon()>=Money::kind)
                    Num1[3]=obj[3].GetMon()+obj[3].GetMon()*4;
                if(obj[7].GetMon()>=Money::kind)
                    Num1[7]=obj[7].GetMon()+obj[7].GetMon()*2;
                if(obj[4].GetMon()>=Money::kind)
                    Num1[4]=obj[4].GetMon()+obj[4].GetMon()*4;
                if(obj[8].GetMon()>=Money::kind)
                    Num1[8]=obj[8].GetMon()+obj[8].GetMon()*2;
                if(obj[10].GetMon()>=Money::kind)
                    Num1[10]=obj[10].GetMon()+obj[10].GetMon();
                if(obj[5].GetMon()>=Money::kind)
                    Num1[5]=obj[5].GetMon()+obj[5].GetMon()*4;
                if(obj[9].GetMon()>=Money::kind)
                    Num1[9]=obj[9].GetMon()+obj[9].GetMon()*2;
                if(obj[6].GetMon()>=Money::kind)
                    Num1[6]=obj[6].GetMon()+obj[6].GetMon()*4;
                if(obj[14].GetMon()>=Money::kind)
                    Num1[14]=obj[14].GetMon()+obj[14].GetMon()*4;
    }
           sce=1;//set econd time
    if(Num==1)
        {
            if(obj[11].GetMon()>0&&obj[11].GetMon()<Num1[11])
                {
                 obj[11].SetNum(obj[11].GetMon()+Money::kind);
                 {
                 PlaceRecieve(9,obj,Ap);
                 }
               }
            if(obj[12].GetMon()>0&&obj[12].GetMon()<Num1[12])
                {
                 obj[12].SetNum(obj[12].GetMon()+Money::kind);
                 {
                  PlaceRecieve(10,obj,Ap);
                 }
                }
          if(obj[13].GetMon()>0&&obj[13].GetMon()<Num1[13])
              {
                obj[13].SetNum(obj[13].GetMon()+Money::kind);
                {
                   PlaceRecieve(11,obj,Ap);
                 }
                }
        }
    else if(Num==2)
        {
            if(obj[11].GetMon()>0&&obj[11].GetMon()<Num1[11])
                {
                 //tem=obj[11].GetMon();

                 obj[11].SetNum(obj[11].GetMon()+Money::kind);
                 //for(i=0;i<tem;i=i+Money::kind)
                 {
                 PlaceRecieve(9,obj,Ap);
                 //SDL_Delay(5);
                 }

                }
            if(obj[3].GetMon()>0&&obj[3].GetMon()<Num1[3])
                {
                 //tem=obj[3].GetMon()*4;

                 obj[3].SetNum(obj[3].GetMon()+Money::kind);
                 //for(i=0;i<tem;i=i+Money::kind)
                 {
                  PlaceRecieve(1,obj,Ap);
                  //SDL_Delay(5);
                 }

                }
            if(obj[7].GetMon()>0&&obj[7].GetMon()<Num1[7])
                {
                 //tem=obj[7].GetMon()*2;

                 obj[7].SetNum(obj[7].GetMon()+Money::kind);
                 //for(i=0;i<tem;i=i+Money::kind)
                 {
                  PlaceRecieve(5,obj,Ap);
                  //SDL_Delay(5);
                 }

                }
        }

    else if(Num==3)
        {
            if(obj[11].GetMon()>0&&obj[11].GetMon()<Num1[11])
                {
                 //tem=obj[11].GetMon();

                 obj[11].SetNum(obj[11].GetMon()+Money::kind);
                 //for(i=0;i<tem;i=i+Money::kind)
                 {
                 PlaceRecieve(9,obj,Ap);
                 //SDL_Delay(5);
                 }

                }
            if(obj[4].GetMon()>0&&obj[4].GetMon()<Num1[4])
                {
                 //tem=obj[4].GetMon()*4;

                 obj[4].SetNum(obj[4].GetMon()+Money::kind);
                 //for(i=0;i<tem;i=i+Money::kind)
                 {
                  PlaceRecieve(2,obj,Ap);
                  //SDL_Delay(5);
                 }

                }
            if(obj[7].GetMon()>0&&obj[7].GetMon()<Num1[7])
                {
                 //tem=obj[7].GetMon()*2;

                 obj[7].SetNum(obj[7].GetMon()+Money::kind);
                 //for(i=0;i<tem;i=i+Money::kind)
                 {
                  PlaceRecieve(5,obj,Ap);
                  //SDL_Delay(5);
                 }

                }
            if(obj[8].GetMon()>0&&obj[8].GetMon()<Num1[8])
                {
                 //tem=obj[8].GetMon()*2;

                 obj[8].SetNum(obj[8].GetMon()+Money::kind);
                 //for(i=0;i<tem;i=i+Money::kind)
                 {
                  PlaceRecieve(6,obj,Ap);
                  //SDL_Delay(5);
                 }

                }
        }
    else if(Num==4)
        {
            if(obj[10].GetMon()>0&&obj[10].GetMon()<Num1[10])
                {
                 //tem=obj[10].GetMon();

                 obj[10].SetNum(obj[10].GetMon()+Money::kind);
                 //for(i=0;i<tem;i=i+Money::kind)
                 {
                  PlaceRecieve(8,obj,Ap);
                  //SDL_Delay(5);
                 }

                }
            if(obj[5].GetMon()>0&&obj[5].GetMon()<Num1[5])
                {
                 //tem=obj[5].GetMon()*4;
                 obj[5].SetNum(obj[5].GetMon()+Money::kind);
                 //for(i=0;i<tem;i=i+Money::kind)
                 {
                  PlaceRecieve(3,obj,Ap);
                  //SDL_Delay(5);
                 }

                }
            if(obj[8].GetMon()>0&&obj[8].GetMon()<Num1[8])
                {
                 //tem=obj[8].GetMon()*2;

                 obj[8].SetNum(obj[8].GetMon()+Money::kind);
                 //for(i=0;i<tem;i=i+Money::kind)
                 {
                  PlaceRecieve(6,obj,Ap);
                  //SDL_Delay(5);
                 }

                }
            if(obj[9].GetMon()>0&&obj[9].GetMon()<Num1[9])
                {
                 //tem=obj[9].GetMon()*2;

                 obj[9].SetNum(obj[9].GetMon()+Money::kind);
                 //for(i=0;i<tem;i=i+Money::kind)
                 {
                  PlaceRecieve(7,obj,Ap);
                  //SDL_Delay(5);
                 }

                }
        }
    else if(Num==5)
        {
            if(obj[10].GetMon()>0&&obj[10].GetMon()<Num1[10])
                {
                 //tem=obj[10].GetMon();

                 obj[10].SetNum(obj[10].GetMon()+Money::kind);
                 //for(i=0;i<tem;i=i+Money::kind)
                 {
                  PlaceRecieve(8,obj,Ap);
                  //SDL_Delay(5);
                 }

                }
            if(obj[6].GetMon()>0&&obj[6].GetMon()<Num1[6])
                {
                 //tem=obj[6].GetMon()*4;

                 obj[6].SetNum(obj[6].GetMon()+Money::kind);
                 //for(i=0;i<tem;i=i+Money::kind)
                 {
                  PlaceRecieve(4,obj,Ap);
                  //SDL_Delay(5);
                 }

                }
            if(obj[9].GetMon()>0&&obj[9].GetMon()<Num1[9])
                {
                 //tem=obj[9].GetMon()*2;

                 obj[9].SetNum(obj[9].GetMon()+Money::kind);
                 //for(i=0;i<tem;i=i+Money::kind)
                 {
                  PlaceRecieve(7,obj,Ap);
                  //SDL_Delay(5);
                 }

                }

        }
    else if(Num==6)
        {
            if(obj[10].GetMon()>0&&obj[10].GetMon()<Num1[10])
                {
                 //tem=obj[10].GetMon();

                 obj[10].SetNum(obj[10].GetMon()+Money::kind);
                 //for(i=0;i<tem;i=i+Money::kind)
                 {
                  PlaceRecieve(8,obj,Ap);
                  //SDL_Delay(5);
                 }

                }
            if(obj[14].GetMon()>0&&obj[14].GetMon()<Num1[14])
                {
                 //tem=obj[14].GetMon()*4;

                 obj[14].SetNum(obj[14].GetMon()+Money::kind);
                 //for(i=0;i<tem;i=i+Money::kind)
                 {
                    PlaceRecieve(12,obj,Ap);
                   // SDL_Delay(5);
                 }

                }
            if(obj[13].GetMon()>0&&obj[13].GetMon()<Num1[13])
                {
                 //tem=obj[13].GetMon()*2;

                 obj[13].SetNum(obj[13].GetMon()+Money::kind);
                 //for(i=0;i<tem;i=i+Money::kind)
                 {
                    PlaceRecieve(11,obj,Ap);
                   // SDL_Delay(5);
                 }

        }}

            if(Num==1)
                    {
                    if(Num1[11]<=obj[11].GetMon()&&Num1[13]<=obj[13].GetMon()&&Num1[12]<=obj[12].GetMon())
                            all=true;
                    }
            else if(Num==2)
                    {
                    if(Num1[11]<=obj[11].GetMon()&&Num1[3]<=obj[3].GetMon()&&Num1[7]<=obj[7].GetMon())all=true;
                    }
            else if(Num==3)
                    {
                    if(Num1[11]<=obj[11].GetMon()&&Num1[4]<=obj[4].GetMon()&&Num1[7]<=obj[7].GetMon()&&Num1[8]<=obj[8].GetMon())all=true;
                    }
            else if(Num==4)
                    {
                    if(Num1[10]<=obj[10].GetMon()&&Num1[5]<=obj[5].GetMon()&&Num1[8]<=obj[8].GetMon()&&Num1[9]<=obj[9].GetMon())all=true;
                    }
            else if(Num==5)
                    {
                    if(Num1[10]<=obj[10].GetMon()&&Num1[6]<=obj[6].GetMon()&&Num1[9]<=obj[9].GetMon())all=true;
                    }
            else if(Num==6)
                    {
                        if(Num1[10]<=obj[10].GetMon()&&Num1[14]<=obj[14].GetMon()&&Num1[13]<=obj[13].GetMon())all=true;
                    }

  //  SDL_Delay(5);
if(all==true)
{
    for(int i=0;i<15;i++)Num1[i]=0;
    all=false;
    return true;
}
else if(all==false)
    return false;
}
bool Result::TakeMoney(Money obj[],int Num,Apong Ap)
{int i;
    if(Num!=1)
        {
            if(obj[12].GetMon()>=Money::kind)
                {obj[12].SetNum(obj[12].GetMon()-Money::kind);
                  PlaceRecieve(22,obj,Ap);
                }
        }
    if(Num!=2)
        {
            if(obj[3].GetMon()>=Money::kind)
                {
                obj[3].SetNum(obj[3].GetMon()-Money::kind);
                  PlaceRecieve(13,obj,Ap);
                }
        }
   if(Num!=3)
        {
            if(obj[4].GetMon()>=Money::kind)
                {
                obj[4].SetNum(obj[4].GetMon()-Money::kind);
                  PlaceRecieve(14,obj,Ap);
                }
        }
    if(Num!=4)
        {
            if(obj[5].GetMon()>=Money::kind)
                {
                obj[5].SetNum(obj[5].GetMon()-Money::kind);
                  PlaceRecieve(15,obj,Ap);
                }
        }
    if(Num!=5)
        {
            if(obj[6].GetMon()>=Money::kind)
                {
                obj[6].SetNum(obj[6].GetMon()-Money::kind);
                  PlaceRecieve(16,obj,Ap);
                }
        }
    if(Num!=6)
        {
            if(obj[14].GetMon()>=Money::kind)
                {
                obj[14].SetNum(obj[14].GetMon()-Money::kind);
                    PlaceRecieve(24,obj,Ap);
                }
        }
   if(Num>3)
        {
            if(obj[7].GetMon()>=Money::kind)
                {
                obj[7].SetNum(obj[7].GetMon()-Money::kind);
                    PlaceRecieve(17,obj,Ap);
                }
            if(obj[11].GetMon()>=Money::kind)
                {
                    obj[11].SetNum(obj[11].GetMon()-Money::kind);
                    PlaceRecieve(21,obj,Ap);
                }
            if(Num<6)
                {
                 if(obj[13].GetMon()>=Money::kind)
                {
                obj[13].SetNum(obj[13].GetMon()-Money::kind);
                    PlaceRecieve(23,obj,Ap);
                }
                }
            if(Num>4)
            {
                if(obj[8].GetMon()>=Money::kind)
                {
                obj[8].SetNum(obj[8].GetMon()-Money::kind);
                    PlaceRecieve(18,obj,Ap);
                }
            }
            if(Num>5)
            {
                if(obj[9].GetMon()>=Money::kind)
                {
                obj[9].SetNum(obj[9].GetMon()-Money::kind);
                    PlaceRecieve(19,obj,Ap);
                }
            }
        }
    if(Num<4)
        {
            if(obj[9].GetMon()>=Money::kind)
                {
                obj[9].SetNum(obj[9].GetMon()-Money::kind);
                    PlaceRecieve(19,obj,Ap);
                }
            if(obj[10].GetMon()>0)
                {
                obj[10].SetNum(obj[10].GetMon()-Money::kind);
                    PlaceRecieve(20,obj,Ap);
                }
            if(Num>1)
                {
                 if(obj[13].GetMon()>=Money::kind)
                {
                obj[13].SetNum(obj[13].GetMon()-Money::kind);
                    PlaceRecieve(23,obj,Ap);
                }
                }
            if(Num<3)
                {
                   if(obj[8].GetMon()>=Money::kind)
                {

                obj[8].SetNum(obj[8].GetMon()-Money::kind);
                    PlaceRecieve(18,obj,Ap);

                }
                }
            if(Num<2)
                {
                  if(obj[7].GetMon()>=Money::kind)
                {
                obj[7].SetNum(obj[7].GetMon()-Money::kind);
                    PlaceRecieve(17,obj,Ap);
                }
                }
        }
    //SDL_Delay(5);
    if(Num==1)
        {
        if(obj[3].GetMon()==0&&obj[4].GetMon()==0&&obj[5].GetMon()==0&&obj[6].GetMon()==0&&obj[7].GetMon()==0&&obj[8].GetMon()==0&&obj[9].GetMon()==0&&obj[10].GetMon()==0&&obj[14].GetMon()==0)
            {
                return true;
            }
        }
    else if(Num==2)
        {
         if(obj[12].GetMon()==0&&obj[4].GetMon()==0&&obj[5].GetMon()==0&&obj[6].GetMon()==0&&obj[13].GetMon()==0&&obj[8].GetMon()==0&&obj[9].GetMon()==0&&obj[10].GetMon()==0&&obj[14].GetMon()==0)
            {
                return true;
            }

        }
    else if(Num==3)
        {
         if(obj[3].GetMon()==0&&obj[5].GetMon()==0&&obj[6].GetMon()==0&&obj[12].GetMon()==0&&obj[13].GetMon()==0&&obj[9].GetMon()==0&&obj[10].GetMon()==0&&obj[14].GetMon()==0)
            {
                return true;
            }

        }
        else if(Num==4)
        {
         if(obj[3].GetMon()==0&&obj[4].GetMon()==0&&obj[11].GetMon()==0&&obj[6].GetMon()==0&&obj[7].GetMon()==0&&obj[12].GetMon()==0&&obj[13].GetMon()==0&&obj[10].GetMon()==0&&obj[14].GetMon()==0)
            {
                return true;
            }

        }
        else if(Num==5)
        {
         if(obj[3].GetMon()==0&&obj[4].GetMon()==0&&obj[5].GetMon()==0&&obj[11].GetMon()==0&&obj[7].GetMon()==0&&obj[8].GetMon()==0&&obj[12].GetMon()==0&&obj[13].GetMon()==0&&obj[14].GetMon()==0)
            {
                return true;
            }

        }
        else if(Num==6)
        {
         if(obj[3].GetMon()==0&&obj[4].GetMon()==0&&obj[5].GetMon()==0&&obj[6].GetMon()==0&&obj[7].GetMon()==0&&obj[8].GetMon()==0&&obj[9].GetMon()==0&&obj[11].GetMon()==0&&obj[12].GetMon()==0)
            {
                return true;
            }

        }
return false;
}
bool Result::WinMoney(Money obj[],int Num,Apong Ap)
{
    int i;
    if(Num==1)
        {
            if(obj[11].GetMon()>=Money::kind)
                {
                 if(obj[11].GetLocat()==1)
                    {
                        obj[1].SetNum(obj[1].GetMon()+Money::kind);
                            PlaceRecieve(33,obj,Ap);
                    }
                 else if(obj[11].GetLocat()==2)
                    {
                        obj[2].SetNum(obj[2].GetMon()+Money::kind);
                            PlaceRecieve(45,obj,Ap);
                    }
                obj[11].SetNum(obj[11].GetMon()-Money::kind);
                if(obj[11].GetMon()<Money::kind)obj[11].SetLocat(0);
                }
            if(obj[12].GetMon()>=Money::kind)
                {

                 if(obj[12].GetLocat()==1)
                    {
                        obj[1].SetNum(obj[1].GetMon()+Money::kind);
                            PlaceRecieve(34,obj,Ap);
                    }
                 else if(obj[12].GetLocat()==2)
                    {
                        obj[2].SetNum(obj[2].GetMon()+Money::kind);
                            PlaceRecieve(46,obj,Ap);
                    }

                obj[12].SetNum(obj[12].GetMon()-Money::kind);
                if(obj[12].GetMon()<Money::kind)obj[12].SetLocat(0);
                }
            if(obj[13].GetMon()>=Money::kind)
                {

                 if(obj[13].GetLocat()==1)
                    {
                        obj[1].SetNum(obj[1].GetMon()+Money::kind);
                            PlaceRecieve(35,obj,Ap);
                    }
                 else if(obj[13].GetLocat()==2)
                    {
                        obj[2].SetNum(obj[2].GetMon()+Money::kind);
                            PlaceRecieve(47,obj,Ap);
                    }

                obj[13].SetNum(obj[13].GetMon()-Money::kind);
                if(obj[13].GetMon()<Money::kind)obj[13].SetLocat(0);
                }
        }
    else if(Num==2)
        {
            if(obj[11].GetMon()>=Money::kind)
                {
                 if(obj[11].GetLocat()==1)
                    {
                        obj[1].SetNum(obj[1].GetMon()+Money::kind);
                            PlaceRecieve(33,obj,Ap);
                    }
                 else if(obj[11].GetLocat()==2)
                    {
                        obj[2].SetNum(obj[2].GetMon()+Money::kind);
                            PlaceRecieve(45,obj,Ap);
                    }
                obj[11].SetNum(obj[11].GetMon()-Money::kind);
                if(obj[11].GetMon()<Money::kind)obj[11].SetLocat(0);
                }
            if(obj[3].GetMon()>=Money::kind)
                {
                 if(obj[3].GetLocat()==1)
                    {
                        obj[1].SetNum(obj[1].GetMon()+Money::kind);
                            PlaceRecieve(25,obj,Ap);
                    }
                 else if(obj[3].GetLocat()==2)
                    {
                        obj[2].SetNum(obj[2].GetMon()+Money::kind);
                            PlaceRecieve(37,obj,Ap);
                    }
                obj[3].SetNum(obj[3].GetMon()-Money::kind);
                if(obj[3].GetMon()<Money::kind)obj[3].SetLocat(0);
                }
            if(obj[7].GetMon()>=Money::kind)
                {
                 if(obj[7].GetLocat()==1)
                    {
                        obj[1].SetNum(obj[1].GetMon()+Money::kind);
                            PlaceRecieve(29,obj,Ap);
                    }
                 else if(obj[7].GetLocat()==2)
                    {
                        obj[2].SetNum(obj[2].GetMon()+Money::kind);
                            PlaceRecieve(41,obj,Ap);
                    }
                obj[7].SetNum(obj[7].GetMon()-Money::kind);
                if(obj[7].GetMon()<Money::kind)obj[7].SetLocat(0);
                }
        }

    else if(Num==3)
        {
            if(obj[11].GetMon()>=Money::kind)
                {
                 if(obj[11].GetLocat()==1)
                    {
                        obj[1].SetNum(obj[1].GetMon()+Money::kind);
                            PlaceRecieve(33,obj,Ap);
                    }
                 else if(obj[11].GetLocat()==2)
                    {
                        obj[2].SetNum(obj[2].GetMon()+Money::kind);
                            PlaceRecieve(45,obj,Ap);
                    }
                obj[11].SetNum(obj[11].GetMon()-Money::kind);
                if(obj[11].GetMon()<Money::kind)obj[11].SetLocat(0);
                }
            if(obj[4].GetMon()>=Money::kind)
                {
                 if(obj[4].GetLocat()==1)
                    {
                        obj[1].SetNum(obj[1].GetMon()+Money::kind);
                            PlaceRecieve(26,obj,Ap);
                    }
                 else if(obj[4].GetLocat()==2)
                    {
                        obj[2].SetNum(obj[2].GetMon()+Money::kind);
                            PlaceRecieve(38,obj,Ap);
                    }
                obj[4].SetNum(obj[4].GetMon()-Money::kind);
                if(obj[4].GetMon()<Money::kind)obj[4].SetLocat(0);
                }
            if(obj[7].GetMon()>=Money::kind)
                {
                 if(obj[7].GetLocat()==1)
                    {
                        obj[1].SetNum(obj[1].GetMon()+Money::kind);
                            PlaceRecieve(29,obj,Ap);
                    }
                 else if(obj[7].GetLocat()==2)
                    {
                        obj[2].SetNum(obj[2].GetMon()+Money::kind);
                            PlaceRecieve(41,obj,Ap);
                    }
                obj[7].SetNum(obj[7].GetMon()-Money::kind);
                if(obj[7].GetMon()<Money::kind)obj[7].SetLocat(0);
                }
            if(obj[8].GetMon()>=Money::kind)
                {
                 if(obj[8].GetLocat()==1)
                    {
                        obj[1].SetNum(obj[1].GetMon()+Money::kind);
                            PlaceRecieve(30,obj,Ap);
                    }
                 else if(obj[8].GetLocat()==2)
                    {
                        obj[2].SetNum(obj[2].GetMon()+Money::kind);
                            PlaceRecieve(42,obj,Ap);
                    }
                obj[8].SetNum(obj[8].GetMon()-Money::kind);
                if(obj[8].GetMon()<Money::kind)obj[8].SetLocat(0);
                }
        }
    else if(Num==4)
        {
            if(obj[10].GetMon()>=Money::kind)
                {
                 if(obj[10].GetLocat()==1)
                    {
                        obj[1].SetNum(obj[1].GetMon()+Money::kind);
                            PlaceRecieve(32,obj,Ap);
                    }
                 else if(obj[10].GetLocat()==2)
                    {
                        obj[2].SetNum(obj[2].GetMon()+Money::kind);
                            PlaceRecieve(44,obj,Ap);
                    }
                obj[10].SetNum(obj[10].GetMon()-Money::kind);
                if(obj[10].GetMon()<Money::kind)obj[10].SetLocat(0);
                }
            if(obj[5].GetMon()>=Money::kind)
                {
                 if(obj[5].GetLocat()==1)
                    {
                        obj[1].SetNum(obj[1].GetMon()+Money::kind);
                            PlaceRecieve(27,obj,Ap);
                    }
                 else if(obj[5].GetLocat()==2)
                    {
                        obj[2].SetNum(obj[2].GetMon()+Money::kind);
                            PlaceRecieve(39,obj,Ap);
                    }
                obj[5].SetNum(obj[5].GetMon()-Money::kind);
                if(obj[5].GetMon()<Money::kind)obj[5].SetLocat(0);
                }
            if(obj[8].GetMon()>=Money::kind)
                {
                 if(obj[8].GetLocat()==1)
                    {
                        obj[1].SetNum(obj[1].GetMon()+Money::kind);
                            PlaceRecieve(30,obj,Ap);
                    }
                 else if(obj[8].GetLocat()==2)
                    {
                        obj[2].SetNum(obj[2].GetMon()+Money::kind);
                            PlaceRecieve(42,obj,Ap);
                    }
                obj[8].SetNum(obj[8].GetMon()-Money::kind);
                if(obj[8].GetMon()<Money::kind)obj[8].SetLocat(0);
                }
            if(obj[9].GetMon()>=Money::kind)
                {
                 if(obj[9].GetLocat()==1)
                    {
                        obj[1].SetNum(obj[1].GetMon()+Money::kind);
                            PlaceRecieve(31,obj,Ap);
                    }
                 else if(obj[9].GetLocat()==2)
                    {
                        obj[2].SetNum(obj[2].GetMon()+Money::kind);
                            PlaceRecieve(43,obj,Ap);
                    }
                obj[9].SetNum(obj[9].GetMon()-Money::kind);
                if(obj[9].GetMon()<Money::kind)obj[9].SetLocat(0);
                }
        }
    else if(Num==5)
        {
            if(obj[10].GetMon()>=Money::kind)
                {
                 if(obj[10].GetLocat()==1)
                    {
                        obj[1].SetNum(obj[1].GetMon()+Money::kind);
                            PlaceRecieve(32,obj,Ap);
                    }
                 else if(obj[10].GetLocat()==2)
                    {
                        obj[2].SetNum(obj[2].GetMon()+Money::kind);
                            PlaceRecieve(44,obj,Ap);
                    }
                obj[10].SetNum(obj[10].GetMon()-Money::kind);
                if(obj[10].GetMon()<Money::kind)obj[10].SetLocat(0);
                }
            if(obj[6].GetMon()>=Money::kind)
                {
                 if(obj[6].GetLocat()==1)
                    {
                        obj[1].SetNum(obj[1].GetMon()+Money::kind);
                            PlaceRecieve(28,obj,Ap);
                    }
                 else if(obj[6].GetLocat()==2)
                    {
                        obj[2].SetNum(obj[2].GetMon()+Money::kind);
                            PlaceRecieve(40,obj,Ap);
                    }
                obj[6].SetNum(obj[6].GetMon()-Money::kind);
                if(obj[6].GetMon()<Money::kind)obj[6].SetLocat(0);
                }
            if(obj[9].GetMon()>=Money::kind)
                {
                 if(obj[9].GetLocat()==1)
                    {
                        obj[1].SetNum(obj[1].GetMon()+Money::kind);
                            PlaceRecieve(31,obj,Ap);
                    }
                 else if(obj[9].GetLocat()==2)
                    {
                        obj[2].SetNum(obj[2].GetMon()+Money::kind);
                            PlaceRecieve(43,obj,Ap);
                    }
                obj[9].SetNum(obj[9].GetMon()-Money::kind);
                if(obj[9].GetMon()<Money::kind)obj[9].SetLocat(0);
                }

        }
    else if(Num==6)
        {
            if(obj[10].GetMon()>=Money::kind)
                {
                 if(obj[10].GetLocat()==1)
                    {
                        obj[1].SetNum(obj[1].GetMon()+Money::kind);
                            PlaceRecieve(32,obj,Ap);
                    }
                 else if(obj[10].GetLocat()==2)
                    {
                        obj[2].SetNum(obj[2].GetMon()+Money::kind);
                            PlaceRecieve(44,obj,Ap);
                    }
                obj[10].SetNum(obj[10].GetMon()-Money::kind);
                if(obj[10].GetMon()<Money::kind)obj[10].SetLocat(0);
                }
            if(obj[14].GetMon()>=Money::kind)
                {
                 if(obj[14].GetLocat()==1)
                    {
                        obj[1].SetNum(obj[1].GetMon()+Money::kind);
                            PlaceRecieve(36,obj,Ap);
                    }
                 else if(obj[14].GetLocat()==2)
                    {
                        obj[2].SetNum(obj[2].GetMon()+Money::kind);
                            PlaceRecieve(48,obj,Ap);
                    }
                obj[14].SetNum(obj[14].GetMon()-Money::kind);
                if(obj[14].GetMon()<Money::kind)obj[14].SetLocat(0);
                }
            if(obj[13].GetMon()>=Money::kind)
                {
                 if(obj[13].GetLocat()==1)
                    {
                        obj[1].SetNum(obj[1].GetMon()+Money::kind);
                            PlaceRecieve(35,obj,Ap);
                    }
                 else if(obj[13].GetLocat()==2)
                    {
                        obj[2].SetNum(obj[2].GetMon()+Money::kind);
                            PlaceRecieve(47,obj,Ap);
                    }
                obj[13].SetNum(obj[13].GetMon()-Money::kind);
                if(obj[13].GetMon()<Money::kind)obj[13].SetLocat(0);
        }}
       // SDL_Delay(5);
        for(int l=3;l<15;l++)
            if(obj[l].GetMon()>=Money::kind)
                return false;
    return true;
}
#endif
