#include "langai.h"
namespace ekr{

HANDLE konsole = GetStdHandle(STD_OUTPUT_HANDLE);

bool spalvaClass::setSpalva(short color){ // Nustatom fono spalva
    spalva=color;
    return true;
}
//--------------------------------------------------------------------------------
bool spalvaClass::setRemelioSpalva(short color){ // Nustatom remelio spalva
    remelioSpalva=color;
    return true;
}
//--------------------------------------------------------------------------------
short spalvaClass::getSpalva(){ // suteikiam fono splava
    return spalva;
}
//--------------------------------------------------------------------------------
short spalvaClass::getRemelioSpalva(){ // suteikiam remeliui spalva
    return remelioSpalva;
}
//--------------------------------------------------------------------------------
bool matmenysClass::setMatmenis(short X, short Y){ // nustatom pirmo kampo matmenis
    this->x=X;
    this->y=Y;
    return true;
}
//--------------------------------------------------------------------------------
void matmenysClass::getMatmenis(short& X, short& Y){ //suteikiam pirmam kampui matmenis
    X=this->x;
    Y=this->y;
}
//--------------------------------------------------------------------------------
bool matmenysClass::setMatmenis2(short X, short Y){ // nustatom antro kampo matmenis
    this->x2=X;
    this->y2=Y;
    return true;
}
//--------------------------------------------------------------------------------
void matmenysClass::getMatmenis2(short& X, short& Y){ //suteikiam antram kampui matmenis
    X=this->x2;
    Y=this->y2;
}
bool matmenysClass::setMatmenisTekstoPradzios(short X, short Y){
    this->xTeksto=X;
    this->yTeksto=Y;
}
void matmenysClass::getMatmenisTekstoPradzios(short& X, short& Y){ //suteikiam antram kampui matmenis
    X=this->xTeksto;
    Y=this->yTeksto;
}
//--------------------------------------------------------------------------------

void meniuClass::pridedamMeniuPunkta(std::string punktas){ // iskvietus sita funkcija, pridedam meniu punkta
    meniuPunktai.push_back(punktas);
    kiekis++;
}
//--------------------------------------------------------------------------------
void meniuClass::naikinam(){ // iskvietus sita funkcija, naikinam visus punktus
    meniuPunktai.clear();
    kiekis=0;

}
//--------------------------------------------------------------------------------

void infoClass::pridedamInfoPunkta(std::string punktas, int sk){
    infoPunktai.push_back(punktas);
    info.push_back(sk);
    kiekis++;
}
void infoClass::naikinam(bool punktus, bool info){ // iskvietus sita funkcija, naikinam visus punktus
    if(punktus==true)
    infoPunktai.clear();
    if(info==true)
    this->info.clear();
    kiekis=0;
}
//--------------------------------------------------------------------------------
pagrindinis::pagrindinis(){ // lango konstruktorius
setSpalva(0b01001110);
setRemelioSpalva(0b11001110);
setMatmenis(0,0);
setMatmenis2(79,32);
}
//--------------------------------------------------------------------------------
resursuTab::resursuTab(){ // teksto lango konstruktorius
setSpalva(0b01001110);
setMatmenis(0,0);
setMatmenis2(79,4);
}
//--------------------------------------------------------------------------------
meniuClass::meniuClass(){ // meniu konstruktorius
setSpalva(0b01001110);
setMatmenis(0,5);
setMatmenis2(24,20);
setMatmenisTekstoPradzios(4,0);
}
infoClass::infoClass(){
setSpalva(0b01001110);
setMatmenis(59,5);
setMatmenis2(79,20);
}
//--------------------------------------------------------------------------------

void pagrindinis::getLangasKoordinates(short& x1, short& x2, short& y1, short& y2){

    getMatmenis(x1,y1);
    getMatmenis2(x2,y2);
    if(x1>x2)std::swap(x1,x2);
    if(y1>y2)std::swap(y1,y2);
}
void resursuTab::getTekstoLangasKoordinates(short& x1, short& x2, short& y1, short& y2){ //gaunam nustatytas koordinates ir patikrinam ar "legalios"

    getMatmenis(x1,y1);
    getMatmenis2(x2,y2);
    if(x1>x2)std::swap(x1,x2);
    if(y1>y2)std::swap(y1,y2);
}
void meniuClass::getMeniuKoordinates(short& x1, short& x2, short& y1, short& y2){

    getMatmenis(x1,y1);
    getMatmenis2(x2,y2);
    if(x1>x2)std::swap(x1,x2);
    if(y1>y2)std::swap(y1,y2);
}
void infoClass::getInfoKoordinates(short& x1, short& x2, short& y1, short& y2){

    getMatmenis(x1,y1);
    getMatmenis2(x2,y2);
    if(x1>x2)std::swap(x1,x2);
    if(y1>y2)std::swap(y1,y2);
}
//--------------------------------------------------------------------------------
void pagrindinis::rodyk(){
    short X1Lang, X2Lang, Y1Lang, Y2Lang, remelis=1;
    getLangasKoordinates(X1Lang, X2Lang, Y1Lang, Y2Lang);

    COORD xy;
    xy.X=X1Lang;
    SetConsoleTextAttribute(konsole,getSpalva());
    for(short y=0; y<Y2Lang-Y1Lang+1; y++){
        xy.Y=Y1Lang+y;
        SetConsoleCursorPosition(konsole,xy);
        for(short x=0;x<X2Lang-X1Lang+1; x++){
            if((y<remelis || y>Y2Lang-Y1Lang-remelis) || (x<remelis || x>X2Lang-X1Lang-remelis)){
                //SetConsoleTextAttribute(konsole,getRemelioSpalva());
                    if((x==0 || x==X2Lang-X1Lang) && (y!=0 && y!=Y2Lang-Y1Lang))
                    std::cout<<char(186);
                    else if((y==0 || y==Y2Lang-Y1Lang) && (x!=0 && x!=X2Lang-X1Lang))
                    std::cout<<char(205);
                    else if(x==0 && y==0)
                    std::cout<<char(201);
                    else if(x==X2Lang-X1Lang && y==Y2Lang-Y1Lang)std::cout<<char(188);
                    else if(x==0 && y==Y2Lang-Y1Lang)std::cout<<char(200);
                    else if(x==X2Lang-X1Lang && y==0)std::cout<<char(187);
            }
            else{
                SetConsoleTextAttribute(konsole,getSpalva());
                std::cout<<' ';
            }
        }
    }
}
//--------------------------------------------------------------------------------
void resursuTab::rodyk(){
    short X1Lang, X2Lang, Y1Lang, Y2Lang, remelis=1, point, index=1,index2=1, languSk=6;
    getTekstoLangasKoordinates(X1Lang, X2Lang, Y1Lang, Y2Lang);
    point=((X2Lang-X1Lang)/languSk);
    COORD xy;
    xy.X=X1Lang;
    SetConsoleTextAttribute(konsole,getSpalva());
    for(short y=0; y<Y2Lang-Y1Lang+1; y++){//isvedam viska i ekrana
        xy.Y=Y1Lang+y;
        SetConsoleCursorPosition(konsole,xy);
        for(short x=0;x<X2Lang-X1Lang+1; x++){
            if(((y<remelis || y>Y2Lang-Y1Lang-remelis) || (x<remelis || x>X2Lang-X1Lang-remelis)) && y!=(Y2Lang-Y1Lang)/2){
                SetConsoleTextAttribute(konsole,getSpalva());
                    if((x==0 || x==X2Lang-X1Lang) && (y!=0 && y!=Y2Lang-Y1Lang))std::cout<<char(186); // ║
                    if((y==0 || y==Y2Lang-Y1Lang) && (x!=0 && (x!=point*index || x==X2Lang-X1Lang-(X2Lang-X1Lang-point*languSk)) && x!=point*index))std::cout<<char(205); //═
                    if(x==point*index && x+point<X2Lang && y==0 && x!=X2Lang-X1Lang){std::cout<<char(203);index++;}//╦
                    if(x==point*index && x+point<X2Lang && y==Y2Lang-Y1Lang && x!=X2Lang-X1Lang){std::cout<<char(202);index++;}//╩
                    if(x==0 && y==0)std::cout<<char(201);//╔
                    if(x==X2Lang-X1Lang && y==Y2Lang-Y1Lang)std::cout<<char(185);//╣
                    if(x==0 && y==Y2Lang-Y1Lang)std::cout<<char(204);//╠
                    if(x==X2Lang-X1Lang &&  y==0)std::cout<<char(187) ;//╗

            }
            else if(y==(Y2Lang-Y1Lang)/2)
            {
                if(x==0)std::cout<<char(199);//╟
                if((x!=point*index || x==X2Lang-X1Lang-(X2Lang-X1Lang-point*languSk)) && x!=X2Lang-X1Lang && x!=0 )std::cout<<char(196);//─
                if(x==point*index && x+point<X2Lang && x!=X2Lang-X1Lang){std::cout<<char(215);index++;}//╫
                if(x==X2Lang-X1Lang )std::cout<<char(182);//╢
            }
            else
            {
                if(x==point*index && y!=0 && y!=Y2Lang-Y1Lang && x!=X2Lang-X1Lang && x+point<X2Lang){std::cout<<char(186);index++;}//║
                else std::cout<<' ';
            }
        }
        index=1;
    }
    xy.X=1;
    xy.Y=1;
    SetConsoleCursorPosition(konsole,xy);
    std::cout<<"Mediena";
    xy.X=1+point;
    xy.Y=1;
    SetConsoleCursorPosition(konsole,xy);
    std::cout<<"Akmuo";
    xy.X=1+point*2;
    xy.Y=1;
    SetConsoleCursorPosition(konsole,xy);
    std::cout<<"Gelezis";
    xy.X=1+point*3;
    xy.Y=1;
    SetConsoleCursorPosition(konsole,xy);
    std::cout<<"Auksas";
    xy.X=1+point*4;
    xy.Y=1;
    SetConsoleCursorPosition(konsole,xy);
    std::cout<<"Maistas";
    xy.X=1+point*5;
    xy.Y=1;
    SetConsoleCursorPosition(konsole,xy);
    std::cout<<"Bedarbiai";
}
//--------------------------------------------------------------------------------
void meniuClass::rodyk(){
    short X1Lang, Y1Lang, X2Lang, Y2Lang, Xtxt, Ytxt;
    getMeniuKoordinates(X1Lang, X2Lang, Y1Lang, Y2Lang);
    COORD xy;
    xy.X=X1Lang;
    SetConsoleTextAttribute(konsole,getSpalva());

       for(short y=0; y<Y2Lang-Y1Lang+1; y++){
        xy.Y=Y1Lang+y;
        SetConsoleCursorPosition(konsole,xy);
        for(short x=0;x<X2Lang-X1Lang+1; x++){
            if((y<1 || y>Y2Lang-Y1Lang-1) || (x<1 || x>X2Lang-X1Lang-1)){
                    if((x==0 || x==X2Lang-X1Lang) && (y!=0 && y!=Y2Lang-Y1Lang))
                    std::cout<<char(186);
                    else if((y==0 || y==Y2Lang-Y1Lang) && (x!=0 && x!=X2Lang-X1Lang))
                    std::cout<<char(205);
                    else if(x==0 && y==0)
                    std::cout<<char(204);
                    else if(x==X2Lang-X1Lang && y==Y2Lang-Y1Lang)std::cout<<char(188);
                    else if(x==0 && y==Y2Lang-Y1Lang)std::cout<<char(204);
                    else if(x==X2Lang-X1Lang && y==0)std::cout<<char(187    );
            }
            else{
                SetConsoleTextAttribute(konsole,getSpalva());
                std::cout<<' ';
            }
        }
    }

    getMatmenisTekstoPradzios(Xtxt,Ytxt);
    for(int y=0; y<kiekis; y++){
        xy.X=Xtxt;
        xy.Y=Y1Lang+y+1;
        SetConsoleCursorPosition(konsole,xy);
        std::cout<<meniuPunktai[y];
    }


}
void infoClass::rodyk(bool kaire, bool suRemeliu){
short X1Lang, Y1Lang, X2Lang, Y2Lang;
    getInfoKoordinates(X1Lang, X2Lang, Y1Lang, Y2Lang);
    COORD xy;
    xy.X=X1Lang;
    SetConsoleTextAttribute(konsole,getSpalva());
    if(kaire==false){
        for(short y=0; y<Y2Lang-Y1Lang+1; y++){
        xy.Y=Y1Lang+y;
        SetConsoleCursorPosition(konsole,xy);
            for(short x=0;x<X2Lang-X1Lang+1; x++){
                if((y<1 || y>Y2Lang-Y1Lang-1) || (x<1 || x>X2Lang-X1Lang-1)){
                    //SetConsoleTextAttribute(konsole,getRemelioSpalva());
                        if((x==0 || x==X2Lang-X1Lang) && (y!=0 && y!=Y2Lang-Y1Lang))
                        std::cout<<char(186);
                        else if((y==0 || y==Y2Lang-Y1Lang) && (x!=0 && x!=X2Lang-X1Lang))
                        std::cout<<char(205);
                        else if(x==0 && y==0)
                        std::cout<<char(201);
                        else if(x==X2Lang-X1Lang && y==Y2Lang-Y1Lang)std::cout<<char(185);
                        else if(x==0 && y==Y2Lang-Y1Lang)std::cout<<char(200);
                        else if(x==X2Lang-X1Lang && y==0)std::cout<<char(185);
                }
                else{
                    SetConsoleTextAttribute(konsole,getSpalva());
                    std::cout<<' ';
                }
            }
        }
        for(int y=0; y<kiekis; y++){
            xy.Y=Y1Lang+y+1;
            xy.X=X1Lang+1;
            SetConsoleCursorPosition(konsole,xy);
            std::cout<<infoPunktai[y];
            xy.X=X2Lang-4;
            SetConsoleCursorPosition(konsole,xy);
            if(info[y]!=-1)
            std::cout<<info[y];
        }
    }
    else {
        if(suRemeliu==false){
        for(short y=0; y<Y2Lang-Y1Lang+1; y++){
        xy.Y=Y1Lang+y;
        SetConsoleCursorPosition(konsole,xy);
            for(short x=0;x<X2Lang-X1Lang+1; x++){
               /* if((y<1 || y>Y2Lang-Y1Lang-1) || (x<1 || x>X2Lang-X1Lang-1)){
                        if((x==0 || x==X2Lang-X1Lang) && (y!=0 && y!=Y2Lang-Y1Lang))
                        std::cout<<char(186);
                        else if((y==0 || y==Y2Lang-Y1Lang) && (x!=0 && x!=X2Lang-X1Lang))
                        std::cout<<char(205);
                        else if(x==0 && y==0)
                        std::cout<<char(204);
                        else if(x==X2Lang-X1Lang && y==Y2Lang-Y1Lang)std::cout<<char(188);
                        else if(x==0 && y==Y2Lang-Y1Lang)std::cout<<char(204);
                        else if(x==X2Lang-X1Lang && y==0)std::cout<<char(187    );*/
                //else{
                    SetConsoleTextAttribute(konsole,getSpalva());
                    std::cout<<' ';
                }
            }
            for(int y=0; y<kiekis; y++){
            xy.Y=Y1Lang+y;
            xy.X=X1Lang;
            SetConsoleCursorPosition(konsole,xy);
            std::cout<<infoPunktai[y];
            xy.X=X2Lang-4;
            SetConsoleCursorPosition(konsole,xy);
            if(info[y]!=-1)
            std::cout<<info[y];
            }
        }
        else{
            for(short y=0; y<Y2Lang-Y1Lang+1; y++){
                xy.Y=Y1Lang+y;
                SetConsoleCursorPosition(konsole,xy);
                for(short x=0;x<X2Lang-X1Lang+1; x++){
                    if((y<1 || y>Y2Lang-Y1Lang-1) || (x<1 || x>X2Lang-X1Lang-1)){
                    //SetConsoleTextAttribute(konsole,getRemelioSpalva());
                        if((x==0 || x==X2Lang-X1Lang) && (y!=0 && y!=Y2Lang-Y1Lang))
                        std::cout<<char(186);
                        else if((y==0 || y==Y2Lang-Y1Lang) && (x!=0 && x!=X2Lang-X1Lang))
                        std::cout<<char(205);
                        else if(x==0 && y==0)
                        std::cout<<char(201);
                        else if(x==X2Lang-X1Lang && y==Y2Lang-Y1Lang)std::cout<<char(188);
                        else if(x==0 && y==Y2Lang-Y1Lang)std::cout<<char(200);
                        else if(x==X2Lang-X1Lang && y==0)std::cout<<char(187);
                    }
                    else{
                        SetConsoleTextAttribute(konsole,getSpalva());
                        std::cout<<' ';
                    }
                }
            }
            for(int y=0; y<kiekis; y++){
            xy.Y=Y1Lang+y+1;
            xy.X=X1Lang+1;
            SetConsoleCursorPosition(konsole,xy);
            std::cout<<infoPunktai[y];
            xy.X=X2Lang-4;
            SetConsoleCursorPosition(konsole,xy);
            if(info[y]!=-1)
            std::cout<<info[y];
            }
        }
        }
}





}  //End of namespace ekr

