#include "Data.h"
#pragma warning(disable : 4996)

int checkData(int left, int right) {

    double temp;
    cout << " Insert value larger than " << left << " or smaller than " << right << " ->"; cin >> temp;
    while (temp<left || temp>right || (temp - (int)temp) > 0) {
        cout << "\nInserted wrong value! Try again! ->"; cin >> temp;
    }

    return temp;
};

void datetime::showInfo(){

    cout << hour << ":" << minute << ":" << second << " " << day << "/" << month << "/" << year;

}

void datetime::showSysDate() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    
    strftime(buf, sizeof(buf), "%d-%m-%Y %X", &tstruct);

    cout << "System date: " << buf << endl;
}

void datetime::addData(int* arr) {

    hour = arr[0];
    minute = arr[1];
    second = arr[2];
    day = arr[3];
    month = arr[4];
    year = arr[5];
    //showInfo(); cout << endl;
}

void datetimeMsec::showInfo() {

    cout << hour << ":" << minute << ":" << second << "." << msec << " " << day << "/" << month << "/" << year;

}

void datetimeMsec::addData(int* arr) {

    hour = arr[0];
    minute = arr[1];
    second = arr[2];
    day = arr[3];
    month = arr[4];
    year = arr[5];
    msec = arr[6];
    //showInfo(); cout << endl;
}

void fileWork::getData(char* fileName, int& i, int** data_new) {
    ifstream fin(fileName);

    if (fin) {
        int* arr = new int[6];

        int j = 0;

        while (fin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5]) {
            data_new[j] = arr;
            if(j-1 < i)arr = new int[6];
            j++;
        }
    }
    else {
        cout << "Error! Current file not found!";
    }

    fin.close();
}

void fileWork::countData(char* fileName, int& i) {
    ifstream fin(fileName);

    if (fin) {
        int arr[6];
        while (fin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4] >> arr[5]) {
            i++;
        }
    }
    else {
        cout << "Error! Current file not found!";
    }

    fin.close();
}

void fileWork::fileCreate(char* filename, int** arr, int count) {
    ofstream fout(filename);

    for (int i = 0; i < count; i++) {
        fout << arr[i][0] << " " << arr[i][1] << " " << arr[i][2] << " " << arr[i][3] << " " << arr[i][4] << " " << arr[i][5];
        if (i - 1 < count) cout << endl;
    }

    fout.close();
}

void fileWorkMsec::getData(char* fileName, int& i, int** data_new) {
    ifstream fin(fileName);

    if (fin) {
        int* arr = new int[7];

        int j = 0;

        while (fin >> arr[0] >> arr[1] >> arr[2] >> arr[6] >> arr[3] >> arr[4] >> arr[5]) {
            data_new[j] = arr;
            if (j - 1 < i)arr = new int[7];
            j++;
        }
    }
    else {
        cout << "Error! Current file not found!";
    }

    fin.close();
}

void fileWorkMsec::fileCreate(char* filename, int** arr, int count) {

    ofstream fout(filename);

    for (int i = 0; i < count; i++) {
        fout << arr[i][0] << " " << arr[i][1] << " " << arr[i][2] << " " << arr[i][6] << " " << arr[i][3] << " " << arr[i][4] << " " << arr[i][5] << endl;
        if (i - 1 < count) cout << endl;
    }

    fout.close();
}

void fileWorkMsec::countData(char* fileName, int& i) {
    ifstream fin(fileName);

    if (fin) {
        int arr[7];
        while (fin >> arr[0] >> arr[1] >> arr[2] >> arr[6] >> arr[3] >> arr[4] >> arr[5]) {
            i++;
        }
    }
    else {
        cout << "Error! Current file not found!";
    }

    fin.close();
}

void List::getListFromFile(char* fileName) {

    int i = 0;

    fileWork* file;

    if (msec == true) {
        file = new fileWorkMsec;
    }
    else {
        file = new fileWork;
    }

    file->countData(fileName, i);

    int** new_data = new int* [i];

    file->getData(fileName, i, new_data);

    datetime* new_date;

    for (int j = 0; j < i; j++) {
        if (msec == true) {
            new_date = new datetimeMsec;
        }
        else {
            new_date = new datetime;
        }

        new_date->addData(new_data[j]);
        //cout << new_data[j]->hour << " ";
        addNode(new_date);
    }

    delete[] new_data;
}

void List::addNode(datetime*& new_date) {

    if (first == NULL) {
        Node* temp = new Node;

        temp->next = NULL;
        temp->prev = NULL;

        C = temp;
        first = temp;
        last = temp;

        temp->objPush(new_date);

    }else

    if (first != NULL && last != NULL) {
        Node* temp = new Node;
        if (first == last) {
            

            first->prev = NULL;
            temp->next = NULL;
            temp->prev = first;
            first->next = temp;

            C = temp;
            C->next = NULL;
            last = temp;

            temp->objPush(new_date);

        }else

        if (first != last && C != last) {

            temp->prev = C;
            temp->next = C->next;
            C->next->prev = temp;
            C->next = temp;

            C = temp;

            temp->objPush(new_date);

        }else

        if (C == last && first != last) {

            temp->prev = C;
            temp->next = NULL;
            C->next = temp;

            last = temp;
            C = temp;

            temp->objPush(new_date);

        }


    }

}

void List::nodeCreate(int* arr) {
    if (msec == true) {
        datetime* new_date = new datetimeMsec;
        new_date->addData(arr);
        addNode(new_date);
        delete arr;
    }
    else {
        datetime* new_date = new datetime;
        new_date->addData(arr);
        addNode(new_date);
        delete arr;
    }
}

void List::clearC() {
    C->deleteData();
    delete C;
};

void List::deleteCurrent() {
    if (C == first && C == last) {
        clearC();
        first = NULL;
        last = NULL;
        C = NULL;
    }else
    
    
    if (C != first && C != last) {
        C->prev->next = C->next;
        C->next->prev = C->prev;

        Node* temp = C->prev;

        clearC();

        C = temp;
    }else

    if (C == first && first != last) {
        first = first->next;
        first->prev = NULL;

        clearC();

        C = first;
    }else

    if (C == last && first != last) {
        last = last->prev;
        last->next = NULL;

        clearC();

        C = last;
    }
}

void List::deleteAll() {

    C = first;
    while (first != NULL) {
        deleteCurrent();
    }

}

void List::moveNext() {

    C = C->next;

};

void List::movePrev() {
    C = C->prev;
};

void List::listPrint() {

    if (first != NULL) {

        Node* temp = C;
        C = first;
        while (C != NULL) {

            C->PrintNode(); cout << endl;

            moveNext();
        }
        C = temp;
    }
    else {
        cout << "\nVoid!\n";
    }
}

void List::listPrintSort() {

    if (first != NULL) {

        Node* temp = C;
        C = first;
        while (C != NULL) {
            if (C->next != NULL) {
                cout << "Date: ";  C->PrintNode(); cout << " Next date: "; C->next->PrintNode();; cout << endl;
            }
            if (C->next == NULL) {
                cout << "Date: ";  C->PrintNode(); cout << " Next date: not found :(" << endl;
                break;
            }
            moveNext();
        }

        C = temp;

    }
    else {
        cout << "\nVoid!\n";
    }
}

void Node::PrintNode() {
    data->showInfo();
}

void Node::objPush(datetime*& new_data) {

    data = new_data;

}

void Node::deleteData() {
    delete data;
    data = NULL;
}