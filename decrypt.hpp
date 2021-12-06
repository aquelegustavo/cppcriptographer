#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int decrypt(string key)
{
    cout << "Selecione o arquivo para descriptografar:";
    string text, textpath;
    cin >> textpath;

    ifstream textfilereader(textpath);
    if (!textfilereader.is_open())
    {
        cout << "Error, arquivo não encontrado!" << endl;
        return 1;
    }

    char textch;
    stringstream textsst;
    while (textfilereader.get(textch))
    {
        textsst << textch;
    }

    text = textsst.str();

    if (text.size() % 4 != 0)
    {
        cout << "Error! Arquivo cripitografado corrompido.";
        return 1;
    }

    ofstream outfile;
    outfile.open("out_decrypt.txt");

    for (size_t i = 0; i < text.size() / 4; i++)
    {
        string code = text.substr(i * 4, 4);

        int decimalcode;
        stringstream sstream;
        sstream << hex << code;
        sstream >> decimalcode;

        int orginal = decimalcode / getKeyValue(key, i);

        outfile << (char)orginal;
    }

    textfilereader.close();
    outfile.close();

    return 0;
}