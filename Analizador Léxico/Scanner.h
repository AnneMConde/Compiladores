#include <fstream>
#include <vector>
#include "Token.h"

enum class ScannLex{
    STRINGP,
    SIMBOLO,
    COMENTARIOP,
    COMENTARIOH,
    DEFAULT
};


class AnLexico{
public:
    ScannLex estado;
    string archivo;
    string c;
    vector<token> tokens;
    size_t token_actual;

public:
    explicit AnLexico(const string& archivo){
        this->archivo = archivo;
        this->token_actual = 0;
        this->estado = ScannLex::DEFAULT;
    }


    token token_siguiente (){
        if (token_actual < tokens.size() - 2)
        {
            ++token_actual;
        }
    }

    token token_actual(){
        return tokens[token_actual];
    }

    TipoToken tipo_actual(){
        return token_actual().type;
    }

    void tokendiv(){
        token_actual = -1;

        size_t linea_actual = 1;
        size_t posision_actual = 0;

        string lexema_actual;

        for (auto& signo : c){
            if (signo == '\n'){
                ++linea_actual;
                posision_actual = 0;
            }
            ++posision_actual;

            if (estado == ScannLex::DEFAULT || estado == ScannLex::COMENTARIOP){
                if (signo == '/')
                {
                    if (estado == ScannLex::COMENTARIOP){
                        estado = ScannLex::COMENTARIOH;
                    }
                    else{
                        estado = ScannLex::COMENTARIOP;
                        lexema_actual += signo;
                        continue;
                    }
                }
                else{
                    estado = ScannLex::DEFAULT;
                }
            }

            if (estado == ScannLex::COMENTARIOH){
                if (signo == '\n'){
                    lexema_actual.clear();
                    estado = ScannLex::DEFAULT;
                }
                continue;
            }

            if (signo == '"'){
                if (estado == ScannLex::DEFAULT){
                    estado = ScannLex::STRINGP;
                    lexema_actual += signo;

                    continue;
                }
                else if (estado == ScannLex::STRINGP){
                    estado = ScannLex::DEFAULT;
                    lexema_actual += signo;

                    token token_nuevo(lexema_actual, linea_actual, posision_actual);
                    tokens.push_back(token_nuevo);
                    lexema_actual.clear();

                    ++token_actual;

                    continue;
                }
            }

            if (estado == ScannLex::STRINGP){
                lexema_actual += signo;
                continue;
            }

            if (signo == '\''){
                if (estado == ScannLex::DEFAULT){
                    estado = ScannLex::SIMBOLO;
                    lexema_actual += signo;

                    continue;
                }
                else if (estado == ScannLex::SIMBOLO){
                    estado = ScannLex::DEFAULT;
                    lexema_actual += signo;

                    token token_nuevo(lexema_actual, linea_actual, posision_actual);
                    tokens.push_back(token_nuevo);
                    lexema_actual.clear();

                    ++token_actual;

                    continue;
                }
            }

            if (estado == ScannLex::SIMBOLO){
                lexema_actual += signo;
                continue;
            }

            else{
                lexema_actual += signo;
            }
        }

        if (!lexema_actual.empty()){
            token token_nuevo(lexema_actual, linea_actual, posision_actual);
            tokens.push_back(token_nuevo);
            lexema_actual.clear();

            ++token_actual;
        }
    }

    void tokenunir(){

        vector<token> token_temporal;
        size_t linea_actual = 1;
        size_t posision_actual = 0;
        bool stringp = false;

        for (int i = 0; i < tokens.size() - 1; ++i){
            if (tokens[i].lexema == "#"){
                string lexema_nuevo = tokens[i].lexema + tokens[i + 1].lexema;
                linea_actual = tokens[i].linea;
                posision_actual = tokens[i].posision;
                token token_nuevo(lexema_nuevo, linea_actual, posision_actual);
                token_temporal.push_back(token_nuevo);
                i += 2;
            }

            token_temporal.push_back(tokens[i]);
        }
        tokens = token_temporal;
        token_temporal.clear();

        for (int i = 0; i < tokens.size() - 1; ++i)
        {
            if (tokens[i].lexema == "#")
            {
                string lexema_nuevo = tokens[i].lexema + tokens[i + 1].lexema;
                linea_actual = tokens[i].linea;
                posision_actual = tokens[i].posision;

                token token_nuevo(lexema_nuevo, linea_actual, posision_actual);

                token_temporal.push_back(token_nuevo);

                i += 2;
            }

            token_nuevo.push_back(tokens[i]);
        }
        tokens = token_nuevo;
        token_nuevo.clear();

        token_actual = 0;
    }

    void print()
    {
        for (auto& token : tokens)
        {
            token.print();
        }
    }


    /*static bool identificador(const string& token)
    {
        if (!token_a(token[0]) && token[0] != '_')
            return false;

        for (const auto& signo : token)
            if (!token_a(signo) && !digito(signo) && signo != '_')
                return false;

        return true;
    }*/ 


    void print_token()
    {
        int i = token_actual;
        int j = token_actual;
        auto linea_actual = token_actual().linea;

        while (i > 0 && tokens[i].linea == linea_actual)
        {
            --i;
        }
        ++i;

        int simbolo_anterior = token_actual - i;

        while (j < tokens.size() && tokens[j].line == linea_actual)
        {
            ++j;
        }


        cout << "linea " << linea_actual << ": ";


        size_t simbolo_anteriorA = 0;
        string b;
        size_t size_token_actual = 0;
        for (int k = i; k < j; ++k)
        {
            if (k - i == simbolo_anterior)
            {
                cout << "" << tokens[k].lexeme << "" << " ";
                size_token_actual = tokens[k].lexeme.size();
                continue;
            }

            cout << tokens[k].lexeme << " ";

            if (k - i <= simbolo_anterior)
            {
                simbolo_anteriorA += tokens[k].lexeme.size() + 1;
            }
        }

        simbolo_anteriorA += 7 + to_string(linea_actual).size();

        for (int l = 0; l < simbolo_anteriorA; ++l)
        {
            b += ' ';
        }

        for (int l = 0; l < size_token_actual; ++l)
        {
            b += '~';
        }

        cout << endl;
        cout << b;
        cout << endl;
    }

};