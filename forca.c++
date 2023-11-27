
#include "forca.hpp"
#include "read_string.hpp"
#include "lib.c++"
#include "random_choice.hpp"

// using namespace std;

int main(){
    
    welcome();
    read_string();

    std::cout << std::endl;
    std::cout << std::endl;

    warning();
    bool nao_acertou = true;
    bool ganhou = false;

    while ( nao_acertou && !ganhou )
    {
        show_choice_error(); 
        
        Is_valid();

        chuta();
        if( !get_number_choices() ) nao_acertou = false;
        if_champion( &ganhou );
    }
    


    if ( !nao_acertou )
    {
        std::cout << "Você não acertou, tente novamente" << std::endl;
    }
    
    game_over();
    verify_add();
    clear();

}