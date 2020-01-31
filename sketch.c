#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct polynomial {
    int order;
    int *koefisien;
} polinom;

void init_poly(polinom *p){
    int i;
    printf("Masukan derajat polinom\n");
    scanf("%d", &p->order);
    p->koefisien = malloc((p->order + 1)*sizeof(int));
    for(i = p->order; i >= 0; --i){
        printf("Masukkan koefisien dari x^%d:", i);
        scanf("%d", &p->koefisien[i]);
    }
}
void drop_poly(polinom *p){
    free(p->koefisien);
}

void print_poly(polinom *p){
    int i;
    for(i = p->order; i >= 0; --i){
        if(p->koefisien[i]){
            if(p->order != i){
                printf(" %c ", p->koefisien[i] < 0 ? '-' : '+');
                printf("%d", abs(p->koefisien[i]));
            } else
                printf("%d", p->koefisien[i]);
            if(i)
                printf("x^%d", i);
        }
    }
    printf("\n");
}

void differential_poly(polinom *p){
    int i;
    for(i = 0; i < p->order; ++i){
        p->koefisien[i] = p->koefisien[i+1] * (i+1);
    }
    p->koefisien[p->order--] = 0;
}

void r_print_differential_poly(polinom *p){
    int i=1;
    while(p->order){
        differential_poly(p);
        printf("f%d = ", i++);
        print_poly(p);
    }
}


int main()
{
    int  x1, x2, y=0;
    char op, tipe;
    printf("Selamat datang di TUGAS 2 \n Silahkan memilih menu \n");
    printf("A Kalkulator Sederhana B Turunan Polinomial\n");
    scanf("%c", &tipe);
    if(tipe=='A'){
        printf("Anda Memilih Menu Kalkulator Sederhana\n");
        printf("Masukkan bilangan pertama : \n");
        scanf("%d", &x1);
        printf("Masukkan bilangan kedua : \n");
        scanf("%d", &x2);
        printf("Masukkan operator : \n");
        scanf("%c", &op);
        if(op=='+'){y = x1 + x2 ;}
        else if(op=='-'){y = x1 - x2 ;}
        else if(op=='*'){y = x1 * x2 ;}
//        printf("Bil 1 = %x1 ; Bil2 = %x2", x1, x2);
        printf("Hasil operasi kalkulator sederhana ini adalah : %d", y);

    }
    else if(tipe=='B')
    {
        printf("Anda Memilih Menu Kalkulator Turunan Polinomial\n");
        polinom poly;

        init_poly(&poly);
        printf("Polinom yang diberikan adalah\n");
        print_poly(&poly);

        r_print_differential_poly(&poly);

        drop_poly(&poly);

    }
    return 0;
}
