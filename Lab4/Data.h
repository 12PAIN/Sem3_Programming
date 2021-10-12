#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>

using namespace std;

class datetime{

private:

    int second, minute, hour, day, month, year;

public:

    virtual void showInfo();
    virtual void addData(int*);
    void showSysDate();
};

class datetimeMsec : public datetime{

private:

    int second, minute, hour, day, month, year, msec;

public:

    virtual void addData(int*);
    virtual void showInfo();

};

class Node{
public:
    Node* prev;
    Node* next;
    datetime* data;
    void objPush(datetime*& new_data);
    void deleteData();
    void PrintNode();
};

class List{
public:

    Node* first;
    Node* last;
    Node* C;

    bool msec = false;

    List(){};

    List(bool check) {
        first = NULL;
        last = NULL;
        C = NULL;
        msec = check;
    }

    ~List() {
    
        deleteAll();

    };

    void getListFromFile(char*);
    void addNode(datetime*& new_date);
    void nodeCreate(int*);
    void printNode();
    void moveNext();
    void movePrev();
    void deleteAll();
    void clearC();
    void listPrint();
    void listPrintSort();
    void deleteCurrent();

};

class fileWork {

public:
    virtual void getData(char*, int&, int**);
    virtual void countData(char*, int&);
    virtual void fileCreate(char*, int**, int);

};

class fileWorkMsec : public fileWork {

public:
    virtual void getData(char*, int&, int**);
    virtual void countData(char*, int&);
    virtual void fileCreate(char*, int**, int);
};

int checkData(int, int);