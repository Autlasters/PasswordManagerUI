#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H
#include<QString>
#include<vector>
#include<random>

class PasswordGenerator {
private:
    static inline std::vector<char> m_alphabet = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h','i', 'j', 'k', 'l', 'm',
                                                    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    static inline std::vector<char> m_symbols = { '!', '@', '#', '$', '%', '^', '&', '*', '-', '_', '+', '=',
                                                    '/', '\\', ',', '.', '?', '<', '>', ':', ';', '\'', '"', '|'};
    static inline std::random_device RD;
    static inline std::default_random_engine DRE{RD()};
public:
    static QString generateRandomPassword();
};

#endif // PASSWORDGENERATOR_H
