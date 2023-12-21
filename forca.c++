
#include "lib.hpp"
#include "read_string.hpp"

using namespace std;
const char ADICIONAR = '+';
const char SAIR = 'q' || 'Q';
std::string NOME_SECRETO;


int main(){
    bool ADD = false;
    int interador = 0;
    int QTD = 0;
    int old_number=0;
    int current_number = 0;
    int SIZE_SECRET_NAME = NOME_SECRETO.size();
    std::map<char, bool> chutou;
    std::vector<char> chutes_errados;
    std::vector<std::string> palavras;

    welcome();
    read_string(&QTD, &old_number, &current_number, &palavras, &NOME_SECRETO, &SIZE_SECRET_NAME);

    cout << endl;
    cout << endl;

    warning();
    bool nao_acertou = true;
    bool ganhou = false;

    while ( nao_acertou && !ganhou )
    {
        show_choice_error(chutes_errados); 
        
        Is_valid(NOME_SECRETO, chutou);

        chuta(&chutes_errados, &chutou, NOME_SECRETO, &interador);
        
        if(interador == 3){
            if_champion(&ganhou, NOME_SECRETO, chutou, SIZE_SECRET_NAME);
            Is_valid(NOME_SECRETO, chutou);
            
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
        if( !get_number_choices(chutes_errados) ) nao_acertou = false;
        if_champion( &ganhou, NOME_SECRETO, chutou, SIZE_SECRET_NAME);
    }
    


    if ( !nao_acertou )
    {
        cout << "Você não acertou, tente novamente" << endl;
    }
    
    game_over(NOME_SECRETO);
    verify_add(&palavras, &ADD, ADICIONAR, SAIR );
    clear();

}