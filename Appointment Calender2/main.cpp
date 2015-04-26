#include <iostream>
#include "HashTable.h"
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

int main()
{
    HashTable h(372);
    string title;
    string month;
    string day;
    string stime;
    string etime;
    string notes;
    int m;
    int d;
    int s;
    int e;
    string choice;

    while(choice != "5")
    {
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Insert appointment"<<endl;
        cout<<"2. Delete appointment"<<endl;
        cout<<"3. Revise appointment"<<endl;
        cout<<"4. Find appointment"<<endl;
        cout<<"5. Show a day's schedule"<<endl;
        cout<<"6. Show schedule for the next 7 days"<<endl;
        cout<<"7. Show a month's schedule"<<endl;
        cout<<"8. Show free time"<<endl;
        cout<<"9. Quit"<<endl;
        cin>>choice;

        if(choice == "1")
        {
            cout<<"Enter appointment title:"<<endl;
            cin.ignore();
            getline(cin,title);
            cout<<"Enter month of appointment(by number~Jan=1,Feb=2,etc):"<<endl;
            getline(cin,month);
            m = atoi(month.c_str());
            cout<<"Enter day of appointment(by number~1 to 31):"<<endl;
            getline(cin,day);
            d = atoi(day.c_str());
            cout<<"Enter starting time of appointment(military time~1 to 24):"<<endl;
            getline(cin,stime);
            s = atoi(stime.c_str());
            cout<<"Enter ending time of appointment(military time~1 to 24):"<<endl;
            getline(cin,etime);
            e = atoi(etime.c_str());
            cout<<"Enter additional notes(ex. 'Bring present'):"<<endl;
            getline(cin,notes);
            h.insertAppt(title,m,d,s,e,notes);


        }
        if(choice == "2")
        {
            cout<<"Enter month of appointment(by number~Jan=1,Feb=2,etc):"<<endl;
            cin.ignore();
            getline(cin,month);
            m = atoi(month.c_str());
            cout<<"Enter day of appointment(by number~1 to 31):"<<endl;
            getline(cin,day);
            d = atoi(day.c_str());
            cout<<"Here are all of the appointments that day"<<endl;
            h.printDay(m,d);
            cout<<"Enter the title of appointment to delete:"<<endl;
            getline(cin,title);
            h.deleteAppt(m,d,title);


        }
        if(choice == "3")
        {
            cout<<"Enter month of appointment(by number~Jan=1,Feb=2,etc):"<<endl;
            cin.ignore();
            getline(cin, month);
            m = atoi(month.c_str());
            cout<<"Here are all of the appointments for this month:"<<endl;
            h.printMonth(m);
            cout<<"What is the name of the appointment you wish to revise?:"<<endl;
            getline(cin,title);

        }
        if(choice == "4")
        {
            cout<<"Do you remember the month of the appointment(y or n)?:"<<endl;
            cin.ignore();
            getline(cin,month);
            if(month == "y")
            {
                Cout<<"Enter month:"<<endl;
                getline(cin,month);
                m = atoi(month.c_str());
                cout<<"Do you remember the day of the appointment(y or n)?"<<endl;
                getline(cin,day);
                if(day == "y")
                {
                    cout<<"Enter day:"<<endl;
                    getline(cin, day);
                    d = atoi(day.c_str());
                    cout<<"Here are all of the appointments for that day:"<<endl;
                    h.printDay(m,d);
                    return;
                }
                cout<<"Here are all of the appointments for this month:"<<endl;
                h.printMonth(m);
                return;
            }
            cout<<"Do you remember the name of the appointment(y or n?):"<<endl;
            getline(cin, title);
            if(title == "y")
            {
                cout<<"Enter name:"<<endl;
                getline(cin,title);
                h.findApptByTitle(title);
            }

        }
        if(choice == "7")
        {
            cout<<"Enter month of appointment(by number~Jan=1,Feb=2,etc):"<<endl;
            cin.ignore();
            getline(cin,month);
            m = atoi(month.c_str());
            h.printMonth(m);
        }

    }


    return 0;
}
