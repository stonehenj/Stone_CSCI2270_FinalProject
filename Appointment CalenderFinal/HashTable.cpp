#include "HashTable.h"
#include <iostream>
using namespace std;
/*
Function prototype:
int HashTable::hashSum(int, int)

Function description:
This method calculates the hashcode for the appointments to be entered into the table.

Example:
HashTable a;
a.hashSum(5,22);

Precondition:Inputs are month and day
Postcondition:Returns the spot in the hashtable where the appointment for that month and day will be stored
*/

int HashTable::hashSum(int m, int d)
{
    int sum = m*d;
    return sum;
}

//Hashtable initializer. sets all locations to NULL
HashTable::HashTable(int h)
{
    Appt *a[h];
    for(int i = 0;i<h;i++)
    {
        a[i] = NULL;
        hashTable[i] = a[i];
    }

}

HashTable::~HashTable()
{
    //dtor
}

/*
Function prototype:
void HashTable::insertAppt(std::string in_title, int month, int day, int stime, int etime, string priority, string notes)

Function description:
This method enters Appointment nodes into hashtable. When there are collisions, the nodes are added to the linked list
and sorted by time of appointment.

Example:
HashTable a;
a.insertAppt("Dave's Birthday",1,10,1,23,y,"Bring cake");

Precondition:Hashatble is initialized. each variable is the right type.
Postcondition:Hashtable is being filled. pointers are updated to reflect this
*/
void HashTable::insertAppt(std::string in_title, int month, int day, int stime, int etime, string priority, string notes)
{
    Appt *a = new Appt;
    a->title = in_title;
    a->month = month;
    a->day = day;
    a->stime = stime;
    a->etime = etime;
    a->notes = notes;
    if(priority == "y")
    {
        a->priority = true;
    }
    else
    {
        a->priority = false;
    }
    a->next = NULL;

    if(hashTable[hashSum(month, day)] == NULL)
    {
        hashTable[hashSum(month, day)] = a;
    }
    else
    {
        Appt *x = hashTable[hashSum(month, day)];
        if(a->stime <= x->stime)
        {
            a->next = x;
            x = NULL;
            hashTable[hashSum(month,day)] = a;
            return;
        }
        while(x->next!=NULL)
        {
            if(a->stime <= x->next->stime)
            {
                a->next = x->next;
                x->next = a;
                return;

            }
            x = x->next;
        }
        x->next = a;
        x = NULL;
    }

}

/*
Function prototype:
void  HashTable::findApptByTitle(string title)

Function description:
Searches entire hashtable for an appointment by its name

Example:
HashTable a;
a.findApptByTitle("Dave's Birthday");

Precondition:Hashatble is initialized. each variable is the right type.
Postcondition:Nothing really changes, just searches and prints
*/
void  HashTable::findApptByTitle(string title)
{
    for(int i = 0;i<372;i++)
    {



        Appt *x = hashTable[i];
        while(x!=NULL)
        {
            if(x->title == title)
            {
                cout<<x->title<<":"<<x->month<<"/"<<x->day<<"/"<<"2015"<<":"<<x->stime<<" to "<<x->etime<<endl;
                cout<<"Priority:"<<x->priority<<endl;
                cout<<"--"<<x->notes<<"--"<<endl;
                return;
            }
            x = x->next;
        }
    }
    cout<<"not found"<<endl;
}
/*
Function prototype:
void  HashTable::printDay(int,int)

Function description:
Jumps to location in hashtable and if it needs to, iterates through linked list to find specific day and prints appointments

Example:
HashTable a;
a.printDay(1,10);

Precondition:Hashatble is initialized. each variable is the right type.
Postcondition:Nothing really changes, just searches and prints
*/
void HashTable::printDay(int m, int d)
{
    Appt *x = hashTable[hashSum(m,d)];
    while(x!=NULL)
    {
        if(x->month == m && x->day == d)
        {
            cout<<x->title<<":"<<x->month<<"/"<<x->day<<"/"<<"2015"<<":"<<x->stime<<" to "<<x->etime<<endl;
            cout<<"Priority:"<<x->priority<<endl;
            cout<<"--"<<x->notes<<"--"<<endl;
        }
        x = x->next;
    }
}
/*
Function prototype:
void  HashTable::printMonth(int)

Function description:
Prints appointments in every day for a specific month

Example:
HashTable a;
a.printMonth(10);

Precondition:Hashatble is initialized. each variable is the right type.
Postcondition:Nothing really changes, just searches and prints
*/
void HashTable::printMonth(int m)
{
    for(int i = 1;i<32;i++)
    {
        printDay(m,i);
    }
}
/*
Function prototype:
void  HashTable::print7Days(int,int)

Function description:
Prints appointments in every day for a week

Example:
HashTable a;
a.printMonth(1,10);

Precondition:Hashatble is initialized. each variable is the right type.
Postcondition:Nothing really changes, just searches and prints
*/
void HashTable::print7Days(int m, int d)
{
    for(int i = d;i<d+7;i++)
    {
        printDay(m,i);
    }
}
/*
Function prototype:
void  HashTable::deleteAppt(int,int,string)

Function description:
jumps to location in hashtable and deletes an appointment node that matches the name user inputs

Example:
HashTable a;
a.deleteAppt(1,10,"Dave's Birthday");

Precondition:Hashatble is initialized. each variable is the right type. The appointment to delete exists
Postcondition:appointment node deleted from chain and memory freed. Pointers updated to bypass deleted appointment.
*/
void HashTable::deleteAppt(int m, int d, string title)
{
    Appt *x = hashTable[hashSum(m,d)];
    Appt *y;
    if(title == x-> title)
    {
        y = x->next;
        hashTable[hashSum(m,d)] = y;
        delete x;
        x = NULL;
        y = NULL;
        return;
    }
    else
    {


        while(x->next!=NULL)
        {
            if(title == x->next->title)
            {
                y = x->next;
                x->next = y->next;
                y->next = NULL;
                delete y;
                y = NULL;
                return;
            }
            x = x->next;
        }
    }

}
/*
Function prototype:
void  HashTable::printPriorityDay(int,int)

Function description:
jumps to location in hashtable and only prints appointments that are priority

Example:
HashTable a;
a.printPriorityDay(1,10,);

Precondition:Hashatble is initialized. each variable is the right type.
Postcondition:Nothing really changes, just searches and prints
*/
void HashTable::printPriorityDay(int m, int d)
{
    Appt *x = hashTable[hashSum(m,d)];
    while(x!=NULL)
    {
        if(x->month == m && x->day == d && x->priority == true)
        {
            cout<<x->title<<":"<<x->month<<"/"<<x->day<<"/"<<"2015"<<":"<<x->stime<<" to "<<x->etime<<endl;
            cout<<"Priority:"<<x->priority<<endl;
            cout<<"--"<<x->notes<<"--"<<endl;
        }
        x = x->next;
    }

}
/*
Function prototype:
void  HashTable::printPriorityMonth(int)

Function description:
Searches hashtable and only prints priority appointments for a specific month

Example:
HashTable a;
a.printPriorityMonth(10);

Precondition:Hashatble is initialized. each variable is the right type.
Postcondition:Nothing really changes, just searches and prints
*/
void HashTable::printPriorityMonth(int m)
{
   for(int i = 1;i<32;i++)
    {
        printPriorityDay(m,i);
    }
}
/*
Function prototype:
void  HashTable::checkFreeTimeDay(int,int)

Function description:
jumps to location in hashtable and prints out the times of day there is not an appointment

Example:
HashTable a;
a.checkFreeTimeDay(1,10);

Precondition:Hashatble is initialized. each variable is the right type.
Postcondition:Nothing really changes, just searches and prints
*/
void HashTable::checkFreeTimeDay(int m, int d)
{
    Appt *x = hashTable[hashSum(m,d)];
    if(x->stime != 1)
    {
        while(x != NULL)
        {
            int a = 1;
            cout<<"You are free from "<<a<<" to "<<x->stime<<endl;
            a = x->etime;
            x = x->next;
        }
        return;
    }
    while(x != NULL)
    {
        int a = x->etime;
        cout<<"You are free from "<<a<<" to "<<x->stime<<endl;
        a = x->etime;
        x = x->next;
    }
}
/*
Function prototype:
void  HashTable::checkFreeTimeMonth(int)

Function description:
searches hashtable for free time within a specific month and prints it

Example:
HashTable a;
a.checkFreeTimeMonth(10);

Precondition:Hashatble is initialized. each variable is the right type.
Postcondition:Nothing really changes, just searches and prints
*/
void HashTable::checkFreeTimeMonth(int m)
{
   for(int i = 1;i < 32; i++)
   {
       checkFreeTimeDay(m,i);
   }
}


