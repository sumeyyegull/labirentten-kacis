#ifndef KONUM_HPP  //daha önceden yapýlmýþ mý kontrol ediyor
#define KONUM_HPP

// Yon adýnda bir enum tanýmlanýyor. Hareket yönlerini belirtmek için kullanýlýr.
typedef enum { GUNEY, BATI, KUZEY, DOGU } 
Yon;
//typedef kullanýmý = Enum türünü Yon adýyla tanýmlar.

/* 
   Konum yapýsý (struct) tanýmlanýyor.
   Bu yapý, x ve y koordinatlarýný (satýr ve sütun) ve mevcut yön bilgisini tutar.
*/
struct Konum {
    int x, y;  // Labirentin geniþlik (x) ve yükseklik (y) koordinatlarý
    Yon yon;   // Hareket yönü (ASAGI, SOL, YUKARI, SAG)
    
    // Parametreli Constructor: Koordinatlarý ve yönü alarak Konum nesnesini baþlatýr.
    Konum(int, int, Yon);

    // Parametreli Constructor: Yalnýzca koordinatlarý alýr, varsayýlan yön ASAGI olur.
    Konum(int, int);

    // Varsayýlan Constructor: x=0, y=0 ve yön=ASAGI olarak baþlatýr.
    Konum();

    // Mevcut yön doðrultusunda bir sonraki konumu döner.
    Konum AyniYon();

    // Verilen yöne doðru saat yönünde döner ve yeni konumu döner.
    Konum SaatYonu(Yon);

    // Aþaðý yönde bir adým ilerleyen konumu döner.
    Konum Guney();

    // Yukarý yönde bir adým ilerleyen konumu döner.
    Konum Kuzey();

    // Sol tarafa bir adým ilerleyen konumu döner.
    Konum Dogu();

    // Sað tarafa bir adým ilerleyen konumu döner.
    Konum Bati();

    // Mevcut yönün tam tersi olan yönü döner.
    Yon TersYon();
};

#endif //koruma kontrolunu kapatýr

