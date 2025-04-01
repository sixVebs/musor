/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct Book {
    string name;
    unsigned amount;
    Book(){
        //rand: fillRandomly
    }
    Book(string n, string a, unsigned am, string g): name(n), author(a), amount(am), genre(g) {}
        //fillManually
    void showInfo (Book b){
        cout << "name" << b.name << endl;
        cout << "amount" << b.amount << endl;
    }
    ~Book(){//destructor
        cout << "Element was deleted:" << endl;
    }
};

bool enterCheckBook(unsigned length ,Book library){
    string bookName;
    cout<<"enter book info"<<endl;
    cin<<bookName;
    for(int i=0;i<length;i++){
        if (bookName==library[i].name){
          library[i].amount++;
          return true;
        }
    }
    addBook();
}

void addBook(b){
    cout << "name" << b.name << endl;
    cout << "amount" << b.amount << endl;
}

void functionsSet(Book library, unsigned length){
    if (enterCheckBook){
        addBook(library[length]);
    }
}

int main()
{
    unsigned length=1;
    Book* library=new Book[length];
    srand (time(NULL));
    Book book("Harry Potter & Orden Pozhirateley Pitsy", 1);
    //book.showInfo (book);
    library [0]= book;
    functionsSet(library, length);
    return 0;
}
