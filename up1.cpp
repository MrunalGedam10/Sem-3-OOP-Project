
#include <iostream>
using namespace std;
class account
{
private:
    string name, ty;
    int acno;
    float balance , depo, with, pin, pin1;

public:
    account(){balance=0;}
    void getdata()
    {
        // cout<<"\nEnter the account details"<<endl;
        cout << "Enter the name of depositer: " << endl;
        cin >> name;
        cout << "Enter the account type: " << endl;
        cin >> ty;
        cout << "Enter account number: " << endl;
        cin >> acno;
        cout << "Enter your pin: " << endl;
        cin >> pin;
    }
    void D()
    {
        cout << "Enter the deposited amount : " << endl;
        cin >> depo;
        balance = balance + depo;
    }
    void withdraw()
    {
        cout << "\nEnter the amount withdrawn : " << endl;
        cin >> with;
        balance = balance - with;
    }
    void B(int pin2)
    {
        
        if (pin2 == pin)
        {
            cout << "\nThe balance of " << name << "is : " << balance << endl;
            
        }
        else
        {
            cout << "\nEnterd pin is incorect please enter corect pin!" << endl;
        }
        
    }
    void display()
    {
        cout << "\nAccount details of " << name << " are : " << endl;
        cout << "name :" << name;
        cout << "Account no.: " << acno << endl;
        cout << "Account Type : " << ty << endl;
    }
    int find(int a)
    {
        if (a == acno)
        {
            return 1;
        }
    }
    int exist(int a)
    {
        if (a != 0)
        {
            return 1;
        }
        else if (a == 1)
        {
            return 0;
        }
    }
};
class card:public account
{
private:
    
public:
    
};

int getpin()
{   int pin1; 
    cout << "\nPlease enter the pin :" << endl;
        cin >> pin1;
        return pin1;
}

int main()
{
    int ch = 0, i, j = 0, acno1, n, acno, pin1;
    account ac[100];
    while (ch != 6)
    {
        system("CLS");
        cout << "Please Enter your choice :" << endl;
        cout << "1) Creat new account." << endl;
        cout << "2) Withdraw Money." << endl;
        cout << "3) Deposite Money." << endl;
        cout << "4) Check balance." << endl;
        cout << "5) See acoount details." << endl;
        cout << "6) Exit." << endl;

        cin >> ch;
        int b;
        switch (ch)
        {
        case 1:
            system("CLS");
            cout << "Enter the no. of accounts you want to create - " << endl;
            cin >> n;
            for (i = 0; i < n; i++)
            {
                cout << i + 1 << ") Enter the acount details. " << endl;
                ac[i].getdata();
            }
            system("CLS");
            cin.ignore();
            cout << "YOUR ACCOUNT IS CREATED" << endl;
            cout <<"\nPlease Enter to continue."<<endl;
            cin.get();//To clear screen after enter
            

            break;

        case 2:
            system("CLS");
            cout<<"Enter account no. to withdraw money."<<endl;
            cin>>acno1;
            while (ac[j].find(acno1)==1)
            {
                j++;
            }
            //cout<<"Enter the amount withdrawn : "<<endl;
            ac[j].withdraw();
            cout<<"Enter 1 to show balance: "<<endl;
            int b;
            cin>>b;
            if (b==1)
            {
                pin1=getpin();
                ac[j].B(pin1);
            }

            break;
        case 3:
            system("CLS");
            cout << "Enter account no. to deposite money." << endl;
            cin >> acno1;
            while (ac[j].find(acno1) == 1)
            {
                j++;
            }

            //cout << "Enter the amount Deposited : " << endl;
            ac[j].D();
            cout << "To show balance enter 1 " << endl;
            cin >> b;
            if (b == 1)
            {
                pin1=getpin();
                ac[j].B(pin1);
            }
            break;
        case 4:
            system("CLS");
            cout << "Enter account no. to show balance." << endl;
            cin >> acno1;
            while (ac[j].find(acno1) == 1)
            {
                j++;
            }
            pin1=getpin();
            ac[j].B(pin1);
            break;
        case 5:
            system("CLS");
            cout << "Enter account no. to get details." << endl;
            cin >> acno1;
            while (acno == acno1)
            {
                j++;
            }
            ac[j].display();
            cout << "To show balance enter 1 " << endl;
            cin >> b;
            if (b == 1)
            {
                pin1=getpin();
                ac[j].B(pin1);
            }
            break;
        default:
            system("CLS");
            cout << "Thank You";
            break;
        }
    }
    return 0;
}