#include "Konum.hpp" // Konum sýnýfýnýn tanýmlandýðý baþlýk dosyasý dahil ediliyor.

// Parametreli Constructor: x, y ve yön (yon) deðerlerini ayarlayan yapýcý fonksiyon
Konum::Konum(int x, int y, Yon yon) : x(x), y(y), yon(yon) {}

// Parametreli Constructor (Yön belirtilmediðinde): Varsayýlan yön "GUNEY" olarak atanýr
Konum::Konum(int x, int y) : x(x), y(y), yon(GUNEY) {}

// Boþ Constructor: Varsayýlan deðerler x=0, y=0 ve yon=GUNEY olarak atanýr
Konum::Konum() : x(0), y(0), yon(GUNEY) {}

// Mevcut yön doðrultusunda ilerleyen yeni bir konum döner
Konum Konum::AyniYon() {
    switch (yon) {
        case KUZEY: return Kuzey();
        case DOGU:  return Dogu();
        case GUNEY: return Guney();
        case BATI:  return Bati();
        default:    return *this; // Geçersiz bir yön durumunda ayný konumu döner
    }
}

// Saat yönünde yön deðiþtirilerek yeni bir konum döner
Konum Konum::SaatYonu(Yon yon) {
    switch (yon) {
        case KUZEY: return Dogu();
        case DOGU:  return Guney();
        case GUNEY: return Bati();
        case BATI:  return Kuzey();
        default:    return *this; // Geçersiz bir yön durumunda ayný konumu döner
    }
}

// Aþaðý yönde bir adým ilerleyen yeni bir konum döner
Konum Konum::Guney() {
    return Konum(x + 1, y, GUNEY);
}

// Yukarý yönde bir adým ilerleyen yeni bir konum döner
Konum Konum::Kuzey() {
    return Konum(x - 1, y, KUZEY);
}

// Sol yönde bir adým ilerleyen yeni bir konum döner
Konum Konum::Bati() {
    return Konum(x, y - 1, BATI);
}

// Sað yönde bir adým ilerleyen yeni bir konum döner
Konum Konum::Dogu() {
    return Konum(x, y + 1, DOGU);
}

// Ters yönü döndüren fonksiyon
Yon Konum::TersYon() {
    switch (yon) {
        case KUZEY: return GUNEY;
        case GUNEY: return KUZEY;
        case BATI:  return DOGU;
        case DOGU:  return BATI;
        default:    return GUNEY; // Varsayýlan dönüþ: "GUNEY"
    }
}

