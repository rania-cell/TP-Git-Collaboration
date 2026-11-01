// Module 3: Display results and security report

#include <stdio.h>
#include <string.h>

void afficher_rapport_securite(int score, const char *niveau)
{
    printf("\n");
    printf("====================================\n");
    printf("        SECURITY REPORT\n");
    printf("====================================\n");

    printf("Analysis completed successfully.\n");
    printf("Password score: %d/100\n", score);
    printf("Password strength: %s\n", niveau);

    printf("\nSecurity recommendations:\n");

    if (score < 40) {
        printf("- Use a longer password.\n");
        printf("- Include uppercase and lowercase letters.\n");
        printf("- Include numbers and special characters.\n");
    }
    else if (score < 70) {
        printf("- Try using a longer password.\n");
        printf("- Avoid predictable patterns.\n");
    }
    else {
        printf("- Use a unique password for each account.\n");
        printf("- Enable two-factor authentication.\n");
        printf("- Never share your password.\n");
    }

    printf("====================================\n");
}
