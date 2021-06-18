#include<iostream>
#include<fstream>
#include<string.h>


#include <stack>
#include <queue>
#include "veriYapisi.hpp"

using namespace std ;



/*******************************************************************************/

/*******************************************************************************/

Agac *agac1 = new Agac((char*)"data1.txt");
Agac *agac2 = new Agac((char*)"data2.txt");
Agac *agac3 = new Agac((char*)"data3.txt");

/*******************************************************************************/

void menu_Main()
{
    system("cls || clear");
    cout << "\t\t\t### ISLEM MENUSU ####" <<::endl;
    cout << " Arama yapmak icin   [A]" <<::endl; 
    cout << " Listeyi gormek icin [L]" <<::endl; 
    cout << " Ogrenci silmek icin [S]" <<::endl; 
    cout << " Dosyaya yazmak icin [Y]" <<::endl; 
    cout << " Cikis yapmak icin   [C]" <<::endl; 
    cout << "\n Yapmak istediginiz islem icin yukaridaki durumlardan birini giriniz..." <<::endl;
}

char secimAl()
{   
    char girdi;
    cout << "\n Seciminiz: ";
    ::cin >> girdi;
    ::cin.ignore(1000, '\n');
    return girdi;
}

Agac* dataSecimi()
{
    cout << " data1.txt icin: [1]" <<::endl;
    cout << " data2.txt icin: [2]" <<::endl;
    cout << " data3.txt icin: [3]" <<::endl;
    Agac *agacim;
    bool gecersizSecim = false;
   
    do{
        gecersizSecim = false;
        char girdi = secimAl(); 
        switch (girdi)
        {
            case '1':
                agacim = agac1;
                break;
            case '2':
                agacim = agac2;
                break;
            case '3':
                agacim = agac3;
                break;
            
            default:
               cout << " Gecersiz secim yapildi. Tekrar deneyiniz.";
                
                gecersizSecim = true;
                break;
        }
    }while(gecersizSecim);

    return agacim;
}

void aramaSecimi()
{
    system("cls || clear");
    

    cout << " Agacta aranacak ogrencinin numarasini giriniz: ";
    char aranacakOgrNo[15];
    ::cin >> aranacakOgrNo;
    ::cin.ignore(1000, '\n');

    Agac *agacim = dataSecimi();

    cout << " ilk derinlik arama yontemi icin: [D]" <<::endl;
    cout << " ilk genislik arama yontemi icin: [B]" <<::endl;
    
    char girdi = secimAl(); 
    bool bulunduMu=false;
    switch (girdi)
    {
        case 'D': case 'd':
            bulunduMu = agacim->ilkDerinlikAra(aranacakOgrNo);
            break;
        case 'B': case 'b':
            bulunduMu = agacim->ilkGenislikAra(aranacakOgrNo);
            break;
        
        default:
           cout << " Gecersiz secim yapildi. Anamenuye aktariliyorsunuz.";
            getchar();
            return;
            break;
    }
    if(!bulunduMu)
        cout << " Aranan ogrenci agacta bulunamadi." <<endl <<endl;
    cout << " Anamenuye donmek icin ENTER basiniz.";
    getchar();
}

void listelemeSecimi()
{
    system("cls || clear");
    
    Agac *agacim = dataSecimi();

   cout << " pre-order  listeleme icin: [R]" <<::endl;
   cout << " in-order   listeleme icin: [I]" <<::endl;
   cout << " post-order listeleme icin: [O]" <<::endl;

    char girdi = secimAl(); 
    switch (girdi)
    {
        case 'R': case 'r':
            agacim->preorderTara(agacim->kok);
            break;
        case 'I': case 'i':
            agacim->inorderTara(agacim->kok);
            break;
        case 'O': case 'o':
            agacim->postorderTara(agacim->kok);
            break;
        
        default:
            cout << " Gecersiz secim yapildi. Anamenuye aktariliyorsunuz.";
            getchar();
            return;
            break;
    }

   cout << " Anamenuye donmek icin ENTER basiniz.";
    getchar();

}

void ogrenciSilmeSecimi()
{
    system("cls || clear");
    Agac *agacim = dataSecimi();

   cout << " Agactan kaldirilacak ogrencinin numarasini giriniz: ";
    char silinecekOgrNo[15];
    ::cin >> silinecekOgrNo;
    ::cin.ignore(1000, '\n');

    agacim->Sil(silinecekOgrNo);
    
   cout << "\n Anamenuye donmek icin ENTER basiniz.";
    getchar();
}

void dosyayaYazdirmaSecimi()
{
    system("cls || clear");
    Agac *agacim = dataSecimi();

    agacim->dosyayaYaz();
   
   cout << "\n Anamenuye donmek icin ENTER basiniz.";
    getchar();
}

void programiKapat()
{
    agac1->Kapat();
    agac2->Kapat();
    agac3->Kapat();

    cout<< " Program bitti kapatmak icin ENTER basiniz." ;
    getchar();
}
/*******************************************************************************/
int main()
{
    bool cikis = false;
    while( !cikis )
    {
        menu_Main();
        char girdi = secimAl();

        switch (girdi)
        {
            case 'A': case 'a':
                aramaSecimi();
                break;
            case 'L': case 'l':
                listelemeSecimi();
                break;
            case 'S': case 's':
                ogrenciSilmeSecimi();
                break;
            case 'Y': case 'y':
                dosyayaYazdirmaSecimi();
                break;
            case 'C': case 'c':
                cikis = true;
                break;
            default:
                cout<< " HATAYLI bir secim yaptiniz. Tekrar denemek icin Lutfen ENTER basiniz." ;
                getchar();
                break;
        }
    }

    programiKapat();
    return EXIT_SUCCESS;
}
/*******************************************************************************/


