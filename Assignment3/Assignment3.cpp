// Assignment3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>


using namespace std;


int n = 0;
int length = 0;

int* numberList ;

bool checkInt(float x)
{

	while (cin.fail() || cin.peek() != '\n')
	{
		cin.clear();


		cin.ignore(512, '\n');
		return true;

	}
	return false;

}



int* fillTheArray(int* arr ) {
	
	for (int i = 0; i < length; i++) {
		*(arr+i) = *(numberList+i);
		
	}
	return arr;
}


void printNumbers() {


	

	if (n == 0) cout << "[] - the list is empty!" << endl;
	else {
		
		cout << endl << "[ ";
		for (int i = 0; i < length; i++) {
			cout << *(numberList+i)<< " ";
		}


		cout << " ]" << endl;

	}



}




void addNumbers(int value) {
	
	if (length == n) {
		
		
		int* arr = new int[n+5];
		
		numberList = fillTheArray(arr);
		*(numberList+n) = value;
		n += 5;
		length++;
		

	}
	else {
		
		*(numberList+length) = value;
		length++;
	}
	
	
}

void meanValueFinder() {
	int sum = 0;
	double mean = 0.0;
	
	for (int i = 0; i < length; i++) {
		sum += numberList[i];

	}
	mean = 1.0 * sum / length;
	cout << endl << "*******************************************" << endl;
	cout << "**  mean of the array is : " << mean << endl;
	cout << "*******************************************" << endl;
	

}

void smallestValueFinder() {
	int min = numberList[0];
	for (int i = 1; i < length; i++) {
		if (min > numberList[i])
			min = numberList[i];
	}
	cout << "The smallest number is " << min << endl;
}

void largestValueFinder() {
	int max = numberList[0];
	for (int i = 1; i < length; i++) {
		if (max < numberList[i])
			max = numberList[i];
	}
	cout << "The largest number is " << max << endl;

}
int main()
{
	
	string ans = "";
	bool checker = false;
	

	do {
		checker = false;
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
		cout << "P - Print numbers" << endl;
		cout << "A - Add a number" << endl;
		cout << "M - Display mean of the numbers" << endl;
		cout << "S - Display the smallest number" << endl;
		cout << "L - Display the largest number" << endl;
		cout << "Q - Quit" << endl;
		cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
		try {

			cout << "Enter your choice : ";
			cin >> ans;
		
			ans.erase(ans.find_last_not_of(' ')+1 );
			
			for (int i = 0; i < ans.length(); i++) {

				ans[i] = tolower(ans[i]);
			}
		

			
			if (ans.length() > 1) {
			
				throw 10;
			}
			else if (!(ans == "a" || ans == "p" || ans == "m" || ans == "s" || ans == "l" || ans == "q")) {
			
				throw 10;
			}
			switch (ans[0]) {

				case 'p':
					system("cls");
					printNumbers();
					checker = true;
					cout << endl << endl << endl;
					break;
				case 'a':
				{
					system("cls");
					checker = true;
					int value = 0;
			
					bool checkerNumber = false;
					do
					{
						try
						{

							checkerNumber = false;

							cout << "Enter the value : ";
							cin >> value;
							
							if (checkInt(value)) throw 10;

						}


						catch (...)
						{
							system("cls");
							checkerNumber = true;
							cout << "Please Enter number!" << endl;
						}
					} while (checkerNumber);

			
					addNumbers(value);
					cout << value << " added!" << endl;
					cout << endl << endl << endl;
					break;
				}
				case 'm':
					checker = true;
					system("cls");
					if (length > 0)
						meanValueFinder();
					else
						cout << "Unable to calculate the mean - no data!" << endl;
					cout << endl << endl << endl;
					break;
				case 's' :
					checker = true;
					system("cls");
					if (length > 0)
						smallestValueFinder();
					else
						cout << "Unable to determine the smallest number - list is empty" << endl;
					cout << endl << endl << endl;
					break;

				case 'l':
					checker = true;
					system("cls");
					if (length > 0)
						largestValueFinder();
					else
						cout << "Unable to determine the largest number - list is empty" << endl;
					cout << endl << endl << endl;
					break;
				case 'q':
					cout << endl <<"GoodBye!" << endl;
					break;

				}
			
		}
		catch (int x) {
			system("cls");
			checker = true;
			cout << "Unknown selection, please try again!" << endl;
		}
		

	} while (checker );
	
	

	


}

