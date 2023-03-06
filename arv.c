#include "arv.h"

Arv* arv_criavazia(void){
    Arv* arvore = NULL;
    return arvore;
}

Arv* arv_cria(char c, Arv* e, Arv* d){
    Arv* a = (Arv *)malloc(sizeof(Arv));
    a->info = c;
    a->esq = e;
    a->dir = d;
    return a;
}

Arv* arv_libera(Arv* a){
    if (!arv_vazia(a)){
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }
    return NULL;
}

int arv_vazia(Arv* a){
    return (a == NULL);
}

int arv_pertence(Arv* a, char c){
    if (a == NULL) return 0;
    return (a->info == c) || arv_pertence(a->esq, c) || arv_pertence(a->dir, c);
}

void arv_imprime_pre(Arv* a){
    printf("<");
    if (!arv_vazia(a)) {
        printf("%c", a->info);
        arv_imprime_pre(a->esq);
        arv_imprime_pre(a->dir);
    }
    printf(">");
}

void arv_imprime_sim(Arv* a){
    printf("<");
    if (!arv_vazia(a)) {
        arv_imprime_pre(a->esq);
        printf("%c", a->info);
        arv_imprime_pre(a->dir);
    }
    printf(">");
}

void arv_imprime_pos(Arv* a){
    printf("<");
    if (!arv_vazia(a)) {
        arv_imprime_pre(a->esq);
        arv_imprime_pre(a->dir);
        printf("%c", a->info);
    }
    printf(">");
}

int arv_folhas(Arv* a){
    if (arv_vazia(a)) return 0;
    if (a->esq == NULL && a->dir == NULL) return 1;
    return arv_folhas(a->esq) + arv_folhas(a->dir);
}

int arv_altura(Arv* a){
    if ((arv_vazia(a)) || (a->esq == NULL && a->dir == NULL)) return 0;
    return 1 + (arv_altura(a->esq) || arv_altura(a->dir));
}

int arv_igual(Arv* a1, Arv* a2){
    if (arv_vazia(a1) && arv_vazia(a2)) return 1;
    if ((arv_vazia(a1) && !arv_vazia(a2)) || (!arv_vazia(a1) && arv_vazia(a2))) return 0;
    return (a1->info == a2->info && arv_igual(a1->esq, a2->esq) && arv_igual(a1->dir, a2->dir));
}

Arv* arv_copia(Arv* a){
    if (arv_vazia(a)) return arv_criavazia();
    return (arv_cria(a->info, arv_copia(a->esq), arv_copia(a->dir)));
}