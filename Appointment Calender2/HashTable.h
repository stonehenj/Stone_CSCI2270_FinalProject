#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <string>
using namespace std;

struct Appt{
    string title;
    int month;
    int day;
    int stime;
    int etime;
    string notes;

    Appt *next;

    /*Movie(){};

    Movie(string in_title, int in_year)
    {
        title = in_title;
        year = in_year;
    }*/

};

class HashTable
{
    public:
        HashTable(int);
        ~HashTable();
        void insertAppt(string in_title, int month, int day, int stime, int etime, string notes);
        void findApptByTitle(string);
        void deleteAppt(int,int, string);
        int hashSum(int x, int s);
        void print7Days(int, int);
        void printMonth(int);
        void printDay(int month, int day);
        void reviseAppt();
    protected:
    private:
        Appt *hashTable[372];
};

#endif // HASHTABLE_H
