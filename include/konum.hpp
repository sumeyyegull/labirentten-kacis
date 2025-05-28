#ifndef KONUM_HPP  //daha �nceden yap�lm�� m� kontrol ediyor
#define KONUM_HPP

// Yon ad�nda bir enum tan�mlan�yor. Hareket y�nlerini belirtmek i�in kullan�l�r.
typedef enum { GUNEY, BATI, KUZEY, DOGU } 
Yon;
//typedef kullan�m� = Enum t�r�n� Yon ad�yla tan�mlar.

/* 
   Konum yap�s� (struct) tan�mlan�yor.
   Bu yap�, x ve y koordinatlar�n� (sat�r ve s�tun) ve mevcut y�n bilgisini tutar.
*/
struct Konum {
    int x, y;  // Labirentin geni�lik (x) ve y�kseklik (y) koordinatlar�
    Yon yon;   // Hareket y�n� (ASAGI, SOL, YUKARI, SAG)
    
    // Parametreli Constructor: Koordinatlar� ve y�n� alarak Konum nesnesini ba�lat�r.
    Konum(int, int, Yon);

    // Parametreli Constructor: Yaln�zca koordinatlar� al�r, varsay�lan y�n ASAGI olur.
    Konum(int, int);

    // Varsay�lan Constructor: x=0, y=0 ve y�n=ASAGI olarak ba�lat�r.
    Konum();

    // Mevcut y�n do�rultusunda bir sonraki konumu d�ner.
    Konum AyniYon();

    // Verilen y�ne do�ru saat y�n�nde d�ner ve yeni konumu d�ner.
    Konum SaatYonu(Yon);

    // A�a�� y�nde bir ad�m ilerleyen konumu d�ner.
    Konum Guney();

    // Yukar� y�nde bir ad�m ilerleyen konumu d�ner.
    Konum Kuzey();

    // Sol tarafa bir ad�m ilerleyen konumu d�ner.
    Konum Dogu();

    // Sa� tarafa bir ad�m ilerleyen konumu d�ner.
    Konum Bati();

    // Mevcut y�n�n tam tersi olan y�n� d�ner.
    Yon TersYon();
};

#endif //koruma kontrolunu kapat�r

