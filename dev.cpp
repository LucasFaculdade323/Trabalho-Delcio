#include <iostream>
#include <ctime> 
#include <cstdlib>
using namespace std; 

FILE *db_clientes, *db_veiculo, *db_locacoes; // Ponteiros

typedef struct clientes {  //struct para agrupar as informações 
  int id;
  char nome[50];
  char cpf[50];
  char endereco[50];
  char telefone[50];
 
  
}reg_clientes;
  
  typedef struct veiculos {
  	int id;
  	char modelo[50];
  	char marca[50];
  	char ano[50];
  	char tipo[50];
  	char placa[50];
  	char valor[50];
  	
  	
  }reg_veiculos;
  
  typedef struct locacoes{
  	char cliente[50]; //clientes vindo da struct de clientes 
  	char vei_placa[50]; //placa do veiculo vindo da struct de veiculos
  	char dias[50];
  	char valor[50];
  	time_t cadastro;   //Adiciona a hora atual
  }reg_locacoes;
  
  //cadastro dos clientes  
 int cadCliente(){
	reg_clientes clientes; 
	int resposta;
 	db_clientes = fopen("db_clientes.dat", "ab");
 
	do { 
		cout << "Digite o Id do cliente:" << endl;
		cin >> clientes.id;

		cout << "Digite o nome do cliente:" << endl;
		cin >> clientes.nome;

		cout << "Digite o CPF do cliente:" << endl;
		cin >> clientes.cpf;
		
		cout << "Digite o telefone do cliente:" << endl;
		cin >> clientes.telefone;
		cout << "Digite o endereco do cliente:" << endl;
		cin >> clientes.endereco; 

		fwrite(&clientes, sizeof(clientes), 1, db_clientes);

		cout << "Cadastro realizado" << endl;
		cout << "Deseja continuar cadastrando? (digite 1 para continuar/2 para sair): ";
		cin >> resposta;

	} while (resposta == 1);
	
	fclose(db_clientes);
	return 0;
}
	
 int cadVeiculo(){    //cadastro dos veiculos
 	reg_veiculos veiculos; 
	int resposta;
	std::system("cls");
	db_veiculo = fopen("db_veiculos.dat", "ab");
	do {
		
 	cout << "Digite o ID do Veiculo:" << endl;
 	cin >> veiculos.id;
 	cout << "Digite o numero da placa veiculo:" << endl;
 	cin >> veiculos.placa;
 	cout << "Digite o modelo do veiculo:" << endl;
	cin >> veiculos.modelo;
	cout << "Digite o ano do veiculo:" << endl;
	cin >> veiculos.ano;
	cout << "Digite o tipo do veiculo:" << endl;
	cin >> veiculos.tipo;
	cout << "Digite o valor do veiculo:" << endl;
	cin >> veiculos.valor;
 	fwrite(&veiculos, sizeof(veiculos), 1, db_veiculo);
 	cout << "Cadastro realizado:" << endl;
 	
 	cout << "Deseja continuar cadastrando? (digite 1 para continuar/2 para sair): ";
 	cin >> resposta;
	} while (resposta == 1 );
 	
	fclose(db_veiculo);
	return 0;
 }
 
  int novalocacao(){    //cadastro de locacoes
 	reg_locacoes locacao; 
	int resposta = 1;

	db_locacoes = fopen("db_locacoes.dat", "ab");
	do {
	  	cout << "Digite o ID do cliente para nova locacao:" << endl;
 		cin >> locacao.cliente;
 		cout << "Digite o numero da placa veiculo:" << endl;
 		cin >> locacao.vei_placa;
 		cout << "Dias:" << endl;
		cin >> locacao.dias;
		cout << "Digite o valor:" << endl;
		cin >> locacao.valor;
		locacao.cadastro = time(nullptr);
	
		fwrite(&locacao, sizeof(reg_locacoes ), 1, db_locacoes);
 		cout << "Cadastro realizado:" << endl;
 		cout << "Deseja continuar cadastrando? (digite 1 para continuar/2 para sair): ";
 		cin >> resposta;
	} while (resposta == 1 );
 	
	fclose(db_locacoes);
	return 0;
 }
 
 
 
 
   
void menuexcluir();
void menuerelatorio();
// Submenu para o modulo de cadastros
void menuCadastro(){  // Tela Menu de Cadastro
	char resposta = ' ';
	do {
		std::system("cls");
		cout << "===========================================" << endl;
		cout << "           LOCADORA - MODULO DE CADASTRO   " << endl;
		cout << "===========================================" << endl;
		cout << "  1. Cadastrar Cliente                     " << endl;
		cout << "  2. Cadastrar Veiculo                     " << endl;
		cout << "  3. Nova Locacao                          " << endl;
		cout << "  0. Voltar ao Menu Principal              " << endl;
		cout << "===========================================" << endl;
		cout << "Selecione uma opcao: ";
		cin >> resposta;

		switch (resposta){
			case '1':
				std::system("cls");
				cadCliente();
				break;
			case '2':
				std::system("cls");
				cadVeiculo();
				break;
			case '3':
				std::system("cls");
				novalocacao();
				break;
			case '4':
				std::system("cls");
				menuexcluir(); 
				break;
			case '5':
				std::system("cls");
				menuerelatorio();
				break;
			case '0':
				break;
			default:
				cout << "\nOpcao invalida! Tente novamente.\n" << endl;
				std::system("pause");
				break;
		}
	} while (resposta != '0');
}

void menuConsulta(){  // Tela Menu de Consulta
	char resposta = ' ';
	do {
		std::system("cls");
		cout << "===========================================" << endl;
		cout << "           LOCADORA - Consultas		    " << endl;
		cout << "===========================================" << endl;
		cout << "  1.  Listar Clientes                   	" << endl;
		cout << "  2.  Listar Veiculos                     	" << endl;
		cout << "  3. Listar Locacoes                       " << endl;
		cout << "  0. Voltar ao Menu Principal              " << endl;
		cout << "===========================================" << endl;
		cout << "Selecione uma opcao: ";
		cin >> resposta;

		switch (resposta){
			case '1':
				std::system("cls");
				cadCliente();
				break;
			case '2':
				std::system("cls");
				cadVeiculo();
				break;
			case '3':
				std::system("cls");
				novalocacao();
				break;
			case '4':
				std::system("cls");
				menuexcluir(); 
				break;
			case '5':
				std::system("cls");
				menuerelatorio();
				break;
			case '0':
				break;
			default:
				cout << "\nOpcao invalida! Tente novamente.\n" << endl;
				std::system("pause");
				break;
		}
	} while (resposta != '0');
}





void menuEditar(){   // Tela Menu de Edicao
	char resposta = ' ';
	do {
		std::system("cls");
		cout << "===========================================" << endl;
		cout << "           LOCADORA - Edicao	            " << endl;
		cout << "===========================================" << endl;
		cout << "  1.  Editar Clientes                   	" << endl;
		cout << "  2.  Editar Veiculos                     	" << endl;
		cout << "  3.  Editar  Locacoes                      " << endl;
		cout << "  0. Voltar ao Menu Principal              " << endl;
		cout << "===========================================" << endl;
		cout << "Selecione uma opcao: ";
		cin >> resposta;

		switch (resposta){
			case '1':
				std::system("cls");
				cadCliente();
				break;
			case '2':
				std::system("cls");
				cadVeiculo();
				break;
			case '3':
				std::system("cls");
				menuEditar(); 
				break;
			case '4':
				std::system("cls");
				menuexcluir();  
				break;
			case '5':
				std::system("cls");
				menuerelatorio();
				break;
				break;
			case '0':
				break;
			default:
				cout << "\nOpcao invalida! Tente novamente.\n" << endl;
				std::system("pause");
				break;
		}
	} while (resposta != '0');
}






void menuexcluir(){ // Tela Menu de Exclusao
	char resposta = ' ';
	do {
		std::system("cls");
		cout << "===========================================" << endl;
		cout << "          LOCADORA -  exclusao	            " << endl;
		cout << "===========================================" << endl;
		cout << "  1.  Excluir Clientes                   	" << endl;
		cout << "  2.  Excluir Veiculos                     " << endl;
		cout << "  3.  Excluir  Locacoes                    " << endl;
		cout << "  0. Voltar ao Menu Principal              " << endl;
		cout << "===========================================" << endl;
		cout << "Selecione uma opcao: ";
		cin >> resposta;

		switch (resposta){
			case '1':
				std::system("cls");
				cadCliente();
				break;
			case '2':
				std::system("cls");
				cadVeiculo();
				break;
			case '3':
				std::system("cls");
				menuEditar(); 
				break;
				case '4':
				std::system("cls");
				menuexcluir(); 
				break;
			case '5':
				std::system("cls");
				menuerelatorio();
				break;
				break;
			case '0':
				break;
			default:
				cout << "\nOpcao invalida! Tente novamente.\n" << endl;
				std::system("pause");
				break;
		}
	} while (resposta != '0');
}





void menuerelatorio(){    // Tela Menu de Relatorio
	char resposta = ' ';
	do {
		std::system("cls");
		cout << "===========================================" << endl;
		cout << "           LOCADORA - Relatorio            " << endl;
		cout << "===========================================" << endl;
		cout << "  1.  Relatorio de Clientes               " << endl;
		cout << "  2.  Relatorio de Veiculos                " << endl;
		cout << "  3.  Relatorio de Locacoes                " << endl;
		cout << "  0. Voltar ao Menu Principal              " << endl;
		cout << "===========================================" << endl;
		cout << "Selecione uma opcao: ";
		cin >> resposta;

		switch (resposta){
			case '1':
				std::system("cls");
				cadCliente();
				break;
			case '2':
				std::system("cls");
				cadVeiculo();
				break;
			case '3':
				std::system("cls");
				menuEditar(); 
				break;
				case '4':
				std::system("cls");
				menuexcluir(); 
				break;
			case '5':
				std::system("cls");
				menuerelatorio(); 
				break;
				break;
			case '0':
				break;
			default:
				cout << "\nOpcao invalida! Tente novamente.\n" << endl;
				std::system("pause");
				break;
		}
	} while (resposta != '0');
}









void menu(){ // Tela Menu Principal
	char resposta = ' ';
	do {
		std::system("cls");
		cout << "===========================================" << endl;
		cout << "        LOCADORA - MENU PRINCIPAL          " << endl;
		cout << "===========================================" << endl;
		cout << "  1. Modulo de cadastro                    " << endl;
		cout << "  2. Consultas                             " << endl;
		cout << "  3. Edicao                                " << endl;
		cout << "  4. Excluir                               " << endl;
		cout << "  5. Relatorio                             " << endl;
		cout << "  6. Sair                                  " << endl;
		cout << "===========================================" << endl;
		cout << "Selecione uma opcao [1-6]: ";
		cin >> resposta;

		switch (resposta){
			case '1':
				menuCadastro();
				break;
			case '2':
				std::system("cls");
				menuConsulta();
				break;
			case '3':
				std::system("cls");
				menuEditar(); 
				break;
			case '4':
				std::system("cls");
				menuexcluir();
				break;
			case '5':
				std::system("cls");
				menuerelatorio(); 
				break;
				break;
			case '6':
				std::system("cls");
				cout << "\n   Programa encerrado com sucesso!\n" << endl;
				break;
			default:
				cout << "\nOpcao invalida! Tente novamente.\n" << endl;
				std::system("pause");
				break;
		}
	} while (resposta != '6');
}   
    
    
    
    
int main(){ 
	menu(); 

	
	
}






 
