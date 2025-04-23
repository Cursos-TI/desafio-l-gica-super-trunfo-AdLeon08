#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta de país
typedef struct {
    char nome_pais[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_demografica;
} Carta;

// Função para calcular densidade demográfica
void calcularDensidade(Carta *c) {
    c->densidade_demografica = c->populacao / c->area;
}

// Função para exibir os dados da carta
void exibirCarta(Carta c) {
    printf("País: %s\n", c.nome_pais);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: R$ %.2f bilhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontos_turisticos);
    printf("Densidade Demográfica: %.2f hab/km²\n", c.densidade_demografica);
    printf("-------------------------------------------\n");
}

int main() {
    // Cartas pré-definidas
    Carta carta1 = {"Brasil", 213000000, 8515767.0, 2200.0, 20};
    Carta carta2 = {"Canadá", 38000000, 9984670.0, 1900.0, 15};

    // Calcular densidades
    calcularDensidade(&carta1);
    calcularDensidade(&carta2);

    int opcao;

    printf("==== SUPER TRUNFO DOS PAÍSES ====\n");
    exibirCarta(carta1);
    exibirCarta(carta2);

    printf("\nEscolha o atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    printf("\nComparação: %s vs %s\n", carta1.nome_pais, carta2.nome_pais);

    switch (opcao) {
        case 1:
            printf("Atributo: População\n");
            printf("%s: %d\n", carta1.nome_pais, carta1.populacao);
            printf("%s: %d\n", carta2.nome_pais, carta2.populacao);
            if (carta1.populacao > carta2.populacao)
                printf("Vencedor: %s\n", carta1.nome_pais);
            else if (carta2.populacao > carta1.populacao)
                printf("Vencedor: %s\n", carta2.nome_pais);
            else
                printf("Resultado: Empate!\n");
            break;

        case 2:
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", carta1.nome_pais, carta1.area);
            printf("%s: %.2f km²\n", carta2.nome_pais, carta2.area);
            if (carta1.area > carta2.area)
                printf("Vencedor: %s\n", carta1.nome_pais);
            else if (carta2.area > carta1.area)
                printf("Vencedor: %s\n", carta2.nome_pais);
            else
                printf("Resultado: Empate!\n");
            break;

        case 3:
            printf("Atributo: PIB\n");
            printf("%s: R$ %.2f bilhões\n", carta1.nome_pais, carta1.pib);
            printf("%s: R$ %.2f bilhões\n", carta2.nome_pais, carta2.pib);
            if (carta1.pib > carta2.pib)
                printf("Vencedor: %s\n", carta1.nome_pais);
            else if (carta2.pib > carta1.pib)
                printf("Vencedor: %s\n", carta2.nome_pais);
            else
                printf("Resultado: Empate!\n");
            break;

        case 4:
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d\n", carta1.nome_pais, carta1.pontos_turisticos);
            printf("%s: %d\n", carta2.nome_pais, carta2.pontos_turisticos);
            if (carta1.pontos_turisticos > carta2.pontos_turisticos)
                printf("Vencedor: %s\n", carta1.nome_pais);
            else if (carta2.pontos_turisticos > carta1.pontos_turisticos)
                printf("Vencedor: %s\n", carta2.nome_pais);
            else
                printf("Resultado: Empate!\n");
            break;

        case 5:
            printf("Atributo: Densidade Demográfica (MENOR vence)\n");
            printf("%s: %.2f hab/km²\n", carta1.nome_pais, carta1.densidade_demografica);
            printf("%s: %.2f hab/km²\n", carta2.nome_pais, carta2.densidade_demografica);
            if (carta1.densidade_demografica < carta2.densidade_demografica)
                printf("Vencedor: %s\n", carta1.nome_pais);
            else if (carta2.densidade_demografica < carta1.densidade_demografica)
                printf("Vencedor: %s\n", carta2.nome_pais);
            else
                printf("Resultado: Empate!\n");
            break;

        default:
            printf("Opção inválida! Por favor, escolha entre 1 e 5.\n");
    }

    return 0;
}
