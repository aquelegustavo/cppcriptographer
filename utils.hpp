/**
 * @file utils.hpp
 * @author Gustavo Simões e Izabelle Custodia Teixeira Sebastião
 * @brief 
 * @version 1.0
 * @date 2021-12-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>

using namespace std;

// Obteção do número inteiro ASCII correspondente a
// um caracter de posição i da chave de criptografia.
int getKeyValue(string key, int i)
{
    return int(key[i % key.size()]);
}

// Obtenção de número na base hexadecimal por meio
// de um número decimal.
// Formato de saída: 4 bits
string getHex(int number)
{

    stringstream sstream;
    sstream << hex << number;
    string result = sstream.str();

    switch (result.size())
    {
    case 1:

        return result.insert(0, 3, '0');
        break;
    case 2:

        return result.insert(0, 2, '0');
        break;
    case 3:

        return result.insert(0, 1, '0');
        break;
    case 4:

        return result;
        break;

    default:
        cout << "Error! Hex maior do que deveria!";
        break;
    }
}

// Alteração da chave de criptografia
int changePassword()
{

    cout << "Informe a nova senha: " << endl;

    string password;
    cin >> password;

    ofstream keyfile;
    keyfile.open("./secrets/key.txt");

    keyfile << password;
}
