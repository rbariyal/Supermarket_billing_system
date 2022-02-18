#include <iostream>
#include <fstream>

using namespace std;
class shopping
{
private:
    int pcode;
    float discount;
    string pname;
    float price;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};
void shopping::menu()
{

m:
    int choice;
    string email;
    string password;
    cout << "\t\t\t                        \n";
    cout << "\t\t\t SUPERMARKET MAIN MENU  \n";
    cout << "\t\t\t                        \n";
    cout << "\t\t\t Enter your choice      \n";
    cout << "\t\t\t 1)Administrator        \n";
    cout << "\t\t\t 2)Buyer                \n";
    cout << "\t\t\t 3)Exit                 \n";
    cout << "\t\t\t Please select:";
    cin >> choice;
    switch (choice)
    {

    case 1:
    {
        cout << "Please login\n";
        cout << "Enter your email:\n";
        cin >> email;
        cout << "Enter your password:\n";
        cin >> password;
        if (email == "rbariyal123@gmail.com" && password == "Rahul123@")
        {
            administrator();
        }
        else
        {
            cout << "You have entered wrong email/password";
        }
        break;
    }
    case 2:
    {
        buyer();
    }
    case 3:
    {
        exit(0);
    }
    default:
    {
        cout << "Please select from given options";
    }
    }

    goto m;
}
void shopping::administrator()
{
m:
    int choice;
    cout << "\n\t\t\t\t Administrator menu";
    cout << "\n\t\t\t\t____1)Add the product \n";
    cout << "\n\t\t\t\t____2)Modify the product \n";
    cout << "\n\t\t\t\t____3)Delete the product \n";
    cout << "\n\t\t\t\t____4)Back to main menu\n";
    cout << "\n\t\t\t\tPlease enter your choice\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        add();
        break;
    }
    case 2:
    {
        edit();
        break;
    }
    case 3:
    {
        rem();
        break;
    }
    case 4:
    {
        menu();
        break;
    }
    default:
    {
        cout << "Invalid choice\n";
    }
    }
    goto m;
}
void shopping::buyer()
{
m:
    int choice;
    cout << "\n\t\t\t Buyer\n";
    cout << "\n\t\t\t 1)Buy  product\n";
    cout << "\n\t\t\t 2)Go Back\n";
    cout << "\t\t\t ENTER YOUR CHOICE:";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        receipt();
        break;
    }
    case 2:
    {
        menu();
    }
    default:
    {
        cout << "Invalid choice";
    }
    }
    goto m;
}
void shopping ::add()
{
m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;
    cout << "\n\t\t\t Add new product\n";
    cout << "\n\t\t\t Product code of Product\n";
    cin >> pcode;
    cout << "\n\t\t\t Name of Product\n";
    cin >> pname;
    cout << "\n\t\t\t Price of Product\n";
    cin >> price;
    cout << "\n\t\t\t Discount on Product\n";
    cin >> discount;
    data.open("database.txt", ios::in);
    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;

        while (!data.eof())
        {
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
    }
    if (token == 1)
    {
        goto m;
    }
    else
    {
        data.open("database.txt", ios::app | ios::out);
        data << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
        data.close();
    }
    cout << "\n\t\t\t\ Record Inserted  ";
}
void shopping::edit()
{
    fstream data1, data2;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;
    cout << "\n\t\t\t Modify the Record";
    cout << "\n\t\t\t Enter the Product code:";
    cin >> pkey;
    data1.open("database.txt", ios::in);
    if (!data1)
    {
        cout << "\n\t\tFile does not exist!";
    }
    else
    {
        data2.open("database1.txt", ios::app | ios::out);
        data1 >> pcode >> pname >> price >> discount;
        while (!data1.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t\tEnter new Product code";
                cin >> c;
                cout << "\n\t\t\tName of the Product";
                cin >> n;
                cout << "\n\t\t\t Price";
                cin >> p;
                cout << "\n\t\t\t Discount";
                cin >> d;
                data2 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\t\t\t Record Edited";
                token++;
            }
            else
            {
                data2 << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
            }
            data1 >> pcode >> pname >> price >> discount;
        }
        data1.close();
        data2.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
        {
            cout << "\n\t\t\t Record does not exit\n";
        }
    }
}
void shopping::rem()
{
    fstream data1, data2;
    int pkey;
    int token = 0;
    cout << "\n\t\t DELETE PRODUCT";
    cout << "\n\t\t Enter Product Code";
    cin >> pkey;
    data1.open("database.txt", ios::in);
    if (!data1)
    {
        cout << "\n\t\t\t File does not exist";
    }
    else
    {
        data2.open("database1.txt", ios::app | ios::out);
        data1 >> pcode >> pname >> price >> discount;
        while (!data1.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\t\t\t Product deleted successfully";
                token++;
            }
            else
            {
                data2 << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
            }
            data1 >> pcode >> pname >> price >> discount;
        }
        data1.close();
        data2.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");
        if (token == 0)
        {
            cout << "\n\t\t\t Record does not exit\n";
        }
    }
}
void shopping::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\t\t\t          \n";
    cout << "Product no."
         << "\ttName"
         << "\tPrice\n";
    cout << "\n\t\t\t           \n";
    data >> pcode >> pname >> price >> discount;
    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t" << price << "\n";
        data >> pcode >> pname >> price >> discount;
    }
    data.close();
}
void shopping::receipt()
{
    fstream data;

    int arrc[100] = {0};
    int arrq[100] = {0};
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;
    cout << "\n\t\t\t    RECEIPT    \n";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "File does not Exist\n";
    }
    else
    {
        data.close();
        list();
        cout << "\n\t\t\t       \n";
        cout << "\n\t\t\t Please place your order";
        cout << "\n\t\t\t       \n";
        do
        {
        m:
            cout << "\n\t\t\t Enter Product Code:";
            cin >> arrc[c];
            cout << "\n\t\t Enter the Product Quality:";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\n Duplicate product code.Please try again!";
                    goto m;
                }
            }
            c++;
            cout << "Do you want to buy another product if yes press y else no:";
            cin >> choice;
        } while (choice == 'y');
        cout << "\n\t\t\t RECEIPT\n";
        cout << "\nProduct No. \tProduct Name \t Product quantity \tPrice\t Amount\t Amount with discount";
        for (int i = 0; i < c; i++)
        {

            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> discount;
            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price *arrq[i];
                    dis = amount - (amount * discount / 100);
                    total = total + dis;
                    cout << "\n"
                         << pcode << "\t\t" << pname << "\t\t\t" << arrq[i] << "\t\t" << price << "\t" << amount << "\t\t" << dis;
                }
                data >> pcode >> pname >> price >> discount;
            }
        }
        data.close();
    }
    cout << "\n\n Total Amount:" << total;
}
int main()
{
    shopping s;
    s.menu();

    return 0;
}