#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int idg,temp,last,lasteqe,issue=0;
int maxrow=40;
string  labequipment;
class equipment
{
	int serialnum;
	string ename;
	int quantity;
	public:	
   void	addeuipment()
  {
		cout << "\n\tEnter equipment  serialno : ";
		cin>>serialnum;
			cout << "\n\tEnter equipment  name : ";
    cin.get();
    getline(cin,ename); 
    cout << "\n\tEnter equipment quantity : ";
    cin >> quantity;
    issue=quantity;
         idg++;
		
		 ofstream write;
    write.open("equipment.txt", ios::app);
    write << "\n" <<serialnum;
    write << "\n" <<ename ;
    write << "\n" <<quantity ;

    
    write.close();
    write.open("id.txt");
    write <<idg;
    write.close();
    cout << "\n\tData save to file"<<endl;
}
void printdata() {
    cout << "\n\t---Equipment Data---";
    cout << "\n\tserial no. is : " << serialnum;
    cout << "\n\tName is : " <<ename;
    cout << "\n\tEquipment quantity is: " <<quantity<<endl;
    
}
int list() {
    
    ifstream read;
    read.open("equipment.txt");
    while (!read.eof()) {
        read >>serialnum;
       read.ignore();
        getline(read, ename);
        read >>quantity;
        if(lasteqe==serialnum)
        {
        		system("cls");
        	cout<<"Your list is empty!!!!"<<endl;
        	return -1;
		}
		if(ename.empty())
		{
				system("cls");
			cout<<"Your list is empty!!!!"<<endl;
        	return -1;
		}
        printdata();
    }
    read.close(); 

}
int searchequipment()
 {
    int num;
    cout << "\n\tEnter serial no. of equipment : ";
    cin >>num;
   
    ifstream read;
    read.open("equipment.txt");
    while (!read.eof()) {
        read >>serialnum;
        read.ignore();
        getline(read,ename);
        read >>quantity;
       
        if (serialnum==num ) {
        		cout<<"\t\tEquipment Available"<<endl;
            printdata();
            return serialnum;
        }
    }
    	system("cls");
    cout<<"Sorry Equipment Not Availiable!!!"<<endl;
}
int searchequipmentst(int num)
 {
    
   
   
    ifstream read;
    read.open("equipment.txt");
    while (!read.eof()) {
        read >>serialnum;
        read.ignore();
        getline(read,ename);
        read >>quantity;
       
        if (serialnum==num ) {
            printdata();
          labequipment=ename;
            return serialnum;
        }
    }
    	system("cls");
    cout<<"Sorry Equipment Not Availiable!!!"<<endl;
    return -1;
}
int searchequipmentstt(int num)
 {
    
   
   
    ifstream read;
    read.open("equipment.txt");
    while (!read.eof()) {
        read >>serialnum;
        read.ignore();
        getline(read,ename);
        read >>quantity;
       
        if (serialnum==num ) {
        
            printdata();
            return serialnum;
        }
    }
    	system("cls");
    cout<<"Sorry Equipment Not Availiable!!!"<<endl;
    return -1;
}
void deleteequipment() 
{
    int num = searchequipment();
     cout << "\n\tYou want to delete record (yes/no) : ";
    string choice;
    cin >> choice;
    if (choice == "yes") {
    
        ofstream tempFile;
        tempFile.open("temps.txt");
        ifstream read;
        read.open("equipment.txt");
        while (!read.eof()) {
            read >>serialnum;
            read.ignore();
            getline(read,ename);
            read >>quantity;
           
            if (serialnum != num) {
                tempFile << "\n" << serialnum;
                tempFile << "\n" << ename;
                tempFile << "\n" << quantity;
               
            }
        }
        read.close();
        tempFile.close();
        remove("equipment.txt");
        rename("temps.txt", "equipment.txt");
        lasteqe=serialnum;
        cout << "\n\tData deleted successfuly"<<endl;
    }
    else {
    		system("cls");
        cout << "\n\tRecord not deleted Something do Wrong";
    }
}
void update()
 {
    int num=searchequipment();
    cout << "\n\tYou want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        string name;
        int newquantity;
        cout << "\n\tEnter a new name : ";
        cin.get();
        getline(cin,name);
        cout << "\n\tEnter a new quantity : ";
        cin >> newquantity;
        ofstream tempFile;
        tempFile.open("temps.txt");
        ifstream read;
        read.open("equipment.txt");
        while (!read.eof()) {
            read >>serialnum;
            read.ignore();
            getline(read,ename);
            read >>quantity;
           
            if (serialnum != num) {
                tempFile << "\n" << serialnum;
                tempFile << "\n" << ename;
                tempFile << "\n" << quantity;
               
            }
            else {
                tempFile << "\n"<<serialnum;
                tempFile << "\n"<<name;
                tempFile << "\n"<<newquantity;
               
            }
        }
        read.close();
        tempFile.close();
        remove("equipment.txt");
        rename("temps.txt","equipment.txt");
        cout << "\n\tData updated successfuly"<<endl;
    }
    else {
    		system("cls");
        cout << "\n\tRecord not updated";
    }
}
    void updatequantity(int newquantity, char choice,int s)
 {
    int num=searchequipmentstt(s);
    
    if (choice == 'y') {
       
        
        
        ofstream tempFile;
        tempFile.open("temps.txt");
        ifstream read;
        read.open("equipment.txt");
        while (!read.eof()) {
            read >>serialnum;
            read.ignore();
            getline(read,ename);
            read >>quantity;
           
            if (serialnum != num) {
                tempFile << "\n" << serialnum;
                tempFile << "\n" << ename;
                tempFile << "\n" << quantity;
               
            }
            else {
            	int temp=quantity-newquantity;
            	//cout<<temp<<"+++++";
                tempFile << "\n"<<serialnum;
                tempFile << "\n"<<ename;
                tempFile << "\n"<<temp;
               
            }
        }
        read.close();
        tempFile.close();
        remove("equipment.txt");
        rename("temps.txt","equipment.txt");
       // cout << "\n\tData updated successfully"<<endl;
    }
    else {
    		system("cls");
        cout << "\n\tRecord not updated";
    }
}

};
class student
{
	int id;
	string name;
	int age;
	string department;
	string eqipment;
	int serialno;
	int quantity;
	string date;

	public:
		int addstudent(int num)
		{
				cout<<"\nEnter a student id-";
			cin>>id;
			cout<<"Enter a student name-";
			cin.get();
			getline(cin,name);
			cout<<"Enter student age-";
			cin>>age;
			cout<<"Enter a student department-";
			cin.get();
			getline(cin,department);
            
			eqipment=labequipment;
			serialno=num;
			cout<<"Enter a quantity of equipment-";
			cin>>quantity;
				cout<<"Enter issueing date-";
			cin.get();
			getline(cin,date);
		
			ofstream write;
			write.open("student.txt",ios::app);
			write<<"\n"<<id;
			write<<"\n"<<name;
			write<<"\n"<<age;
			write<<"\n"<<department;
				write<<"\n"<<'.';
			write<<eqipment;
			write<<"\n"<<serialno;
			write<<"\n"<<quantity;
			write<<"\n"<<date;
			write.close();
            cout << "\n\tData save to file"<<endl;
            return quantity;
			
		}
		void printdetails() {
             cout << "\n\t---Stuent Data---";
               cout << "\n\tID is : " << id;
             cout << "\n\tName is : " <<name;
             cout << "\n\tAge is : " <<age;
           cout << "\n\tDepartement: " <<department;
             cout << "\n\tEqipment details : " <<eqipment;
            cout << "\n\tSerial no. : " <<serialno;
             cout << "\n\tEquipment Quantity : " <<quantity;
              cout << "\n\tIssuing Date : " <<date<<endl;

             }
int  readData()
 { ifstream read;
              read.open("student.txt");
           while (!read.eof()) {
           read >> id;
         read.ignore();
        getline(read, name);
          read >>age;
       // read >>department;
         read.ignore();
        getline(read,department);
         //  read>>eqipment ;
            read.ignore();
        getline(read, eqipment);
        read>>serialno;
        read>>quantity;
        read.ignore();
        getline(read, date);
        if(last==id||date.empty())
        {
        	cout<<"List is Empty"<<endl;
        	read.close();
        	return 1;
		}
        printdetails();
    }
    read.close();
    
}
int searchData() 
{
    int num,count=0;
    cout << "\n\tEnter a student id : ";
    cin >>num;
   
   ifstream read;
              read.open("student.txt");
           while (!read.eof()) {
           read >> id;
           if(id==0)
           {
           	cout<<"\tYour list is empty"<<endl;
           	read.close();
           	break;
		   }
         read.ignore();
        getline(read, name);
          read >>age;
        read.ignore();
        getline(read,department);
          read.ignore();
        getline(read,eqipment);
        read>>serialno;
        read>>quantity;
         read.ignore();
        getline(read,date);
        if(num==id)
        {
        	read.close();
		count=1;
        printdetails();
        return id;
		}
    }
    if(count==0)
    {
		system("cls");
    cout<<"Your Record Not Found!!!"<<endl;
    read.close();
    return -1;
}
}
int deleteData()
 {
    
    int ids= searchData();
    if(ids==-1)
    {
    	cout<<"Record not found"<<endl;
    	return -1;
	}
    cout << "\n\tYou want to delete record (y/n) : ";
    char choice;
    cin >> choice;
   // cout<<ids;
  //  cout<<x;
    if (choice == 'y') {
          ofstream tempFile;
        tempFile.open("temp.txt");
          ifstream read;
        read.open("student.txt");
      while (!read.eof()) {
              read >>id;
              read.ignore();
               getline(read,name);
            read >>age;
              read.ignore();
               getline(read,department);
             read.ignore();
               getline(read,eqipment);
            read>>serialno;
            read >>quantity;
           read.ignore();
        getline(read,date);
           
          // cout<<id;
            if (ids != id) {
                  tempFile << "\n" <<id;
                 tempFile << "\n" <<name;
                 tempFile << "\n" <<age;
                  tempFile << "\n" <<department;
                  tempFile << "\n" <<eqipment;
                tempFile<<"\n"<<serialno;
                  tempFile << "\n" <<quantity;
                tempFile<<"\n"<<date;
                
            }
              
        
            
        }
        read.close();
       tempFile.close();
        remove("student.txt");
         rename("temp.txt", "student.txt");
         last=ids;
        cout << "\n\tData deleted successfuly"<<endl;  
      
    }
    else {
    		system("cls");
        cout << "\n\tRecord not deleted";
    }
}
int updateData() 
{
    int ids = searchData();
    if(ids==-1)
    {
    	cout<<"Record Not Updated!!!"<<endl;
    	return -1;
	}
    cout << "\n\tYou want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
    	string newname,newdepartment,neweqipment,newdate;
      	int newserialno,newage,newquantity;
        cout << "\n\tEnter student name : ";
          cin.get();
        getline(cin,newname);
        cout << "\n\tEnter student age : ";
         cin >>newage;
        cout << "\n\tEnter student department : ";
         cin.get();
        getline(cin,newdepartment);
          cout << "\n\tEnter student eqipment details : ";
           cin.get();
        getline(cin,neweqipment);
        cout << "\n\tEnter serial no : ";
           cin >>newserialno;
           cout << "\n\tEnter Quantity : ";
           cin >>newquantity;
            cout << "\n\tEnter new date : ";
          cin.get();
        getline(cin,newdate);
        ofstream tempFile;
           tempFile.open("temp.txt");
        ifstream read;
        read.open("student.txt");
        while (!read.eof()) {
             read >>id;
            read.ignore();
              getline(read,name);
            read >>age;
              // read >> department;
                read.ignore();
              getline(read,department);
           // read >>eqipment;
             read.ignore();
              getline(read,eqipment);
            read>>serialno;
            read>>quantity;
             read.ignore();
              getline(read,date);
            
            if (ids!= id) {
                tempFile << "\n" << id;
                tempFile << "\n" << name;
                   tempFile << "\n" << age;
                  tempFile << "\n" <<department;
                tempFile << "\n" <<eqipment;
                tempFile<<"\n"<<serialno;
                 tempFile << "\n" <<quantity;
                tempFile<<"\n"<<date;
                
            }
            else {
                 tempFile << "\n" << id;
                 tempFile << "\n" << newname;
                  tempFile << "\n" << newage;
                tempFile << "\n" <<newdepartment;
                   tempFile << "\n" <<neweqipment;
                tempFile<<"\n"<<newserialno;
                 tempFile << "\n" <<newquantity;
                tempFile<<"\n"<<newdate;
            }
        }
        read.close();
          tempFile.close();
        remove("student.txt");
           rename("temp.txt", "student.txt");
        cout << "\n\tData updated successfuly"<<endl;
    }
    else {
    		system("cls");
        cout << "\n\tRecord not Updated";
    }
}
};
int login()
{
	int count;
	string userid,password,id,pass;
//	system("cls");
	cout<<"\t\tPlease enter your username and password-"<<endl;
	cout<<"\t\tUSERNAME-";
	cin>>userid;
	cout<<"\t\tPASSWORD-";
	cin>>password;
	ifstream input("record.txt");
	while(input>>id>>pass)
	{
		if(id==userid&&pass==password)
		{
			count=1;
		//	system("cls");
		}
	}
	input.close();
	if(count==1)
	{    	system("cls");
		cout<<"\t\tYou login is successfully"<<endl;
	
		cout<<"#######################WELCOME-"<<userid<<"############################ "<<endl;
			return 1;
	}
	else
	{
			system("cls");
			cout<<"\t\tLogin error please check your password and username"<<endl;
			return 0;
	}
	
}
void registration()
{
		string ruserid,rpassword,rid,rpass;
		//system("cls");
		cout<<"\t\t\tEnter a username-";
		cin>>ruserid;
		cout<<"\t\t\tEnter a password-";
		cin>>rpassword;
		
		ofstream f1("record.txt",ios::app);
		f1<<ruserid<<' '<<rpassword<<endl;
			system("cls");
		cout<<"\t\t\tRegistration is successful!!!\n"<<endl;
	}
void forgot()
{
	int option;
//	system("cls");
		do
		{
		
    cout<<"press 1 to Search your password by username"<<endl;
    cout<<"press 2 for Go Back"<<endl;
	cout<<"\t\t\tEnter your choice-";
	cin>>option;
	
	
	
	switch(option)
	{
		case 1:
		{
				system("cls");
		int count=0;
		string suserid,sid,spass;
		cout<<"\t\t\tEnter the username which you rememberd:";
		cin>>suserid;
		ifstream f2("record.txt");
		while(f2>>sid>>spass)
		{	
		     if(sid==suserid)
				count=1;
     	}           
		if(count==1)
		{
				system("cls");
		
			cout<<"\n\nYour account is found!!!!\n";
			cout<<"\n\nYour password is-"<<spass<<endl;	
		}
		else
		{
				system("cls");
		cout<<"\t\tSorry your account is not found!!\n"<<endl;
	}
	}
	case 2:
		break;
	default:
		cout<<"Please Enter correct choice"<<endl;
}
}while(option!=2);
}
int main()
{
	
   int choice,ch,c;
	student s;
	equipment A;
	 ifstream read;
    read.open("id.txt");
    if (!read.fail()) {
        read >>idg;
    }
    else {
        idg = 0;
    }
    read.close();
    cout<<"************ WELCOME TO GCEK LABROTARY MANAGEMENT SYSTEM ************\n";
     cout<<"*********************************************************************"<<endl;
      cout<<"*********************************************************************"<<endl;

    
    cout<<"*********************************************************************"<<endl;
    do
    {
    cout<<"*************************     MAIN MENU     ************************"<<endl;
    cout<<"\t\t1.Labrotary Incharge Section"<<endl;
    cout<<"\t\t2.Student Section"<<endl;
    cout<<"\t\t3.Close Window"<<endl;
    cout<<endl;
    cout<<"Enter Your Choice=";
    cin>>choice;
    switch(choice)
    {
    	case 1:
    
        		system("cls");
        		do{
	cout<<"_________________________________________________________________"<<endl;
	cout<<"\t\t\tWELCOME TO LOGIN PAGE"<<endl;
	cout<<"_________________________________________________________________"<<endl;
	cout<<"\t1.Login"<<endl;
	cout<<"\t2.Register"<<endl;
	cout<<"\t3.Forgot password"<<endl;
	cout<<"\t4.Go to main menu"<<endl;
	cout<<"\t\tEnter your choice-";
	cin>>c;
	cout<<endl;

	
	switch(c)
	{
		case 1:
				system("cls");
			{
			
			if(login())
			{	
			do{
			  cout<<"                ##**YUOR CHOICES**##                        "<<endl;
		   	cout<<"\t\t1.See Student List"<<endl;
             cout<<"\t\t2.Search Student Recrod"<<endl;
             cout<<"\t\t3.Delete Student Record"<<endl;
             cout<<"\t\t4.Update Student Record"<<endl;
             cout<<"\t\t5.Add New Equipment Into List"<<endl;
            cout<<"\t\t6.Show Equipment List"<<endl;
             cout<<"\t\t7.Delete Equipement Record Into List"<<endl;
            cout<<"\t\t8.Edit Equipment Details"<<endl;
            cout<<"\t\t9.Serch Equipment Avalilability"<<endl;
            cout<<"\t\t10.LOGOUT"<<endl;
            cout<<endl;
    cout<<"Enter Your Choice=";
    cin>>ch;
    switch(ch)
    {
    
    	case 1:
    			system("cls");
    		s.readData();
    		break;
    	case 2:
    			system("cls");
    		s.searchData();
    		break;
    	case 3:
    		system("cls");
    		s.deleteData();
    		break;
    	case 4:
    			system("cls");
    		s.updateData();
    		break;
    	case 5:
    			system("cls");
    		A.addeuipment();
    		break;
    	case 6:
    			system("cls");
    		A.list();
    		break;
    	case 7:
    			system("cls");
    		A.deleteequipment();
    		break;
    	case 8:
    		A.update();
    		break;
    	case 9:
    			system("cls");
    		A.searchequipment();
    		break;
    	case 10:
    			system("cls");
    		cout<<"Logout Successfully Thank You!!!"<<endl;
    		break;
    	default:
    			system("cls");
    		cout<<"You are enter wrong choice,please enter a correct choice"<<endl;
    	
    	}
    cout<<"##############################################"<<endl;
    cout<<endl;
}while(ch!=10);
}
else
cout<<"\t\t\tPlease try again"<<endl;
}
			break;
		case 2:
				system("cls");
			registration();
			break;
		case 3:
				system("cls");
			forgot();
			break;
		case 4:
				system("cls");
		    cout<<"Thank You"<<endl;
		    break;
		default:
				system("cls");
			
			cout<<"Please enter correct choice"<<endl;
			
	}
}while(c!=4);
		
    
    		break;
    	case 2:
    		system("cls");
    		cout<<"________________________WELCOME TO STUDENT SECTION____________________________"<<endl;
    		cout<<"                            **Your Choices**                                       "<<endl;
    		do{
			
		  
    cout<<"\t\t1.Issue New Eqipment"<<endl;
    cout<<"\t\t2.Search Your Issueing Eqipment  Recrod"<<endl;
    cout<<"\t\t3.Show Equipment List In Labrotary"<<endl;
    cout<<"\t\t4.Search A Particular Equipment"<<endl;
    cout<<"\t\t5.Go to Main Menu"<<endl;
            cout<<endl;
    cout<<"Enter Your Choice=";
    cin>>ch;
    switch(ch)
    {
    
    	case 1:
    	   {system("cls");
    	   	int r,x,y;
    	   	cout<<"Enter a Equipment Serial No-";
    	   	cin>>r;
    	   		y=A.searchequipmentst(r);
    	   		if(y==-1)
    	   		{
    	   				system("cls");
    	   			cout<<"\tSorry Equipment Not Found!!!"<<endl;
    	   			break;
				   }
			x=s.addstudent(r);
    	    int dia=issue;
    	    A.updatequantity(dia,'y',r);
    		break;
    	}
    	case 2:
    		system("cls");
    		s.searchData();
    		break;
    	case 3:
    			system("cls");
    		A.list();
    		break;
    	case 4:
    			system("cls");
    	A.searchequipment();
    		break;
    	case 5:
    			system("cls");
    		cout<<"Thank You"<<endl;
    		break;
    	default:
    			system("cls");
    		cout<<"You are enter wrong choice,please enter a correct choice"<<endl;
    	
    	}
    cout<<"##############################################"<<endl;
    cout<<endl;
}while(ch!=5);
    		break;
    	case 3:
    			system("cls");
            cout<<"\tWINDOW CLOSED SUCCESSFULLY THANK YOU!!!"<<endl;
    		break;
    	default:
    			system("cls");
    		cout<<"You are enter wrong choice,please enter a correct choice"<<endl;
    	
    	}
    cout<<"********************************************************************"<<endl;
    cout<<endl;
}while(choice!=3);
	
	
}
