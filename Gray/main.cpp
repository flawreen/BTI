#include <iostream>

int main() {
    int x, i, k, bcd[10][4], gray[10][4]; // bcd si gray sunt matricele in care vor fi stocate numerele de la 0-9 in codul 8421 respectiv gray
    //8421
    for (x = 0; x < 10; ++x) { // x este numarul care va fi transformat in codul 8421
        i = 3; // i va fi pozitia bitului si este 3 deoarece codul se citeste in ordine inversa in urma calculului
        k = x; // stochez valoarea lui x in variabila k pentru a o folosi mai tarziu

        while (i >= 0) {
            bcd[x][i] = k % 2; // a (i + 1)-lea bit din reprezentarea cifrei x in codul 8421 ia valoarea k % 2;
            k /= 2; // il impart pe k la 2 pentru urmatoarea operatie
            --i; // trec la bitul urmator
        }
    }
    x = 0; // pornesc de la cifra 0
    while (x < 10) { // ma opresc la cifra 9
        /*
         a8-a4-a2-a1 cod 8421
         b4 b3 b2 b1 cod gray
         formula gray:
         b4 = a8
         b3 = a4 + a8
         b2 = a2 + a4
         b1 = a1 + a2
         */
        gray[x][0] = bcd[x][0]; // copiez prima cifra din 8421 conform formulei

        for (i = 1; i < 4; ++i) // pornesc de la al 2-lea bit din
            gray[x][i] = (bcd[x][i] + bcd[x][i-1]) % 2; // conform formulei, dupa ce am copiat primul bit din codul 8421, urmatorul bit = bitul de pe
                                                        // aceeasi pozitie in 8421 adunat cu bitul de pe pozitia precedenta in 8421 in baza 2
        ++x; // trec la urmatorul numar
    }
    //gray
    x = 0;
    std::cout << "Nr | 8421 | Gray\n";
    while (x < 10) {
        std::cout << x << "  | ";
        for (i = 0; i < 4; ++i) std::cout << bcd[x][i]; // afisez cifra cu valoarea x in 8421
        std::cout << " | ";
        for (i = 0; i < 4; ++i) std::cout << gray[x][i]; // afisez cifra cu valoarea x in gray
        std::cout << '\n';
        ++x;
    }
    return 0;
}






































