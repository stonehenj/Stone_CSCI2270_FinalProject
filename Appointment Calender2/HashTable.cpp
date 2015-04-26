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
Appt*  HashTable::findAppt(int m, int d)
{

    Appt *x = hashTable[hashSum(m,d)];
    while(x!=NULL)
    {
        if(x->month == m && x->day == d)
        {
            //printDay();
            /*
            return x;*/
        }
        x = x->next;
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
/*void HashTable::deleteMovie(std::string in_title)
{
    Movie *x = hashTable[hashSum(in_title,10)];
    Movie *y;
    while(x!=NULL)
    {
        if(in_title == x->title)
        {
            y = x->next;
            delete x;
            x = y;
            return;
        }
        x = x->next;
    }

}*/
/*void HashTable::printInventory()
{
    for(int i = 0;i<10;i++)
    {
        if(hashTable[i]!=NULL)
        {
            Movie *x = hashTable[i];
            while(x!=NULL)
            {
                cout<<x->title<<":"<<x->year<<endl;
                x = x->next;
            }
        }
    }
}*/

