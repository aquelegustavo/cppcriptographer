#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int encrypt(string key)
{
    cout << "Selecione o arquivo para criptografar:";
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

    ofstream outfile;
    outfile.open("out_encrypt.txt");

    for (size_t i = 0; i < text.size(); i++)
    {
        int value = int(text[i]) * getKeyValue(key, i);

        outfile << getHex(value);
    }

    textfilereader.close();
    outfile.close();

    return 0;
}