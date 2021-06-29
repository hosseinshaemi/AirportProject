#include <iostream>
#include <map>
#include <string>
#include "Classes.h"
using namespace std;

void printAnElement(flight*);
void setInfo(Airport&);
void printOrNot(Airport);

int main() {



    flight *head;
    int n, choose;
    string ti, ml, typ; int pss, fln, ID;

    Airport start(head);
    /*
    start.insert("17:45", "Rachakof 451", "Exit", 547, 54, 66598);
    start.insert("16:41", "Shotor", "Enter", 314, 74, 84941);
    start.insert("15:36", "Khar", "Exit", 432, 63, 98114);
    start.insert("14:52", "Gorbe", "Enter", 234, 198, 14871);
    */

    cout << "1. Set info\n2. Add a flight\n3. Cancel a flight\n4. Arrange flights\n5. view inbound and outbound flights\n6. exit\n";

    while (true)
    {
        cout << "Enter what you want: ";
        cin >> choose;
        if (choose == 1)
        {
            setInfo(start);
            start.setRunway();
        }
        else if (choose == 2)
        {
            int n;
            cout << "Number of flights: "; cin >> n;
            start.setNumberofflights(n);

            for (int i = 0; i < start.getNumberofflights(); i++)
            {
                cout << "Enter flight " << i + 1 << " : ";
                cin >> ti >> ml >> typ >> pss >> fln >> ID;
                start.insert(ti, ml, typ, pss, fln, ID);
            }
            printOrNot(start);

        }
        else if (choose == 3)
        {
            int fln;
            cout << "Enter flight number: "; cin >> fln;
            start.Delete(fln);
            printOrNot(start);
        }
        else if (choose == 4)
        {
            start.sort();
            printOrNot(start);
        }
        else if (choose == 5)
        {
            cout << "Enter runway number: "; cin >> n;
            start.print(n);
        }
        else if (choose == 6)
        {
            break;
        }
    }

    return 0;
}

void printAnElement(flight *node)
{
    cout << "Time: " << node->getTime() << "\t\t" << "Model: " << node->getModel()
    << '\n' << "Type: " << node->getType() << "\t\t" << "Passengers: " << node->getPassengers()
    << '\n' << "Runway: " << node->getRunway() << "\t\t" << "Flight nummber: " << node->getFlightnumber()
    << '\n' << "ID: " << node->getId() << "\n\n";
}

void setInfo(Airport &ins)
{
    int n, i = 0;
    string tmp;
    while (true)
    {
        cout << "Enter airplane and runway " << i + 1 << " : ";
        i++;
        cin >> tmp;
        if (tmp != "Exit")
        {
            cin >> n;
        }
        else
        {
            cout << "Exited\n";
            break;
        }
        ins.airplane_size[tmp] = n;
    }
}

void printOrNot(Airport ins)
{
    string ans;
    cout << "Do you want to print? ";

    while (true)
    {
        cin >> ans;
        if (ans == "Yes" || ans == "yes")
        {
            ins.print(0);
            break;
        }
        else if (ans == "No" || ans == "no")
        {
            return;
        }
        cout << "Try again: ";
    }
}
