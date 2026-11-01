#include <stdio.h>
#include <string.h>
#include <ctype.h>

int analyserSecuriteMotDePasse(const char *motDePasse)
{
    int score = 0;
    int majuscule = 0;
    int minuscule = 0;
    int chiffre = 0;
    int caractereSpecial = 0;

    int longueur = strlen(motDePasse);

    if (longueur >= 8)
        score++;

    for (int i = 0; motDePasse[i] != '\0'; i++)
    {
        if (isupper((unsigned char)motDePasse[i]))
            majuscule = 1;
        else if (islower((unsigned char)motDePasse[i]))
            minuscule = 1;
        else if (isdigit((unsigned char)motDePasse[i]))
            chiffre = 1;
        else
            caractereSpecial = 1;
    }

    score += majuscule;
    score += minuscule;
    score += chiffre;
    score += caractereSpecial;
    
    return score;
}