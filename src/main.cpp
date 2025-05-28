#include "Labirent.hpp"

int main() {
    // Labirent sýnýfýndan bir nesne oluþturuluyor.
    // Baþlangýç konumu (0, 20), bitiþ konumu (19, 6)
    Labirent *labirent = new Labirent(Konum(0, 20), Konum(19, 6));

    // Ýlk konumu yýðýna (stack) ekliyoruz, ilk hareket yönü "AÞAÐI" olacak.
    labirent->yigit->push(Konum(labirent->x, labirent->y, GUNEY));

    // Baþlangýç konumundan bir adým aþaðýya gidiliyor ve yön "AÞAÐI" olarak ayarlanýyor.
    labirent->ayarla(Konum(labirent->x, labirent->y, GUNEY).Guney(), GUNEY);

    // Labirentin çýkýþýna ulaþana kadar döngü devam eder.
    while (!labirent->CikisaGeldimi()) {
        int denemeYonSayisi = 1; // Denenen yönlerin sayýsý (baþlangýçta 1)
        Konum oncekiKonum = labirent->yigit->top(); // Stack'teki önceki konum
        Konum mevcutKonum = labirent->mevcutKonum(); // Mevcut konum

        // Mevcut yönde bir adým ileri gidilecek konumu hesapla.
        Konum ileri = mevcutKonum.AyniYon();

        // Eðer ileri yönde adým atýlamýyorsa:
        if (!labirent->adimAt(mevcutKonum, ileri)) {
            int i = 0; // Döngü için yön sayacý
            bool sonuc = false; // Adým atma sonucunu kontrol etmek için
            Konum yeni = mevcutKonum; // Yeni konum baþlangýçta mevcut konuma eþit

            // Saat yönünde yön deðiþtirerek hareket etmeye çalýþ
            while (!sonuc && denemeYonSayisi < 5) { 
                yeni = mevcutKonum.SaatYonu((Yon)((mevcutKonum.yon + i) % 4)); 
                // Saat yönünde bir sonraki yön hesaplanýr.

                i++; // Yön deneme sayacý artýrýlýr.
                denemeYonSayisi++; // Deneme yön sayýsý artýrýlýr.

                // Eðer yön ters yönse (geri dönme yönü), o yönde hareket etme.
                if (yeni.yon == mevcutKonum.TersYon()) {
                    sonuc = false; // Adým atýlmaz.
                }
                else {
                    // Yeni yönde adým atmayý dene
                    sonuc = labirent->adimAt(mevcutKonum, yeni);
                }
            }

            // Eðer 4 farklý yön denenip hala ilerleme saðlanamadýysa:
            if (denemeYonSayisi == 5) {
                labirent->yigit->pop(); // Stack'ten önceki konumu sil (geri adým at).
                labirent->ayarla(oncekiKonum, oncekiKonum.TersYon()); 
                // Önceki konuma geri dön ve yönü ters çevir.
            }
        }
    }

    // Labirent çýkýþýna ulaþýldýðýnda mesaj yazdýrýlýr.
    cout << "CIKISA GELDI" << endl;

    getchar(); // Programýn sonlanmasýný bekler.

    // Bellek temizliði: Labirent nesnesini sil.
    delete labirent;
    return 0; // Program baþarýlý þekilde sonlanýr.
}

