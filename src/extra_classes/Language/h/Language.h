#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <vector>
#include <string>
#include <QString>

class Languages
{
    static int chosenLanguage;
    static std::vector<std::vector<std::vector<std::pair<QString, QString>>>> Languages_vector;
    static std::vector<std::pair<QString, QString>> createPairVector(const std::initializer_list<std::pair<QString, QString>>& pairs);
public:
    enum languages {
       ENGLISH,
       GERMAN,
       SPANISH,
       POLISH 
    };
    static void setLanguage(int);
    static int getLanguage();
    static std::vector<std::vector<std::pair<QString, QString>>> getOneLanguage(int);
    
};

#endif // LANGUAGE_H