/**
 * @file decrypt.hpp
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

int decrypt(string key)
{
    // Abertura do arquivo a ser descriptografado
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

    // Caso o número de caracteres do arquivo a  ser descriptografado
    // não seja múltiplo de 4, o arquivo é considerado corrompido.
    // Isso acontece porque o texto criptografado é mandido
    // criptografado em base hexadecimal 4 bits.
    if (text.size() % 4 != 0)
    {
        cout << "Error! Arquivo cripitografado corrompido.";
        return 1;
    }

    // Criação do arquivo com o texto descriptografado
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

    // Fechamento dos arquivos utilizados pelo programa
    textfilereader.close();
    outfile.close();

    return 0;
}