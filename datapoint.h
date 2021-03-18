#ifndef __DATAPOINT_H__
#define __DATAPOINT_H__

#include <iostream>
#include <string>

class Datapoint {
    private:
        std::string timestamp;
        double latitude;
        double longitude;
        double temperature;
    public:
        Datapoint(std::string timestamp, double latitude, double longitude, double temperature);
        
        std::string ecrireDatapoint() const;

        bool operator<(const Datapoint& datapoint_suivant) const {
            if (this->latitude > datapoint_suivant.latitude) return true;
            else if ((this->latitude == datapoint_suivant.latitude) && (this->longitude < datapoint_suivant.longitude)){
                return true;
            }
            return false;
        }
};

#endif // __DATAPOINT_H__