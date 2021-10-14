#include <iostream>

void b2(int x, int& i) { // acest subprogram este asemanator celui transformarii unui numar in baza 2 din baza 10,
    // insa il impart de 3 ori la 2 chiar daca catul va da 0 intre timp
    // pentru a-l putea reprezenta apoi prin inmultirea bitilor cu puterile lui 2 (b8 * 8 + b4 * 4 + b2 * 2 + b1 * 1)
    ++i; // i reprezinta numarul de repetitii ale subprogramului
    if (i > 4) return; // daca programul s-a repetat de mai mult de 4 ori se opreste

    b2(x / 2, i); // apelez programul din nou transmitand numarul de repetitii
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
