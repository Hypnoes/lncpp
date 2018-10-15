// hello.cpp -- hello world
#include <iostream>
#include <locale>

int main(int argc, char const *argv[])
{
    using namespace std;
    locale::global(locale("zh_CN.UTF8"));  // *nix style
    //locale::global(locale("zh-CN"));     // windows style
    wcout << L"Hello world.\n"
             L"雷吼啊~\n"
             L"😄" << endl;
    return 0;
}
