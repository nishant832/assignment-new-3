#include <iostream>
#include <string>

// Base Transport class
class Transport {
protected:
    std::string manufacturer;
    unsigned int modelYear;
    std::string modelName;

public:
    // Constructor with default values
    Transport(const std::string& make = "Generic", unsigned int year = 2020, 
              const std::string& model = "Basic") 
        : manufacturer(make), modelYear(year), modelName(model) {
    }
    
    // Virtual method for displaying information
    virtual void displaySpecs() {
        std::cout << "Manufacturer: " << manufacturer << std::endl;
        std::cout << "Model: " << modelName << std::endl;
        std::cout << "Year: " << modelYear << std::endl;
    }
    
    // Virtual method for transport operation
    virtual void operate() {
        std::cout << "Generic transport operation initiated" << std::endl;
    }
    
    // Virtual destructor
    virtual ~Transport() {
        std::cout << "Transport destructor called" << std::endl;
    }
};

// Automobile class inheriting from Transport
class Automobile : public Transport {
private:
    unsigned int seatCapacity;
    std::string fuelType;

public:
    // Default constructor
    Automobile() : Transport(), seatCapacity(5), fuelType("Gasoline") {}
    
    // Parameterized constructor
    Automobile(const std::string& make, unsigned int year, const std::string& model,
               unsigned int seats, const std::string& fuel)
        : Transport(make, year, model), seatCapacity(seats), fuelType(fuel) {}
    
    // Override display method
    void displaySpecs() override {
        Transport::displaySpecs();
        std::cout << "Seating Capacity: " << seatCapacity << std::endl;
        std::cout << "Fuel Type: " << fuelType << std::endl;
    }
    
    // Override operate method
    void operate() override {
        std::cout << "Automobile engine started - " << fuelType << " powered" << std::endl;
    }
    
    // Destructor
    ~Automobile() override {
        std::cout << "Automobile destructor called" << std::endl;
    }
};

// HybridAutomobile class inheriting from Automobile
class HybridAutomobile : public Automobile {
private:
    unsigned int electricRange;
    std::string batteryType;

public:
    // Default constructor
    HybridAutomobile() 
        : Automobile(), electricRange(50), batteryType("Lithium-Ion") {}
    
    // Parameterized constructor
    HybridAutomobile(const std::string& make, unsigned int year, const std::string& model,
                 unsigned int seats, const std::string& fuel, unsigned int range, const std::string& battery)
        : Automobile(make, year, model, seats, fuel), electricRange(range), batteryType(battery) {}
    
    // Override display method
    void displaySpecs() override {
        Automobile::displaySpecs();
        std::cout << "Electric Range: " << electricRange << " miles" << std::endl;
        std::cout << "Battery Type: " << batteryType << std::endl;
    }
    
    // Override operate method
    void operate() override {
        std::cout << "Hybrid system activated - Switching between electric and " 
                  << "conventional power sources" << std::endl;
    }
    
    // Destructor
    ~HybridAutomobile() override {
        std::cout << "HybridAutomobile destructor called" << std::endl;
    }
};

int main() {
    // Create Transport object
    Transport* basicTransport = new Transport("Basic Motors", 2018, "Generic");
    basicTransport->displaySpecs();
    basicTransport->operate();
    std::cout << std::endl;
    
    // Create Automobile object
    Automobile* sedan = new Automobile("Ford", 2022, "Fusion", 5, "Diesel");
    sedan->displaySpecs();
    sedan->operate();
    std::cout << std::endl;
    
    // Create HybridAutomobile objects
    HybridAutomobile* hybridSUV = new HybridAutomobile("Toyota", 2024, "RAV4", 5, 
                                                      "Hybrid", 42, "Lithium-Ion");
    hybridSUV->displaySpecs();
    hybridSUV->operate();
    std::cout << std::endl;
    
    HybridAutomobile* luxuryHybrid = new HybridAutomobile("Lexus", 2023, "ES300h", 5,
                                                         "Premium Hybrid", 50, "Enhanced Lithium");
    luxuryHybrid->displaySpecs();
    luxuryHybrid->operate();
    std::cout << std::endl;
    
    // Clean up memory
    delete basicTransport;
    delete sedan;
    delete hybridSUV;
    delete luxuryHybrid;
    
    return 0;
}
