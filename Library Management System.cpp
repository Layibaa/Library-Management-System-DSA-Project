#include <bits/stdc++.h>
using namespace std; 

class book {
public:
    string id, bName, aName;
    int year;
    book* next;
};
// Stores the head of the Linked List 
book* head = new book();



class library{ // LIBRARY CLASS STARTS
	public:
// To check if the book exists in the library or not
bool check(string userId)
{   if (head == NULL)
        return false;
 
    book* temp = new book;
    temp = head; 
    while (temp != NULL) {
        if (temp->id == userId)
            return true;
        temp = temp->next;
    }
    return false;
}

//To search a book via its id
void searchBookId(string id){
    if (!head) {
        cout << "No book with this ID is available in the library.";
        return;
    } 
    else {
        book* b = head;
        while (b) { //means loop until the last character('\0') is reached.
            if (b->id == id) {
                cout << "Book id: \t" << b->id << endl;
                cout << "Book name: \t\t"  << b->bName << endl;
                cout << "Author name:\t"  << b->aName << endl;
                cout << "Year published:\t\t"   << b->year << endl;
                return;
            }
            b = b->next;
        } 
        if (b == NULL)
            cout << "No such book is available in the library\n";
    }
}
//To search a book via its name
void searchBookName(string bName)
{ 
    if (!head) {
        cout << "No book with this name is available in the library.";
        return;
    } 
    else { //where b is the book being searched
        book* b = head;
        while (b) { //means loop until the last character('\0') is reached.
            if (b->bName == bName) {
                cout << "Book id: \t" << b->id << endl;
                cout << "Book name: \t\t"  << b->bName << endl;
                cout << "Author name:\t"  << b->aName << endl;
                cout << "Year published:\t\t"   << b->year << endl;
                return;
            }
            b = b->next;
        }
        if (b == NULL)
            cout << "No such book is available in the library.\n";
    }
}

// Function to display the Student's
// Record
void displayBooks()
{
    book* temp = head;
    if (temp == NULL) {
        cout << "No books are present in the library.\n";
    }
    else {
        cout << "ID\tBook name\tAuthor name\tYear\n";
 
        // Until temp is not NULL
        while (temp != NULL) {
            cout << temp->id << "    \t"
                 << temp->bName << "\t\t"
                 << temp->aName << "\t\t"
                 << temp->year << endl;
            temp = temp->next;
        }
    }
}

int countBooks(book* temp)
{
    int bookCount = -1;
    while (temp != NULL)
    {
        bookCount++;
        temp = temp->next;
    }
    return bookCount;
}
};  // LIBRARY CLASS ENDS
class librarian{ 
public:
book b;
library l; 
void login(book& ptr){
	int choiceSearch;
        string pass;
        cout << "Enter password: (Must contain 1 or more numbers and minimum 3 alphabets)\n";
        cin >> pass;

        if (pass == "lib123") {
            bool exit = false;
            while (!exit) {
                cout << "\tLIBRARIAN MENU" << endl;
                cout << "1. Add a book" << endl;
                cout << "2. Delete a book" << endl;
                cout << "3. View number of books present in the library at the moment." << endl;
                cout << "4. Display all books present in the library" << endl;
                cout << "5. Search a book" << endl;
                cout << "6. Exit" << endl;
                cout << "Enter your choice: ";
                int choice;
                cin >> choice;

                switch (choice) {
                    case 1: {
                        cout << "Enter id of the book: ";
                        cin >> b.id;
                        cout << "Enter name of the book: ";
                        cin>>b.bName;  
                        cout << "Enter name of the author: ";
                        cin>>b.aName;
                        cout << "Enter the year the book was published in: ";
                        cin >> b.year; 
                        addBook(b.id,b.bName,b.aName,b.year); 
                        break;
                    }
                    case 2: {
                        cout << "Enter id of the book you want to delete\n";
                        cin >> b.id;
                        deleteBookId(b.id);
                        break;
                    }
                    case 3: {
                        cout<<"Number of books are: "<<l.countBooks(head)<<endl;
                        break;
                    }
                    case 4:
                        l.displayBooks();
                        break;
                    case 5:
                    	cout<<"Press 1 to search book by its ID\n Press 2 to search book by its name\n";
        	            cin>>choiceSearch;
        	            if(choiceSearch==1){
        		            cout << "Enter id of the book you want to Search\n";
                            cin >> b.id;
                            l.searchBookId(b.id); }
                        else if(choiceSearch==2){
        	                cout << "Enter name of the book you want to Search\n";
                     		cin >> b.bName;
                    		l.searchBookName(b.bName); }
                    		break;
                    case 6:
                        exit = true;
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                } 
            }
        } else {
            cout << "Invalid password. Access denied." << endl;
        }
    }
    // Add book in the library
void addBook(string id, string bName, string aName, int year)
{ // if the book being added already exists in the system
    if (l.check(id)) {
        cout << "This book is already present in the library.\n";
        return;
    }
    // where t is the book that is being added
    book* t = new book();
    t->id = id;
    t->bName = bName;
    t->aName = aName;
    t->year = year;
    t->next = NULL;
    // insert book in the beginning of the linked list
    if (head == NULL  || (head->id >= t->id)) { //so that the books being added are sorted in ascending order
        t->next = head;
        head = t;
    }
    // Insert in the middle or end of the linked list
    else {
        book* c = head; //where c acts like temp
        while (c->next != NULL && c->next->id < t->id) { //the 1st condition is to traverse till the end and 2nd is to stop as soon as a bigger id comes and place the new book before it
            c = c->next;
        }
        t->next = c->next;
        c->next = t;
    }
 
    cout<<"Book has been added in the library.\n";
}
    //delete a bok via its ID
 int deleteBookId(string id)
{   book* temp=head; //temp is the book being deleted
	if(l.check(id)==true)
	{
	while(temp->next->id!=id)
	{
		temp=temp->next;
	}
	book* todelete=temp->next;
	temp->next=temp->next->next;
    delete todelete;   
	cout<<"The book has been succesfully deleted.\n" ;}
    else 
    cout<<"The book that you want to delete does not exist"<<endl;
}
};	
class student{
	book b;
	public:
	library l;
	string sName, issuedBookId=" ", returnBookId;
	int sId; 
	void menu(){
		cout<<"\tEnter credentials to enter.\n";
            	cout<<"Name: ";
            	cin>>sName;
            	cout<<"\nId:  ";
            	cin>>sId;
		int choiceSearch;
            bool exit = false;
            while (!exit) {
                cout << "\n\tSTUDENT MENU" << endl;
                cout << "1. Issue a book" << endl;
                cout << "2. Return a book" << endl;
                cout << "3. View number of books present in the library at the moment." << endl;
                cout << "4. Display all books present in the library" << endl;
                cout << "5. Search a book" << endl;
                cout << "6. Exit" << endl;
                cout << "Enter your choice: ";
                int choice;
                cin >> choice;
string id;
                switch (choice) {
                    case 1: {
                        cout<<"Enter the book Id you want to issue: \n";
						cin>>id;
						if(issuedBookId==id){
							cout<<"The book you want to issue is already issued by another student. Pleasy come back after a week.";	}
						else  {
						cout<<"The book has been issued.\n";
						issuedBookId=id; } 
                    }
                    break;
                    case 2: {
                        cout<<"Enter the book Id you want to return.";
                        cin>>id;
                        if(id==issuedBookId){
                    		issuedBookId=" ";
							cout<<"The book has been returned\n";		 }
                        else
                        cout<<"This book has already been returned. Maybe you made a mistake. Please try again.\n";
                        break;
                    }
                    case 3: {
                        cout<<"Number of books are: "<<l.countBooks(head)<<endl;
                        break;
                    }
                    case 4:
                        l.displayBooks();
                        break;
                    case 5:
                    	cout<<"Press 1 to search book by its ID\n Press 2 to search book by its name\n";
        	            cin>>choiceSearch;
        	            if(choiceSearch==1){
        		            cout << "Enter id of the book you want to Search\n";
                            cin >>b.id;
                            l.searchBookId(b.id); }
                        else if(choiceSearch==2){
        	                cout << "Enter name of the book you want to Search\n";
                     		cin >> b.bName;
                    		l.searchBookName(b.bName); }
                    		break;
                    case 6:
                        exit = true;
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                } 
            }
        }  
};

int main()
{   book b1;
    library l; 
    librarian lb; 
    student s; 
    bool exit = false;
            while (!exit) {
    cout<<"\tLIBRARY MANAGEMENT SYSTEM\n";
    cout<<"\t1. Enter as librarian.\n";
    cout<<"\t2. Enter as student.\n";
    cout<<"\t3. Exit.\n";
    int option;
    cin>>option;
    switch(option){
    	case 1:
    		lb.login(b1);
    		break;
    	case 2:
    		s.menu();
    		break; 
    	case 3:
    		exit = true;
            break;
    	default:
    		cout<<"Invalid option\n Please try again.";
	}
}}
