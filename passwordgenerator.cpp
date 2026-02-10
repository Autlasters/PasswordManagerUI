/*
 * passwordgenerator.cpp
 *
 * In this .cpp file the algorithm of password generation is implemented
 *
 * Built with C++ in Qt Creator using MSVC 2022
 *
 */
#include"passwordgenerator.h"
#include<QString>
#include<vector>
#include<random>

//Method to generate the random password with 16 symbols
QString PasswordGenerator::generateRandomPassword(){
    QString m_generatedPassword;
    m_generatedPassword.clear();

    for(int i = 0; i < 16; ++i){
        std::uniform_int_distribution<int> UID(0, 3);
        int n = UID(DRE);
        switch (n) {
        case 0: {
            std::uniform_int_distribution<int> LUID(0, 9);
            m_generatedPassword.append(QChar('0' + LUID(DRE)));
            break;
        }
        case 1: {
            std::uniform_int_distribution<int> LUID(0, m_alphabet.size() - 1);
            m_generatedPassword.append(m_alphabet[LUID(DRE)]);
            break;
        }
        case 2: {
            std::uniform_int_distribution<int> LUID(0, m_alphabet.size() - 1);
            m_generatedPassword.append(QChar(toupper(m_alphabet[LUID(DRE)])));
            break;
        }
        case 3: {
            std::uniform_int_distribution<int> LUID(0, m_symbols.size() - 1);
            m_generatedPassword.append(m_symbols[LUID(DRE)]);
            break;
        }
        default:
            break;
        }
    }
    return m_generatedPassword;
}

