#include "Language/h/Language.h"


int Languages::chosenLanguage = 3;

std::vector<std::pair<QString, QString>> Languages::createPairVector(const std::initializer_list<std::pair<QString, QString>>& pairs)
{
    return std::vector<std::pair<QString, QString>>(pairs);
};

std::vector<std::shared_ptr<std::vector<std::vector<std::pair<QString, QString>>>>> Languages::Languages_vector
{
    // ENGLISH
    std::make_shared<std::vector<std::vector<std::pair<QString, QString>>>>(std::vector<std::vector<std::pair<QString, QString>>>{
        createPairVector({
            {"Standard", "   Settings"}}),

        createPairVector({
            {"src/ikony/pop_up_menu/calculator.png", "   Standard"},
            {"src/ikony/pop_up_menu/scientific.png", "   Scientific"},
            {"src/ikony/pop_up_menu/graph.png", "   Charting"},
            {"src/ikony/pop_up_menu/programming.png", "   Programmer"},
            {"src/ikony/pop_up_menu/calendar.png", "   Date calculation"}
        }),

        createPairVector({
            {"src/ikony/pop_up_menu/value.png", "   Currency"},
            {"src/ikony/pop_up_menu/density.png", "   Density"},
            {"src/ikony/pop_up_menu/length.png", "   Length"},
            {"src/ikony/pop_up_menu/weight.png", "   Weight and mass"},
            {"src/ikony/pop_up_menu/temperature.png", "   Temperature"},
            {"src/ikony/pop_up_menu/energy.png", "   Energy"},
            {"src/ikony/pop_up_menu/area.png", "   Area"},
            {"src/ikony/pop_up_menu/speed.png", "   Speed"},
            {"src/ikony/pop_up_menu/time.png", "   Time"},
            {"src/ikony/pop_up_menu/data.png", "   Data"},
            {"src/ikony/pop_up_menu/cisnienie.png", "   Pressure"},
            {"src/ikony/pop_up_menu/angle.png", "   Angle"}
        }),

        createPairVector({
            {"Calculator",""},
            {"Converter",""}
        })
    }),

    // SPANISH
    std::make_shared<std::vector<std::vector<std::pair<QString, QString>>>>(std::vector<std::vector<std::pair<QString, QString>>>{
        createPairVector({
            {"Estándar", "   Ajustes"}}),

        createPairVector({
            {"src/ikony/pop_up_menu/calculator.png","   Estándar"},
            {"src/ikony/pop_up_menu/scientific.png","   Científico"},
            {"src/ikony/pop_up_menu/graph.png","   Gráficos"},
            {"src/ikony/pop_up_menu/programming.png","   Programador"},
            {"src/ikony/pop_up_menu/calendar.png","   Cálculo de la fecha"}
        }),

        createPairVector({
            {"src/ikony/pop_up_menu/value.png","   Moneda"},
            {"src/ikony/pop_up_menu/density.png","   Densidad"},
            {"src/ikony/pop_up_menu/length.png","   Longitud"},
            {"src/ikony/pop_up_menu/weight.png","   Peso y masa"},
            {"src/ikony/pop_up_menu/temperature.png","   Temperatura"},
            {"src/ikony/pop_up_menu/energy.png","   Energía"},
            {"src/ikony/pop_up_menu/area.png","   Zona"},
            {"src/ikony/pop_up_menu/speed.png","   Velocidad"},
            {"src/ikony/pop_up_menu/time.png","   Tiempo"},
            {"src/ikony/pop_up_menu/data.png","   Datos"},
            {"src/ikony/pop_up_menu/cisnienie.png","   Presión"},
            {"src/ikony/pop_up_menu/angle.png","   Ángulo"}
        }),

        createPairVector({
            {"Calculadora",""},
            {"Convertidor",""}
        })
    }),

    // GERMAN
    std::make_shared<std::vector<std::vector<std::pair<QString, QString>>>>(std::vector<std::vector<std::pair<QString, QString>>>{
        createPairVector({
            {"Standard", "   Einstellungen"}}),

        createPairVector({
            {"src/ikony/pop_up_menu/calculator.png","   Standard"},
            {"src/ikony/pop_up_menu/scientific.png","   Wissenschaftlerin"},
            {"src/ikony/pop_up_menu/graph.png","   Grafiken"},
            {"src/ikony/pop_up_menu/programming.png","   Programmierer"},
            {"src/ikony/pop_up_menu/calendar.png","   Berechnung des Datums"}
        }),

        createPairVector({
            {"src/ikony/pop_up_menu/value.png","   Währung"},
            {"src/ikony/pop_up_menu/density.png","   Dichte"},
            {"src/ikony/pop_up_menu/length.png","   Länge"},
            {"src/ikony/pop_up_menu/weight.png","   Gewicht und Masse"},
            {"src/ikony/pop_up_menu/temperature.png","   Temperatur"},
            {"src/ikony/pop_up_menu/energy.png","   Energie"},
            {"src/ikony/pop_up_menu/area.png","   Zone"},
            {"src/ikony/pop_up_menu/speed.png","   Geschwindigkeit"},
            {"src/ikony/pop_up_menu/time.png","   Wetter"},
            {"src/ikony/pop_up_menu/data.png","   Daten"},
            {"src/ikony/pop_up_menu/cisnienie.png","   Druck"},
            {"src/ikony/pop_up_menu/angle.png","   Winkel"}
        }),

        createPairVector({
            {"Taschenrechner",""},
            {"Konverter",""}
        })
    }),

    // POLISH
    std::make_shared<std::vector<std::vector<std::pair<QString, QString>>>>(std::vector<std::vector<std::pair<QString, QString>>>{
        createPairVector({
            {"Standardowy", "   Ustawienia"}}),

        createPairVector({
            {"src/ikony/pop_up_menu/calculator.png","   Standardowy"},
            {"src/ikony/pop_up_menu/scientific.png","   Naukowy"},
            {"src/ikony/pop_up_menu/graph.png","   Tworzenie wykresow"},
            {"src/ikony/pop_up_menu/programming.png","   Programisty"},
            {"src/ikony/pop_up_menu/calendar.png","   Obliczanie daty"}
        }),

        createPairVector({
            {"src/ikony/pop_up_menu/value.png","   Waluta"},
            {"src/ikony/pop_up_menu/density.png","   Objętość"},
            {"src/ikony/pop_up_menu/length.png","   Długość"},
            {"src/ikony/pop_up_menu/weight.png","   Ciężar i masa"},
            {"src/ikony/pop_up_menu/temperature.png","   Temperatura"},
            {"src/ikony/pop_up_menu/energy.png","   Energia"},
            {"src/ikony/pop_up_menu/area.png","   Powierzchnia"},
            {"src/ikony/pop_up_menu/speed.png","   Prędkość"},
            {"src/ikony/pop_up_menu/time.png","   Czas"},
            {"src/ikony/pop_up_menu/energy.png","   Zasilanie"},
            {"src/ikony/pop_up_menu/data.png","   Dane"},
            {"src/ikony/pop_up_menu/cisnienie.png","   Ciśnienie"},
            {"src/ikony/pop_up_menu/angle.png","   Kąt"}
        }),

        createPairVector({
            {"Kalkulator",""},
            {"Konwerter",""}
        })
    }),
};


void Languages::setLanguage(int lang)
{
    chosenLanguage = lang;
}
int Languages::getLanguage()
{
    return chosenLanguage;
}
std::shared_ptr<std::vector<std::vector<std::pair<QString, QString>>>> Languages::getOneLanguage(int lang)
{
    return Languages_vector[lang]; 
}

