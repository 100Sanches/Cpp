#include <iostream>
#include <string.h>

using namespace std;

//função que percorre a string e analisa os caracteres.
int contaparenteses(string str) {

  //contadores de parenteses que abrem e que fecham.
  int abre = 0;
  int fecha = 0;
  
  //laço que percorre a string.
  for (int i = 0; i < str.size(); i++){

    //comperação para ver se o caracter é um parenteses que abre.
    if (str[i] == '(') {
        abre++;
    }

    //comperação para ver se o caracter é um parenteses que fecha.
    if (str[i] == ')') {
        fecha++;
    }
  }

    //comperação para ver se o numero de parenteses que abre e fecham são iguais, para retornar 1 caso sejam e 0 caso não.
    if (abre == fecha){
        return 1;
    }

    else{
        return 0;
    }
}

// Código principal que chama as funções e declara a string que vai ser analizada.
int main(){
    std::string str = "(hello_world)";
    cout << "Saida: " << contaparenteses(str);
}