#ifndef EKRANAS_H_DEFINED
#define EKRANAS_H_DEFINED

#include <string>
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <bits/stdc++.h>
namespace ekr{
class spalvaClass {
    short spalva, remelioSpalva;
public:
    bool setSpalva(short);
    bool setRemelioSpalva(short);
    short getSpalva();
    short getRemelioSpalva();
};

class matmenysClass {
    short x, y, x2, y2,xTeksto,yTeksto;
public:
    bool setMatmenis(short,short);
    void getMatmenis(short&, short&);
    bool setMatmenis2(short,short);
    void getMatmenis2(short&, short&);
    bool setMatmenisTekstoPradzios(short,short);
    void getMatmenisTekstoPradzios(short&, short&);
};

class pagrindinis : public spalvaClass, public matmenysClass {
    bool linija, linijaDviguba;
public:

    pagrindinis();
    void setLinija(bool);
    void setLinijaDviguba(bool);
    void getLangasKoordinates(short&, short&, short&, short&);
    void rodyk();
};
class resursuTab: public spalvaClass, public matmenysClass{
    std::string tekstas;
public:
    void setTekstas(std::string);
    resursuTab();
    void getTekstoLangasKoordinates(short&, short&, short&, short&);
    void rodyk();
};

class meniuClass : public spalvaClass,public matmenysClass {
private:
    std:: vector<std::string> meniuPunktai;
    short kiekis=0;
    int medzioKaina, akmensKaina, auksoKaina, geleziesKaina;
    bool arKaina=false;
public:
    meniuClass();
    void pridedamMeniuPunkta(std::string);
    void pridedamKaina(int,int,int,int);
    void getMeniuKoordinates(short&, short&, short&, short&);
    void naikinam();

    void rodyk();

};
class infoClass : public spalvaClass,public matmenysClass{
std:: vector<std::string> infoPunktai;
std:: vector<int> info;
short kiekis=0;
public:
    infoClass();
    void pridedamInfoPunkta(std::string,int);
    void getInfoKoordinates(short&, short&, short&, short&);
    void naikinam(bool,bool);
    void rodyk(bool,bool);
};
}
#endif // EKRANAS_H_DEFINED
