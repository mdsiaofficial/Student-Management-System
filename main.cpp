#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <conio.h>
#define pi 3.14159
#define forn(i, n) for (int i = 0; i < int(n); i++)

#define nl endl
#define ll long long
#define ld long double
#define ull unsigned long long
#define mod 90000007
#define fs(n) fixed << setprecision(int(n))
#define s(n) setprecision(int(n))
using namespace std;

class student
{
private:
    string name, roll, course, address, email, contact;

public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleteData();
};

void student::insert()
{
    system("cls");

    fstream file;
    cout << "\n";
    cout << "\t\t-------------------------------------\n";
    cout << "\t\t|---       Add Student Data      ---|\n";
    cout << "\t\t-------------------------------------\n";
    cout << "\t\tEnter Name: ";
    cin >> name;
    cout << "\t\tEnter Roll: ";
    cin >> roll;
    cout << "\t\tEnter Course: ";
    cin >> course;
    cout << "\t\tEnter Contact: ";
    cin >> contact;
    cout << "\t\tEnter Email: ";
    cin >> email;
    cout << "\t\tEnter Address: ";
    cin >> address;

    file.open("studentdata.txt", ios::app | ios::out);
    file << " " << name << " " << roll << " " << course << " " << email << " " << contact << " " << address << endl;
    file.close();
}

void student::display()
{
    string name, roll, course, address, email, contact;
    int total = 1;
    system("cls");
    fstream file;
    cout << "\t\t-------------------------------------\n";
    cout << "\t\t|---     Display Student Data    ---|\n";
    cout << "\t\t-------------------------------------\n";

    file.open("studentdata.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t No data found!!!\n";
        file.close();
    }
    else
    {
        // file >> name >> roll >> course >> email >> contact >> address;
        while (!file.eof())
        {
            cout << "\n\n\t\t|---     Student Data    ---|\n";
            cout << "\t\tStudent No: " << total++ << endl;
            cout << "\t\tStudent Name: " << name << endl;
            cout << "\t\tStudent Roll: " << roll << endl;
            cout << "\t\tStudent Course: " << course << endl;
            cout << "\t\tStudent Email: " << email << endl;
            cout << "\t\tStudent Contact: " << contact << endl;
            cout << "\t\tStudent Address: " << address << endl;
            file >> name >> roll >> course >> email >> contact >> address;
        }

        if (total == 0)
        {

            cout << "\n\t\t No data found!!!\n";
        }
    }

    file.close();
}

void student::modify()
{
    system("cls");
    fstream file, file1;

    cout << endl;
    cout << "\t\t-------------------------------------\n";
    cout << "\t\t|---     Student Data Modify     ---|\n";
    cout << "\t\t-------------------------------------\n";

    string roll_select;
    int found = 0;
    file.open("studentdata.txt", ios::in);

    if (!file)
    {
        cout << "\n\t\t No data found!!!\n";
        file.close();
    }
    else
    {
        cout << "\nEnter roll no to select student: ";
        cin >> roll_select;

        file1.open("data.txt", ios::app | ios::out);

        file >> name >> roll >> course >> email >> contact >> address;
        while (!file.eof())
        {
            if (roll != roll_select)
            {
                file1 << " " << name << " " << roll << " " << course << " " << email << " " << contact << " " << address << endl;
            }
            else
            {
                cout << "\t\tEnter Name: ";
                cin >> name;
                cout << "\t\tEnter Roll: ";
                cin >> roll;
                cout << "\t\tEnter Course: ";
                cin >> course;
                cout << "\t\tEnter Contact: ";
                cin >> contact;
                cout << "\t\tEnter Email: ";
                cin >> email;
                cout << "\t\tEnter Address: ";
                cin >> address;

                file1 << " " << name << " " << roll << " " << course << " " << email << " " << contact << " " << address << endl;

                found++;
            }

            file >> name >> roll >> course >> email >> contact >> address;
            if (found == 0)
            {
                cout << "\t\tStudent Roll not found.\n";
            }
        }

        file1.close();
        file.close();
        remove("studentdata.txt");
        rename("data.txt", "studentdata.txt");
    }
}

void student::search(){
    system("cls");
    fstream file;
    int found=0;
    file.open("studentdata.txt", ios::in);
    if(!file){
        
        cout << endl;
        cout << "\t\t-------------------------------------\n";
        cout << "\t\t|---     Student Data Search     ---|\n";
        cout << "\t\t-------------------------------------\n";

        cout<<"\n\n\t\t------     No data found    -----\n";


    }else{
        string roll_select;

            
        cout << endl;   
        cout << "\t\t-------------------------------------\n";
        cout << "\t\t|---     Student Data Modify     ---|\n";
        cout << "\t\t-------------------------------------\n";

        cout<<"\t\tEnter Student Roll no. to search: ";
        cin>>roll_select;

        file >> name >> roll >> course >> email >> contact >> address;

        while(!file.eof()){
            if(roll == roll_select){
                cout << "\n\n\t\t|---     Student Data    ---|\n";
                cout << "\t\tStudent Name: " << name << endl;
                cout << "\t\tStudent Roll: " << roll << endl;
                cout << "\t\tStudent Course: " << course << endl;
                cout << "\t\tStudent Email: " << email << endl;
                cout << "\t\tStudent Contact: " << contact << endl;
                cout << "\t\tStudent Address: " << address << endl;

                found++;
            }
            file >> name >> roll >> course >> email >> contact >> address;
        }

        if(found == 0){
            cout<<"\n\t\tNo data found!!!";
        }

        file.close();
    }
}

void student::deleteData(){
    system("cls");
    fstream file, file1;
    int found = 0;
    cout << endl;
    cout << "\t\t-------------------------------------\n";
    cout << "\t\t|---     Student Data Delete     ---|\n";
    cout << "\t\t-------------------------------------\n";

    file.open("studentdata.txt", ios::in);

    if(!file){
        cout<<"\n\t\tNo data found...\n";
    }else{
        string roll_select;

            
        cout << endl;   
        cout << "\t\t-------------------------------------\n";
        cout << "\t\t|---     Student Data Delete     ---|\n";
        cout << "\t\t-------------------------------------\n";

        cout<<"\t\tEnter Student Roll no. to search: ";
        cin>>roll_select;

        file1.open("data.txt", ios::app | ios::out);

        file >> name >> roll >> course >> email >> contact >> address;

        while(!file.eof()){
            if(roll != roll_select){
                file1 << " " << name << " " << roll << " " << course << " " << email << " " << contact << " " << address << endl;
            }

            file >> name >> roll >> course >> email >> contact >> address;
        }
        cout << "\n\n\t\t|---     Student Data Deleting   ---|\n";
        cout << "\t\tStudent Name: " << name << endl;
        cout << "\t\tStudent Roll: " << roll << endl;
        cout << "\t\tStudent Course: " << course << endl;
        cout << "\t\tStudent Email: " << email << endl;
        cout << "\t\tStudent Contact: " << contact << endl;
        cout << "\t\tStudent Address: " << address << endl;
        cout<<"\n\n\t\t### Data deleted ###\n\n";

        if(found == 0){
            cout<<"\n\t\tNo data avaiable with roll: "<<roll_select<<endl;
        }

        file.close();
        file1.close();
        remove("studentdata.txt");
        rename("data.txt", "studentdata.txt");
    }
    
}

void student::menu()
{

menustart:
    int choice;
    char x;
    system("cls");

    cout << "\t\t-------------------------------------\n";
    cout << "\t\t|---  Student Management System  ---|\n";
    cout << "\t\t-------------------------------------\n";

    cout << "\t\t1. Enter new record\n";
    cout << "\t\t2. Display record\n";
    cout << "\t\t3. Modify record\n";
    cout << "\t\t4. Search record\n";
    cout << "\t\t5. Delete record\n";
    cout << "\t\t6. Exit\n";
    cout << "\t\t-------------------------------------\n";
    cout << "\t\t|---   Choose option:[ 1 - 6 ]   ---|\n";
    cout << "\t\t-------------------------------------\n";
    cout << "\t\tEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n\t\tAdd Another Student Data(Y/N): ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        // insert();
        break;
    case 2:
        display();
        break;

    case 3:
        modify();
        break;

    case 4:
        search();
        break;
    case 5:
        deleteData();
        break;

    case 6:
        exit(0);

    default:
        cout << "\n\t\t Invalid selection...Try again.\n";
        // break;
    }
    getch();
    goto menustart;
}

int main()
{

    student stu;
    stu.menu();

    return 0;
}
