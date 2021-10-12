#include "App.h"

int* App::userInput(int k) {
	int* arr = new int[k];
	cout << "Insert Hour->"; arr[0] = checkData(0,23);
	cout << "Insert Minute->"; arr[1] = checkData(0, 59);
	cout << "Insert Second->"; arr[2] = checkData(0, 59);
	if (k == 7) { cout << "Insert Milisecond->"; arr[6] = checkData(0, 999); }
	cout << "Insert Day->"; arr[3] = checkData(1, 31);
	cout << "Insert Month->"; arr[4] = checkData(1, 12);
	cout << "Insert Year->"; cin >> arr[5];
	return arr;
}

void App::userFile(int key) {
	fileWork* file;

	cout << "How many dates you want to write? Insert ->"; int count; cin >> count;
	int** file_output = new int* [count];

	if (key == 1) {
		file = new fileWorkMsec;

		for (int i = 0; i < count; i++) {
			cout << "----------------------------------\n";
			file_output[i] = userInput(7);
		}
		cout << "----------------------------------\n";
	}
	else {
		file = new fileWork;
		
		for (int i = 0; i < count; i++) {
			cout << "----------------------------------\n";
			file_output[i] = userInput(6);
		}
		cout << "----------------------------------\n";

	}
	cout << "Insert name of new file ->"; char* new_filename = new char[20]; cin >> new_filename;
	file->fileCreate(const_cast<char*>(new_filename),file_output, count);

	delete file;

	for (int i = 0; i < count; i++) {
		delete [] file_output[i];
	}

	delete [] file_output;
}

void App::start(){

	

	cout << "Atention! Would you like to work with Miliseconds? \n\nInsert 1 if yes or 0 if not!->"; int key_msec; cin >> key_msec; cout << endl;

	bool key_msec_bool = false;

	if (key_msec == 1) {

		key_msec_bool = true;
		cout << "\n!!!Miliseconds activated! \n\n";
	}
	
	List list(key_msec_bool);

	int key = -1;
	do {
		
		cout << "----MENU----" << endl;
		cout << "1) Show All Date's" << endl;
		cout << "2) Show in format \"Date - Next Date\"" << endl;
		cout << "3) Show system date and time" << endl;
		cout << "4) Info about file format!" << endl;
		cout << "5) Add date" << endl;
		cout << "6) Make file" << endl;
		cout << "7) Read file" << endl;
		cout << "0) Exit" << endl << endl;

		cout << "Insert key->"; cin >> key;
		system("cls");
		switch (key)
		{
		case 1: {
			cout << endl;
			list.listPrint();
			cout << endl;
			break;
		}
		
		case 2: {
			cout << endl;
			list.listPrintSort();
			cout << endl;
			break;
		}

		case 3: {
			cout << endl;
			datetime sysTime;
			sysTime.showSysDate();
			cout << endl;
			break;
		}

		case 4: {
			if (key_msec == 1) {
				cout << "\nFile format for activated miliseconds:\n \"Hours Minutes Seconds Miliseconds Day Month Year\"\n" << endl;
			}
			else {
				cout << "\nFile format: \"Hours Minutes Seconds Day Month Year\"\n" << endl;
			}
			break;
		}

		case 5: {
			if (key_msec == 1) list.nodeCreate(userInput(7));
			else list.nodeCreate(userInput(6));
			break;
		}

		case 6: {
			userFile(key_msec);
			break;
		}

		case 7: {
			cout << "Insert name of file you want to read ->"; char* new_filename = new char[20]; cin >> new_filename;
			list.getListFromFile(const_cast<char*>(new_filename));
			break;
		}

		default:

			if (key != 0) cout << "Error! Not found in menu! Try again!" << endl;

			break;
		}

	} while (key != 0);
}
