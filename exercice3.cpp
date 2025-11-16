// vectok.h
#include "vect.h"
#include <iostream>
using namespace std;
class vect
{
protected:                // accessible aux classes dérivées
    int nelem;            // nombre d'éléments
    int* adr;             // tableau dynamique

public:
    vect(int n) : nelem(n) {
        adr = new int[n];
        for(int i = 0; i < n; i++) adr[i] = 0; // init
    }

    ~vect() {
        delete[] adr;
    }

    int& operator[](int i) {
        return adr[i];
    }
};



class vectok : public vect
{
public:
    // Constructeur normal ? simplement utiliser celui de base
    vectok(int n) : vect(n) {}

    // Constructeur par copie
    vectok(const vectok& other) : vect(other.nelem)
    {
        for(int i = 0; i < nelem; i++)
            adr[i] = other.adr[i];
    }

    // Opérateur d'affectation
    vectok& operator=(const vectok& other)
    {
        if (this == &other)  // auto-affectation
            return *this;

        // Si tailles différentes ? réallouer
        if (nelem != other.nelem)
        {
            delete[] adr;
            nelem = other.nelem;
            adr = new int[nelem];
        }

        // Copier les éléments
        for(int i = 0; i < nelem; i++)
            adr[i] = other.adr[i];

        return *this;
    }

    // Fonction taille()
    int taille() const {
        return nelem;
    }
};


int main()
{
    vectok a(5);

    for(int i = 0; i < a.taille(); i++)
        a[i] = i * 10;

    cout << "Vecteur a : ";
    for(int i = 0; i < a.taille(); i++)
        cout << a[i] << " ";
    cout << endl;

    // Test du constructeur de copie
    vectok b = a;

    cout << "Vecteur b (copie de a) : ";
    for(int i = 0; i < b.taille(); i++)
        cout << b[i] << " ";
    cout << endl;

    // Modification de b ? doit PAS modifier a
    b[0] = 999;

    cout << "Après modification de b :\n";
    cout << "a[0] = " << a[0] << endl;
    cout << "b[0] = " << b[0] << endl;

    // Test opérateur d’affectation
    vectok c(3);
    c = a;

    cout << "Vecteur c (après affectation c = a) : ";
    for(int i = 0; i < c.taille(); i++)
        cout << c[i] << " ";
    cout << endl;

    return 0;
}

