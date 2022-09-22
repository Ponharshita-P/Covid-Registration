#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

static int count = 0;

class vaccine
{
public:
	struct vaccination
	{
		string centre;
		int number;
	} cv[12], cs[12];
};

class covaxin : public vaccine
{
public:
	covaxin()
	{
		cv[0].centre = "Corporation Middle School, Vilangudi";
		cv[0].number = 500;
		cv[1].centre = "Corporation Primary School, Fathima Nagar";
		cv[1].number = 255;
		cv[2].centre = "Ilango School";
		cv[2].number = 1000;
		cv[3].centre = "Corporation Middle School, Uthangudi";
		cv[3].number = 800;
		cv[4].centre = "Munichalai UPHC";
		cv[4].number = 150;
		cv[5].centre = "Manimegalai School, Kamarajar Road";
		cv[5].number = 320;
		cv[6].centre = "Thedeer Nagar UPHC";
		cv[6].number = 650;
		cv[7].centre = "Corporation Middl";
		cv[7].number = 450;
		cv[8].centre = "Corporation Middle School, Naganakulam";
		cv[8].number = 850;
		cv[9].centre = "K Pudur UPHC";
		cv[9].number = 420;
		cv[10].centre = "Corporation Middle School, Avaniyapuram";
		cv[10].number = 600;
		cv[11].centre = "Corporation Primary School, Thirunagar";
		cv[11].number = 700;
	}

	friend void display1(covaxin v1);

	void vacinated(int t)
	{
		cv[t - 1].number -= 1;
	}
};

void display1(covaxin v1)
{
	for (int i = 0; i < 12; i++)
	{
		cout << i + 1 << ".  " << v1.cv[i].centre << "      - " << v1.cv[i].number << endl;
	}
}

class covishield : public vaccine
{
public:
	covishield()
	{
		cs[0].centre = "Manimegalai School, Kamarajar Road ";
		cs[0].number = 1500;
		cs[1].centre = "Corporation Primary School, Thirunagar ";
		cs[1].number = 2650;
		cs[2].centre = "Corporation Middle School, Korodiya ";
		cs[2].number = 3500;
		cs[3].centre = "Ansari Nagar UPHC";
		cs[3].number = 2350;
		cs[4].centre = "Corporation Middle School, Avaniyapuram";
		cs[4].number = 1800;
		cs[5].centre = "Corporation Primary School, Subramaniapuram ";
		cs[5].number = 3850;
		cs[6].centre = "K Pudur UPHC ";
		cs[6].number = 800;
		cs[7].centre = "Munichalai UPHC ";
		cs[7].number = 2800;
		cs[8].centre = "Corporation Middle School, Naganakulam ";
		cs[8].number = 2650;
		cs[9].centre = "Primary Health Centre, Sellur";
		cs[9].number = 950;
		cs[10].centre = "Corporation Middle School, Keeraithurai ";
		cs[10].number = 3500;
		cs[11].centre = "Corporation Primary School, Muthupatti";
		cs[11].number = 1700;
	}

	friend void display2(covishield v2);

	void vacinated(int t)
	{
		cs[t - 1].number -= 1;
	}
};

void display2(covishield v2)
{
	for (int i = 0; i < 12; i++)
	{
		cout << i + 1 << ".  " << v2.cs[i].centre << " - " << v2.cs[i].number << endl;
	}
}

class people
{
public:
	struct details
	{
		string name;
		int age;
		long long int phoneNumber;
		bool dose1;
		bool dose2;
		string password;
	} d[1000];

	void signUp()
	{
		cout << "Name: ";
		cin >> d[count].name;
		cout << "Phone Number: ";
		cin >> d[count].phoneNumber;
		cout << "Password: ";
		cin >> d[count].password;
		count++;
	}

	int login(string name, string password)
	{
		for (int i = 0; i < count; i++)
		{
			if (!(this->d[i].name.compare(name)) && !(this->d[i].password.compare(password)))
			{
				return i;
			}
		}
		return -1;
	}

	void firstDose(int t)
	{
		d[t].dose1 = true;
	}

	void secondDose(int t)
	{
		d[t].dose2 = true;
	}
};
class information
{
public:
	long long int aadhar;
	int yr_br, res_c, wrd_no, sub;
	char gne;
	string comor;
	void info()
	{
		cout << "\nAadhar number : ";
		cin >> aadhar;
		cout << "\nGender (M/F): ";
		cin >> gne;
		cout << "\nYear of birth : ";
		cin >> yr_br;
		cout << "\nAny existing Comorbidities : ";
		cin >> comor;
		cout << "\n1. Madurai Corporation\n2. Others";
		cout << "\nResidential Area : ";
		cin >> res_c;
		cout << "\nWard number (1 - 100): ";
		cin >> wrd_no;
	}
};

int main()
{
	cout << "************************************\n\n";
	cout << "                                      VACCINE RESERVATION                                                 \n\n";
	cout << "************************************\n\n";
	int ch1, ch2, ch3, n1, n2;
	int sub1, sub2;
	string name, password, last;
	people p;
	covaxin v1;
	covishield v2;
	information obj;
	do
	{
		cout << "\n\t\t\t1. Register\n\t\t\t";
		cout << "2. Login\n\t\t\t";
		cout << "3. Covaxin Slot Availability\n\t\t\t";
		cout << "4. Covishield Slot Availability\n\t\t\t";
		cout << "5. Exit";
		cout << "\n\t\t\tEnter your choice (1 - 5) :  ";
		cin >> ch1;
		cout << endl;
		switch (ch1)
		{
		case 1:
		{
			cout << "**  REGISTER  **" << endl;
			p.signUp();
			break;
		}
		case 2:
		{
			cout << "**  LOGIN  **" << endl;
			cout << "Name: ";
			cin >> name;
			cout << "Password: ";
			cin >> password;
			n1 = p.login(name, password);
			if (n1 == -1)
			{
				cout << "Sorry...You have not registed still...!!\n";
				break;
			}
			cout << "\n1. First Dose\n2. Second Dose ";
			cout << "\nDosage of Vaccination : ";
			cin >> ch2;
			if (ch2 == 1)
			{
				p.firstDose(n1);
			}
			else if (ch2 == 2)
			{
				p.secondDose(n1);
			}
			cout << "\n1. Covaxin\n2. Covishield: ";
			cout << "\nVaccine Type : ";
			cin >> ch3;
			if (ch3 == 1)
			{
				cout << "\n";
				display1(v1);
				cout << "Select center number: ";
				cin >> n2;
				v1.vacinated(n2);
				obj.info();
				cout << "Confirm Submission  1. Yes  2. No : ";
				cin >> sub1;
				if (sub1 == 1)
				{
					cout << "\nDear " << name << ", you have successfully registered for the Covaxin Vaccination.\n";
					cout << "Your slot for vaccinating will be alloted shortly. Thankyou for Registering!!!\n";
					cout << "Helpline : 10789";
				}
				else if (sub1 == 2)
				{
					cout << "If you want to make changes. Please exit and Re-login into it.\n";
				}
			}
			else if (ch3 == 2)
			{
				cout << "\n";
				display2(v2);
				cout << "Select center number: ";
				cin >> n2;
				v2.vacinated(n2);
				obj.info();
				cout << "\nConfirm Submission  1. Yes  2. No : ";
				cin >> sub2;
				if (sub2 == 1)
				{
					cout << "Dear " << name << ", you have successfully registered for the Coishield Vaccination.\n";
					cout << "Your slot for vaccinating will be alloted shortly. Thankyou for Registering!!!\n";
					cout << "Helpline : 10789";
				}
				else if (sub2 == 2)
				{
					cout << "If you want to make changes. Please exit and Re-login into it.\n";
				}
			}
			cout << "\n\n\t\t\t##  GUIDELINE  ##\n";
			cout << "Dear user, Please kindly do follow the below guideline while getting vaccination \n";
			cout << "1. Arrive at the Vaccination Center at the correct time.\n";
			cout << "2. Please carry the Aadhar photo id proof with you.\n It will be verified at the time of vaccination appoinment.\n";
			cout << "3. Please be patient at the Vaccination center.\n";
			cout << "4. Don't forget to get back your photo id proof.\n";
			cout << "5. Don't rub your hands as soon as vaccine is injected.\n";
			cout << "\n\t\t\t  HAPPY VACCINATION :)            \n";
			break;
		}
		case 3:
		{
			cout << "**  COVAXIN SLOT AVAILABILITY  **" << endl;
			display1(v1);
			break;
		}
		case 4:
		{
			cout << "**  COVISHIELD SLOT AVAILABILITY  **" << endl;
			display2(v2);
			break;
		}
		case 5:
		{
			cout << "**  EXIT  **" << endl;
			exit(0);
		}
		}
	} while (ch1 != 5);
	return 0;
}