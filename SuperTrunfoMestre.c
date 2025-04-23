#include <stdio.h>
#include <string.h>

#define QTD_ATRIBUTOS 6

typedef struct {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_demografica;
} Carta;

// Função auxiliar para exibir atributos disponíveis
void exibirMenuAtributos(int excluir) {
    printf("\nEscolha um atributo:\n");
    if (excluir != 1) printf("1 - População\n");
    if (excluir != 2) printf("2 - Área\n");
    if (excluir != 3) printf("3 - PIB\n");
    if (excluir != 4) printf("4 - Pontos Turísticos\n");
    if (excluir != 5) printf("5 - Densidade Demográfica\n");
}

// Função para retornar o valor do atributo escolhido
float obterValorAtributo(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pontos_turisticos;
        case 5: return c.densidade_demografica;
        default: return 0;
    }
}

// Função para comparar dois atributos com regras
int compararAtributo(Carta c1, Carta c2, int atributo) {
    float v1 = obterValorAtributo(c1, atributo);
    float v2 = obterValorAtributo(c2, atributo);

    if (atributo == 5) { // Densidade Demográfica: menor vence
        return (v1 < v2) ? 1 : (v1 > v2) ? 2 : 0;
    } else {
        return (v1 > v2) ? 1 : (v1 < v2) ? 2 : 0;
    }
}

int main() {
    // Cartas pré-definidas
    Carta carta1 = {"Brasil", 214000000, 8515767, 1500000000000.0, 100, 25.1};
    Carta carta2 = {"Japão", 126000000, 377975, 5100000000000.0, 150, 333.4};

    int escolha1, escolha2;

    printf("Comparação entre %s e %s!\n", carta1.nome, carta2.nome);

    // Escolha do primeiro atributo
    exibirMenuAtributos(0);
    printf("Escolha o primeiro atributo (1 a 5): ");
    scanf("%d", &escolha1);

    while (escolha1 < 1 || escolha1 > 5) {
        printf("Atributo inválido. Escolha de novo: ");
        scanf("%d", &escolha1);
    }

    // Escolha do segundo atributo
    exibirMenuAtributos(escolha1);
    printf("Escolha o segundo atributo (diferente do primeiro): ");
    scanf("%d", &escolha2);

    while (escolha2 < 1 || escolha2 > 5 || escolha2 == escolha1) {
        printf("Atributo inválido ou repetido. Escolha de novo: ");
        scanf("%d", &escolha2);
    }

    // Comparação individual
    int resultado1 = compararAtributo(carta1, carta2, escolha1);
    int resultado2 = compararAtributo(carta1, carta2, escolha2);

    float valor1_a = obterValorAtributo(carta1, escolha1);
    float valor2_a = obterValorAtributo(carta2, escolha1);

    float valor1_b = obterValorAtributo(carta1, escolha2);
    float valor2_b = obterValorAtributo(carta2, escolha2);

    float soma1 = valor1_a + valor1_b;
    float soma2 = valor2_a + valor2_b;

    printf("\n--- Resultado da Comparação ---\n");
    printf("País 1: %s\n", carta1.nome);
    printf("País 2: %s\n", carta2.nome);

    printf("\nAtributo %d: %.2f (%.s) vs %.2f (%s)\n", escolha1, valor1_a, carta1.nome, valor2_a, carta2.nome);
    printf("Atributo %d: %.2f (%.s) vs %.2f (%s)\n", escolha2, valor1_b, carta1.nome, valor2_b, carta2.nome);

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", carta1.nome, soma1);
    printf("%s: %.2f\n", carta2.nome, soma2);

    if (soma1 > soma2) {
        printf("\n%s venceu a rodada!\n", carta1.nome);
    } else if (soma2 > soma1) {
        printf("\n%s venceu a rodada!\n", carta2.nome);
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}
