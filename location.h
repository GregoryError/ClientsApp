#ifndef LOCATION_H
#define LOCATION_H
#include <QRect>
#include <mainwindow.h>

class location
{
public:
    double longitude, latitude;
    location();
    location(const double &lon, const double &lat):longitude(lon), latitude(lat){}

    bool operator >(location &obj)
    {
        location temp(longitude, latitude);
        location zero(0.0, 0.0);
        if(ShowDiff(temp, zero) > ShowDiff(obj, zero))
                return true;
                else return false;
    }
    bool operator <(location &obj)
    {
        location temp(longitude, latitude);
        location zero(0.0, 0.0);
        if(ShowDiff(temp, zero) < ShowDiff(obj, zero))
                return true;
                else return false;
    }

    double ShowDiff(location &first, location &second)
    {
        return pow(pow((first.latitude - second.latitude), 2) + pow((first.longitude - second.longitude), 2), 0.5);
    }


};

#endif // LOCATION_H
