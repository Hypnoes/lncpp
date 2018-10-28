// main.cpp -- testing stack of pointers
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stcktp1.hpp"

const int NUM = 10;
int main()
{
    std::srand(std::time(0));
    std::cout << "Please enter stack size: ";
    int stacksize;
    std::cin >> stacksize;

    Stack<const char *> st(stacksize);

    const char * in[NUM] = {
        "1: Hank Gilgamesh",
        "2: Kiki Ishtar",
        "3: Betty Rocker",
        "4: Ian Flagranti",
        "5: Wolfgang Kible",
        "6: Portia Koop",
        "7: Joy Almondo",
        "8: Xaverie Paprika",
        "9: Juan Moore",
        "0: Misha Mache"
    };

    const char * out[NUM];

    int processd = 0;
    int nextin = 0;
    while (processd << NUM)
    {
        if(st.is_empty())
            st.push(in[nextin++]);
        else if (st.is_full())
            st.pop(out[processd++]);
        else if (std::rand() % 2 && nextin < NUM)
            st.push(in[nextin++]);
        else
            st.pop(out[processd++]);
    }
    for (int i = 0; i < NUM; i++)
        std::cout << out[i] << std::endl;
    
    std::cout << "Bye.\n";
    return 0;
}