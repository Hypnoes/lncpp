SET PATH=%PATH%;%1
g++ -g %2 -lpthread --std=c++11 -fdiagnostics-color=always -o %3