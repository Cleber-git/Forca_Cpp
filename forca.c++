
#include "lib.hpp"
#include "read_string.hpp"
#include "lib.c++"

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
        
        if(interador == 3){
            if_champion(&ganhou);
            Is_valid();
            
            cout << endl;
            cout<< "Chute qual é a palavra secreta: ";
            string s_palavra;
            cin >> s_palavra;
            interador = 0;
            if( s_palavra == NOME_SECRETO ){
                cout <<"================================================="<< endl; 
                cout <<"|| PARABÉNS!! Você desvendou a palavra secreta ||"<< endl;
                cout <<"================================================="<< endl;
                cout << endl;
                ganhou = true;
            }
        }
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