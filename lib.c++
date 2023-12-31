#include "lib.hpp"

using namespace std;


namespace lib {
    bool equal_number(int old_number, int current_number) {
        return old_number == current_number;
    }

    int random_choice(int QTD) {

        srand(time(NULL));
        int secret_number = rand() % QTD;


        return secret_number;
    }

    bool cont(std::string NOME_SECRETO, std::map<char, bool> &chutou, int SIZE_SECRET_NAME) {

        int i = 0;
        for (char letra: NOME_SECRETO) {

            if (chutou[letra]) {
                i++;
            }
        }
        if (i == SIZE_SECRET_NAME) {
            return true;
        }
        return false;
    }

    void Is_valid(const std::string NOME_SECRETO, const std::map<char, bool> &chutou) {

        for (char letra: NOME_SECRETO) {
            if (chutou.find(letra) == chutou.end() || !chutou.at(letra)) {
                cout << "_ ";
            } else {
                cout << letra << " ";

            }

        }

    }

    void Validation_information(const char chute, map<char, bool> &chutou, const std::string NOME_SECRETO, int &interador) {

        for (char letra: NOME_SECRETO) {
            if (chute == letra) {
                chutou[letra] = true;
                interador++;
                break;
            }
        }
    }

    void menu() {

        cout << endl;
        cout << endl;
        cout << "   //////////////////////////////////////" << endl;
        cout << "   //////////////// MENU ////////////////" << endl;
        cout << "   //////////////////////////////////////" << endl;
        cout << endl;
        cout << endl;

        cout << "COMANDOS ESPECIAIS:" << endl;
        cout << " + : Adicionar mais uma fruta ao banco de dados." << endl;
        cout << " q : Sair do jogo." << endl;

        cout << endl;
        cout << endl;

    }


    bool get_number_choices(std::array<char, 6> &chutes_errados) {
        int index = 0;
        for (char chutes : chutes_errados) {
            if (chutes) {
                index++;
            }
        }
        std::cout << index << std::endl;
        return index < 5;
    }


    void verify_add(std::vector<std::string> &palavras, bool &ADD) {

          menu();

        char chute;
        cout << "Escolha o que quer fazer agora: ";
        cin >> chute;

        switch (chute) {
            case '+':
                ADD = true;
                break;
            case 'q' || 'Q':

            default:
                break;
        }
        string new_add;

        if (ADD) {
            ofstream file;
            file.open("palavas.txt");
            if (!file.is_open()) return;

            cout << "Sua nova palavra: ";
            cin >> new_add;
            palavras.push_back(new_add);


            file << palavras.size() << endl;

            for (string palavra: palavras) {
                file << palavra << endl;
            }
            file.close();
        }

    }

    void welcome() {
        cout << "==================================================" << endl;
        cout << "||            BEM VINDO AO MEU MUNDO            ||" << endl;
        cout << "==================================================" << endl;
        cout << endl;
    }

    void if_champion(bool &ganhou, std::string NOME_SECRETO, map<char, bool> &chutou, int SIZE_SECRET_NAME) {

        if (  cont(NOME_SECRETO, chutou, SIZE_SECRET_NAME)) {

            cout << "=================================================" << endl;
            cout << "|| PARABÉNS!! Você desvendou a palavra secreta ||" << endl;
            cout << "=================================================" << endl;
            cout << endl;
            ganhou = true;

        }
    }

    bool verify(char chute, std::string NOME_SECRETO) {

        for (char letra: NOME_SECRETO) {

            if (chute == letra) {
                return true;
            }

        }
        return false;
    }

    void add_choice_error( int &array_c ,char chute, std::array<char, 6> &chutes_errados, std::string NOME_SECRETO ) {

        for ( char chutes_e : chutes_errados ) {
            if(chutes_e != 0) {
                array_c++;
            }
        }

        if (!verify(chute, NOME_SECRETO)) {

            for (char letra: chutes_errados) {

                if (letra == chute) return;

            }
            chutes_errados[array_c] = chute;
            array_c = 0;

        }
    }

    bool verify_array( std::array<char, 6> &chutes_errados){
        int j = 0;
        for(int i = 0; i < chutes_errados.size(); i++ ){
            if(chutes_errados[i] != 0){
                j++;
            }
        }
        if(j == 0){ return true;}else{return false;}

    }

    void show_choice_error( std::array<char, 6> &chutes_errados ) {

        if (verify_array(chutes_errados)) return;

        if (chutes_errados.size() > 0) {

            cout << "Chutes Errados: ";

            for (char erros: chutes_errados) {

                cout << erros << " ";

            }
            cout << endl;
        }
    }


    void chuta( int &array_c ,std::array<char, 6> &chutes_errados, std::map<char, bool> &chutou, std::string NOME_SECRETO, int &interador ) {

        char chute;
        cout << endl;
        cin >> chute;
        Validation_information(chute, chutou, NOME_SECRETO, interador);

        cout << endl;

        add_choice_error( array_c ,chute, chutes_errados, NOME_SECRETO);

    }

    void warning() {

        cout << "--------------------------------------------------------" << endl;
        cout << "  Você terá 5 vidas. Boa sorte e que os jogos comecem!  " << endl;
        cout << "--------------------------------------------------------" << endl;

    }

    void clear(int old_number, int current_number, int QTD, int SIZE_SECRET_NAME, std::string &NOME_SECRETO,
               std::map<char, bool> &chutou, std::array<char, 6> &chutes_errados, std::vector<std::string> &palavras) {

        old_number = 0;
        current_number = 0;
        SIZE_SECRET_NAME = 0;
        NOME_SECRETO.clear();
        chutou.clear();
        palavras.clear();
        for (int i = 0; i < chutes_errados.size(); ++i) {
            chutes_errados[i] = ' ';

        }
    }

    void game_over(const std::string NOME_SECRETO) {
        cout << "A palavra secreta era: " << NOME_SECRETO << endl;
        cout << "Fim de jogo!" << endl;
    }

}
