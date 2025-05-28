#ifndef STACK_HPP  
#define STACK_HPP  

#include <stdexcept>  // runtime_error istisna s�n�f� i�in gerekli k�t�phane
#include <iostream>   // Giri�/��k�� i�lemleri i�in gerekli k�t�phane
#include <vector>     // std::vector kullan�m� i�in gerekli k�t�phane
using namespace std;

// Generic (�ablon) Stack S�n�f� Tan�m�
template <typename Object>
class Stack {
private:
    vector<Object> items;  // Stack verilerini tutmak i�in std::vector kullan�l�yor

public:
    // Constructor (Kurucu Fonksiyon)
    Stack() {}  // Bo� stack olu�turur, �zel bir i�lem yap�lmaz.

    // Stack bo� mu kontrol�
    bool isEmpty() const {
        return items.empty();  // std::vector bo�sa 'true' d�ner, de�ilse 'false'
    }

    // Stack'e eleman ekleme (Push)
    void push(const Object& item) {
        items.push_back(item);  // Yeni eleman vekt�r�n sonuna eklenir
    }

    // Stack'ten eleman ��kartma (Pop)
    void pop() {
        if (isEmpty()) {  // Stack bo�sa hata f�rlat�r
            throw runtime_error("Stack bo�");
        }
        items.pop_back();  // Vekt�r�n son eleman�n� siler
    }

    // Stack'in en �st�ndeki eleman� d�nd�rme (Top)
    const Object& top() const {
        if (isEmpty()) {  // Stack bo�sa hata f�rlat�r
            throw runtime_error("Stack bo�");
        }
        return items.back();  // Vekt�r�n son eleman�n� d�ner (�stteki eleman)
    }

    // Stack'i tamamen temizleme (MakeEmpty)
    void makeEmpty() {
        items.clear();  // Vekt�r i�indeki t�m elemanlar� temizler
    }

    // Destructor (Y�k�c� Fonksiyon)
    ~Stack() {
        makeEmpty();  // Stack'i temizleyerek bellekten silinir
    }
};

#endif��//�STACK_HPP

