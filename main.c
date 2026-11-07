#include <stdio.h>

// Fonctions des autres membres
void saisirMotDePasse(char motDePasse[]);
int analyserSecuriteMotDePasse(const char *motDePasse);
void afficher_resultat(int resultat);
void afficher_message_erreur(const char *message);
void afficher_rapport_securite(int resultat);

int main(void)
{
    char motDePasse[100];
    int score;

    printf("Application de securite informatique\n");
    printf("Application developpee par A\n");
    printf("Application developpee par B\n");

    // Appel du module 1
    saisirMotDePasse(motDePasse);

    // Appel du module 2
    score = analyserSecuriteMotDePasse(motDePasse);

    // Appel du module 3
    afficher_resultat(score);
    afficher_rapport_securite(score);

    return 0;
}
