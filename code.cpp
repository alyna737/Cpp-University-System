#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <thread>
#include <chrono>
#include <vector>
#include<cctype>
using namespace std;

struct coursee {
    string name;
    double credits;
    int marks;
};

struct Program {
    string name;
    vector<coursee> coursees;
};

struct Department {
    string name;
    vector<Program> programs;
};

struct Student {
    string name;
    string registrationNumber;
    double gpa;
    string grade;
    vector<coursee> coursees;
};

void calculateGPA(vector<coursee>& coursees, double& gpa, string& grade);
void saveStudentInfo(ofstream& outFile, Student& student);
void displayDepartments(const vector<Department>& departments);
void displayPrograms(const vector<Program>& programs);
void displaycoursees(const vector<coursee>& coursees);

class Course {
public:
    Course(string name) : name(name) {}

    string getName() const {
        return name;
    }

private:
    string name;
};

void IT();
void MD();
void saveStudentInfo(const string& name, const string& app, const string& email, char gender, int department, const Course& selectedCourse);
void generateConfirmationLetter(const string& name, const string& app, const string& email, const Course& selectedCourse);
void generateRejectionLetter(const string& name, const string& app, const string& email);
void IT_cselect();
void MD_cselect();
void entryTestit(const string& name, const string& app, const string& email, char gender) ;
void entryTestmd(const string& name, const string& app, const string& email, char gender);
int getDepartmentChoice();

const int MAX_USERS = 100;

struct User {
    string username;
    string password;
};

User users[MAX_USERS];
int userCount = 0;


void fun1();
void fun2();
void subfun2(int seconds);

void loginn();

void loadUsers();
void saveUser(const User& user);
void registration();
void login();
void forgot();


int main()
{
	system ("color f0");
   fun1();
   fun2();
    loadUsers();

    string name;
    int chooce;

    cout << "ENTER YOUR NAME:" << endl;
    getline(cin, name);
    cout << "\n" << setw(10) << "  | NAME: " << name << " |" << endl;

    cout << "MAIN MENU: " << endl;
    cout << "\n\t" << "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcxcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd" << endl;
    cout << "\t" << "| [1]. Teacher/Management            |" << endl;
    cout << "\t" << "| [2]. Student                       |" << endl;
    cout << "\t" << "\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd" << endl;
    cin >> chooce;

    while (!(chooce == 1 || chooce == 2)) {
        cout << "INVALID ENTRY, PLEASE RE-ENTER" << endl;
        cin >> chooce;
    }

   switch (chooce) {
    case 1:
        cout << "TEACHER/MANAGEMENT" << endl;
        loginn();

        vector<Student> students;

       Department itDepartment;
    itDepartment.name = "IT & CS";

    Program aiProgram;
    aiProgram.name = "Artificial Intelligence";
    aiProgram.coursees = { 
        {"DSA", 3.0},
        {"AI", 3.0},
        {"TBW", 3.5},
		{"DLD",3.0}
    };

    Program cyberSecurityProgram;
    cyberSecurityProgram.name = "Cyber Security";
    cyberSecurityProgram.coursees = {
        {"DSA", 3.0},
        {"AI", 3.0},
        {"DLD",3.0},
        {"Linear Algebra", 3.5},
        {"Information Security", 3.5}
    };
     Program Software;
    Software.name = "Software Eng";
    Software.coursees = {
         {"DSA", 3.0},
        {"Software Engineering", 3.0},
        {"SE Supporting-I",3.0},
        {"Linear Algebra", 3.5},
        {"Professional Ethics", 3.5}
    };
       Program DS;
    DS.name = "Data Structures";
   DS.coursees = {
         {"DSA", 3.0},
        {"Applied Statistics", 3.0},
        {"SE Supporting-I",3.0},
        {"Linear Algebra", 3.5},
        {"Introduction to Data Science", 3.5}
    };
Program CS;
    DS.name = "Computer Science";
   DS.coursees = {
         {"DSA", 3.0},
        {"Applied Statistics", 3.0},
        {"Comp. Organization and Assembly Lang. ",3.0},
        {"Linear Algebra", 3.5},
        {"TBW", 3.5}
    };


    itDepartment.programs = {aiProgram, cyberSecurityProgram,Software,DS,CS};

    // Define the structure of the Medical department
    Department medicalDepartment;
    medicalDepartment.name = "Medical";

    Program pp;
    pp.name = "Physiotherapy";
    pp.coursees = {
        {"PATHOLOGY & MICROBIOLOGY I", 3.5},
        {"PHARMACOLOGY ", 4.0},
        {"HEALTH & WELLNESS", 3.0},
        {"SUPERVISED CLINICAL PRACTICE I", 3.0}
    };

    Program bmsProgram;
    bmsProgram.name = "Biomedical Science";
    bmsProgram.coursees = {
        {"General Pathology and Histopathology-I", 4.0},
        {"Human Physiology", 3.5},
        {"Biochemistry", 2.0},
        {"Medical Virology ", 3.0},
        {"Economics and Healthcare Management", 3.0}
        
    };
    Program btyProgram;
    btyProgram.name = "Biotechnology";
    btyProgram.coursees = {
        {"Classical Genetics", 3.5},
        {"Molecular Biology", 4.0},
        {"General Physiology", 3.0},
        {"General Microbiology", 3.0},
        {"Biosafety and Bioethics", 3.0}
    };
    Program mb;
    mb.name = "Microbiology";
    mb.coursees = {
        {"Biochemistry I", 3.5},
        {"Microbial Anatomy & Physiology", 4.0},
        {"Laboratory Animals & Model Organism", 3.0},
        {"Biosafety & Risk Management", 3.0},
        {"Microbial Taxonomy", 3.0},
        
    };

    medicalDepartment.programs = {btyProgram, bmsProgram,mb,pp};

    while (true) {
        cout << "1. Calculate GPA\n";

        int choice;
        choice=1;
        switch (choice) {
            case 1: {
                Student student;
                cout << "Enter student name: ";
                cin.ignore();  // Ignore newline character in buffer
                getline(cin, student.name);

                cout << "Enter registration number: ";
                getline(cin, student.registrationNumber);

                displayDepartments({itDepartment, medicalDepartment});
               
 cout << "Select your department:\n";
                int departmentChoice;
                cin >> departmentChoice;

                const Department& selectedDepartment = (departmentChoice == 1) ? itDepartment : medicalDepartment;
 system("cls");
                displayPrograms(selectedDepartment.programs);
                cout << "Select your program:\n";
                int programChoice;
                cin >> programChoice;

                const Program& selectedProgram = selectedDepartment.programs[programChoice - 1];

                // Loop over all coursees in the program
                for (const auto& coursee : selectedProgram.coursees) {
                    double marks;
                    double credits;  // Added variable for credit hours

                    cout << "Enter marks for " << coursee.name << ": ";
                    cin >> marks;
                    //****************************************************************************************
                    
                    while(marks<0 || marks>100)
	{
	 cout<<"Enter Valid Marks"<<endl;
	 cin>>marks;
	}
           cout << "Enter credit hours for " << coursee.name << ": ";
                    cin >> credits;

                    student.coursees.push_back({coursee.name, credits, marks});
                }


                calculateGPA(student.coursees, student.gpa, student.grade);
                students.push_back(student);

                // Save GPA and student information to a text file
                ofstream outFile("student_info.txt", ios::app);  // Append to the file
                saveStudentInfo(outFile, student);
                system("cls");
                cout << "\nStudent Information and GPA saved to student_info.txt\n";
                cout << "GPA for " << student.name << ": " << fixed << setprecision(2) << student.gpa << " | Grade: " << student.grade << endl;
            } break;

            case 2: {
                cout << "Student" << endl;
                cout << "1. New Student" << endl;
                cout << "2. Enrolled Student" << endl;
                int choose1;
                cin >> choose1;

                while (!(choose1 == 1 || choose1 == 2)) {
                    cout << "INVALID ENTRY, PLEASE RE-ENTER" << endl;
                    cin >> choose1;
                }

                switch (choose1) {
                    case 1: {
                        cout << "New Student" << endl;
                        cout << "1. Login\n2. Registration\n3. Forgot password\n4. Exit" << endl;
                        int choose3;
                        cin >> choose3;

                        switch (choose3) {
                            case 1: {
                                login();

                                int chuse = getDepartmentChoice();
                                string name, app, email;
                                char gender;

                                cout << "Enter your name: ";
            cin >> name;

            cout << "Enter your application ID: ";
            cin >> app;

            cout << "Enter your email: ";
            cin >> email;

            cout << "Enter your gender (M/F): ";
            cin >> gender;

            switch (chuse) {
                case 1:
                    // IT & CS department
                    entryTestit(name, app, email, gender);
                    break;
                case 2:
                    // Medical department
                    entryTestmd(name, app, email, gender);
                    break;
                default:
                    cout << "INVALID CHOICE" << endl;
            }
        
                            } break;

                            case 2:
                                registration();
                                break;
                            case 3:
                                forgot();
                                break;
                            case 4:
                                // exit
                                break;
                            default:
                                cout << "Invalid choice" << endl;
                        }
                    } break;

                    case 2: {
                        cout << " Enrolled Student" << endl;
                        cout << "1. Login\n2. Registration\n3. Forgot password\n4. Exit" << endl;
                        int choose4;
                        cin >> choose4;

                        switch (choose4) {
                            case 1: {
                                login();

                                string searchRegistrationNumber;
                                cout << "Enter registration number to search: ";
                                cin >> searchRegistrationNumber;

                                bool found = false;
                                for (const auto& student : students) {
                    if (student.registrationNumber == searchRegistrationNumber) {
                        cout << "GPA for " << student.name << " (Registration Number: " << student.registrationNumber << "): "
                             << fixed << setprecision(2) << student.gpa << " | Grade: " << student.grade << endl;
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "Student with registration number " << searchRegistrationNumber << " not found.\n";
                }
                    
                            } break;
                            case 2:
                                registration();
                                break;
                            case 3:
                                cout << "forgot" << endl;
                                forgot();
                                break;
                            case 4:
                                cout << "exit" << endl;
                                break;
                            default:
                                cout << "invalid" << endl;
                        }
                    } break;

                    default:
                        cout << "invalid" << endl;
                }
            } break;

            default:
                cout << "invalid" << endl;
        }
    }
}

}

void fun1()		//intro
{
    ifstream inputFile("ds1.txt"); 
    string line;
    while (getline(inputFile, line))
	{
        cout << line <<endl;
    }	
}

void fun2() 
{
    int countdownSeconds = 10;
    cout <<setw(64)<<"Loading..." << endl;
    subfun2(countdownSeconds);
    system("cls");
    cout<<setw(64)<< "WELCOME TO THE PORTAL OF PAFIAST!" << endl;
}
void subfun2(int seconds) 
{
    if (seconds <= 0) {
        return;
    }
    cout<<setw(55)<< seconds << " sec\r" << flush;
    this_thread::sleep_for(chrono::seconds(1));
    subfun2(seconds - 1);
}

void loadUsers() {
    ifstream file("records.txt");
    string username, password;

    while (file >> username >> password && userCount < MAX_USERS) {
        users[userCount] = {username, password};
        userCount++;
    }

    file.close();
}

void saveUser(const User& user) {
    if (userCount < MAX_USERS) {
        ofstream file("records.txt", ios::app);
        file << user.username << ' ' << user.password << endl;
        file.close();

        users[userCount] = user;
        userCount++;
    } else {
        cout << "User storage limit reached.\n";
    }
}


void loginn()
{
	string lkey, useridt ;
	
	cout<<"Enter the login key to proceed......"<<endl;
					cin>>lkey;
					
					ifstream f2("loginkey.txt");
		while(f2>>useridt)
			{
			if(lkey==useridt )
			{
				cout<<"Your login is Succesfull"<<endl;
			}
			else 
			{
				cout<<"Login Error"<<endl;
			cout<<"."<<endl;
			system("cls");
			main();
			}
			}
	
}




void registration() {
    string username, password;
    cout << "Enter Registration Username: ";
    cin >> username;
    cout << "Enter Registration Password: ";
    cin >> password;

    bool usernameExists = false;
    for (int i = 0; i < userCount; ++i) {
        if (users[i].username == username) {
            usernameExists = true;
            break;
        }
    }

    if (!usernameExists) {
        User newUser = {username, password};
        saveUser(newUser);
        cout << setw(25) << "REGISTRATION SUCCESSFUL \n" << endl;
        cout << "WELCOME TO LOGIN PAGE...!!! \n" << endl;
    } else {
        cout << "Username already exists. Please choose a different username.\n\n";
    }
}

void login() {
    string username, password;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    bool userAuthenticated = false;
    for (int i = 0; i < userCount; ++i) {
        if (users[i].username == username && users[i].password == password) {
            userAuthenticated = true;
            break;
        }
    }

    if (userAuthenticated) {
        cout << "Your login is Successful\n";
    } else {
    system("cls");
        cout << "Login Error\n";
        cout << ".\n";
       main();
    }
}


	void forgot()
	{
		int option;
		cout<<"press 1 to search your password with the help of username"<<endl;
		cout<<"press 2 to go back to main menu"<<endl;
		cout<<"choice"<<endl;
		cin>>option;
		switch(option)
		{
			case 1:
				{	
				int count;
				string suserid,ruserid,rpassword;
				cin>>suserid;
				ifstream f1("records.txt");
				while(f1>>ruserid>>rpassword)
		{
			if(suserid==ruserid)
			{
				count=1;
			}
			else 
			{
				count=2;
			}
	}
	f1.close();
		if (count==1)
		{
			cout<<"you account is found"<<endl;
			cout<<"your password is : "<<rpassword<<"\n\n\n"<<endl;
			login();
			cout<<"\n"<<endl;
			
	}
		else
		{
			cout<<"we cant find your account"<<endl;
			
			
		}
		break;
	}
				case 2:
					cout<<"we cant find your account"<<endl;
		break;
				default:
						cout<<"invalid"<<endl;
		}
	}







void saveStudentInfo(const string& name, const string& app, const string& email, char gender, int department, const Course& selectedCourse) {
    // Save student information to a file or database
    ofstream outFile("student_info.txt", ios::app);

    if (outFile.is_open()) {
        outFile << "Name: " << name << "\n";
        outFile << "Application ID: " << app << "\n";
        outFile << "Email: " << email << "\n";
        outFile << "Gender: " << gender << "\n";
        outFile << "Department: " << (department == 1 ? "IT & CS" : "Medical") << "\n";
        outFile << "Selected Course: " << selectedCourse.getName() << "\n\n";
        outFile.close();
    } else {
        cout << "Error: Unable to save student information." << endl;
    }
}

void generateConfirmationLetter(const string& name, const string& app, const string& email, const Course& selectedCourse) {
    // Generate and save confirmation letter
    ofstream confirmationFile("confirmation_letter.txt");

    if (confirmationFile.is_open()) {
        confirmationFile << "Congratulations, " << name << "!\n";
        confirmationFile << "Your application (ID: " << app << ") for admission to PAK AUSTRIA UNIVERSITY has been accepted.\n";
        confirmationFile << "You are admitted to the " << selectedCourse.getName() << " program.\n";
        confirmationFile << "Classes will commence on the specified date. Please make sure to complete the necessary registration procedures.\n";
        confirmationFile << "Best regards,\n";
        confirmationFile << "PAK AUSTRIA UNIVERSITY\n";
        confirmationFile.close();
    } else {
        cout << "Error: Unable to generate confirmation letter." << endl;
    }
}

void generateRejectionLetter(const string& name, const string& app, const string& email) {
    // Generate and save rejection letter
    ofstream rejectionFile("rejection_letter.txt");

    if (rejectionFile.is_open()) {
        rejectionFile << "Dear " << name << ",\n";
        rejectionFile << "We regret to inform you that your application (ID: " << app << ") for admission to PAK AUSTRIA UNIVERSITY has been unsuccessful.\n";
        rejectionFile << "Thank you for considering our university, and we wish you the best in your future endeavors.\n";
        rejectionFile << "Best regards,\n";
        rejectionFile << "PAK AUSTRIA UNIVERSITY\n";
        rejectionFile.close();
    } else {
        cout << "Error: Unable to generate rejection letter." << endl;
    }
}

int getDepartmentChoice() {
    int chuse;

    cout << "Please choose the department for the entry test:" << endl;
    cout << "1. IT & CS" << endl;
    cout << "2. Medical" << endl;
    cin >> chuse;

    while (!(chuse == 1 || chuse == 2)) {
        cout << "INVALID ENTRY, PLEASE RE-ENTER" << endl;
        cin >> chuse;
    }

    return chuse;
}




void IT_cselect()
	{
		int a;
		toupper(a);
		cout<<"[Apply Now]"<<endl;
		cout<<setw(20)<<"Select your  Bachelor course regarding IT"<<endl;
		cout<<setw(20)<<"1:BS Software Engineering"<<endl;
		cout<<setw(20)<<"2:BS Computer Science"<<endl;
		cout<<setw(20)<<"3:BS Artificial Intelligence"<<endl;
		cout<<setw(20)<<"4:BS Data Science"<<endl;
		cout<<setw(20)<<"5:BS Cyber Security"<<endl;
		cin>>a;
		switch(a)
		{
			case 1:
			{
					cout<<setw(20)<<"__________________________"<<endl;
					cout<<setw(20)<<"SOFTWARE ENGINEERING DETAILS:"<<endl;
					cout<<setw(20)<<"__________________________"<<endl;
					cout<<endl<<endl;
					cout<<" Your sujects will be:"<<endl;
					cout<<setw(15)<<"1:ICT"<<endl;
					cout<<setw(15)<<"2:Programming Fundamentals"<<endl;
					cout<<setw(15)<<"3:English"<<endl;
					cout<<setw(15)<<"4:calculus and analytical geometery"<<endl;
					cout<<setw(15)<<"5:pakstudies"<<endl;
					cout<<setw(30)<<"Total Fee: 1,50,000"<<endl;}
					
				break;
                     

				case 2:
					
					{
					cout<<setw(20)<<"__________________________"<<endl;
					cout<<setw(20)<<"Computer Science DETAILS:"<<endl;
					cout<<setw(20)<<"__________________________"<<endl;
					cout<<endl<<endl;
					cout<<" Your sujects will be:"<<endl;
					cout<<setw(15)<<"1:ICT"<<endl;
					cout<<setw(15)<<"2:Programming Fundamentals"<<endl;
					cout<<setw(15)<<"3:English"<<endl;
					cout<<setw(15)<<"4:calculus and analytical geometery"<<endl;
					cout<<setw(15)<<"5:Applied Physics"<<endl;
					cout<<setw(30)<<"Total Fee: 1,58,000"<<endl;}
				break;
				case 3:
					
					{
					cout<<setw(20)<<"__________________________"<<endl;
					cout<<setw(20)<<"Artificial Intelligence DETAILS:"<<endl;
					cout<<setw(20)<<"__________________________"<<endl;
					cout<<endl<<endl;
					cout<<" Your sujects will be:"<<endl;
					cout<<setw(15)<<"1:ICT"<<endl;
					cout<<setw(15)<<"2:Programming Fundamentals"<<endl;
					cout<<setw(15)<<"3:English Language and Communication skills"<<endl;
					cout<<setw(15)<<"4:Islamic Studies"<<endl;
					cout<<setw(15)<<"5:pakstudies"<<endl;
					cout<<setw(15)<<"6:Applied Physics"<<endl;
					cout<<setw(30)<<"Total Fee: 1,72,000"<<endl;}
					break;
					case 4:
					{
					cout<<setw(20)<<"__________________________"<<endl;
					cout<<setw(20)<<"Data Science DETAILS:"<<endl;
					cout<<setw(20)<<"__________________________"<<endl;
					cout<<endl<<endl;
					cout<<" Your sujects will be:"<<endl;
					cout<<setw(15)<<"1:ICT"<<endl;
					cout<<setw(15)<<"2:Programming Fundamentals"<<endl;
					cout<<setw(15)<<"3:English"<<endl;
					cout<<setw(15)<<"4:Islamic Studies"<<endl;
					cout<<setw(15)<<"5:Analytical Geometery"<<endl;
					cout<<setw(15)<<"6:Applied Physics"<<endl;
					cout<<setw(30)<<"Total Fee: 1,72,000"<<endl;}
						
						break;
						case 5:
					{
					cout<<setw(20)<<"__________________________"<<endl;
					cout<<setw(20)<<"Cyber Security:"<<endl;
					cout<<setw(20)<<"__________________________"<<endl;
					cout<<endl<<endl;
					cout<<" This subject will be introduce in next semester:"<<endl;
					}
						break; 
						default:
							cout<<"INVALID COURSE"<<endl;
		}
		
		
	}
	void MD_cselect()
	{
	int a;
		toupper(a);
		cout<<"[Apply Now]"<<endl;
		cout<<setw(20)<<"Select your  Bachelor course regarding Medical"<<endl;
		cout<<setw(20)<<"1:BS BIO MEDICAL SCIENCE "<<endl;
		cout<<setw(20)<<"2:BS PHARMACY "<<endl;
		cout<<setw(20)<<"3:BS MICROBIOLOGY "<<endl;
		cout<<setw(20)<<"4:BS BIOTECHNOLOGY"<<endl;
		
		cin>>a;
		switch(a)
		{
				case 1:
			{
					cout<<setw(20)<<"__________________________"<<endl;
					cout<<setw(20)<<"BIO MEDICAL SCIENCE:"<<endl;
					cout<<setw(20)<<"__________________________"<<endl;
					cout<<endl<<endl;
					cout<<" Your sujects will be:"<<endl;
					cout<<setw(15)<<"1:ICT"<<endl;
					cout<<setw(15)<<"2:Programming Fundamentals"<<endl;
					cout<<setw(15)<<"3:English Language and communication skills"<<endl;
					cout<<setw(15)<<"4:Chemistry & stichiometry"<<endl;
					cout<<setw(15)<<"5:Islamic studies"<<endl;
					cout<<setw(30)<<"Total Fee: 1,68,000"<<endl;}
					
					break;
						case 2:
			{
					cout<<setw(20)<<"__________________________"<<endl;
					cout<<setw(20)<<"BS PHARMACY DETAILS:"<<endl;
					cout<<setw(20)<<"__________________________"<<endl;
					cout<<endl<<endl;
					cout<<" Your sujects will be:"<<endl;
					cout<<setw(15)<<"1:ICT"<<endl;
					cout<<setw(15)<<"2:Programming Fundamentals"<<endl;
					cout<<setw(15)<<"3:English Language and communication skills"<<endl;
					cout<<setw(15)<<"4:Chemistry & stichiometry"<<endl;
					cout<<setw(15)<<"4:Foundation maths"<<endl;
					cout<<setw(15)<<"5:Islamic studies"<<endl;
					cout<<setw(30)<<"Total Fee: 1,55,000"<<endl;}
					break;
						case 3:
			        {
					cout<<setw(20)<<"__________________________"<<endl;
					cout<<setw(20)<<"MICROBIOLOGY DETAILS:"<<endl;
					cout<<setw(20)<<"__________________________"<<endl;
					cout<<endl<<endl;
					cout<<" Your sujects will be:"<<endl;
					cout<<setw(15)<<"1:ICT"<<endl;
					cout<<setw(15)<<"2:Programming Fundamentals"<<endl;
					cout<<setw(15)<<"3:English Language and communication skills"<<endl;
					cout<<setw(15)<<"4:Entrepreneurship"<<endl;
					cout<<setw(15)<<"5:Pakistan studies"<<endl;
					cout<<setw(15)<<"6:Fundamentals of microbiology"<<endl;
					cout<<setw(30)<<"Total Fee: 1,68,000"<<endl;}
					break;
						case 4:
			{
					cout<<setw(20)<<"__________________________"<<endl;
					cout<<setw(20)<<"BIOTECHNOLOGY DETAILS:"<<endl;
					cout<<setw(20)<<"__________________________"<<endl;
					cout<<endl<<endl;
					cout<<" Your sujects will be:"<<endl;
					cout<<setw(15)<<"1:ICT"<<endl;
					cout<<setw(15)<<"2:Programming Fundamentals"<<endl;
					cout<<setw(15)<<"3:English Language and communication skills"<<endl;
					cout<<setw(15)<<"4:Chemistry & stichiometry"<<endl;
					cout<<setw(15)<<"5:Pakistan studies"<<endl;
					cout<<setw(15)<<"6:Fundamentals of microbiology"<<endl;
					
					cout<<setw(30)<<"Total Fee: 1,68,000"<<endl;}
					break;
					default:
						cout<<"INVALID COURSE"<<endl;
					
					
		}










}






void entryTestit(const string& name, const string& app, const string& email, char gender) {
    // Implement entry test logic here
    // ...
    char opt;
    toupper(opt);

    system("cls");
    cout << "***********************************************" << endl;
    cout << " ENTRY TEST FOR IT/CS Department" << endl;
    cout << "Time:20 mins" << endl;
    cout << "***********************************************" << endl;
    int total = 0;
    cout << "1: Unit of frequency is________" << endl;
    cout << "a)Hz        b)joule        c)ampere        d)columb" << endl;
    cout << "correct option is:\n" << endl;
    cin >> opt;
    if (opt == 'a') {
        cout << "Correct answer \n" << endl;
        total += 1;
        cout << "Points: " << total << endl << endl;
    } else {
        cout << "Wrong answer" << endl << endl;
    }
    cout << "2: BIOS is loaded in________" << endl;
    cout << "a)Hard drive        b)RAM        c)ROM        d)Cache" << endl;
    cout << "correct option is:" << endl;
    cin >> opt;
    if (opt == 'c') {
        cout << "Correct answer \n" << endl;
        total += 1;
        cout << "Points: " << total << endl << endl;
    } else {
        cout << "Wrong answer" << endl << endl;
    }
    cout << "3: Circumference of a circle is =________" << endl;
    cout << "a)2pi*r        b)1/2pi        c)pi*r^2        d)2pi" << endl;
    cout << "correct option is:" << endl;
    cin >> opt;
    if (opt == 'a') {
        cout << "Correct answer \n" << endl;
        total += 1;
        cout << "Points: " << total << endl << endl;
    } else {
        cout << "Wrong answer" << endl << endl;
    }
    cout << "4: which of them have the same unit________" << endl;
    cout << "a)force \\ energy        b)power \\ force        c)work \\ energy        d)charge \\ force" << endl;
    cout << "correct option is:" << endl;
    cin >> opt;
    if (opt == 'c') {
        cout << "Correct answer \n" << endl;
        total += 1;
        cout << "Points: " << total << endl << endl;
    } else {
        cout << "Wrong answer" << endl << endl;
    }
    cout << "5: Slope of velocity-time graph gives us________" << endl;
    cout << "a)displacement        b)speed        c)acceleration        d)momentum" << endl;
    cout << "correct option is:" << endl;
    cin >> opt;
    if (opt == 'c') {
        cout << "Correct answer \n" << endl;
        total += 1;
        cout << "Points: " << total << endl << endl;
    } else {
        cout << "Wrong answer" << endl << endl;
    }
    cout << "6: Which of them stores a large amount of data________" << endl;
    cout << "a)blu-ray        b)DVD        c)CD        d)all " << endl;
    cout << "correct option is:" << endl;
    cin >> opt;
    if (opt == 'a') {
        cout << "Correct answer \n" << endl;
        total += 1;
        cout << "Points: " << total << endl << endl;
    } else {
        cout << "Wrong answer" << endl << endl;
    }
    cout << "7: In the computer system, 1 nibble=________" << endl;
    cout << "a)2_bits        b)4_bytes        c)8_bits        d)4_bits" << endl;
    cout << "correct option is:" << endl;
    cin >> opt;
    if (opt == 'd') {
        cout << "Correct answer \n" << endl;
        total += 1;
        cout << "Points: " << total << endl << endl;
    } else {
        cout << "Wrong answer" << endl;
    }
    cout << "8: Convex lens produces ________ image" << endl;
    cout << "a)real        b)virtual        c)none        d)both" << endl;
    cout << "correct option is:" << endl;
    cin >> opt;
    if (opt == 'b') {
        cout << "Correct answer \n" << endl;
        total += 1;
        cout << "Points: " << total << endl << endl;
    } else {
        cout << "Wrong answer" << endl;
    }
    cout << "9: To access a class in C++, we have to create________ in the main function" << endl;
    cout << "a)variable        b)function        c)object        d)array" << endl;
    cout << "correct option is:" << endl;
    cin >> opt;
    if (opt == 'c') {
        cout << "Correct answer \n" << endl;
        total += 1;
        cout << "Points: " << total << endl << endl;
    } else {
        cout << "Wrong answer\n" << endl;
    }
    cout << "10: The fixed point on the ellipse is called _________" << endl;
    cout << "a)vertex        b)axis        c)centre        d)focus" << endl;
    cout << "correct option is:" << endl;
    cin >> opt;
    if (opt == 'd') {
        cout << "Correct answer \n" << endl;
        total += 1;
        cout << "Points: " << total << endl << endl;
    } else {
        cout << "Wrong answer" << endl;
    }

    // Displaying results
    if (total > 7) {
        cout << setw(60) << "_______________________" << endl;
        cout << setw(60) << "CONGRATULATIONS ....!!!" << endl;
        cout << setw(60) << "_______________________" << endl;
        cout << "correct answers: " << total << endl;
        cout << "You have scored 70% " << endl;
        Course selectedCourse("IT & CS Program");
        saveStudentInfo(name, app, email, gender, 1, selectedCourse); // 1 represents the IT & CS department
        generateConfirmationLetter(name, app, email, selectedCourse);
        IT_cselect(); // function IT course selection
    } else {
        cout << "Correct answers were:" << total << endl;
        cout << "Unfortunately, you are not eligible \nBetter luck next time" << endl;
        // Student failed entry test, generate rejection letter
        generateRejectionLetter(name, app, email);
    }
}


void entryTestmd(const string& name, const string& app, const string& email, char gender) {
    // Implement entry test logic here
    // ...
    system("cls");
    char opt;
    toupper(opt);
    cout << "***********************************************" << endl;
    cout << " ENTRY TEST FOR Medical Departments" << endl;
    cout << "Time:20 mins" << endl;
    cout << "***********************************************" << endl;
    int total = 0;
    cout << "1:________ is the powerhouse of the cell" << endl;
    cout << "a)cell membrane		b)cytoplasm		c)mitochondria		d)none" << endl;
    cin >> opt;
    if (opt == 'c') {
        cout << "Correct answer" << endl;
        total += 1;
        cout << "Points: " << total << endl;
    } else {
        cout << "Wrong Answer" << endl;
    }

 		cout<<"2: Unit of frequency is________"<<endl;
	    cout<<"a)Hz		b)joule		c)ampere		d)columb"<<endl;
	    cout<<"correct option is:\n"<<endl;
	    cin>>opt;
		if(opt=='a')
    	{cout<<"Correct answer \n"<<endl;
		total+=1;
		cout<<"Points: "<<total<<endl<<endl;}
      	else
	    cout<<"Wrong answer"<<endl<<endl;
	    cout<<"3: which of them have same unit________"<<endl;
    	cout<<"a)force / energy		b)power | force		c)work | energy		d)charge  | force"<<endl;
    	cout<<"correct option is:"<<endl;
	    cin>>opt;
	    if(opt=='c')
	    {cout<<"Correct answer \n"<<endl;
		total+=1;
		cout<<"Points: "<<total<<endl<<endl;}
    	else
    	cout<<"Wrong answer"<<endl<<endl;
    	cout<<"4: Slope of velocity time graph gives us________"<<endl;
    	cout<<"a)displacement		b)speed		c)acceleration		d)momentum"<<endl;
    	cout<<"correct option is:"<<endl;
	    cin>>opt;
    	if(opt=='c')
     	{cout<<"Correct answer \n"<<endl;
		total+=1;
		cout<<"Points: "<<total<<endl<<endl;}
	    else
	    cout<<"Wrong answer"<<endl<<endl;
	    cout<<"5: convax lens produces ________ image"<<endl;
	    cout<<"a)real		b)virtual		c)none		d)both"<<endl;
	    cout<<"correct option is:"<<endl;
	    cin>>opt;
	    if(opt=='b')
	    {cout<<"Correct answer \n"<<endl;
		total+=1;
		cout<<"Points: "<<total<<endl<<endl;}
	    else
	    cout<<"Wrong answer"<<endl;
	    cout<<"5: There are  ________ numbers of chambers is heart"<<endl;
	    cout<<"a)2		b)3		c)4		d)1"<<endl;
	    cout<<"correct option is:"<<endl;
	    cin>>opt;
	    if(opt=='c')
	    {cout<<"Correct answer \n"<<endl;
		total+=1;
		cout<<"Points: "<<total<<endl<<endl; }
	    else
	    cout<<"Wrong answer"<<endl;
	    cout<<"6: Group of cells working together are called________"<<endl;
	    cout<<"a)tissues		b)cells 	c)organs	d)all"<<endl;
	    cout<<"correct option is:"<<endl;
	    cin>>opt;
	    if(opt=='a')
	    {cout<<"Correct answer \n"<<endl;
		total+=1;
		cout<<"Points: "<<total<<endl<<endl; }
	    else
	    cout<<"Wrong answer"<<endl;
	    cout<<"7: viruse lives as__________"<<endl;
	    cout<<"a)organism	b)living organism	c)non living organism		d)parasite"<<endl;
	    cout<<"correct option is:"<<endl;
	    cin>>opt;
	    if(opt=='d')
	    {cout<<"Correct answer \n"<<endl;
		total+=1;
		cout<<"Points: "<<total<<endl<<endl; }
	    else
	    cout<<"Wrong answer"<<endl;
	    cout<<"8:LI is located in group _____ in periodic table."<<endl;
	    cout<<"a)alkaline earth metals		b)alkali metals	c) alloys	d)btoh b and c"<<endl;
	    cout<<"correct option is:"<<endl;
	    cin>>opt;
	    if(opt=='b')
	    {cout<<"Correct answer \n"<<endl;
		total+=1;
		cout<<"Points: "<<total<<endl<<endl; }
	    else
	    cout<<"Wrong answer"<<endl;
	    cout<<"9: There are _____ types of endoplasmic reticulum"<<endl;
	    cout<<"a)2		b)3		c)4		d)1"<<endl;
	    cout<<"correct option is:"<<endl;
	    cin>>opt;
	    if(opt=='a')
	    {cout<<"Correct answer \n"<<endl;
		total+=1;
		cout<<"Points: "<<total<<endl<<endl; }
	    else
	    cout<<"Wrong answer"<<endl;
	    cout<<"10: unprogrammed death of cell is _________"<<endl;
	    cout<<"a)meosis		b)apoptosis 	c)necrosis		d)mitosis"<<endl;
	    cout<<"correct option is:"<<endl;
	    cin>>opt;
	    if(opt=='c')
	    {cout<<"Correct answer \n"<<endl;
		total+=1;
		cout<<"Points: "<<total<<endl<<endl; }
	    else
	    cout<<"Wrong answer"<<endl;

    if (total > 7) {
        cout << setw(60) << "_______________________" << endl;
        cout << setw(60) << "CONGRATULATIONS ....!!!" << endl;
        cout << setw(60) << "_______________________" << endl;
        cout << "correct answers: " << total << endl;
        cout << "You have scored 70% " << endl;
        Course selectedCourse("Medical Program");
        saveStudentInfo(name, app, email, gender, 2, selectedCourse);
        generateConfirmationLetter(name, app, email, selectedCourse);
        MD_cselect(); // function medical course selection
    } else {
        cout << "Correct answers were:" << total << endl;
        cout << "Unfortunately, you are not eligible \nBetter luck next time" << endl;
        // Student failed entry test, generate rejection letter
        generateRejectionLetter(name, app, email);
    }
}




void calculateGPA(vector<coursee>& coursees, double& gpa, string& grade) {
    double totalCredits = 0;
    double totalGradePoints = 0;

    for (const auto& currentcoursee : coursees) {
        totalCredits += currentcoursee.credits;

        if (currentcoursee.marks >= 95) {
            totalGradePoints += 4.0 * currentcoursee.credits;
            grade += "A+ ";
        } else if (currentcoursee.marks >= 90) {
            totalGradePoints += 3.67 * currentcoursee.credits;
            grade += "A ";
        } else if (currentcoursee.marks >= 85) {
            totalGradePoints += 3.33 * currentcoursee.credits;
            grade += "A- ";
        } else if (currentcoursee.marks >= 80) {
            totalGradePoints += 3.0 * currentcoursee.credits;
            grade += "B+ ";
        } else if (currentcoursee.marks >= 75) {
            totalGradePoints += 2.67 * currentcoursee.credits;
            grade += "B ";
        } else if (currentcoursee.marks >= 70) {
            totalGradePoints += 2.33 * currentcoursee.credits;
            grade += "B- ";
        } else if (currentcoursee.marks >= 65) {
            totalGradePoints += 2.0 * currentcoursee.credits;
            grade += "C+ ";
        } else if (currentcoursee.marks >= 60) {
            totalGradePoints += 1.67 * currentcoursee.credits;
            grade += "C ";
        } else if (currentcoursee.marks >= 55) {
            totalGradePoints += 1.33 * currentcoursee.credits;
            grade += "C- ";
        } else if (currentcoursee.marks >= 50) {
            totalGradePoints += 1.0 * currentcoursee.credits;
            grade += "D ";
        } else {
            grade += "F ";
        }

        cout << "coursee: " << setw(25) << left << currentcoursee.name << " Marks: " << setw(5) << right << currentcoursee.marks << " Credits: " << setw(5) << right << currentcoursee.credits << endl;
    }

    gpa = totalGradePoints / totalCredits;
}

void saveStudentInfo(ofstream& outFile, Student& student) {
    outFile << "Name: " << student.name << endl;
    outFile << "Registration Number: " << student.registrationNumber << endl;
    outFile << "GPA: " << fixed << setprecision(2) << student.gpa << endl;
    outFile << "Grade: " << student.grade << endl;
    outFile << "-------------------------------------\n";
}

void displayDepartments(const vector<Department>& departments) {
    cout << "Available Departments:\n";
    for (const auto& department : departments) {
        cout << "- " << department.name << endl;
    }
}

void displayPrograms(const vector<Program>& programs) {
    cout << "Available Programs:\n";
    for (const auto& program : programs) {
        cout << "- " << program.name << endl;
    }
}

void displaycoursees(const vector<coursee>& coursees) {
    cout << "Available coursees:\n";
    for (const auto& coursee : coursees) {
        cout << "- " << coursee.name << " (Credits: " << coursee.credits << ")\n";
    }
}



