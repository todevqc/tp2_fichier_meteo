#include <iostream>
#include <string>
#include <fstream>
#include <set>

#include "datapoint.h"

int main() {

  std::set<Datapoint> dataCanada;

  std::ifstream fichierUS("rawdata.txt");
  if (!fichierUS.is_open()){
    std::cout << "Impossible d'ouvrir le fichier !" << std::endl;
  }else{  
    double latitude;
    double longitude;
    double temperature;
    std::string timestamp;  

    while(!fichierUS.eof()){
      std::string stationNonUtile;
      fichierUS >> latitude >> longitude >> stationNonUtile >> temperature >> timestamp;
      //  T°C = (T°F − 32) × 5 ÷ 9.
      Datapoint dataStation(timestamp, latitude, longitude, (temperature-32.0)*5.0/9.0);
      dataCanada.insert(dataStation);
    }  
  }
  fichierUS.close();
  
  std::ofstream mateoCanada("candata.txt");
  std::set<Datapoint>::iterator it;
  for (it=dataCanada.begin(); it!=dataCanada.end(); ++it) {
    mateoCanada << it->ecrireDatapoint() << std::endl;
  }
}