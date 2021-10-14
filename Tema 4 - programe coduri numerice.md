# 1. Codul 8421

Codurile binar-zecimale se utilizează pentru codificarea cifrelor zecimale. Pentru codificarea fiecăreia din cele 10 cifre, sunt necesari 4 biți; din cele 16 valori posibile, 6 vor fi neutilizate. Codurile utilizate se împart în coduri ponderate și neponderate. În cazul codurilor ponderate, o cifră zecimală este exprimată printr=o combinație de 4 cifre binare, în care fiecărei cifre i se asociază o anumită pondere. Ponderile pot fi pozitive sau negative. Valoarea cifrei zecimale se obține prin suma biților din cod, fiecare bit fiind multiplicat cu valoarea ponderii asociate. În codul 8421, fiecare bit are ponderea numărării in binar, iar cuvintele de cod reprezintă numerele succesive în sistemul binar natural, codul se mai numește cod binar-zecimal natural (NBCD - Natural Binary Coded Decimal). În mod obișnuit, acest cod se numește, impropriu, cod BCD. 

Fie un cod format din biții b0, b1, b2, b3, ponderile acestora fiind p0 = 8, p1 = 4, p2 = 2, p3 = 1, valoarea cifrei zecimale codificate este:
N = p0 x b0 + p1 x b1 + p2 x b2 + p3 x b3;

```cpp
#include <iostream>

void b2(int x, int& i) { // impart numarul de 4 ori la 2 pentru a putea fi reprezentat in codul 8421
                        
    ++i;                // i reprezinta numarul de repetitii ale subprogramului
    if (i > 4) return;  // daca subprogramul s-a repetat de mai mult de 4 ori se opreste

    b2(x / 2, i);       // apelez subprogramul din nou transmitand numarul de repetitii
                        // prin var. i si impartind numarul x la 2 pentru a obtine noul rest

    std::cout << x % 2; // afisez numarul reprezentat in codul 8421 in ordine inversa
}

int main() {
    int x, i = 0;
    std::cout << "8421\n";
    for (x = 0; x < 10; ++x) { // x este numarul care va fi reprezentat in codul 8421
        i = 0;
        b2(x, i);
        std::cout << '\n';
    }
    return 0;
}
```
Rezultatul rulării programului este următorul:

![image](https://user-images.githubusercontent.com/83332450/137374880-5d21fa99-8c37-4c71-b60a-3a5943f43426.png)

# 2. Codul Gray

Codul Gray este un cod digital care acceptă modificarea unui singur bit din cuvântul de  cod,  la  trecerea  dintre  două  cuvinte  de  cod  succesive  (trecerea  de  la  o  cifră zecimală la următoarea cifră zecimală). Această  proprietate  face  ca  acest  cod  să  fie  utilizat  la  dispozitivele  de  codare circulare (diverse traductoare unghiulare de poziţie). Codul  Gray  are  proprietatea  de  adiacenţă, adică trecerea de la o cifră zecimală la următoarea sau precedenta necesită modificarea unui singur bit din cuvântul de cod. Codul Gray este util pentru mărimile care cresc sau descresc succesiv. Codul Gray se obține din codul 8421 astfel:
```
Fie o cifră reprezentată în codul 8421 b4b3b2b1 și o cifră reprezentată în codul Gray g4g3g2g1.
g4 = b4;
g3 = (b4 + b3) % 2;
g2 = (b3 + b2) % 2;
b1 = (b2 + b1) % 2;
```

```cpp
#include <iostream>

int main() {
    int x, i, k, bcd[10][4], gray[10][4]; // bcd si gray sunt matricele in care vor fi stocate numerele de la 0-9 in codul 8421 respectiv gray
    //8421
    for (x = 0; x < 10; ++x) {            // x este numarul care va fi transformat in codul 8421
        i = 3;                            // i va fi pozitia bitului si este 3 deoarece codul se citeste in ordine inversa in urma calculului
        k = x;                            // stochez valoarea lui x in variabila k pentru a o folosi mai tarziu

        while (i >= 0) {
            bcd[x][i] = k % 2;           // al (i + 1)-lea bit din reprezentarea cifrei x in codul 8421 ia valoarea k % 2;
            k /= 2;                      // il impart pe k la 2 pentru urmatoarea operatie
            --i;                         // trec la bitul urmator
        }
    }
    x = 0;                               // pornesc de la cifra 0
    while (x < 10) {                     // ma opresc la cifra 9
        /*
         a8-a4-a2-a1 cod 8421
         b4 b3 b2 b1 cod gray
         formula gray:
         b4 = a8
         b3 = a4 + a8
         b2 = a2 + a4
         b1 = a1 + a2
         */
        gray[x][0] = bcd[x][0];         // copiez prima cifra din 8421 conform formulei

        for (i = 1; i < 4; ++i)         // pornesc de la al 2-lea bit din
            gray[x][i] = (bcd[x][i] + bcd[x][i-1]) % 2; // conform formulei, dupa ce am copiat primul bit din codul 8421, urmatorul bit = bitul de pe
                                                        // aceeasi pozitie in 8421 adunat cu bitul de pe pozitia precedenta in 8421 in baza 2
                                                        
        ++x;                            // trec la urmatorul numar
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
```

Rezultatul rulării programului:

![image](https://user-images.githubusercontent.com/83332450/137377517-c210870c-5b79-4462-b76b-e761f87a990e.png)

# Bibliografie
https://www.creeaza.com/referate/informatica/CODURI-BINARZECIMALE853.php *Coduri binar-zecimale*  
https://eprofu.ro/docs/electronica/digitala/04codare.pdf *Codul Gray* (pg 7-8)
