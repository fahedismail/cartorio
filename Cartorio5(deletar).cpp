#include <stdio.h> // biblioteca de comunicaco com o ususario
#include <stdlib.h> //biblioteca 
#include <locale.h> // biblioteca
#include <string.h> //biblioteca responsavel por cuida da string


int registro() // funcao responsavel por cadastrar os ususarios no sistema
{ 
 // inicio criacao de variabeis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
	char sobrenome[40];
    char cargo[40];
 // final criacao de variabeis/string

printf("Digite o CPF a ser cadastrado"); // coletando informacao do usuarios
scanf("%s", cpf); //%s refere-se a string 

strcpy(arquivo, cpf); // responsavel por copia os valores das string

FILE *file; // cria o arquivo
file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
fprintf(file, cpf); // salvo o valor da variavel
fclose(file); // fecha o arquivo

file = fopen(arquivo, "a");
fprintf(file, ",");
fclose(file);

printf("Digite o nome a ser cadastrado: ");
scanf("%s",nome);

file = fopen(arquivo, "a");
fprintf(file,nome);
fclose(file);

printf("digite o sobrenome a ser cadastrado: ");
scanf("%s",sobrenome);

file = fopen(arquivo, "a");
fprintf(file,sobrenome);
fclose(file);


printf("digite o cargo a ser cadastrado: ");
scanf("%s",cargo);

file = fopen(arquivo, "a");
fprintf(file,cargo);
fclose(file);

system("pause");

}

int consulta()
{ 
  char cpf[40];
  char conteudo[200];
  
  printf("digite o CPF a ser consultado: ");
  scanf("%s", cpf);
  
  FILE *file;
  file = fopen(cpf,"r");
  
  if(file == NULL)
  {
  	printf("nao foi possivel abrir o arquivo, nao localizado!.\n");
  }
  
  while(fgets(conteudo, 200, file) != NULL)
  {
  	printf("\nEssas sao as informacoes do usuario: ");
  	printf("%s", conteudo);
  	printf("\n\n");
  }
  
  system("pause");
  fclose(file);
  
}

int deletar()
{ 
     char cpf[40];
     printf("Digite o CPf a ser deletado: ");
     scanf("%s",cpf);
     
     remove(cpf);
     
     FILE * file;
     file = fopen(cpf, "r");
     
     if(file == NULL)
	 {
         printf("o usuario nao se econtra no sistema!. \n");
		 system("pause");	
	 }
}

int main ()
 {
	int opcao=0; //Definindo variáveis
    int laco=1;
    
    for(laco=1;laco=1;) 
    {

system("cls");

 setlocale(LC_ALL,"Portuguese");  // Definindo a linguagem
 
 printf("### Cartorio do EBAC ###\n\n"); //inicio do menu
 printf("Escolha a opcao desejada do menu:\n\n");
 printf("\t1 - Registar o nome\n");
 printf("\t2 - Consultar o nome\n");
 printf("\t3 - Deletar o nome\n\n"); 
 printf("Opcao: "); // fim do menu
 
 scanf("%d", &opcao); //armazenando a escolha do usuário
 
system("cls"); //responsavel por limpar a tela
 
switch(opcao) // inicio da selecao do menu
 {
 	 case 1:
     registro(); // chamada de funcao
 	 break;
 	 
 	 case 2:
 	 consulta();
 	 break;
 	 
	 case 3:
	 deletar();
 	 break;		
 	
 	 default:
	 printf("Essa opcao näo está disponivel\n");
	 system("pause");
	 break;
}
//fim da selecao
}
}
