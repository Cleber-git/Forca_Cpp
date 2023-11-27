				******************************************
				*** Funções que eu não conhecia em C++ ***
				******************************************

- Cout.Posicion(parameter):

* Define a precisão de quantas casas decimais o número desejado vai ter.
_______________________________________________________________________

- Cout << fixed;

* Seta a virgula fixada no mesmo ponto, fazendo com que ela não percorra o número.
_______________________________________________________________________

- cin << nome_da_variavel;

* Função para receber a entrada do usuário;
_______________________________________________________________________


				******************************************
				*** DOCUMENTAÇÃO DE PROJETO EM C++ .MD ***
				******************************************



Este código é um jogo de adivinhação de palavras em C++, onde o jogador tem que adivinhar uma palavra secreta.

    Bibliotecas e Variáveis Globais:

        ### Bibliotecas: ###
		1- <iostream>;
		2-  <string>;
		3-  <map>;
		4- <vector>;
		5- <fstream>;
		6- <ctime>;
		7- <cstdlib>
		* Para manipulação de strings, vetores, arquivos, entre outros.*
        Há variáveis globais como old_number, NOME_SECRETO, SIZE_SECRET_NAME, chutou, chutes_errados, palavras, QTD.

    ###Funções:###

        1- equal_number: Verifica se dois números são iguais.
        2- cont: Verifica se todas as letras da palavra secreta foram adivinhadas.
        3- verify: Verifica se uma letra é parte da palavra secreta.
        4- Is_valid: Mostra as letras adivinhadas e espaços para as não adivinhadas.
        5- Validation_of_information: Marca a letra adivinhada.
        6- get_number_choices: Retorna se ainda há chances para errar.
        7- welcome: Mensagem de boas-vindas.
        8- if_champion: Verifica se o jogador ganhou.
        9- add_choice_error: Adiciona um chute errado.
        10- show_choice_error: Mostra os chutes errados.
        11- chuta: Solicita um chute do jogador.
        12- random_choice: Gera um número aleatório para selecionar a palavra secreta.
        13- read_string: Lê palavras de um arquivo.
        14- warning: Exibe uma mensagem de aviso.

    ###Main:###
        
		O programa começa com uma saudação e depois lê as palavras de um arquivo de texto.
        Há um loop onde o jogador tenta adivinhar a palavra secreta, com limitação de 5 tentativas.
        O jogador é convidado a chutar uma letra, e o jogo verifica se foi acertado ou não. O loop continua até que o jogador acerte ou esgote as tentativas.

    #Fim do Jogo:#
        Quando o jogo termina, uma mensagem é exibida indicando se o jogador ganhou ou perdeu, junto com a palavra secreta.
