#include <iostream>
#include <iostream>
#include <locale.h>
#include <ctime>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <windows.h>
#include <conio.h>
using namespace std;

// Criptografia: Backspace e ENTER
enum IN {
 
    IN_BACK = 8,
    IN_RET = 13
 
};
 
// Criptografia
std::string takePasswdFromUser(
    char sp = '*')
{
    string passwd = "";
    char ch_ipt;

    while (true) {
 
        ch_ipt = getch();
 
        if (ch_ipt == IN::IN_RET) {
            cout << endl;
            return passwd;
        }
        else if (ch_ipt == IN::IN_BACK
                 && passwd.length() != 0) {
            passwd.pop_back();
 
            cout << "\b \b";
 
            continue;
        }
 
        else if (ch_ipt == IN::IN_BACK
                 && passwd.length() == 0) {
            continue;
        }
 
        passwd.push_back(ch_ipt);
        cout << sp;
    }
}

//Delay de tempo
void timer1(){
	
	time_t start = time(0);
	while (difftime( time(0), start) < 3.0);
		
}

//Animação de logoff
void logoff(){
	
	for(int temp = 0; temp <=100; temp = temp + 3){
	cout << "		Realizando Logoff." << endl << endl;
	cout << " " << temp << "% Sincronizando dados com usuario.";
	Sleep(5);
	system("cls");
	}
	
	for(int temp = 0; temp <=100; temp = temp + 5){
	cout << "		Realizando Logoff." << endl << endl;
	cout << " 100% Sincronizando dados com usuario." << endl;
	cout << " " << temp << "% Salvando dados na nuvem.";
	Sleep(5);
	system("cls");
	}
	
	for(int temp = 0; temp <=100; temp = temp + 10){
	cout << "		Realizando Logoff." << endl << endl;
	cout << " 100% Sincronizando dados com usuario." << endl;
	cout << " 100% Salvando dados na nuvem." << endl;
	cout << " " << temp << "% Retornando ao login.";
	Sleep(10);
	system("cls");
	}
	
}

//Animação de finalização
void finalizacao(){
	
	for(int temp = 0; temp <=100; temp = temp + 3){
	cout << "		Finalizando Programa." << endl << endl;
	cout << " " << temp << "% Sincronizando dados com usuario.";
	Sleep(5);
	system("cls");
	}
	
	for(int temp = 0; temp <=100; temp = temp + 5){
	cout << "		Finalizando Programa." << endl << endl;
	cout << " 100% Sincronizando dados com usuario." << endl;
	cout << " " << temp << "% Salvando dados na nuvem.";
	Sleep(5);
	system("cls");
	}
	
	for(int temp = 0; temp <=100; temp = temp + 10){
	cout << "		Finalizando Programa." << endl << endl;
	cout << " 100% Sincronizando dados com usuario." << endl;
	cout << " 100% Salvando dados na nuvem." << endl;
	cout << " " << temp << "% Encerrando programa.";
	Sleep(10);
	system("cls");
	}
	
}

//Retorna data e hora
void dth(){
	
	time_t data_tempo;
    time(&data_tempo);
    
    struct tm*tempo = localtime(&data_tempo);
    struct tm*data = localtime(&data_tempo);
    
    int dia = data->tm_mday;
    int mes = data->tm_mon + 1;
    int ano = data->tm_year + 1900;
    
    int seg = tempo->tm_sec;
    int min = tempo->tm_min;
    int hora = tempo->tm_hour;
    
    printf(" Data: %.2d/%.2d/%.4d", dia, mes, ano);
    printf("\n Horário: %d:%.2d", hora, min);
    
}

//Listar Fornecedores
void listarf() {
	
	system("cls");
	cout << "		Lista de Fornecedores" << endl << endl;
	fstream fin;
    fin.open("BanDados/fornecedores.txt", ios::in);
    vector<string> linhas;
    string linha, palavra, temp;
    
    while (fin >> temp) {
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); // ,1[0] , nome[1] , contato[2] , cnpj[3]
        }

			cout << "       Fornecedor " << linhas[0] << endl << endl;
            cout << "Nome: " << linhas[1] << endl;
            cout << "Contato: " << linhas[2] << endl;
            cout << "CNPJ: " << linhas[3] << endl;
    		cout << endl << endl;

    }	
    system("pause");
}

//Buscar Fornecedores
void buscarf() {
	int mp3;
	
	system("cls");
	cout << "		Busca de Fornecedores" << endl << endl;
    fstream fin; 
    fin.open("BanDados/fornecedores.txt", ios::in); 
    int linhan1, linhan2, cont = 0; 
    cout << " Digite o código do fornecedor: ";
    cin >> linhan1;
    vector<string> linhas;
    string linha, palavra, temp;
  
    while (fin >> temp) { 
  
        linhas.clear();
        getline(fin, linha); 
        stringstream s(linha);
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); // ,1[0] , nome[1] , contato[2] , cnpj[3]
        }
        
        linhan2 = stoi(linhas[0]);
  
        if (linhan2 == linhan1) { 
  			
  			cont = 1;
			cout << endl;
            cout << "       Fornecedor " << linhas[0] << endl << endl;
            cout << "Nome: " << linhas[1] << endl;
            cout << "Contato: " << linhas[2] << endl;
            cout << "CNPJ: " << linhas[3];
    		cout << endl << endl;
			system("pause");
            break;
        }
    }
    if (cont == 0) { 
    	cout << endl;
        cout << "               Dados não encontrados..." << endl << endl;
        cout << " 1. Realizar nova busca" << endl; 
        cout << " 2. Voltar ao menu" << endl;
        cout << " Informe uma das opções: ";
        cin >> mp3;
        
        switch(mp3) {
        	case 1:
        		
				buscarf();
        		break;		
		}   
	}
	
} 

//Cadastrar Fornecedores
void cadastrarf() {
	
	system("cls"); 
	cout << "		Cadastrar Fornecedor" << endl << endl;   
    fstream fin, fout;
    fin.open("BanDados/fornecedores.txt", ios::in);
    vector<string> linhas;
    string linha, palavra, temp;
    int x = 0;
  
  	while(fin >> temp) {
	  
	    linhas.clear(); 
	    getline(fin, linha); 
	    stringstream s(linha);
	    char virgula = ',';
	    while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); // ,1[0] , nome[1] , contato[2] , cnpj[3] 
	    }
	    x = stoi(linhas[0]);
	}

    fout.open("BanDados/fornecedores.txt", ios::out | ios::app); 
    int n; 
    cout << " Informe quantos fornecedores deseja cadastrar: ";
	cin >> n;
    cin.sync();
    cout << " Informe os dados do " << n << "º fornecedor:" << endl << endl;
    int codigo;
    string nome, contato, cnpj;
    codigo = x;

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
  		cout << "       Adicionar Fornecedor " << codigo << endl << endl;
  		cout << "Informe o nome do fornecedor: ";
        getline(cin, nome);
        cout << "Informe o contato do fornecedor: ";
        getline(cin, contato);
        cout << "Informe o CNPJ do fornecedor: ";
        getline(cin, cnpj);
        cout << endl << endl;
  
        fout << ", "
			 << codigo << ", " // ,1[0] , nome[1] , contato[2] , cnpj[3] 
             << nome << setlocale(LC_ALL, "UTF-8") << ", "
             << contato << ", "
             << cnpj
             << endl;
    }
	cout << "               Dados cadastrados com sucesso." << endl;
	timer1();
}

//Excluir Fornecedores
void excluirf() {
	
	system("cls"); 
	cout << "		Excluir dados dos fornecedores" << endl << endl; 
    fstream fin, fout; 
    fin.open("BanDados/fornecedores.txt", ios::in);
    fout.open("BanDados/attfornecedores.txt", ios::out); 
    int linhan1, linhan2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas; 
	cout << " Digite o código do fornecedor que deseja excluir os dados: ";
    cin >> linhan1;
    while (fin >> temp) { 
  
        linhas.clear();
        getline(fin, linha); 
        stringstream s(linha); 
  		char virgula = ','; 
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra); // ,1[0] , nome[1] , contato[2] , cnpj[3] 
        }
  
        int row_size = linhas.size(); 
        linhan2 = stoi(linhas[0]); 

        if (linhan2 != linhan1) { 
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof()) 
            break;
    }
    if (cont == 1) {
        cout << "               Dados excluidos com sucesso." << endl << endl;
        timer1();
    } else {
        cout << "               Dados nao encontrados." << endl << endl;
        timer1();
	}
		
    fin.close();
    fout.close(); 

    remove("BanDados/fornecedores.txt"); 
    rename("BanDados/attfornecedores.txt", "BanDados/fornecedores.txt");
	
}

//Atualizar Fornecedores
void atualizarf() {
	
	system("cls"); 
	cout << "       Atualizar dados dos fornecedores" << endl << endl;
    fstream fin, fout; 
    fin.open("BanDados/fornecedores.txt", ios::in); 
    fout.open("BanDados/attfornecedores.txt", ios::out);
    int linhan1, linhan2, indice, sub, cont = 0;
    string linha, palavra, novo, temp;
    vector<string> linhas;
    cout << " Digite o código do fornecedor que deseja atualizar os dados: ";
    cin >> linhan1;
    cin.sync();

	cout << endl;
    cout << "       Alterar dados do Fornecedor " << linhan1 << endl << endl;
    cout << " 1. Alterar nome" << endl;
    cout << " 2. Alterar contato" << endl;
    cout << " 3. Alterar CNPJ" << endl;
    cout << " Informe uma das opções: ";
    cin >> sub;
  	cin.sync();
  	cout << endl;
  	
  	switch(sub) { 
  		case 1:
  			
  		    cout << "       Alterar nome do fornecedor" << endl << endl;
  			indice = 1;
  			break;
  		case 2:
  			
  			cout << "       Alterar contato do fornecedor" << endl << endl;
  			indice = 2;
  			break;
  		case 3:
  			
  			cout << "       Alterar CNPJ do fornecedor" << endl << endl;
  			indice = 3;
  			break;
  			
  		default:
	        cout << "Opçao Invalida." << endl;
	        atualizarf();
			break;  			
	  }

    cout << "Informe o dado atualizado: ";
    getline(cin, novo);

    while (fin >> temp) { 
  
        linhas.clear(); 
  
        getline(fin, linha); 
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra); // ,1[0] , nome[1] , contato[2] , cnpj[3] 
        }
  
        linhan2 = stoi(linhas[0]);
        
        int row_size = linhas.size(); 
  
        if (linhan2 == linhan1) { 
            cont = 1; 
            stringstream convert; 

            convert << novo; 

            linhas[indice] = convert.str(); 
  
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << endl;
            }
        }
        else {
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << endl;
            }
        }
        if (fin.eof()) { 
            break;
		}
    }
    if (cont == 1) { 
        cout << "Dados atualizados com Sucesso." << endl;
        timer1();
	} else if (cont == 0) { 
    	cout << "Dados nao encontrados, nao foi Possivel atualizar os dados." << endl << endl;
    	timer1();
    	atualizarf();
	}

    fin.close(); 
    fout.close(); 

    remove("BanDados/fornecedores.txt");
    rename("BanDados/attfornecedores.txt", "BanDados/fornecedores.txt");
} 

//Menu Fornecedores
void mfor(){
	int mp2;
	
	do{
	system("cls");
		cout << "		Menu Fornecedores" << endl << endl;
		cout << " 1. Listar todos" << endl;
		cout << " 2. Pesquisar fornecedor" << endl;
		cout << " 3. Cadastrar novo" << endl;
		cout << " 4. Atualizar" << endl;
		cout << " 5. Excluir" << endl;
		cout << " 6. Sair" << endl;
		cout << " Informe uma das opções: ";
		cin >> mp2;
		
	switch(mp2) {
		case 1:
			
			listarf();
			break;
		case 2:
			
			buscarf();
			break;
		case 3:
			
			cadastrarf();
			break;
		case 4:
			
			atualizarf();
			break;
		case 5:
			
			excluirf();
			break;
		case 6:
			
			break;
		default:
			
			cout << endl << "		Opção Inválida." << endl;
				system("pause");
			break;
	}
	}while(mp2 != 6);
	
}

//Listar Parceiros
void listarp() {
	
	system("cls");
	cout << "		Lista de Parceiros" << endl << endl;
	fstream fin;
    fin.open("BanDados/parceiros.txt", ios::in);
    vector<string> linhas;
    string linha, palavra, temp;
    
    while (fin >> temp) {
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); // ,1[0] , nome[1] , contato[2] , cnpj[3]
        }

			cout << "       Parceiro " << linhas[0] << endl << endl;
            cout << "Nome: " << linhas[1] << endl;
            cout << "Contato: " << linhas[2] << endl;
            cout << "CNPJ: " << linhas[3];
    		cout << endl << endl;

    }	
    system("pause");
}

//Buscar Parceiros
void buscarp() {
	int mp3;
	
	system("cls");
	cout << "		Busca de Parceiros" << endl << endl;
    fstream fin; 
    fin.open("BanDados/parceiros.txt", ios::in); 
    int linhan1, linhan2, cont = 0; 
    cout << " Digite o código do parceiro: ";
    cin >> linhan1;
    vector<string> linhas;
    string linha, palavra, temp;
  
    while (fin >> temp) { 
  
        linhas.clear();
        getline(fin, linha); 
        stringstream s(linha);
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); // ,1[0] , nome[1] , contato[2] , cnpj[3]
        }
        
        linhan2 = stoi(linhas[0]);
  
        if (linhan2 == linhan1) { 
  			
  			cont = 1;
			cout << endl;
            cout << "       Parceiro " << linhas[0] << endl << endl;
            cout << "Nome: " << linhas[1] << endl;
            cout << "Contato: " << linhas[2] << endl;
            cout << "CNPJ: " << linhas[3];
    		cout << endl << endl;
			system("pause");
            break;
        }
    }
    if (cont == 0) { 
    	cout << endl;
        cout << "               Dados não encontrados..." << endl << endl;
        cout << " 1. Realizar nova busca" << endl; 
        cout << " 2. Voltar ao menu" << endl;
        cout << " Informe uma das opções: ";
        cin >> mp3;
        
        switch(mp3) {
        	case 1:
        		
				buscarp();
        		break;		
		}   
	}
	
} 

//Cadastrar Parceiros
void cadastrarp() {
	
	system("cls"); 
	cout << "		Cadastrar Parceiros" << endl << endl;   
    fstream fin, fout;
    fin.open("BanDados/parceiros.txt", ios::in);
    vector<string> linhas;
    string linha, palavra, temp;
    int x = 0;
  
  	while(fin >> temp) {
	  
	    linhas.clear(); 
	    getline(fin, linha); 
	    stringstream s(linha);
	    char virgula = ',';
	    while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); // ,1[0] , nome[1] , contato[2] , cnpj[3] 
	    }
	    x = stoi(linhas[0]);
	}

    fout.open("BanDados/parceiros.txt", ios::out | ios::app); 
    int n; 
    cout << " Informe quantos parceiros deseja cadastrar: ";
	cin >> n;
    cin.sync();
    cout << " Informe os dados do " << n << "º parceiro:" << endl << endl;
    int codigo;
    string nome, contato, cnpj;
    codigo = x;

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
  		cout << "       Adicionar Parceiro " << codigo << endl << endl;
  		cout << "Informe o nome do parceiro: ";
        getline(cin, nome);
        cout << "Informe o contato do parceiro: ";
        getline(cin, contato);
        cout << "Informe o CNPJ do parceiro: ";
        getline(cin, cnpj);
        cout << endl << endl;
  
        fout << ", "
			 << codigo << ", " // ,1[0] , nome[1] , contato[2] , cnpj[3] 
             << nome << ", "
             << contato << ", "
             << cnpj
             << endl;
    }
	cout << "               Dados cadastrados com sucesso." << endl;
	timer1();
}

//Excluir Parceiros
void excluirp() {
	
	system("cls"); 
	cout << "		Excluir dados dos parceiros" << endl << endl; 
    fstream fin, fout; 
    fin.open("BanDados/parceiros.txt", ios::in);
    fout.open("BanDados/attparceiros.txt", ios::out); 
    int linhan1, linhan2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas; 
	cout << " Digite o código do parceiro que deseja excluir os dados: ";
    cin >> linhan1;
    while (fin >> temp) { 
  
        linhas.clear();
        getline(fin, linha); 
        stringstream s(linha); 
  		char virgula = ','; 
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra); // ,1[0] , nome[1] , contato[2] , cnpj[3] 
        }
  
        int row_size = linhas.size(); 
        linhan2 = stoi(linhas[0]); 

        if (linhan2 != linhan1) { 
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof()) 
            break;
    }
    if (cont == 1) {
        cout << "               Dados excluidos com sucesso." << endl << endl;
        timer1();
    } else {
        cout << "               Dados nao encontrados." << endl << endl;
        timer1();
	}
		
    fin.close();
    fout.close(); 

    remove("BanDados/parceiros.txt"); 
    rename("BanDados/attparceiros.txt", "BanDados/parceiros.txt");
	
}

//Atualizar Parceiros
void atualizarp() {
	
	system("cls"); 
	cout << "       Atualizar dados dos parceiros" << endl << endl;
    fstream fin, fout; 
    fin.open("BanDados/parceiros.txt", ios::in); 
    fout.open("BanDados/attparceiros.txt", ios::out);
    int linhan1, linhan2, indice, sub, cont = 0;
    string linha, palavra, novo, temp;
    vector<string> linhas;
    cout << " Digite o código do parceiro que deseja atualizar os dados: ";
    cin >> linhan1;
    cin.sync();

	cout << endl;
    cout << "       Alterar dados do Parceiro " << linhan1 << endl << endl;
    cout << " 1. Alterar nome" << endl;
    cout << " 2. Alterar contato" << endl;
    cout << " 3. Alterar CNPJ" << endl;
    cout << " Informe uma das opções: ";
    cin >> sub;
  	cin.sync();
  	cout << endl;
  	
  	switch(sub) { 
  		case 1:
  			
  		    cout << "       Alterar nome do parceiro" << endl << endl;
  			indice = 1;
  			break;
  		case 2:
  			
  			cout << "       Alterar contato do parceiro" << endl << endl;
  			indice = 2;
  			break;
  		case 3:
  			
  			cout << "       Alterar CNPJ do parceiro" << endl << endl;
  			indice = 3;
  			break;
  			
  		default:
	        cout << "Opçao Invalida." << endl;
	        atualizarp();
			break;  			
	  }

    cout << "Informe o dado atualizado: ";
    getline(cin, novo);

    while (fin >> temp) { 
  
        linhas.clear(); 
  
        getline(fin, linha); 
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra); // ,1[0] , nome[1] , contato[2] , cnpj[3] 
        }
  
        linhan2 = stoi(linhas[0]);
        
        int row_size = linhas.size(); 
  
        if (linhan2 == linhan1) { 
            cont = 1; 
            stringstream convert; 

            convert << novo; 

            linhas[indice] = convert.str(); 
  
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << endl;
            }
        }
        else {
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << endl;
            }
        }
        if (fin.eof()) { 
            break;
		}
    }
    if (cont == 1) { 
        cout << "Dados atualizados com Sucesso." << endl;
        timer1();
	} else if (cont == 0) { 
    	cout << "Dados nao encontrados, nao foi Possivel atualizar os dados." << endl << endl;
    	timer1();
    	atualizarp();
	}

    fin.close(); 
    fout.close(); 

    remove("BanDados/parceiros.txt");
    rename("BanDados/attparceiros.txt", "BanDados/parceiros.txt");
} 

//Menu Parceiros
void mpar(){
	int mp2;
	
	do{
	system("cls");
		cout << "		Menu Parceiros" << endl << endl;
		cout << " 1. Listar todos" << endl;
		cout << " 2. Pesquisar parceiro" << endl;
		cout << " 3. Cadastrar novo" << endl;
		cout << " 4. Atualizar" << endl;
		cout << " 5. Excluir" << endl;
		cout << " 6. Sair" << endl;
		cout << " Informe uma das opções: ";
		cin >> mp2;
		
	switch(mp2) {
		case 1:
			
			listarp();
			break;
		case 2:
			
			buscarp();
			break;
		case 3:
			
			cadastrarp();
			break;
		case 4:
			
			atualizarp();
			break;
		case 5:
			
			excluirp();
			break;
		case 6:
			break;
		default:
			
			cout << endl << "		Opção Inválida." << endl;
				system("pause");
			break;
	}
	}while(mp2 != 6);
	
}

//Listar Clientes
void listarc() {
	
	system("cls");
	cout << "		Lista de Clientes" << endl << endl;
	fstream fin;
    fin.open("BanDados/clientes.txt", ios::in);
    vector<string> linhas;
    string linha, palavra, temp;
    
    while (fin >> temp) {
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }

			cout << "       Cliente " << linhas[0] << endl << endl;
            cout << "Nome: " << linhas[1] << endl;
            cout << "Telefone: " << linhas[2] << endl;
            cout << "E-mail: " << linhas[3] << endl;
            cout << "Idade: " << linhas[4] << endl;
            cout << "CPF: " << linhas[5] << endl;
    		cout << endl << endl;

    }	
    system("pause");
}

//Buscar Clientes
void buscarc() {
	int mp3;
	
	system("cls");
	cout << "		Busca de Clientes" << endl << endl;
    fstream fin; 
    fin.open("BanDados/clientes.txt", ios::in); 
    int linhan1, linhan2, cont = 0; 
    cout << " Digite o código do cliente: ";
    cin >> linhan1;
    vector<string> linhas;
    string linha, palavra, temp;
  
    while (fin >> temp) { 
  
        linhas.clear();
        getline(fin, linha); 
        stringstream s(linha);
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }
        
        linhan2 = stoi(linhas[0]);
  
        if (linhan2 == linhan1) { 
  			
  			cont = 1;
			cout << endl;
            cout << "       Cliente " << linhas[0] << endl << endl;
            cout << "Nome: " << linhas[1] << endl;
            cout << "Telefone: " << linhas[2] << endl;
            cout << "E-mail: " << linhas[3] << endl;
            cout << "Idade: " << linhas[4] << endl;
            cout << "CPF: " << linhas[5] << endl;
    		cout << endl << endl;
			system("pause");
            break;
        }
    }
    if (cont == 0) { 
    	cout << endl;
        cout << "               Dados não encontrados..." << endl << endl;
        cout << " 1. Realizar nova busca" << endl; 
        cout << " 2. Voltar ao menu" << endl;
        cout << " Informe uma das opções: ";
        cin >> mp3;
        
        switch(mp3) {
        	case 1:
        		
				buscarc();
        		break;		
		}   
	}
	
} 

//Cadastrar Cliente
void cadastrarc() {
	
	system("cls"); 
	cout << "		Cadastrar Clientes" << endl << endl;   
    fstream fin, fout;
    fin.open("BanDados/clientes.txt", ios::in);
    vector<string> linhas;
    string linha, palavra, temp;
    int x = 0;
  
  	while(fin >> temp) {
	  
	    linhas.clear(); 
	    getline(fin, linha); 
	    stringstream s(linha);
	    char virgula = ',';
	    while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
	    }
	    x = stoi(linhas[0]);
	}

    fout.open("BanDados/clientes.txt", ios::out | ios::app); 
    int n; 
    cout << " Informe quantos clientes deseja cadastrar: ";
	cin >> n;
    cin.sync();
    cout << " Informe os dados do " << n << "º Cliente:" << endl << endl;
    int codigo, idade;
    string nome, telefone, email, cpf;
    codigo = x;

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
  		cout << "       Adicionar Cliente " << codigo << endl << endl;
  		cout << "Informe o nome do cliente: ";
        getline(cin, nome);
        cout << "Informe o telefone do cliente: ";
        getline(cin, telefone);
        cout << "Informe o E-mail do cliente: ";
        getline(cin, email);
        cout << "Informe o idade do cliente: ";
        cin >> idade;
        cin.sync();
        cout << "Informe o CPF do cliente: ";
        getline(cin, cpf);
        cout << endl << endl;
  
        fout << ", "
			 << codigo << ", " // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
             << nome << ", "
             << telefone << ", "
             << email << ", "
             << idade << ", "
             << cpf
             << endl;
    }
	cout << "               Dados cadastrados com sucesso." << endl;
	timer1();
}

//Excluir Clientes
void excluirc() {
	
	system("cls"); 
	cout << "		Excluir dados dos clientes" << endl << endl; 
    fstream fin, fout; 
    fin.open("BanDados/clientes.txt", ios::in);
    fout.open("BanDados/attclientes.txt", ios::out); 
    int linhan1, linhan2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas; 
	cout << " Digite o código do cliente que deseja excluir os dados: ";
    cin >> linhan1;
    while (fin >> temp) { 
  
        linhas.clear();
        getline(fin, linha); 
        stringstream s(linha); 
  		char virgula = ','; 
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }
  
        int row_size = linhas.size(); 
        linhan2 = stoi(linhas[0]); 

        if (linhan2 != linhan1) { 
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof()) 
            break;
    }
    if (cont == 1) {
        cout << "               Dados excluidos com sucesso." << endl << endl;
        timer1();
    } else {
        cout << "               Dados nao encontrados." << endl << endl;
        timer1();
	}
		
    fin.close();
    fout.close(); 

    remove("BanDados/clientes.txt"); 
    rename("BanDados/attclientes.txt", "BanDados/clientes.txt");
	
}

//Atualizar Clientes
void atualizarc() {
	
	system("cls"); 
	cout << "       Atualizar dados dos Clientes" << endl << endl;
    fstream fin, fout; 
    fin.open("BanDados/clientes.txt", ios::in); 
    fout.open("BanDados/attclientes.txt", ios::out);
    int linhan1, linhan2, indice, sub, cont = 0;
    string linha, palavra, novo, temp;
    vector<string> linhas;
    cout << " Digite o código do cliente que deseja atualizar os dados: ";
    cin >> linhan1;
    cin.sync();

	cout << endl;
    cout << "       Alterar dados do cliente " << linhan1 << endl << endl;
    cout << " 1. Alterar nome" << endl;
    cout << " 2. Alterar telefone" << endl;
    cout << " 3. Alterar E-mail" << endl;
    cout << " 4. Alterar idade" << endl;
    cout << " 5. Alterar CPF" << endl;
    cout << " Informe uma das opções: ";
    cin >> sub;
  	cin.sync();
  	cout << endl;
  	
  	switch(sub) { 
  		case 1:
  		    cout << "       Alterar nome do cliente" << endl << endl;
  			indice = 1;
  			break;
  		case 2:
  			cout << "       Alterar telefone do cliente" << endl << endl;
  			indice = 2;
  			break;
  		case 3:
  			cout << "       Alterar E-mail do cliente" << endl << endl;
  			indice = 3;
  			break;
  		case 4:
  			cout << "       Alterar idade do cliente" << endl << endl;
  			indice = 4;
  			break;
  		case 5:
  			cout << "       Alterar CPF do cliente" << endl << endl;
  			indice = 5;
  			break;
  		default:
	        cout << "Opçao Invalida." << endl;
	        atualizarc();
			break;  			
	  }

    cout << "Informe o dado atualizado: ";
    getline(cin, novo);

    while (fin >> temp) { 
  
        linhas.clear(); 
  
        getline(fin, linha); 
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }
  
        linhan2 = stoi(linhas[0]);
        
        int row_size = linhas.size(); 
  
        if (linhan2 == linhan1) { 
            cont = 1; 
            stringstream convert; 

            convert << novo; 

            linhas[indice] = convert.str(); 
  
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << endl;
            }
        }
        else {
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << endl;
            }
        }
        if (fin.eof()) { 
            break;
		}
    }
    if (cont == 1) { 
        cout << "Dados atualizados com Sucesso." << endl;
        timer1();
	} else if (cont == 0) { 
    	cout << "Dados nao encontrados, nao foi Possivel atualizar os dados." << endl << endl;
    	timer1();
    	atualizarc();
	}

    fin.close(); 
    fout.close(); 

    remove("BanDados/clientes.txt");
    rename("BanDados/attclientes.txt", "BanDados/clientes.txt");
}

//Cadastrar Produtos no Histórico
void cadastrarhp() {
	
	system("cls"); 
	cout << "		Cadastrar produtos" << endl << endl;   
    fstream fin, fout;
    fin.open("BanDados/historico.txt", ios::in);
    vector<string> linhas;
    string linha, palavra, temp;
  
  	while(fin >> temp) {
	  
	    linhas.clear(); 
	    getline(fin, linha); 
	    stringstream s(linha);
	    char virgula = ',';
	    while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra);  
	    }
	}

    fout.open("BanDados/historico.txt", ios::out | ios::app); 
    int n; 
    cout << " Informe quantos produtos deseja cadastrar: ";
	cin >> n;
    cin.sync();
    int codigo, idade;
    string produto, nome;

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
  		cout << "       Adicionar produto " << codigo << endl << endl;
  		cout << "Repita o nome do cliente: ";
        getline(cin, nome);
  		cout << "Informe o nome do produto: ";
        getline(cin, produto);
        cout << endl << endl;
  
        fout << ", " 
		<< nome << ", " 
		<< produto
        << endl;
		
    }
	cout << "               Dados cadastrados com sucesso." << endl;
	timer1();
}

//BuscarC Histórico
void buscarhc() {
	int mp3;
	
	system("cls");
	cout << "		Histórico de compra" << endl << endl;
    fstream fin; 
    fin.open("BanDados/clientes.txt", ios::in); 
    int cont = 0; 
    string linhan1, linhan2; 
    cout << " Digite o nome do cliente que deseja cadastrar: ";
    cin >> linhan1;
    linhan1 = " " + linhan1; 
    vector<string> linhas;
    string linha, palavra, temp;
  
    while (fin >> temp) { 
  
        linhas.clear();
        getline(fin, linha); 
        stringstream s(linha);
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); //nome[1] 
        }
        
        linhan2 = linhas[1];
  
        if (linhan2 == linhan1) { 
  			
  			cont = 1;
            break;
        }
    }
    if (cont == 0) { 
    	cout << endl;
        cout << "               Dados não encontrados..." << endl << endl;
        cout << " 1. Realizar nova busca" << endl; 
        cout << " 2. Voltar ao menu" << endl;
        cout << " Informe uma das opções: ";
        cin >> mp3;
        
        switch(mp3) {
        	case 1:
        		
				buscarhc();
				cadastrarhp();
        		break;
			default:
				
				break;		
		} 
		  
	} 
	if(cont == 1) {
		cadastrarhp();	
	}

}

//Listar Hitórico de Clientes
void listarhc() {
	int mp3;
	
	system("cls");
	cout << "		Histórico de compra" << endl << endl;
    fstream fin; 
    fin.open("BanDados/historico.txt", ios::in); 
    int cont = 0, v = 1; 
    string linhan1, linhan2; 
    cout << " Digite o nome do cliente que deseja exibir o histórico: ";
    cin >> linhan1;
    linhan1 = " " + linhan1; 
    vector<string> linhas;
    string linha, palavra, temp;
  	
    while (fin >> temp) { 
  
        linhas.clear();
        getline(fin, linha); 
        stringstream s(linha);
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); //nome[1] 
        }
        
        linhan2 = linhas[0];
        if (linhan2 == linhan1 and v == 1) { 
        cout << "       Cliente: " << linhas[0] << endl << endl;
        v = 2;
   		}    
  
        if (linhan2 == linhan1) { 
        
  			cont = 1;
  			
            cout << " Produto: " << linhas[1] << endl;
    
        }	
    }
    
    if (cont == 0) { 
    	cout << endl;
        cout << "               Esse cliente não possui compras..." << endl << endl;
        cout << " 1. Realizar nova busca" << endl; 
        cout << " 2. Voltar ao menu" << endl;
        cout << " Informe uma das opções: ";
        cin >> mp3;
        
        switch(mp3) {
        	case 1:
        		
				buscarhc();
        		break;
			default:
				
				break;		
		}   
	}else{
		cout << endl;
		system("pause");	
	}
}

//Histórico de Compra
void historicoc() {
	int mp4;
	
	system("cls");
	cout << "		Histórico de compra" << endl << endl;
	cout << " 1. Cadastrar compra" << endl;
	cout << " 2. Exibir histórico de compra" << endl;
	cout << " 3. Sair" << endl;
	cout << " Informe uma das opções: ";
	cin >> mp4;
	
	switch(mp4) {
		case 1:
			
			buscarhc();
			break;
		case 2:
			
			listarhc();
			break;
		case 3:
			
			break;
		default:
			
			cout << endl << "		Opção Inválida." << endl;
			system("pause");
			historicoc();	
			break;
	}
	
	
}

//Menu Clientes
void mcli(){
	int mp2;
	
	do{
		system("cls");
		cout << "		Menu Clientes" << endl << endl;
		cout << " 1. Listar todos" << endl;
		cout << " 2. Buscar cliente" << endl;
		cout << " 3. Cadastrar novo" << endl;
		cout << " 4. Atualizar" << endl;
		cout << " 5. Excluir" << endl;
		cout << " 6. Histórico de compra" << endl;
		cout << " 7. Sair" << endl;
		cout << " Informe uma das opções: ";
		cin >> mp2;
		
	switch(mp2) {
		case 1:
			
			listarc();
			break;
		case 2:
			
			buscarc();
			break;
		case 3:
			
			cadastrarc();
			break;
		case 4:
			
			atualizarc();
			break;
		case 5:
			
			excluirc();
			break;
		case 6:
			
			historicoc();
			break;
		case 7:
			
			break;
		default:
			
			cout << endl << "		Opção Inválida." << endl;
				system("pause");
			break;
	}
	}while(mp2 != 7);
	
}

//Listar Produtos
void listarpr() {
	
	system("cls");
	cout << "		Lista de Produtos" << endl << endl;
	fstream fin;
    fin.open("BanDados/produtos.txt", ios::in);
    vector<string> linhas;
    string linha, palavra, temp;
    
    while (fin >> temp) {
  
        linhas.clear();

        getline(fin, linha); 
  
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); // ,1[0] , nome[1] , marca[2] , tipo[3], preço[4] , vendas[5] , parceiro[6] , fornecedor[7]
        }

			cout << "       Produto " << linhas[0] << endl << endl;
            cout << "Nome: " << linhas[1] << endl;
            cout << "Marca: " << linhas[2] << endl;
            cout << "Tipo: " << linhas[3] << endl;
            cout << "Preço: R$ " << linhas[4] << endl;
            cout << "Quantidade vendida: " << linhas[5] << endl;
            cout << "Anunciado em: " << linhas[6] << endl;
            cout << "Fornecido por: " << linhas[7] << endl;
    		cout << endl << endl;

    }	
    system("pause");
}

//Buscar Produtos
void buscarpr() {
	int mp3;
	
	system("cls");
	cout << "		Busca de Produtos" << endl << endl;
    fstream fin; 
    fin.open("BanDados/produtos.txt", ios::in); 
    int linhan1, linhan2, cont = 0; 
    cout << " Digite o código do produto: ";
    cin >> linhan1;
    vector<string> linhas;
    string linha, palavra, temp;
  
    while (fin >> temp) { 
  
        linhas.clear();
        getline(fin, linha); 
        stringstream s(linha);
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) { 
			linhas.push_back(palavra); // ,1[0] , nome[1] , marca[2] , tipo[3], preço[4] , vendas[5] , parceiro[6] , fornecedor[7]
        }
        
        linhan2 = stoi(linhas[0]);
  
        if (linhan2 == linhan1) { 
  			
  			cont = 1;
			cout << endl;
            cout << "       Produto " << linhas[0] << endl << endl;
            cout << "Nome: " << linhas[1] << endl;
            cout << "Marca: " << linhas[2] << endl;
            cout << "Tipo: " << linhas[3] << endl;
            cout << "Preço: R$ " << linhas[4] << endl;
            cout << "Quantidade vendida: " << linhas[5] << endl;
            cout << "Anunciado em: " << linhas[6] << endl;
            cout << "Fornecido por: " << linhas[7] << endl;
    		cout << endl << endl;
			system("pause");
            break;
        }
    }
    if (cont == 0) { 
    	cout << endl;
        cout << "               Dados não encontrados..." << endl << endl;
        cout << " 1. Realizar nova busca" << endl; 
        cout << " 2. Voltar ao menu" << endl;
        cout << " Informe uma das opções: ";
        cin >> mp3;
        
        switch(mp3) {
        	case 1:
        		
				buscarpr();
        		break;		
		}   
	}
	
} 

//Cadastrar Produtos
void cadastrarpr() {
	
	system("cls"); 
	cout << "		Cadastrar Produto" << endl << endl;   
    fstream fin, fout;
    fin.open("BanDados/produtos.txt", ios::in);
    vector<string> linhas;
    string linha, palavra, temp;
    int x = 0;
  
  	while(fin >> temp) {
	  
	    linhas.clear(); 
	    getline(fin, linha); 
	    stringstream s(linha);
	    char virgula = ',';
	    while (getline(s, palavra, virgula)) {
			linhas.push_back(palavra); // ,1[0] , nome[1] , marca[2] , tipo[3], preço[4] , vendas[5] , parceiro[6] , fornecedor[7]
	    }
	    x = stoi(linhas[0]);
	}

    fout.open("BanDados/produtos.txt", ios::out | ios::app); 
    int n; 
    cout << " Informe quantos produtos deseja cadastrar: ";
	cin >> n;
    cin.sync();
    cout << " Informe os dados do " << n << "º produto:" << endl << endl;
    int codigo;
    string nome, marca, tipo, preco, venda, parceiro, fornecedor;
    codigo = x;

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
  		cout << "       Adicionar Produto " << codigo << endl << endl;
  		cout << "Informe o nome do produto: ";
        getline(cin, nome);
        cout << "Informe a marca do produto: ";
        getline(cin, marca);
        cout << "Informe tipo do produto: ";
        getline(cin, tipo);
        cout << "Informe o preco do produto: ";
        getline(cin, preco);
        cout << "Informe a quantidade de produtos vendidos: ";
        getline(cin, venda);
        cout << "Informe o anunciante desse produto: ";
        getline(cin, parceiro);
        cout << "Informe o fornecedor desse produto: ";
        getline(cin, fornecedor);
        cout << endl << endl;
  
        fout << ", "
			 << codigo << ", " // ,1[0] , nome[1] , marca[2] , tipo[3], preço[4] , vendas[5] , parceiro[6] , fornecedor[7]
             << nome << ", "
             << marca << ", "
             << tipo << ", "
             << preco << ", "
             << venda << ", "
             << parceiro << ", "
             << fornecedor
             << endl;
    }
	cout << "               Dados cadastrados com sucesso." << endl;
	timer1();
}

//Excluir Produtos
void excluirpr() {
	
	system("cls"); 
	cout << "		Excluir dados dos produtos" << endl << endl; 
    fstream fin, fout; 
    fin.open("BanDados/produtos.txt", ios::in);
    fout.open("BanDados/attprodutos.txt", ios::out); 
    int linhan1, linhan2, cont = 0; 
    string linha, palavra, temp;
    vector<string> linhas; 
	cout << " Digite o código do produto que deseja excluir os dados: ";
    cin >> linhan1;
    while (fin >> temp) { 
  
        linhas.clear();
        getline(fin, linha); 
        stringstream s(linha); 
  		char virgula = ','; 
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra); // ,1[0] , nome[1] , marca[2] , tipo[3], preço[4] , vendas[5] , parceiro[6] , fornecedor[7]
        }
  
        int row_size = linhas.size(); 
        linhan2 = stoi(linhas[0]); 

        if (linhan2 != linhan1) { 
        	
            if (!fin.eof()) {
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof()) 
            break;
    }
    if (cont == 1) {
        cout << "               Dados excluidos com sucesso." << endl << endl;
        timer1();
    } else {
        cout << "               Dados nao encontrados." << endl << endl;
        timer1();
	}
		
    fin.close();
    fout.close(); 

    remove("BanDados/produtos.txt"); 
    rename("BanDados/attprodutos.txt", "BanDados/produtos.txt");
	
}

//Atualizar Produtos
void atualizarpr() {
	
	system("cls"); 
	cout << "       Atualizar dados dos produtos" << endl << endl;
    fstream fin, fout; 
    fin.open("BanDados/produtos.txt", ios::in); 
    fout.open("BanDados/attprodutos.txt", ios::out);
    int linhan1, linhan2, indice, sub, cont = 0;
    string linha, palavra, novo, temp;
    vector<string> linhas;
    cout << " Digite o código do produto que deseja atualizar os dados: ";
    cin >> linhan1;
    cin.sync();

	cout << endl;
    cout << "       Alterar dados do Fornecedor " << linhan1 << endl << endl;
    cout << " 1. Alterar nome" << endl;
    cout << " 2. Alterar marca" << endl;
    cout << " 3. Alterar tipo" << endl;
    cout << " 4. Alterar preço " << endl;
    cout << " 5. Alterar a quantidade de vendas" << endl;
    cout << " 6. Alterar o anunciante" << endl;
    cout << " 7. Alterar o fornecedor" << endl;
    cout << " Informe uma das opções: ";
    cin >> sub;
  	cin.sync();
  	cout << endl;
  	
  	switch(sub) { 
  		case 1:
  			
  		    cout << "       Alterar nome do produto" << endl << endl;
  			indice = 1;
  			break;
  		case 2:
  			
  			cout << "       Alterar marca do produto" << endl << endl;
  			indice = 2;
  			break;
  		case 3:
  			
  			cout << "       Alterar tipo do produto" << endl << endl;
  			indice = 3;
  			break;
  		case 4:
  			
  		    cout << "       Alterar preço do produto" << endl << endl;
  			indice = 4;
  			break;
  		case 5:
  			
  			cout << "       Alterar quantidade de vendas" << endl << endl;
  			indice = 5;
  			break;
  		case 6:
  			
  			cout << "       Alterar anunciante do produto" << endl << endl;
  			indice = 6;
  			break;
  		case 7:
  			
  			cout << "       Alterar fornecedor do protudo" << endl << endl;
  			indice = 7;
  			break;
  			
  		default:
	        cout << "Opçao Invalida." << endl;
	        atualizarpr();
			break;  			
	  }

    cout << "Informe o dado atualizado: ";
    getline(cin, novo);

    while (fin >> temp) { 
  
        linhas.clear(); 
  
        getline(fin, linha); 
        stringstream s(linha);
        
        char virgula = ','; 
  
        while (getline(s, palavra, virgula)) {
            linhas.push_back(palavra); // ,1[0] , nome[1] , marca[2] , tipo[3], preço[4] , vendas[5] , parceiro[6] , fornecedor[7]
        }
  
        linhan2 = stoi(linhas[0]);
        
        int row_size = linhas.size(); 
  
        if (linhan2 == linhan1) { 
            cont = 1; 
            stringstream convert; 

            convert << novo; 

            linhas[indice] = convert.str(); 
  
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << endl;
            }
        }
        else {
            if (!fin.eof()) { 
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << endl;
            }
        }
        if (fin.eof()) { 
            break;
		}
    }
    if (cont == 1) { 
        cout << "Dados atualizados com Sucesso." << endl;
        timer1();
	} else if (cont == 0) { 
    	cout << "Dados nao encontrados, nao foi Possivel atualizar os dados." << endl << endl;
    	timer1();
    	atualizarpr();
	}

    fin.close(); 
    fout.close(); 

    remove("BanDados/produtos.txt");
    rename("BanDados/attprodutos.txt", "BanDados/produtos.txt");
} 

//Menu Produtos
void mpro(){
	int mp2;
	
	do{
	system("cls");
		cout << "		Menu Produtos" << endl << endl;
		cout << " 1. Listar todos" << endl;
		cout << " 2. Pesquisar produto" << endl;
		cout << " 3. Cadastrar novo" << endl;
		cout << " 4. Atualizar" << endl;
		cout << " 5. Excluir" << endl;
		cout << " 6. Sair" << endl;
		cout << " Informe uma das opções: ";
		cin >> mp2;
		
	switch(mp2) {
		case 1:
			
			listarpr();
			break;
		case 2:
			
			buscarpr();
			break;
		case 3:
			
			cadastrarpr();
			break;
		case 4:
			
			atualizarpr();
			break;
		case 5:
			
			excluirpr();
			break;
		case 6:
			break;
		default:
			
			cout << endl << "		Opção Inválida." << endl;
				system("pause");
			break;
	}
	}while(mp2 != 6);
	
}

int main (){
	
	setlocale(LC_ALL,"Portuguese");
	
	//Declaração de variáveis
	string senha, senha1, senha2;
	int mp1, s, verificacao;
	
	//Atribuição das variáveis
	senha = "GGHardware";
	s = 0;
	
	//Int main()
	do{
		verificacao = 0;
		s++;
		
	system("cls");
	cout << "       Realize o login para continuar." << endl;
	cout << endl;
	cout << "  LOGIN: " << endl;
	cout << " .	 Usuário: ADMINISTRADOR" << endl;
	cout << " .  	 Senha: ";
	
	//Encriptografia de senha
	senha1 = takePasswdFromUser();
	
	//Confirmação da senha.
	if(senha1 == senha) {
	cout << endl << "                               SEJA BEM-VINDO." << endl;
	cout << "                         Carregando Sistema...";
	timer1();
	
	//Tela Inicial
	system("cls");
	cout << endl << "         SEJA BEM-VINDO" << endl << endl;
    dth();
	cout << endl << endl << "         Compromissos do dia:" << endl;
	cout << " *" << endl;
	cout << " * Levantamento de vendas [x]" << endl;
	cout << " * Chegada de peças (Kabum) [ ]" << endl << endl;
	system("pause");
	
	//Menu principal
	do {
		system("cls");
		cout << "		Menu Principal" << endl << endl;
		cout << " Usuário: Administrador" << endl << endl;
		cout << " 1. Produtos" << endl;
		cout << " 2. Clientes" << endl;
		cout << " 3. Fornecedores" << endl;
		cout << " 4. Parceiros" << endl;
		cout << " 5. Ajuda" << endl;
		cout << " 6. Sobre" << endl;
		cout << " 7. Alterar senha" << endl;
		cout << " 8. Logoff" << endl;
		cout << " 9. Sair" << endl;
		cout << " Informe uma das opções: ";
		cin >> mp1;
		
		switch(mp1) {
			case 1:
				
				mpro();
				break;
			case 2:
				
				mcli();
				break;
			case 3:
				
				mfor();
				break;
			case 4:
				
				mpar();
				break;
			case 5:
				
				system("cls");
				cout << "					Ajuda" << endl << endl;
				cout << " O código basea-se em um menu de login para dar acesso ao menu principal, no menu principal" << endl;
				cout << " as escolhas são feitos por um número que representa uma determinada função exibida na tela." << endl << endl;
				cout << "		Menu Principal" << endl << endl;
				cout << " Usuário: Administrador                  No sistema esse é o menu principal, ele representa" << endl;
				cout << " 1. Produtos                             o corpo do software. No menu principal você deve" << endl;
				cout << " 2. Clientes                             digitar um número no teclado e precionar ENTER," << endl;
				cout << " 3. Fornecedores                         cada digito mostrado ao lado levará a uma função" << endl;
				cout << " 4. Parceiros                            especifica, caso coloque um digito errado o" << endl;
				cout << " 5. Ajuda                                sistema mostrará uma mensagem de erro, e dará" << endl;
				cout << " 6. Sobre                                a opção de digitar novamente." << endl;
				cout << " 7. Logoff" << endl;
				cout << " 8. Sair" << endl;
				cout << " Informe uma das opções: " << endl << endl;
				cout << "		Menu Parceiros" << endl << endl;
				cout << " 1. Listar todos                         Exemplo (Menu Parceiros): Os menus secundários" << endl;
				cout << " 2. Pesquisar parceiro                   seguem o mesmo princípio do menu principal. Logo" << endl;
				cout << " 3. Cadastrar novo                       você deve digitar um número no teclado e" << endl;
				cout << " 4. Atualizar                            precionar ENTER, cada digito mostrado ao lado" << endl;
				cout << " 5. Excluir                              levará a uma função especifica." << endl;
				cout << " 6. Sair" << endl;
				cout << " Informe uma das opções: " << endl << endl;
				cout << " Pressione qualquer tecla para continuar. . .       Esta opção pausa o sistema até você" << endl;
				cout << "                                                    digitar qualquer tecla, após isso" << endl;
				cout << "                                                    o sistema continua." << endl << endl;
				cout << "                                                    Diretos Reservados © Trilhas Sistemas G3" << endl;
				system("pause");
				break;
			case 6:
				
				system("cls");
				cout << "					Sobre" << endl << endl;
				cout << " Este código foi desenvolvido por Gabriel Gomes, Maria Eduarda Lopes, Henrique Rodrigues. " << endl;
				cout << " Atualmente na versão alpha 1.4.7, foi construido com o intuito de controle para clientes," << endl;
				cout << " produtos, fornecedores, parceiros, etc, quando requisitado pelo diretor geral da empresa" << endl;
				cout << " GGHARDWARE (produto feito especialmente para o mesmo), o sistema usa a interação entre " << endl;
				cout << " menus atravez de escolhas numericas para as funções, utiliza tambem um sistema de banco " << endl;
				cout << " de dados para armazenar as informações ja estabelecidas, (Para mais informações do uso do " << endl;
				cout << " código acesse o menu AJUDA, atravez do menu PRINCIPAL)." << endl << endl;
				cout << " Versão: alpha 1.4.7, essa versão foi desenvovida para atender as necessidades básicas da" << endl;
				cout << " empresa solicitante. O menu de login e limitado apenas ao administrador pois o solicitante" << endl;
				cout << " informou que não haveria necessidade de usar um banco de dados para armazenamento de" << endl;
				cout << " usuário e senha. " << endl << endl;
				cout << "					Contatos" << endl << endl;
				cout << " Gabriel Gomes (Técnico): (31) 999876543, ggomes.sistemas@gmail.com" << endl;
				cout << " Maria Eduarda (Técnico): (31) 977542103, meduarda.sistemas@gmail.com" << endl;
				cout << " Henrique Rodrigues (Técnico): (31) 922654128, hrodrigues.sistemas@gmail.com" << endl;
				cout << " Wellington Santos (Gerente Geral): (31) 966554433, wsantos.sistemas@gmail.com" << endl;
				cout << " Laila de Fatima (Recursos Humanos): (31) 975843900, lfatima.sistemas@gmail.com" << endl << endl;;
				cout << "							Diretos Reservados © Trilhas Sistemas G3" << endl;
				system("pause");
				break;
			case 7:
				
				system("cls");
				cout << "					Alteração de senha" << endl << endl;
				cout << " Digite a senha antiga: ";
				
				//Encriptografia de senha
				senha2 = takePasswdFromUser();
				
				if(senha2 == senha) {
					
					cout << endl << " Digite a nova senha: ";
					
					//Encriptografia de senha
					senha = takePasswdFromUser();
					
				} else{
					cout << endl << "					Senha incorreta.";
					timer1();	
				}
				break;
			case 8:
				
				logoff();
				s = 0;
				verificacao = 1;
				break;
			case 9:
				
				finalizacao();
				exit(0);
				break;
			default:
				
				cout << endl << "		Opção Inválida." << endl;
				system("pause");
				
		}
	} while(mp1 != 8);
	}
		
	//Erro da senha.	
	if (s < 3 and verificacao == 0){
 	cout << endl << "                               Acesso Negado.";
 	cout << endl << "                             Tente Novamente." << endl;
 	cout << endl;
 	system("pause");
 	system("cls");
 	}
 	
	//Erro senha tentativas 	
	if(s < 5 and s > 2){
		cout << endl << "                               Acesso Negado.";
 		cout << endl << "                             Tente Novamente.";
 		cout << endl << "    (Caso não consiga realizar o login entre,";
 		cout << endl << "     em contato com o administrador de rede.)" << endl;
 		cout << endl;
 		system("pause");
 		system("cls");
 	}
	
	if(s == 5){
		cout << endl << "                               Acesso Negado.";
 		cout << endl << "                     Por razões de segurança,"; 
		cout << endl << "                   o programa será encerrado." << endl;
		timer1();
 		exit(0);
	} 
	
	}while (1 == 1);

	return 0;		
}
