#include <stdio.h>
#include <string.h>

void saisirMotDePasse(char motDePasse[])
{
    do
    {
        printf("Entrez votre mot de passe : ");

        fgets(motDePasse, 100, stdin);

        // Supprimer le retour à la ligne ajouté par fgets
        motDePasse[strcspn(motDePasse, "\n")] = '\0';

        if (strlen(motDePasse) == 0)
        {
            printf("Erreur : le mot de passe ne peut pas etre vide.\n");
        }

    } while (strlen(motDePasse) == 0);
}