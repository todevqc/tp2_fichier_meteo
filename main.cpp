#include <iostream>
#include <string>
#include <fstream>
#include <set>

#include "datapoint.h"

int main() {
  //  declaration d'un conteneur de type set (Arbre binaire de recherche)
  //  vu qu'il est demandé de les garder en ordre dans le conteneur
  //  sinon il aurais étais aussi possible d'utiliser un conteneur de type priority_queue
  std::set<Datapoint> dataCanada;

  //  Lecture et récupération des données du fichier rawdata.txt
  std::ifstream fichierUS("rawdata.txt");
  if (!fichierUS.is_open()){
    std::cout << "Impossible d'ouvrir le fichier !" << std::endl;
  }else{  
    double latitude;
    double longitude;
    double temperature;
    std::string timestamp;  
    //  Récupère l’information de la station, mais n’est pas ajouté a mon objet Datapoint
    std::string stationInutile;
    while(!fichierUS.eof()){
      fichierUS >> latitude >> longitude >> stationInutile >> temperature >> timestamp;
      //  T°C = (T°F − 32) × 5 ÷ 9.
      //  Création d’objet Datapoint, à partir des données de la lecture
      Datapoint dataStation(timestamp, latitude, longitude, (temperature-32)*5/9.0);
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
    for (std::set<Datapoint>::iterator iter = dataCanada.begin() ; iter!=dataCanada.end() ; iter++){
      mateoCanada << iter->ecrireDatapoint() << std::endl;
    }
    mateoCanada.close();
  }
}