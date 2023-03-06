#include "arv.c"

int main(void){
    setlocale(LC_ALL, "Portuguese");
    /*
                'a'
               /   \
              /     \
            'b'     'c'
            /       / \
           /       /   \
         'd'     'e'   'f'
    */
    Arv* arvore1 = arv_cria('d', arv_criavazia(), arv_criavazia());
    Arv* arvore2 = arv_cria('e', arv_criavazia(), arv_criavazia());
    Arv* arvore3 = arv_cria('f', arv_criavazia(), arv_criavazia());    
    Arv* arvore4 = arv_cria('b', arvore1, arv_criavazia());
    Arv* arvore5 = arv_cria('c', arvore2, arvore3);
    Arv* arvore6 = arv_cria('a', arvore4, arvore5);

    printf("Qtd folhas - arvore1: %d", arv_folhas(arvore1));
    printf("\nQtd folhas - arvore2: %d", arv_folhas(arvore2));
    printf("\nQtd folhas - arvore3: %d", arv_folhas(arvore3));
    printf("\nQtd folhas - arvore4: %d", arv_folhas(arvore4));
    printf("\nQtd folhas - arvore5: %d", arv_folhas(arvore5));
    printf("\nQtd folhas - arvore6: %d", arv_folhas(arvore6));

    printf("\n\nAltura - arvore1: %d", arv_altura(arvore1));
    printf("\nAltura - arvore2: %d", arv_altura(arvore2));
    printf("\nAltura - arvore3: %d", arv_altura(arvore3));
    printf("\nAltura - arvore4: %d", arv_altura(arvore4));
    printf("\nAltura - arvore5: %d", arv_altura(arvore5));
    printf("\nAltura - arvore6: %d", arv_altura(arvore6));

    printf("\n\n\t\tImpressão (Pré-ordem)\n");
    arv_imprime_pre(arvore6);
    printf("\n\n\t\tImpressão (Ordem simétrica)\n");
    arv_imprime_sim(arvore6);
    printf("\n\n\t\tImpressão (Pós-ordem)\n");
    arv_imprime_pos(arvore6);

    printf("\n\nChar 'a' pertence à arvore6? %d", arv_pertence(arvore6, 'a'));
    printf("\n\nChar 'z' pertence à arvore6? %d", arv_pertence(arvore6, 'z'));

    Arv* arvore7 = arv_copia(arvore6);
    printf("\n\n\t\tImpressão da Cópia (Pré-ordem)\n");
    arv_imprime_pre(arvore7);
    printf("\n\n\t\tImpressão da Cópia (Ordem simétrica)\n");
    arv_imprime_sim(arvore7);
    printf("\n\n\t\tImpressão da Cópia (Pós-ordem)\n");
    arv_imprime_pos(arvore7);

    printf("\n\narvore6 e arvore7 (Cópia de arvore6) são iguais? %d", arv_igual(arvore6, arvore7));
    printf("\n\narvore6 e arvore5 (Filha de arvore6) são iguais? %d", arv_igual(arvore6, arvore5));

    printf("\n\n\t\tImpressão antes da utilização de arv_libera()\n");
    arv_imprime_pre(arvore6);
    printf("\n\narvore6 está vazia? %d", arv_vazia(arvore6));
    arvore6 = arv_libera(arvore6);
    printf("\n\n\t\tImpressão depois da utilização de arv_libera()\n");
    arv_imprime_pre(arvore6);
    printf("\n\narvore6 está vazia? %d\n", arv_vazia(arvore6));
}