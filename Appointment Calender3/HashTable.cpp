#include "HashTable.h"
#include <iostream>
using namespace std;

int HashTable::hashSum(int m, int d)
{
    int sum = m*d;
    return sum;
}
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

void HashTable::insertAppt(std::string in_title, int month, int day, int stime, int etime, string notes)
{
    Appt *a = new Appt;
    a->title = in_title;
    a->month = month;
    a->day = day;
    a->stime = stime;
    a->etime = etime;
    a->notes = notes;
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
                cout<<"--"<<x->notes<<"--"<<endl;
                return;
            }
            x = x->next;
        }
    }
    cout<<"not found"<<endl;
}
void HashTable::printDay(int m, int d)
{
    Appt *x = hashTable[hashSum(m,d)];
    while(x!=NULL)
    {
        if(x->month == m && x->day == d)
        {
            cout<<x->title<<":"<<x->month<<"/"<<x->day<<"/"<<"2015"<<":"<<x->stime<<" to "<<x->etime<<endl;
            cout<<"--"<<x->notes<<"--"<<endl;
        }
        x = x->next;
    }
}
void HashTable::printMonth(int m)
{
    for(int i = 1;i<32;i++)
    {
        printDay(m,i);
    }
}
void HashTable::print7Days(int m, int d)
{
    for(int i = d;i<d+7;i++)
    {
        printDay(m,i);
    }
}
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
/*void HashTable::reviseAppt(int m, string title)
{
    for(int i = 1;i<32;i++)
    {
        while(x != NULL)
        {
            Appt *x = hashTable[hashSum(m,i)];
            if(x->title == title)
            {

            }
        }
    }
}*/
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
void HashTable::checkFreeTimeMonth(int m)
{
   for(int i = 1;i < 32; i++)
   {
       checkFreeTimeDay(m,i);
   }
}


