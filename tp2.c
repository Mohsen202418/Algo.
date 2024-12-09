#include <stdio.h>
#include <stdlib.h>

// 1. "ChargerChaine"
char *ChargerChaine(int N) {
    char *chaine = (char *)malloc((N + 1) * sizeof(char));

    while (1) {
        printf("Veuillez saisir une chaîne de caractères (max %d caractères):\n", N);
        scanf(" %[^\n]", chaine); //قراءة النص المدخل 

        //حساب طول النص المدخل للتحقق
             int longueur = 0;
        for (int i = 0; chaine[i] != '\0'; i++) {
            longueur++;
        }

        if (longueur > N) { //التحقق من طول النص المدخل 
            printf("Erreur: La chaîne dépasse la taille maximale de %d caractères. Veuillez réessayer.\n", N);
        } else {
            break; //إذا كان الطول صحيحًا الخروج من الحلقة 
        }
    }

    return chaine;
}

// 2. "Longueur"
int Longueur(char *ch) {
    int longueur = 0;
    while (ch[longueur] != '\0') {
        longueur++;
    }
    return longueur;
}

// 3. "ChargerTab"
void ChargerTab(char *p, char Tab[]) {
    int i = 0;
    while (p[i] != '\0') {
        Tab[i] = p[i]; //نسخ النص من المؤشر إلى المصفوفة 
        i++;
    }
    Tab[i] = '\0'; // إضافة النهاية null
}

// 4. "InverserTab"
void InverserTab(char Tab[], char T[], int m) {
    for (int i = 0; i < m; i++) {
        T[i] = Tab[m - 1 - i]; // عكس العناصر
    }
    T[m] = '\0'; // إضافة النهاية null
}

// 5. "AfficherTab"
void AfficherTab(char Tab[], int m) { //m طول السلسلة 
    for (int i = 0; i < m; i++) {
        printf("%c", Tab[i]);
    }
    printf("\n");
}

int main() {
    char *ch;
    int n;

    printf("Veuillez saisir la taille maximale de la chaîne:\nn=");
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
