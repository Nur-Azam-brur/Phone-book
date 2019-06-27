#include <iostream>
#include<algorithm>
#include<bits/stdc++.h>
#include<string>
#include<cstdlib>
#include <sstream>
#include<vector>
#include<conio.h>
#define Max 100
using namespace std;

class contact
{
public:
    string firstName,lastName,mobileNumber;
//    void setinfo(string sf, string sl, string ms)
//    {
//        fisrtName=sf;
//        lastName=sl;
//        mobileNumber=ms;
//    }
};

enum search_t{FIRST_NAME,LAST_NAME,MOBILE_NUMBER};

vector <contact> phoneBook;
int currentSize=0;
void addInformation()
{
    if(phoneBook.size()==Max)
    {
        cout << "Your Phone Book is full";
        return;
    }
    else
    {
        contact c;
        cout << "Enter Your First Name :" << endl;
        cin >> c.firstName;
        cout << "Enter Your Last Name :" << endl;
        cin >> c.lastName;
        cout << "Enter Your Mobile Number :" << endl;
        cin >> c.mobileNumber;
        phoneBook.push_back(c);
        ++currentSize;
        cout << "Contact Added successfully !!" << endl;

    }


}

void removeInfo(string mn) // mn means mobile number
{
    int i,c=0;
    for(i=0;i<phoneBook.size();i++)
    {
        if(mn==phoneBook[i].mobileNumber)
        {
            phoneBook.erase(phoneBook.begin()+i);
            c=1;
            currentSize--;
            break;
        }
    }
    if(c==1) cout << "Contact Deleted Successfully !!" << endl;
    else cout << "Contact Not Found !!" << endl;
}
void displayInformation(int index)
{
    if(index<0 || index>=currentSize)
    {
        cout << "Error !! Invalid Index";
        return;
    }
    cout <<"First Name :"<<phoneBook[index].firstName << endl;
    cout <<"Last Name :"<< phoneBook[index].lastName << endl;
    cout <<"Mobile Number :"<<phoneBook[index].mobileNumber << endl;

}

void displayAllInformation()
{
    if(currentSize==0)
    {
        cout << "Phone Book Is Empty !!" << endl;
        cout << endl;
        return;
    }
    for(int i=0;i<currentSize;i++)
    {
    cout <<"First Name :"<<phoneBook[i].firstName << endl;
    cout <<"Last Name :"<< phoneBook[i].lastName << endl;
    cout <<"Mobile Number :"<<phoneBook[i].mobileNumber << endl;
    cout << endl;
    }


}


string toLowerCase(string s)
{
   transform(s.begin(), s.end(), s.begin(), ::tolower);
   return s;
}

void searchInfo(string s, search_t type)
{
    int found=0;
    string keyString=toLowerCase(s);
    string pbString,content; // pb means phone book
    if(type==FIRST_NAME)
    {
        for(int i=0;i<currentSize;i++)
        {
            content=phoneBook[i].firstName;
            pbString=toLowerCase(content);
            if(keyString==pbString)
            {
                displayInformation(i);
                found=1;
            }
        }
    }

    else if(type==LAST_NAME)
    {
       for(int i=0;i<currentSize;i++)
        {
            content=phoneBook[i].lastName;
            pbString=toLowerCase(content);
            if(keyString==pbString)
            {
                displayInformation(i);
                found=1;
            }
        }
    }

    else if(type==MOBILE_NUMBER)
    {
      for(int i=0;i<currentSize;i++)
        {
            content=phoneBook[i].mobileNumber;
            pbString=toLowerCase(content);
            if(keyString==pbString)
            {
                displayInformation(i);
                found=1;
            }
        }
    }

    else
    {
        cout << "Error!! Invalid Search Type.";
        return;
    }

    if(found==0)
    {
        cout <<"Not found In The Phone Book";
        return;
    }
}


void readFromFile()
{
    phoneBook.clear();
   string fn,ln,mn; // fn->first name,ln->last name,mn->mobile number
   int cs,i; //cs->current size
   contact read;
     ifstream in("myPoneBook.txt");
      if(!in)
      {
        cout << "Error !!" << endl;
        return;
      }

      else
    {
        in >> cs;
        currentSize=cs;
        for(i=0;i<currentSize;i++){
          in >> fn;
          in >> ln;
          in >> mn;
          read.firstName=fn;
          read.lastName=ln;
          read.mobileNumber=mn;
          //cout << f.name << " " << f.id << endl;
            phoneBook.push_back(read);

        }
        in.close();

    }

}


void saveToFile()
{
    contact save;
    ofstream out("myPoneBook.txt");
    if(!out)
    {
        cout << "Error !! can't open the file" << endl;
        return;
    }
    else
    {
        int i;
        out << currentSize << endl;
        for(i=0;i<phoneBook.size();i++)
        {

            save.firstName=phoneBook[i].firstName;
            save.lastName=phoneBook[i].lastName;
            save.mobileNumber=phoneBook[i].mobileNumber;
         out << save.firstName << " " << save.lastName << " "
         <<save.mobileNumber << endl;
        }
        out.close();
        cout << "Contact Saved Successfully !!" << endl;

    }

}

void clear()
{
    //system("push"); //press any key to continue
    system("CLS"); // clear the screen
}

int main()
{
    readFromFile();
    string selection;
    int choice,i;
    while(1){
   cout << "Phone Book Application Main Menu" << endl;
   cout << "    1.Insert A New Contact"<< endl;
   cout << "    2.Display All Contact"<< endl;
   cout << "    3.Search By First Name"<< endl;
   cout << "    4.Search By Last Name"<< endl;
   cout << "    5.Search By Mobile Number"<< endl;
   cout << "    6.Delete A Contact(By Mobile Number)"<< endl;
   cout << "    7.Save Contact"<< endl;
   cout << "    8.Exit"<< endl;


         cout << "Enter Your Choice :" << endl;
          cin >> selection;
          stringstream geek(selection); // string to integer
          geek>> choice;
   switch(choice)
   {
   case 1:
    addInformation();
    cout << endl;
    cout << "press any key to continue..." << endl;
    getch();
    clear();
    break;

   case 2:
    displayAllInformation();
    cout << "press any key to continue..." << endl;
    getch();
    clear();
    break;

   case 3:
       cout << "Enter The First Name To Search :" << endl;
       cin >> selection;
       searchInfo(selection,FIRST_NAME);
       cout << endl;
       cout << "press any key to continue..." << endl;
       getch();
       clear();
       break;
   case 4:
       cout << "Enter The Last Name To Search :" << endl;
       cin >> selection;
       searchInfo(selection,LAST_NAME);
       cout << endl;
       cout << "press any key to continue..." << endl;
       getch();
       clear();
       break;
   case 5:
       cout << "Enter The Mobile Number To Search :" << endl;
       cin >> selection;
       searchInfo(selection,MOBILE_NUMBER);
       cout << endl;
       cout << "press any key to continue..." << endl;
       getch();
       clear();
       break;
   case 6:
       cout << "Enter The Mobile Number To Delete :" << endl;
       cin >> selection;
       removeInfo(selection);
       cout << endl;
       cout << "press any key to continue..." << endl;
       getch();
       clear();
    break;
   case 7:
    saveToFile();
    cout << endl;
    cout << "press any key to continue..." << endl;
    getch();
    clear();
    break;
   case 8:
    exit(0);
   default:
    break;
   }
    }

    return 0;
}

