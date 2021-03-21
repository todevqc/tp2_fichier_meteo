#include <iostream>
#include <string>
#include <fstream>
#include <set>

#include "datapoint.h"

int main() {
  //  declaration d'un conteneur de type Arbre
  //  il est aussi possible d'utiliser un conteneur de type priority_queue
  std::set<Datapoint> dataCanada;

  //  Lecture et récupération des données du fichier rawdata.txt
  std::ifstream fichierUS("rawdata.txt");
  if (!fichierUS.is_open()){
    std::cout << "Impossible d'ouvrir le fichier !" << std::endl;
  }else{  
    double latitude;
    double longitude;
    double temperature;
    std::string date_releve;  
    //  Récupère l’information de la station, mais n’est pas ajouté a mon objet Datapoint
    std::string stationInutile;
    while(!fichierUS.eof()){
      fichierUS >> latitude >> longitude >> stationInutile >> temperature >> date_releve;
      //  T°C = (T°F − 32) × 5 ÷ 9.
      //  Création d’objet Datapoint, à partir des données de la lecture
      Datapoint dataStation(date_releve, latitude, longitude, (temperature-32)*5/9.0);
      //  Ajout de l’objet Datapoint dans le conteneur
      dataCanada.insert(dataStation);
    }  
    fichierUS.close();
  }

  //  Écriture des informations sur le nouveaux fichier candata.txt dans le bon ordre
  std::ofstream mateoCanada("candata.txt");
  
  if (!mateoCanada.is_open()){
    std::cout << "Impossible d'ouvrir le fichier !" << std::endl;
  }else{
    for (std::set<Datapoint>::iterator it = dataCanada.begin(); it != dataCanada.end(); ++it) {
      mateoCanada << it->ecrireDatapoint() << std::endl;
    }
    mateoCanada.close();
  }
}