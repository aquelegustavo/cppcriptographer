#include <iostream>

using namespace std;

int getKeyValue(string key, int i)
{
    return int(key[i % key.size()]);
}

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

int changePassword()
{

    cout << "Informe a nova senha: " << endl;

    string password;
    cin >> password;

    ofstream keyfile;
    keyfile.open("./secrets/key.txt");

    keyfile << password;
}
