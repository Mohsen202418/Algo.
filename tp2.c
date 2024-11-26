#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1.  "ChargerChaine"
char *ChargerChaine(int N) {
    char *chaine = (char *)malloc((N + 1) * sizeof(char));
    if (chaine == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }

    while (1) { // حلقة تستمر حتى يدخل المستخدم نصًا بطول مناسب
        printf("Veuillez saisir une chaîne de caractères (max %d caractères):\n", N);
        scanf(" %[^\n]", chaine);

        // التحقق من طول النص المدخل
        if (strlen(chaine) > N) {
            printf("Erreur: La chaîne dépasse la taille maximale de %d caractères. Veuillez réessayer.\n", N);
        } else {
            break; // إذا كان الطول صحيحًا، نخرج من الحلقة
        }
    }

    return chaine;
}
// 2.  "Longueur"
int Longueur(char *ch) {
    return strlen(ch); // حساب طول السلسلة باستخدام الدالة strlen
}

// 3.  "ChargerTab"
void ChargerTab(char *p, char Tab[]) {
    strcpy(Tab, p); // نسخ السلسلة إلى المصفوفة
}

// 4.  "InverserTab"
void InverserTab(char Tab[], char T[], int m) {
    for (int i = 0; i < m; i++) {
        T[i] = Tab[m - 1 - i]; // عكس العناصر
    }
    T[m] = '\0'; // إضافة النهاية null
}

// 5.  "AfficherTab"
void AfficherTab(char Tab[], int m) {
    printf("Contenu du tableau: %s\n", Tab);
}

int main() {
    char *ch;
    int n;

    printf("Veuillez saisir la taille maximale de la chaîne:\n");
    scanf("%d", &n);

    ch = ChargerChaine(n);

    int m = Longueur(ch);
    printf("La longueur de la chaîne est: %d\n", m);

    char Tab[m + 1], T[m + 1];
    ChargerTab(ch, Tab);

    printf("Chaîne originale:\n");
    AfficherTab(Tab, m);

    InverserTab(Tab, T, m);

    printf("Chaîne inversée:\n");
    AfficherTab(T, m);

    free(ch);  
    return 0;
}