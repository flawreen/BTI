1. Codul 8421

Codurile binar-zecimale se utilizează pentru codificarea cifrelor zecimale. Pentru codificarea fiecăreia din cele 10 cifre, sunt necesari 4 biți; din cele 16 valori posibile, 6 vor fi neutilizate. Codurile utilizate se împart în coduri ponderate și neponderate. În cazul codurilor ponderate, o cifră zecimală este exprimată printr=o combinație de 4 cifre binare, în care fiecărei cifre i se asociază o anumită pondere. Ponderile pot fi pozitive sau negative. Valoarea cifrei zecimale se obține prin suma biților din cod, fiecare bit fiind multiplicat cu valoarea ponderii asociate. În codul 8421, fiecare bit are ponderea numărării in binar, iar cuvintele de cod reprezintă numerele succesive în sistemul binar natural, codul se mai numește cod binar-zecimal natural (NBCD - Natural Binary Coded Decimal). În mod obișnuit, acest cod se numește, impropriu, cod BCD. 

Fie un cod format din biții b0, b1, b2, b3, ponderile acestora fiind p0 = 8, p1 = 4, p2 = 2, p3 = 1, valoarea cifrei zecimale codificate este:
N = p0*b0 + p1*b1 + p2*b2 + p3*b3;

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

![image](https://user-images.githubusercontent.com/83332450/137370061-ad263871-bc46-4770-b602-a1205edb435b.png)


