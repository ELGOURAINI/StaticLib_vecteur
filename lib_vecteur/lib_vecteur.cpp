// lib_vecteur.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
#include <iostream>
#include "Header1.h"
using namespace math;
using namespace std;
int main()
{
    Vecteur3D<int> v1(1, 2, 3);
    Vecteur3D<int> v2(1, 2, 3);
    v1.print();
    int i=v1.norme();
    cout << "la norme est" << i;
}
