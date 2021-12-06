/**
 * @file main.cpp
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

#include "utils.hpp"
#include "encrypt.hpp"
#include "decrypt.hpp"

using namespace std;

int main()
{
    // Carregamento da chave de criptografia ("senha"/"password")
    string key;

    ifstream keyfilereader("./secrets/key.txt");

    // Verificando se a chave de criptografia existe
    if (!keyfilereader.is_open())
    {
        cout << "Error, chave de criptografia não encontrada !" << endl;
        return 1;
    }

    char keych;
    stringstream keysst;
    while (keyfilereader.get(keych))
    {
        keysst << keych;
    }

    key = keysst.str();
    keyfilereader.close();

    // Inciando menu de opções
    int option;
    while (1)
    {
        cout << "\n*******************************\n"
             << "Escolha uma das opções abaixo: \n"
             << "*******************************\n\n";

        cout << " 1 - Criptografar arquivo." << endl;
        cout << " 2 - Descriptografar arquivo." << endl;
        cout << " 3 - Alterar a senha do programa." << endl;
        cout << " 4 - Sair." << endl;

        cin >> option;
        switch (option)
        {
        case 1:
            // Criptografar arquivo.
            // encrypt.hpp
            encrypt(key);
            break;
        case 2:
            // Descriptografar arquivo.
            // decrypt.hpp
            decrypt(key);
            break;
        case 3:
            // Alterar a senha do programa.
            // utils.hpp
            changePassword();
        case 4:
            return 0;

        default:
            cout << "Escolha uma opção entre 1, 2 e 3.";
            break;
        }
    }

    return 0;
}