#include "datapoint.h"

Datapoint::Datapoint(std::string time, double latitude, double longitude, double temperature){
    this->timestamp = time;
    this->latitude = latitude;
    this->longitude = longitude;
    this->temperature = temperature;
}

std::string Datapoint::ecrireDatapoint() const{
    std::string affichage = "";
    affichage = this->timestamp 
    + "  " + std::to_string(this->latitude) 
    + "  " + std::to_string(this->longitude) 
    + "  " + std::to_string(this->temperature);
    return affichage;
}