
#include <stdio.h>

int main() { printf("Exercise 1 :\n");
    char M[5][5] = {
        {'1', '2', '3', '4', '5'},
        {'7', 'a', 'c', '8', 'd'},
        {'c', '9', '4', 'z', '8'},
        {'5', '6', 'p', 'n', '3'},
        {'2', '9', 't', 'm', 'k'}
    };
    

    printf("Matrice complète:\n");
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%c ", M[i][j]);
        }
        printf("\n");
    }

    printf("\nLignes d'indice pair:\n");
    for(int i = 0; i < 5; i += 2) { // Itérer sur les indices pairs
        for(int j = 0; j < 5; j++) {
            printf("%c ", M[i][j]);
        }
        printf("\n");
    }
    printf("\nÉléments d'indice impair de chaque ligne:\n");
    for(int i = 0; i < 5; i++) {
        for(int j = 1; j < 5; j += 2) { // Itérer sur les indices impairs
            printf("%c ", M[i][j]);
        }
        printf("\n");
    }
    
    
   printf("Exercise 2 :\n");
    
{
     int A[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
     int T;
     int i,j;
     printf("tableau inital:\n");
     for (i=0;i<4;i++){
        for(j=0;j<4;j++){
                printf("%d\t",A[i][j]);
        }
        printf("\n");
     }
     for (i=0;i<3;i++){
        for(j=i+1;j<4;j++){
            T=A[i][j];
            A[i][j]=A[j][i];
            A[j][i]=T;
        }
     }
     printf("tableau echange:\n");
     for (i=0;i<4;i++){
        for(j=0;j<4;j++){
                printf("%d\t",A[i][j]);
        }
               printf("\n");
     }
    return 0;
}
}
    
