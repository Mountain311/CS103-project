/*
Name: Muhammad Ibne Muzammil
Registration Number: 2020311
Section : CS-103 A
Faculty : Faculty of Computer Science and Engineering [BS-AI]
Teacher : Dr. Raja Hashim
Ghulam Ishaq Khan Institute of Engineering Sciences and Technology
*/

// CODE

/*________________________________Including Header Files__________________________________ */

#include <iostream>
#include <fstream> // To Open and Manipulte Files
#include <string>
#include <stdlib.h> //To use the Clear Screen function and the System Pause function
#include <vector>
#include <sstream>  //to use String Stream (To split strings into words)

using namespace std;

/*______________________________Declaring User Defined Functions__________________________ */

void intro();
void coe_console();
void instructor_console(string);
void student_console(string);

/*_____________________________Beginning the Main Program_________________________________ */



int main()
{
	system("cls");
	
	intro(); // Function call to Display intro message
	
	Again :
	
	vector<string> column;
	string row,word,line;
	string userid, password;
	int attempt=0;
	bool found=false;
	
	fstream usersin;
	
	usersin.open("userpw.csv", ios::in); // Opens A file for Reading 
	
	system("cls");
	
	cout<<"Enter User ID : "<<endl;
	cin>>userid;
	
	while(!usersin.eof() )
		{
			column.clear();   //Clears every entry currently in the vector 
			
			getline(usersin,line); // Gets a single line from the File and assigns it to the string
			
			istringstream s(line); // Assigns the String to the string stream so that it can be manipulated
			
			while( getline(s,word,','))  // Takes the string stream and breaks it into smaller strings deliminated by the ',' special Character and assigns these to another
			{
				column.push_back(word);  // Enters the smaller strings into a new index of the vector
			}
		if(column[1]==userid)
		{
			cout<<endl<<"User Found."<<endl<<endl;
			found=true;
			break;
		}
	}
	if(found==false)
	{
		cout<<"User Not Found. TRY AGAIN."<<endl;
		system("pause");
		goto Again;
	}
	
	usersin.close();
	
	while(attempt<5)
	{
		cout<<"Enter Password : "<<endl;
		cin>>password;
		
		if(column[2]==password)
			{
				cout<<endl<<"ACCESS GRANTED!"<<endl;
				break;
			}
		else
			{
				attempt++;
				cout<<endl<<"ACCESS DENIED"<<endl;
				cout<<"Try Again! Remaining Attemps = "<<5-attempt<<endl<<endl;
			}
	}
	if(attempt>=5)
	{
		cout<<" Maximum Number of Attempts Reached"<<endl;
		system("pause");
		exit(0);
	}
	
			if(column[0]=="COE")
			{
				cout<<"COE User Detected"<<endl;
				system("pause");
				coe_console();
			}
			else if(column[0]=="Instructor")
			{
				cout<<"Instructor User Detected"<<endl;
				
				system("pause");
				
				instructor_console(userid);
			}
			else if(column[0]=="Student")
			{
				cout<<"Student User Detected"<<endl;
				
				system("pause");
				
				student_console(userid);
			}
	
	
return 0;	
}

void coe_console()
{
	system("cls");
	
	int choice;
	vector<string> column;
	string row,word,line;
	
	Start:		
	
	system("cls");
	
	cout<<"Welcome to The COE Console"<<endl<<endl;
		
	cout<<"Enter 1 to Change Password : "<<endl
	<<"Enter 2 to Create New Student ID : "<<endl
	<<"Enter 3 to Create New Instructor ID : "<<endl
	<<"Enter 4 to Delete a Student or Instructor ID : "<<endl
	<<"Enter 5 to Send Message to Instructor Chat : "<<endl
	<<"Enter 6 to View Instructor Chat : "<<endl
	<<"Enter 7 to Log Out : "<<endl;
	
	cin>>choice;
	
	if(choice==1)
	{
		fstream usersin,usersout;
		usersin.open("userpw.csv", ios::in);
		usersout.open("userpwnew.csv", ios::out);  // Opens a file for writing
		
		string new_pass;
		
		system("cls");
		
		cout<<"Enter New Password : "<<endl;
		cin>> new_pass;
		
		while(!usersin.eof() )
		{
			column.clear();
			
			getline(usersin,line);
			
			istringstream s(line);
			
			while( getline(s,word,','))
			{
				column.push_back(word); 
			}
			if(column[0]=="COE")
			{
				column[2]=new_pass;
				
				if (!usersin.eof()) 
				{ 
					for (int j = 0; j < column.size()-1; j++) 
					{ 
	
						// write the updated data 
						// into a new file 'reportcardnew.csv' 
						// using fout 
						usersout << column[j] << ","; 
					}
					
					usersout << column[column.size()-1] << "\n"; 
					
					if(column[2]==new_pass)
					{
						cout<<"Password Change successful"<<endl;
					}
				}
			}
			else 
			{
				if (!usersin.eof()) 
				{ 
				for (int j = 0; j < column.size()-1 ; j++)
				{ 

					// writing other existing records 
					// into the new file using fout. 
					usersout << column[j] << ","; 
				} 

				// the last column data ends with a '\n' 
				usersout << column[column.size()-1]  << "\n"; 
				}
			} 
		} 
		usersin.close();
		usersout.close();
		
			
		
	// removing the existing file 
	remove("userpw.csv");

	// renaming the updated file with the existing file name 
	rename("userpwnew.csv","userpw.csv");
	
	system("pause");
	
	goto Start;

	}

	else if(choice==2)
	{
		system("cls");
		
		string user_id, user_pass, first_name, second_name, faculty;
		
		cout<<"Enter User ID of New Student : "<<endl;
		cin>>user_id;
		cout<<"Enter Password of New Student : "<<endl;
		cin>>user_pass;
		cout<<"Enter First Name of New Student : "<<endl;
		cin>>first_name;
		cout<<"Enter Last Name  of New Student : "<<endl;
		cin>>second_name;
		cout<<"Enter Faculty of New Student : "<<endl;
		cin>>faculty;
		
		fstream usersout;
		usersout.open("userpw.csv", ios::app); // Opens a file to append
		
		usersout<< "Student" << "," 
		<< user_id << ","
		<< user_pass << ","
		<< first_name << ","
		<< second_name << ","
		<< faculty << ","
		<< " " << ","	// CS103 grade
		<< " " << ","   // CS131 grade
		<< " " << ","   // CS121 grade
		<< " " << ","   // MT101 grade
		<< " " << ","   // HM101 grade
		<<"\n";
		usersout.close();
		 
		cout<<"New User Added Succesfully "<<endl;
		 
		system("pause");
		
		goto Start;
		
	}
	
	else if(choice==3)
	{
		system("cls");
		
		string user_id, user_pass, first_name, second_name, faculty, course;
		
		cout<<"Enter User ID of New Instructor : "<<endl;
		cin>>user_id;
		cout<<"Enter Password of New Instructor : "<<endl;
		cin>>user_pass;
		cout<<"Enter First Name of New Instructor : "<<endl;
		cin>>first_name;
		cout<<"Enter Last Name  of New Instructor : "<<endl;
		cin>>second_name;
		cout<<"Enter Faculty of New Instructort : "<<endl;
		cin>>faculty;
		cout<<"Enter Course of New Instructor : "<<endl;
		cin>>course;
		
		fstream usersout;
		usersout.open("userpw.csv", ios::app);
		
		usersout<< "Instructor" << "," 
		<< user_id << ","
		<< user_pass << ","
		<< first_name << ","
		<< second_name << ","
		<< faculty << ","
		<< course <<","
		<<"\n";
		usersout.close();
		 
		cout<<"New User Added Succesfully "<<endl;
		 
		system("pause");
		
		goto Start;
		
	}
	
	
	else if(choice==4)
	{
		fstream usersin,usersout;
		usersin.open("userpw.csv", ios::in);
		usersout.open("userpwnew.csv", ios::out);
		
		string userdel;
		
		system("cls");
		
		cout<<"Enter User ID to be Deleted : "<<endl;
		cin>> userdel;
		
		while(!usersin.eof() )
		{
			column.clear();
			
			getline(usersin,line);
			
			istringstream s(line);
			
			while( getline(s,word,','))
			{
				column.push_back(word); 
			}
			if(column[1]==userdel)
			{
				column.clear();
			}
			else 
			{
				if (!usersin.eof()) 
				{ 
				for (int j = 0; j < column.size()-1 ; j++)
				{ 

					// writing other existing records 
					// into the new file using fout. 
					usersout << column[j] << ","; 
				} 

				// the last column data ends with a '\n' 
				usersout << column[column.size()-1]  << "\n"; 
				}
			} 
		} 
		usersin.close();
		usersout.close();
		
			
		
	// removing the existing file 
	remove("userpw.csv");

	// renaming the updated file with the existing file name 
	rename("userpwnew.csv","userpw.csv");
	
	cout<<"User Deleted Successfully"<<endl<<endl;
	
	system("pause");
	
	goto Start;

	}
	
	else if (choice==5)
	{
		system("cls");
		
		fstream chatout;
		chatout.open("chat.txt",ios::app);
		
		string message;
		
		cout<<"Enter the Message you wish to send : "<<endl;
		cin.ignore();
		getline(cin,message);		
		
		chatout<<"(Message from COE) "<<"\n"
		<<message<<"\n"<<"\n";
		
		chatout.close();
		
		cout<<endl<<endl<<"Message Sent!"<<endl<<endl;
		
		system("pause");
		
		goto Start;	
	}
	
	else if(choice==6)
	{
		system("cls");
		
		fstream chatread;
		chatread.open("chat.txt",ios::in);
		
		string line;
		
		while(!chatread.eof())
		{
			getline(chatread,line);
			
			cout<<line<<endl;
		}
		
		chatread.close();
		
		cout<<endl<<endl<<"END OF CHAT"<<endl<<endl;
		
		system("pause");
		
		goto Start;
	}
	
	else if(choice==7)
	{
		system("cls");
		cout<<"You have been Logged Out"<<endl;
		system("pause");
		main();
	}
	
	else
	{
		system("cls");
		cout<<"Invalid Input. TRY AGAIN."<<endl;
		system("pause");
		
		goto Start;
	}
	

}

void instructor_console(string useridI)
{
	system("cls");
	
	int index;
	
	vector<string> columnI;
	string rowI,wordI,lineI;
	
	fstream usersinI;
	
	usersinI.open("userpw.csv", ios::in);
	
	while(!usersinI.eof() )
	{
		columnI.clear();
			
		getline(usersinI,lineI);
			
		istringstream sI(lineI);
			
		while( getline(sI,wordI,','))
		{
			columnI.push_back(wordI); 
		}
		if(columnI[1]==useridI)
		{
			break;
		}
		
	}
	usersinI.close();
	
	if(columnI[6]=="CS103")
	{
		index=6;
	}
	else if(columnI[6]=="CS131")
	{
		index=7;
	}
	else if(columnI[6]=="CS121")
	{
		index=8;
	}
	else if(columnI[6]=="MT101")
	{
		index=9;
	}
	else if(columnI[6]=="HM101")
	{
		index=10;
	}
	
	int choice;
	vector<string> column;
	string row,word,line;
	
	StartI :
		
	system("cls");
	
	cout<<"Welcome to The Instructor Console"<<endl<<endl;
	
	cout<<"Enter 1 to Change Password : "<<endl
	<<"Enter 2 to View Details  : "<<endl
	<<"Enter 3 to Assign Grade to a Student : "<<endl
	<<"Enter 4 to Send Message to COE Chat : "<<endl
	<<"Enter 5 to View COE Chat : "<<endl
	<<"Enter 6 to Log Out : "<<endl;
	
	cin>>choice;
	
	if(choice==1)
	{
		fstream usersin,usersout;
		usersin.open("userpw.csv", ios::in);
		usersout.open("userpwnew.csv", ios::out);
		
		string new_pass;
		
		system("cls");
		
		cout<<"Enter New Password : "<<endl;
		cin>> new_pass;
		
		while(!usersin.eof() )
		{
			column.clear();
			
			getline(usersin,line);
			
			istringstream s(line);
			
			while( getline(s,word,','))
			{
				column.push_back(word); 
			}
			if(column[1]==useridI)
			{
				column[2]=new_pass;
				
				if (!usersin.eof()) 
				{ 
					for (int j = 0; j < column.size()-1; j++) 
					{ 
	
						// write the updated data 
						// into a new file 'reportcardnew.csv' 
						// using fout 
						usersout << column[j] << ","; 
					}
					
					usersout << column[column.size()-1] << "\n"; 
					
					if(column[2]==new_pass)
					{
						cout<<"Password Change successful"<<endl;
					}
				}
			}
			else 
			{
				if (!usersin.eof()) 
				{ 
				for (int j = 0; j < column.size()-1 ; j++)
				{ 

					// writing other existing records 
					// into the new file using fout. 
					usersout << column[j] << ","; 
				} 

				// the last column data ends with a '\n' 
				usersout << column[column.size()-1]  << "\n"; 
				}
			} 
		} 
		usersin.close();
		usersout.close();
		
			
		
	// removing the existing file 
	remove("userpw.csv");

	// renaming the updated file with the existing file name 
	rename("userpwnew.csv","userpw.csv");
	
	system("pause");
	
	goto StartI;

	}
	
	else if(choice==2)
	{
		system("cls");
		
		fstream usersin;
	
		usersin.open("userpw.csv", ios::in);
		
		while(!usersin.eof() )
		{
			column.clear();
			
			getline(usersin,line);
			
			istringstream s(line);
			
			while( getline(s,word,','))
			{
				column.push_back(word); 
			}
			if(column[1]==useridI)
			{
				break;
			}
		}
		
		cout<<"Instructor ID : "<<column[1]<<endl;	
		cout<<"Instructor First Name : "<<column[3]<<endl;	
		cout<<"Instructor Last Name : "<<column[4]<<endl;
		cout<<"Instructor Faculty : "<<column[5]<<endl;
		cout<<"Instructor Assigned Course : "<<column[6]<<endl<<endl;
		
		
		system("pause");
		
		goto StartI;	
	}
	
	else if(choice==3)
	{
		fstream usersin,usersout;
		usersin.open("userpw.csv", ios::in);
		usersout.open("userpwnew.csv", ios::out);
		
		string useridGC;
		string new_grade;
		
		system("cls");
		
		cout<<"Enter Student ID to Assign Grade to : "<<endl;
		cin>> useridGC;
		cout<<"Assign Grade : "<<endl;
		cin>> new_grade;
		
		while(!usersin.eof() )
		{
			column.clear();
			
			getline(usersin,line);
			
			istringstream s(line);
			
			while( getline(s,word,','))
			{
				column.push_back(word); 
			}
			if(column[1]==useridGC)
			{
				column[index]=new_grade;
				
				if (!usersin.eof()) 
				{ 
					for (int j = 0; j < column.size()-1; j++) 
					{ 
	
						// write the updated data 
						// into a new file 'reportcardnew.csv' 
						// using fout 
						usersout << column[j] << ","; 
					}
					
					usersout << column[column.size()-1] << "\n"; 
					
					if(column[index]==new_grade)
					{
						cout<<"Assignment of Grade Successful"<<endl;
					}
				}
			}
			else 
			{
				if (!usersin.eof()) 
				{ 
				for (int j = 0; j < column.size()-1 ; j++)
				{ 

					// writing other existing records 
					// into the new file using fout. 
					usersout << column[j] << ","; 
				} 

				// the last column data ends with a '\n' 
				usersout << column[column.size()-1]  << "\n"; 
				}
			} 
		} 
		usersin.close();
		usersout.close();
		
			
		
	// removing the existing file 
	remove("userpw.csv");

	// renaming the updated file with the existing file name 
	rename("userpwnew.csv","userpw.csv");
	
	system("pause");
	
	goto StartI;

	}
	
	else if (choice==4)
	{
		system("cls");
		
		fstream chatout;
		chatout.open("chat.txt",ios::app);
		
		string message;
		
		cout<<"Enter the Message you wish to send : "<<endl;
		cin.ignore();
		getline(cin,message);	
		
		chatout<<"(Message from Instructor ID : "<<useridI<<" )"<<"\n"
		<<message<<"\n"<<"\n";
		
		chatout.close();
		
		cout<<endl<<endl<<"Message Sent!"<<endl<<endl;
		
		system("pause");
		
		goto StartI;	
	}
	
	else if(choice==5)
	{
		system("cls");
		
		fstream chatread;
		chatread.open("chat.txt",ios::in);
		
		string line;
		
		while(!chatread.eof())
		{
			getline(chatread,line);
			
			cout<<line<<endl;
		}
		
		chatread.close();
		
		cout<<endl<<endl<<"END OF CHAT"<<endl<<endl;
		
		system("pause");
		
		goto StartI;
	}
	
	else if(choice==6)
	{
		system("cls");
		cout<<"You have been Logged Out"<<endl;
		system("pause");
		main();
	}
	
	else
	{
		system("cls");
		cout<<"Invalid Input. TRY AGAIN."<<endl;
		system("pause");
		
		goto StartI;
	}
}

void student_console(string useridS)
{
	system("cls");
	
	int choice;
	vector<string> column;
	string row,word,line;
	
	StartS:		
	
	system("cls");
	
	cout<<"Welcome to The Student Console"<<endl<<endl;
		
	cout<<"Enter 1 to Change Password : "<<endl
	<<"Enter 2 to View Details  : "<<endl
	<<"Enter 3 to Log Out : "<<endl;
	
	cin>>choice;
	
	if(choice==1)
	{
		fstream usersin,usersout;
		usersin.open("userpw.csv", ios::in);
		usersout.open("userpwnew.csv", ios::out);
		
		string new_pass;
		
		system("cls");
		
		cout<<"Enter New Password : "<<endl;
		cin>> new_pass;
		
		while(!usersin.eof() )
		{
			column.clear();
			
			getline(usersin,line);
			
			istringstream s(line);
			
			while( getline(s,word,','))
			{
				column.push_back(word); 
			}
			if(column[1]==useridS)
			{
				column[2]=new_pass;
				
				if (!usersin.eof()) 
				{ 
					for (int j = 0; j < column.size()-1; j++) 
					{ 
	
						// write the updated data 
						// into a new file 'reportcardnew.csv' 
						// using fout 
						usersout << column[j] << ","; 
					}
					
					usersout << column[column.size()-1] << "\n"; 
					
					if(column[2]==new_pass)
					{
						cout<<"Password Change successful"<<endl;
					}
				}
			}
			else 
			{
				if (!usersin.eof()) 
				{ 
				for (int j = 0; j < column.size()-1 ; j++)
				{ 

					// writing other existing records 
					// into the new file using fout. 
					usersout << column[j] << ","; 
				} 

				// the last column data ends with a '\n' 
				usersout << column[column.size()-1]  << "\n"; 
				}
			} 
		} 
		usersin.close();
		usersout.close();		
		
	// removing the existing file 
	remove("userpw.csv");

	// renaming the updated file with the existing file name 
	rename("userpwnew.csv","userpw.csv");
	
	system("pause");
	
	goto StartS;

	}	
	
	
	else if(choice==2)
	{
		system("cls");
		
		fstream usersin;
	
		usersin.open("userpw.csv", ios::in);
		
		while(!usersin.eof() )
		{
			column.clear();
			
			getline(usersin,line);
			
			istringstream s(line);
			
			while( getline(s,word,','))
			{
				column.push_back(word); 
			}
			if(column[1]==useridS)
			{
				break;
			}
		}
		
		cout<<"Student ID : "<<column[1]<<endl;	
		cout<<"Student First Name : "<<column[3]<<endl;	
		cout<<"Student Last Name : "<<column[4]<<endl;
		cout<<"Student Faculty : "<<column[5]<<endl;
		cout<<"Student CS103 Grade : "<<column[6]<<endl;
		cout<<"Student CS131 Grade : "<<column[7]<<endl;	
		cout<<"Student CS121 Grade : "<<column[8]<<endl;	
		cout<<"Student MT101 Grade : "<<column[9]<<endl;	
		cout<<"Student HM101 Grade : "<<column[10]<<endl<<endl;
		
		system("pause");
		
		goto StartS;	
	}
	
	else if(choice==3)
	{
		system("cls");
		cout<<"You have been Logged Out"<<endl;
		system("pause");
		main();
	}
	
	else
	{
		system("cls");
		cout<<"Invalid Input. TRY AGAIN."<<endl;
		system("pause");
		
		goto StartS;
	}
}

void intro()
{
	cout<<endl<<"Welcome to The Student Transcript System"<<endl
    <<"Made by : "<<endl
    <<"	Name : Muhammad Ibne Muzammil"<<endl
    <<"	Registration Number : 2020311"<<endl
    <<"	Faculty : FCSE (BAI)"<<endl<<endl;
    system("pause"); // System Was Paused to make these Lines Readable Otherwise the program would read through them too fast
    system("cls");
}
