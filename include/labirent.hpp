#ifndef LABIRENT_HPP
#define LABIRENT_HPP

#include <fstream>     // Dosya iþlemleri için gerekli kütüphane
#include <iomanip>     // Ekran çýktýsýný hizalamak için gerekli
#include "Windows.h"   // Windows platformuna özel iþlemler (örneðin, Sleep)
#include <sstream>     // String oluþturma ve iþleme için gerekli kütüphane

#include "Konum.hpp"   // Konum sýnýfýný dahil eder
#include "Stack.hpp"   // Stack sýnýfýný dahil eder
#define YUKSEKLIK 20   // Haritanýn yüksekliði: 20 satýr
#define GENISLIK 50    // Haritanýn geniþliði: 50 sütun

// Labirent sýnýfýnýn tanýmý
class Labirent {
    public:
        char harita[YUKSEKLIK][GENISLIK];  // Labirentin haritasýný tutan 2 boyutlu dizi
        int x, y;  // Mevcut konumun satýr (x) ve sütun (y) koordinatlarý
        Yon yon;   // Mevcut hareket yönü (Aþaðý, Yukarý, Sað, Sol)
        Konum bitis;  // Labirentin çýkýþ (bitiþ) noktasý
        Stack<Konum> *yigit;  // Konumlarý tutmak için kullanýlan Stack yapýsý
        
        // Constructor: Labirent nesnesini baþlatýr, baþlangýç ve bitiþ konumlarýný alýr
        Labirent(Konum, Konum);
        
        // Mevcut konumu döner
        Konum mevcutKonum();
        
        // Belirli bir konuma adým atmaya çalýþýr, baþarýlýysa true döner
        bool adimAt(Konum, Konum);
        
        // Labirentte yeni konumu ve yönü ayarlar, haritayý günceller
        void ayarla(Konum, Yon);
        
        // Çýkýþa ulaþýlýp ulaþýlmadýðýný kontrol eder
        bool CikisaGeldimi();
        
        // Belirtilen konumda engel olup olmadýðýný kontrol eder
        bool EngelVarmi(Konum);
        
        // Haritayý string olarak döner (labirenti ekrana yazdýrmak için kullanýlýr)
        string yaz();
};

#endif

