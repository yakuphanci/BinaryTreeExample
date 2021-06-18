#include<iostream>
#include<fstream>
#include<string.h>


#include <stack>
#include <queue>



struct ogrenci_dugum{ 
    char ogrno[15]; 
    char ad[30] ; 
    char soyad[30]; 
    ogrenci_dugum *sol; 
    ogrenci_dugum *sag; 

    ogrenci_dugum()
    {
        sol = NULL;
        sag = NULL;
    }
};

struct Agac{
    ogrenci_dugum *kok;
    int dugumSayisi;
    char *dosyaAdi;
  
    Agac(char* _dosyaAdi)
    {
        kok = NULL;
        dugumSayisi = 0;
        dosyaAdi = _dosyaAdi;
        dosyadanOku();
    }           

    void Bosalt(ogrenci_dugum *p); //Agac Bosalt
    void Kapat(); //Agaci dosyaya kayedip bellegi bosaltir..
    
    void Ekle(ogrenci_dugum *eklenecekOgrenci); //Agaca ogrenci verisi ekler.
    
    void Sil(char *ogrenciNum);  //ogrenci numarasi eslesen ogrenciyi agactan siler.
    void Sil(ogrenci_dugum **p);

    void inorderTara(ogrenci_dugum *p);
    void preorderTara(ogrenci_dugum *p);
    void postorderTara(ogrenci_dugum *p);

    bool ilkDerinlikAra(char *ogrenciNum);
    bool ilkGenislikAra(char *ogrenciNum);

    void dosyadanOku();

    void preorderYaz(ogrenci_dugum *p, std::ofstream *dosya);
    void dosyayaYaz();

};

void Agac::Bosalt(ogrenci_dugum  *p){
    if(p)
    {
        if (p ->sol != NULL)
        {
            Bosalt (p->sol);
            p->sol = NULL;
        }
        if (p->sag != NULL)
        {
            Bosalt (p->sag);
            p->sag = NULL;
        }
        delete p;
    }
}

void Agac::Kapat()
{
    dosyayaYaz();
    Bosalt(kok);
}

void Agac::preorderYaz(ogrenci_dugum *p, std::ofstream *dosya)
{
    if (p)
    {
        *dosya << p->ogrno << "\t" << p->ad << " " << p->soyad <<std::endl; 
        preorderYaz(p->sol, dosya);
        preorderYaz(p->sag, dosya);
    }
}

void Agac::dosyayaYaz()
{
    std::ofstream *dosya = new std::ofstream();

    char outputPath[30] = "output_";
    strcat(outputPath, dosyaAdi);

    dosya->open(outputPath);
    preorderYaz(kok, dosya);
    dosya->close();

    std::cout << " Dosyaya yazma islemi tamam. -" <<outputPath <<"-" <<std::endl;
}

void Agac::preorderTara (ogrenci_dugum *p){
    if (p){
        std::cout << " " << p->ogrno  << "\t" << p->ad << " - " << p->soyad << std::endl;
        preorderTara(p->sol);
        preorderTara (p->sag);
    }
}

void Agac::inorderTara (ogrenci_dugum *p){
    if (p){
        inorderTara(p->sol);
       std::cout << " " << p->ogrno  << "\t" << p->ad << " - " << p->soyad <<std::endl;
        inorderTara (p->sag);
    }
}

void Agac::postorderTara (ogrenci_dugum *p){
    if (p){
        postorderTara(p->sol);
        postorderTara (p->sag);
       std::cout << " " << p->ogrno  << "\t" << p->ad << " - " << p->soyad <<std::endl;
    }
}


void Agac::Ekle(ogrenci_dugum *eklenecekOgrenci)
{
    ogrenci_dugum *gezgin, *yeniOgrenci;
    gezgin = kok;

   
    bool eklendi = false;

    yeniOgrenci = new ogrenci_dugum();
    strcpy(yeniOgrenci->ogrno, eklenecekOgrenci->ogrno);
    strcpy(yeniOgrenci->ad,eklenecekOgrenci->ad);
    strcpy(yeniOgrenci->soyad,eklenecekOgrenci->soyad);

    //ilk dugum ekleniyor.
    if(kok == NULL)
    {
        kok = yeniOgrenci;
        dugumSayisi++;
        return;
    }

    //ilk dugum disinda kayit ekleniyor.
    while(gezgin && !eklendi)
    {
        int karsilas = strcmp(yeniOgrenci->ogrno, gezgin->ogrno);
       
        //ogrenci numarasi kokten kucukse
        if(karsilas < 0 )
        {
            if(gezgin->sol != NULL)
            {
                gezgin = gezgin->sol;
            }
            else
            {
                gezgin->sol = yeniOgrenci;
                eklendi = true;
            }
        }
        
        //ogrenci numarasi kokten buyukse
        else if(karsilas > 0)
        {
            if(gezgin->sag != NULL)
            {
                gezgin = gezgin->sag;
            }
            else
            {
                gezgin->sag = yeniOgrenci;
                eklendi = true;
            }
        }
        //ogrenci numarasi koke esitse -zaten ekliyse-
        else
        {
           std::cout << "Islem gerceklesmedi. Veri tekrari olamaz." <<std::endl;
            break;
        } 
    }

    if(eklendi)
        dugumSayisi++;
    
}


void Agac::Sil(ogrenci_dugum **p)
{
    ogrenci_dugum *r, *q;
    r = *p;
    if(r == NULL)
        return;
    else if(r->sag == NULL)
        *p = r->sol;
    else if(r->sol == NULL)
        *p = r->sag;
    
    else 
    {
        for(q = r ->sag; q->sol; q = q->sol);
        q->sol = r->sol;
        *p = r->sag;
    }
    delete r;
}

void Agac::Sil(char *ogrenciNum)
{
    int islemSayisi = 0;
    ogrenci_dugum *gezgin, *ust;
    gezgin = kok;
    bool bulundu = false;
    char yon='k';
    
    while(gezgin && !bulundu)
    {
        islemSayisi++;
        int karsilas = strcmp(ogrenciNum, gezgin->ogrno);

        if(karsilas < 0)
        {
            ust = gezgin;
            yon = 'l';
            gezgin = gezgin->sol;
        }
        else if (karsilas > 0)
        {
            ust = gezgin;
            yon = 'r';
            gezgin = gezgin->sag;
        }
        //silinecek kayit bulundu.
        else
            bulundu = true;
    }

    if(bulundu)
    {
        if(yon == 'l')
            Sil(&ust->sol);
        else if(yon == 'r')
            Sil(&ust->sag);
        else
            Sil(&kok);
        
        std::cout << "Kayit silindi." <<std::endl;
    }
    else
       std::cout << "Silinecek kayit bulunamadi." <<std::endl;

     std::cout << "\n Bakinilan veri adeti: " << islemSayisi << " tanedir.";
    
}

void Agac::dosyadanOku()
{
    char ogrno[15],ad[30],soyad[30];
    char satirAl[75];  
    char *ptr;
    std::ifstream dosya(dosyaAdi);

    dosya.getline(satirAl, 75);
    for(int i = 0; i<75; i++)
    {
        //satır sonundaki '\r' karakterini, '\0' karakteri ile değiştirme
        if(satirAl[i] == '\r')
            satirAl[i] = '\0';
    }


    ogrenci_dugum *yeniOgrenci = new ogrenci_dugum();
    while(dosya){
        ptr = strtok(satirAl, "\t");

        int j = 0;
        while(ptr)
        {
            if(j==0)
                strcpy(ogrno, ptr);
            else if(j == 1)
                strcpy(ad, ptr);
            else if(j == 2)
                strcpy(soyad, ptr);
            else 
            {
                strcat(ad, " ");
                strcat(ad, soyad);
                strcpy(soyad, ptr);
            }

            ptr = strtok(NULL," ");
            j++;
        }

        strcpy(yeniOgrenci->ogrno, ogrno);
        strcpy(yeniOgrenci->ad, ad);
        strcpy(yeniOgrenci->soyad, soyad);

        Ekle(yeniOgrenci);

       // printf(" %s - %s %s \n", yeniOgrenci->ogrno, yeniOgrenci->ad, yeniOgrenci->soyad);

        dosya.getline(satirAl, 75);
        for(int i = 0; i<75; i++)
        {
            //satır sonundaki '\r' karakterini, '\0' karakteri ile değiştirme
            if(satirAl[i] == '\r')
                satirAl[i] = '\0';
        }
    }

    dosya.close();

}

bool Agac::ilkDerinlikAra(char *ogrenciNum)
{
     bool bulunduMu = false;
    int islemAdet = 0;
    ogrenci_dugum *p;
    std::stack< ogrenci_dugum* > yigin; //yigin veri yapisi tanimlandi
    yigin.push( kok ); //
    while(!yigin.empty())
    {   
        islemAdet++;
        p = yigin.top();
        yigin.pop();

        if(strcmp(ogrenciNum, p->ogrno) == 0)
        {
           std::cout << p->ogrno << "\t" << p->ad << " - " << p->soyad <<std::endl;
            bulunduMu= true;
            break;
        }
        if(p->sag)
            yigin.push(p->sag);
        if(p->sol)
            yigin.push(p->sol);

    }
    std::cout << "\n Bakinilan veri adeti: " << islemAdet << " tanedir.";
    return bulunduMu;
}

bool Agac::ilkGenislikAra(char *ogrenciNum)
{
    bool bulunduMu = false;
    int islemAdet = 0;
    ogrenci_dugum *p;
    std::queue<ogrenci_dugum*> kuyruk;
    kuyruk.push(kok);
    while(!kuyruk.empty())
    {
        islemAdet++;
        p = kuyruk.front();
        kuyruk.pop();

        if(strcmp(ogrenciNum, p->ogrno) == 0)
        {
           std::cout << p->ogrno << "\t" << p->ad << " - " << p->soyad <<std::endl;
            bulunduMu = true;
            break;
        }
        if(p->sol)
            kuyruk.push(p->sol);
        if(p->sag)
            kuyruk.push(p->sag);
    }
   std::cout << "\n Bakinilan veri adeti: " << islemAdet << " tanedir.";
    return bulunduMu;
}
