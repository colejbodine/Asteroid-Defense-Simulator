#ifndef PROJECT3HEADER_H_INCLUDED
#define PROJECT3HEADER_H_INCLUDED

using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


void get_input(double& diameter, double& distance)
{

    cout << "Enter the meteor size in meters: ";
    cin >> diameter;
    cout << endl;
    cout << "Enter the meteor's distance from Earth in Miles: ";
    cin >> distance;
    cout << endl;

    while((diameter <= 0) || (distance <= 0))
    {
        SetConsoleTextAttribute(hConsole, 14);
        cout << "\t Attention: Invalid Data Has Been Entered.";
        Sleep(2000);
        system("CLS");
        SetConsoleTextAttribute(hConsole, 7);

        cout << "Enter the meteor size in meters: ";
        cin >> diameter;
        cout << endl;
        cout << "Enter the meteor's distance from Earth in Miles: ";
        cin >> distance;
        cout << endl;
    }
}

void meteor_data(double diameter, double distance, double& speed, double& time)
{
    speed = 120 * diameter;
    time = (distance/speed) * 60;

    cout << fixed << setprecision(2);
    cout << "Meteor Data:" << endl;
    cout << "\t" << "Diameter: " << diameter << " meters" << endl;
    cout << "\t" << "Distance from Earth: " << distance << " miles" << endl;
    cout << "\t" << "Speed in Miles per hour: " << speed << " mph" << endl;
    cout << "\t" << "Time to Impact: " << time << " Minutes" << endl << endl;
}

bool can_be_tracked(double diameter, double distance, bool trackable)
{
    trackable = false;

    if(diameter >= 3 && distance <= 440)
    {
        trackable = true;
    }
    else if(diameter >= 2 && distance <= 330)
    {
        trackable = true;
    }
    else if(diameter >= 1 && distance <= 220)
    {
        trackable = true;
    }
    else if(diameter < 1 && distance <= 110)
    {
        trackable = true;
    }

    return trackable;
}

void engagement_data(double diameter, double distance, double speed, double time, bool trackable, char& runAnother)
{
    double interceptRange = distance - (3.4 * (speed / 60));

    if(trackable == true)
    {
        if(interceptRange > 0 && interceptRange < distance)
        {
            cout << "Engagement Data:" << endl;
            cout << "\t" << "Missile Intercept Range: " << interceptRange << " miles" << endl;
            SetConsoleTextAttribute(hConsole, 10);
            cout << "\t" << "MDS Status: Missile Intercept Probable" << endl << endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "Meteor Status:" << endl;
            SetConsoleTextAttribute(hConsole, 14);
            cout << "\t" << "Meteor Inbound" << endl << endl << endl;
            SetConsoleTextAttribute(hConsole, 7);
        }
        else
        {
            cout << "Engagement Data:" << endl;
            SetConsoleTextAttribute(hConsole, 12);
            cout << "\t" << "MDS Status: Missile Intercept not Possible." << endl;
            cout << "\t" << "Earth Impact in " << time << " minutes" << endl << endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "Meteor Status:" << endl;
            SetConsoleTextAttribute(hConsole, 12);
            cout << "\t" << "Meteor Inbound" << endl << endl << endl;;
            SetConsoleTextAttribute(hConsole, 7);
        }
    }
    else if(trackable == false)
    {
        cout << "Engagement Data:" << endl;
        cout << "\t" << "Missile Intercept Range: " << "0.00" << " miles" << endl;
        SetConsoleTextAttribute(hConsole, 12);
        cout << "\t" << "MDS Status: Missile Intercept not Possible." << endl;
        cout << "\t" << "Earth Impact in " << time << " minutes" << endl << endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout << "Meteor Status:" << endl;
        SetConsoleTextAttribute(hConsole, 12);
        cout << "\t" << "Meteor Inbound" << endl << endl << endl;;
        SetConsoleTextAttribute(hConsole, 7);
    }

    cout << "Enter Y to run another, any other key to quit. ";
    cin >> runAnother;
}

#endif // PROJECT3HEADER_H_INCLUDED
