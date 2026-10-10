#include <iostream> 
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
  	char data[50];
  	char hora[50];
  	char cliente[50];
  	char veiculo[50];
  	char dias[50];
  	char valor[50];
  	char status[50];
  }reg_locacoes;
  
  //cadastro dos clientes  
 int cadCliente(){
 	reg_clientes clientes; 
	char resposta;
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

	} while (resposta == 'S');
	
		
	}
	
 int cadVeiculo(){    //cadastro dos professores 
 	reg_veiculos veiculos; 
	std::system("cls");
	db_veiculo = fopen("db_veiculos.dat", "ab");
 	cout << "Digite o ID do Veiculo:" << endl;
 	cin >> veiculos.id;
 	cout << "Digite o numero da placa veiculo" << endl;
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
	
 	
 }
 
 
   
    
 void menu(){
 	cout << "1. Modulo de cadastro";
 	cout << "2. Consultas";
 	cout << "3. Edicao";
 	cout << "4. Excluir";
 	cout << "5. Relatorio";
 	cout << "6. Sair";
 }   
    
    
    
    
int main(){
	//menu() 
	cadCliente();
	cadVeiculo();  
	
	
}






 
