#include <stdio.h>
#include <stdlib.h>

// تعريف بنية العقدة في القائمة
typedef struct element {
    int val;                   // القيمة المخزنة في العقدة
    struct element *suivant;   // مؤشر للعقدة التالية
} element;

// دالة لإنشاء قائمة فارغة
element* creerListe() {
    return NULL; // إرجاع قائمة فارغة
}

// دالة لإضافة عقدة جديدة في نهاية القائمة
void chargerListe(int Tab[], int taille, element **liste) {
    for (int i = 0; i < taille; i++) {
        element *nouveau = (element *)malloc(sizeof(element));
        nouveau->val = Tab[i];
        nouveau->suivant = NULL;

        if (*liste == NULL) {
            *liste = nouveau; // إذا كانت القائمة فارغة، اجعل العنصر الأول هو العقدة الجديدة
        } else {
            element *temp = *liste;
            while (temp->suivant != NULL) {
                temp = temp->suivant; // الانتقال إلى آخر عقدة
            }
            temp->suivant = nouveau; // ربط العقدة الجديدة بنهاية القائمة
        }
    }
}

// دالة لعرض محتويات القائمة
void afficherListe(element *liste) {
    if (liste == NULL) {
        printf("La liste est vide\n");
        return;
    }
    element *temp = liste;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->suivant;
    }
    printf("NULL\n");
}

// دالة لحذف العقدة الأخيرة من القائمة
element* supprimerEnFin(element *liste) {
    if (liste == NULL) {
        printf("La liste est vide, rien à supprimer.\n");
        return NULL;
    }

    if (liste->suivant == NULL) { // إذا كانت القائمة تحتوي على عقدة واحدة
        free(liste);
        return NULL;
    }

    element *temp = liste;
    while (temp->suivant->suivant != NULL) {
        temp = temp->suivant; // الوصول إلى العقدة قبل الأخيرة
    }

    free(temp->suivant); // حذف العقدة الأخيرة
    temp->suivant = NULL; // تعيين العقدة قبل الأخيرة كنهاية القائمة
    return liste;
}

// دالة لإضافة عقدة جديدة في بداية القائمة
element* ajouterEnDebut(element *liste, int val) {
    element *nouveau = (element *)malloc(sizeof(element));
    nouveau->val = val;
    nouveau->suivant = liste; // ربط العقدة الجديدة ببداية القائمة
    return nouveau; // إرجاع القائمة الجديدة
}

// دالة لتفريغ القائمة
void viderListe(element **liste) {
    element *temp;
    while (*liste != NULL) {
        temp = *liste;
        *liste = (*liste)->suivant;
        free(temp);
    }
    printf("La liste est vide.\n");
}

// الدالة الرئيسية
int main() {
    int Tab[10] = {1, 3, 5, 7, 8, 10, 9, 11, 13, 20}; // مصفوفة تحتوي على القيم
    element *liste = creerListe(); // إنشاء قائمة فارغة

    // بناء القائمة من المصفوفة
    chargerListe(Tab, 10, &liste);
    afficherListe(liste); // عرض القائمة

    // حذف العقدة الأخيرة
    liste = supprimerEnFin(liste);
    afficherListe(liste);

    // إضافة عقدة جديدة في البداية
    liste = ajouterEnDebut(liste, 40);
    afficherListe(liste);

    // تفريغ القائمة
    viderListe(&liste);
    afficherListe(liste);

    return 0;
}