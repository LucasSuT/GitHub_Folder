#include "parser.h"
#include "scanner.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char **argv) {
    string input, part, all = "";
    stringstream inputStream;
    Parser *parser;
    while (true)
    {
        while ( input == "" || input.back() != '.')
        {
            if (input == "" )
                cout << "?- ";
            else
                cout << "|  ";
            getline(cin, input);
            inputStream << input;
            while ( inputStream >> part)all += part ;
            inputStream.str("");
            inputStream.clear();
        }

        if ( all == "halt.")
            break;
        else
        {
            parser = new Parser(Scanner(all));
            try
            {
                parser->buildExpression();
                cout << parser->result() << endl;
            }
            catch( string &error)
            {
                cout << error << endl;
            }
        }
        all = "";
        input = "";
    }

}
