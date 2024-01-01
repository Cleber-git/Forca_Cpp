
#include "lib.hpp"
#include "read_string.hpp"

using namespace std;
static std::string NOME_SECRETO;


int main(){

    // declaração de variáveis

    bool ADD = false;
    int interador = 0;
    int QTD = 1;
    int old_number=0;
    int current_number = 0;
    int SIZE_SECRET_NAME = NOME_SECRETO.size();
    std::map<char, bool> chutou;
    std::array<char, 5> chutes_errados={0};
    int array_c = 0;
    std::vector<std::string> palavras;

    lib::welcome();
    read::read_string(QTD, old_number, current_number, palavras, NOME_SECRETO, SIZE_SECRET_NAME); // Função para escolher a letra secreta.

    cout << endl;
    cout << endl;

    lib::warning();
    bool nao_acertou = true;
    bool ganhou = false;

    while ( nao_acertou && !ganhou )
    {
        lib::show_choice_error(chutes_errados); // Verificar na array se tem algum chute errado e exibir na tela

        lib::Is_valid(NOME_SECRETO, chutou);

        lib::chuta(array_c ,chutes_errados, chutou, NOME_SECRETO, interador);
        
        if( interador == 3 ){

            lib::if_champion(ganhou, NOME_SECRETO, chutou, SIZE_SECRET_NAME); // Verificar se o usuário já acertou todas as  palavras
            lib::Is_valid(NOME_SECRETO, chutou); // Verifica se o chute do usuário é correto e exibe no formato de palavras de forca
            
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
        if( !lib::get_number_choices(chutes_errados) ) nao_acertou = false; // verifica o número de erros.
        lib::if_champion( ganhou, NOME_SECRETO, chutou, SIZE_SECRET_NAME);

    }
    


    if ( !nao_acertou )
    {
        cout << "Você não acertou, tente novamente" << endl;
    }

    lib::game_over(NOME_SECRETO);
    lib::verify_add(palavras, ADD );
    lib::clear(old_number, current_number, QTD, SIZE_SECRET_NAME, NOME_SECRETO, chutou, chutes_errados, palavras);

}