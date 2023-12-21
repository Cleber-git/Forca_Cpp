#include "lib.hpp"






using namespace std;



bool equal_number(int old_number, int current_number){
    return old_number == current_number; 
}

int random_choice(int QTD){

    srand(time(NULL));
    int secret_number = rand() % QTD;

    
    return secret_number;
}

bool cont(std::string NOME_SECRETO, std::map<char, bool> chutou, int SIZE_SECRET_NAME){
    
    int i = 0;
    for(char letra : NOME_SECRETO ){

        if (chutou[letra])
        {
            i++;
        }
    }
    if (i == SIZE_SECRET_NAME)
    {

        return true;

    }
    
    return false;

}



void Is_valid(std::string NOME_SECRETO, std::map<char, bool> chutou){

    for (char letra: NOME_SECRETO)
        {
            if (chutou[letra])
            {
                cout << letra << " ";
            }else{
                cout << "_ ";
            }
            
        }
      
    
}




void Validation_information(char chute, map<char, bool> *chutou, std::string NOME_SECRETO, int *interador){

    


    for ( char letra : NOME_SECRETO )
    {
        if(chute == letra){
            (*chutou)[letra] = true;
            (*interador)++;
            break;
        }
    }
    

}

void menu(){

    cout << endl;
    cout << endl;
    cout << "   //////////////////////////////////////"<<endl;
    cout << "   //////////////// MENU ////////////////"<<endl;
    cout << "   //////////////////////////////////////"<<endl;
    cout << endl;
    cout << endl;

    cout << "COMANDOS ESPECIAIS:"<<endl;
    cout << " + : Adicionar mais uma fruta ao banco de dados."<< endl;
    cout << " q : Sair do jogo."<< endl;

    cout << endl;
    cout << endl;

}


bool get_number_choices(std::vector<char> chutes_errados){
    return chutes_errados.size() < 5;
}



void verify_add(std::vector<std::string>*palavras, bool *ADD,  char ADICIONAR ,  char SAIR) {

    menu();

    char chute;
    cout << "Escolha o que quer fazer agora: ";
    cin >> chute;

 //   switch(chute){
//        case ADICIONAR:
 //           (*ADD) = true;
 //           break;
 //       case SAIR:
            
 //       default:
//            break;
    //}
    string new_add;

    if(ADD){
        ofstream file;
        file.open("palavas.txt");
        if(!file.is_open()) return;

        cout << "Sua nova palavra: ";
        cin >> new_add;
        palavras->push_back(new_add);


        file << palavras->size()<< endl;

        for (string palavra : (*palavras)) {
            file << palavra << endl;
        }
        file.close();
    }

}

void welcome(){
    cout <<"=================================================="<< endl; 
    cout <<"||            BEM VINDO AO MEU MUNDO            ||"<< endl;
    cout <<"=================================================="<< endl;
    cout << endl;
}

void if_champion( bool *ganhou, std::string NOME_SECRETO, map<char, bool> chutou, int SIZE_SECRET_NAME){

    if(cont(NOME_SECRETO, chutou, SIZE_SECRET_NAME)){
    
    cout <<"================================================="<< endl; 
    cout <<"|| PARABÉNS!! Você desvendou a palavra secreta ||"<< endl;
    cout <<"================================================="<< endl;
    cout << endl;
    (*ganhou) = true;

    }
}

bool verify(char chute, std::string NOME_SECRETO){

    for ( char letra : NOME_SECRETO )
    {
        
        if ( chute == letra )
        {
            return true;
        }
        
    }
    return false;
} 

void add_choice_error(char chute, std::vector<char>*chutes_errados, std::string NOME_SECRETO ) {
    if (!verify(chute, NOME_SECRETO))
    {
        for (char letra : (*chutes_errados)) {
            if(letra == chute) return;
        }
        chutes_errados->push_back(chute);
    }
}

void show_choice_error(std::vector<char> chutes_errados){
    if (chutes_errados.size() > 0)
        {
            cout << "Chutes Errados: ";
            for(char erros: chutes_errados){
                cout << erros;
            }
            cout << endl;
        }
}

std::string read_string(int QTD, int old_number, int current_number, std::vector<std::string>palavras, int *SIZE_SECRET_NAME, std::string *NOME_SECRETO){
    
    std::ifstream arquivo;
    arquivo.open("palavas.txt");

    if(!arquivo.is_open()) {std::cout << "Seu arquivo não pôde ser aberto. Tente novamente!" << std::endl; exit(1);}

    arquivo >> QTD;
    std::string palavra_lida;

    for (int i = 0; i < QTD; i++)
    {
        arquivo >> palavra_lida;
        palavras.push_back(palavra_lida);
    }
    arquivo.close();


    old_number = current_number;
    
    int index = random_choice(QTD);
    if (old_number == index)
    {   
        std::cout << "Indice se repetiu e está passando pelo tratamento"<< std::endl;
        index = random_choice(QTD);
        current_number = index;
        
    }else{current_number = index;}
    // cout << current_number << endl;
    // current_number = index;
    if (current_number == 0) {std::cout << current_number << std::endl;}
    // cout << qtd << endl;



    

    
    

    (*NOME_SECRETO) = palavras[current_number];
    (*SIZE_SECRET_NAME) = NOME_SECRETO->size();
   


    // for ( string fruta : palavras)
    // {
    //     cout << fruta << endl;
    // }

    return (*NOME_SECRETO);
}

void chuta(std::vector<char> *chutes_errados,std::map<char,bool>* chutou, std::string NOME_SECRETO, int* interador){
    char chute;
    cout << endl;
    cin >> chute;
    Validation_information(chute, chutou, NOME_SECRETO, interador);



    cout << endl;
    
    
    add_choice_error(chute, chutes_errados, NOME_SECRETO);
}









void warning(){

    cout << "--------------------------------------------------------" << endl;
    cout << "  Você terá 5 vidas. Boa sorte e que os jogos comecem!  " << endl;
    cout << "--------------------------------------------------------" << endl;

}

void clear(){

//    old_number = 0;
 //   current_number = 0;
 //   QTD = 0;
 //   SIZE_SECRET_NAME = 0;
 //   NOME_SECRETO.clear();
  //  chutou.clear();
 //   chutes_errados.clear();
  //  palavras.clear();
    
}

void game_over(std::string NOME_SECRETO){
    cout << "A palavra secreta era: " << NOME_SECRETO << endl;
    cout << "Fim de jogo!" << endl;
}
