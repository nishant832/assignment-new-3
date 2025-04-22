#include <iostream>
#include <string>
using namespace std;

class Learner {
private:
    string fullName;     // Learner's full name
    unsigned short yearOfBirth;  // Learner's birth year
    char performance;    // Performance grade
    const string cohort = "Class of 2025"; // Constant cohort identifier

public:
    // Inline setters
    inline void updateName(string newName)
    {
        fullName = newName;
    }
    
    inline void updateBirthYear(unsigned short year)
    {
        yearOfBirth = year;
    }
    
    // Calculate and set grade
    void updatePerformance(char p)
    {
        performance = p;
    }

    // Getters with different naming convention
    inline string fetchName() const
    {
        return fullName;
    }
    
    inline unsigned short fetchBirthYear() const
    {
        return yearOfBirth;
    }
    
    inline char fetchPerformance() const
    {
        return performance;
    }
    
    // Function to calculate age (assuming current year is 2025)
    unsigned short calculateAge() const
    {
        return 2025 - yearOfBirth;
    }

    // Method to print learner information
    void printDetails() const
    {
        cout << "Name: " << fullName << endl;
        cout << "Age: " << calculateAge() << endl;
        cout << "Performance Grade: " << performance << endl;
        cout << "Cohort: " << cohort << endl;
    }
};

int main() {
    Learner pupil;
    string inputName;
    unsigned short birthYear;
    char perfGrade;
    
    cout << "Enter learner's full name: ";
    getline(cin, inputName);
    
    cout << "Enter birth year: ";
    cin >> birthYear;
    
    cout << "Enter performance grade (A-F): ";
    cin >> perfGrade;
    
    pupil.updateName(inputName);
    pupil.updateBirthYear(birthYear);
    pupil.updatePerformance(perfGrade);
    
    cout << "\n--- Learner Information ---\n";
    pupil.printDetails();
    
    return 0;
}
