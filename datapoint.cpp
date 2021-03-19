#include "datapoint.h"

//  Constructeur Datapoint
Datapoint::Datapoint(std::string date_releve, std::string latitude, std::string longitude, double temperature){
    this->date_releve = date_releve;
    this->latitude = latitude;
    this->longitude = longitude;
    this->temperature = temperature;
}

//  Méthode d’affichage des informations de Datapoint dans le bon format
std::string Datapoint::ecrireDatapoint() const{
    std::string affichage = "";
    affichage = this->date_releve 
    + "  " + this->latitude 
    + "  " + this->longitude
    + "  " + std::to_string(this->temperature);
    return affichage;
}

//  Redéfinition de l’opérateur inferieur, pour répondre au besoins de notre logiciel
bool Datapoint::operator<(const Datapoint& datapoint_suivant) const {
    if (this->latitude > datapoint_suivant.latitude) return true;
    else if ((this->latitude == datapoint_suivant.latitude) && (this->longitude < datapoint_suivant.longitude)){
        return true;
    }
    return false;
}