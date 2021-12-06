/**
 * @file encrypt.hpp
 * @author Gustavo Simões e Izabelle Custodia Teixeira Sebastião
 * @brief 
 * @version 1.0
 * @date 2021-12-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int encrypt(string key)
{
    // Seleção do arquivo para ser criptografado
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

    // Criação do arquivo com o texto criptografado
    ofstream outfile;
    outfile.open("out_encrypt.txt");

    for (size_t i = 0; i < text.size(); i++)
    {
        int value = int(text[i]) * getKeyValue(key, i);

        outfile << getHex(value);
    }

    // Fechamento dos arquivos utilizados pelo programa
    textfilereader.close();
    outfile.close();

    return 0;
}