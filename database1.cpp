#include <iostream>		//output text and input texts;
#include <string>		//string functions and string variables
#include <fstream>		//files (structural support)

using namespace std;

void input ();
void searchname ();
void searchage ();
void searchsalary ();
void quit ();
void displayall ();
void search ();

int main()
{
	system ("title ItalyHorse45 Database Program");		//aesthetics
	system ("cls"); 	//aesthetics; clear screen of prior text
	system ("color 0F");	 //aesthetics; 0 - background color; F - text color
		int choice;
		cout << "1.Input a new name" << endl;
		cout << "2.Search a data base for employee" << endl;
		cout << "3.Exit Program" << endl;
		cin >> choice; 	//input a choice
		
			switch (choice){
				case 1:
					input();
					break;
				case 2:
					search();
					break;
				case 3:
					quit();
					break;
					
				cin.get();
			}
}

void input()
{
	string name;
	int age;
	long int salary;
	ofstream newemployee("newemployee.txt", ios::app);	//output file streaming; doesnt delete past information
	cout << "Enter the new employee's name" << endl;
	cin >> name;
	
	cout << "Enter the employee's age." << endl;
	cin >> age;
	
	cout << "Enter the employee's yearly salary" << endl;
	cin >> salary;
	
	newemployee << name << ' ' << age << ' ' << salary << endl;	
	newemployee.close();
	main();		//go back to main
}

void search()
{
	int choice2;
	system ("CLS");
	
	cout << "1.Search by name" << endl;
	cout << "2.Search by agee" << endl;
	cout << "3.Search by salary" << endl;
	cout << "4.Display all employees" << endl;
	cout << "5.Exit program" << endl;
	cin >> choice2;

			switch (choice2){
				case 1:
					searchname();
					break;
				case 2:
					searchage();
					break;
				case 3:
					searchsalary();
					break;	
				case 4:
					displayall();
					break;
				case 5:
					quit();
					break;	
			}
	
	
}

	void searchname()
	{
		ifstream employee("newemployee.txt");  //opposite from ofstream; takes from the file
		string name;
		string str;
		
		int age;
		long int salary;
		system("CLS");
		cout << "Enter the employee's name:";
		cin >> str;
		
		while(employee >> name >> age >> salary){
			
			if (str == name){
				
				system ("CLS");
				cout << "Employee(s) found" << endl;
				cout << "Name" << ' ' << "Age" << ' ' << "Salary" << endl;
				cout << "_ _ _ _ _ _ _ _ _ _ _" << endl;
				cout << name << ' ' << age << ' ' << "$" << salary <<endl;
				
			}
			if(!(str == name)){
				system ("cls");
				cout << "No employee(s) found" << endl;
				
			}
		}
		system ("pause");
		cin.get();
		main();
		
	}
	
	void searchage()
	{
		ifstream employee("newemployee.txt");
		string name;
		int age;
		int fage;
		long int salary;
		system ("CLS");
		cout << "Enter the age of an employee:";
		cin >> fage;
		
			while(employee >> name >> age >> salary){
			
			if (fage == age){
				
				system ("CLS");
				cout << "Employee(s) found" << endl;
				cout << "Name" << ' ' << "Age" << ' ' << "Salary" << endl;
				cout << "_ _ _ _ _ _ _ _ _ _ _" << endl;
				cout << name << ' ' << age << ' ' << "$" << salary <<endl;
				
			}
			if(fage != age){
				system ("cls");
				cout << "No employee(s) found" << endl;
				
			}
		
		}
		
		system ("pause");
		cin.get();
		main();
	}
	
	
	void searchsalary()
	{
		ifstream employee ("newemployee.txt");
		string name;
		int age;
		long int salary;
		long int fsalary;
		system ("CLS");
		cout << "Enter an employee's salary:";
		cin >> fsalary;
		
			while(employee >> name >> age >> salary){
			
			if (fsalary == salary){
				
				system ("CLS");
				cout << "Employee(s) found" << endl;
				cout << "Name" << ' ' << "Age" << ' ' << "Salary" << endl;
				cout << "_ _ _ _ _ _ _ _ _ _ _" << endl;
				cout << name << ' ' << age << ' ' << "$" << salary <<endl;
				
			}
			if(fsalary != salary){
				system ("cls");
				cout << "No employee(s) found" << endl;
				
			}
		
		}
		
		system ("pause");
		cin.get();
		main();
	}
	
void quit()
{
	system ("CLS");
	cout << "Thank you for using the italyhorse45 database program" << endl;
	system ("pause");
	cin.get();
}

void displayall ()
{
	ifstream employee("newemployee.txt");
	int age;
	long int salary;
	string name;
	system ("CLS");
	cout << "Entire employee database" << endl;
	cout << "Name" << ' ' << "Age" << ' ' << "Salary" << endl;
	cout << "_ _ _ _ _ _ _ _ _ _ _" << endl;
	while(employee >> name >> age >> salary){
	cout << name << ' ' << age << ' ' << "$" << salary <<endl;
	}
	system ("pause");
	cin.get();
	main();
}

