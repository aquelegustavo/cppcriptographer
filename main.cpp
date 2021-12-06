#include <iostream>
#include <sstream>
#include <fstream>

#include "utils.hpp"
#include "encrypt.hpp"
#include "decrypt.hpp"

using namespace std;

int main()
{
    string key;

    ifstream keyfilereader("./secrets/key.txt");

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
            encrypt(key);
            break;
        case 2:
            decrypt(key);
            break;
        case 3:
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