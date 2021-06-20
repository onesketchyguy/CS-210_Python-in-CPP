#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void callProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python function you wish to call
	and the string parameter you want to send.
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	None
*/
void callProcedure(const string proc, const string param)
{
	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference
	pFunc = PyDict_GetItemString(pDict, proc.c_str());
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", param.c_str());
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();
}

/*
Description:
	To call this function, pass the name of the Python function you wish to call
	and a set of string parameters you want to send.
Example:
	int x = callProcedure("findWordInFile","Input.txt", "word");
Output:
	Python will print on the screen:
		Found "word"!
Return:
	None
*/
void callProcedure(string proc, string param1, string param2)
{
	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference
	pFunc = PyDict_GetItemString(pDict, proc.c_str());
	if (PyCallable_Check(pFunc))
	{
		// Create a two parameter object
		pValue = PyTuple_New(2);

		// Set the two parameters
		PyTuple_SetItem(pValue, 0, Py_BuildValue("z", param1.c_str()));
		PyTuple_SetItem(pValue, 1, Py_BuildValue("z", param2.c_str()));
		PyErr_Print();

		// Send the two parameters
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}

	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference
	pFunc = PyDict_GetItemString(pDict, proc.c_str());
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", param.c_str());
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean
	delete[] procname;

	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python function you wish to call
	and a set of string parameters you want to send.
Example:
	int x = callIntFunc("countWord","Input.txt", "Word");
Output:
	None
Return:
	int number of times word found.
	ex. 3
*/
int callIntFunc(string proc, string param1, string param2)
{
	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference
	pFunc = PyDict_GetItemString(pDict, proc.c_str());
	if (PyCallable_Check(pFunc))
	{
		// Create a two parameter object
		pValue = PyTuple_New(2);

		// Set the two parameters
		PyTuple_SetItem(pValue, 0, Py_BuildValue("z", param1.c_str()));
		PyTuple_SetItem(pValue, 1, Py_BuildValue("z", param2.c_str()));
		PyErr_Print();

		// Send the two parameters
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}

	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
bool callBoolFunc(string proc, string param)
{
	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference
	pFunc = PyDict_GetItemString(pDict, proc.c_str());
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	return _PyLong_AsInt(presult) == 1;
}

/*
Description:
	This function returns a valid integer recieved from the user.
Example:
	int input = getIntFromUser();

	Copyright Forrest Hunter Lowe 6/1/2021 CS-210-T5407 Programming Languages 21EW5
*/
int getIntFromUser()
{
	int value;
	cin >> value;

	// If we failed to parse the input we need to do some cleanup before trying again
	while (cin.fail())
	{
		// Clear the input buffer
		cin.clear();
		string empty;
		getline(cin, empty);

		// Output an error, and try to recieve new input
		cout << "You have entered invalid input. Please use only numerical and non-decimal values." << endl;
		cin >> value;
	}

	return value;
}

/*
Description:
	Converts an input string to it's uppercase varient.
Example:
	val = "bob";
	swapToUpper(val);
	cout << val;

	Outputs:
		BOB
*/
void swapToUpper(string& str)
{
	string strCopy = str;
	str = "";

	for (int i = 0; i < strCopy.length(); i++)
	{
		char c = toupper(strCopy.at(i));
		str.push_back(c);
	}
}

void printFileItemTable(string fileName)
{
	// Symbol to use for the table
	const char TABLE_ICON = '@';
	// Digit to use to have a minimum line length before inserting table data
	const int LINE_LENGTH = 20;

	// Read the file

	// Current line we're reading
	string line;
	// Open the file
	ifstream file(fileName.c_str());
	if (file.is_open())
	{
		// Format the contents of the file and output them onto the screen
		while (getline(file, line))
		{
			// Parse through the input line and find our data
			bool readingName = true;
			string itemName = "";
			string itemCountStr = "";
			int itemCount = 0;

			for (int i = 0; i < line.length(); i++)
			{
				// If this current character is a space then we don't need to parse it
				if (line.at(i) != ' ')
				{
					// If the current character is a digit then we have stopped reading the item
					if (isdigit(line.at(i)))
					{
						readingName = false;
					}

					// Fill the respective string with it's data
					if (readingName)
					{
						itemName.push_back(line.at(i));
					}
					else
					{
						itemCountStr.push_back(line.at(i));
					}
				}
			}

			// Converts the item count string to an int
			itemCount = stoi(itemCountStr);

			// Format the text on screen as a histogram
			string itemData = itemName + "<" + to_string(itemCount) + "> ";

			cout << itemData;

			// Try to fill the line with space to make sure all items are equally spaced for better readability
			int lineDifference = LINE_LENGTH - itemData.length();
			if (lineDifference > 0)
			{
				for (size_t i = 0; i < lineDifference; i++)
				{
					cout << " ";
				}
			}

			// Adds histogram items
			for (int i = 0; i < itemCount; i++)
			{
				cout << TABLE_ICON;
			}

			// End the line in preperation for the next item
			cout << endl;
		}

		// Close up the file stream
		file.close();
	}
	else
	{
		// Log error if file did not open for some reason
		cout << "ERROR! Unable to open \'" << fileName << "\'!" << endl;
	}
}

int main()
{
	const string OUTPUT_FILE = "frequency.dat";
	bool applicationRunning = true;

	string fileInput;
	int inputInt;

	// Allow the user to input a file which may be assigned to a particular day
	while (fileInput.empty() && applicationRunning)
	{
		// Show a menu of options
		cout << "Select an option:" << endl;
		cout << "1. Use default file (\"Input.txt\")" << endl;
		cout << "2. Use user file" << endl;
		cout << "3. Exit application" << endl;

		inputInt = getIntFromUser();

		// Handle input
		switch (inputInt)
		{
		case 1: // Use default file
			system("cls");
			fileInput = "Input.txt";
			break;
		case 2: // Use user file
			system("cls");
			cout << "User file (case sensitive): ";
			cin >> fileInput;
			break;
		case 3: // Exit application
			applicationRunning = false;
			break;
		default:
			cout << "ERROR! Unable to parse input. Please make sure your value is between 1-3." << endl;
			break;
		}

		if (fileInput.empty() == false)
		{
			// Validate that the file exists before attempting to send it to Python
			if (callBoolFunc("getFileExists", fileInput) == false)
			{
				cout << "ERROR! File not found." << endl;
				fileInput.clear();
			}
			else
			{
				cout << "File successfully found." << endl;
			}
		}

		// If the app isn't running we can go ahead and break from this loop here
		if (applicationRunning == false) break;

		// Wait for the user to press a key before clearing the screen and looping again
		system("pause");
		system("cls");
	}

	while (applicationRunning)
	{
		// Display an options menu
		cout << "Select a file option:" << endl;
		cout << "1. Show item counts" << endl;
		cout << "2. Show specific item count" << endl;
		cout << "3. Show item histogram" << endl;
		cout << "4. Exit application" << endl;

		// Get input
		inputInt = getIntFromUser();
		string inputString;

		int count;

		// Handle input
		switch (inputInt)
		{
		case 1: // Show all items
			system("cls");

			callProcedure("countWords", fileInput);
			break;
		case 2: // Show a particular item
			system("cls");

			// Get the item to find from the user
			cout << "What item would you like to find? ";
			cin >> inputString;

			// Convert the input to it's upper variant for clarity while searching
			swapToUpper(inputString);

			// Find the count of the input within the file
			count = callIntFunc("countWord", fileInput, inputString);

			// Print out the result
			if (count > 0)
			{
				cout << inputString << ": " << count << endl;
			}
			else
			{
				cout << "No " << inputString << " were purchased, or the item was not found." << endl;
			}

			break;
		case 3: // Show all items as a histogram
			system("cls");

			// Get the word list from the file and ouput it's counts to a separate file
			callProcedure("createWordListFile", fileInput, OUTPUT_FILE);

			// Use that new file and print out our table
			printFileItemTable(OUTPUT_FILE);

			break;
		case 4: // Exit application
			applicationRunning = false;
			break;
		default:
			cout << "ERROR! Unable to parse input. Please make sure your value is between 1-4." << endl;
			break;
		}

		// If the app isn't running we can go ahead and break from this loop here
		if (applicationRunning == false) break;

		// Wait for the user to press a key before clearing the screen and looping again
		system("pause");
		system("cls");
	}

	return 0;
}