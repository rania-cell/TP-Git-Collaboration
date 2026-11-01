
#include <stdio.h>

// 1. Display the analysis result
void afficher_resultat(int resultat)
{
    printf("\n====================================\n");
    printf("         RESULTAT DE L'ANALYSE\n");
    printf("====================================\n");

    printf("Score obtenu : %d/5\n", resultat);
}

// 2. Display an error message
void afficher_message_erreur(const char *message)
{
    printf("\n[ERREUR] %s\n", message);
}

// 3. Generate and display the security report
void afficher_rapport_securite(int resultat)
{
    printf("\n====================================\n");
    printf("          RAPPORT DE SECURITE\n");
    printf("====================================\n");

    if (resultat < 0 || resultat > 5)
    {
        afficher_message_erreur("Score invalide !");
        return;
    }

    if (resultat <= 2)
    {
        printf("Niveau : FAIBLE\n");
        printf("Votre mot de passe est faible.\n");

        printf("\nRecommandations :\n");
        printf("- Utilisez au moins 8 caracteres.\n");
        printf("- Ajoutez des lettres majuscules et minuscules.\n");
        printf("- Ajoutez des chiffres.\n");
        printf("- Ajoutez des caracteres speciaux.\n");
    }
    else if (resultat <= 4)
    {
        printf("Niveau : MOYEN\n");
        printf("Votre mot de passe offre une securite moyenne.\n");

        printf("\nRecommandations :\n");
        printf("- Ajoutez les caracteristiques manquantes.\n");
        printf("- Utilisez un mot de passe plus long.\n");
        printf("- Evitez les mots de passe previsibles.\n");
    }
    else
    {
        printf("Niveau : FORT\n");
        printf("Votre mot de passe est fort.\n");

        printf("\nRecommandations :\n");
        printf("- Utilisez un mot de passe unique.\n");
        printf("- Ne partagez jamais votre mot de passe.\n");
        printf("- Activez l'authentification a deux facteurs.\n");
    }

    printf("====================================\n");
}
