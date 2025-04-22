#include <iostream>
#include <string>
using namespace std;

class Publication
{
private:
    string bookTitle;
    unsigned int pageCount;
    string bookAuthor;

protected:
    double bookPrice;

public:
    // Inline function for setting title
    inline void assignTitle(string t)
    {
        bookTitle = t;
    }   
    
    // Regular setter functions
    void assignPages(unsigned int p)
    {
        pageCount = p;
    }
    
    void assignAuthor(string a)
    {
        bookAuthor = a;
    }
    
    inline void assignPrice(double p)
    {
        bookPrice = p;
    }
    
    // Getter functions
    string retrieveTitle()
    {
        return bookTitle;
    }
    
    unsigned int retrievePages()
    {
        return pageCount;
    }
    
    string retrieveAuthor()
    {
        return bookAuthor;
    }
    
    double retrievePrice()
    {
        return bookPrice;
    }
    
    // Public member variable
    string publishingHouse;
    
    // Method to display author information
    void ShowAuthorDetails()
    {
        cout << "Author: " << bookAuthor << endl;
    }
};

int main()
{    
    Publication myBook;
    myBook.publishingHouse = "Random House";
    myBook.assignTitle("Modern C++ Programming");
    myBook.assignPages(250);
    myBook.assignAuthor("Jane Smith");
    myBook.assignPrice(34.99);
    
    myBook.ShowAuthorDetails();
    cout << "Publisher: " << myBook.publishingHouse << endl;
    cout << "Price: $" << myBook.retrievePrice() << endl;
    cout << "Title: " << myBook.retrieveTitle() << endl;
    cout << "Pages: " << myBook.retrievePages() << endl;
    cout << "Author: " << myBook.retrieveAuthor() << endl;

    return 0;
}
