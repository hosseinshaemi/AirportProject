//
// Created by Hossein Shaemi on 6/26/2021 AD.
//
#include <iostream>
#include <map>
#include "Classes.h"
using namespace std;

void swapForArray(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
int findInArray(int *arr, int key)
{
    int andis = 0;
    for (int i = 0; i < 100; i++)
        if (arr[i] == key)
        {
            andis = i;
            break;
        }
    return andis;
}
string TimeAddition(string t, int add)
{
    int hour = 0;
    int minute = 0;
    int newT = 0;

    hour = ( (int(t[0]) - 48) * 10 ) + (int(t[1]) - 48);
    minute = ( (int(t[3]) - 48) * 10 ) + (int(t[4]) - 48);

    newT = (hour * 60) + minute;

    newT += add;

    hour = newT / 60;
    minute = newT - (hour * 60);

    char tmp[6];
    tmp[0] = char( ( (hour - (hour % 10)) / 10) + 48 );
    tmp[1] = char((hour % 10) + 48);
    tmp[2] = ':';
    tmp[3] = char( ( (minute - (minute % 10)) / 10) + 48 );
    tmp[4] = char((minute % 10) + 48);
    tmp[5] = '\0';

    string s = "";
    for (int i = 0; tmp[i] != '\0'; i++)
        s = s + tmp[i];
    return s;
}
bool check(string ti, int rnw, flight *node)
{
    flight *tmp = node;
    bool flag = true;
    while (tmp != NULL)
    {
        if (rnw == tmp->getRunway() && ti == tmp->getTime())
        {
            flag = false;
            break;
        }
        tmp = tmp->getNextflight();
    }
    return flag;
}
int convertTime(string t)
{
    int hour = 0, minute = 0, Time = 0;
    hour = ( (int(t[0]) - 48) * 10 ) + (int(t[1]) - 48);
    minute = ( (int(t[3]) - 48) * 10 ) + (int(t[4]) - 48);
    Time = (hour * 60) + minute;

    return Time;
}
void printAnElement1(flight *node)
{
    cout << "Time: " << node->getTime() << "\t\t" << "Model: " << node->getModel()
         << '\n' << "Type: " << node->getType() << "\t\t" << "Passengers: " << node->getPassengers()
         << '\n' << "Runway: " << node->getRunway() << "\t\t" << "Flight nummber: " << node->getFlightnumber()
         << '\n' << "ID: " << node->getId() << "\n\n";
}
flight *swap(flight *ptr1, flight *ptr2)
{
    flight *tmp = ptr2->getNextflight();
    ptr2->setNextflight(ptr1);
    ptr1->setNextflight(tmp);
    return ptr2;
}

void Airport::print(int run)
{

    flight *tmp = first;
    if (run == 0)
    {
        while (tmp != NULL)
        {
            cout << "Time: " << tmp->getTime() << "\t\t" << "Model: " << tmp->getModel()
            << '\n' << "Type: " << tmp->getType() << "\t\t" << "Passengers: " << tmp->getPassengers()
            << '\n' << "Runway: " << tmp->getRunway() << "\t\t" << "Flight nummber: " << tmp->getFlightnumber()
            << '\n' << "ID: " << tmp->getId() << "\n\n";
            tmp = tmp->getNextflight();
        }
    }
    else
    {
        while (tmp != NULL)
        {
            if (tmp->getRunway() == run)
                cout << "Time: " << tmp->getTime() << "\t\t" << "Model: " << tmp->getModel()
                << '\n' << "Type: " << tmp->getType() << "\t\t" << "Passengers: " << tmp->getPassengers()
                << '\n' << "Runway: " << tmp->getRunway() << "\t\t" << "Flight nummber: " << tmp->getFlightnumber()
                << '\n' << "ID: " << tmp->getId() << "\n\n";
            tmp = tmp->getNextflight();
        }
    }
}

TimeAndRunway Airport::searchForRunway(string ti, int rnw)
{
    int newRnw, index, i = 0;
    string tmp = ti;
    bool flag;
    flight *tmp1 = first;

    while (true)
    {
        flag = false;
        tmp = TimeAddition(tmp, i);
        index = findInArray(runways, rnw);
        newRnw = runways[index];
        for (int j = 0; newRnw != 0; j++)
        {
            newRnw = runways[index + j];
            if (newRnw == 0) {break;}
            if (check(tmp, newRnw, tmp1))
            {
                flag = true;
                break;
            }
        }
        i = 0;
        i += 30;
        if (flag == true) {break;}
    }

    TimeAndRunway save;
    save.RNW = newRnw;
    save.TIME = tmp;

    return save;


}

void Airport::insert(string tme, string mdl, string tp, int pass, int flno, int ID)
{
    flight *newNode = new flight();

    flight **tmp = &first;

    TimeAndRunway Checked = Airport::searchForRunway(tme, airplane_size[mdl]);
    newNode->setTime(Checked.TIME);
    newNode->setModel(mdl);
    newNode->setType(tp);
    newNode->setPassengers(pass);
    newNode->setRunway(Checked.RNW);
    newNode->setFlightnumber(flno);
    newNode->setId(ID);
    newNode->setNextflight(NULL);

    flight *lastFlight = *tmp;

    if (*tmp == NULL)
    {
        *tmp = newNode;
        return;
    }

    while (lastFlight->getNextflight() != NULL)
        lastFlight = lastFlight->getNextflight();

    lastFlight->setNextflight(newNode);
    return;
}

flight *Airport::searchById(int ID)
{
    flight *tmp = first;
    flight *found;
    while (tmp != NULL)
    {
        if (tmp->getId() == ID) {found = tmp; break;}
        tmp = tmp->getNextflight();
    }
    return found;
}

flight *Airport::searchByFlightNumber(int Flno)
{
    flight *tmp = first;
    flight *prev = NULL;
    while (tmp != NULL)
    {
        if (tmp->getFlightnumber() == Flno) {break;}
        prev = tmp;
        tmp = tmp->getNextflight();
    }
    return prev;
}

void Airport::Delete(int Flno)
{
    flight **tmp = &first;
    flight **tmp1 = &first;

    flight *temp = *tmp;

    if (temp != NULL && temp->getFlightnumber() == Flno)
    {
        *tmp1 = temp->getNextflight();
        delete temp;
        return;
    }
    else
    {
        flight *find = Airport::searchByFlightNumber(Flno);
        flight *next1 = find->getNextflight();
        flight *next2 = next1->getNextflight();
        find->setNextflight(next2);
        delete next1;
        return;
    }
}

void Airport::setRunway()
{
    map <string, int>::iterator it;
    int n = 0;
    for (n = 0, it = airplane_size.begin(); it != airplane_size.end(); it++, n++)
        runways[n] = it->second;

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (runways[j] > runways[j + 1])
                swapForArray(runways[j], runways[j + 1]);
}

void Airport::sort()
{
      flight **head = &first;
      flight **h;
      flight *tmp;

      bool flag;

      for (int i = 0; i <= number_of_flights; i++)
      {
          h = head;
          flag = false;
          for (int j = 0; j < number_of_flights - i - 1; j++)
          {
              flight *p1 = *h;
              flight *p2 = p1->getNextflight();

              if (convertTime(p1->getTime()) > convertTime(p2->getTime()))
              {
                  *h = swap(p1, p2);
                  flag = true;
              }
              tmp = (*h)->getNextflight();
              h = &tmp;
          }

          if (flag == false)
              break;
      }
}