#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca respons�vel por aloca��o de espa�os de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	printf("Voc� escolheu o registro de nomes \n\n");	

	//in�cio da cria��o de vari�veis/string	
	char arquivo[40];
	char cpf[40]; //criando uma string cpf do tipo 40 (que seriam 40 caracteres) n�o precisa igualar a zero, o programa faz isso sozinho
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	//final da cria��o de vari�veis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s ir� salvar dentro de uma string
	
	strcpy(arquivo, cpf); //string copy, puxando do cpf para o arquivo, respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	//est� falando para o sistema procurar dentro das bibliotecas alguma estrutura que chama file porque a gente vai criar um arquivo 
	//acessa o FILE e cria o comando *file
	//FILE � uma fun��o j� existente, n�o inventamos, j� sabemos como usar. � como dizer: acessa o FILE porque vamos criar um arquivo
	//n�o falamos do que o *file � composto, ent�o:
	file = fopen(arquivo, "w"); //cria o arquivo e o w significa escrever
	//fopen: abrir o arquivo. abre o arquivo com o nome que estiver dentro dessa vari�vel e � um arquivo novo, ent�o � write
	fprintf(file,"\n CPF: ");
	fprintf(file,cpf); //salvo o valor da vari�vel
	//fprintf dentro do arquivo, ao inv�s de mostrar para o usu�rio, est� salvando dentro do arquvo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" � para atualizar a informa��o, adicionar
	fprintf(file,"\n Nome: "); //coloca uma v�rgula para separar
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,"\n Sobrenome: "); 
	fclose(file);
	
	printf ("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,"\n Cargo: "); 
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fprintf(file, "\n\n");
	fclose(file);
	
	system("pause");	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	printf("Voc� escolheu a consulta de nomes \n\n");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //r de read, ler o arquivo
	
	if(file == NULL) //se o arquivo n�o existe, for nulo
	{
		printf("\n N�o foi poss�vel abrir, arquivo n�o localizado \n\n");
	}
	
	printf("\n Essas s�o as informa��es do usu�rio: \n");
	
	while(fgets(conteudo, 200, file) != NULL) //"enquanto", la�o de repeti��o. est� salvando na vari�vel conte�do (na string) os 200 caract�res que est�o dentro do arquivo e � pra parar quando for nulo (quando n�o achar, � nulo, n�o se encaixa na regra)
	//fgets: indo buscar o arquivo
	{
		printf("%s", conteudo);
	}
	
	fclose(file);
	system("pause");
}

int deletar()
{
	printf("Voc� escolheu deletar nomes \n\n");	
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\n Usu�rio n�o encontrado \n\n");
		system("pause");
		fclose(file);
	}
	
	else
	{
		remove(cpf); //essa fun��o serve apenas para deletar, n�o retorna uma valida��o para o usu�rio
		printf("\n Usu�rio deletado com sucesso \n\n");
		system("pause");
		fclose(file);
	}
		
	
}


int main()
{
	int opcao=0; //definindo vari�veis para a escolha do menu
	//a vari�vel aloca um espa�o de mem�ria, ent�o um pedacinho da mem�ria do computador se chama "opcao" e ela come�a do 0 se n�o pode ficar um valor vari�vel de mem�ria. para avisar ao computador que aquela vari�vel n�o est� livre 
	int laco=1; //definindo vari�veis para voltar para o menu, repeti��o
	//for (laco=1 ; laco=10 ; laco++) -> "for" faz com que fa�a/repita todas vezes que eu pedir
	//laco=1 a entrada quando for 1; laco=10 a sa�da quando for 10; laco++ toda vez que o programa entrar no la�o vai aumentar em 1 o valor da vari�vel
	//mas para n�o encerrar o programa, deixamos que comece em laco=1 e continue em laco=1, sem incremento
	char senhadigitada[10]="a";
	int comparacao;
	
	setlocale(LC_ALL, "Portuguese");
	printf("Cart�rio da EBAC \n\n");
	printf("Login de administrador \n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0) //como o valor � igual ele salva igual a 0
	{
		system("cls");
		
		for(laco=1;laco=1;)
		{
			system("cls"); //comando para limpar a tela
		
			setlocale(LC_ALL, "Portuguese"); //definir o local para conseguir usar os acentos

			printf("Cart�rio da EBAC \n\n"); //in�cio do menu
			printf("Digite a op��o desejada do menu: \n\n");
			printf("\t 1 - Registrar nomes \n");
			printf("\t 2 - Consultar nomes \n");
			printf("\t 3 - Deletar nomes \n"); 
			printf("\t 4 - Sair do sistema \n\n");
			printf("Op��o: ");//fim do menu
			//\n pr�xima linha. \t espa�amento, margem  
	
			scanf ("%d", &opcao); //armazenando as informa��es, a escolha do usu�rio
			//scanf tem como objetivo scanear o que o usu�rio coloca. %d armazena uma vari�vel do tipo inteiro. indicar em qual vari�vel armazenar, no caso opcao, adicionando um & antes
	
			system("cls"); //ap�s o usu�rio escolher a op��o, o sistema deleta todas as mensagens anteriores
		
			switch(opcao) //in�cio da sele��o do menu
			{
				case 1: //switch case usa o : como uma chave {}
				registro(); //chamada de fun��es
				break; //break fecha as chaves do switch case, mostra quando acaba. ; porque � uma instru��o
			
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema \n\n");
				return 0; //retorna valor 0: quebra la�o, qubra fun��o, etc.
				break;
			
				default: //se for diferente do padr�o, fora das op��es dadas ao usu�rio	
				printf("Essa op��o n�o est� dispon�vel \n\n");
				system("pause");
				break;
			}
	
		}
	}
	
	else
		printf("\nSenha incorreta\n");
	
}
