#include <iostream>
using namespace std;

class Car
{
public:
    string model; // Private attribute

private:
    int year;     // Private attribute

public:
    // Constructor
    Car(string mod, int yr) : model(mod), year(yr) {}

    // Public method to access private data (Getter for year)
    int getYear()
    {
        return year;
    }

    // Public method to modify private data (Setter for year)
    void setYear(int yr)
    {
        if (yr > 1886) // Simple validation, since cars were invented after 1886
            year = yr;
    }

    // Public method to display car info
    void display()
    {
        cout << "Model: " << model << ", Year: " << year << endl;
    }
};

int main()
{
    Car myCar("Tesla", 2023); // Create an object of the class Car

    myCar.display(); // Access public method to display details

    myCar.setYear(2025); // Update the year using the setter method
    cout << "Updated Year: " << myCar.getYear() << endl;

    cout << myCar.model << endl;

    return 0;
}
