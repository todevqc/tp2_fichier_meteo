#include <iostream>
#include <string>
#include <fstream>
#include <queue>

#include "datapoint.h"

int main() {
  //  declaration d'un conteneur de type priority_queue
  //  il est aussi possible d'utiliser un conteneur de type Arbre
  std::priority_queue<Datapoint> dataCanada;

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
      //  avec test de fin de fichier pour pas avoir un doublon au dernier enregistrement
      if(!fichierUS.eof()){
        dataCanada.push(dataStation);
      }
    }  
    fichierUS.close();
  }

  //  Écriture des informations sur le nouveaux fichier candata.txt dans le bon ordre
  std::ofstream mateoCanada("candata.txt");
  
  if (!mateoCanada.is_open()){
    std::cout << "Impossible d'ouvrir le fichier !" << std::endl;
  }else{
    while(dataCanada.size() > 0){
      mateoCanada << dataCanada.top().ecrireDatapoint() << std::endl;
      dataCanada.pop();
    }
    mateoCanada.close();
  }
}