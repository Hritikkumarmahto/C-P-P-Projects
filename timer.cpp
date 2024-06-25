#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;

int main()
{
    short minutes, seconds;
    int time;

    do
    {
        cout << "Enter Seconds:: ";
        cin >> seconds;
    } while (seconds > 59);
    do
    {
        cout << "Enter Minute:: ";
        cin >> minutes;
    } while (minutes > 59);

    time = (minutes != 0) ? minutes * 60 : 0;
    time += seconds;

    for (int i = time; i > 0; i--)
    {
        system("cls");
        cout << "Time remaining is 0:" << minutes << ":" << seconds << endl;
        minutes = (i % 60 == 0) ? --minutes : minutes;
        seconds = (seconds == 0) ? 59 : --seconds;
        system("sleep 1");
    }
    system("clear");
    cout << "---------------------------\n Timer Ended!\a\n Lasted For " << time << " second" << "\n----------------------\n\n"
         << endl;
    return 0;
}