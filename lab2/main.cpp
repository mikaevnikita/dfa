#include <iostream>
#include <regex>
using namespace std;

/*
ДКА для чисел кратных 4 переведенный в  регулярное выражение
Если число кратно 4, все вхождения 1 заменяются на мою фамилию.
Так же в коментарии приведен тест для
обычной версии программы проверки для чисел кратных 4 всех чисел до 1000
*/

string dfa_multiply_four(string s){
    regex re("^0|[01]*00$");
    if(regex_match(s, re)){
        regex re2("1");
        string result = regex_replace(s, re2, "MIKAEV");
        return result;
    }
    return "";
}

int main()
{
    /*for(int i=0;i<1000;i++){
        string num = bitset<64>(i).to_string();
        cout << i << " " << dfa_multiply_four(num) << endl;
    }*/
    string num = "10100";
    cout << dfa_multiply_four(num) << endl;
    return 0;
}
