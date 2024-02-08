#include <iostream>
#include<fstream>
#include<windows.h>
using namespace std;
struct student
{
	public:
	char name[20];
	char id[10];
	float obj,sof,web,ope,sum,average;
};
void intro();
void mainmenu();
void acceptdata();
void view_Specific(int);
void viewall();
void result(int);
void deleterecord(int);
void modify(int);

int main()
{
    system("color a");
    char c;
    system("cls");
    intro();

    do{
   system("cls");
   system("color e");
   cout<<"\n\n";
   cout<<"\t====================STUDENT RECORD MANEGEMENT SYSTEM===================="<<endl;
   cout<<endl;
   cout<<"\t\t\t\t1. MAIN MENU\n\n";
   cout<<"\t\t\t\t2. EXIT\n\n";
   cout<<"ENTER YOUR CHOICE :";
   cin>>c;
   system("cls");
   switch(c)
   {
   case '1':
    {
        mainmenu();
        break;
    }
   case '2':
    {          cout << "\t\t     WELCOME!   "<<endl;

        cout << "\n\n";
             cout<<"\t   GROUP MEMBERS";
             cout << "\n\n";
             cout << "\t   NAME                               ID           PHONE NUMBER \n\n";
             cout << "\t   1. STEPHANIE MURUTU             22-1187        +25474600560   \n\n";
             cout << "\t   2. DEXTER BOSIRE                22-0771        +25474640004    \n\n";
             cout << "\t   3. MUSHY CUTHBERT               22-1142        +25562020673     \n\n";
             cout << "\t   4. MARAGUA ANDREW               20-0287        +25462546778     \n\n";
             cout << "\t   5. CHAID OKALO                  22-3624        +25434578993      \n\n";
              cout << "\n\n";
             cout<<"\t\t\t\t\t\t\t\t\t   SUBMITED TO:   FREDRICK OGORE \n";
             cout<<"\t\t\t\t\t\t\t\t\t   SUBMITED DATE: 12/01/2023 ";

              cout << "\n\n";
    }
   }
    }while(c!='2');
    return 0;
}
void acceptdata()
{
    system("cls");
    student s;
    ofstream outfile;
    outfile.open("Report.txt",ios::app|ios::binary);
    if(outfile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPEN...press enter key";
        cin.ignore();
        cin.get();
    }
    cout<<"\n\n";
    cout<<"\t\t\t\t=======CREATE A REPORT CARD========\n\n";
    cout<<"ENTER YOUR FULL NAME :";
    cin.ignore();
    cin.getline(s.name,20);
    cout<<"ENTER YOUR ID NUMBER : GUE/";
    cin.ignore();
    cin.get(s.id,10);
    cout<<"ENTER YOUR OBJECT ORIENTED PROGRAMMING MARK :";
    cin>>s.obj;
    cout<<"ENTER YOUR SOFTWARE ENGINEERING MARK :";
    cin>>s.sof;
    cout<<"ENTER YOUR WEB TECHNOLOGIES MARK :";
    cin>>s.web;
    cout<<"ENTER YOUR OPERATING SYSTEMS MARK :";
    cin>>s.ope;
    s.sum=s.obj+s.sof+s.web+s.ope;
    s.average=(s.sum/4);
    outfile.write(reinterpret_cast<char *> (&s), sizeof(student));
    outfile.close();
    cout<<endl;
    cout<<"\t\t\t\tTHE FILE IS SUCCESSFULLY SAVED"<<endl;
    cout<<endl;
    cout<<"press any key to continue...";
    cin.ignore();
    cin.get();
}

void intro()

{

    cout << "\n\n\n";
    Sleep(300);
    cout << "\t\t\t\t ***   ***   ***   " << endl;
    Sleep(300);
    cout << "\t\t\t\t ***  ***  ***   "<< endl;
    Sleep(300);
    cout << "\t\t\t\t ***   ***  ***    " << endl;
    Sleep(300);
    cout << "\t\t\t\t ***   ***   ***   " << endl;
    Sleep(300);
    cout << "\t\t\t\t  ***  ***   **** " << endl;
    Sleep(300);
    cout<<endl;
    cout<<"\t\t\t\t============================================="<<endl;
    Sleep(500);
    cout<<"\t\t\t\tTHIS IS STUDENT RECORD MANEGEMENT SYSTEM"<<endl;
    Sleep(500);
    cout<<"\t\t\t\t============================================="<<endl;
    Sleep(500);
    cout<<"press any key to continue...";
    cin.ignore();
    cin.get();
}

void mainmenu()

{
    system("color c");
    char cc;
    cout<<"\t\t\t\t=================MAIN MENU================\n\n"<<endl;
    Sleep(300);
    cout<<"\t\t\t\t1. CREATE STUDENT REPORT CARD\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t\t2. VIEW ALL STUDENTS REPORT CARD\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t\t3. VIEW A SINGLE STUDENT REPORT CARD\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t\t4. MODIFY REPORT CARD\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t\t5. RESULT\n\n"<<endl;
     Sleep(300);
     cout<<"\t\t\t\t6. DELETE RECORD\n\n"<<endl;
     Sleep(300);
    cout<<"\t\t\t\t=============================="<<endl;
     Sleep(300);
    cout<<"\t\t\t\tENTER YOUR CHOICE...:) <1-6> :";
     Sleep(300);
    cin>>cc;
    cout<<endl;
    switch(cc)
    {
    case '1':
        {
            acceptdata();
            break;
        }
    case '2':
        {
            viewall();
            break;
        }
    case '3':
          {
              int n;
              cout<<"ENTER YOUR NUMBER OF CHOICE :";
              cin>>n;
              view_Specific(n);
              break;
          }
    case '4':
        {
            int n;
            cout<<"ENTER YOUR NUMBER OF CHOICE :";
            cin>>n;
            modify(n);
            break;
        }

    case '5':
        {
            int n;
            cout<<"ENTER YOUR NUMBER OF CHOICE :";
            cin>>n;
            cout<<endl;
            result(n);
            break;
        }
    case '6':
        {
            int n;
            cout<<"ENTER YOUR NUMBER OF CHOICE :";
            cin>>n;
            cout<<endl;
            deleterecord(n);
            break;
        }
    }
}

void viewall()

{
    system("cls");
    student s;
    ifstream infile;
    bool check=false;
    infile.open("Report.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED.....press enter key...";
        cin.ignore();
        cin.get();
    }
     cout<<"\n\n";
     cout<<"\t\t\t\t ALL STUDENTS REPORT CARDS"<<endl;
     cout<<"=================================================================================="<<endl;
    while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
    {
        cout<<"\t\t\t\t STUDENT NAME :"<<s.name<<endl<<endl;
        cout<<"\t\t\t\t STUDENT ID NUMBER :GUE/"<<s.id<<endl<<endl;
        cout<<"\t\t\t\t OBJECT ORIENTED PROGRAMMING MARK :"<<s.obj<<endl<<endl;
        cout<<"\t\t\t\t SOFTWARE ENGINEERING MARK :"<<s.sof<<endl<<endl;
        cout<<"\t\t\t\t WEB TECHNOLOGIES MARK :"<<s.web<<endl<<endl;
        cout<<"\t\t\t\t OPERATING SYSTEMS MARK :"<<s.ope<<endl<<endl;
        cout<<"\t\t\t\t SUM :"<<s.sum<<endl<<endl;
        cout<<"\t\t\t\t AVERAGE :"<<s.average<<endl<<endl;
        cout<<"=================================================================================="<<endl;
        check=true;
    }
    infile.close();
    if(check==false)
    cout<<"\t\t\t\t NO RECORD FOUND..."<<endl<<endl;
    cout<<"press any key to continue....";
    cin.ignore();
    cin.get();
}

void view_Specific(int n)

{
    system("cls");
    student s;
    ifstream infile;
    infile.open("Report.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED...";

        cin.ignore();
        cin.get();
    }
    bool equality=false;
    cout<<"\t\t\t\t==========VIEW A SINGLE STUDENT REPORT==========\n\n";
    while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
    
        {
        cout<<"\t\t\t\t STUDENT NAME :"<<s.name<<endl;
        cout<<"\t\t\t\t STUDENT ID NUMBER :GUE/"<<s.id<<endl;
        cout<<"\t\t\t\t OBJECT ORIENTED PROGRAMMING MARK :"<<s.obj<<endl<<endl;
        cout<<"\t\t\t\t SOFTWARE ENGINEERING MARK :"<<s.sof<<endl<<endl;
        cout<<"\t\t\t\t WEB TECHNOLOGIES MARK :"<<s.web<<endl<<endl;
        cout<<"\t\t\t\t OPERATING SYSTEMS MARK :"<<s.ope<<endl<<endl;
        cout<<"\t\t\t\t SUM :"<<s.sum<<endl;
        cout<<"\t\t\t\t AVERAGE :"<<s.average<<endl;
        cout<<"\t\t\t\t================================================"<<endl;
        equality=true;
        }
    }
        
        
            
            
            

void result(int n)

{
    system("cls");
    student s;
    ifstream infile;
    infile.open("Report.txt",ios::app|ios::binary);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
        cin.ignore();
        cin.get();
    }
    bool eq=false;
    cout<<"\t\t\t\t===========VIEW A SINGLE STUDENT RESULT==========\n\n";
    while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
    
        
        {
        cout<<"\t\t\t\t STUDENT NAME :"<<s.name<<endl<<endl;
         cout<<"\t\t\t\t OBJECT ORIENTED PROGRAMMING MARK :"<<s.obj<<endl<<endl;
        cout<<"\t\t\t\t SOFTWARE ENGINEERING MARK :"<<s.sof<<endl<<endl;
        cout<<"\t\t\t\t WEB TECHNOLOGIES MARK :"<<s.web<<endl<<endl;
        cout<<"\t\t\t\t OPERATING SYSTEMS MARK :"<<s.ope<<endl<<endl;
        cout<<"\t\t\t\t SUM :"<<s.sum<<endl<<endl;
        cout<<"\t\t\t\t AVERAGE :"<<s.average<<endl<<endl;
        cout<<"\t\t\t\t=================================================="<<endl;
        eq=true;
        }
    }
        
        
            
           

void modify(int n)

{
    system("cls");
    student s;
    fstream infile;
    infile.open("Report.txt",ios::binary|ios::in|ios::out);
    if(infile.fail())
    {
        cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
        cin.ignore();
        cin.get();
    }
     bool checker=false;
     cout<<"\t\t\t\t==========MODIFY A REPORT CARD==========\n\n";
     while(!infile.eof() && checker==false)
     {
     infile.read(reinterpret_cast<char*>(&s),sizeof(student));
     
         {
        cout<<"\t\t\t\t STUDENT NAME :"<<s.name<<endl<<endl;
        cout<<"\t\t\t\t STUDENT ID NUMBER :GUE/"<<s.id<<endl<<endl;
        cout<<"\t\t\t\t OBJECT ORIENTED PROGRAMMING MARK :"<<s.obj<<endl<<endl;
        cout<<"\t\t\t\t SOFTWARE ENGINEERING MARK :"<<s.sof<<endl<<endl;
        cout<<"\t\t\t\t WEB TECHNOLOGIES MARK :"<<s.web<<endl<<endl;
        cout<<"\t\t\t\t OPERATING SYSTEMS MARK :"<<s.ope<<endl<<endl;
        cout<<"============================================="<<endl;
        cout<<"\t\tENTER THE NEW INFORMATION"<<endl;
        cout<<"============================================="<<endl;
        cout<<"ENTER YOUR FULL NAME :";
    cin.ignore();
    cin.getline(s.name,20);
    cout<<"ENTER YOUR ID NUMBER : GUE/";
    cin.ignore();
    cin.get(s.id,10);
    cout<<"ENTER YOUR OBJECT ORIENTED PROGRAMMING MARK :";
    cin>>s.obj;
    cout<<"ENTER YOUR SOFTWARE ENGINEERING MARK :";
    cin>>s.sof;
    cout<<"ENTER YOUR WEB TECHNOLOGIES MARK :";
    cin>>s.web;
    cout<<"ENTER YOUR OPERATING SYSTEMS MARK :";
    cin>>s.ope;
    s.sum=s.obj+s.sof+s.web+s.ope;
    s.average=(s.sum/4);
    int pos=(-1)*static_cast<int>(sizeof(student));
    infile.seekp(pos,ios::cur);
    infile.write(reinterpret_cast<char *> (&s), sizeof(student));
    cout<<endl;
    cout<<"\t\t\t\t THE FILE IS SUCCESSFULLY updated"<<endl;
    checker=true;
         }
     }
     }
        
          
  

  void deleterecord(int n)

  {
     system("cls");
     student s;
     ifstream infile;
     infile.open("Report.txt",ios::binary);
     if(!infile)
     {
         cout<<"THE FILE COULD NOT BE OPENED..."<<endl;
         cin.ignore();
         cin.get();
     }
     ofstream outfile;
     outfile.open("Record2.txt",ios::binary);
     infile.seekg(0,ios::beg);
     cout<<"\t\t\t\t===========DELETE A REPORT CARD==========\n\n";
     while(infile.read(reinterpret_cast<char*>(&s),sizeof(student)))
    


infile.close();
     outfile.close();
     remove("Report.txt");
     rename("Record2.txt","Report.txt");
     cout<<endl;
     cout<<"\t\t\t\tRECORD SUCCESSFULLY DELETED"<<endl;
     cout<<"press any key to continue...";
     cin.ignore();
     cin.get();
  }