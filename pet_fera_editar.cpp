#include "pet_fera.h"

void alterar_dados(map <int, ANFIBIO_NATIVO> &anfibios_nat, map <int, ANFIBIO_EXOTICO> &anfibios_ex, map <int, MAMIFERO_NATIVO> &mamiferos_nat, map <int, MAMIFERO_EXOTICO> &mamiferos_ex, map <int, REPTIL_NATIVO> &repteis_nat, map <int, REPTIL_EXOTICO> &repteis_ex, map <int, AVE_NATIVO> &aves_nat, map <int, AVE_EXOTICO> &aves_ex){
		char tipo_animal, opcao;
		char resp, op='s';

		do{  
			cout << "Qual animal deseja editar? \n a - anfíbio\n m - mamífero \n r - reptil \n v - ave" << endl;
			cin >> tipo_animal;
			if(tipo_animal != 'a' && tipo_animal != 'm' && tipo_animal != 'r' && tipo_animal != 'v' ){
				cout << "Opção inválida!! Tente novamente!\n" << endl;
				cout << endl;
				cout << "Deseja sair? s/n" << endl;
				cin >> resp;
					if(resp == 's'){
						break;
					}
			}
				else{
					cout << "É nativo ou exotico? \n n - NATIVO\n e - EXOTICO" << endl;
					cin >> opcao;
					if(opcao != 'n' && opcao != 'e'){
						cout << "Opção inválida!! Tente novamente!\n" << endl;
						cout << endl;
						cout << "Deseja sair? s/n" << endl;
						cin >> resp;
						if(resp == 's'){
							break;
						}	
					}

					else{ 
						if(tipo_animal == 'a' && opcao == 'n'){
							int id_buscado;

							cout << "Insira o ID buscado: " << endl;
							cin >> id_buscado;

							auto result = anfibios_nat.find(id_buscado);
						
							if(result != anfibios_nat.end()){
								cout << "ID existe!" << endl;

								int total_mudas;
								string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, ultima_muda;
								char sexo;;
								double tamanho;
								ofstream nativos;

								cout << "Digite a classe: " << endl;
								cin.ignore();
								getline(cin, classe);
								cout << "Digite o nome científico: " << endl;
								getline(cin, nome_cientifico);
								cout << "Digite a dieta: " << endl;
								getline(cin, dieta);
								cout << "Digite o nome do veterinario: " << endl;
								getline(cin, veterinario);
								cout << "Digite o nome do tratador: " << endl;
								getline(cin, tratador);
								cout << "Digite o nome de batismo: " << endl;
								getline(cin, nome_batismo);
								cout << "Digite o sexo do animal: " << endl;
								cin >> sexo;
								cout << "Digite o tamanho do animal: " << endl;
								cin >> tamanho;
								cout << "Insira o total de mudas:" << endl;
								cin >> total_mudas;
								cout << "Insira a data da última muda(D/M/A)" << endl;
								cin.ignore();
								getline(cin, ultima_muda);
								cout << "Insira a autorizacao do IBAMA: " << endl;
								getline(cin, autorizacao_IBAMA);
								cout << "Digite a UF de origem: " << endl;
								getline(cin, origem);
								cout << "Insira a autorizacao do animal: " << endl;
								getline(cin, autorizacao);

								(*result).second = ANFIBIO_NATIVO(id_buscado, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, total_mudas, ultima_muda, autorizacao_IBAMA, origem, autorizacao);
								
								if(!anfibios_nat.empty()){
									nativos.open("anfibios_nat.txt");
									for(auto it = anfibios_nat.begin(); it != anfibios_nat.end(); it++){
										nativos << (*it).second;
									}
									nativos.close();
								}

								cout << "Editar outro ?" << endl;
								cin >> op;

							}
						}
						else if(tipo_animal == 'a' && opcao == 'e'){
							int id_buscado;
							int total_mudas;
							string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, ultima_muda;
							char sexo;;
							double tamanho;
							ofstream exoticos;

							cout << "Insira o ID buscado: " << endl;
							cin >> id_buscado;

							auto result = anfibios_ex.find(id_buscado);
						
							if(result != anfibios_ex.end()){
								cout << "ID existe!" << endl;

								cout << "Digite a classe: " << endl;
								cin.ignore();
								getline(cin, classe);
								cout << "Digite o nome científico: " << endl;
								getline(cin, nome_cientifico);
								cout << "Digite a dieta: " << endl;
								getline(cin, dieta);
								cout << "Digite o nome do veterinario: " << endl;
								getline(cin, veterinario);
								cout << "Digite o nome do tratador: " << endl;
								getline(cin, tratador);
								cout << "Digite o nome de batismo: " << endl;
								getline(cin, nome_batismo);
								cout << "Digite o sexo do animal: " << endl;
								cin >> sexo;
								cout << "Digite o tamanho do animal: " << endl;
								cin >> tamanho;
								cout << "Insira o total de mudas:" << endl;
								cin >> total_mudas;
								cout << "Insira a data da última muda(D/M/A)" << endl;
								cin.ignore();
								getline(cin, ultima_muda);
								cout << "Insira a autorizacao do IBAMA: " << endl;
								getline(cin, autorizacao_IBAMA);
								cout << "Digiteo País de origem: " << endl;
								getline(cin, origem);
								cout << "Insira a autorizacao do animal: " << endl;
								getline(cin, autorizacao);

								(*result).second = ANFIBIO_EXOTICO(id_buscado, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, total_mudas, ultima_muda, autorizacao_IBAMA, origem, autorizacao);
								
								if(!anfibios_ex.empty()){
									exoticos.open("anfibios_ex.txt");
									for(auto it = anfibios_ex.begin(); it != anfibios_ex.end(); it++){
										exoticos << (*it).second;
									}
									exoticos.close();
								}

								cout << "Deseja editar outro ? s/n" << endl;
								cin >> op;

							}
						}
						else if(tipo_animal == 'm' && opcao == 'n'){
							int id_buscado;
							string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, cor;
							char sexo;;
							double tamanho;
							ofstream nativos;

							cout << "Insira o ID buscado: " << endl;
							cin >> id_buscado;

							auto result = mamiferos_nat.find(id_buscado);
						
							if(result != mamiferos_nat.end()){
								cout << "ID existe!" << endl;

								cout << "Digite a classe: " << endl;
								cin.ignore();
								getline(cin, classe);
								cout << "Digite o nome científico: " << endl;
								getline(cin, nome_cientifico);
								cout << "Digite a dieta: " << endl;
								getline(cin, dieta);
								cout << "Digite o nome do veterinario: " << endl;
								getline(cin, veterinario);
								cout << "Digite o nome do tratador: " << endl;
								getline(cin, tratador);
								cout << "Digite o nome de batismo: " << endl;
								getline(cin, nome_batismo);
								cout << "Digite o sexo do animal: " << endl;
								cin >> sexo;
								cout << "Digite o tamanho do animal: " << endl;
								cin >> tamanho;
								cout << "Digite a cor do pelo: " << endl;
								cin.ignore();
								getline(cin, cor);
								cout << "Insira a autorizacao do IBAMA: " << endl;
								getline(cin, autorizacao_IBAMA);
								cout << "Digite a UF de origem: " << endl;
								getline(cin, origem);
								cout << "Insira a autorizacao do animal: " << endl;
								getline(cin, autorizacao);


								(*result).second = MAMIFERO_NATIVO(id_buscado, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, cor, autorizacao_IBAMA, origem, autorizacao);
								
								if(!mamiferos_nat.empty()){
									nativos.open("mamiferos_nat.txt");
									for(auto it = mamiferos_nat.begin(); it != mamiferos_nat.end(); it++){
										nativos << (*it).second;
									}
									nativos.close();
								}

								cout << "Deseja editar outro ? s/n" << endl;
								cin >> op;
								
								}
							}
						
						else if(tipo_animal == 'm' && opcao == 'e'){
							int id_buscado;
							string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, cor;
							char sexo;;
							double tamanho;
							ofstream exoticos;

							cout << "Insira o ID buscado: " << endl;
							cin >> id_buscado;

							auto result = mamiferos_ex.find(id_buscado);
						
							if(result != mamiferos_ex.end()){
								cout << "ID existe!" << endl;

								cout << "Digite a classe: " << endl;
								cin.ignore();
								getline(cin, classe);
								cout << "Digite o nome científico: " << endl;
								getline(cin, nome_cientifico);
								cout << "Digite a dieta: " << endl;
								getline(cin, dieta);
								cout << "Digite o nome do veterinario: " << endl;
								getline(cin, veterinario);
								cout << "Digite o nome do tratador: " << endl;
								getline(cin, tratador);
								cout << "Digite o nome de batismo: " << endl;
								getline(cin, nome_batismo);
								cout << "Digite o sexo do animal: " << endl;
								cin >> sexo;
								cout << "Digite o tamanho do animal: " << endl;
								cin >> tamanho;
								cout << "Digite a cor do pelo: " << endl;
								cin.ignore();
								getline(cin, cor);
								cout << "Insira a autorizacao do IBAMA: " << endl;
								getline(cin, autorizacao_IBAMA);
								cout << "Digiteo País de origem: " << endl;
								getline(cin, origem);
								cout << "Insira a autorizacao do animal: " << endl;
								getline(cin, autorizacao);


								(*result).second = MAMIFERO_EXOTICO(id_buscado, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, cor, autorizacao_IBAMA, origem, autorizacao);
								
								if(!mamiferos_ex.empty()){
									exoticos.open("mamiferos_ex.txt");
									for(auto it = mamiferos_ex.begin(); it != mamiferos_ex.end(); it++){
										exoticos << (*it).second;
									}
									exoticos.close();
								}
								cout << "Deseja editar outro ? s/n" << endl;
								cin >> op;
							}	
						}

						else if(tipo_animal == 'r' && opcao == 'n'){
							int id_buscado;
							string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, tipo_veneno;
							char sexo;
							double tamanho;
							bool venenoso;
							ofstream nativos;

							cout << "Insira o ID buscado: " << endl;
							cin >> id_buscado;

							auto result = repteis_nat.find(id_buscado);
						
							if(result != repteis_nat.end()){
								cout << "ID existe!" << endl;

								cout << "Digite a classe: " << endl;
								cin.ignore();
								getline(cin, classe);
								cout << "Digite o nome científico: " << endl;
								getline(cin, nome_cientifico);
								cout << "Digite a dieta: " << endl;
								getline(cin, dieta);
								cout << "Digite o nome do veterinario: " << endl;
								getline(cin, veterinario);
								cout << "Digite o nome do tratador: " << endl;
								getline(cin, tratador);
								cout << "Digite o nome de batismo: " << endl;
								getline(cin, nome_batismo);
								cout << "Digite o sexo do animal: " << endl;
								cin >> sexo;
								cout << "Digite o tamanho do animal: " << endl;
								cin >> tamanho;
								cout << "Digite 0-não venenoso / 1-venenoso: " << endl;
								cin >> venenoso;
								if(venenoso){
									cout << "Digite o tipo do veneno: " << endl;
									cin.ignore();
									getline(cin, tipo_veneno);
								}else{
									cin.ignore();
								}
								cout << "Insira a autorizacao do IBAMA: " << endl;
								getline(cin, autorizacao_IBAMA);
								cout << "Digite a UF de origem: " << endl;
								getline(cin, origem);
								cout << "Insira a autorizacao do animal: " << endl;
								getline(cin, autorizacao);

								(*result).second = REPTIL_NATIVO(id_buscado, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, venenoso, tipo_veneno, autorizacao_IBAMA, origem, autorizacao);
								
								if(!repteis_nat.empty()){
									nativos.open("repteis_nat.txt");
									for(auto it = repteis_nat.begin(); it != repteis_nat.end(); it++){
										nativos << (*it).second;
									}
									nativos.close();
								}

								cout << "Deseja editar outro ? s/n" << endl;
								cin >> op;
								
								}
						}
						else if(tipo_animal == 'r' && opcao == 'e'){
						int id_buscado;
							string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem, tipo_veneno;
							char sexo;
							double tamanho;
							bool venenoso;
							ofstream exoticos;

							cout << "Insira o ID buscado: " << endl;
							cin >> id_buscado;

							auto result = repteis_ex.find(id_buscado);
						
							if(result != repteis_ex.end()){
								cout << "ID existe!" << endl;

								cout << "Digite a classe: " << endl;
								cin.ignore();
								getline(cin, classe);
								cout << "Digite o nome científico: " << endl;
								getline(cin, nome_cientifico);
								cout << "Digite a dieta: " << endl;
								getline(cin, dieta);
								cout << "Digite o nome do veterinario: " << endl;
								getline(cin, veterinario);
								cout << "Digite o nome do tratador: " << endl;
								getline(cin, tratador);
								cout << "Digite o nome de batismo: " << endl;
								getline(cin, nome_batismo);
								cout << "Digite o sexo do animal: " << endl;
								cin >> sexo;
								cout << "Digite o tamanho do animal: " << endl;
								cin >> tamanho;
								cout << "Digite 0-não venenoso / 1-venenoso: " << endl;
								cin >> venenoso;
								if(venenoso){
									cout << "Digite o tipo do veneno: " << endl;
									cin.ignore();
									getline(cin, tipo_veneno);
								}else{
									cin.ignore();
								}
								cout << "Insira a autorizacao do IBAMA: " << endl;
								getline(cin, autorizacao_IBAMA);
								cout << "Digite o País de origem: " << endl;
								getline(cin, origem);
								cout << "Insira a autorizacao do animal: " << endl;
								getline(cin, autorizacao);


								(*result).second = REPTIL_EXOTICO(id_buscado, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, venenoso, tipo_veneno, autorizacao_IBAMA, origem, autorizacao);
								
								if(!repteis_ex.empty()){
									exoticos.open("repteis_ex.txt");
									for(auto it = repteis_ex.begin(); it != repteis_ex.end(); it++){
										exoticos << (*it).second;
									}
									exoticos.close();
								}

								cout << "Deseja editar outro ? s/n" << endl;
								cin >> op;
								
								}
						}	

						
						else if(tipo_animal == 'v' && opcao == 'n'){
							int id_buscado;
							string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem;
							char sexo;
							double tamanho;
							double envergadura, tam_bico;
							ofstream nativos;

							cout << "Insira o ID buscado: " << endl;
							cin >> id_buscado;

							auto result = aves_nat.find(id_buscado);
						
							if(result != aves_nat.end()){
								cout << "ID existe!" << endl;

								cout << "Digite a classe: " << endl;
								cin.ignore();
								getline(cin, classe);
								cout << "Digite o nome científico: " << endl;
								getline(cin, nome_cientifico);
								cout << "Digite a dieta: " << endl;
								getline(cin, dieta);
								cout << "Digite o nome do veterinario: " << endl;
								getline(cin, veterinario);
								cout << "Digite o nome do tratador: " << endl;
								getline(cin, tratador);
								cout << "Digite o nome de batismo: " << endl;
								getline(cin, nome_batismo);
								cout << "Digite o sexo do animal: " << endl;
								cin >> sexo;
								cout << "Digite o tamanho do animal: " << endl;
								cin >> tamanho;
								cout << "Digite o tamanho do bico: " << endl;
								cin >> tam_bico;
								cout << "Digite a envergadura: " << endl;
								cin >> envergadura;
								cout << "Insira a autorizacao do IBAMA: " << endl;
								cin.ignore();
								getline(cin, autorizacao_IBAMA);
								cout << "Digite a UF de origem: " << endl;
								getline(cin, origem);
								cout << "Insira a autorizacao do animal: " << endl;
								getline(cin, autorizacao);

								(*result).second = AVE_NATIVO(id_buscado, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, tam_bico, envergadura, autorizacao_IBAMA, origem, autorizacao);
								
								if(!aves_nat.empty()){
									nativos.open("aves_nat.txt");
									for(auto it = aves_nat.begin(); it != aves_nat.end(); it++){
										nativos << (*it).second;
									}
									nativos.close();
								}

								cout << "Deseja editar outro ? s/n" << endl;
								cin >> op;
								
								}
						}	

						else if(tipo_animal == 'v' && opcao == 'e'){
						int id_buscado;
							string classe, nome_cientifico, dieta, veterinario, tratador, nome_batismo, autorizacao, autorizacao_IBAMA, origem;
							char sexo;
							double tamanho;
							double envergadura, tam_bico;
							ofstream exoticos;

							cout << "Insira o ID buscado: " << endl;
							cin >> id_buscado;

							auto result = aves_ex.find(id_buscado);
						
							if(result != aves_ex.end()){
								cout << "ID existe!" << endl;

								cout << "Digite a classe: " << endl;
								cin.ignore();
								getline(cin, classe);
								cout << "Digite o nome científico: " << endl;
								getline(cin, nome_cientifico);
								cout << "Digite a dieta: " << endl;
								getline(cin, dieta);
								cout << "Digite o nome do veterinario: " << endl;
								getline(cin, veterinario);
								cout << "Digite o nome do tratador: " << endl;
								getline(cin, tratador);
								cout << "Digite o nome de batismo: " << endl;
								getline(cin, nome_batismo);
								cout << "Digite o sexo do animal: " << endl;
								cin >> sexo;
								cout << "Digite o tamanho do animal: " << endl;
								cin >> tamanho;
								cout << "Digite o tamanho do bico: " << endl;
								cin >> tam_bico;
								cout << "Digite a envergadura: " << endl;
								cin >> envergadura;
								cout << "Insira a autorizacao do IBAMA: " << endl;
								cin.ignore();
								getline(cin, autorizacao_IBAMA);
								cout << "Digite o País de origem: " << endl;
								getline(cin, origem);
								cout << "Insira a autorizacao do animal: " << endl;
								getline(cin, autorizacao);

								(*result).second = AVE_EXOTICO(id_buscado, classe, nome_cientifico, sexo, tamanho, dieta, veterinario, tratador, nome_batismo, tam_bico, envergadura, autorizacao_IBAMA, origem, autorizacao);
								
								if(!aves_ex.empty()){
									exoticos.open("aves_ex.txt");
									for(auto it = aves_ex.begin(); it != aves_ex.end(); it++){
										exoticos << (*it).second;
									}
									exoticos.close();
								}

								cout << "Deseja editar outro ? s/n" << endl;
								cin >> op;
								
								}
							}

					}
				}			

	}while(op == 's');

}