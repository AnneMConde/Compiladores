#include "Scanner.h"

int main()
{
    AnLexico lex("Ejemplo.cpp");
    lex.tokendiv();
    lex.tokenunir();
    lex.print();

}