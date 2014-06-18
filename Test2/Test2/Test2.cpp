//I affirm that all code given below was written solely by me, Jason Trader, and that any help I 
//received adhered to the rules stated for this exam. #include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int verifyRecords(fstream& color, char a[100], char b[100], int t, int minPace, int maxPace){
	int errors=0;
	// will return extra repeated t value but the repeated value should still be in range
	while (!color.eof()){
		color.getline(a, 100,' ');
		color.getline(b, 100,' ');
		color >> t;
		//takes care of \n character
		color.get();
		if (!(t>=minPace&& t<=maxPace)){
			cout <<"sorting error." << endl;
			errors++;
		}
		return errors;
	}
}
class Runner{
private:
	string firstName;
	string lastName;
	int pace;
public:
	Runner (){
		firstName="Jason";
		lastName="Trader";
		pace=7;
	}
	Runner (string a, string b, int c){
		firstName=a;
		lastName=b;
		pace=c;
	}
	string getFirstName(){
		return firstName;
	}
	string getLastName(){
		return lastName;
	}
	int getPace(){
		return pace;
	}
};

int main(){
	vector<Runner> runnerVector;
	ifstream input;
	//inputs shouldn't be larger than 100 chars
	char FirstName[100];
	char LastName[100];
	int Pace;
	//file name is put into a variable so that it can be reused if needed
	string inputFileName="c:\\users\\Jason\\desktop\\Registrants.txt";
	input.open(inputFileName);
	//will return one garbage value but it is taken care of later
	while (!input.eof()){
		input.getline(FirstName, 100,' ');
		input.getline(LastName, 100,' ');
		input >> Pace;
		Runner tempRunner(FirstName,LastName,Pace);
		runnerVector.push_back(tempRunner);
		//takes care of \n character
		input.get();
	}
	input.close();
	runnerVector.pop_back(); //takes care of last garbage values
	int x=runnerVector.size();
	for (int q=0; q<x; q++){
		for (int i=0; i<x-1; i++){
			Runner temp;
			int a=runnerVector[i].getPace(), b=runnerVector[i+1].getPace();
			if (a>b){
				temp=runnerVector[i];
				runnerVector[i]=runnerVector[i+1];
				runnerVector[i+1]=temp;
			}
		}
	}
	fstream red, lilac, blue, orange, green, yellow, white;
	red.open("c:\\users\\Jason\\desktop\\red.txt", ios::out);
	lilac.open("c:\\users\\Jason\\desktop\\lilac.txt", ios::out);
	blue.open("c:\\users\\Jason\\desktop\\blue.txt", ios::out);
	orange.open("c:\\users\\Jason\\desktop\\orange.txt", ios::out);
	green.open("c:\\users\\Jason\\desktop\\green.txt", ios::out);
	yellow.open("c:\\users\\Jason\\desktop\\yellow.txt", ios::out);
	white.open("c:\\users\\Jason\\desktop\\white.txt", ios::out);

	for (int i=0; i<x; i++){
		if (runnerVector[i].getPace()<1201 && runnerVector[i].getPace()>720){
			red << runnerVector[i].getFirstName() << " " << runnerVector[i].getLastName() << " " << runnerVector[i].getPace() << endl;
		}
		else if (runnerVector[i].getPace()>600){
			lilac << runnerVector[i].getFirstName() << " " << runnerVector[i].getLastName() << " " << runnerVector[i].getPace() << endl;
		}
		else if (runnerVector[i].getPace()>540){
			blue << runnerVector[i].getFirstName() << " " << runnerVector[i].getLastName() << " " << runnerVector[i].getPace() << endl;
		}
		else if (runnerVector[i].getPace()>480){
			orange << runnerVector[i].getFirstName() << " " << runnerVector[i].getLastName() << " " << runnerVector[i].getPace() << endl;
		}
		else if (runnerVector[i].getPace()>420){
			green << runnerVector[i].getFirstName() << " " << runnerVector[i].getLastName() << " " << runnerVector[i].getPace() << endl;
		}
		else if (runnerVector[i].getPace()>360){
			yellow << runnerVector[i].getFirstName() << " " << runnerVector[i].getLastName() << " " << runnerVector[i].getPace() << endl;
		}
		else{
			white << runnerVector[i].getFirstName() << " " << runnerVector[i].getLastName() << " " << runnerVector[i].getPace() << endl;
		}
	}
	red.close();
	lilac.close();
	blue.close();
	orange.close();
	green.close();
	yellow.close();
	white.close();
	//errors used in many places from here down in .cpp file
	int errors=0;
	//could have made these into one function but I did not see the functionality of a function here as it would be very
	//long to pass the .txt address and I felt it would be nice to tell the user which file did not load properly and if I was using the fstream variable as an argument
	//I couldn't convert the name to text inside error message uniquely.
	red.open("c:\\users\\Jason\\desktop\\red.txt", ios::in);
	if (red.fail()){
		cout << "Red file did not load properly" << endl;
		errors++;
	}
	lilac.open("c:\\users\\Jason\\desktop\\lilac.txt", ios::in);
	if (lilac.fail()){
		cout << "Lilac file did not load properly" << endl;
		errors++;
	}
	blue.open("c:\\users\\Jason\\desktop\\blue.txt", ios::in);
	if (blue.fail()){
		cout << "Blue file did not load properly" << endl;
		errors++;
	}
	orange.open("c:\\users\\Jason\\desktop\\orange.txt", ios::in);
	if (orange.fail()){
		cout << "Orange file did not load properly" << endl;
		errors++;
	}
	green.open("c:\\users\\Jason\\desktop\\green.txt", ios::in);
	if (green.fail()){
		cout << "Green file did not load properly" << endl;
		errors++;
	}
	yellow.open("c:\\users\\Jason\\desktop\\yellow.txt", ios::in);
	if (yellow.fail()){
		cout << "Yellow file did not load properly" << endl;
		errors++;
	}
	white.open("c:\\users\\Jason\\desktop\\white.txt", ios::in);
	if (white.fail()){
		cout << "White file did not load properly" << endl;
		errors++;
	}
	char a[100], b[100];
	int t=0;
	errors+=verifyRecords(red,a,b,t,721,1200);
	errors+=verifyRecords(lilac,a,b,t,601,720);
	errors+=verifyRecords(blue,a,b,t,541,600);
	errors+=verifyRecords(orange,a,b,t,481, 540);
	errors+=verifyRecords(green,a,b,t,421, 480);
	errors+=verifyRecords(yellow,a,b,t,361, 420);
	errors+=verifyRecords(white,a,b,t,0, 360);
	red.close();
	lilac.close();
	blue.close();
	orange.close();
	green.close();
	yellow.close();
	white.close();
	if (errors==0){
		cout << "Zero Errors! Rock on!" << endl;
	}
	else{
		cout << "You have " << errors << " errors :(" << endl;
	}
	return 0;
}