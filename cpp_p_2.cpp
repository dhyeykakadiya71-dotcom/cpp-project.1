#include <iostream>

using namespace std;

class Train
{
private:
    int trainNumber;
    char trainName[50];
    char source[50];
    char destination[50];
    char trainTime[10];

    static int trainCount;

public:
    Train()
    {
        trainNumber = 0;
        strcpy(trainName, "");
        strcpy(source, "");
        strcpy(destination, "");
        strcpy(trainTime, "");

        trainCount++;
    }
    Train(int num, const char tName[], const char src[],
          const char dest[], const char time[])
    {
        trainNumber = num;
        strcpy(trainName, tName);
        strcpy(source, src);
        strcpy(destination, dest);
        strcpy(trainTime, time);

        trainCount++;
    }
    
    ~Train()
    {
        trainCount--;
    }

    void setTrainNumber(int num)
    {
        trainNumber = num;
    }

    void setTrainName(char name[])
    {
        strcpy(trainName, name);
    }

    void setSource(char src[])
    {
        strcpy(source, src);
    }

    void setDestination(char dest[])
    {
        strcpy(destination, dest);
    }

    void setTrainTime(char time[])
    {
        strcpy(trainTime, time);
    }

    int getTrainNumber()
    {
        return trainNumber;
    }

    char* getTrainName()
    {
        return trainName;
    }

    char* getSource()
    {
        return source;
    }

    char* getDestination()
    {
        return destination;
    }

    char* getTrainTime()
    {
        return trainTime;
    }

    void inputTrainDetails()
    {
        cout << "Enter Train Number: ";
        cin >> trainNumber;

        cin.ignore();

        cout << "Enter Train Name: ";
        cin.getline(trainName, 50);

        cout << "Enter Source: ";
        cin.getline(source, 50);

        cout << "Enter Destination: ";
        cin.getline(destination, 50);

        cout << "Enter Train Time: ";
        cin.getline(trainTime, 10);
    }

    void displayTrainDetails()
    {
        cout << "Train Number : " << trainNumber << endl;
        cout << "Train Name   : " << trainName << endl;
        cout << "Source       : " << source << endl;
        cout << "Destination  : " << destination << endl;
        cout << "Train Time   : " << trainTime << endl;
    }

    static int getTrainCount()
    {
        return trainCount;
    }
};

int Train::trainCount = 0;

class RailwaySystem
{
private:
    Train trains[100];
    int totalTrains;

public:

    RailwaySystem()
    {
        totalTrains = 0;
    }

    void addTrain()
    {
        if (totalTrains < 5)
        {
            trains[totalTrains].inputTrainDetails();
            totalTrains++;

            cout << "\nTrain Record Added Successfully!\n";
        }
        else
        {
            cout << "Train Storage Full!\n";
        }
    }

    void displayAllTrains()
    {
        if (totalTrains == 0)
        {
            cout << "\nNo Train Records Found!\n";
            return;
        }

        cout << "\n----- All Train Records -----\n";

        for (int i = 0; i < totalTrains; i++)
        {
            cout << "\nTrain " << i + 1 << " Details:\n";
            trains[i].displayTrainDetails();
        }
    }

    void searchTrainByNumber(int number)
    {
        bool found = false;

        for (int i = 0; i < totalTrains; i++)
        {
            if (trains[i].getTrainNumber() == number)
            {
                cout << "\nTrain Found!\n";
                trains[i].displayTrainDetails();

                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "\nTrain with Number "
                 << number
                 << " not found!\n";
        }
    }
};

int main()
{
    RailwaySystem railway;
    int choice, number;

    do
    {
        cout << "\n===== Railway Reservation System =====\n";
        cout << "1. Add New Train Record\n";
        cout << "2. Display All Train Records\n";
        cout << "3. Search Train by Number\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            railway.addTrain();
            break;

        case 2:
            railway.displayAllTrains();
            break;

        case 3:
            cout << "Enter Train Number to Search: ";
            cin >> number;

            railway.searchTrainByNumber(number);
            break;

        case 4:
            cout << "\nExiting the System. Goodbye!\n";
            break;

        default:
            cout << "\nInvalid Choice! Please Try Again.\n";
        }

    } while (choice != 4);
}
/*
	output:
	===== Railway Reservation System =====
	1. Add New Train Record
	2. Display All Train Records
	3. Search Train by Number
	4. Exit
	Enter your choice: 1
	Enter Train Number: 12
	Enter Train Name: dharuka
	Enter Source: jdjf
	Enter Destination: surat
	Enter Train Time: 12 A.M
	
	Train Record Added Successfully!
	
	===== Railway Reservation System =====
	1. Add New Train Record
	2. Display All Train Records
	3. Search Train by Number
	4. Exit
	Enter your choice: 2
	
	----- All Train Records -----
	
	Train 1 Details:
	Train Number : 12
	Train Name   : dharuka
	Source       : jdjf
	Destination  : surat
	Train Time   : 12 A.M
	
	===== Railway Reservation System =====
	1. Add New Train Record
	2. Display All Train Records
	3. Search Train by Number
	4. Exit
	Enter your choice: 3
	Enter Train Number to Search: 12
	
	Train Found!
	Train Number : 12
	Train Name   : dharuka
	Source       : jdjf
	Destination  : surat
	Train Time   : 12 A.M
	
	===== Railway Reservation System =====
	1. Add New Train Record
	2. Display All Train Records
	3. Search Train by Number
	4. Exit
	Enter your choice: 3
	Enter Train Number to Search: 45
	
	Train with Number 45 not found!
	
	===== Railway Reservation System =====
	1. Add New Train Record
	2. Display All Train Records
	3. Search Train by Number
	4. Exit
	Enter your choice: 4
	
	Exiting the System. Goodbye!
*/