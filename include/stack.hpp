#ifndef STACK_HPP  
#define STACK_HPP  

#include <stdexcept>  // runtime_error istisna sýnýfý için gerekli kütüphane
#include <iostream>   // Giriþ/çýkýþ iþlemleri için gerekli kütüphane
#include <vector>     // std::vector kullanýmý için gerekli kütüphane
using namespace std;

// Generic (Þablon) Stack Sýnýfý Tanýmý
template <typename Object>
class Stack {
private:
    vector<Object> items;  // Stack verilerini tutmak için std::vector kullanýlýyor

public:
    // Constructor (Kurucu Fonksiyon)
    Stack() {}  // Boþ stack oluþturur, özel bir iþlem yapýlmaz.

    // Stack boþ mu kontrolü
    bool isEmpty() const {
        return items.empty();  // std::vector boþsa 'true' döner, deðilse 'false'
    }

    // Stack'e eleman ekleme (Push)
    void push(const Object& item) {
        items.push_back(item);  // Yeni eleman vektörün sonuna eklenir
    }

    // Stack'ten eleman çýkartma (Pop)
    void pop() {
        if (isEmpty()) {  // Stack boþsa hata fýrlatýr
            throw runtime_error("Stack boþ");
        }
        items.pop_back();  // Vektörün son elemanýný siler
    }

    // Stack'in en üstündeki elemaný döndürme (Top)
    const Object& top() const {
        if (isEmpty()) {  // Stack boþsa hata fýrlatýr
            throw runtime_error("Stack boþ");
        }
        return items.back();  // Vektörün son elemanýný döner (üstteki eleman)
    }

    // Stack'i tamamen temizleme (MakeEmpty)
    void makeEmpty() {
        items.clear();  // Vektör içindeki tüm elemanlarý temizler
    }

    // Destructor (Yýkýcý Fonksiyon)
    ~Stack() {
        makeEmpty();  // Stack'i temizleyerek bellekten silinir
    }
};

#endif  // STACK_HPP

