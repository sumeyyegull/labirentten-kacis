#include "Labirent.hpp"

// Constructor (Kurucu Fonksiyon): Labirenti ba�lat�r.
Labirent::Labirent(Konum baslangic, Konum bitis){
    FILE* fp = fopen("Harita.txt", "r");  // Harita.txt dosyas�n� okumak i�in a�ar.
      if (!fp) {
        cerr << "Harita dosyas� a��lamad�!" << endl;
        exit(EXIT_FAILURE); // Dosya a��lamazsa program sonland�r�l�r.
    }
    
    unsigned char karakter = 0;
    int satir = 0, sutun = 0;

    x = baslangic.x;  // Ba�lang�� konumu x'e atan�r.
    y = baslangic.y;  // Ba�lang�� konumu y'ye atan�r.
    this->bitis = bitis;  // Biti� konumu `bitis` nesnesi olarak ayarlan�r.
    yon = GUNEY;  // Ba�lang�� y�n� a�a�� (`ASAGI`) olarak atan�r.
    yigit = new Stack<Konum>();  // Yeni bir y���n nesnesi olu�turulur.
    yigit->push(Konum(-1, -1, yon));  // Y���na ba�lang�� konumu eklenir.

    // Harita.txt dosyas�ndan karakterleri okuyarak harita olu�turur.
    while (true) { //d�ng� devam edene kadar cal�ss�n demek
        karakter = getc(fp); //dosyadan bir karakter okuyor
        if (karakter == 255) break;  // Dosyan�n sonuna ula��l�rsa d�ng� k�r�l�r.
        if (karakter == '\n') {  // Sat�r sonuna gelinirse sat�r� art�r�r. Burada 'n', ASCII de�eri olan 10 kar��l���d�r.

            satir++;
            sutun = 0;
        }
        else {
            harita[satir][sutun] = karakter;  // Haritadaki sat�r ve s�tunlara karakteri yerle�tirir.
            sutun++;
        }
    }
     fclose(fp); // Dosya kapat�l�r.
}

// Mevcut konumu d�nd�ren fonksiyon
Konum Labirent::mevcutKonum() {
    return Konum(x, y, yon);  // �u anki konumu (`x`, `y`, `yon`) d�nd�r�r.
}

// Ad�m atma i�lemi: E�er hedefte engel yoksa ad�m at�l�r.
bool Labirent::adimAt(Konum mevcut, Konum ileri) {
    if (!EngelVarmi(ileri)) {
        yigit->push(mevcut);  // Mevcut konumu y���na ekler.
        ayarla(ileri, ileri.yon);  // Yeni konuma gitmek i�in y�n� ayarlar.
        return true;
    }
    return false;  // E�er engel varsa ad�m atamaz.
}

// Haritada konumu ve y�n� ayarlama i�lemi
void Labirent::ayarla(Konum konum, Yon yon) {
    system("cls");  // Konsolu temizler.

    this->x = konum.x;  // Yeni konumu x'e atan�r.
    this->y = konum.y;  // Yeni konumu y'e atan�r.
    this->yon = yon;   // Yeni y�n atan�r.

    harita[konum.x][konum.y] = '-';  // Yeni konumu haritada bo� olarak temsil eder.
    cout << yaz();  // G�ncellenmi� harita ��kt�s�n� ekrana yazd�r�r.B�ylece, karakterin hareketi anl�k olarak konsolda takip edilebilir.


    Sleep(100);  // 100 milisaniye bekler.
}

// ��k��a ula�ma kontrol�: E�er konum biti�le e�le�iyorsa ��k�� sa�lan�r.
bool Labirent::CikisaGeldimi() {
    return x == bitis.x && y == bitis.y;  // Mevcut konum biti� noktas�na e�le�iyorsa true d�nd�r�r.
}

// Engel kontrol�: Haritadaki engel olup olmad���n� kontrol eder.
bool Labirent::EngelVarmi(Konum konum) {
    if (konum.x >= YUKSEKLIK || konum.x < 0 || konum.y >= GENISLIK || konum.y < 0)
        return false;  // E�er konum labirentin s�n�rlar� d���nda ise false d�nd�r�r.

    return harita[konum.x][konum.y] == '#' || harita[konum.x][konum.y] == '-';  // Engel kontrol�.
}

string Labirent::yaz() {
	// YonChr dizisinin tan�mlanmas�
	char YonChr[] = {'v', '<', '^', '>'};  //yukar�,sag,asag�,sol y�n karakterlerini temsil eder

    string haritaStr = "";  // Harita ��kt�s�n� tutacak bir string olu�turuyoruz.
    
    for (int satir = 0; satir < YUKSEKLIK; satir++) {
        for (int sutun = 0; sutun < GENISLIK; sutun++) {
            if (satir == x && sutun == y) {
                // E�er bu konumda isek, y�n karakterini ekleriz
                haritaStr += YonChr[yon];
            } else if (harita[satir][sutun] == '-') {
                // E�er harita bo�sa, bir bo�luk ekleriz
                haritaStr += ' ';
            } else {
                // Di�er durumlar i�in, harita karakterini ekleriz
                haritaStr += harita[satir][sutun];
            }
        }
        
        // Her sat�r sonunda yeni bir sat�ra ge�eriz
        haritaStr += "\n";
    }

    return haritaStr;  // Sonu� olarak haritay��d�nd�r�r�z
}

