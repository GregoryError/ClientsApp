#ifndef LOCATION_H
#define LOCATION_H


class location
{
public:
    int value;
    double longitude, latitude;
    QString name;
    location();
    location(const double &lon, const double &lat):longitude(lon), latitude(lat){}
    location(const double &lon, const double &lat, const QString &name):longitude(lon), latitude(lat), name(name){}
    location(const double &lon, const double &lat, const QString &name, int &val):
        longitude(lon), latitude(lat), name(name), value(val){}
    int getval() { return value; }

};

#endif // LOCATION_H
