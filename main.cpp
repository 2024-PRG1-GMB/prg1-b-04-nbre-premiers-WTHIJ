/*
-----------------------------------------------------------------------------
Titre          : Calcul des nombres premiers
Auteur         : Pierre THIEBAUD
Date           : 3 Octobre 2024
-----------------------------------------------------------------------------
Description :
Ce programme sert à afficher les nombres premiers dans un intervalle de 2 jusqu'à 1000
au maximum. La limite peut toutefois être modifiée par l'utilisateur.
*/

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {

    int nombre_limite;
    string reponse;

    cout << "Ce programme affiche tous les nombres premiers "
         << "compris entre 1 et une valeur saisie par l’utilisateur." << endl;

    do {
        do {
            cout << "Veuillez entrer une valeur limite dans l'intervalle [2-1000] : ";
            cin >> nombre_limite;
        } while (nombre_limite < 2 or nombre_limite > 1000);

        int nombre_colones = 0, compteur = 0;

        //Test des nombres premiers de 2 à la limite entrée par l'utilisateur (nombre_limite)

        for (int nombre_actuel = 2; nombre_actuel <= nombre_limite; ++nombre_actuel) {
            compteur = 0;

            //Test de tous les diviseurs possibles pour le nombre actuel (jusqu'à la racine du nombre actuel)

            for (int diviseur = 1; diviseur * diviseur <= nombre_actuel; ++diviseur) {
                if (nombre_actuel % diviseur == 0) {
                    ++compteur;
                }
            }

            // Si le nombre possède plus de deux diviseurs, il n'est pas premier

            if (compteur < 2) {
                if (nombre_colones < 5) {
                    cout << '\t' << nombre_actuel << " ";
                    ++nombre_colones;

                } else {
                    cout << endl << '\t' << nombre_actuel << " ";
                    nombre_colones = 0;
                    ++nombre_colones;

                }
            }
        }

        cout << "\n" << "Souhaitez-vous recommencer ? [O/N] ";
        cin >> reponse;

    } while (reponse != "N");

    return EXIT_SUCCESS;
}
