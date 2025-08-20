#include <stdio.h>
#include <stdlib.h>
#define MAXnome 50
#define MAXproduto 50
#define MAXvenda 100



struct produto
{
    char nome[MAXnome];
    int codigo;
	int Qestoque;
    float Pvenda;

};
struct st_venda
{
    int Cvenda;
    struct produto prod;
    float Vtotal;

};


void ler_string ()
{
    while(getchar()!='\n');
}

void cadastrar_produto (struct produto item[], int n_produto)
{
    system("cls");
    if (n_produto >=MAXproduto)
    {
        printf("\n\n\tO LIMITE DE PRODUTOS FOI ATINGIDO\n");
        system("pause");

    }

    else
    {


        printf("\n\n\t==== CADASTRO DE PRODUTO ====\n");


        item[n_produto].codigo = n_produto;
        printf("\tCodigo gerado: %d\n", item[n_produto].codigo);


        printf("\n\tNome: ");

        ler_string();

        fgets(item[n_produto].nome,50,stdin);



        printf("\n\tQuantidade em estoque: ");
        scanf("%d", &item[n_produto].Qestoque);


        printf("\n\tPreco de venda: ");
        scanf("%f", &item[n_produto].Pvenda);

        printf("\n\n\tCADASTRO REALIZADO\n\n");
        system("pause");
    }
}

void registrar_venda (struct produto item[], int n_produto, int *Codvenda, struct st_venda venda[])
{
    int i, Qvendida, n_venda;
    char correto = 'S';
    n_venda = *Codvenda;

    do
    {
        do
        {
            system("cls");
            printf("\n\n\tREGISTRAR UMA VENDA\n\n");
            printf("\n\tCodigo |  Nome\n");
            for (int z=0; z<n_produto;z++)
            {
                printf("\t%d      |  %s  ", item[z].codigo, item[z].nome);

            }

            printf("\nInforme o codigo do produto: ");
            scanf("%d", &i);



            printf("\n\tNome: %s", item[i].nome);
            printf("\tPreco de venda: %.2f", item[i].Pvenda);
            printf("\n\tQuantidade em estoque: %d", item[i].Qestoque);


            printf("\n\tConfirmar escolha (S/N): ");

            ler_string();
            scanf("%c", &correto);

            if ((correto != 's') && (correto != 'S') && (correto != 'n')&&(correto !='N'))
            {
                printf("\n\tDIGITE SOMENTE S PARA SIM OU N PARA N�O\n\n");
                system ("pause");
            }




        }while (correto != 's' && correto != 'S');


        printf("\n\tINFORME A QUANTIDADE VENDIDA: ");
        scanf ("%d", &Qvendida);

        if (item[i].Qestoque - Qvendida <0)
        {
                printf("\n\tNao ha quantidade em estoque\n\n");
                system ("pause");

        }
        if (Qvendida<0)
        {
            printf("\n\tQUANTIDADE INVALIDA\n\n");
            system("pause");

        }
    }while (item[i].Qestoque - Qvendida <0 || Qvendida <0);


    venda[n_venda].Cvenda = n_venda;
    venda[n_venda].prod = item[i];
    venda[n_venda].Vtotal = (item[i].Pvenda*Qvendida);

    item[i].Qestoque = item[i].Qestoque - Qvendida;

    system ("cls");
    printf("\n\tCodigo de venda: %d", venda[n_venda].Cvenda);
    printf("\n\tPreco de venda: %.2f", item[i].Pvenda);
    printf("\n\tQuantidade vendida: %d", Qvendida);
    printf ("\n\tQuantidade ainda em estoque: %d", item[i].Qestoque);
    printf("\n\tValor total vendido: %.2f", venda[n_venda].Vtotal);

    printf ("\n\n\tCADASTRO REALIZADO\n\n");
    system("pause");

    n_venda++;
    *Codvenda = n_venda;
}

void listar_produtos_disp (struct produto item[],int n_produto)
{
    system("cls");
    printf("\n\t\tLISTA DE PRODUTOS DISPONIVEIS\n\n");

    for (int i=0; i < n_produto; i++)
    {
        if (item[i].Qestoque !=0)
        {
            printf("\n\tCodigo: %d", item[i].codigo);
            printf("\n\tNome: %s", item[i].nome);
            printf("\tPreco de venda: %.2f", item[i].Pvenda);
            printf("\n\tQuantidade em estoque: %d", item[i].Qestoque);
            printf("\n\n=======================================================\n");
        }
    }
    system ("pause");

}

void listar_vendas (int *Codvenda, struct st_venda venda[])
{
    system ("cls");

    int n_vendas = *Codvenda;

    printf ("\n\n\tLISTA DE VENDAS\n\n");
     for (int i=0; i<n_vendas; i++)
     {

            printf("\n\tCodigo de venda: %d", venda[i].Cvenda);
            printf("\n\tCodigo do produto: %d", venda[i].prod.codigo);
            printf("\n\tNome: %s", venda[i].prod.nome);
            printf("\tPreco de venda: %.2f", venda[i].prod.Pvenda);
            printf("\n\tQuantidade vendida: %.0f", venda[i].Vtotal/venda[i].prod.Pvenda);
            printf("\n\tValor total vendido: %.2f", venda[i].Vtotal);
            printf("\n\n=======================================================\n");


     }
     system("pause");
}

void listar_produtos_falt (struct produto item[], int n_produto)
{
system("cls");
    printf("\n\t\tLISTA DE PRODUTOS EM FALTA\n\n");

    for (int i=1; i < n_produto; i++)
    {
        if (item[i].Qestoque ==0)
        {
            printf("\n\tCodigo: %d", item[i].codigo);

            printf("\n\tNome: %s", item[i].nome);
            printf("\tPreco de venda: %.2f", item[i].Pvenda);
            printf("\n\tQuantidade em estoque: %d", item[i].Qestoque);

            printf("\n\n=======================================================\n");
        }
    }
    system ("pause");
}


void relatorio (struct produto item[], struct st_venda vendas[], int *Codvenda, int n_produto)
{
    int opcao, i, z;
    int n_venda = *Codvenda;
    int maior_quantidade = 0;
    int item_maisVendido = 0;
    float soma_valor_total =0;

    do
    {
        system ("cls");
        printf("\n\n\t\tRELATORIO\n");
        printf("\n\t1 - Produto mais vendido");
        printf("\n\t2 - Total de vendas por produto");
        printf("\n\t3 - Valor total obtido com as vendas");
        printf("\n\t4 - Sair do relatorio");

        printf("\n\tESCOLHA UMA DAS OPCOES: ");
        scanf("%d", &opcao);

        if (n_venda == 0 && opcao >= 1 && opcao <= 3)
            {
                printf("\n\n\tNenhuma venda registrada!\n");
                system("pause");
                continue;
            }

        switch (opcao)
        {
            case 1:


                for (int j = 0; j < n_produto; j++)
                    {
                        int soma = 0;


                        for (int i = 0; i < n_venda; i++)
                        {
                            if (vendas[i].prod.codigo == item[j].codigo)
                            {
                                soma = soma + (vendas[i].Vtotal / vendas[i].prod.Pvenda);
                            }
                        }
                        if (soma > maior_quantidade)
                        {
                            maior_quantidade = soma;
                            item_maisVendido = j;
                        }
                }

                printf("\n\tProduto mais vendido: \n");
                printf("\n\tCodigo do produto: %d", item[item_maisVendido].codigo);
                printf("\n\tNome: %s", item[item_maisVendido].nome);
                printf("\tQuantidade vendida: %d\n\n", maior_quantidade);

                system("pause");
                break;

            case 2:


                for (int z=0; z<n_produto; z++)
                {
                    float soma_valor=0;
                    int soma_quantidade=0;

                    for (int i=0; i<n_venda; i++)
                    {
                        if (vendas[i].prod.codigo == item[z].codigo)
                        {
                            soma_quantidade = soma_quantidade + (vendas[i].Vtotal / vendas[i].prod.Pvenda);
                            soma_valor = soma_valor + vendas[i].Vtotal;
                        }
                    }
                    if (soma_valor > 0 || soma_quantidade >0)
                        {
                            printf("\n\tCodigo do produto: %d", item[z].codigo);
                            printf ("\n\n\tNome: %s", item[z].nome);
                            printf ("\tTotal: R$ %.2f", soma_valor);
                            printf ("\n\tQuantidade vendida: %d", soma_quantidade);
                            printf("\n\n=======================================================\n");
                        }
                }

                system ("pause");
                break;

            case 3:

                printf("\n\tCodigo Produto | Valor das vendas | Nome\n");
                for (int z=0; z<n_produto; z++)
                {
                    float soma_valor=0;
                    int soma_quantidade=0;


                    for (int i=0; i<n_venda; i++)
                    {
                        if (vendas[i].prod.codigo == item[z].codigo)
                        {
                            soma_quantidade = soma_quantidade + (vendas[i].Vtotal / vendas[i].prod.Pvenda);
                            soma_valor = soma_valor + vendas[i].Vtotal;

                        }
                    }
                    if (soma_valor > 0 || soma_quantidade >0)
                        {
                            printf("\t      %d        |       %.2f      | %s", item[z].codigo, soma_valor, item[z].nome);
                            soma_valor_total = soma_valor_total + soma_valor;
                        }
                }
                printf("\n\n\tSoma total: %.2f\n\n", soma_valor_total);
                system("pause");
                break;

        }

    }while (opcao !=4);
}


int main()
{

    int opcao, n_produto=0, Codvenda=0,RegVenda=0;
    struct produto item[MAXproduto];
    struct st_venda venda[MAXvenda];


    do {

        printf("\n\n\t\tBEM VINDO!!\n");
        printf("\n\t1 - Cadastrar um Produto");
        printf("\n\t2 - Registrar uma Venda");
        printf("\n\t3 - Lista de Produtos Disponiveis");
        printf("\n\t4 - Lista de Vendas");
        printf("\n\t5 - Listar Produtos em Falta");
        printf("\n\t6 - Relatorio");
        printf("\n\t7 - Fechar o programa");

        printf("\n\n\t\tEscolha uma das opcoes: ");
        scanf("%d", &opcao);

        switch(opcao)
        {

        case 1:

           cadastrar_produto(item, n_produto);
            n_produto++;
           break;

        case 2:
            if (RegVenda <MAXvenda)
            {
                registrar_venda(item, n_produto, &Codvenda, venda);
            }
            else
            {
                printf ("\n\n\tLIMITE DE VENDAS ATINGIDO");
            }
            break;
//aaaaa
        case 3:
            listar_produtos_disp(item, n_produto);
            break;

        case 4:
            listar_vendas(&Codvenda, venda);
            break;

        case 5:
            listar_produtos_falt(item, n_produto);
            break;

        case 6:
            relatorio(item, venda, &Codvenda, n_produto);
            break;

        }

    system("cls");
  }while (opcao!=7);

	return 0;
}

