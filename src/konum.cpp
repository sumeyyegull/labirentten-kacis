#include "Konum.hpp" // Konum s�n�f�n�n tan�mland��� ba�l�k dosyas� dahil ediliyor.

// Parametreli Constructor: x, y ve y�n (yon) de�erlerini ayarlayan yap�c� fonksiyon
Konum::Konum(int x, int y, Yon yon) : x(x), y(y), yon(yon) {}

// Parametreli Constructor (Y�n belirtilmedi�inde): Varsay�lan y�n "GUNEY" olarak atan�r
Konum::Konum(int x, int y) : x(x), y(y), yon(GUNEY) {}

// Bo� Constructor: Varsay�lan de�erler x=0, y=0 ve yon=GUNEY olarak atan�r
Konum::Konum() : x(0), y(0), yon(GUNEY) {}

// Mevcut y�n do�rultusunda ilerleyen yeni bir konum d�ner
Konum Konum::AyniYon() {
    switch (yon) {
        case KUZEY: return Kuzey();
        case DOGU:  return Dogu();
        case GUNEY: return Guney();
        case BATI:  return Bati();
        default:    return *this; // Ge�ersiz bir y�n durumunda ayn� konumu d�ner
    }
}

// Saat y�n�nde y�n de�i�tirilerek yeni bir konum d�ner
Konum Konum::SaatYonu(Yon yon) {
    switch (yon) {
        case KUZEY: return Dogu();
        case DOGU:  return Guney();
        case GUNEY: return Bati();
        case BATI:  return Kuzey();
        default:    return *this; // Ge�ersiz bir y�n durumunda ayn� konumu d�ner
    }
}

// A�a�� y�nde bir ad�m ilerleyen yeni bir konum d�ner
Konum Konum::Guney() {
    return Konum(x + 1, y, GUNEY);
}

// Yukar� y�nde bir ad�m ilerleyen yeni bir konum d�ner
Konum Konum::Kuzey() {
    return Konum(x - 1, y, KUZEY);
}

// Sol y�nde bir ad�m ilerleyen yeni bir konum d�ner
Konum Konum::Bati() {
    return Konum(x, y - 1, BATI);
}

// Sa� y�nde bir ad�m ilerleyen yeni bir konum d�ner
Konum Konum::Dogu() {
    return Konum(x, y + 1, DOGU);
}

// Ters y�n� d�nd�ren fonksiyon
Yon Konum::TersYon() {
    switch (yon) {
        case KUZEY: return GUNEY;
        case GUNEY: return KUZEY;
        case BATI:  return DOGU;
        case DOGU:  return BATI;
        default:    return GUNEY; // Varsay�lan d�n��: "GUNEY"
    }
}

