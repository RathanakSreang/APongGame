#ifndef SAVE_H
#define SAVE_H

class Save{
private:
    double usermon;
    int monkind;
    int monSel;
    int montyp;
public:
    Save();
    Save(double u,int k,int s,int t);
    void setUsermon(double u);
    void setKindMon(int k);
    double getUserMon();
    int getMonKind();
    int getMonSel(){return monSel;}
    void setMonSel(int m){monSel=m;}
    int getMonTyp(){return montyp;}
    void setMonTyp(int m){montyp=m;}
};
Save::Save(){
usermon=0;
monkind=1;
monSel=0;
montyp=1;
}
Save::Save(double u,int k,int s,int t){
    usermon=u;
    monkind=k;
    monSel=s;
    montyp=t;
}
void Save::setUsermon(double u){
    usermon=u;
}
void Save::setKindMon(int k){
    monkind=k;
}
double Save::getUserMon(){
return usermon;
}
int Save::getMonKind(){
return monkind;
}
#endif
