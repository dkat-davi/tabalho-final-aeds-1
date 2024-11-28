#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VEICULOS 100

struct Veiculo
{
    int renavam;
    char nomeProprietario[51];
    int anoFabricacao;
    char cor[4];
    char marca[5];
    double preco;
};

void mostrarMenu()
{
    printf("==============================================================\n");
    printf("                       MENU PRINCIPAL                        \n");
    printf("==============================================================\n");
    printf("1. Adicionar Veículo\n");
    printf("2. Listar Veículos\n");
    printf("3. Atualizar Dados de Veículo\n");
    printf("4. Listar Veículos por Cor\n");
    printf("5. Listar Veículos por Marca\n");
    printf("6. Consultar Veículo por Renavam\n");
    printf("7. Remover Veículo\n");
    printf("8. Sair\n");
    printf("--------------------------------------------------------------\n");
    printf("Escolha uma opção: ");
}

void limparTela()
{
    // Se estiver em ambiente Windows use o cls
    // system("cls");

    // Caso contrário use clear
    system("clear");
}

void adicionarVeiculo(struct Veiculo veiculos[], int *contador)
{
    if (*contador >= MAX_VEICULOS)
    {
        limparTela();
        printf("\n");
        printf("=================================================\n");
        printf("        🚨 ATENÇÃO: LIMITE ATINGIDO 🚨           \n");
        printf("=================================================\n");
        printf("      O limite de veículos foi atingido!         \n");
        printf("    Remova um veículo para adicionar um novo.    \n");
        printf("=================================================\n");
        printf("\n");
        return;
    }

    limparTela();
    struct Veiculo novoVeiculo;

    printf("======================= NOVO VEÍCULO =======================\n");
    printf("=> Digite o nº do Renavam: ");
    scanf("%d", &novoVeiculo.renavam);

    getchar();

    printf("=> Digite o nome do proprietário (máximo 50 caracteres): ");
    fgets(novoVeiculo.nomeProprietario, 50, stdin);
    novoVeiculo.nomeProprietario[strcspn(novoVeiculo.nomeProprietario, "\n")] = '\0';

    printf("=> Digite o ano de fabricação: ");
    scanf("%d", &novoVeiculo.anoFabricacao);

    printf("=> Digite a cor do veículo (3 caracteres): ");
    scanf("%s", novoVeiculo.cor);

    printf("=> Digite a marca do veículo (4 caracteres): ");
    scanf("%s", novoVeiculo.marca);

    printf("=> Digite o preço de compra: ");
    scanf("%lf", &novoVeiculo.preco);
    printf("==============================================================\n");

    veiculos[*contador] = novoVeiculo;
    (*contador)++;

    printf("                 VEÍCULO ADICIONADO COM SUCESSO!                  ");
    printf("\n==============================================================\n");
}

void listarVeiculos(struct Veiculo veiculos[], int contador)
{
    limparTela();
    printf("==============================================================\n");
    printf("                     LISTAGEM DE VEÍCULOS                     \n");
    printf("==============================================================\n");

    if (contador == 0)
    {
        printf("\n                  NENHUM VEÍCULO CADASTRADO                   \n\n");
        printf("==============================================================\n");
        return;
    }

    for (int i = 0; i < contador; i++)
    {
        printf("------------------------   Veículo %d   -----------------------\n", i + 1);
        printf("=> Renavam: %d\n", veiculos[i].renavam);
        printf("=> Nome do Proprietário: %s\n", veiculos[i].nomeProprietario);
        printf("=> Ano de Fabricação: %d\n", veiculos[i].anoFabricacao);
        printf("=> Cor: %s\n", veiculos[i].cor);
        printf("=> Marca: %s\n", veiculos[i].marca);
        printf("=> Preço de Compra: R$%.2lf\n", veiculos[i].preco);
        printf("==============================================================\n");
    }
}

void atualizarVeiculo(struct Veiculo veiculos[], int contador)
{
    int numeroRenavam;
    int opcao;
    int encontrado = -1;

    limparTela();
    printf("==============================================================\n");
    printf("                   ATUALIZAR DADOS DE VEICULO                 \n");
    printf("==============================================================\n");

    printf("Digite o Renavam do veículo que deseja atualizar: ");
    scanf("%d", &numeroRenavam);
    printf("==============================================================\n");

    for (int i = 0; i < contador; i++)
    {
        if (veiculos[i].renavam == numeroRenavam)
        {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1)
    {

        printf("\n        🚨 Veículo com Renavam %d não encontrado! 🚨         \n", numeroRenavam);
        printf("\n==============================================================\n");
    }
    else
    {
        limparTela();
        struct Veiculo *veiculoParaAtualizar = &veiculos[encontrado];
        printf("\n==============================================================\n");
        printf("                  DADOS PARA SEREM ATUALIZADOS                \n");
        printf("==============================================================\n");
        printf("------------------------   Veículo %d   ----------------------\n", encontrado + 1);
        printf("=> Renavam: %d\n", veiculoParaAtualizar->renavam);
        printf("1. Proprietário: %s\n", veiculoParaAtualizar->nomeProprietario);
        printf("2. Ano de Fabricação: %d\n", veiculoParaAtualizar->anoFabricacao);
        printf("3. Cor: %s\n", veiculoParaAtualizar->cor);
        printf("4. Marca: %s\n", veiculoParaAtualizar->marca);
        printf("5. Preço: R$ %.2lf\n", veiculoParaAtualizar->preco);
        printf("6. Atualizar todos os dados\n");
        printf("7. Cancelar atualização\n");
        printf("==============================================================\n");
        printf("Escolha uma opção para atualizar: ");
        scanf("%d", &opcao);
        printf("\n=================   ATUALIZAÇÃO DOS DADOS   ==================\n");

        switch (opcao)
        {
        case 1:
            printf("=> Digite o nome do proprietário atualizado (máximo 50 caracteres): ");
            getchar();
            fgets(veiculoParaAtualizar->nomeProprietario, 50, stdin);
            veiculoParaAtualizar->nomeProprietario[strcspn(veiculoParaAtualizar->nomeProprietario, "\n")] = '\0';
            break;
        case 2:
            printf("=> Digite o ano de fabricação atualizado: ");
            scanf("%d", &veiculoParaAtualizar->anoFabricacao);
            break;
        case 3:
            printf("=> Digite a cor do veículo atualizada (3 caracteres): ");
            scanf("%s", veiculoParaAtualizar->cor);
            break;
        case 4:
            printf("=> Digite a marca do veículo atualizada (4 caracteres): ");
            scanf("%s", veiculoParaAtualizar->marca);
            break;
        case 5:
            printf("=> Digite o preço de compra atualizado: ");
            scanf("%lf", &veiculoParaAtualizar->preco);
            break;
        case 6:
            printf("Atualizar todos");
            break;
        case 7:
            printf("\n              ATUALIZAÇÃO CANCELADA COM SUCESSO!              \n");
            printf("\n==============================================================\n");
            break;
        default:
            printf("\n                OPÇÃO INVÁLIDA, TENTE NOVAMENTE!              \n");
            printf("\n==============================================================\n");
            break;
        }
    }
}

void filtrarVeiculosPorCor(struct Veiculo veiculos[], int contador)
{
    char corParaBuscar[4];
    int encontrados = 0;

    limparTela();
    printf("==============================================================\n");
    printf("                   BUSCAR VEÍCULOs POR COR                    \n");
    printf("==============================================================\n");

    printf("Digite a cor do veículo que deseja buscar: ");
    scanf("%s", corParaBuscar);

    printf("\n==============================================================\n");
    printf("                   RESULTADOS DA BUSCA                        \n");
    printf("==============================================================\n");

    for (int i = 0; i < contador; i++)
    {
        if (strcmp(veiculos[i].cor, corParaBuscar) == 0)
        {
            printf("------------------------   Veículo %d   -----------------------\n", i + 1);
            printf("=> Renavam: %d\n", veiculos[i].renavam);
            printf("=> Proprietário: %s\n", veiculos[i].nomeProprietario);
            printf("=> Ano de Fabricação: %d\n", veiculos[i].anoFabricacao);
            printf("=> Cor: %s\n", veiculos[i].cor);
            printf("=> Marca: %s\n", veiculos[i].marca);
            printf("=> Preço: R$ %.2lf\n", veiculos[i].preco);
            printf("==============================================================\n");
            encontrados++;
        }
    }

    if (encontrados == 0)
    {
        printf("\n        🚨 Nenhum veículo da cor '%s' encontrado! 🚨        \n", corParaBuscar);
        printf("\n==============================================================\n");
    }
}

void filtrarVeiculosPorMarca(struct Veiculo veiculos[], int contador)
{
    char marcaParaBuscar[5];
    int encontrados = 0;

    limparTela();
    printf("==============================================================\n");
    printf("                  BUSCAR VEÍCULOs POR MARCA                    \n");
    printf("==============================================================\n");

    printf("Digite a marca do veículo que deseja buscar: ");
    scanf("%s", marcaParaBuscar);

    printf("\n==============================================================\n");
    printf("                   RESULTADOS DA BUSCA                        \n");
    printf("==============================================================\n");

    for (int i = 0; i < contador; i++)
    {
        if (strcmp(veiculos[i].marca, marcaParaBuscar) == 0)
        {
            printf("------------------------   Veículo %d   ----------------------\n", i + 1);
            printf("=> Renavam: %d\n", veiculos[i].renavam);
            printf("=> Proprietário: %s\n", veiculos[i].nomeProprietario);
            printf("=> Ano de Fabricação: %d\n", veiculos[i].anoFabricacao);
            printf("=> Cor: %s\n", veiculos[i].cor);
            printf("=> Marca: %s\n", veiculos[i].marca);
            printf("=> Preço: R$ %.2lf\n", veiculos[i].preco);
            printf("==============================================================\n");
            encontrados++;
        }
    }

    if (encontrados == 0)
    {
        printf("\n        🚨 Nenhum veículo da marca '%s' encontrado! 🚨        \n", marcaParaBuscar);
        printf("\n==============================================================\n");
    }
}

void filtrarVeiculoPorRenavam(struct Veiculo veiculos[], int contador)
{
    int numeroRenavam;
    int encontrado = -1;

    limparTela();
    printf("==============================================================\n");
    printf("                  BUSCAR VEÍCULO PELO RENAVAM                  \n");
    printf("==============================================================\n");

    printf("Digite o Renavam do veículo que deseja buscar: ");
    scanf("%d", &numeroRenavam);

    for (int i = 0; i < contador; i++)
    {
        if (veiculos[i].renavam == numeroRenavam)
        {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1)
    {
        printf("\n==============================================================\n");
        printf("           🚨 Veículo com Renavam %d não encontrado! 🚨       \n", numeroRenavam);
        printf("==============================================================\n");
    }
    else
    {
        struct Veiculo veiculo = veiculos[encontrado];
        printf("\n==============================================================\n");
        printf("                   DADOS DO VEÍCULO ENCONTRADO                \n");
        printf("==============================================================\n");
        printf("------------------------   Veículo %d   ----------------------\n", encontrado + 1);
        printf("=> Renavam: %d\n", veiculo.renavam);
        printf("=> Proprietário: %s\n", veiculo.nomeProprietario);
        printf("=> Ano de Fabricação: %d\n", veiculo.anoFabricacao);
        printf("=> Cor: %s\n", veiculo.cor);
        printf("=> Marca: %s\n", veiculo.marca);
        printf("=> Preço: R$ %.2lf\n", veiculo.preco);
        printf("==============================================================\n");
    }
}

void removerVeiculo(struct Veiculo veiculos[], int *contador)
{
    int renavam;
    int encontrado = -1;

    limparTela();
    printf("==============================================================\n");
    printf("                         APAGAR VEÍCULO                       \n");
    printf("==============================================================\n");

    printf("Digite o Renavam do veículo que deseja buscar: ");
    scanf("%d", &renavam);

    printf("==============================================================\n");

    for (int i = 0; i < *contador; i++)
    {
        if (veiculos[i].renavam == renavam)
        {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1)
    {
        printf("\n        🚨 Veículo com Renavam %d não encontrado! 🚨       \n", renavam);
        printf("\n==============================================================\n");
        return;
    }

    for (int i = encontrado; i < *contador - 1; i++)
    {
        veiculos[i] = veiculos[i + 1];
    }

    (*contador)--;

    printf("\n  🚗 Veículo com Renavam %d removido com sucesso! 🚗     \n", renavam);
    printf("\n==============================================================\n");
}

void sair()
{
    printf("\n");
    printf("============================================\n");
    printf("         ✅ PROGRAMA FINALIZADO ✅         \n");
    printf("============================================\n");
    printf("      Obrigado por usar nosso sistema!      \n");
    printf("                 Até logo!                  \n");
    printf("============================================\n");
    printf("\n");
}

int main()
{
    int opcao;
    int count = 6;
    struct Veiculo veiculos[MAX_VEICULOS] =
        {
            {123456789, "João Batista", 2015, "VRM", "FIAT", 35000.00},
            {987654321, "Davi Teixeira", 2020, "PRE", "HON", 200000.00},
            {123454839, "João Silva", 2015, "VRM", "FIAT", 25000.00},
            {678902342, "Maria Oliveira", 2019, "PRE", "FORD", 35000.00},
            {111211122, "Carlos Pereira", 2018, "AZL", "VW", 30000.00},
            {135794534, "Ana Costa", 2020, "AMA", "CHE", 32000.00}};

    do
    {
        mostrarMenu();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            adicionarVeiculo(veiculos, &count);
            break;
        case 2:
            listarVeiculos(veiculos, count);
            break;
        case 3:
            atualizarVeiculo(veiculos, count);
            break;
        case 4:
            filtrarVeiculosPorCor(veiculos, count);
            break;
        case 5:
            filtrarVeiculosPorMarca(veiculos, count);
            break;
        case 6:
            filtrarVeiculoPorRenavam(veiculos, count);
            break;
        case 7:
            removerVeiculo(veiculos, &count);
            break;
        case 8:
            limparTela();
            sair();
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }

        if (opcao != 8)
        {
            printf("\nPressione qualquer tecla para voltar ao menu...");
            getchar();
            getchar();
            limparTela();
        }
    } while (opcao != 9);

    return 0;
}