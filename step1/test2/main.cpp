#include <stdio.h>
#include <iostream>

extern int yylex(void);
extern FILE*   yyin;

int main()
{
    yyin    = fopen("testFiles/fibonacci.micro", "r");
    std::cout << yylex() << "\n";
}
