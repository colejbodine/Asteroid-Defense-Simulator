#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include "Project3Header.h"

using namespace std;

int main()
{
    double diameter, distance, speed, time;
    bool trackable;
    char runAnother = 'Y';

    while(runAnother == 'y' || runAnother == 'Y')
    {
        get_input(diameter, distance);
        meteor_data(diameter, distance, speed, time);
        trackable = can_be_tracked(diameter, distance, trackable);
        engagement_data(diameter, distance, speed, time, trackable, runAnother);
        system("CLS");
    }

    return 0;
}
