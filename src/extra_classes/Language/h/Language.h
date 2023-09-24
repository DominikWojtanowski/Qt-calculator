#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <vector>
#include <string>

class Languages
{
    static enum languages {
       ENGLISH,
       GERMAN,
       SPANISH,
       POLISH 
    };
    static int chosenLanguage;
    static std::vector<std::vector<std::vector<std::string>>>Languages_vector;
public:
    static void setLanguage(int);
    static int getLanguage();
    static std::vector<std::vector<std::string>>getAll(int);
    
};

#endif // LANGUAGE_H