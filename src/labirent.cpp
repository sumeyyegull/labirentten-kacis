#include "Labirent.hpp"

// Constructor (Kurucu Fonksiyon): Labirenti baþlatýr.
Labirent::Labirent(Konum baslangic, Konum bitis){
    FILE* fp = fopen("Harita.txt", "r");  // Harita.txt dosyasýný okumak için açar.
      if (!fp) {
        cerr << "Harita dosyasý açýlamadý!" << endl;
        exit(EXIT_FAILURE); // Dosya açýlamazsa program sonlandýrýlýr.
    }
    
    unsigned char karakter = 0;
    int satir = 0, sutun = 0;

    x = baslangic.x;  // Baþlangýç konumu x'e atanýr.
    y = baslangic.y;  // Baþlangýç konumu y'ye atanýr.
    this->bitis = bitis;  // Bitiþ konumu `bitis` nesnesi olarak ayarlanýr.
    yon = GUNEY;  // Baþlangýç yönü aþaðý (`ASAGI`) olarak atanýr.
    yigit = new Stack<Konum>();  // Yeni bir yýðýn nesnesi oluþturulur.
    yigit->push(Konum(-1, -1, yon));  // Yýðýna baþlangýç konumu eklenir.

    // Harita.txt dosyasýndan karakterleri okuyarak harita oluþturur.
    while (true) { //döngü devam edene kadar calýssýn demek
        karakter = getc(fp); //dosyadan bir karakter okuyor
        if (karakter == 255) break;  // Dosyanýn sonuna ulaþýlýrsa döngü kýrýlýr.
        if (karakter == '\n') {  // Satýr sonuna gelinirse satýrý artýrýr. Burada 'n', ASCII deðeri olan 10 karþýlýðýdýr.

            satir++;
            sutun = 0;
        }
        else {
            harita[satir][sutun] = karakter;  // Haritadaki satýr ve sütunlara karakteri yerleþtirir.
            sutun++;
        }
    }
     fclose(fp); // Dosya kapatýlýr.
}

// Mevcut konumu döndüren fonksiyon
Konum Labirent::mevcutKonum() {
    return Konum(x, y, yon);  // Þu anki konumu (`x`, `y`, `yon`) döndürür.
}

// Adým atma iþlemi: Eðer hedefte engel yoksa adým atýlýr.
bool Labirent::adimAt(Konum mevcut, Konum ileri) {
    if (!EngelVarmi(ileri)) {
        yigit->push(mevcut);  // Mevcut konumu yýðýna ekler.
        ayarla(ileri, ileri.yon);  // Yeni konuma gitmek için yönü ayarlar.
        return true;
    }
    return false;  // Eðer engel varsa adým atamaz.
}

// Haritada konumu ve yönü ayarlama iþlemi
void Labirent::ayarla(Konum konum, Yon yon) {
    system("cls");  // Konsolu temizler.

    this->x = konum.x;  // Yeni konumu x'e atanýr.
    this->y = konum.y;  // Yeni konumu y'e atanýr.
    this->yon = yon;   // Yeni yön atanýr.

    harita[konum.x][konum.y] = '-';  // Yeni konumu haritada boþ olarak temsil eder.
    cout << yaz();  // Güncellenmiþ harita çýktýsýný ekrana yazdýrýr.Böylece, karakterin hareketi anlýk olarak konsolda takip edilebilir.


    Sleep(100);  // 100 milisaniye bekler.
}

// Çýkýþa ulaþma kontrolü: Eðer konum bitiþle eþleþiyorsa çýkýþ saðlanýr.
bool Labirent::CikisaGeldimi() {
    return x == bitis.x && y == bitis.y;  // Mevcut konum bitiþ noktasýna eþleþiyorsa true döndürür.
}

// Engel kontrolü: Haritadaki engel olup olmadýðýný kontrol eder.
bool Labirent::EngelVarmi(Konum konum) {
    if (konum.x >= YUKSEKLIK || konum.x < 0 || konum.y >= GENISLIK || konum.y < 0)
        return false;  // Eðer konum labirentin sýnýrlarý dýþýnda ise false döndürür.

    return harita[konum.x][konum.y] == '#' || harita[konum.x][konum.y] == '-';  // Engel kontrolü.
}

string Labirent::yaz() {
	// YonChr dizisinin tanýmlanmasý
	char YonChr[] = {'v', '<', '^', '>'};  //yukarý,sag,asagý,sol yön karakterlerini temsil eder

    string haritaStr = "";  // Harita çýktýsýný tutacak bir string oluþturuyoruz.
    
    for (int satir = 0; satir < YUKSEKLIK; satir++) {
        for (int sutun = 0; sutun < GENISLIK; sutun++) {
            if (satir == x && sutun == y) {
                // Eðer bu konumda isek, yön karakterini ekleriz
                haritaStr += YonChr[yon];
            } else if (harita[satir][sutun] == '-') {
                // Eðer harita boþsa, bir boþluk ekleriz
                haritaStr += ' ';
            } else {
                // Diðer durumlar için, harita karakterini ekleriz
                haritaStr += harita[satir][sutun];
            }
        }
        
        // Her satýr sonunda yeni bir satýra geçeriz
        haritaStr += "\n";
    }

    return haritaStr;  // Sonuç olarak haritayý döndürürüz
}

