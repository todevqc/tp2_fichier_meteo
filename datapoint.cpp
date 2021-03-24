#include "datapoint.h"

//  Constructeur Datapoint
Datapoint::Datapoint(std::string timestamp, double latitude, double longitude, double temperature){
    this->timestamp = timestamp;
    this->latitude = latitude;
    this->longitude = longitude;
    this->temperature = temperature;
}

//  Méthode d’affichage des informations de Datapoint dans le bon format
std::string Datapoint::ecrireDatapoint() const{
    // créer un flux de sortie
    std::ostringstream oss;
    // écrire dans le flux pour garder le bon format des Double
    oss << this->timestamp << "  " << this->latitude << "  " << this->longitude << "  " << this->temperature;
    // récupérer une chaîne de caractères
    std::string affichage = oss.str();
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