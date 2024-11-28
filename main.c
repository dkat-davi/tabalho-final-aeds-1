#include <stdio.h>

struct Veiculo
{
    int placa;
    char nome[20];
};

int main()
{
    struct Veiculo veiculos;

    printf("Nome do veiculo: ");
    fgets(veiculos.nome, 20, stdin);

    // printf("Digite: ");
    // scanf("%19s", veiculos.nome);

    printf("Este é o nome do veiculo: %s", veiculos.nome);

    return 0;
}