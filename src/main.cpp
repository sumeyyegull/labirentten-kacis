#include "Labirent.hpp"

int main() {
    // Labirent s�n�f�ndan bir nesne olu�turuluyor.
    // Ba�lang�� konumu (0, 20), biti� konumu (19, 6)
    Labirent *labirent = new Labirent(Konum(0, 20), Konum(19, 6));

    // �lk konumu y���na (stack) ekliyoruz, ilk hareket y�n� "A�A�I" olacak.
    labirent->yigit->push(Konum(labirent->x, labirent->y, GUNEY));

    // Ba�lang�� konumundan bir ad�m a�a��ya gidiliyor ve y�n "A�A�I" olarak ayarlan�yor.
    labirent->ayarla(Konum(labirent->x, labirent->y, GUNEY).Guney(), GUNEY);

    // Labirentin ��k���na ula�ana kadar d�ng� devam eder.
    while (!labirent->CikisaGeldimi()) {
        int denemeYonSayisi = 1; // Denenen y�nlerin say�s� (ba�lang��ta 1)
        Konum oncekiKonum = labirent->yigit->top(); // Stack'teki �nceki konum
        Konum mevcutKonum = labirent->mevcutKonum(); // Mevcut konum

        // Mevcut y�nde bir ad�m ileri gidilecek konumu hesapla.
        Konum ileri = mevcutKonum.AyniYon();

        // E�er ileri y�nde ad�m at�lam�yorsa:
        if (!labirent->adimAt(mevcutKonum, ileri)) {
            int i = 0; // D�ng� i�in y�n sayac�
            bool sonuc = false; // Ad�m atma sonucunu kontrol etmek i�in
            Konum yeni = mevcutKonum; // Yeni konum ba�lang��ta mevcut konuma e�it

            // Saat y�n�nde y�n de�i�tirerek hareket etmeye �al��
            while (!sonuc && denemeYonSayisi < 5) { 
                yeni = mevcutKonum.SaatYonu((Yon)((mevcutKonum.yon + i) % 4)); 
                // Saat y�n�nde bir sonraki y�n hesaplan�r.

                i++; // Y�n deneme sayac� art�r�l�r.
                denemeYonSayisi++; // Deneme y�n say�s� art�r�l�r.

                // E�er y�n ters y�nse (geri d�nme y�n�), o y�nde hareket etme.
                if (yeni.yon == mevcutKonum.TersYon()) {
                    sonuc = false; // Ad�m at�lmaz.
                }
                else {
                    // Yeni y�nde ad�m atmay� dene
                    sonuc = labirent->adimAt(mevcutKonum, yeni);
                }
            }

            // E�er 4 farkl� y�n denenip hala ilerleme sa�lanamad�ysa:
            if (denemeYonSayisi == 5) {
                labirent->yigit->pop(); // Stack'ten �nceki konumu sil (geri ad�m at).
                labirent->ayarla(oncekiKonum, oncekiKonum.TersYon()); 
                // �nceki konuma geri d�n ve y�n� ters �evir.
            }
        }
    }

    // Labirent ��k���na ula��ld���nda mesaj yazd�r�l�r.
    cout << "CIKISA GELDI" << endl;

    getchar(); // Program�n sonlanmas�n� bekler.

    // Bellek temizli�i: Labirent nesnesini sil.
    delete labirent;
    return 0; // Program ba�ar�l� �ekilde�sonlan�r.
}

