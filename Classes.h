//
// Created by Hossein Shaemi on 6/26/2021 AD.
//
#include <map>
using namespace std;
#ifndef FINALPROJECT_CLASSES_H
#define FINALPROJECT_CLASSES_H

struct TimeAndRunway {
    int RNW;
    string TIME;
};

class flight {
    private:
        string time;
        string model;
        string type;
        int passengers;
        int runway;
        int flight_number;
        int id;
        flight *nextFlight;
    public:
        flight(string ti, string mdl, string typ, int pss, int fln, int ID) {
            setTime(ti);
            setModel(mdl);
            setType(typ);
            setPassengers(pss);
            setFlightnumber(fln);
            setId(ID);
        }
        flight() {cout << "A flight was added\n";}
        void setTime(string x) {time = x;}
        void setModel(string x) {model = x;}
        void setType(string x) {type = x;}
        void setPassengers(int x) {passengers = x;}
        void setRunway(int x) {runway = x;}
        void setFlightnumber(int x) {flight_number = x;}
        void setId(int x) {id = x;}
        void setNextflight(flight *x) {nextFlight = x;}
        string getTime() {return time;}
        string getModel() {return model;}
        string getType() {return type;}
        int getPassengers() {return passengers;}
        int getRunway() {return runway;}
        int getFlightnumber() {return flight_number;}
        int getId() {return id;}
        flight *getNextflight() {return nextFlight;}
};

class Airport {
    private:
        flight *first;
        int number_of_flights;
    public:
        map <string, int> airplane_size;
        int runways[100] = {0};
        Airport(flight *firstNode) {setFirst(firstNode);}
        void setFirst(flight *x) {first = x;}
        void setNumberofflights(int x) {number_of_flights = x;}
        void setRunway();
        flight *getFirst() {return first;}
        int getNumberofflights() {return number_of_flights;}
        void insert(string, string, string, int, int, int);
        void sort();
        void print(int);
        void Delete(int);
        flight *searchById(int);
        flight *searchByFlightNumber(int);
        TimeAndRunway searchForRunway(string, int);
};

#endif //FINALPROJECT_CLASSES_H
