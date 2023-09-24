#include "Language/h/Language.h"


int Languages::chosenLanguage = 3;
std::vector<std::vector<std::vector<std::string>>> Languages::Languages_vector
{
    
};


void Languages::setLanguage(int lang)
{
    chosenLanguage = lang;
}
int Languages::getLanguage()
{
    return chosenLanguage;
}
std::vector<std::vector<std::string>> Languages::getAll(int lang)
{
    return Languages_vector[lang];
}

