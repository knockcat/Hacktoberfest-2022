// Contains Defiition of Files

// Static Cast: This is the simplest type of cast which can be used. It is a compile time cast.
// It does things like implicit conversions between types (such as int to float, or pointer to void*),
// and it can also call explicit conversion functions (or implicit ones).

#include "MemeberFunctions.h" //Defintion of  Member Functions and Class
#include <fstream>
#include <iostream>
using namespace std;

void write_account();            // func to write record in binary file
void display_sp(int);            // Func to display account details given by user
void modify_account(int);        // function to modify record into a file
void delete_account(int);        // function to delete record from a file
void display_all();              // function to display all records from a file
void deposit_withdraw(int, int); // function to deposit/withdraw amount for given account
void intro();                    // Introductory Screen

// defintion of writing record to file
// Here data present in class object acc is written to file knockcat.dat by calling write function.
// (char*)&acc is used to point at the start of an object and sizeof(account) calculates the number of bytes copied in file.
void write_account()
{
    Account acc;   // class object
    Account unacc; // for handling unique case
    bool k = false;

    ofstream outfile; // represents output file stream and writes information to files.
    ifstream infile;

    unacc.create_account();

    infile.open("knockcat.dat", ios::binary | ios::in);

    while (infile.read((char *)(&acc), sizeof(Account)))
    {
        if (acc.retaccno() == Unique)
        {
            k = true;
            Unique = 0;
        }
    }

    infile.close();

    if (!k)
    {
        outfile.open("knockcat.dat", ios::binary | ios::app);
        outfile.write((char *)(&unacc), sizeof(Account));
        cout << "\n\nAccount Created.........";
        Thankyou();
    }
    else
    {
        cout << "\n\nAccount number already Exist !!!" << endl
             << endl
             << endl
             << endl;
        Error();
    }

    outfile.close();
}

// defintion for displaying specific record from a file
void display_sp(int n)
{
    Account acc;
    bool flag = 0;
    ifstream infile; // represents input file stream and reads information from files.

    infile.open("knockcat.dat", ios::binary);
    if (!infile)
    {
        cout << "File could not be opened !! press any key ...";
        return;
    }

    cout << "\nBALANCE DETAILS\n";

    while (infile.read((char *)(&acc), sizeof(Account)))
    {
        if (acc.retaccno() == n)
        {
            acc.show_account();
            flag = 1;
        }
    }

    infile.close();
    if (flag == 0)
        cout << "\n\nAccount number doesn't exists...";
}

// definition for modification of record from file
void modify_account(int n)
{
    bool found = false;
    Account acc;
    fstream vj; // represents general file stream and has capabilities of both read & write.
    vj.open("knockcat.dat", ios::binary | ios::in | ios::out);

    if (!vj)
    {
        cout << "\nFile could not be opened !! press any key ....";
        return;
    }

    while (!vj.eof() && found == false)
    {
        vj.read((char *)(&acc), sizeof(Account));
        if (acc.retaccno() == n)
        {
            acc.show_account();
            cout << "\nEnter the New Details of the Account " << endl;
            acc.modify();
            //(-1)*static_cast<int>(sizeof(acc)); turns the unsigned result of the sizeof operator into a signed number, and multiplies it by -1.
            int pos = (-1) * static_cast<int>(sizeof(Account));
            // The seekp(pos) method of ostream in C++ is used to set the position of the pointer in the output sequence with the specified position
            vj.seekp(pos, ios::cur); // for moving pointer from curr position
            vj.write((char *)(&acc), sizeof(Account));

            cout << "\n\n\t Record Updated";
            found = true;
        }
    }
    vj.close();
    if (found == false)
        cout << "\n\n Record Not Found ";
}

// definition of deleting record from file
void delete_account(int n)
{
    Account acc;
    ifstream infile;  // represents input file stream and reads information from files.
    ofstream outfile; // represents output file stream and writes information to files.
    infile.open("knockcat.dat", ios::binary);
    if (!infile)
    {
        cout << "\nFile cannot be opened !! Press any key...";
        return;
    }

    outfile.open("Temp.dat", ios::binary);
    // seekg() is a function in the iostream library that allows you to seek an arbitrary position in a file.
    infile.seekg(0, ios::beg); // offset from the beginning of the stream’s buffer.

    while (infile.read((char *)(&acc), sizeof(Account)))
    {
        if (acc.retaccno() != n)
        {
            outfile.write((char *)(&acc), sizeof(Account));
        }
    }

    infile.close();
    outfile.close();
    remove("knockcat.dat");             // Delete a File from Current Directory
    rename("Temp.dat", "knockcat.dat"); // Changes the name of the file or directory specified by oldname to newname.

    cout << "\n\n\n\n\tRecord Deleted ..";
}

// definition for displaying all records from a file
void display_all()
{
    Account acc;
    ifstream infile; // represents input file stream and reads information from files.
    infile.open("knockcat.dat", ios::binary);
    if (!infile)
    {
        cout << "File could not be open !! Press any key...";
        return;
    }

    cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
    cout << "==============================================================\n";
    cout << "A/C NO.              NAME              TYPE          BALANCE\n";
    cout << "==============================================================\n";

    while (infile.read((char *)(&acc), sizeof(Account)))
    {
        acc.report();
        cout << endl;
    }
    infile.close();
}

// defintion for deposit and withdraw for a record from file
void deposit_withdraw(int n, int option)
{
    int amt;
    bool found = false;
    Account acc;
    fstream vj; // represents general file stream and has capabilities of both read & write.
    vj.open("knockcat.dat", ios::binary | ios::in | ios::out);
    if (!vj)
    {
        cout << "File could not be open !! press any key...";
        return;
    }

    while (!vj.eof() && found == false)
    {
        vj.read((char *)(&acc), sizeof(Account));
        if (acc.retaccno() == n)
        {
            acc.show_account();

            if (option == 1)
            {
                cout << "\n\n\tTo Deposit Ammount : ";
                cout << "Enter the amount to be deposited ";
                cin >> amt;
                acc.deposit_money(amt);
            }

            if (option == 2)
            {
                cout << "\n\n\tTo Withdraw Amount : ";
                cout << "\n\nEnter the Amount you need Withdraw : ";
                cin >> amt;

                int bal = acc.retdeposit() - amt;
                if ((bal < 500 && acc.rettype() == 'S' || (bal < 1000 && acc.rettype() == 'C')))
                    cout << "Insufficent balance !!";
                else
                    acc.draw(amt);
            }

            int pos = (-1) * static_cast<int>(sizeof(acc));
            vj.seekp(pos, ios::cur);
            vj.write((char *)(&acc), sizeof(Account));
            cout << "\n\nRecord Updated ";
            found = true;
        }
    }
    vj.close();

    if (found == false)
        cout << "\n\nRecord Not FOund";
}
