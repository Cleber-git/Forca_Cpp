#ifndef _LIB_HPP
#define _LIB_HPP

#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <ctime>
#include <cstdlib>



#define ADICIONAR '+'
#define SAIR 'q' || 'Q'

int QTD;

int old_number;
int current_number = 0;
std::string NOME_SECRETO;
int SIZE_SECRET_NAME = NOME_SECRETO.size();
std::map<char, bool> chutou;
std::vector<char> chutes_errados;
std::vector<std::string> palavras;
int interador;

int random_choice();
bool cont();
void warning();
void chuta();
void show_choice_error();
void add_choice_error( char chute);
void if_champion( bool *ganhou);
void welcome();
bool get_number_choices();
void Validation_of_information(char chute);
void Is_valid();
bool verify(char chute);
bool equal_number(int old_number, int current_number);
void clear();
void menu();
void verify_add();
void game_over();
#endif