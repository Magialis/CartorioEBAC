#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca responsável por alocação de espaços de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função responsável por cadastrar os usuários no sistema
{
	printf("Você escolheu o registro de nomes \n\n");	

	//início da criação de variáveis/string	
	char arquivo[40];
	char cpf[40]; //criando uma string cpf do tipo 40 (que seriam 40 caracteres) não precisa igualar a zero, o programa faz isso sozinho
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	//final da criação de variáveis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s irá salvar dentro de uma string
	
	strcpy(arquivo, cpf); //string copy, puxando do cpf para o arquivo, responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	//está falando para o sistema procurar dentro das bibliotecas alguma estrutura que chama file porque a gente vai criar um arquivo 
	//acessa o FILE e cria o comando *file
	//FILE é uma função já existente, não inventamos, já sabemos como usar. É como dizer: acessa o FILE porque vamos criar um arquivo
	//não falamos do que o *file é composto, então:
	file = fopen(arquivo, "w"); //cria o arquivo e o w significa escrever
	//fopen: abrir o arquivo. abre o arquivo com o nome que estiver dentro dessa variável e é um arquivo novo, então é write
	fprintf(file,"\n CPF: ");
	fprintf(file,cpf); //salvo o valor da variável
	//fprintf dentro do arquivo, ao invés de mostrar para o usuário, está salvando dentro do arquvo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" é para atualizar a informação, adicionar
	fprintf(file,"\n Nome: "); //coloca uma vírgula para separar
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
	
	printf("Você escolheu a consulta de nomes \n\n");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //r de read, ler o arquivo
	
	if(file == NULL) //se o arquivo não existe, for nulo
	{
		printf("\n Não foi possível abrir, arquivo não localizado \n\n");
	}
	
	printf("\n Essas são as informações do usuário: \n");
	
	while(fgets(conteudo, 200, file) != NULL) //"enquanto", laço de repetição. está salvando na variável conteúdo (na string) os 200 caractéres que estão dentro do arquivo e é pra parar quando for nulo (quando não achar, é nulo, não se encaixa na regra)
	//fgets: indo buscar o arquivo
	{
		printf("%s", conteudo);
	}
	
	fclose(file);
	system("pause");
}

int deletar()
{
	printf("Você escolheu deletar nomes \n\n");	
	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\n Usuário não encontrado \n\n");
		system("pause");
		fclose(file);
	}
	
	else
	{
		remove(cpf); //essa função serve apenas para deletar, não retorna uma validação para o usuário
		printf("\n Usuário deletado com sucesso \n\n");
		system("pause");
		fclose(file);
	}
		
	
}


int main()
{
	int opcao=0; //definindo variáveis para a escolha do menu
	//a variável aloca um espaço de memória, então um pedacinho da memória do computador se chama "opcao" e ela começa do 0 se não pode ficar um valor variável de memória. para avisar ao computador que aquela variável não está livre 
	int laco=1; //definindo variáveis para voltar para o menu, repetição
	//for (laco=1 ; laco=10 ; laco++) -> "for" faz com que faça/repita todas vezes que eu pedir
	//laco=1 a entrada quando for 1; laco=10 a saída quando for 10; laco++ toda vez que o programa entrar no laço vai aumentar em 1 o valor da variável
	//mas para não encerrar o programa, deixamos que comece em laco=1 e continue em laco=1, sem incremento
	char senhadigitada[10]="a";
	int comparacao;
	
	setlocale(LC_ALL, "Portuguese");
	printf("Cartório da EBAC \n\n");
	printf("Login de administrador \n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0) //como o valor é igual ele salva igual a 0
	{
		system("cls");
		
		for(laco=1;laco=1;)
		{
			system("cls"); //comando para limpar a tela
		
			setlocale(LC_ALL, "Portuguese"); //definir o local para conseguir usar os acentos

			printf("Cartório da EBAC \n\n"); //início do menu
			printf("Digite a opção desejada do menu: \n\n");
			printf("\t 1 - Registrar nomes \n");
			printf("\t 2 - Consultar nomes \n");
			printf("\t 3 - Deletar nomes \n"); 
			printf("\t 4 - Sair do sistema \n\n");
			printf("Opção: ");//fim do menu
			//\n próxima linha. \t espaçamento, margem  
	
			scanf ("%d", &opcao); //armazenando as informações, a escolha do usuário
			//scanf tem como objetivo scanear o que o usuário coloca. %d armazena uma variável do tipo inteiro. indicar em qual variável armazenar, no caso opcao, adicionando um & antes
	
			system("cls"); //após o usuário escolher a opção, o sistema deleta todas as mensagens anteriores
		
			switch(opcao) //início da seleção do menu
			{
				case 1: //switch case usa o : como uma chave {}
				registro(); //chamada de funções
				break; //break fecha as chaves do switch case, mostra quando acaba. ; porque é uma instrução
			
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema \n\n");
				return 0; //retorna valor 0: quebra laço, qubra função, etc.
				break;
			
				default: //se for diferente do padrão, fora das opções dadas ao usuário	
				printf("Essa opção não está disponível \n\n");
				system("pause");
				break;
			}
	
		}
	}
	
	else
		printf("\nSenha incorreta\n");
	
}
