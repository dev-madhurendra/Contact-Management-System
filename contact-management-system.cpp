#include <iostream>
#include <cstring>
using namespace std;

class dnode
{
public:
    char number[100];
    char email[100];
    char name[100];
    dnode *prev, *next;
    dnode(char n[100], char r[100], char g[100])
    {
        strcpy(name, n);
        strcpy(number, r);
        strcpy(email, g);
        next = NULL;
        prev = NULL;
    }
    friend class dlist;
};

class dlist
{
    dnode *head, *temp, *ptr;
public:
    void insert();
    void sort();
    void deletecontact(char n[100]);
    void searchbyname(char p[100]);
    void searchbynumber(char no[100]);
    void searchbyemail(char g[100]);
    void accept();
    void display();
    void update(char ch[100]);
    dlist()
    {
        head = NULL;
        temp = NULL;
        ptr = NULL;
        
    }
};


void dlist::accept()
{
    char number[100];
    char email[100];
    char name[100];
    char ans;
    do
    {
        cout << "Enter Name:-";
        cin >> name;
        cout << "Enter Number:-";
        cin >> number;
        cout << "Enter E-mail ID:-";
        cin >> email;
        temp = new dnode(name, number, email);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->prev = ptr;
        }
        cout << "Do You want to Continue(y/n):-";
        cin >> ans;
    } while (ans == 'y');
}

void dlist::display()
{
    ptr = head;
    while (ptr != NULL)
    {
        cout << "\n\nName ::" << ptr->name;
        cout << "\nNumber ::+91-" << ptr->number;
        cout << "\nE-mail ID::" << ptr->email;
        ptr = ptr->next;
    }
}

void dlist::insert()
{
    accept();
}

void dlist::sort()
{
    dnode *i, *j;
    int temp;
    char n[10];
    for (i = head; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            temp = strcmp(i->name, j->name);
            if (temp > 0)
            {
                strcpy(n, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, n);
            }
            else
            {
                strcpy(n, j->name);
                strcpy(j->name, i->name);
                strcpy(i->name, n);
            }
        }
    }
}

void dlist::deletecontact(char s[100])
{
    int c = 0;
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(s, ptr->name) == 0)
        {
            c = 1;
            break;
        }
        else
        {
            c = -1;
        }
        ptr = ptr->next;
    }
    if (c == 1 && ptr != head && ptr->next != NULL)
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        delete (ptr);
        cout << "Your Contact is successfully deleted\n\n";
    }
    if (ptr == head)
    {
        head = head->next;
        head->prev = NULL;
        delete (ptr);
        cout << "Your Contact is successfully deleted\n\n";
    }
    if (ptr->next == NULL)
    {
        ptr->prev->next = NULL;
        ptr->prev = NULL;
        delete (ptr);
        cout << "Your Contact is successfully deleted\n\n";
    }
    if (c == -1)
    {
        cout << "Your Entered Name is not in the list...";
    }
}

void dlist::searchbyname(char na[100])
{
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(na, ptr->name) == 0)
        {
            cout << "Name Found!!" << endl;
            cout << "Contact Details are as Follows::\n"
                 << endl;
            cout << "\n\nName ::\t" << ptr->name;
            cout << "\nNumber ::\t+91-" << ptr->number;
            cout << "\nE-mail ID ::\t" << ptr->email;
        }
        else
        {
            cout<<"Contact not found!!\n";
        }
        ptr = ptr->next;
    }
}
void dlist::searchbynumber(char num[100])
{
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(num, ptr->number) == 0)
        {
            cout << "Number Found!!\n"
                 << endl;
            cout << "Contact Details are as Follows::\n"
                 << endl;
            cout << "\n\nName ::\t" << ptr->name;
            cout << "\nNumber ::\t+91-" << ptr->number;
            cout << "\nE-mail ID ::\t" << ptr->email;
        }
        else
        {
            cout<<"Contact not found!!\n";
        }
        ptr = ptr->next;
    }
}
void dlist::searchbyemail(char em[100])
{
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(em, ptr->email) == 0)
        {
            cout << "E-mail ID Found!!\n"
                 << endl;
            cout << "Contact Details are as Follows::\n"
                 << endl;
            cout << "\n\nName ::\t" << ptr->name;
            cout << "\nNumber ::\t+91-" << ptr->number;
            cout << "\nE-mail ID ::\t" << ptr->email;
        }
        else
        {
            cout<<"Contact not found!!\n";
        }
        ptr = ptr->next;
    }
}
void dlist::update(char n[100])
{
    char ans;
    int c;
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(n, ptr->name) == 0)
        {

            do
            {
                cout << "\nWhat do you want to Update...?\n1.Name:\n2.Phone Number:\n3.E-mail ID:\n";
                cin >> c;
                switch (c)
                {
                case 1:
                    cout << "Enter New Name:-";
                    cin >> ptr->name;
                    break;
                case 2:
                    cout << "Enter New Phone Number:-";
                    cin >> ptr->number;
                case 3:
                    cout << "Enter New E-mail ID:-";
                    cin >> ptr->email;
                    break;
                }
                cout << "Do you want to continue Updating(y/n):-";
                cin >> ans;
            } while (ans == 'y');
        }
        ptr = ptr->next;
    }
}
int main()
{
    char n[100];
    char name[100];
    char number[100];
    char email[100];
    dlist d1;
    char ans;
    int ch, a;
    cout << "\n\n******************Phone Book Management System - By Madhurendra Nath Tiwari******************";
    cout << "\n\nPlease Enter Your Name:- ";
    cin.getline(name, 100);
    cout << "\n\nWelcome " << name <<", Let's make your own PhoneBook\n\n";
    d1.accept();
    d1.sort();
    do
    {
        cout << "\n\n\n\n1. Display your Saved Contacts\n2. Insert New Contact\n3. Update Details on Existing Contact \n4. Delete Contact\n5. Search Contact\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            d1.display();
            break;

        case 2:
            d1.insert();
            d1.sort();
            break;

        case 3:
            cout << "\n\nEnter the name of the Person whose Details you want to update..\n";
            cin >> n;
            d1.update(n);
            d1.sort();
            break;

        case 4:
            cout << "\nEnter the name you want to delete from the Phone Book :-\n";
            cin >> name;
            d1.deletecontact(name);
            break;

        case 5:
            do
            {
                cout << "1.Search by Name:\n2.Search by Number:\n3.Search by E-mail ID:";
                cin >> a;
                switch (a)
                {
                case 1:
                    cout << "Enter the name to be Searched:-\n";
                    cin >> name;
                    d1.searchbyname(name);
                    break;
                case 2:
                    cout << "Enter the Number to be Searched:-\n";
                    cin >> number;
                    d1.searchbynumber(number);
                    break;
                case 3:
                    cout << "Enter the E-mail ID to be Searched:-\n";
                    cin >> email;
                    d1.searchbyemail(email);
                    break;
                default:
                    cout << "\nNo Proper Input Given..\n";
                }
                cout << "Do you want to continue Searching(y/n):-";
                cin >> ans;
            } while (ans == 'y');

            break;
        default:
            cout << "\nNo Proper Input Given..\n";
        }
        cout << "\n\nDo you want to continue operations(y/n):-";
        cin >> ans;
    } while (ans == 'y');
} 