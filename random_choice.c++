#include <ctime>
#include <cstdlib>
#include "forca.hpp"
#include "random_choice.hpp"


int random_choice(){

    srand(time(NULL));
    int secret_number = rand() % QTD;

    
    return secret_number;
}
