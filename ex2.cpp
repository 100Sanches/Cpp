#include <iostream>
#include <string.h>

using namespace std;

int countunderscores(string s) {
  int abre = 0;
  int fecha = 0;

  for (int i = 0; i < s.size(); i++){
    if (s[i] == '(') {
        abre++;
    }

    if (s[i] == ')') {
        fecha++;
    }
  }

    if (abre == fecha){
        return 1;
    }

    else{
        return 0;
    }
}

int main(){
    std::string s = "(hello_world)";
    cout << "Saida: " << countunderscores(s);
}