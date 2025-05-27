#include <stdio.h>
#include <stdlib.h>
#define MAXnome 50
#define MAXproduto 50
#define MAXvenda 100


//Estrutura do produto
struct produto
{
    char nome[MAXnome];
    int codigo;
	int Qestoque; //Quantidade em estoque
    float Pvenda;   //Preco de venda
	int Cvenda;     //Código da venda
	float Vtotal;   //Valor total da venda
};
//Leitura de strings
void ler_string ()
{
    while(getchar()!='\n');
}

//Cadastrar o produto
void cadastrar_produto (struct produto item[], int n_produto)
{
    system("cls");
    if (n_produto >=MAXproduto) //Limite na quantidade de produtos cadastrados
    {
        printf("\n\n\tO LIMITE DE PRODUTOS FOI ATINGIDO\n");
        system("pause");

    }

    else
    {


        printf("\n\n\t==== CADASTRO DE PRODUTO ====\n");

        //Codigo
        item[n_produto].codigo = n_produto; //Ter a quantidade de produtos
        printf("\tCodigo gerado: %d\n", item[n_produto].codigo);

        //Nome
        printf("\n\tNome: ");

        ler_string();
        //while(getchar()!='\n'); // CRIAR UMA FUNCAO PRA CHAMAR ESSE TRECO!!!!! ====== FEITO

       // fflush(stdin); //Limpar
        fgets(item[n_produto].nome,50,stdin);


        //Quantidade em estoque
        printf("\n\tQuantidade em estoque: ");
        scanf("%d", &item[n_produto].Qestoque);

        //Preco de venda
        printf("\n\tPreco de venda: ");
        scanf("%f", &item[n_produto].Pvenda);

        printf("\n\n\tCADASTRO REALIZADO\n\n");
        system("pause");
    }
}

//Registrar venda
void registrar_venda (struct produto item[], int n_produto, int *Codvenda)
{
    int i, correto, Qvendida, aux;      //Pensando em fazer algo perguntando se o produto do codigo esta correto
    aux = *Codvenda; //O aux recebe o valor de Codvenda, no final do void ele muda o valor e guarda na main
    do
    {
        system("cls");
        printf("\n\n\tREGISTRAR UMA VENDA\n\n");
        printf("\n\tCodigo |  Nome\n");
        for (int z=1; z<=n_produto;z++) //Mostrar produtos cadastrados
        {
            printf("\t%d      |  %s  ", item[z].codigo, item[z].nome);

        }

        printf("\nInforme o codigo do produto: ");
        scanf("%d", &i);

        //Informações do produto
        printf("\n\tNome: %s", item[i].nome);
        printf("\tPreco de venda: %.2f", item[i].Pvenda);
        printf("\n\tQuantidade em estoque: %d", item[i].Qestoque);

        //leitura de string =================================================================================== ARRUMAR
        printf("\n\tConfirmar escolha (S/N): ");
        printf("\nTEMPORARIO - Aperte 1 para prosseguir");


        scanf("%d", &correto); //Temporario ate fazer a leitura da sring


    }while (correto !=1);

    do  //Perguntar a quantidade vendida:
            {
                printf("\n\tINFORME A QUANTIDADE VENDIDA: ");
                scanf ("%d", &Qvendida);

                if (item[i].Qestoque - Qvendida <0)
                {
                    printf("\nNao ha quantidade em estoque\n\n");
                    system ("pause");
                    //system("cls");
                }
            }while (item[i].Qestoque - Qvendida <0);


    //Se nao houve venda registrada no mesmo produto:
    if (item[i].Cvenda == 0)
    {
        item[i].Cvenda = aux + 1; //Codvenda (aux) e um auxiliar para nn fazer repetir o mesmo
        aux++;

        item[i].Vtotal = 0; //Apenas na primeira vez, eu quero limpar o lixo
    }

    //Informacao sobre a venda:
    item[i].Vtotal = item[i].Vtotal + (item[i].Pvenda*Qvendida); //Valor total = valor anterior + valor novo
    item[i].Qestoque = item[i].Qestoque - Qvendida;

    system ("cls");
    printf("\n\tCodigo de venda: %d", item[i].Cvenda);
    printf("\n\tPreco de venda: %.2f", item[i].Pvenda);
    printf("\n\tQuantidade vendida: %d", Qvendida);
    printf ("\n\tQuantidade ainda em estoque: %d", item[i].Qestoque);
    printf("\n\tValor total vendido: %.2f", item[i].Vtotal);

    printf ("\n\n\tCADASTRO REALIZADO\n\n");
    system("pause");

    *Codvenda = aux; //Guardar no ponteiro
}

//Listar produtos disponivveis
void listar_produtos_disp (struct produto item[],int n_produto)
{
    system("cls");
    printf("\n\t\tLISTA DE PRODUTOS DISPONIVEIS\n\n");
   // printf("Codigo | P.venda | Quantidade disp | Nome\n");
    for (int i=1; i <= n_produto; i++)
    {
        if (item[i].Qestoque !=0) //Mostrar apenas os que estao em estoque
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

//Listar vendas
void listar_vendas (struct produto item[], int n_produto)
{
    system ("cls");

    printf ("\n\n\tLISTA DE VENDAS\n\n");
     for (int i=0; i<=n_produto; i++) //Leitura dos itens
     {
         if (item[i].Cvenda!=0)
         {
            printf("\n\tCodigo: %d", item[i].codigo);
            printf("\n\tCodigo de venda: %d", item[i].Cvenda);
            printf("\n\tNome: %s", item[i].nome);
            printf("\tPreco de venda: %.2f", item[i].Pvenda);
            printf("\n\tQuantidade em estoque: %d", item[i].Qestoque);
            printf("\n\tQuantidade vendida: %.0f", item[i].Vtotal/item[i].Pvenda); //Valor total dividido pelo valor individual
            printf("\n\tValor total vendido: %.2f", item[i].Vtotal);
            printf("\n\n=======================================================\n");

         }
     }
     system("pause");
}


//Listar produtos em falta
void listar_produtos_falt (struct produto item[], int n_produto)
{
system("cls");
    printf("\n\t\tLISTA DE PRODUTOS EM FALTA\n\n");
   // printf("Codigo | P.venda | Quantidade disp | Nome\n");
    for (int i=1; i <= n_produto; i++)
    {
        if (item[i].Qestoque ==0) //Mostrar apenas os que estao em estoque
        {
            printf("\n\tCodigo: %d", item[i].codigo);
            printf("\n\tCodigo de venda: %d", item[i].Cvenda);
            printf("\n\tNome: %s", item[i].nome);
            printf("\tPreco de venda: %.2f", item[i].Pvenda);
            printf("\n\tQuantidade em estoque: %d", item[i].Qestoque);
            printf("\n\tQuantidade vendida: %.0f", item[i].Vtotal/item[i].Pvenda);
            printf("\n\tValor total vendido: %.2f", item[i].Vtotal);
            printf("\n\n=======================================================\n");
        }
    }
    system ("pause");
}

//Relatorio
void relatorio (struct produto item[], int n_produto)  //FAZER : recebe ponteiro Codvenda e verifica se ja houve venda
{
    int opcao, i, z;
    float aux=0;
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

        switch (opcao)
        {
            case 1: //Produto mais vendido
                printf ("\n\n\tCodigo  |  Codigo de Venda |  Quantidade vendida"); //"mostrando o código de cada venda e a quantidade vendida"
                for (i=0;i<=n_produto; i++)
                {
                    if (item[i].Cvenda !=0)
                    {
                        printf("\n\t%d    |        %d        |             %.0f", item[i].codigo, item[i].Cvenda, (item[i].Vtotal/item[i].Pvenda));

                        if (aux < item[i].Vtotal/item[i].Pvenda)
                        {
                            aux = item[i].Vtotal/item[i].Pvenda;
                            z = i;
                        }
                    }
                }

                printf("\n\n\tPRODUTO MAIS VENDIDO\n");

                printf("\n\tCodigo: %d", item[z].codigo);
                printf("\n\tCodigo de venda: %d", item[z].Cvenda);
                printf("\n\tNome: %s", item[z].nome);
                printf("\tPreco de venda: %.2f", item[z].Pvenda);
                printf("\n\tQuantidade em estoque: %d", item[z].Qestoque);
                printf("\n\tQuantidade vendida: %.0f", (item[z].Vtotal/item[i].Pvenda));
                printf("\n\tValor total vendido: %.2f", item[z].Vtotal);

                printf ("\n\n");
                system ("pause");
                break;

            case 2: //Total de vendas por produto
                printf ("\n\n\tCodigo  |  Codigo de Venda |  Quantidade vendida"); //"mostrando o código de cada venda e a quantidade vendida"
                for (i=0;i<=n_produto; i++)
                {
                    if (item[i].Cvenda !=0)
                    {
                        printf("\n\t%d    |        %d        |             %.0f", item[i].codigo, item[i].Cvenda, (item[i].Vtotal/item[i].Pvenda));
                    }

                }
                system ("pause");
                break;

            case 3: //Valor total obtido com as vendas ---- colocar: codigo do produto, nome do produto, valor da venda
                printf ("\n\n\tCodigo  |  Codigo de Venda |  Quantidade vendida");
                for (i=0;i<=n_produto; i++)
                {
                    if (item[i].Cvenda !=0)
                    {
                        printf("\n\t%d    |        %d        |             %.0f", item[i].codigo, item[i].Cvenda, (item[i].Vtotal/item[i].Pvenda));
                        aux = aux + item[i].Vtotal;
                    }

                }
                printf ("\n\n\tValor total obtido com as vendas: %.2f\n\n", aux);
                system("pause");
                break;
        }

    }while (opcao !=4);
}


int main()
{

    int opcao, n_produto=0, Codvenda=0,RegVenda=0;
    struct produto item[MAXproduto];

    //For zerando todos os codigos de venda
    for (int i=0; i<MAXproduto; i++)
    {
        item[i].Cvenda = 0;
    }

    //Codigo
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
           n_produto++;
           cadastrar_produto(item, n_produto); //"item" está é a variavel da struct declarada no comeco do main, e n_produto serve para controle de quantidade

           break;

        case 2:
            if (RegVenda <MAXvenda) //"o número máximo de vendas é de 100"
            {
                registrar_venda(item, n_produto, &Codvenda); //Usar ponteiro no Codvenda
            }
            else
            {
                printf ("\n\n\tLIMITE DE VENDAS ATINGIDO");
            }
            break;

        case 3:
            listar_produtos_disp(item, n_produto);
            break;

        case 4:
            listar_vendas(item, n_produto);
            break;

        case 5:
            listar_produtos_falt(item, n_produto);
            break;

        case 6:
            relatorio(item, n_produto);
            break;

        }

    system("cls");
  }while (opcao!=7); // Repetir enquanto a opcao 7 for escolhidda

	return 0;
}


/*
Fazer no codigo:
1 - Fazer mais de uma venda antes de voltar pra tela (improvavel)
2 - Arrumar a string na confirmacao de venda

Se não tiver produto vendido, avisar o usuario

Dificuldades:
1 - Acumulo de matéria do semestre
    descricao: juncao de todo coteudo aprendido no semestre dentro de 1 unico projeto
    solucao: revisao aprofundada do conteudo
*/
