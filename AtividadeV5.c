#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Livro
{
    int numeroLivro;
    int quantPag;
    double valorReal;
    double valorAlterar;
    // valorReal * 4.30;
};

struct RepositorioLivro
{
    struct Livro livros[100];
    int proxLivro;
};

struct RepositorioLivro CriarRepositorio(struct Livro *livros)
{
    int i;
    struct RepositorioLivro repositorioTemp;

    for (i = 0; i < sizeof(livros) / sizeof(livros[0]); i++)
    {
        repositorioTemp.livros[i] = livros[i];
    }

    repositorioTemp.proxLivro = 0;

    return repositorioTemp;
}

struct Livro criarLivro(int numeroLivro, int quantPag, double valorReal)
{
    struct Livro livroTemp;

    livroTemp.numeroLivro = numeroLivro;
    livroTemp.quantPag = quantPag;
    livroTemp.valorReal = valorReal;

    return livroTemp;
}

void cadastrarLivro(struct RepositorioLivro *LivrariaBIG, struct Livro *livros)
{
    LivrariaBIG->livros[LivrariaBIG->proxLivro] = *livros;
    LivrariaBIG->livros[LivrariaBIG->proxLivro].numeroLivro;
    // = LivrariaBIG->livros[LivrariaBIG->proxLivro - 1].numeroLivro + 1;
    LivrariaBIG->proxLivro++;
}

void visualizarLivros(struct RepositorioLivro *LivrariaBIG)
{
    int i;
    int proxLivro;
    system("cls");
    printf("____________________ LivrariaBIG ____________________\n\n");
    printf("________________| Livros Cadastrados |_______________\n\n");
    for (i = 0; i < LivrariaBIG->proxLivro; i++)
    {
        printf("Numero do Livro: %d\n\n", LivrariaBIG->livros[i].numeroLivro);
        printf("Quantidade de Paginas do Livro: %d\n\n", LivrariaBIG->livros[i].quantPag);
        printf("Valor do livro (em real): R$%.2lf\n\n", LivrariaBIG->livros[i].valorReal);
        printf("Valor do livro (em dolar): $%.2lf\n\n", LivrariaBIG->livros[i].valorReal * 4.30);
        printf("_____________________________________________________\n\n\n");
    }
}

void RegistrarLivro(struct RepositorioLivro *LivrariaBIG, int numeroLivro, int quantPag, double valorReal)
{
    LivrariaBIG->livros[LivrariaBIG->proxLivro].numeroLivro = numeroLivro;
    LivrariaBIG->livros[LivrariaBIG->proxLivro].quantPag = quantPag;
    LivrariaBIG->livros[LivrariaBIG->proxLivro].valorReal = valorReal;

    if (LivrariaBIG->proxLivro != 0)
    {
        LivrariaBIG->livros[LivrariaBIG->proxLivro].numeroLivro = LivrariaBIG->livros[LivrariaBIG->proxLivro - 1].numeroLivro + 1;
    }
    LivrariaBIG->proxLivro++;
}

void editarLivro(struct RepositorioLivro *LivrariaBIG)
{
    int i, j, erro = 0;
    char novoLivro[100];
    double novoValor;
    int numLivro;

    printf("____________________ Livraria BIG ____________________\n\n");
    printf("_______________| Livros Cadastrados |________________\n\n");
    for (i = 0; i < LivrariaBIG->proxLivro; i++)
    {
        printf("Numero do livro: %d\n\n", LivrariaBIG->livros[i].numeroLivro);
        printf("Quantidade de paginas do livro: %d\n\n", LivrariaBIG->livros[i].quantPag);
        printf("Valor do livro (em real): R$%.2lf\n\n", LivrariaBIG->livros[i].valorReal);
        printf("Valor do livro (em dolar): $%.2lf\n\n", LivrariaBIG->livros[i].valorReal * 4.30);
        printf("_____________________________________________________\n\n\n");
    }

    printf("Informe o numero do livro que deseja editar as informacoes: \n");
    scanf("%d", &numLivro);

    system("cls");

    for (i = 0; i < LivrariaBIG->proxLivro; i++)
    {

        if (LivrariaBIG->livros[i].numeroLivro == numLivro)
        {
            erro = 1;
            printf("Informe um novo valor para o livro (em reais): \n");
            scanf("%lf", &novoValor);

            system("cls");
            LivrariaBIG->livros[i].valorReal = novoValor;

            printf("____________________ Livraria BIG ____________________\n\n");
            printf("__________________| Livro Editado |__________________\n\n");
            printf("Numero do livro: %d\n\n", LivrariaBIG->livros[i].numeroLivro);
            printf("Quantidade de paginas do livro: %d\n\n", LivrariaBIG->livros[i].quantPag);
            printf("Valor do livro (em real): R$%.2lf\n\n", novoValor);
            printf("Valor do livro (em dolar): $%.2lf\n\n", novoValor * 4.30);
            printf("_____________________________________________________\n\n\n");
        }
    }
    if (erro = 0)
    {
        printf("________________ Livraria BIG ________________\n\n");
        printf("            |Livro nao encontrado|\n\n");
        printf("_____________________________________________\n\n\n");
    }
}

void PreCadastrados(struct RepositorioLivro *LivrariaBIG)
{
    RegistrarLivro(LivrariaBIG, 1, 200, 10);
}

void Fim()
{
    printf("____________________ Livraria BIG ____________________\n\n");
    printf("- Desenvolvido por: \n\n");
    printf(" Henrique de Almeida Silva. \n\n");
    printf(" version 0.1.0  \t-\t 05/08/2022\n");
    printf("_____________________________________________________\n\n");
}

int main()
{
    struct Livro livros[100];
    struct RepositorioLivro LivrariaBIG = CriarRepositorio(livros);
    int numeroLivro;
    int i, quantPag;
    double valorReal, valorDolar, valor;

    PreCadastrados(&LivrariaBIG);
    int opcao = 0;

    do
    {
        printf("____________________ Locadora HI ____________________\n\n");
        printf("_____________________| Filmes |______________________\n\n");
        printf("1 - Cadastrar livro.\n");
        printf("2 - Editar livro.\n");
        printf("3 - Buscar livro.\n");
        printf("4 - Sair.\n");
        printf("_____________________________________________________\n\n");
        printf("- Informe uma opcao: ");
        scanf("%d", &opcao);
        system("cls");

        switch (opcao)
        {
        case 1:

            printf("Digite o numero do livro: ");
            scanf(" %d", &numeroLivro);

            printf("Digite a quantidade de paginas do livro: ");
            scanf("%d", &quantPag);

            printf("Digite o valor do livro (em real): ");
            scanf(" %lf", &valorReal);

            system("cls");
            valorDolar = valorReal * 4.30;

            struct Livro livros = criarLivro(numeroLivro, quantPag, valorReal);
            printf("____________________ LivrariaBIG ____________________\n\n");
            printf("_____________________| Livros |______________________\n\n");
            printf("Numero do livro: %d\n\n", numeroLivro);
            printf("Quantidade de paginas do livro: %d\n\n", quantPag);
            printf("Valor do livro (em real): R$%.2lf\n\n", valorReal);
            printf("Valor do livro (em dolar): $%.2lf\n\n", valorDolar);
            printf("_____________________________________________________\n\n");
            cadastrarLivro(&LivrariaBIG, &livros);

            system("pause");
            system("cls");

            do
            {
                printf("____________________ LivrariaBIG ____________________\n\n");
                printf("1 - Mudar valor do livro.\n");
                printf("2 - Sair.\n");
                printf("_____________________________________________________\n\n");
                printf("- Informe uma opcao: ");
                scanf("%d", &opcao);
                system("cls");
                switch (opcao)
                {
                case 1:
                    editarLivro(&LivrariaBIG);
                    break;
                    system("pause");
                    system("cls");
                }

            } while (opcao != 2);
            break;
        case 2:
            editarLivro(&LivrariaBIG);
            break;
            system("pause");
            system("cls");
        case 3:
            visualizarLivros(&LivrariaBIG);
            system("pause");
            system("cls");
            break;
        }
    } while (opcao != 4);

    system("cls");
    Fim();

    return 0;
}
