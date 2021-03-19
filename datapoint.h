#ifndef __DATAPOINT_H__
#define __DATAPOINT_H__

#include <iostream>
#include <string>

class Datapoint {
    private:
        std::string date_releve;
        std::string latitude;
        std::string longitude;
        double temperature;
    public:
        Datapoint(std::string date_releve, std::string latitude, std::string longitude, double temperature);
        //  Méthode d’affichage des informations de Datapoint dans le bon format
        std::string ecrireDatapoint() const;
        //  Redéfinition de l’opérateur inferieur, pour répondre au besoins de notre logiciel
        bool operator<(const Datapoint& datapoint_suivant) const ;
};

#endif // __DATAPOINT_H__