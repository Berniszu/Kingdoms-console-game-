#define _GLIBCXX_USE_CXX11_ABI 0
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13


#include <iostream>
#include "langai.h"
#include <cstdio>
#include <conio.h>
#include <thread>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

HANDLE konsole = GetStdHandle(STD_OUTPUT_HANDLE);

void showConsoleCursor( bool showFlag){
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(konsole,&cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(konsole, &cursorInfo);
}

void SetWindow(int Width, int Height){
    _COORD coord;
    coord.X = Width+1;
    coord.Y = Height+1;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Height+1;
    Rect.Right = Width+1;

    SetConsoleScreenBufferSize(konsole, coord);            // Set Buffer Size
    SetConsoleWindowInfo(konsole, TRUE, &Rect);            // Set Window Size
}

void gotoxy(int x, int y){
    COORD xy;
    xy.X=x;
    xy.Y=y;
    SetConsoleCursorPosition(konsole,xy);
}
class formules{
public:
    int tobulinimoFormule(int lvl,double base,double kof)
    {
        double kaina;
        double pradinisKof=kof;
        if(lvl!=0)
        {
            for(int i=0; i<lvl; i++)
            {
                kaina=base*kof;
                kof=kof*pradinisKof;
            }
            return (int)kaina;
        }
        else return (int)base;
    }
    double resursuFormule(int lvl,double base,double kof)
    {
        double kaina;
        double pradinisKof=kof;
        if(lvl!=0)
        {
            for(int i=0; i<lvl; i++)
            {
                kaina=base*kof;
                //gotoxy(30,8+i);
                // cout<<kof;
                kof=kof*pradinisKof;
            }
            return kaina;
        }
        else return base;
    }

};
//----------------------------------------------------------------------------------
class meniuLenteles{// meniu lenteliu ir pranesimu lango funkcijos
public:
    ekr::meniuClass meniu, msgBox, save;
    void pradinisMeniu(){
        meniu.naikinam();
        meniu.setMatmenis(0,5);
        meniu.setMatmenis2(28,8);
        meniu.pridedamMeniuPunkta("Naujas zaidimas");
        meniu.pridedamMeniuPunkta("Uzkrauti sena zaidima");
        meniu.rodyk();
    }
    void seniZaidimai(string seivas[], short seivuSk){
        save.setMatmenis(0,5);
        save.setMatmenis2(28,20);
        for(int i=0; i<seivuSk; i++){
            save.pridedamMeniuPunkta(seivas[i]);
        }
        save.rodyk();
        save.naikinam();

    }
    void pagrindinisMeniu(){
        meniu.naikinam();
        meniu.setMatmenis(0,5);
        meniu.setMatmenis2(24,20);
        meniu.pridedamMeniuPunkta("Pastatu pirkimas");
        meniu.pridedamMeniuPunkta("Darb. paskyrimas");
        meniu.pridedamMeniuPunkta("Kariu treniravimas");
        meniu.pridedamMeniuPunkta("Bedarbiu pirkimas");
        meniu.pridedamMeniuPunkta("Priesai");
        meniu.pridedamMeniuPunkta("Pradeti darbus");
        meniu.rodyk();
    }
    void pastataiMeniu(){
        meniu.naikinam();
        meniu.pridedamMeniuPunkta("Lentpjuve");
        meniu.pridedamMeniuPunkta("Akmens Kasykla");
        meniu.pridedamMeniuPunkta("Gelezies Kasykla");
        meniu.pridedamMeniuPunkta("Aukso kasykla");
        meniu.pridedamMeniuPunkta("Ferma");
        meniu.pridedamMeniuPunkta("Kareivines");
        meniu.pridedamMeniuPunkta("Gynybine siena");
        meniu.pridedamMeniuPunkta("<<-");
        meniu.rodyk();
    }
    void taipNeMeniu(){
        meniu.naikinam();
        meniu.pridedamMeniuPunkta("Taip");
        meniu.pridedamMeniuPunkta("Ne");
        meniu.rodyk();
    }
    void darbuotojaiMeniu(){
        meniu.naikinam();
        meniu.pridedamMeniuPunkta("Medkirciai");
        meniu.pridedamMeniuPunkta("Akmenskaldziai");
        meniu.pridedamMeniuPunkta("Gelezkasiai");
        meniu.pridedamMeniuPunkta("Auksakasiai");
        meniu.pridedamMeniuPunkta("Ukininkai");
        meniu.pridedamMeniuPunkta("<<-");
        meniu.rodyk();
    }
    void kareiviaiMeniu(){

        meniu.naikinam();
        meniu.pridedamMeniuPunkta("Apginkl. bedarbiai.");
        meniu.pridedamMeniuPunkta("Lengvieji pest.");
        meniu.pridedamMeniuPunkta("Sunkieji pest.");
        meniu.pridedamMeniuPunkta("Lankininkai");
        meniu.pridedamMeniuPunkta("Lengvoji kav.");
        meniu.pridedamMeniuPunkta("Sunkioji kav.");
        meniu.pridedamMeniuPunkta("<<-");
        meniu.rodyk();
    }
    void kareiviniuLvlMsgBox(int lvl,int minLvl){
        msgBox.naikinam();
        msgBox.setMatmenis(0,21);
        msgBox.setMatmenis2(30,31);
        msgBox.setMatmenisTekstoPradzios(1,0);
        msgBox.pridedamMeniuPunkta("Per mazas kareiviniu lygis!");
        msgBox.pridedamMeniuPunkta("Reikiamas lygis: ");
        msgBox.pridedamMeniuPunkta("Jusu kareiviniu lygis: ");
        msgBox.rodyk();
        gotoxy(18,23);
        cout<<minLvl;
        gotoxy(24,24);
        cout<<lvl;
    }
    void prastoLaikoMsgBox(){
        msgBox.naikinam();
        msgBox.setMatmenis(0,21);
        msgBox.setMatmenis2(30,31);
        msgBox.setMatmenisTekstoPradzios(1,0);
        msgBox.pridedamMeniuPunkta("Ivestas blogas darbo valandu ");
        msgBox.pridedamMeniuPunkta("skaicius!");
        msgBox.pridedamMeniuPunkta("Tinka nuo 1 iki 60");
        msgBox.rodyk();
    }
    void pradinisMsgBox(){
        msgBox.setMatmenis(0,21);
        msgBox.setMatmenis2(30,31);
        msgBox.pridedamMeniuPunkta("");
        msgBox.pridedamMeniuPunkta("");
        msgBox.pridedamMeniuPunkta("   PRANESIMU LANGAS");
        msgBox.rodyk();
    }
    void nepakankamuResursuMsgBox(){
        msgBox.naikinam();
        msgBox.setMatmenis(0,21);
        msgBox.setMatmenis2(30,31);
        msgBox.setMatmenisTekstoPradzios(1,0);
        msgBox.pridedamMeniuPunkta("");
        msgBox.pridedamMeniuPunkta("");
        msgBox.pridedamMeniuPunkta("Nepakankamas resursu kiekis!!");
        msgBox.rodyk();
    }
    void neraBedarbiuMsgBox(){
        msgBox.naikinam();
        msgBox.setMatmenis(0,21);
        msgBox.setMatmenis2(30,31);
        msgBox.setMatmenisTekstoPradzios(1,0);
        msgBox.pridedamMeniuPunkta("");
        msgBox.pridedamMeniuPunkta("");
        msgBox.pridedamMeniuPunkta("Visi gyventojai uzimti!!");
        msgBox.rodyk();
    }
    void kariuKainosMsgBox(double mediena,double akmuo,double gelezis,double auksas, double laikas){

        msgBox.naikinam();
        msgBox.setMatmenis(0,21);
        msgBox.setMatmenis2(30,31);
        msgBox.setMatmenisTekstoPradzios(1,0);
        msgBox.pridedamMeniuPunkta("Vieno kario trenirav. kaina:");
        msgBox.pridedamMeniuPunkta("Mediena:");
        msgBox.pridedamMeniuPunkta("Akmuo:");
        msgBox.pridedamMeniuPunkta("Gelezis:");
        msgBox.pridedamMeniuPunkta("Auksas:");
        msgBox.pridedamMeniuPunkta("Treniravimo laikas:");
        msgBox.rodyk();
        gotoxy(11,23);
        cout<<mediena;
        gotoxy(11,24);
        cout<<akmuo;
        gotoxy(11,25);
        cout<<gelezis;
        gotoxy(11,26);
        cout<<auksas;
        gotoxy(21,27);
        cout<<laikas;
    }
    void blogoKiekoMsgBox(){
        msgBox.naikinam();
        msgBox.setMatmenis(0,21);
        msgBox.setMatmenis2(30,31);
        msgBox.pridedamMeniuPunkta("Ivestas netinkamas kiekis!");
        msgBox.rodyk();
    }
    void bedarbioKainaMsgBox(){
        msgBox.naikinam();
        msgBox.setMatmenis(0,21);
        msgBox.setMatmenis2(30,31);
        msgBox.setMatmenisTekstoPradzios(1,0);
        msgBox.pridedamMeniuPunkta("Vieno bedarbio pirkimo kaina:");
        msgBox.pridedamMeniuPunkta("Maisto:");
        msgBox.rodyk();
        gotoxy(9,23);
        cout<<"100";
    }
    void nenupirktoPastatoMsgBox(string a){
        msgBox.naikinam();
        msgBox.setMatmenis(0,21);
        msgBox.setMatmenis2(30,31);
        msgBox.setMatmenisTekstoPradzios(1,0);
        msgBox.pridedamMeniuPunkta("Nera galimybes paskirti");
        msgBox.pridedamMeniuPunkta("darbuotoju.");
        msgBox.pridedamMeniuPunkta(a);
        msgBox.rodyk();
    }
    void priesuMeniu(){
        meniu.naikinam();
        meniu.pridedamMeniuPunkta("Goblinu stovyklav");
        meniu.pridedamMeniuPunkta("Orku stovyklaviete");
        meniu.pridedamMeniuPunkta("Goblinu urvas");
        meniu.pridedamMeniuPunkta("Orku kaimas");
        meniu.pridedamMeniuPunkta("Goblinu pozemiai");
        meniu.pridedamMeniuPunkta("Orku gynybine siena");
        meniu.pridedamMeniuPunkta("Orku HQ");
        meniu.pridedamMeniuPunkta("<<-");
        meniu.rodyk();
    }
};
class priesai{
private:
    int apginkluotiBedarbiaiGalia=10, lengviejiPestininkaiGalia=20, sunkiejiPestininkaiGalia=50, lankininkaiGalia=40, lengvojikavalerijaGalia=70, sunkiojiKavalerijaGalia=100;
    int goblinuGalia=12, orkuPestininkuGalia=20, orkuLankininkuGalia=20, orkuKavalerijosGalia=60;
public:
    ekr::infoClass kovosInfo;
    //----------------------------------------------------------------------------------
    //Kovos lauko vaizdavimo funkcijos
    void kovaLaimeta()
    {
        kovosInfo.naikinam(true,true);
        kovosInfo.setMatmenis(25,8);
        kovosInfo.setMatmenis2(55,20);
        kovosInfo.pridedamInfoPunkta("",-1);
        kovosInfo.pridedamInfoPunkta("",-1);
        kovosInfo.pridedamInfoPunkta("",-1);
        kovosInfo.pridedamInfoPunkta("",-1);
        kovosInfo.pridedamInfoPunkta("        KOVA LAIMETA!!",-1);
        kovosInfo.rodyk(true,true);
    }
    void kovaPralaimeta()
    {
        kovosInfo.naikinam(true,true);
        kovosInfo.setMatmenis(25,8);
        kovosInfo.setMatmenis2(55,20);
        kovosInfo.pridedamInfoPunkta("",-1);
        kovosInfo.pridedamInfoPunkta("",-1);
        kovosInfo.pridedamInfoPunkta("",-1);
        kovosInfo.pridedamInfoPunkta("",-1);
        kovosInfo.pridedamInfoPunkta("       KOVA PRALAIMETA!!",-1);
        kovosInfo.rodyk(true,true);
    }
    void kovosLaukasPriesGoblinus()
    {
        kovosInfo.naikinam(true,true);
        kovosInfo.setMatmenis(25,8);
        kovosInfo.setMatmenis2(55,20);
        kovosInfo.pridedamInfoPunkta("        Vyksta kova!!!",-1);
        kovosInfo.pridedamInfoPunkta("",-1);
        kovosInfo.pridedamInfoPunkta("Jusu kariai     prieso kariai",-1);
        kovosInfo.pridedamInfoPunkta("", -1);
        kovosInfo.pridedamInfoPunkta("             VS", -1);
        kovosInfo.pridedamInfoPunkta(" A. b.               Goblinai", -1);
        kovosInfo.pridedamInfoPunkta(" L. p.",-1);
        kovosInfo.pridedamInfoPunkta(" S. p.",-1);
        kovosInfo.pridedamInfoPunkta(" Lank.",-1);
        kovosInfo.pridedamInfoPunkta(" L. k.",-1);
        kovosInfo.pridedamInfoPunkta(" S. k.",-1);
        kovosInfo.rodyk(true,true);
    }
    void kovosLaukasPriesOrkus()
    {
        kovosInfo.naikinam(true,true);
        kovosInfo.setMatmenis(25,8);
        kovosInfo.setMatmenis2(55,20);
        kovosInfo.pridedamInfoPunkta("        Vyksta kova!!!",-1);
        kovosInfo.pridedamInfoPunkta("",-1);
        kovosInfo.pridedamInfoPunkta("Jusu kariai     prieso kariai",-1);
        kovosInfo.pridedamInfoPunkta("", -1);
        kovosInfo.pridedamInfoPunkta("             ", -1);
        kovosInfo.pridedamInfoPunkta(" A. b.             Orku pest.", -1);
        kovosInfo.pridedamInfoPunkta(" L. p.             Orku lank.",-1);
        kovosInfo.pridedamInfoPunkta(" S. p.             Orku kava.",-1);
        kovosInfo.pridedamInfoPunkta(" Lank.",-1);
        kovosInfo.pridedamInfoPunkta(" L. k.",-1);
        kovosInfo.pridedamInfoPunkta(" S. k.",-1);
        kovosInfo.rodyk(true,true);
    }
    //----------------------------------------------------------------------------------
    // gaunam zaidejo kariu bendra galia, pagal kuria ziuresim ar laimes ar ne
    int zaidejoKariuGaliosSkaiciuokle(bool arPuola, int sienosLvl, int&a,int&b,int&c,int&d,int&e)
    {
        int zaidejoKariuGalia;
        int a2,b2,c2,d2,e2;
        if(a>0)a2=a*apginkluotiBedarbiaiGalia;
        else a2=1;
        if(b>0)b2=b*lengviejiPestininkaiGalia;
        else b2=1;
        if(c>0)c2=c*sunkiejiPestininkaiGalia;
        else c2=1;
        if(d>0)d2=d*lengvojikavalerijaGalia;
        else d2=1;
        if(e>0)e2=e*sunkiojiKavalerijaGalia;
        else e2=1;
        zaidejoKariuGalia=rand()%a2+rand()%b2+rand()%c2+rand()%d2+rand()%e2;
        if(arPuola==true)
            return zaidejoKariuGalia*(double)(1+sienosLvl/10);
        else return zaidejoKariuGalia;
    }
    //----------------------------------------------------------------------------------
    // si funkcija atsakinga uz kario praradima
    void zaidejoPrarastasKarys(int&a,int&b,int&c,int&d,int&e,int&f)
    {
        int a2,b2,c2,d2,e2,f2;
        if(a>0)a2=rand()%60;
        else a2=0;
        if(b>0)b2=rand()%40;
        else b2=0;
        if(c>0)c2=rand()%30;
        else c2=0;
        if(d>0)d2=rand()%30;
        else d2=0;
        if(e>0)e2=rand()%20;
        else e2=0;
        if(f>0)f2=rand()%10;
        else f2=0;

        if(a>0)
            if(a2>b2 && a2>c2 && a2>d2 && a2>e2 && a2>f2)a--;
        if(b>0)
            if(b2>a2 && b2>c2 && b2>d2 && b2>e2 && b2>f2)b--;
        if(c>0)
            if(c2>b2 && c2>a2 && c2>d2 && c2>e2 && c2>f2)c--;
        if(d>0)
            if(d2>b2 && d2>c2 && d2>a2 && d2>e2 && d2>f2)d--;
        if(e>0)
            if(e2>b2 && e2>c2 && e2>d2 && e2>a2 && e2>f2)e--;
        if(f>0)
            if(f2>b2 && f2>c2 && f2>d2 && f2>e2 && f2>a2)f--;
    }
    //----------------------------------------------------------------------------------
    // sios funkcijos atsakingos uz musio eiga ir tipa
    void goblinuAtaka(bool arPuola, int sienosLvl,bool&arLaimeta,int&apginkluotiBedarbiai,int &lengviejiPestininkai,int &sunkiejiPestininkai,int &lankininkai,int &lengvojikavalerija,int &sunkiojiKavalerija, int goblinuSk, double&medienaRes,double&akmuoRes,double&gelezisRes,double&auksasRes,double&maistasRes)
    {
        int zaidejoKariuGalia, zaidejoLankininkuGalia, priesoKariuGalia, priesoLankininkuGalia=0;
        int zaidejokariuKiekis=apginkluotiBedarbiai+lengviejiPestininkai+sunkiejiPestininkai+lankininkai+lengvojikavalerija+sunkiojiKavalerija;
        int priesokariuKiekis=goblinuSk;
        int pradinisGoblinuSkaicius=goblinuSk;
        kovosLaukasPriesGoblinus();
        while(zaidejokariuKiekis>0 && priesokariuKiekis>0)
        {
            zaidejoKariuGalia=zaidejoKariuGaliosSkaiciuokle(arPuola,sienosLvl,apginkluotiBedarbiai,lengviejiPestininkai,sunkiejiPestininkai,lengvojikavalerija,sunkiojiKavalerija);

            if(lankininkai>0)zaidejoLankininkuGalia=rand()%(lankininkai*lankininkaiGalia);
            else zaidejoLankininkuGalia=0;
            priesoKariuGalia=rand()%(goblinuSk*goblinuGalia);
            if(zaidejoKariuGalia<priesoKariuGalia)zaidejoPrarastasKarys(apginkluotiBedarbiai,lengviejiPestininkai,lankininkai,sunkiejiPestininkai,lengvojikavalerija,sunkiojiKavalerija);
            else if(zaidejoKariuGalia>priesoKariuGalia)goblinuSk--;
            if(zaidejoLankininkuGalia<priesoLankininkuGalia)zaidejoPrarastasKarys(apginkluotiBedarbiai,lengviejiPestininkai,lankininkai,sunkiejiPestininkai,lengvojikavalerija,sunkiojiKavalerija);
            else if(zaidejoLankininkuGalia>priesoLankininkuGalia)goblinuSk--;
            zaidejokariuKiekis=apginkluotiBedarbiai+lengviejiPestininkai+sunkiejiPestininkai+lankininkai+lengvojikavalerija+sunkiojiKavalerija;
            {
                priesokariuKiekis=goblinuSk;
                gotoxy(32,14);
                cout<<"    ";
                gotoxy(32,14);
                cout<<apginkluotiBedarbiai;
                gotoxy(32,15);
                cout<<"    ";
                gotoxy(32,15);
                cout<<lengviejiPestininkai;
                gotoxy(32,16);
                cout<<"    ";
                gotoxy(32,16);
                cout<<sunkiejiPestininkai;
                gotoxy(32,17);
                cout<<"    ";
                gotoxy(32,17);
                cout<<lankininkai;
                gotoxy(32,18);
                cout<<"    ";
                gotoxy(32,18);
                cout<<lengvojikavalerija;
                gotoxy(32,19);
                cout<<"    ";
                gotoxy(32,19);
                cout<<sunkiojiKavalerija;
                //--------------------
                gotoxy(42,14);
                cout<<"    ";
                gotoxy(42,14);
                cout<<goblinuSk;
            }
            Sleep(200);
        }
        if(zaidejokariuKiekis>0)
        {
            medienaRes=medienaRes+3*pradinisGoblinuSkaicius;
            akmuoRes=akmuoRes+2*pradinisGoblinuSkaicius;
            gelezisRes=gelezisRes+1*pradinisGoblinuSkaicius;
            auksasRes=auksasRes+0.5*pradinisGoblinuSkaicius;
            maistasRes=maistasRes+4*pradinisGoblinuSkaicius;
            arLaimeta=true;
            kovaLaimeta();
        }
        else if(zaidejokariuKiekis<=0 && priesokariuKiekis>0)
        {
            if(medienaRes>=3*priesokariuKiekis)
                medienaRes=medienaRes-3*priesokariuKiekis;
            else medienaRes=medienaRes-medienaRes;

            if(akmuoRes>=2*priesokariuKiekis)
                akmuoRes=akmuoRes-2*priesokariuKiekis;
            else akmuoRes=akmuoRes-akmuoRes;

            if(gelezisRes>=1*priesokariuKiekis)
                gelezisRes=gelezisRes-1*priesokariuKiekis;
            else gelezisRes=gelezisRes-gelezisRes;

            if(auksasRes>=0.5*priesokariuKiekis)
                auksasRes=auksasRes-0.5*priesokariuKiekis;
            else auksasRes=auksasRes-auksasRes;

            if(maistasRes>=4*priesokariuKiekis)
                maistasRes=maistasRes-4*priesokariuKiekis;
            else maistasRes=maistasRes-maistasRes;
            arLaimeta=false;
            kovaPralaimeta();
        }

    }
    void orkuAtaka(bool arPuola, int sienosLvl,bool&arLaimeta,int&apginkluotiBedarbiai,int &lengviejiPestininkai,int &sunkiejiPestininkai,int &lankininkai,int &lengvojikavalerija,int &sunkiojiKavalerija, int orkuPestininkai, int orkuLankininkai,int orkuKavalerija, double&medienaRes,double&akmuoRes,double&gelezisRes,double&auksasRes,double&maistasRes)
    {
        int zaidejoKariuGalia, zaidejoLankininkuGalia, priesoKariuGalia, priesoLankininkuGalia;
        int zaidejokariuKiekis=apginkluotiBedarbiai+lengviejiPestininkai+sunkiejiPestininkai+lankininkai+lengvojikavalerija+sunkiojiKavalerija;
        int priesoKariuKiekis=orkuPestininkai+orkuLankininkai+orkuKavalerija;
        int pradinisOrkuSkaicius=priesoKariuKiekis;
        int a2,b2;
        int a3,b3,c3;
        int a4,b4,c4;
        kovosLaukasPriesOrkus();
        //--------------------------
        while(zaidejokariuKiekis>0 && priesoKariuKiekis>0)
        {
            zaidejoKariuGalia=zaidejoKariuGaliosSkaiciuokle(arPuola,sienosLvl,apginkluotiBedarbiai,lengviejiPestininkai,sunkiejiPestininkai,lengvojikavalerija,sunkiojiKavalerija);
            //--------------------------
            if(lankininkai>0)zaidejoLankininkuGalia=rand()%(lankininkai*lankininkaiGalia);
            else zaidejoLankininkuGalia=0;
            //--------------------------
            if(orkuPestininkai>0)a2=orkuPestininkai*apginkluotiBedarbiaiGalia;
            else a2=1;
            if(orkuKavalerija>0)b2=orkuKavalerija*sunkiejiPestininkaiGalia;
            else b2=1;
            priesoKariuGalia=rand()%a2+rand()%b2;
            //--------------------------
            if(orkuLankininkai>0)priesoLankininkuGalia=rand()%(orkuLankininkai*orkuLankininkuGalia);
            else priesoLankininkuGalia=0;
            //--------------------------
            if(zaidejoKariuGalia<priesoKariuGalia)zaidejoPrarastasKarys(apginkluotiBedarbiai,lengviejiPestininkai,lankininkai,sunkiejiPestininkai,lengvojikavalerija,sunkiojiKavalerija);
            else if(zaidejoKariuGalia>priesoKariuGalia)
            {
                if(orkuPestininkai>0)a3=rand()%60;
                else a3=0;
                if(orkuLankininkai>0)b3=rand()%40;
                else b3=0;
                if(orkuKavalerija>0)c3=rand()%30;
                else c3=0;

                if(orkuPestininkai>0)
                    if(a3>b3 && a3>c3)orkuPestininkai--;
                if(orkuLankininkai>0)
                    if(b3>a3 && b3>c3)orkuLankininkai--;
                if(orkuKavalerija>0)
                    if(c3>b3 && c3>a3)orkuKavalerija--;
            }
            //--------------------------
            if(zaidejoLankininkuGalia<priesoLankininkuGalia)zaidejoPrarastasKarys(apginkluotiBedarbiai,lengviejiPestininkai,lankininkai,sunkiejiPestininkai,lengvojikavalerija,sunkiojiKavalerija);
            else if(zaidejoLankininkuGalia>priesoLankininkuGalia)
            {

                if(orkuPestininkai>0)a4=rand()%60;
                else a4=0;
                if(orkuLankininkai>0)b4=rand()%40;
                else b4=0;
                if(orkuKavalerija>0)c4=rand()%30;
                else c4=0;

                if(orkuPestininkai>0)
                    if(a4>b4 && a4>c4)orkuPestininkai--;
                if(orkuLankininkai>0)
                    if(b4>a4 && b4>c4)orkuLankininkai--;
                if(orkuKavalerija>0)
                    if(c4>b4 && c4>a4)orkuKavalerija--;
            }
            //--------------------------
            zaidejokariuKiekis=apginkluotiBedarbiai+lengviejiPestininkai+sunkiejiPestininkai+lankininkai+lengvojikavalerija+sunkiojiKavalerija;
            priesoKariuKiekis=orkuPestininkai+orkuLankininkai+orkuKavalerija;
            //--------------------------
            {
                gotoxy(32,14);
                cout<<"    ";
                gotoxy(32,14);
                cout<<apginkluotiBedarbiai;
                gotoxy(32,15);
                cout<<"    ";
                gotoxy(32,15);
                cout<<lengviejiPestininkai;
                gotoxy(32,16);
                cout<<"    ";
                gotoxy(32,16);
                cout<<sunkiejiPestininkai;
                gotoxy(32,17);
                cout<<"    ";
                gotoxy(32,17);
                cout<<lankininkai;
                gotoxy(32,18);
                cout<<"    ";
                gotoxy(32,18);
                cout<<lengvojikavalerija;
                gotoxy(32,19);
                cout<<"    ";
                gotoxy(32,19);
                cout<<sunkiojiKavalerija;
                //--------------------
                gotoxy(41,14);
                cout<<"    ";
                gotoxy(41,14);
                cout<<orkuPestininkai;
                gotoxy(41,15);
                cout<<"    ";
                gotoxy(41,15);
                cout<<orkuLankininkai;
                gotoxy(41,16);
                cout<<"    ";
                gotoxy(41,16);
                cout<<orkuKavalerija;
            }
            //--------------------------
            Sleep(200);
        }
        //--------------------------
        if(zaidejokariuKiekis>0)
        {
            medienaRes=medienaRes+7*pradinisOrkuSkaicius;
            akmuoRes=akmuoRes+5*pradinisOrkuSkaicius;
            gelezisRes=gelezisRes+4*pradinisOrkuSkaicius;
            auksasRes=auksasRes+3*pradinisOrkuSkaicius;
            maistasRes=maistasRes+9*pradinisOrkuSkaicius;
            arLaimeta=true;
        }
        else if(zaidejokariuKiekis<=0 && priesoKariuKiekis>0)
        {
            if(medienaRes>=6*priesoKariuKiekis)
                medienaRes=medienaRes-6*priesoKariuKiekis;
            else medienaRes=medienaRes-medienaRes;

            if(akmuoRes>=4*priesoKariuKiekis)
                akmuoRes=akmuoRes-4*priesoKariuKiekis;
            else akmuoRes=akmuoRes-akmuoRes;

            if(gelezisRes>=3*priesoKariuKiekis)
                gelezisRes=gelezisRes-3*priesoKariuKiekis;
            else gelezisRes=gelezisRes-gelezisRes;

            if(auksasRes>=2*priesoKariuKiekis)
                auksasRes=auksasRes-2*priesoKariuKiekis;
            else auksasRes=auksasRes-auksasRes;

            if(maistasRes>=8*priesoKariuKiekis)
                maistasRes=maistasRes-8*priesoKariuKiekis;
            else maistasRes=maistasRes-maistasRes;
            arLaimeta=false;
        }
    }
    //----------------------------------------------------------------------------------
};
//----------------------------------------------------------------------------------
class kareiviai:public meniuLenteles{

public:
    void kariuTreniravimas(int sk,int&laisvigyventojaiSk, int&kariuTipas, double&treniravimoLaikas,double laikas, double mediena, double akmuo, double gelezis, double auksas,double&medienaRes, double&akmuoRes, double&gelezisRes, double&auksasRes)
    {
        if(sk*mediena<=medienaRes && sk*akmuo<=akmuoRes && sk*gelezis<=gelezisRes && sk*auksas<=auksasRes)
        {
            if(sk<=laisvigyventojaiSk && sk>=0)
            {
                medienaRes=medienaRes-mediena*sk;
                akmuoRes=akmuoRes-akmuo*sk;
                gelezisRes=gelezisRes-gelezis*sk;
                auksasRes=auksasRes-auksas*sk;
                //-----
                laisvigyventojaiSk=laisvigyventojaiSk-sk;
                kariuTipas=kariuTipas+sk;
                treniravimoLaikas=treniravimoLaikas+sk*laikas;
            }
            else if(sk>laisvigyventojaiSk)
            {
                medienaRes=medienaRes-mediena*laisvigyventojaiSk;
                akmuoRes=akmuoRes-akmuo*laisvigyventojaiSk;
                gelezisRes=gelezisRes-gelezis*laisvigyventojaiSk;
                auksasRes=auksasRes-auksas*laisvigyventojaiSk;
                //-----
                treniravimoLaikas=treniravimoLaikas+laisvigyventojaiSk*laikas;
                kariuTipas=kariuTipas+laisvigyventojaiSk;
                laisvigyventojaiSk=laisvigyventojaiSk-laisvigyventojaiSk;
            }
            else if(sk>=-kariuTipas && sk<0)
            {
                medienaRes=medienaRes-mediena*sk;
                akmuoRes=akmuoRes-akmuo*sk;
                gelezisRes=gelezisRes-gelezis*sk;
                auksasRes=auksasRes-auksas*sk;
                //-----
                laisvigyventojaiSk=laisvigyventojaiSk-sk;
                kariuTipas=kariuTipas+sk;
                treniravimoLaikas=treniravimoLaikas+sk*laikas;
            }
            else if(sk<-kariuTipas)
            {
                medienaRes=medienaRes+mediena*kariuTipas;
                akmuoRes=akmuoRes+akmuo*kariuTipas;
                gelezisRes=gelezisRes+gelezis*kariuTipas;
                auksasRes=auksasRes+auksas*kariuTipas;
                //-----
                treniravimoLaikas=treniravimoLaikas+kariuTipas*laikas;
                laisvigyventojaiSk=laisvigyventojaiSk+kariuTipas;
                kariuTipas=kariuTipas-kariuTipas;
            }
        }
        else nepakankamuResursuMsgBox();

    }
    void kariuTreniravimas2(int&kariuTipas,int&kariuTipasPskirti,double&kariuTipoLaikas,int x, int y,int x2, int y2)
    {
        if(kariuTipasPskirti>0 && kariuTipoLaikas>0)
        {
            kariuTipoLaikas--;
            gotoxy(x,y);
            cout<<kariuTipoLaikas;
            if(kariuTipoLaikas<=0)
            {
                kariuTipas=kariuTipas+kariuTipasPskirti;
                kariuTipasPskirti=kariuTipasPskirti-kariuTipasPskirti;
                gotoxy(x,y);
                cout<<"    ";
                gotoxy(x,y);
                cout<<'-';
                gotoxy(x2,y2);
                cout<<"    ";
                gotoxy(x2,y2);
                cout<<'-';

            }
        }
    }
};
//----------------------------------------------------------------------------------
class tobulinimai: public formules{
private:
    //bool arTobulinti=false, arGalimas=false;
public:
    //----------------------------------------------------------------------------------
    // sios funkcijos atsakingos uz pastatu tobulinima
    void lentpjuvesFermosTobulinimas(double&medienaRes,double&akmuoRes,double&gelezisRes,double&auksasRes,int&pastatoLygis,bool&arGalimas,bool &arTobulinti,double base)
    {
        if(pastatoLygis==0 && tobulinimoFormule(pastatoLygis,base,2.5)<=medienaRes)
        {
            arGalimas=true;
            if(arTobulinti==true)
            {
                medienaRes=medienaRes-tobulinimoFormule(pastatoLygis,base,2.5);
                pastatoLygis++;
                arTobulinti=false;
                arGalimas=false;
            }
        }
        else if(pastatoLygis==1 && tobulinimoFormule(pastatoLygis,base,2.5)<=medienaRes && tobulinimoFormule(pastatoLygis,base,2)<=akmuoRes)
        {
            arGalimas=true;
            if(arTobulinti==true)
            {
                medienaRes=medienaRes-tobulinimoFormule(pastatoLygis,base,2.5);
                akmuoRes=akmuoRes-tobulinimoFormule(pastatoLygis,base,2);
                pastatoLygis++;
                arTobulinti=false;
                arGalimas=false;
            }
        }
        else if(pastatoLygis==2 && tobulinimoFormule(pastatoLygis,base,2.5)<=medienaRes && tobulinimoFormule(pastatoLygis,base,2)<=akmuoRes && tobulinimoFormule(pastatoLygis,base,1.8)<=gelezisRes)
        {
            arGalimas=true;
            if(arTobulinti==true)
            {
                medienaRes=medienaRes-tobulinimoFormule(pastatoLygis,base,2.5);
                akmuoRes=akmuoRes-tobulinimoFormule(pastatoLygis,base,2);
                gelezisRes=gelezisRes-tobulinimoFormule(pastatoLygis,base,1.8);
                pastatoLygis++;
                arTobulinti=false;
                arGalimas=false;
            }
        }
        else if(pastatoLygis==3 && tobulinimoFormule(pastatoLygis,base,2.5)<=medienaRes && tobulinimoFormule(pastatoLygis,base,2)<=akmuoRes && tobulinimoFormule(pastatoLygis,base,1.8)<=gelezisRes && tobulinimoFormule(pastatoLygis,base,1.5)<=auksasRes)
        {
            arGalimas=true;
            if(arTobulinti==true)
            {
                medienaRes=medienaRes-tobulinimoFormule(pastatoLygis,base,2.5);
                akmuoRes=akmuoRes-tobulinimoFormule(pastatoLygis,base,2);
                gelezisRes=gelezisRes-tobulinimoFormule(pastatoLygis,base,1.8);
                auksasRes=auksasRes-tobulinimoFormule(pastatoLygis,base,1.5);
                pastatoLygis++;
                arTobulinti=false;
                arGalimas=false;
            }
        }
        else if(pastatoLygis>=4 && tobulinimoFormule(pastatoLygis,base,2.5)<=medienaRes && tobulinimoFormule(pastatoLygis,base,2+(pastatoLygis-3)/base)<=akmuoRes && tobulinimoFormule(pastatoLygis,base,1.8+(pastatoLygis-3)/base)<=gelezisRes && tobulinimoFormule(pastatoLygis,base,1.5+(pastatoLygis-3)/base)<=auksasRes)
        {
            arGalimas=true;
            if(arTobulinti==true)
            {
                medienaRes=medienaRes-tobulinimoFormule(pastatoLygis,base,2.5);
                akmuoRes=akmuoRes-tobulinimoFormule(pastatoLygis,base,2+(pastatoLygis-3)/10);
                gelezisRes=gelezisRes-tobulinimoFormule(pastatoLygis,base,1.8+(pastatoLygis-3)/10);
                auksasRes=auksasRes-tobulinimoFormule(pastatoLygis,base,1.5+(pastatoLygis-3)/10);
                pastatoLygis++;
                arTobulinti=false;
                arGalimas=false;
            }
        }
    }
    void akmensSkaldyklosTobulinimas(double&medienaRes,double&akmuoRes,double&gelezisRes,double&auksasRes,int&pastatoLygis,bool&arGalimas,bool &arTobulinti,double medienosKof,double akmensKof,double geleziesKof, double auksoKof, double base)
    {
        if(pastatoLygis==0 && tobulinimoFormule(pastatoLygis,base,medienosKof)<=medienaRes)
        {
            arGalimas=true;
            if(arTobulinti==true)
            {
                medienaRes=medienaRes-tobulinimoFormule(pastatoLygis,base,medienosKof);
                pastatoLygis++;
                arTobulinti=false;
                arGalimas=false;
            }
        }
        else if(pastatoLygis==1 && tobulinimoFormule(pastatoLygis,base,medienosKof)<=medienaRes && tobulinimoFormule(pastatoLygis,base,akmensKof)<=akmuoRes && tobulinimoFormule(pastatoLygis,base,geleziesKof)<=gelezisRes)
        {
            arGalimas=true;
            if(arTobulinti==true)
            {
                medienaRes=medienaRes-tobulinimoFormule(pastatoLygis,base,medienosKof);
                akmuoRes=akmuoRes-tobulinimoFormule(pastatoLygis,base,akmensKof);
                gelezisRes=gelezisRes-tobulinimoFormule(pastatoLygis,base,geleziesKof);
                pastatoLygis++;
                arTobulinti=false;
                arGalimas=false;
            }
        }
        else if(pastatoLygis==2 && tobulinimoFormule(pastatoLygis,base,medienosKof)<=medienaRes && tobulinimoFormule(pastatoLygis,base,akmensKof)<=akmuoRes && tobulinimoFormule(pastatoLygis,base,geleziesKof)<=gelezisRes && tobulinimoFormule(pastatoLygis,base,auksoKof)<=auksasRes)
        {
            arGalimas=true;
            if(arTobulinti==true)
            {
                medienaRes=medienaRes-tobulinimoFormule(pastatoLygis,base,medienosKof);
                akmuoRes=akmuoRes-tobulinimoFormule(pastatoLygis,base,akmensKof);
                gelezisRes=gelezisRes-tobulinimoFormule(pastatoLygis,base,geleziesKof);
                auksasRes=auksasRes-tobulinimoFormule(pastatoLygis,base,auksoKof);
                pastatoLygis++;
                arTobulinti=false;
                arGalimas=false;
            }
        }
        else if(pastatoLygis>=3 && tobulinimoFormule(pastatoLygis,base,medienosKof)<=medienaRes && tobulinimoFormule(pastatoLygis,base,akmensKof+(pastatoLygis-3)/base)<=akmuoRes && tobulinimoFormule(pastatoLygis,base,geleziesKof+(pastatoLygis-3)/base)<=gelezisRes && tobulinimoFormule(pastatoLygis,base,auksoKof+(pastatoLygis-3)/base)<=auksasRes)
        {
            arGalimas=true;
            if(arTobulinti==true)
            {
                medienaRes=medienaRes-tobulinimoFormule(pastatoLygis,base,medienosKof+(pastatoLygis-2)/10);
                akmuoRes=akmuoRes-tobulinimoFormule(pastatoLygis,base,akmensKof+(pastatoLygis-2)/10);
                gelezisRes=gelezisRes-tobulinimoFormule(pastatoLygis,base,geleziesKof+(pastatoLygis-2)/10);
                auksasRes=auksasRes-tobulinimoFormule(pastatoLygis,base,auksoKof+(pastatoLygis-2)/10);
                pastatoLygis++;
                arTobulinti=false;
                arGalimas=false;
            }
        }
    }
    void geleziesKasyklosGynybinesSienosTobulinimas(double&medienaRes,double&akmuoRes,double&gelezisRes,double&auksasRes,int&pastatoLygis,bool&arGalimas,bool &arTobulinti,double medienosKof,double akmensKof,double geleziesKof, double auksoKof, double base)
    {
        if(pastatoLygis==0 && tobulinimoFormule(pastatoLygis,base,medienosKof)<=medienaRes && tobulinimoFormule(pastatoLygis,base,akmensKof)<=akmuoRes)
        {
            arGalimas=true;
            if(arTobulinti==true)
            {
                medienaRes=medienaRes-tobulinimoFormule(pastatoLygis,base,medienosKof);
                akmuoRes=akmuoRes-tobulinimoFormule(pastatoLygis,base,akmensKof);
                pastatoLygis++;
                arTobulinti=false;
                arGalimas=false;
            }
        }
        else if(pastatoLygis==1 && tobulinimoFormule(pastatoLygis,base,medienosKof)<=medienaRes && tobulinimoFormule(pastatoLygis,base,akmensKof)<=akmuoRes && tobulinimoFormule(pastatoLygis,base,geleziesKof)<=gelezisRes)
        {
            arGalimas=true;
            if(arTobulinti==true)
            {
                medienaRes=medienaRes-tobulinimoFormule(pastatoLygis,base,medienosKof);
                akmuoRes=akmuoRes-tobulinimoFormule(pastatoLygis,base,akmensKof);
                gelezisRes=gelezisRes-tobulinimoFormule(pastatoLygis,base,geleziesKof);
                pastatoLygis++;
                arTobulinti=false;
                arGalimas=false;
            }
        }
        else if(pastatoLygis==2 && tobulinimoFormule(pastatoLygis,base,medienosKof)<=medienaRes && tobulinimoFormule(pastatoLygis,base,akmensKof)<=akmuoRes && tobulinimoFormule(pastatoLygis,base,geleziesKof)<=gelezisRes && tobulinimoFormule(pastatoLygis,base,auksoKof)<=auksasRes)
        {
            arGalimas=true;
            if(arTobulinti==true)
            {
                medienaRes=medienaRes-tobulinimoFormule(pastatoLygis,base,medienosKof);
                akmuoRes=akmuoRes-tobulinimoFormule(pastatoLygis,base,akmensKof);
                gelezisRes=gelezisRes-tobulinimoFormule(pastatoLygis,base,geleziesKof);
                auksasRes=auksasRes-tobulinimoFormule(pastatoLygis,base,auksoKof);
                pastatoLygis++;
                arTobulinti=false;
                arGalimas=false;
            }
        }
        else if(pastatoLygis>=3 && tobulinimoFormule(pastatoLygis,base,medienosKof)<=medienaRes && tobulinimoFormule(pastatoLygis,base,akmensKof+(pastatoLygis-3)/base)<=akmuoRes && tobulinimoFormule(pastatoLygis,base,geleziesKof+(pastatoLygis-3)/base)<=gelezisRes && tobulinimoFormule(pastatoLygis,base,auksoKof+(pastatoLygis-3)/base)<=auksasRes)
        {
            arGalimas=true;
            if(arTobulinti==true)
            {
                medienaRes=medienaRes-tobulinimoFormule(pastatoLygis,base,medienosKof+(pastatoLygis-2)/10);
                akmuoRes=akmuoRes-tobulinimoFormule(pastatoLygis,base,akmensKof+(pastatoLygis-2)/10);
                gelezisRes=gelezisRes-tobulinimoFormule(pastatoLygis,base,geleziesKof+(pastatoLygis-1)/10);
                auksasRes=auksasRes-tobulinimoFormule(pastatoLygis,base,auksoKof+(pastatoLygis-2)/10);
                pastatoLygis++;
                arTobulinti=false;
                arGalimas=false;
            }
        }
    }
    void auksoKasyklosTobulinimas(double&medienaRes,double&akmuoRes,double&gelezisRes,double&auksasRes,int&pastatoLygis,bool&arGalimas,bool &arTobulinti,double medienosKof,double akmensKof,double geleziesKof, double auksoKof, double base)
    {
        if(pastatoLygis==0 && tobulinimoFormule(pastatoLygis,base,medienosKof)<=medienaRes && tobulinimoFormule(pastatoLygis,base,akmensKof)<=akmuoRes && tobulinimoFormule(pastatoLygis,base,geleziesKof)<=gelezisRes)
        {
            arGalimas=true;
            if(arTobulinti==true)
            {
                medienaRes=medienaRes-tobulinimoFormule(pastatoLygis,base,medienosKof);
                akmuoRes=akmuoRes-tobulinimoFormule(pastatoLygis,base,akmensKof);
                gelezisRes=gelezisRes-tobulinimoFormule(pastatoLygis,base,geleziesKof);
                pastatoLygis++;
                arTobulinti=false;
                arGalimas=false;
            }
        }
        else if(pastatoLygis==1 && tobulinimoFormule(pastatoLygis,base,medienosKof)<=medienaRes && tobulinimoFormule(pastatoLygis,base,akmensKof)<=akmuoRes && tobulinimoFormule(pastatoLygis,base,geleziesKof)<=gelezisRes && tobulinimoFormule(pastatoLygis,base,auksoKof)<=auksasRes)
        {
            arGalimas=true;
            if(arTobulinti==true)
            {
                medienaRes=medienaRes-tobulinimoFormule(pastatoLygis,base,medienosKof);
                akmuoRes=akmuoRes-tobulinimoFormule(pastatoLygis,base,akmensKof);
                gelezisRes=gelezisRes-tobulinimoFormule(pastatoLygis,base,geleziesKof);
                auksasRes=auksasRes-tobulinimoFormule(pastatoLygis,base,auksoKof);
                pastatoLygis++;
                arTobulinti=false;
                arGalimas=false;
            }
        }
        else if(pastatoLygis>=2 && tobulinimoFormule(pastatoLygis,base,medienosKof)<=medienaRes && tobulinimoFormule(pastatoLygis,base,akmensKof+(pastatoLygis-3)/base)<=akmuoRes && tobulinimoFormule(pastatoLygis,base,geleziesKof+(pastatoLygis-3)/base)<=gelezisRes && tobulinimoFormule(pastatoLygis,base,auksoKof+(pastatoLygis-3)/base)<=auksasRes)
        {
            arGalimas=true;
            if(arTobulinti==true)
            {
                medienaRes=medienaRes-tobulinimoFormule(pastatoLygis,base,medienosKof+(pastatoLygis-1)/10);
                akmuoRes=akmuoRes-tobulinimoFormule(pastatoLygis,base,akmensKof+(pastatoLygis-1)/10);
                gelezisRes=gelezisRes-tobulinimoFormule(pastatoLygis,base,geleziesKof+(pastatoLygis-1)/10);
                auksasRes=auksasRes-tobulinimoFormule(pastatoLygis,base,auksoKof+(pastatoLygis-1)/10);
                pastatoLygis++;
                arTobulinti=false;
                arGalimas=false;
            }
        }
    }
    void kituPastatuTobulinimas(double&medienaRes,double&akmuoRes,double&gelezisRes,double&auksasRes,int&pastatoLygis,bool&arGalimas,bool &arTobulinti,double medienosKof,double akmensKof,double geleziesKof, double auksoKof, double base)
    {
        if(pastatoLygis==0 && tobulinimoFormule(pastatoLygis,base,medienosKof)<=medienaRes && tobulinimoFormule(pastatoLygis,base,akmensKof)<=akmuoRes && tobulinimoFormule(pastatoLygis,base,geleziesKof)<=gelezisRes && tobulinimoFormule(pastatoLygis,base,auksoKof)<=auksasRes)
        {
            arGalimas=true;
            if(arTobulinti==true)
            {
                medienaRes=medienaRes-tobulinimoFormule(pastatoLygis,base,medienosKof);
                akmuoRes=akmuoRes-tobulinimoFormule(pastatoLygis,base,akmensKof);
                gelezisRes=gelezisRes-tobulinimoFormule(pastatoLygis,base,geleziesKof);
                auksasRes=auksasRes-tobulinimoFormule(pastatoLygis,base,auksoKof);
                pastatoLygis++;
                arTobulinti=false;
                arGalimas=false;
            }
        }
        else if(pastatoLygis>=1 && tobulinimoFormule(pastatoLygis,base,medienosKof)<=medienaRes && tobulinimoFormule(pastatoLygis,base,akmensKof+(pastatoLygis-3)/base)<=akmuoRes && tobulinimoFormule(pastatoLygis,base,geleziesKof+(pastatoLygis-3)/base)<=gelezisRes && tobulinimoFormule(pastatoLygis,base,auksoKof+(pastatoLygis-3)/base)<=auksasRes)
        {
            arGalimas=true;
            if(arTobulinti==true)
            {
                medienaRes=medienaRes-tobulinimoFormule(pastatoLygis,base,medienosKof+(pastatoLygis)/10);
                akmuoRes=akmuoRes-tobulinimoFormule(pastatoLygis,base,akmensKof+(pastatoLygis)/10);
                gelezisRes=gelezisRes-tobulinimoFormule(pastatoLygis,base,geleziesKof+(pastatoLygis)/10);
                auksasRes=auksasRes-tobulinimoFormule(pastatoLygis,base,auksoKof+(pastatoLygis)/10);
                pastatoLygis++;
                arTobulinti=false;
                arGalimas=false;
            }
        }
    }
    //----------------------------------------------------------------------------------
    // sios funkcijos atsakingos uz pastatu tobulinimo kainos parodyma
    void gautiLentpjuvesFermosKaina(int pastatoLygis, double medienosKof, double akmensKof, double geleziesKof, double auksoKof, double base, double&medienosKaina, double&akmensKaina, double&geleziesKaina, double&auksoKaina)
    {
        if(pastatoLygis==0)
        {
            medienosKaina=tobulinimoFormule(pastatoLygis,base,medienosKof);
            akmensKaina=0;
            geleziesKaina=0;
            auksoKaina=0;
        }
        else if(pastatoLygis==1)
        {
            medienosKaina=tobulinimoFormule(pastatoLygis,base,medienosKof);
            akmensKaina=tobulinimoFormule(pastatoLygis,base,akmensKof);
            geleziesKaina=0;
            auksoKaina=0;
        }
        else if(pastatoLygis==2)
        {
            medienosKaina=tobulinimoFormule(pastatoLygis,base,medienosKof);
            akmensKaina=tobulinimoFormule(pastatoLygis,base,akmensKof);
            geleziesKaina=tobulinimoFormule(pastatoLygis,base,geleziesKof);
            auksoKaina=0;
        }
        else if(pastatoLygis==3)
        {
            medienosKaina=tobulinimoFormule(pastatoLygis,base,medienosKof);
            akmensKaina=tobulinimoFormule(pastatoLygis,base,akmensKof);
            geleziesKaina=tobulinimoFormule(pastatoLygis,base,geleziesKof);
            auksoKaina=tobulinimoFormule(pastatoLygis,base,auksoKof);
        }
        else if(pastatoLygis>=4)
        {
            medienosKaina=tobulinimoFormule(pastatoLygis,base,medienosKof+(pastatoLygis-3)/base);
            akmensKaina=tobulinimoFormule(pastatoLygis,base,akmensKof+(pastatoLygis-3)/base);
            geleziesKaina=tobulinimoFormule(pastatoLygis,base,geleziesKof+(pastatoLygis-3)/base);
            auksoKaina=tobulinimoFormule(pastatoLygis,base,auksoKof+(pastatoLygis-3)/base);
        }
    }
    void gautiAkmensSkaldyklosKaina(int pastatoLygis, double medienosKof, double akmensKof, double geleziesKof, double auksoKof, double base, double&medienosKaina, double&akmensKaina, double&geleziesKaina, double&auksoKaina)
    {
        if(pastatoLygis==0)
        {
            medienosKaina=tobulinimoFormule(pastatoLygis,base,medienosKof);
            akmensKaina=0;
            geleziesKaina=0;
            auksoKaina=0;
        }
        else if(pastatoLygis==1)
        {
            medienosKaina=tobulinimoFormule(pastatoLygis,base,medienosKof);
            akmensKaina=tobulinimoFormule(pastatoLygis,base,akmensKof);
            geleziesKaina=tobulinimoFormule(pastatoLygis,base,geleziesKof);
            auksoKaina=0;
        }
        else if(pastatoLygis==2)
        {
            medienosKaina=tobulinimoFormule(pastatoLygis,base,medienosKof);
            akmensKaina=tobulinimoFormule(pastatoLygis,base,akmensKof);
            geleziesKaina=tobulinimoFormule(pastatoLygis,base,geleziesKof);
            auksoKaina=tobulinimoFormule(pastatoLygis,base,auksoKof);
        }
        else if(pastatoLygis>=3)
        {
            medienosKaina=tobulinimoFormule(pastatoLygis,base,medienosKof+(pastatoLygis-3)/base);
            akmensKaina=tobulinimoFormule(pastatoLygis,base,akmensKof+(pastatoLygis-3)/base);
            geleziesKaina=tobulinimoFormule(pastatoLygis,base,geleziesKof+(pastatoLygis-3)/base);
            auksoKaina=tobulinimoFormule(pastatoLygis,base,auksoKof+(pastatoLygis-3)/base);
        }
    }
    void gautiGeleziesKasyklosGynybinesSienosKaina(int pastatoLygis, double medienosKof, double akmensKof, double geleziesKof, double auksoKof, double base, double&medienosKaina, double&akmensKaina, double&geleziesKaina, double&auksoKaina)
    {
        if(pastatoLygis==0)
        {
            medienosKaina=tobulinimoFormule(pastatoLygis,base,medienosKof);
            akmensKaina=tobulinimoFormule(pastatoLygis,base,akmensKof);
            geleziesKaina=0;
            auksoKaina=0;
        }
        else if(pastatoLygis==1)
        {
            medienosKaina=tobulinimoFormule(pastatoLygis,base,medienosKof);
            akmensKaina=tobulinimoFormule(pastatoLygis,base,akmensKof);
            geleziesKaina=tobulinimoFormule(pastatoLygis,base,geleziesKof);
            auksoKaina=0;
        }
        else if(pastatoLygis==2)
        {
            medienosKaina=tobulinimoFormule(pastatoLygis,base,medienosKof);
            akmensKaina=tobulinimoFormule(pastatoLygis,base,akmensKof);
            geleziesKaina=tobulinimoFormule(pastatoLygis,base,geleziesKof);
            auksoKaina=tobulinimoFormule(pastatoLygis,base,auksoKof);
        }
        else if(pastatoLygis>=3)
        {
            medienosKaina=tobulinimoFormule(pastatoLygis,base,medienosKof+(pastatoLygis-3)/base);
            akmensKaina=tobulinimoFormule(pastatoLygis,base,akmensKof+(pastatoLygis-3)/base);
            geleziesKaina=tobulinimoFormule(pastatoLygis,base,geleziesKof+(pastatoLygis-3)/base);
            auksoKaina=tobulinimoFormule(pastatoLygis,base,auksoKof+(pastatoLygis-3)/base);
        }
    }
    void gautiAuksoKasyklosKaina(int pastatoLygis, double medienosKof, double akmensKof, double geleziesKof, double auksoKof, double base, double&medienosKaina, double&akmensKaina, double&geleziesKaina, double&auksoKaina)
    {
        if(pastatoLygis==0)
        {
            medienosKaina=tobulinimoFormule(pastatoLygis,base,medienosKof);
            akmensKaina=tobulinimoFormule(pastatoLygis,base,akmensKof);
            geleziesKaina=tobulinimoFormule(pastatoLygis,base,geleziesKof);
            auksoKaina=0;
        }
        else if(pastatoLygis==1)
        {
            medienosKaina=tobulinimoFormule(pastatoLygis,base,medienosKof);
            akmensKaina=tobulinimoFormule(pastatoLygis,base,akmensKof);
            geleziesKaina=tobulinimoFormule(pastatoLygis,base,geleziesKof);
            auksoKaina=tobulinimoFormule(pastatoLygis,base,auksoKof);
        }
        else if(pastatoLygis>=2)
        {
            medienosKaina=tobulinimoFormule(pastatoLygis,base,medienosKof+(pastatoLygis-3)/base);
            akmensKaina=tobulinimoFormule(pastatoLygis,base,akmensKof+(pastatoLygis-3)/base);
            geleziesKaina=tobulinimoFormule(pastatoLygis,base,geleziesKof+(pastatoLygis-3)/base);
            auksoKaina=tobulinimoFormule(pastatoLygis,base,auksoKof+(pastatoLygis-3)/base);
        }
    }
    void gautiKituPastatuKaina(int pastatoLygis, double medienosKof, double akmensKof, double geleziesKof, double auksoKof, double base, double&medienosKaina, double&akmensKaina, double&geleziesKaina, double&auksoKaina)
    {
        if(pastatoLygis==0)
        {
            medienosKaina=tobulinimoFormule(pastatoLygis,base,medienosKof);
            akmensKaina=tobulinimoFormule(pastatoLygis,base,akmensKof);
            geleziesKaina=tobulinimoFormule(pastatoLygis,base,geleziesKof);
            auksoKaina=tobulinimoFormule(pastatoLygis,base,auksoKof);
        }
        else if(pastatoLygis>=1)
        {
            medienosKaina=tobulinimoFormule(pastatoLygis,base,medienosKof+(pastatoLygis-3)/base);
            akmensKaina=tobulinimoFormule(pastatoLygis,base,akmensKof+(pastatoLygis-3)/base);
            geleziesKaina=tobulinimoFormule(pastatoLygis,base,geleziesKof+(pastatoLygis-3)/base);
            auksoKaina=tobulinimoFormule(pastatoLygis,base,auksoKof+(pastatoLygis-3)/base);
        }
    }
    //----------------------------------------------------------------------------------
};

class pastataiIrPagrindinis:public tobulinimai,public kareiviai,public priesai{ // si klase atsakinga uz visu zaidimu obijektu saveikavima tarpusavyje.
private:
    int lentpjuvesLygis=0, akmensSakldyklosLygis=0, geleziesKasyklosLygis=0, fermosLygis=0, auksoKasyklosLygis=0;//rusrsu pastatu lygiai
    int kareiviniuLygis=0, gynybinesSienosLygis=0; // karo pastatai
    int apginkluotiBedarbiai=0, lengviejiPestininkai=0, sunkiejiPestininkai=0, lankininkai=0, lengvojikavalerija=0, sunkiojiKavalerija=0;//kariu tipai
    int apginkluotiBedarbiaiPaskirti=0,lengviejiPestininkaiPaskirti=0, sunkiejiPestininkaiPaskirti=0, lankininkaiPaskirti=0, lengvojikavalerijaPaskirti=0, sunkiojiKavalerijaPaskirti=0;
    double apginkluotiBedarbiaiPaskirtiLaikas=0, lengviejiPestininkaiPaskirtiLaikas=0, sunkiejiPestininkaiPaskirtiLaikas=0, lankininkaiPaskirtiLaikas=0, lengvojikavalerijaPaskirtiLaikas=0, sunkiojiKavalerijaPaskirtiLaikas=0; //likes treniravimo laikas
    double medienaRes=40, akmuoRes=0, gelezisRes=0, auksasRes=0, maistasRes=250;// resursai
    int laisvigyventojaiSk=7;
    int lentpjuvesDarbuotojai=0, akmensSkaldyklosDarbuotojai=0, geleziesKasyklosDarbuotojai=0, auksoKasyklosDarbuotojai=0, fermosDarbuotojai=0;
    double medienosKaina, akmensKaina, geleziesKaina, auksoKaina;//kainos tikrinant pastatu tobulinimo kainas
    int likesLaikasIkiIvikio=200, ivikioNr=0, puolimoNr=0;
public:
    ekr::infoClass info, kaina, ivestis;
    //----------------------------------------------------------------------------------
    //sios funkcijos atsakingos uz pastatu tobulinima
    void lentpjuve(bool tobulinam){
        bool arGalimas=false, arTobulinti=false;
        lentpjuvesFermosTobulinimas(medienaRes,akmuoRes,gelezisRes,auksasRes,lentpjuvesLygis,arGalimas,arTobulinti,10);
        if(arGalimas==true)arTobulinti=tobulinam;
        else nepakankamuResursuMsgBox();
        lentpjuvesFermosTobulinimas(medienaRes,akmuoRes,gelezisRes,auksasRes,lentpjuvesLygis,arGalimas,arTobulinti,10);
    }
    void akmensSakldykla(bool tobulinam){
        bool arGalimas=false, arTobulinti=false;
        akmensSkaldyklosTobulinimas(medienaRes,akmuoRes,gelezisRes,auksasRes,akmensSakldyklosLygis,arGalimas,arTobulinti,2.7,2.3,2,1.6,20);
        if(arGalimas==true)arTobulinti=tobulinam;
        else nepakankamuResursuMsgBox();
        akmensSkaldyklosTobulinimas(medienaRes,akmuoRes,gelezisRes,auksasRes,akmensSakldyklosLygis,arGalimas,arTobulinti,2.7,2.3,2,1.6,20);
    }
    void geleziesKasykla(bool tobulinam){
        bool arGalimas=false, arTobulinti=false;
        geleziesKasyklosGynybinesSienosTobulinimas(medienaRes,akmuoRes,gelezisRes,auksasRes,geleziesKasyklosLygis,arGalimas,arTobulinti,2.8,2.4,2.2,1.7,40);
        if(arGalimas==true)arTobulinti=tobulinam;
        else nepakankamuResursuMsgBox();
        geleziesKasyklosGynybinesSienosTobulinimas(medienaRes,akmuoRes,gelezisRes,auksasRes,geleziesKasyklosLygis,arGalimas,arTobulinti,2.8,2.4,2.2,1.7,40);
    }
    void ferma(bool tobulinam){
        bool arGalimas=false, arTobulinti=false;
        lentpjuvesFermosTobulinimas(medienaRes,akmuoRes,gelezisRes,auksasRes,fermosLygis,arGalimas,arTobulinti,10);
        if(arGalimas==true)arTobulinti=tobulinam;
        else nepakankamuResursuMsgBox();
        lentpjuvesFermosTobulinimas(medienaRes,akmuoRes,gelezisRes,auksasRes,fermosLygis,arGalimas,arTobulinti,10);
    }
    void auksoKasykla(bool tobulinam){
        bool arGalimas=false, arTobulinti=false;
        auksoKasyklosTobulinimas(medienaRes,akmuoRes,gelezisRes,auksasRes,auksoKasyklosLygis,arGalimas,arTobulinti,3,2.6,2.4,2,60);
        if(arGalimas==true)arTobulinti=tobulinam;
        else nepakankamuResursuMsgBox();
        auksoKasyklosTobulinimas(medienaRes,akmuoRes,gelezisRes,auksasRes,auksoKasyklosLygis,arGalimas,arTobulinti,3,2.6,2.4,2,60);

    }
    void kareivines(bool tobulinam){
        bool arGalimas=false, arTobulinti=false;
        kituPastatuTobulinimas(medienaRes,akmuoRes,gelezisRes,auksasRes,kareiviniuLygis,arGalimas,arTobulinti,3,2.6,2.4,2,60);
        if(arGalimas==true)arTobulinti=tobulinam;
        else nepakankamuResursuMsgBox();
        kituPastatuTobulinimas(medienaRes,akmuoRes,gelezisRes,auksasRes,kareiviniuLygis,arGalimas,arTobulinti,3,2.6,2.4,2,60);
    }
    void gynybineSiena(bool tobulinam){
        bool arGalimas=false, arTobulinti=false;
        geleziesKasyklosGynybinesSienosTobulinimas(medienaRes,akmuoRes,gelezisRes,auksasRes,gynybinesSienosLygis,arGalimas,arTobulinti,2.8,2.4,2.2,1.7,80);
        if(arGalimas==true)arTobulinti=tobulinam;
        else nepakankamuResursuMsgBox();
        geleziesKasyklosGynybinesSienosTobulinimas(medienaRes,akmuoRes,gelezisRes,auksasRes,gynybinesSienosLygis,arGalimas,arTobulinti,2.8,2.4,2.2,1.7,80);
    }
    //----------------------------------------------------------------------------------
    //sios funkcijos atsakingos uz resursu gavyba
    double gautiMedienos(int darbuotojuSk){
        return medienaRes=medienaRes+(darbuotojuSk*resursuFormule(lentpjuvesLygis,1,1.5));
    }
    double gautiAkmens(int darbuotojuSk){
        return akmuoRes=akmuoRes+(darbuotojuSk*resursuFormule(akmensSakldyklosLygis,1,1.4));
    }
    double gautiGelezies(int darbuotojuSk){
        return gelezisRes=gelezisRes+(darbuotojuSk*resursuFormule(geleziesKasyklosLygis,1,1.3));
    }
    double gautiAukso(int darbuotojuSk){
        return auksasRes=auksasRes+(darbuotojuSk*resursuFormule(auksoKasyklosLygis,1,1.2));
    }
    double gautiMaisto(int darbuotojuSk){
        return maistasRes=maistasRes+(darbuotojuSk*resursuFormule(fermosLygis,1,1.7));
    }
    //----------------------------------------------------------------------------------
    // si funkcija atsakinga uz bedarbiu pirkima
    void bedarbiuPirkimas(){
        int sk;

        bedarbioKainaMsgBox();
        ivedimoLaukas(sk);
        if(maistasRes<100)nepakankamuResursuMsgBox();
        else if(100*sk<=maistasRes && sk>=0)
        {
            laisvigyventojaiSk=laisvigyventojaiSk+sk;
            maistasRes=maistasRes-100*sk;
        }
        else if(100*sk>maistasRes)
        {
            laisvigyventojaiSk=(int)laisvigyventojaiSk+maistasRes/100;
            maistasRes=maistasRes-100*(int)(maistasRes/100);
        }
        else if(sk<0)blogoKiekoMsgBox();

        //prideti msgBox
        //kainos rodyma
    }
    //----------------------------------------------------------------------------------
    // sios funkcijos paskiria darbuotojus resursu pastatams
    void lentpjuvesDarbuotojuPaskyrimas(){
        int sk;
        ivedimoLaukas(sk);
        if(sk<=laisvigyventojaiSk && sk>=0)
        {
            laisvigyventojaiSk=laisvigyventojaiSk-sk;
            lentpjuvesDarbuotojai=lentpjuvesDarbuotojai+sk;
        }
        else if(sk>laisvigyventojaiSk)
        {
            lentpjuvesDarbuotojai=lentpjuvesDarbuotojai+laisvigyventojaiSk;
            laisvigyventojaiSk=laisvigyventojaiSk-laisvigyventojaiSk;
        }
        else if(sk>=-lentpjuvesDarbuotojai && sk<0)
        {
            laisvigyventojaiSk=laisvigyventojaiSk-sk;
            lentpjuvesDarbuotojai=lentpjuvesDarbuotojai+sk;
        }
        else if(sk<-lentpjuvesDarbuotojai)
        {
            laisvigyventojaiSk=laisvigyventojaiSk+lentpjuvesDarbuotojai;
            lentpjuvesDarbuotojai=lentpjuvesDarbuotojai-lentpjuvesDarbuotojai;
        }
        if(laisvigyventojaiSk==0 && sk>0)neraBedarbiuMsgBox();
        gotoxy(75,6);
        cout<<"    ";
            gotoxy(75,6);
        if(lentpjuvesDarbuotojai!=0){

            cout<<lentpjuvesDarbuotojai;
        }
        else cout<<'-';
    }
    void akmensSkaldyklosDarbuotojuPaskyrimas(){
        int sk;
        ivedimoLaukas(sk);
        if(sk<=laisvigyventojaiSk && sk>=0)
        {
            laisvigyventojaiSk=laisvigyventojaiSk-sk;
            akmensSkaldyklosDarbuotojai=akmensSkaldyklosDarbuotojai+sk;

        }
        else if(sk>laisvigyventojaiSk)
        {
            akmensSkaldyklosDarbuotojai=akmensSkaldyklosDarbuotojai+laisvigyventojaiSk;
            laisvigyventojaiSk=laisvigyventojaiSk-laisvigyventojaiSk;
        }
        else if(sk>=-akmensSkaldyklosDarbuotojai && sk<0)
        {
            laisvigyventojaiSk=laisvigyventojaiSk-sk;
            akmensSkaldyklosDarbuotojai=akmensSkaldyklosDarbuotojai+sk;
        }
        else if(sk<-akmensSkaldyklosDarbuotojai)
        {
            laisvigyventojaiSk=laisvigyventojaiSk+akmensSkaldyklosDarbuotojai;
            akmensSkaldyklosDarbuotojai=akmensSkaldyklosDarbuotojai-akmensSkaldyklosDarbuotojai;
        }
        if(laisvigyventojaiSk==0 && sk>0)neraBedarbiuMsgBox();
        gotoxy(75,7);
        cout<<"    ";
        gotoxy(75,7);
        if(akmensSkaldyklosDarbuotojai!=0){

            cout<<akmensSkaldyklosDarbuotojai;
        }
        else cout<<'-';
    }
    void geleziesKasyklosDarbuotojuPaskyrimas(){
        int sk;
        ivedimoLaukas(sk);
        if(sk<=laisvigyventojaiSk && sk>=0)
        {
            laisvigyventojaiSk=laisvigyventojaiSk-sk;
            geleziesKasyklosDarbuotojai=geleziesKasyklosDarbuotojai+sk;

        }
        else if(sk>laisvigyventojaiSk)
        {
            geleziesKasyklosDarbuotojai=geleziesKasyklosDarbuotojai+laisvigyventojaiSk;
            laisvigyventojaiSk=laisvigyventojaiSk-laisvigyventojaiSk;
        }
        else if(sk>=-geleziesKasyklosDarbuotojai && sk<0)
        {
            laisvigyventojaiSk=laisvigyventojaiSk-sk;
            geleziesKasyklosDarbuotojai=geleziesKasyklosDarbuotojai+sk;
        }
        else if(sk<-geleziesKasyklosDarbuotojai)
        {
            laisvigyventojaiSk=laisvigyventojaiSk+geleziesKasyklosDarbuotojai;
            geleziesKasyklosDarbuotojai=geleziesKasyklosDarbuotojai-geleziesKasyklosDarbuotojai;
        }
        if(laisvigyventojaiSk==0 && sk>0)neraBedarbiuMsgBox();
        gotoxy(75,8);
        cout<<"    ";
        gotoxy(75,8);
        if(geleziesKasyklosDarbuotojai!=0)
        {

            cout<<geleziesKasyklosDarbuotojai;
        }
        else cout<<'-';
    }
    void auksoKasyklosDarbuotojuPaskyrimas(){
        int sk;
        ivedimoLaukas(sk);
        if(sk<=laisvigyventojaiSk && sk>=0)
        {
            laisvigyventojaiSk=laisvigyventojaiSk-sk;
            auksoKasyklosDarbuotojai=auksoKasyklosDarbuotojai+sk;

        }
        else if(sk>laisvigyventojaiSk)
        {
            auksoKasyklosDarbuotojai=auksoKasyklosDarbuotojai+laisvigyventojaiSk;
            laisvigyventojaiSk=laisvigyventojaiSk-laisvigyventojaiSk;
        }
        else if(sk>=-auksoKasyklosDarbuotojai && sk<0)
        {
            laisvigyventojaiSk=laisvigyventojaiSk-sk;
            auksoKasyklosDarbuotojai=auksoKasyklosDarbuotojai+sk;
        }
        else if(sk<-auksoKasyklosDarbuotojai)
        {
            laisvigyventojaiSk=laisvigyventojaiSk+auksoKasyklosDarbuotojai;
            auksoKasyklosDarbuotojai=auksoKasyklosDarbuotojai-auksoKasyklosDarbuotojai;
        }
        if(laisvigyventojaiSk==0 && sk>0)neraBedarbiuMsgBox();
        gotoxy(75,9);
        cout<<"    ";
        gotoxy(75,9);
        if(auksoKasyklosDarbuotojai!=0){

            cout<<auksoKasyklosDarbuotojai;
        }
        else cout<<'-';
    }
    void fermosDarbuotojuPaskyrimas(){
        int sk;
        ivedimoLaukas(sk);
        if(sk<=laisvigyventojaiSk && sk>=0)
        {
            laisvigyventojaiSk=laisvigyventojaiSk-sk;
            fermosDarbuotojai=fermosDarbuotojai+sk;

        }
        else if(sk>laisvigyventojaiSk)
        {
            fermosDarbuotojai=fermosDarbuotojai+laisvigyventojaiSk;
            laisvigyventojaiSk=laisvigyventojaiSk-laisvigyventojaiSk;
        }
        else if(sk>=-fermosDarbuotojai && sk<0)
        {
            laisvigyventojaiSk=laisvigyventojaiSk-sk;
            fermosDarbuotojai=fermosDarbuotojai+sk;
        }
        else if(sk<-fermosDarbuotojai)
        {
            laisvigyventojaiSk=laisvigyventojaiSk+fermosDarbuotojai;
            fermosDarbuotojai=fermosDarbuotojai-fermosDarbuotojai;
        }
        if(laisvigyventojaiSk==0 && sk>0)neraBedarbiuMsgBox();
        gotoxy(75,10);
        cout<<"    ";
        gotoxy(75,10);
        if(fermosDarbuotojai!=0){

            cout<<fermosDarbuotojai;
        }
        else cout<<'-';
    }
//----------------------------------------------------------------------------------
// Sios funkcijos paruosia karius treniravimui
    void apginkluotuBedarbiuPaskyrimas(){
        int sk;
        kariuKainosMsgBox(30,0,0,0,0.5);
        if(laisvigyventojaiSk>0)
        {
            ivedimoLaukas(sk);
            kariuTreniravimas(sk,laisvigyventojaiSk,apginkluotiBedarbiaiPaskirti,apginkluotiBedarbiaiPaskirtiLaikas,0.5,30,0,0,0,medienaRes,akmuoRes,gelezisRes,auksasRes);
        }
        else neraBedarbiuMsgBox();
        gotoxy(75,22);
        cout<<"   ";
        gotoxy(75,22);
        if(apginkluotiBedarbiaiPaskirti>0)
            cout<<apginkluotiBedarbiaiPaskirti;
        else cout<<'-';
        gotoxy(75,11);
        cout<<"   ";
        gotoxy(75,11);
        if(apginkluotiBedarbiai!=0)
            cout<<apginkluotiBedarbiai;
        else cout<<'-';
    }
    void lengvujuPestininkuPaskyrimas(){
        int sk;
        kariuKainosMsgBox(25,0,30,15,1);
        if(laisvigyventojaiSk>0)
        {
            ivedimoLaukas(sk);
            kariuTreniravimas(sk,laisvigyventojaiSk,lengviejiPestininkaiPaskirti,lengviejiPestininkaiPaskirtiLaikas,1,25,0,30,15,medienaRes,akmuoRes,gelezisRes,auksasRes);
        }
        else neraBedarbiuMsgBox();
        gotoxy(75,23);
        cout<<"   ";
        gotoxy(75,23);
        if(lengviejiPestininkaiPaskirti>0)
            cout<<lengviejiPestininkaiPaskirti;
        else cout<<'-';
        gotoxy(75,12);
        cout<<"   ";
        gotoxy(75,12);
        if(lengviejiPestininkai!=0)
            cout<<lengviejiPestininkai;
        else cout<<'-';
    }
    void sunkiujuPestininkuPaskyrimas(){
        int sk;
        kariuKainosMsgBox(25,0,60,30,2.5);
        if(laisvigyventojaiSk>0)
        {
            ivedimoLaukas(sk);
            kariuTreniravimas(sk,laisvigyventojaiSk,sunkiejiPestininkaiPaskirti,sunkiejiPestininkaiPaskirtiLaikas,2.5,25,0,60,30,medienaRes,akmuoRes,gelezisRes,auksasRes);
        }
        else neraBedarbiuMsgBox();
        gotoxy(75,24);
        cout<<"   ";
        gotoxy(75,24);
        if(sunkiejiPestininkaiPaskirti!=0)
            cout<<sunkiejiPestininkaiPaskirti;
        else cout<<'-';
        gotoxy(75,13);
        cout<<"   ";
        gotoxy(75,13);
        if(sunkiejiPestininkai!=0)
            cout<<sunkiejiPestininkai;
        else cout<<'-';
    }
    void lankininkuPaskyrimas(){
        int sk;
        kariuKainosMsgBox(50,0,15,30,2);
        if(laisvigyventojaiSk>0)
        {
            ivedimoLaukas(sk);
            kariuTreniravimas(sk,laisvigyventojaiSk,lankininkaiPaskirti,lankininkaiPaskirtiLaikas,2,50,0,15,30,medienaRes,akmuoRes,gelezisRes,auksasRes);
        }
        else neraBedarbiuMsgBox();
        gotoxy(75,25);
        cout<<"   ";
        gotoxy(75,25);
        if(lankininkaiPaskirti!=0)
            cout<<lankininkaiPaskirti;
        else cout<<'-';
        gotoxy(75,14);
        cout<<"   ";
        gotoxy(75,14);
        if(lankininkai!=0)
            cout<<lankininkai;
        else cout<<'-';
    }
    void lengvosiosKavalerijosPaskyrimas(){
        int sk;
        kariuKainosMsgBox(25,0,40,50,3);
        if(laisvigyventojaiSk>0)
        {
            ivedimoLaukas(sk);
            kariuTreniravimas(sk,laisvigyventojaiSk,lengvojikavalerijaPaskirti,lengvojikavalerijaPaskirtiLaikas,3,25,0,40,50,medienaRes,akmuoRes,gelezisRes,auksasRes);
        }
        else neraBedarbiuMsgBox();
        gotoxy(75,26);
        cout<<"   ";
        gotoxy(75,26);
        if(lengvojikavalerijaPaskirti!=0)
            cout<<lengvojikavalerijaPaskirti;
        else cout<<'-';
        gotoxy(75,15);
        cout<<"   ";
        gotoxy(75,15);
        if(lengvojikavalerija!=0)
            cout<<lengvojikavalerija;
        else cout<<'-';
    }
    void sunkiosiosKavalerijosPaskyrimas(){
        int sk;
        kariuKainosMsgBox(25,0,60,70,4.5);
        if(laisvigyventojaiSk>0)
        {
            ivedimoLaukas(sk);
            kariuTreniravimas(sk,laisvigyventojaiSk,sunkiojiKavalerijaPaskirti,sunkiojiKavalerijaPaskirtiLaikas,4.5,25,0,60,70,medienaRes,akmuoRes,gelezisRes,auksasRes);
        }
        else neraBedarbiuMsgBox();
        gotoxy(75,27);
        cout<<"   ";
        gotoxy(75,27);
        if(sunkiojiKavalerijaPaskirti>0)
            cout<<sunkiojiKavalerijaPaskirti;
        else cout<<'-';
        gotoxy(75,16);
        cout<<"   ";
        gotoxy(75,16);
        if(sunkiojiKavalerija!=0)
            cout<<sunkiojiKavalerija;
        else cout<<'-';
    }
//----------------------------------------------------------------------------------
// si funkcija vykdo resursu gamvyba, kariu treniravima ir ivykiu eiga
    void vykstaDarbas(int laikas){
        bool arLaimeta;
        int visiKariai=apginkluotiBedarbiai+2*lengviejiPestininkai+3*sunkiejiPestininkai+2*lankininkai+3*lengvojikavalerija+4*sunkiojiKavalerija;
        for(int i=laikas; i>0; i--)
        {
            gotoxy(51,22);
            cout<<"   ";
            gotoxy(51,22);
            cout<<i-1;
            gotoxy(51,30);
            cout<<"   ";
            gotoxy(51,30);
            cout<<likesLaikasIkiIvikio;
            gautiMedienos(lentpjuvesDarbuotojai);
            gautiAkmens(akmensSkaldyklosDarbuotojai);
            gautiGelezies(geleziesKasyklosDarbuotojai);
            gautiAukso(auksoKasyklosDarbuotojai);
            gautiMaisto(fermosDarbuotojai);

            kariuTreniravimas2(apginkluotiBedarbiai,apginkluotiBedarbiaiPaskirti,apginkluotiBedarbiaiPaskirtiLaikas,51,23,75,22);
            kariuTreniravimas2(lengviejiPestininkai,lengviejiPestininkaiPaskirti,lengviejiPestininkaiPaskirtiLaikas,51,24,75,23);
            kariuTreniravimas2(sunkiejiPestininkai,sunkiejiPestininkaiPaskirti,sunkiejiPestininkaiPaskirtiLaikas,51,25,75,24);
            kariuTreniravimas2(lankininkai,lankininkaiPaskirti,lankininkaiPaskirtiLaikas,51,26,75,25);
            kariuTreniravimas2(lengvojikavalerija,lengvojikavalerijaPaskirti,lengvojikavalerijaPaskirtiLaikas,51,27,75,26);
            kariuTreniravimas2(sunkiojiKavalerija,sunkiojiKavalerijaPaskirti,sunkiojiKavalerijaPaskirtiLaikas,51,28,75,27);
            if(likesLaikasIkiIvikio<=0)
            {
                if(ivikioNr==0)
                {
                    goblinuAtaka(true,gynybinesSienosLygis,arLaimeta,apginkluotiBedarbiai,lengviejiPestininkai,sunkiejiPestininkai,lankininkai,lengvojikavalerija,sunkiojiKavalerija,25,medienaRes,akmuoRes,gelezisRes,auksasRes,maistasRes);
                    if(arLaimeta==true)
                    {
                        ivikioNr++;
                        likesLaikasIkiIvikio=likesLaikasIkiIvikio+150;
                    }
                    else likesLaikasIkiIvikio=likesLaikasIkiIvikio+200;
                }
                else if(ivikioNr==1)
                {
                    goblinuAtaka(true,gynybinesSienosLygis,arLaimeta,apginkluotiBedarbiai,lengviejiPestininkai,sunkiejiPestininkai,lankininkai,lengvojikavalerija,sunkiojiKavalerija,115,medienaRes,akmuoRes,gelezisRes,auksasRes,maistasRes);
                    if(arLaimeta==true)
                    {
                        ivikioNr++;
                        likesLaikasIkiIvikio=likesLaikasIkiIvikio+150;
                    }
                    else likesLaikasIkiIvikio=likesLaikasIkiIvikio+200;
                }
                else if(ivikioNr==2)
                {
                    orkuAtaka(true,gynybinesSienosLygis,arLaimeta,apginkluotiBedarbiai,lengviejiPestininkai,sunkiejiPestininkai,lankininkai,lengvojikavalerija,sunkiojiKavalerija,40,10,10,medienaRes,akmuoRes,gelezisRes,auksasRes,maistasRes);
                    if(arLaimeta==true)
                    {
                        ivikioNr++;
                        likesLaikasIkiIvikio=likesLaikasIkiIvikio+300;
                    }
                    else likesLaikasIkiIvikio=likesLaikasIkiIvikio+300;
                }
                else if(ivikioNr==3)
                {
                    goblinuAtaka(true,gynybinesSienosLygis,arLaimeta,apginkluotiBedarbiai,lengviejiPestininkai,sunkiejiPestininkai,lankininkai,lengvojikavalerija,sunkiojiKavalerija,300,medienaRes,akmuoRes,gelezisRes,auksasRes,maistasRes);
                    if(arLaimeta==true)
                    {
                        ivikioNr++;
                        likesLaikasIkiIvikio=likesLaikasIkiIvikio+300;
                    }
                    else likesLaikasIkiIvikio=likesLaikasIkiIvikio+300;
                }
                else if(ivikioNr==4)
                {
                    orkuAtaka(true,gynybinesSienosLygis,arLaimeta,apginkluotiBedarbiai,lengviejiPestininkai,sunkiejiPestininkai,lankininkai,lengvojikavalerija,sunkiojiKavalerija,100,40,40,medienaRes,akmuoRes,gelezisRes,auksasRes,maistasRes);
                    if(arLaimeta==true)
                    {
                        ivikioNr++;
                        likesLaikasIkiIvikio=likesLaikasIkiIvikio+500;
                    }
                    else likesLaikasIkiIvikio=likesLaikasIkiIvikio+400;
                }
                else if(ivikioNr==5)
                {
                    goblinuAtaka(true,gynybinesSienosLygis,arLaimeta,apginkluotiBedarbiai,lengviejiPestininkai,sunkiejiPestininkai,lankininkai,lengvojikavalerija,sunkiojiKavalerija,600,medienaRes,akmuoRes,gelezisRes,auksasRes,maistasRes);
                    if(arLaimeta==true)
                    {
                        ivikioNr++;
                        likesLaikasIkiIvikio=likesLaikasIkiIvikio+500;
                    }
                    else likesLaikasIkiIvikio=likesLaikasIkiIvikio+400;
                }
                else if(ivikioNr==6)
                {
                    orkuAtaka(true,gynybinesSienosLygis,arLaimeta,apginkluotiBedarbiai,lengviejiPestininkai,sunkiejiPestininkai,lankininkai,lengvojikavalerija,sunkiojiKavalerija,200,50,50,medienaRes,akmuoRes,gelezisRes,auksasRes,maistasRes);
                    if(arLaimeta==true)
                    {
                        ivikioNr++;
                        likesLaikasIkiIvikio=likesLaikasIkiIvikio+700;
                    }
                    else likesLaikasIkiIvikio=likesLaikasIkiIvikio+400;
                }
                else if(ivikioNr>=7)
                {
                    goblinuAtaka(true,gynybinesSienosLygis,arLaimeta,apginkluotiBedarbiai,lengviejiPestininkai,sunkiejiPestininkai,lankininkai,lengvojikavalerija,sunkiojiKavalerija,50,medienaRes,akmuoRes,gelezisRes,auksasRes,maistasRes);
                    orkuAtaka(true,gynybinesSienosLygis,arLaimeta,apginkluotiBedarbiai,lengviejiPestininkai,sunkiejiPestininkai,lankininkai,lengvojikavalerija,sunkiojiKavalerija,250,100,150,medienaRes,akmuoRes,gelezisRes,auksasRes,maistasRes);
                    if(arLaimeta==true)
                    {
                        ivikioNr++;
                        likesLaikasIkiIvikio=likesLaikasIkiIvikio+300;
                    }
                    else likesLaikasIkiIvikio=likesLaikasIkiIvikio+400;
                }
            }
            if(lentpjuvesDarbuotojai>10 && auksasRes>0)auksasRes=auksasRes-(lentpjuvesDarbuotojai-10);
            if(akmensSkaldyklosDarbuotojai>10 && auksasRes>0)auksasRes=auksasRes-(akmensSkaldyklosDarbuotojai-10);
            if(geleziesKasyklosDarbuotojai>10 && auksasRes>0)auksasRes=auksasRes-(2*(geleziesKasyklosDarbuotojai-10));
            if(maistasRes>0)maistasRes=maistasRes-visiKariai;
            rodyk();
            likesLaikasIkiIvikio--;
            Sleep(1000);
        }
        //orkuAtaka(true,gynybinesSienosLygis,arLaimeta,apginkluotiBedarbiai,lengviejiPestininkai,sunkiejiPestininkai,lankininkai,lengvojikavalerija,sunkiojiKavalerija,20,0,30,medienaRes,akmuoRes,gelezisRes,auksasRes,maistasRes);
        uzkrautiDuomenis();

    }
//----------------------------------------------------------------------------------
// sios funkcijos gauna pastatu kainas
    void lentpjuvesKaina(){
        gautiLentpjuvesFermosKaina(lentpjuvesLygis,2.5,2,1.8,1.5,10,medienosKaina,akmensKaina,geleziesKaina,auksoKaina);
    }
    void FermosKaina(){
        gautiLentpjuvesFermosKaina(fermosLygis,2.5,2,1.8,1.5,10,medienosKaina,akmensKaina,geleziesKaina,auksoKaina);
    }
    void akmensSakldyklosKaina(){
        gautiAkmensSkaldyklosKaina(akmensSakldyklosLygis,2.7,2.3,2,1.6,20,medienosKaina,akmensKaina,geleziesKaina,auksoKaina);
    }
    void geleziesKasyklosGynybinesSienosKaina(){
        gautiGeleziesKasyklosGynybinesSienosKaina(geleziesKasyklosLygis,2.8,2.4,2.2,1.7,40,medienosKaina,akmensKaina,geleziesKaina,auksoKaina);
    }
    void auksoKasyklosKaina(){
        gautiAuksoKasyklosKaina(auksoKasyklosLygis,3,2.6,2.4,2,60,medienosKaina,akmensKaina,geleziesKaina,auksoKaina);
    }
    void kareiviniuKaina(){
        gautiKituPastatuKaina(kareiviniuLygis,3,2.6,2.4,2,60,medienosKaina,akmensKaina,geleziesKaina,auksoKaina);
    }
    void gynybinesSienosKaina(){
        gautiGeleziesKasyklosGynybinesSienosKaina(gynybinesSienosLygis,2.8,3.2,2.2,1.7,80,medienosKaina,akmensKaina,geleziesKaina,auksoKaina);
    }
    //----------------------------------------------------------------------------------
    void rodyk(){
        gotoxy(1,3);
        cout<<"          ";
        gotoxy(1,3);
        cout<<(int)medienaRes;
        gotoxy(14,3);
        cout<<"          ";
        gotoxy(14,3);
        cout<<(int)akmuoRes;
        gotoxy(27,3);
        cout<<"          ";
        gotoxy(27,3);
        cout<<(int)gelezisRes;
        gotoxy(40,3);
        cout<<"          ";
        gotoxy(40,3);
        cout<<(int)auksasRes;
        gotoxy(53,3);
        cout<<"          ";
        gotoxy(53,3);
        cout<<(int)maistasRes;
        gotoxy(66,3);
        cout<<"          ";
        gotoxy(66,3);
        cout<<(int)laisvigyventojaiSk;
    }
    //----------------------------------------------------------------------------------
    // sios funkcijos rodo info, kainas
    void rodykStats(){

        info.setMatmenis(56,5);
        info.setMatmenis2(79,20);
        info.pridedamInfoPunkta("Medkirciai:",lentpjuvesDarbuotojai);
        info.pridedamInfoPunkta("Akmenskaldziai:",akmensSkaldyklosDarbuotojai);
        info.pridedamInfoPunkta("Gelezkasiai:",geleziesKasyklosDarbuotojai);
        info.pridedamInfoPunkta("Auksakasiai:",auksoKasyklosDarbuotojai);
        info.pridedamInfoPunkta("Ukininkai:",fermosDarbuotojai);
        info.pridedamInfoPunkta("Apginkl. bedarb.",apginkluotiBedarbiai);
        info.pridedamInfoPunkta("L. pestininkai:",lengviejiPestininkai);
        info.pridedamInfoPunkta("S. pestininkai:",sunkiejiPestininkai);
        info.pridedamInfoPunkta("Lankininkai:",lankininkai);
        info.pridedamInfoPunkta("L. kavalerija:",lengvojikavalerija);
        info.pridedamInfoPunkta("S. kavalerija:",sunkiojiKavalerija);
        info.rodyk(false,false);
        info.naikinam(true,true);
    }
    void rodykLaika(int laikas){
        info.naikinam(false,true);
        info.setMatmenis(31,21);
        info.setMatmenis2(55,31);
        info.pridedamInfoPunkta("Darbo laikas",laikas);
        info.pridedamInfoPunkta("A.b laikas",apginkluotiBedarbiaiPaskirtiLaikas);
        info.pridedamInfoPunkta("L.p. laikas",lengviejiPestininkaiPaskirtiLaikas);
        info.pridedamInfoPunkta("S.p. laikas",sunkiejiPestininkaiPaskirtiLaikas);
        info.pridedamInfoPunkta("Lank. laikas",lankininkaiPaskirtiLaikas);
        info.pridedamInfoPunkta("L.k. laikas",lengvojikavalerijaPaskirtiLaikas);
        info.pridedamInfoPunkta("S.k. laikas",sunkiojiKavalerijaPaskirtiLaikas);
        info.pridedamInfoPunkta("",-1);
        info.pridedamInfoPunkta("Laikas iki ivykio",sunkiojiKavalerijaPaskirtiLaikas);
        info.rodyk(true,true);
        info.naikinam(true,true);
    }
    void rodykRuosiamuskarius(){
        info.naikinam(false,true);
        info.setMatmenis(56,21);
        info.setMatmenis2(79,31);
        //info.pridedamInfoPunkta("Darbo laikas",laikas);
        info.pridedamInfoPunkta("Treniruojami a.b",apginkluotiBedarbiaiPaskirti);
        info.pridedamInfoPunkta("Treniruojami l.p.",lengviejiPestininkaiPaskirti);
        info.pridedamInfoPunkta("Treniruojami s.p.",sunkiejiPestininkaiPaskirti);
        info.pridedamInfoPunkta("Treniruojami lank.",lankininkaiPaskirti);
        info.pridedamInfoPunkta("Treniruojami l.k.",lengvojikavalerijaPaskirti);
        info.pridedamInfoPunkta("Treniruojami s.k.",sunkiojiKavalerijaPaskirti);
        info.rodyk(false,true);
    }
    void rodykKaina(string a, int lvl){
        kaina.naikinam(true,true);
        kaina.setMatmenis(1,8);
        kaina.setMatmenis2(23,12);
        kaina.pridedamInfoPunkta("",-1);
        kaina.pridedamInfoPunkta(a,lvl);
        kaina.pridedamInfoPunkta("",-1);
        kaina.pridedamInfoPunkta("Pirkti/tobulinti uz:",-1);
        kaina.pridedamInfoPunkta("",-1);
        kaina.pridedamInfoPunkta("Medienos:",medienosKaina);
        kaina.pridedamInfoPunkta("Akmens:",akmensKaina);
        kaina.pridedamInfoPunkta("Gelezies:",geleziesKaina);
        kaina.pridedamInfoPunkta("Aukso:",auksoKaina);
        kaina.rodyk(true,false);
    }
    void rodykPriesoKariuKiekis(int kariuKiekis, string priesas){
        info.naikinam(true,true);
        info.setMatmenis(1,8);
        info.setMatmenis2(23,12);
        info.pridedamInfoPunkta("",-1);
        info.pridedamInfoPunkta("Ar tikrai norite pulti",-1);
        info.pridedamInfoPunkta(priesas,-1);
        info.pridedamInfoPunkta("",-1);
        info.pridedamInfoPunkta("Prieso k. kiekis:",kariuKiekis);
        info.rodyk(true,false);
    }
    //----------------------------------------------------------------------------------
    void ivedimoLaukas(int&sk){
        ivestis.setMatmenis(25,5);
        ivestis.setMatmenis2(55,7);
        ivestis.pridedamInfoPunkta("Iveskite kieki:",-1);
        ivestis.rodyk(true,true);
        gotoxy(45,6);
        cin>>sk;
        ivestis.naikinam(true,true);
        ivestis.rodyk(true,false);
    }
    void pradinisIvedimoLaukas(string&failas){
        ivestis.setMatmenis(1,29);
        ivestis.setMatmenis2(50,31);
        ivestis.pridedamInfoPunkta("Iveskite zaidejo pav.:",-1);
        ivestis.rodyk(true,true);
        gotoxy(25,30);
        cin>>failas;
        ivestis.naikinam(true,true);
        //ivestis.rodyk(true,false);
    }
    //----------------------------------------------------------------------------------
    // sios funkcijos leidzia zaidejui pulti priesus
    void pultiGoblinus(int goblinuSk){
        bool arLaimeta;
        int kariuKiekis=goblinuSk;
        goblinuAtaka(false,gynybinesSienosLygis,arLaimeta,apginkluotiBedarbiai,lengviejiPestininkai,sunkiejiPestininkai,lankininkai,lengvojikavalerija,sunkiojiKavalerija,goblinuSk,medienaRes,akmuoRes,gelezisRes,auksasRes,maistasRes);
        if(arLaimeta==true){
            medienaRes=medienaRes+(2*kariuKiekis);
            akmuoRes=akmuoRes+(2*kariuKiekis);
            gelezisRes=gelezisRes+(2*kariuKiekis);
            auksasRes=auksasRes+(2*kariuKiekis);
            maistasRes=maistasRes+(2*kariuKiekis);
            puolimoNr++;
        }
    }
    void pultiOrkus(int orkuPestininkai, int orkuLankininkai, int orkuKavalerija){
        bool arLaimeta;
        int kariuKiekis=orkuKavalerija+orkuPestininkai+orkuLankininkai;
        orkuAtaka(false,gynybinesSienosLygis,arLaimeta,apginkluotiBedarbiai,lengviejiPestininkai,sunkiejiPestininkai,lankininkai,lengvojikavalerija,sunkiojiKavalerija,orkuPestininkai,orkuLankininkai,orkuKavalerija,medienaRes,akmuoRes,gelezisRes,auksasRes,maistasRes);
        if(arLaimeta==true){
            medienaRes=medienaRes+(5*kariuKiekis);
            akmuoRes=akmuoRes+(5*kariuKiekis);
            gelezisRes=gelezisRes+(5*kariuKiekis);
            auksasRes=auksasRes+(5*kariuKiekis);
            maistasRes=maistasRes+(5*kariuKiekis);
            puolimoNr++;
        }
    }
    //----------------------------------------------------------------------------------
    int getLentpjuvesLygis(){
        return lentpjuvesLygis;
    }
    int getAkmensSkaldyklosLygis(){
        return akmensSakldyklosLygis;
    }
    int getGeleziesKasyklosLygis(){
        return geleziesKasyklosLygis;
    }
    int getAuksoKasyklosLygis(){
        return auksoKasyklosLygis;
    }
    int getFermosLygis(){
        return fermosLygis;
    }
    int getKareiviniuLygis(){
        return kareiviniuLygis;
    }
    int getGynybinesSienosLygis(){
        return gynybinesSienosLygis;
    }
    int getPuolimoNr(){
        return puolimoNr;
    }
    void issaugojimas(string failas){
        string txt=".txt";
        failas=failas+txt;
        ofstream out(failas);
        out<<lentpjuvesLygis<<" "<<akmensSakldyklosLygis<<" "<<geleziesKasyklosLygis<<" "<<fermosLygis<<" "<<auksoKasyklosLygis<<endl;
        out<<kareiviniuLygis<<" "<<gynybinesSienosLygis<<endl;
        out<<apginkluotiBedarbiai<<" "<<lengviejiPestininkai<<" "<<sunkiejiPestininkai<<" "<<lankininkai<<" "<<lengvojikavalerija<<" "<<sunkiojiKavalerija<<endl;
        out<<apginkluotiBedarbiaiPaskirti<<" "<<lengviejiPestininkaiPaskirti<<" "<<sunkiejiPestininkaiPaskirti<<" "<<lankininkaiPaskirti<<" "<<lengvojikavalerijaPaskirti<<" "<<sunkiojiKavalerijaPaskirti<<endl;
        out<<apginkluotiBedarbiaiPaskirtiLaikas<<" "<<lengviejiPestininkaiPaskirtiLaikas<<" "<<sunkiejiPestininkaiPaskirtiLaikas<<" "<<lankininkaiPaskirtiLaikas<<" "<<lengvojikavalerijaPaskirtiLaikas<<" "<<sunkiojiKavalerijaPaskirtiLaikas<<endl;
        out<<medienaRes<<" "<<akmuoRes<<" "<<gelezisRes<<" "<<auksasRes<<" "<<maistasRes<<endl;
        out<<laisvigyventojaiSk<<endl;
        out<<lentpjuvesDarbuotojai<<" "<<akmensSkaldyklosDarbuotojai<<" "<<geleziesKasyklosDarbuotojai<<" "<<auksoKasyklosDarbuotojai<<" "<<fermosDarbuotojai<<endl;
        out<<likesLaikasIkiIvikio<<" "<<ivikioNr<<" "<<puolimoNr<<endl;
        out.close();
    }
    void paleidimas(string failas){
        string txt=".txt";
        failas=failas+txt;
        ifstream in(failas);
        in>>lentpjuvesLygis>>akmensSakldyklosLygis>>geleziesKasyklosLygis>>fermosLygis>>auksoKasyklosLygis;
        in>>kareiviniuLygis>>gynybinesSienosLygis;
        in>>apginkluotiBedarbiai>>lengviejiPestininkai>>sunkiejiPestininkai>>lankininkai>>lengvojikavalerija>>sunkiojiKavalerija;
        in>>apginkluotiBedarbiaiPaskirti>>lengviejiPestininkaiPaskirti>>sunkiejiPestininkaiPaskirti>>lankininkaiPaskirti>>lengvojikavalerijaPaskirti>>sunkiojiKavalerijaPaskirti;
        in>>apginkluotiBedarbiaiPaskirtiLaikas>>lengviejiPestininkaiPaskirtiLaikas>>sunkiejiPestininkaiPaskirtiLaikas>>lankininkaiPaskirtiLaikas>>lengvojikavalerijaPaskirtiLaikas>>sunkiojiKavalerijaPaskirtiLaikas;
        in>>medienaRes>>akmuoRes>>gelezisRes>>auksasRes>>maistasRes;
        in>>laisvigyventojaiSk;
        in>>lentpjuvesDarbuotojai>>akmensSkaldyklosDarbuotojai>>geleziesKasyklosDarbuotojai>>auksoKasyklosDarbuotojai>>fermosDarbuotojai;
        in>>likesLaikasIkiIvikio>>ivikioNr>>puolimoNr;
        in.close();
    }
    void uzkrautiDuomenis(){
    gotoxy(75,22);
    cout<<"    ";
    gotoxy(75,22);
    if(apginkluotiBedarbiaiPaskirti!=0)cout<<apginkluotiBedarbiaiPaskirti;
    else cout<<'-';
    gotoxy(75,23);
    cout<<"    ";
    gotoxy(75,23);
    if(lengviejiPestininkaiPaskirti!=0)cout<<lengviejiPestininkaiPaskirti;
    else cout<<'-';
    gotoxy(75,24);
    cout<<"    ";
    gotoxy(75,24);
    if(sunkiejiPestininkaiPaskirti!=0)cout<<sunkiejiPestininkaiPaskirti;
    else cout<<'-';
    gotoxy(75,25);
    cout<<"    ";
    gotoxy(75,25);
    if(lankininkaiPaskirti!=0)cout<<lankininkaiPaskirti;
    else cout<<'-';
    gotoxy(75,26);
    cout<<"    ";
    gotoxy(75,26);
    if(lengvojikavalerijaPaskirti!=0)cout<<lengvojikavalerijaPaskirti;
    else cout<<'-';
    gotoxy(75,27);
    cout<<"    ";
    gotoxy(75,27);
    if(sunkiojiKavalerijaPaskirti!=0)cout<<sunkiojiKavalerijaPaskirti;
    else cout<<'-';
    gotoxy(75,6);
    cout<<"    ";
    gotoxy(75,6);
    if(lentpjuvesDarbuotojai!=0)cout<<lentpjuvesDarbuotojai;
    else cout<<'-';
    gotoxy(75,7);
    cout<<"    ";
    gotoxy(75,7);
    if(akmensSkaldyklosDarbuotojai!=0)cout<<akmensSkaldyklosDarbuotojai;
    else cout<<'-';
    gotoxy(75,8);
    cout<<"    ";
    gotoxy(75,8);
    if(geleziesKasyklosDarbuotojai!=0)cout<<geleziesKasyklosDarbuotojai;
    else cout<<'-';
    gotoxy(75,9);
    cout<<"    ";
    gotoxy(75,9);
    if(auksoKasyklosDarbuotojai!=0)cout<<auksoKasyklosDarbuotojai;
    else cout<<'-';
    gotoxy(75,10);
    cout<<"    ";
    gotoxy(75,10);
    if(fermosDarbuotojai!=0)cout<<fermosDarbuotojai;
    else cout<<'-';
    gotoxy(75,11);
    cout<<"    ";
    gotoxy(75,11);
    if(apginkluotiBedarbiai!=0)cout<<apginkluotiBedarbiai;
    else cout<<'-';
    gotoxy(75,12);
    cout<<"    ";
    gotoxy(75,12);
    if(lengviejiPestininkai!=0)cout<<lengviejiPestininkai;
    else cout<<'-';
    gotoxy(75,13);
    cout<<"    ";
    gotoxy(75,13);
    if(sunkiejiPestininkai!=0)cout<<sunkiejiPestininkai;
    else cout<<'-';
    gotoxy(75,14);
    cout<<"    ";
    gotoxy(75,14);
    if(lankininkai!=0)cout<<lankininkai;
    else cout<<'-';
    gotoxy(75,15);
    cout<<"    ";
    gotoxy(75,15);
    if(lengvojikavalerija!=0)cout<<lengvojikavalerija;
    else cout<<'-';
    gotoxy(75,16);
    cout<<"    ";
    gotoxy(75,16);
    if(sunkiojiKavalerija!=0)cout<<sunkiojiKavalerija;
    else cout<<'-';
    gotoxy(51,22);
    cout<<'-';
    gotoxy(51,23);
    cout<<"    ";
    gotoxy(51,23);
    if(apginkluotiBedarbiaiPaskirtiLaikas!=0)cout<<apginkluotiBedarbiaiPaskirtiLaikas;
    else cout<<'-';
    gotoxy(51,24);
    cout<<"    ";
    gotoxy(51,24);
    if(lengviejiPestininkaiPaskirtiLaikas!=0)cout<<lengviejiPestininkaiPaskirtiLaikas;
    else cout<<'-';
    gotoxy(51,25);
    cout<<"    ";
    gotoxy(51,25);
    if(sunkiejiPestininkaiPaskirtiLaikas!=0)cout<<sunkiejiPestininkaiPaskirtiLaikas;
    else cout<<'-';
    gotoxy(51,26);
    cout<<"    ";
    gotoxy(51,26);
    if(lankininkaiPaskirtiLaikas!=0)cout<<lankininkaiPaskirtiLaikas;
    else cout<<'-';
    gotoxy(51,27);
    cout<<"    ";
    gotoxy(51,27);
    if(lengvojikavalerijaPaskirtiLaikas!=0)cout<<lengvojikavalerijaPaskirtiLaikas;
    else cout<<'-';
    gotoxy(51,28);
    cout<<"    ";
    gotoxy(51,28);
    if(sunkiojiKavalerijaPaskirtiLaikas!=0)cout<<sunkiojiKavalerijaPaskirtiLaikas;
    else cout<<'-';
    gotoxy(51,30);
    cout<<"    ";
    gotoxy(51,30);
    cout<<likesLaikasIkiIvikio;


    }
};

void pasirinkimas(int meniuPunktuKiekis,int&key){//vaiksciojancios rodykles funkcija
    bool pasirinkta=false;
    int pasirinktasPunktas=0, i=0, x=1, y=6;
    gotoxy(x,y);
    cout<<"->";
    while(pasirinkta==false)
    {
        key=getch();
        switch(key)
        {
        case KEY_UP:
            if(pasirinktasPunktas>0)
            {
                pasirinktasPunktas--;
                gotoxy(x,y);
                cout<<"  ";
                y=6+pasirinktasPunktas;
                gotoxy(x,y);
                cout<<"->";
            }
            break;
        case KEY_DOWN:
            if(pasirinktasPunktas<meniuPunktuKiekis-1)
            {
                pasirinktasPunktas++;
                gotoxy(x,y);
                cout<<"  ";
                y=6+pasirinktasPunktas;
                gotoxy(x,y);
                cout<<"->";
            }
            break;
        case KEY_ENTER:
            gotoxy(x,y);
            cout<<"  ";
            key=pasirinktasPunktas;
            pasirinkta=true;
            break;

        default:
            break;
        }

    }
}
void welcome(){
gotoxy(32,5);
cout<<char(201)<<char(187)<<char(201)<<char(187)<<char(201)<<char(187)<<"  "<<char(201)<<char(187);
gotoxy(32,6);
cout<<char(186)<<char(186)<<char(186)<<char(186)<<char(186)<<char(186)<<"  "<<char(186)<<char(186);
gotoxy(32,7);
cout<<char(186)<<char(186)<<char(186)<<char(186)<<char(186)<<char(204)<<char(205)<<char(205)<<char(185)<<char(186)<<char(201)<<char(205)<<char(205)<<char(203)<<char(205)<<char(205)<<char(203)<<char(187)<<char(201)<<char(203)<<char(205)<<char(205)<<char(187);
gotoxy(32,8);
cout<<char(186)<<char(200)<<char(188)<<char(200)<<char(188)<<char(186)<<char(186)<<char(205)<<char(185)<<char(186)<<char(186)<<char(201)<<char(205)<<char(185)<<char(201)<<char(187)<<char(186)<<char(200)<<char(188)<<char(186)<<char(186)<<char(205)<<char(185);
gotoxy(32,9);
cout<<char(200)<<char(187)<<char(201)<<char(187)<<char(201)<<char(185)<<char(186)<<char(205)<<char(185)<<char(200)<<char(185)<<char(200)<<char(205)<<char(185)<<char(200)<<char(188)<<char(186)<<char(186)<<char(186)<<char(186)<<char(186)<<char(205)<<char(185);
gotoxy(32,10);
cout<<" "<<char(200)<<char(188)<<char(200)<<char(188)<<char(200)<<char(205)<<char(205)<<char(202)<<char(205)<<char(202)<<char(205)<<char(205)<<char(202)<<char(205)<<char(205)<<char(202)<<char(202)<<char(202)<<char(202)<<char(205)<<char(205)<<char(188);
gotoxy(32,11);
cout<<char(201)<<char(205)<<char(205)<<char(205)<<char(205)<<char(187);
gotoxy(32,12);
cout<<char(186)<<char(201)<<char(187)<<char(201)<<char(187)<<char(186);
gotoxy(32,13);
cout<<char(200)<<char(188)<<char(186)<<char(186)<<char(204)<<char(202)<<char(205)<<char(187);
gotoxy(32,14);
cout<<"  "<<char(186)<<char(186)<<char(186)<<char(201)<<char(187)<<char(186);
gotoxy(32,15);
cout<<"  "<<char(186)<<char(186)<<char(186)<<char(200)<<char(188)<<char(186);
gotoxy(32,16);
cout<<"  "<<char(200)<<char(188)<<char(200)<<char(205)<<char(205)<<char(188);
gotoxy(32,17);
cout<<char(201)<<char(187)<<char(201)<<char(205)<<char(187)<<"        "<<char(201)<<char(187);
gotoxy(32,18);
cout<<char(186)<<char(186)<<char(186)<<char(201)<<char(188)<<"        "<<char(186)<<char(186);
gotoxy(32,19);
cout<<char(186)<<char(200)<<char(188)<<char(188)<<char(201)<<char(203)<<char(205)<<char(187)<<char(201)<<char(205)<<char(205)<<char(203)<<char(205)<<char(188)<<char(204)<<char(205)<<char(205)<<char(203)<<char(187)<<char(201)<<char(187);
gotoxy(32,20);
cout<<char(186)<<char(201)<<char(187)<<char(186)<<char(204)<<char(185)<<char(201)<<char(187)<<char(185)<<char(201)<<char(187)<<char(186)<<char(201)<<char(187)<<char(186)<<char(201)<<char(187)<<char(186)<<char(200)<<char(188)<<char(186);
gotoxy(32,21);
cout<<char(186)<<char(186)<<char(186)<<char(200)<<char(185)<<char(186)<<char(186)<<char(186)<<char(186)<<char(200)<<char(188)<<char(186)<<char(200)<<char(188)<<char(186)<<char(200)<<char(188)<<char(186)<<char(186)<<char(186)<<char(186);
gotoxy(32,22);
cout<<char(200)<<char(188)<<char(200)<<char(205)<<char(202)<<char(202)<<char(188)<<char(200)<<char(202)<<char(205)<<char(187)<<char(204)<<char(205)<<char(205)<<char(202)<<char(205)<<char(205)<<char(202)<<char(202)<<char(202)<<char(188);
gotoxy(32,23);
cout<<"        "<<char(201)<<char(205)<<char(188)<<char(186);
gotoxy(32,24);
cout<<"        "<<char(200)<<char(205)<<char(205)<<char(188);
}
int main(){
    SetWindow(80,33);
    showConsoleCursor(false);
    srand(time(NULL));
    int seivuSk;
    int key, failoIndex;
    string seivai[100];
    //------------------
    pastataiIrPagrindinis a;
    priesai puolimas;
    ekr::pagrindinis pagrLangas;
    ekr::resursuTab resursuLangas;
    meniuLenteles meniu, msgBox;
    //------------------
    pagrLangas.rodyk();
    welcome();
    meniu.pradinisMeniu();
    pasirinkimas(2,key);
    switch(key){
    case 0:
        {

        ifstream inSeivai("seivai.txt");
        ifstream inSeivuSk("seivuSk.txt");
        inSeivuSk>>seivuSk;
        for(int i=0; i<seivuSk; i++)inSeivai>>seivai[i];
        gotoxy(1,25);
        a.pradinisIvedimoLaukas(seivai[seivuSk]);
        failoIndex=seivuSk;
        inSeivai.close();
        inSeivuSk.close();
        ofstream outSeivai("seivai.txt");
        ofstream outSeivuSk("seivuSk.txt");
        seivuSk++;
        for(int i=0; i<seivuSk; i++)outSeivai<<seivai[i]<<endl;
        outSeivuSk<<seivuSk;
        outSeivai.close();
        outSeivuSk.close();
        }
        break;
    case 1:
        {
        ifstream inSeivai("seivai.txt");
        ifstream inSeivuSk("seivuSk.txt");
        inSeivuSk>>seivuSk;
        for(int i=0; i<seivuSk; i++)inSeivai>>seivai[i];
        meniu.seniZaidimai(seivai,seivuSk);
        pasirinkimas(seivuSk,key);
        a.paleidimas(seivai[key]);
        failoIndex=key;
        inSeivai.close();
        inSeivuSk.close();
        }
        break;
    }
    pagrLangas.rodyk();
    resursuLangas.rodyk();
    msgBox.pradinisMsgBox();
    //--------------
    a.rodykStats();
    a.rodykLaika(0);
    a.rodykRuosiamuskarius();
    a.uzkrautiDuomenis();
    //--------------
    while(1)
    {
        a.issaugojimas(seivai[failoIndex]);
        meniu.pagrindinisMeniu();
        a.rodyk();
        a.uzkrautiDuomenis();
        pasirinkimas(6,key);
        switch(key)
        {
        case 0:// Pastatu pirkimas ir tobulinimas
atgalPastataiMeniu:
            a.rodyk();
            meniu.pastataiMeniu();
            pasirinkimas(8,key);
            switch(key)
            {
            case 0:
                //Lentpjuve
                meniu.taipNeMeniu();
                a.lentpjuvesKaina();
                a.rodykKaina("Lentpjuves lvl ",a.getLentpjuvesLygis());
                pasirinkimas(2,key);
                switch(key)
                {
                case 0:
                {
                    a.lentpjuve(true);
                    goto atgalPastataiMeniu;
                }
                case 1:
                    goto atgalPastataiMeniu;
                }
            case 1:
                //Akmens Skaldykla
                meniu.taipNeMeniu();
                a.akmensSakldyklosKaina();
                a.rodykKaina("Akmens skald. lvl ",a.getAkmensSkaldyklosLygis());
                pasirinkimas(2,key);
                switch(key)
                {
                case 0:
                {
                    a.akmensSakldykla(true);
                    goto atgalPastataiMeniu;
                }
                case 1:
                    goto atgalPastataiMeniu;
                }
            case 2:
                //Gelezies kasykla
                meniu.taipNeMeniu();
                a.geleziesKasyklosGynybinesSienosKaina();
                a.rodykKaina("Gelezies kasy. lvl ",a.getGeleziesKasyklosLygis());
                pasirinkimas(2,key);
                switch(key)
                {
                case 0:
                {
                    a.geleziesKasykla(true);
                    goto atgalPastataiMeniu;
                }
                case 1:
                    goto atgalPastataiMeniu;
                }
            case 3:
                //Aukso kasykla
                meniu.taipNeMeniu();
                a.auksoKasyklosKaina();
                a.rodykKaina("Aukso kasyklos lvl ",a.getAuksoKasyklosLygis());
                pasirinkimas(2,key);
                switch(key)
                {
                case 0:
                {
                    a.auksoKasykla(true);
                    goto atgalPastataiMeniu;
                }
                case 1:
                    goto atgalPastataiMeniu;
                }
            case 4:
                //Ferma
                meniu.taipNeMeniu();
                a.FermosKaina();
                a.rodykKaina("Fermos lvl ", a.getFermosLygis());
                pasirinkimas(2,key);
                switch(key)
                {
                case 0:
                {
                    a.ferma(true);
                    goto atgalPastataiMeniu;
                }
                case 1:
                    goto atgalPastataiMeniu;
                }
            case 5:
                meniu.taipNeMeniu();
                a.kareiviniuKaina();
                a.rodykKaina("Kareiviniu lvl", a.getKareiviniuLygis());
                pasirinkimas(2,key);
                switch(key)
                {
                case 0:
                {
                    a.kareivines(true);
                    goto atgalPastataiMeniu;
                }
                case 1:
                    goto atgalPastataiMeniu;
                }
            case 6:
                meniu.taipNeMeniu();
                a.gynybinesSienosKaina();
                a.rodykKaina("Gyn. Sienos lvl", a.getGynybinesSienosLygis());
                pasirinkimas(2,key);
                switch(key)
                {
                case 0:
                {
                    a.gynybineSiena(true);
                    goto atgalPastataiMeniu;
                }
                case 1:
                    goto atgalPastataiMeniu;
                }
            case 7:
                break;
            }
            break;
        case 1://Darbuotoju paskyrimas
atgalDarbuotojuPaskyrimas:
            //a.rodykStats();
            a.rodyk();
            meniu.darbuotojaiMeniu();
            pasirinkimas(6,key);
            switch(key)
            {
            case 0:
                if(a.getLentpjuvesLygis()>0)
                    a.lentpjuvesDarbuotojuPaskyrimas();
                else msgBox.nenupirktoPastatoMsgBox("Neturite lentpjuves");
                goto atgalDarbuotojuPaskyrimas;
            case 1:
                if(a.getAkmensSkaldyklosLygis()>0)
                    a.akmensSkaldyklosDarbuotojuPaskyrimas();
                else msgBox.nenupirktoPastatoMsgBox("Neturite akmens skaldyklos");
                goto atgalDarbuotojuPaskyrimas;
            case 2:
                if(a.getGeleziesKasyklosLygis()>0)
                    a.geleziesKasyklosDarbuotojuPaskyrimas();
                else msgBox.nenupirktoPastatoMsgBox("Neturite gelezies kasyklos");
                goto atgalDarbuotojuPaskyrimas;
            case 3:
                if(a.getAuksoKasyklosLygis()>0)
                    a.auksoKasyklosDarbuotojuPaskyrimas();
                else msgBox.nenupirktoPastatoMsgBox("Neturite aukso kasyklos");
                goto atgalDarbuotojuPaskyrimas;
            case 4:
                if(a.getFermosLygis()>0)
                    a.fermosDarbuotojuPaskyrimas();
                else msgBox.nenupirktoPastatoMsgBox("Neturite fermos");
                goto atgalDarbuotojuPaskyrimas;
            case 5:
                break;
            }
            break;
        case 2:// Kareiviu treniravimas
atgalKareiviuPaskyrimas:
            a.rodyk();
            meniu.kareiviaiMeniu();
            pasirinkimas(7,key);
            switch(key)
            {
            case 0:
                a.apginkluotuBedarbiuPaskyrimas();
                goto atgalKareiviuPaskyrimas;
            case 1:
                if(a.getKareiviniuLygis()>=1)
                    a.lengvujuPestininkuPaskyrimas();
                else msgBox.kareiviniuLvlMsgBox(a.getKareiviniuLygis(),1);
                goto atgalKareiviuPaskyrimas;
            case 2:
                if(a.getKareiviniuLygis()>=3)
                    a.sunkiujuPestininkuPaskyrimas();
                else msgBox.kareiviniuLvlMsgBox(a.getKareiviniuLygis(),3);
                goto atgalKareiviuPaskyrimas;
            case 3:
                if(a.getKareiviniuLygis()>=5)
                    a.lankininkuPaskyrimas();
                else msgBox.kareiviniuLvlMsgBox(a.getKareiviniuLygis(),5);
                goto atgalKareiviuPaskyrimas;
            case 4:
                if(a.getKareiviniuLygis()>=7)
                    a.lengvosiosKavalerijosPaskyrimas();
                else msgBox.kareiviniuLvlMsgBox(a.getKareiviniuLygis(),7);
                goto atgalKareiviuPaskyrimas;
            case 5:
                if(a.getKareiviniuLygis()>=8)
                    a.sunkiosiosKavalerijosPaskyrimas();
                else msgBox.kareiviniuLvlMsgBox(a.getKareiviniuLygis(),8);
                goto atgalKareiviuPaskyrimas;
            case 6:
                break;
            }

            break;
        case 3:
            a.bedarbiuPirkimas();
            break;
        case 4:
            meniu.priesuMeniu();
            pasirinkimas(8,key);
                switch(key){
            case 0:
                meniu.taipNeMeniu();
                a.rodykPriesoKariuKiekis(100,"goblinus?");
                pasirinkimas(2,key);
                    switch(key){
                case 0:
                    if(a.getPuolimoNr()==0)a.pultiGoblinus(100);
                case 1:
                    break;
                    }
                    break;
            case 1:
                meniu.taipNeMeniu();
                a.rodykPriesoKariuKiekis(70,"orkus?");
                pasirinkimas(2,key);
                switch(key){
                case 0:
                    if(a.getPuolimoNr()==1)a.pultiOrkus(40,10,20);
                case 1:
                    break;
                    }
                break;
            case 2:
                meniu.taipNeMeniu();
                a.rodykPriesoKariuKiekis(350,"goblinus?");
                pasirinkimas(2,key);
                switch(key){
                case 0:
                    if(a.getPuolimoNr()==2)a.pultiGoblinus(350);
                case 1:
                    break;
                    }
                break;
            case 3:
                meniu.taipNeMeniu();
                a.rodykPriesoKariuKiekis(185,"orkus?");
                pasirinkimas(2,key);
                switch(key){
                case 0:
                    if(a.getPuolimoNr()==3)a.pultiOrkus(100,50,35);
                case 1:
                    break;
                    }
                break;
            case 4:
                meniu.taipNeMeniu();
                a.rodykPriesoKariuKiekis(1000,"goblinus?");
                pasirinkimas(2,key);
                switch(key){
                case 0:
                    if(a.getPuolimoNr()==4)a.pultiGoblinus(1000);
                case 1:
                    break;
                    }
                break;
            case 5:
                meniu.taipNeMeniu();
                a.rodykPriesoKariuKiekis(500,"orkus?");
                pasirinkimas(2,key);
                switch(key){
                case 0:
                    if(a.getPuolimoNr()==5)a.pultiOrkus(250,250,0);
                case 1:
                    break;
                    }
                break;
            case 6:
                meniu.taipNeMeniu();
                a.rodykPriesoKariuKiekis(1800,"orkus?");
                pasirinkimas(2,key);
                switch(key){
                case 0:
                    if(a.getPuolimoNr()==6)a.pultiOrkus(1000,500,300);
                case 1:
                    break;
                    }
                break;
            case 7:
                break;
                }
                break;
        case 5:
            int sk;
            a.ivedimoLaukas(sk);
            if(sk>=0 && sk<=60)
            {
                a.vykstaDarbas(sk);
            }
            else msgBox.prastoLaikoMsgBox();
            //a.rodyk();
            break;

        }

    }

    //key=_getch();
    //cout<<key;
    //SMALL_RECT windowSize = {0, 0, 60, 60};

    //SetConsoleWindowInfo(konsole, TRUE, &windowSize);
    //getchar();
    return 0;
}
