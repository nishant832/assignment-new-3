#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
private:
    string manufacturer;
    unsigned int productionYear;
    string model;

public:
    // Constructor with default parameter
    Vehicle(string make, unsigned int year, string mdl = "Standard")
    {
        manufacturer = make;
        productionYear = year;
        model = mdl;
        cout << "New " << manufacturer << " " << model << " from " << productionYear << " initialized." << endl;
    }
    
    // Overloaded constructor
    Vehicle(string make, string mdl)
    {
        manufacturer = make;
        model = mdl;
        productionYear = 2025;  // Default to current year
        cout << "New " << manufacturer << " " << model << " (latest model) initialized." << endl;
    }
    
    // Destructor
    ~Vehicle()
    {
        cout << "Vehicle " << manufacturer << " " << model << " is being removed from memory." << endl;
    }
    
    // Member function to display vehicle details
    inline void displayDetails() const
    {
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << productionYear << endl;
    }
};

int main()
{
    // Create vehicle using new
    Vehicle* myVehicle = new Vehicle("Honda", 2023, "Civic");
    myVehicle->displayDetails();
    
    // Create another vehicle using overloaded constructor
    Vehicle* luxuryVehicle = new Vehicle("Lexus", "ES350");
    luxuryVehicle->displayDetails();
    
    // Free memory
    delete myVehicle;
    delete luxuryVehicle;
    
    return 0;
}
