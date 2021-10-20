#include "input.h"
void enter(int choice){         // Função para perguntar se quer continuar depois de cada ação.
	cout << "OperaÃ§Ã£o realizada! Deseja voltar ao menu inicial? (1 - Sim; 2 - NÃ£o)\n";
	cin >> choice;
        if (choice == 1){
            user_interactions();}
        
        if (choice== 2){
            cout << "Volte sempre!\n";}
           }
void user_interactions(){
    // cout << "teste\n";
    // Product pr("Abacate", 5);
    // product_stock_files::create(pr);
    // product_stock_files::remove(986);
    // product_stock_files::update(895, 50);
    // string xd = "Abacate";
    // product_stock_files::update(895, 0, xd);
    // auto x = product_stock_files::get(895);

    // cout pr.name; (acessar parametros pr)

    #ifdef cplusplus
    #include <cstdlib>
    #else
    #include <stdlib.h>
    #endif
    if (system("CLS")) system("clear");

    int entry;
    int choice;
    unsigned short int uid;
    string name;
    int quantity;
    

    cout << "Seja bem-vindo ao controle de inventÃ¡rio!\n O que vocÃª deseja fazer?\n 1 - Adicionar venda\n 2 - Inserir novo produto no estoque\n 3 - Alterar produto\n 4 - Remover produto\n 5 - Emitir relatÃ³rio\n 6 - Sair\n";
    
    cin >> entry;

    if (entry == 1){
        cout << "Qual Ã© o cÃ³digo do produto vendido?\n";
        cin >> entry;
        cout << "Qual foi a quantidade vendida?\n";
        cin >> entry;
        enter(choice);

        
    }

    if (entry == 2){
    	cout << "Qual Ã© o nome do produto que se deseja adicionar?\n";
    	cin.ignore();
    	getline(cin,name);
    	product_stock_files::product_exists_in_stock(name);
		if (product_stock_files::product_exists_in_stock(name)==false){
    	cout << "Quantos produtos estÃ£o entrando no estoque?\n";
    	cin>>quantity;
    	Product pr(name, quantity);
		product_stock_files::create(pr); 
        enter(choice);}
        else if (product_stock_files::product_exists_in_stock(name)==true){
			cout<<"O Produto ja existe no estoque.\n"<<"Entre novamente.\n";
			cout << "Deseja voltar ao menu inicial? (1 - Sim; 2 - NÃ£o)\n";
			cin >> choice;
			if (choice == 1){
			user_interactions();}
			if (choice== 2){
            cout << "Volte sempre!\n";}
           }
        
    }
    if (entry == 3){
        cout << "Qual o cÃ³digo do produto que se deseja alterar?\n";
        cin >> uid;
        cout << "O que vocÃª deseja alterar? (1 - Nome; 2 - Quantidade)\n";
        cin >> entry;
        if (entry == 1){
	    auto pr = product_stock_files::get(uid);
	    cout<< "O Nome atual do produto Ã© "<<pr.name<<endl; 
            cout << "Insira o novo nome:\n";
            string new_name;
            cin.ignore();
            getline(cin,new_name);
            product_stock_files::update(uid, 0, new_name);
            
            
            
        }
        else if (entry == 2){
	    auto pr = product_stock_files::get(uid);
	    cout<<"A quantidade atual do produto Ã© "<<pr.quantity<<endl; 
            cout << "Insira a nova quantidade:\n";
            int new_quantity;
            cin>>new_quantity;
            product_stock_files::update(uid,new_quantity );
        }
        enter(choice);
    }

    if (entry == 4){
    	cout << "Qual o codigo do produto que se deseja remover?\n";
        cin >> uid;
	auto pr = product_stock_files::get(uid);
        cout<<"O produto "<<pr.name<<" foi removido do estoque"<<endl; 
        Product get(unsigned short int uid);
        product_stock_files::remove(uid);
        enter(choice);
    }

    if (entry == 5){
        cout << "Existem x tipos de produtos cadastrados na base, totalizando x produtos no estoque. A lista encontra-se a seguir:\n";
        cout << "cÃ³digo ----------- nome --------- quantidade\n";
        
    }
    if (entry == 6){
        return;
    }

}


