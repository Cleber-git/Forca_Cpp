#include "read_string.hpp"
#include "lib.hpp"






std::string read_string(int *QTD, int *old_number, int *current_number, std::vector<std::string>*palavras, std::string *NOME_SECRETO, int *SIZE_SECRET_NAME) {
    
    std::ifstream arquivo;
    arquivo.open("palavas.txt");

    if(!arquivo.is_open()) {std::cout << "Seu arquivo não pôde ser aberto. Tente novamente!" << std::endl; exit(1);}

    arquivo >> (*QTD);
    std::string palavra_lida;

    for (int i = 0; i < (*QTD); i++)
    {
        arquivo >> palavra_lida;
        palavras->push_back(palavra_lida);

    }

    arquivo.close();


    old_number = current_number;
    
    int index = random_choice((*QTD));
    if ((*old_number) == index)
    {   
        std::cout << "Indice se repetiu e está passando pelo tratamento"<< std::endl;
        index = random_choice((*QTD));
        (*current_number) = index;
        
    }else{ (*current_number) = index;}

    if ((*current_number) == 0) {std::cout << (*current_number) << std::endl;}

    (*NOME_SECRETO) = (*palavras)[(*current_number)];
    (*SIZE_SECRET_NAME) = NOME_SECRETO->size();
   

    return (*NOME_SECRETO);
}