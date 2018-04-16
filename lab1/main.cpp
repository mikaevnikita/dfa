#include <iostream>
#include <functional>
using namespace std;

/*
ДКА для чисел кратных 4
*/

enum multiply_four_states {REST_0, REST_1, REST_2, REST_3, UNKNOWN};

void dfa_multiply_four(string s, function<void(multiply_four_states)> f){
    multiply_four_states state = UNKNOWN;
    char curr_char;
    multiply_four_states arr[4][2];
    arr[0][0] = REST_0;
    arr[0][1] = REST_1;
    arr[1][0] = REST_2;
    arr[1][1] = REST_3;
    arr[2][0] = REST_0;
    arr[2][1] = REST_1;
    arr[3][0] = REST_2;
    arr[3][1] = REST_3;
    int four_index;
    for(auto it = s.begin(); it!=s.end(); it++){
        curr_char = *it;
        if(curr_char == '0')
            four_index = 0;
        else if(curr_char == '1')
            four_index = 1;
        else
            return;

        if(state == UNKNOWN){
            if(curr_char == '0')
                state = REST_0;
            else if(curr_char == '1')
                state = REST_1;
        }
        else
            state = arr[(int)state][four_index];
        f(state);
    }
}

int main()
{
    string num = "1000";//Число в двоичной системе счисления
    dfa_multiply_four(num, [](multiply_four_states curr_state)->void{
        cout << "Current state: " << curr_state << endl;
    });
    return 0;
}
