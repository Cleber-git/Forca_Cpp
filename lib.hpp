#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <ctime>
#include <cstdlib>


int random_choice(int QTD);
bool cont(std::string NOME_SECRETO, std::map<char, bool> chutou, int SIZE_SECRET_NAME);//certo
void warning();//certo
void chuta(std::vector<char>* chutes_errados, std::map<char, bool>* chutou, std::string NOME_SECRETO, int* interador);
void show_choice_error(std::vector<char> chutes_errados);
void add_choice_error(char chute, std::vector<char>*chutes_errados, std::string NOME_SECRETO);
void if_champion(bool* ganhou, std::string NOME_SECRETO, std::map<char, bool> chutou, int SIZE_SECRET_NAME);
void welcome();
bool get_number_choices(std::vector<char> chutes_errados);
void Validation_information(char chute, std::map<char, bool> *chutou, std::string NOME_SECRETO, int* interador);
void Is_valid(std::string NOME_SECRETO, std::map<char, bool> chutou);
bool verify(char chute, std::string NOME_SECRETO);
bool equal_number(int old_number, int current_number);
void clear();
void menu();
void verify_add(std::vector<std::string>* palavras, bool* ADD, const char ADICIONAR, const char SAIR);
void game_over(std::string NOME_SECRETO);
