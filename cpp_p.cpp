#include<iostream>
using namespace std;

class TimeConverter
{
public:

    void sectoHMS()
    {
        int totalsec;

        cout << "Enter total seconds: ";
        cin >> totalsec;

        int hour = totalsec / 3600;
        int min = (totalsec % 3600) / 60;
        int sec = totalsec % 60;

        cout << "Total time is: ";
        cout << hour << ":" << min << ":" << sec << endl;
    }

    void HMStosec()
    {
        int hour, min, sec;

        cout << "Enter hour: ";
        cin >> hour;

        cout << "Enter minute: ";
        cin >> min;

        cout << "Enter second: ";
        cin >> sec;

        int totalsec = (hour * 3600) + (min * 60) + sec;

        cout << "Total seconds: " << totalsec << endl;
    }
};

int main()
{
    TimeConverter tc;
    int choice;

    cout << "1. Second to HMS" << endl;
    cout << "2. HMS to Second" << endl;
    cout << "Choose any one: ";
    cin >> choice;

    if(choice == 1)
    {
        tc.sectoHMS();
    }
    else if(choice == 2)
    {
        tc.HMStosec();
    }
    else
    {
        cout << "Invalid choice" << endl;
    }
}
/*outpu:
	1. Second to HMS
	2. HMS to Second
	Choose any one: 2
	Enter hour: 1
	Enter minute: 1
	Enter second: 1
	Total seconds: 3661
*/