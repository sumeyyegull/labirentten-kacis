#ifndef LABIRENT_HPP
#define LABIRENT_HPP

#include <fstream>     // Dosya i�lemleri i�in gerekli k�t�phane
#include <iomanip>     // Ekran ��kt�s�n� hizalamak i�in gerekli
#include "Windows.h"   // Windows platformuna �zel i�lemler (�rne�in, Sleep)
#include <sstream>     // String olu�turma ve i�leme i�in gerekli k�t�phane

#include "Konum.hpp"   // Konum s�n�f�n� dahil eder
#include "Stack.hpp"   // Stack s�n�f�n� dahil eder
#define YUKSEKLIK 20   // Haritan�n y�ksekli�i: 20 sat�r
#define GENISLIK 50    // Haritan�n geni�li�i: 50 s�tun

// Labirent s�n�f�n�n tan�m�
class Labirent {
    public:
        char harita[YUKSEKLIK][GENISLIK];  // Labirentin haritas�n� tutan 2 boyutlu dizi
        int x, y;  // Mevcut konumun sat�r (x) ve s�tun (y) koordinatlar�
        Yon yon;   // Mevcut hareket y�n� (A�a��, Yukar�, Sa�, Sol)
        Konum bitis;  // Labirentin ��k�� (biti�) noktas�
        Stack<Konum> *yigit;  // Konumlar� tutmak i�in kullan�lan Stack yap�s�
        
        // Constructor: Labirent nesnesini ba�lat�r, ba�lang�� ve biti� konumlar�n� al�r
        Labirent(Konum, Konum);
        
        // Mevcut konumu d�ner
        Konum mevcutKonum();
        
        // Belirli bir konuma ad�m atmaya �al���r, ba�ar�l�ysa true d�ner
        bool adimAt(Konum, Konum);
        
        // Labirentte yeni konumu ve y�n� ayarlar, haritay� g�nceller
        void ayarla(Konum, Yon);
        
        // ��k��a ula��l�p ula��lmad���n� kontrol eder
        bool CikisaGeldimi();
        
        // Belirtilen konumda engel olup olmad���n� kontrol eder
        bool EngelVarmi(Konum);
        
        // Haritay� string olarak d�ner (labirenti ekrana yazd�rmak i�in kullan�l�r)
        string yaz();
};

#endif

