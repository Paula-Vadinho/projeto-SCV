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

};
struct st_venda
{
    int Cvenda;     //Código da venda
    struct produto prod;
    float Vtotal;   //Valor total da venda

};

//Limpar buffer
void ler_string ()
{
    while(getchar()!='\n');
}
//========================================================================================================================================

//                                                      Cadastrar o produto -- Funcionando

//========================================================================================================================================
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
//========================================================================================================================================

//                                                      Registrar venda  -- Corrigido

//========================================================================================================================================
void registrar_venda (struct produto item[], int n_produto, int *Codvenda, struct st_venda venda[])
{
    int i, Qvendida, n_venda;      //Pensando em fazer algo perguntando se o produto do codigo esta correto
    char correto = 'S';
    n_venda = *Codvenda; //O n_venda recebe o valor de Codvenda, no final do void ele muda o valor e guarda na main
    do
    {
        system("cls");
        printf("\n\n\tREGISTRAR UMA VENDA\n\n");
        printf("\n\tCodigo |  Nome\n");
        for (int z=0; z<n_produto;z++) //Mostrar produtos cadastrados
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
       // printf("\nTEMPORARIO - Aperte 1 para prosseguir: ");

        ler_string();
        scanf("%c", &correto); //Temporario ate fazer a leitura da sring

        if ((correto != 's') && (correto != 'S') && (correto != 'n')&&(correto !='N'))
        {
            printf("\n\tDIGITE SOMENTE S PARA SIM OU N PARA NÃO\n\n");
            system ("pause");
        }




    }while (correto != 's' && correto != 'S');

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


    venda[n_venda].Cvenda = n_venda;  //Define o código do produto
    venda[n_venda].prod = item[i]; //Guarda as informações do produto dentro da venda
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
    *Codvenda = n_venda; //Guardar no ponteiro
}
//========================================================================================================================================

//                                                      Listar produtos disponiveis - Funcionando

//========================================================================================================================================
void listar_produtos_disp (struct produto item[],int n_produto)
{
    system("cls");
    printf("\n\t\tLISTA DE PRODUTOS DISPONIVEIS\n\n");
   // printf("Codigo | P.venda | Quantidade disp | Nome\n");
    for (int i=0; i < n_produto; i++)
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
//========================================================================================================================================

//                                                  Listar vendas  - Corrigido

//========================================================================================================================================
void listar_vendas (int *Codvenda, struct st_venda venda[])
{
    system ("cls");

    int n_vendas = *Codvenda;

    printf ("\n\n\tLISTA DE VENDAS\n\n");
     for (int i=0; i<n_vendas; i++) //Leitura dos itens
     {

            printf("\n\tCodigo de venda: %d", venda[i].Cvenda);
            printf("\n\tCodigo do produto: %d", venda[i].prod.codigo);
            printf("\n\tNome: %s", venda[i].prod.nome);
            printf("\tPreco de venda: %.2f", venda[i].prod.Pvenda);
//            printf("\n\tQuantidade em estoque: %d", item[i].Qestoque);
            printf("\n\tQuantidade vendida: %.0f", venda[i].Vtotal/venda[i].prod.Pvenda); //Valor total dividido pelo valor individual
            printf("\n\tValor total vendido: %.2f", venda[i].Vtotal);
            printf("\n\n=======================================================\n");


     }
     system("pause");
}
//========================================================================================================================================

//                                              Listar produtos em falta  - Funcionando

//========================================================================================================================================
void listar_produtos_falt (struct produto item[], int n_produto)
{
system("cls");
    printf("\n\t\tLISTA DE PRODUTOS EM FALTA\n\n");
   // printf("Codigo | P.venda | Quantidade disp | Nome\n");
    for (int i=1; i < n_produto; i++)
    {
        if (item[i].Qestoque ==0) //Mostrar apenas os que estao em estoque
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

//========================================================================================================================================

//                                      Relatorio

//========================================================================================================================================

void relatorio (struct produto item[], struct st_venda vendas[], int *Codvenda, int n_produto)
{
    int opcao, i, z;
    int n_venda = *Codvenda;
    int maior_quantidade = 0; //Usado case 1
    int item_maisVendido = 0; //Usado case 1
    int soma_valor_total =0; //Usado case 3

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
            case 1: //Produto mais vendido


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
                        if (soma > maior_quantidade) {
                            maior_quantidade = soma;
                            item_maisVendido = j;
                    }
                }

                printf("\n\tProduto mais vendido: \n");
                printf("\nCodigo do produto: %d", item[z].codigo);
                printf("\n\tNome: %s", item[item_maisVendido].nome);
                printf("\tQuantidade: %d\n\n", maior_quantidade);

                system("pause");
                break;

            case 2: //Total de vendas por produto


                for (int z=0; z<n_produto; z++)
                {
                    float soma_valor=0;
                    int soma_quantidade=0;

                    for (int i=0; i<n_venda; i++)  // Segura o produto e analisa todas as vendas
                    {
                        if (vendas[i].prod.codigo == item[z].codigo)  // Se o codigo dentro da venda for igual ao codigo do produto... soma
                        {
                            soma_quantidade = soma_quantidade + (vendas[i].Vtotal / vendas[i].prod.Pvenda);
                            soma_valor = soma_valor + vendas[i].Vtotal;
                        }
                    }
                    if (soma_valor > 0 || soma_quantidade >0)
                        {
                            printf("\nCodigo do produto: %d", item[z].codigo);
                            printf ("\n\n\tNome: %s", item[z].nome);
                            printf ("\tTotal: R$ %.2f", soma_valor);
                            printf ("\n\tQuantidade : %d", soma_quantidade);
                            printf("\n\n=======================================================\n");
                        }
                }

                system ("pause");
                break;

            case 3: //Valor total obtido com as vendas ---- colocar: codigo do produto, nome do produto, valor da venda

                printf("\n\tCodigo Produto | Valor das vendas | Nome\n");
                for (int z=0; z<n_produto; z++)
                {
                    float soma_valor=0;
                    int soma_quantidade=0;


                    for (int i=0; i<n_venda; i++)  // Segura o produto e analisa todas as vendas
                    {
                        if (vendas[i].prod.codigo == item[z].codigo)  // Se o codigo dentro da venda for igual ao codigo do produto... soma
                        {
                            soma_quantidade = soma_quantidade + (vendas[i].Vtotal / vendas[i].prod.Pvenda);
                            soma_valor = soma_valor + vendas[i].Vtotal;

                        }
                    }
                    if (soma_valor > 0 || soma_quantidade >0)
                        {
                            printf("\t      %d        |       %.2f       | %s", item[z].codigo, soma_valor, item[z].nome);
                            soma_valor_total = soma_valor_total + soma_valor;
                        }
                }
                printf("\n\n\tSoma total: %.2f\n\n", soma_valor_total);
                system("pause");
                break;

        }

    }while (opcao !=4);
}
//========================================================================================================================================

//                                                             MAIN

//========================================================================================================================================

int main()
{

    int opcao, n_produto=0, Codvenda=0,RegVenda=0;
    struct produto item[MAXproduto];
    struct st_venda venda[MAXvenda];

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

           cadastrar_produto(item, n_produto); //"item" está é a variavel da struct declarada no comeco do main, e n_produto serve para controle de quantidade
            n_produto++;
           break;

        case 2:
            if (RegVenda <MAXvenda) //"o número máximo de vendas é de 100"
            {
                registrar_venda(item, n_produto, &Codvenda, venda); //Envia a struct item, a quantidade de produtos cadastrados, a quantidade de vendas realziadas, e a struct venda
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
            listar_vendas(&Codvenda, venda); // Envia a quantidade de vendas realizadas (posicao do ponteiro) e a struct venda
            break;

        case 5:
            listar_produtos_falt(item, n_produto);
            break;

        case 6:
            relatorio(item, venda, &Codvenda, n_produto);
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
Falta case 3 do relatório
Falta leitura de string e confimação de venda
Arrumar quando vende produto que não tem em estoque

Gerar código aleatorio

Se não tiver produto vendido, avisar o usuario

Dificuldades:
1 - Acumulo de matéria do semestre
    descricao: juncao de todo coteudo aprendido no semestre dentro de 1 unico projeto
    solucao: revisao aprofundada do conteudo

2- Confusão com as structs
    descricao: uso apenas da struct produto
    solicao: Estudo com materia na internet
*/
