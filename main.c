#include <stdio.h>
#include <stdlib.h>
#define Nnome 49

struct produto
{
    char nome [Nnome];
    int codigo;
	int Qestoque;
    float Pvenda;
	int Cvenda;
	float Vtotal;
};

int leitura (int item)
{


    return 0;
}

int main()
{
    int i, opcao=0;

    do {

        printf("\n\n\t\tBEM VINDO!!");
        printf("\n\t1 - Cadastrar um Produto");
        printf("\n\t2 - Registrar uma Venda");
        printf("\n\t3 - Lista de Produtos Disponíveis");
        printf("\n\t4 - Lista de Vendas");
        printf("\n\t5 - Relatório");
        printf("\n\t6 - Fechar o programa");

        printf("\n\n\t\tEscolha uma das opcoes: ");
        scanf("%d", &opcao);

        switch(opcao)
        {
        case 1:




        }




    }while (opcao!=6);


	system("pause");
	return 0;
}
