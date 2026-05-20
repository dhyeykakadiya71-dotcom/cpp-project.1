#include <iostream>
using namespace std;

// 1. Base Class: Vehicle (Demonstrates Encapsulation & Static Members)
class Vehicle {
protected:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

public:
    static int totalVehicles; // Static Member

    // Constructor
    Vehicle(int id, string mfg, string mdl, int yr) 
        : vehicleID(id), manufacturer(mfg), model(mdl), year(yr) {
        totalVehicles++;
    }

    // Virtual Destructor for proper cleanup of derived classes
    virtual ~Vehicle() {}

    // Getters and Setters
    int getID() const { return vehicleID; }
    string getModel() const { return model; }
    
    virtual void display() const {
        cout << "ID: " << vehicleID << " | " << manufacturer << " " << model << " (" << year << ")";
    }
};

int Vehicle::totalVehicles = 0;

// 2. Derived Classes

// Single Inheritance: Car from Vehicle
class Car : public Vehicle {
protected:
    string fuelType;
public:
    Car(int id, string mfg, string mdl, int yr, string fuel)
        : Vehicle(id, mfg, mdl, yr), fuelType(fuel) {}

    void display() const override {
        Vehicle::display();
        cout << " | Fuel: " << fuelType;
    }
};

// Multilevel Inheritance: ElectricCar from Car
class ElectricCar : public Car {
protected:
    int batteryCapacity;
public:
    ElectricCar(int id, string mfg, string mdl, int yr, string fuel, int batt)
        : Car(id, mfg, mdl, yr, fuel), batteryCapacity(batt) {}

    void display() const override {
        Car::display();
        cout << " | Battery: " << batteryCapacity << " kWh";
    }
};

// Base Class for Multiple Inheritance: Aircraft
class Aircraft {
protected:
    int flightRange;
public:
    Aircraft(int range) : flightRange(range) {}
    void displayAircraftInfo() const {
        cout << " | Flight Range: " << flightRange << " km";
    }
};

// Multiple Inheritance: FlyingCar from Car and Aircraft
class FlyingCar : public Car, public Aircraft {
public:
    FlyingCar(int id, string mfg, string mdl, int yr, string fuel, int range)
        : Car(id, mfg, mdl, yr, fuel), Aircraft(range) {}

    void display() const override {
        Car::display();
        displayAircraftInfo();
        cout << " [Type: Flying Car]";
    }
};

// Multilevel Inheritance continued: SportsCar from ElectricCar
class SportsCar : public ElectricCar {
private:
    int topSpeed;
public:
    SportsCar(int id, string mfg, string mdl, int yr, string fuel, int batt, int speed)
        : ElectricCar(id, mfg, mdl, yr, fuel, batt), topSpeed(speed) {}

    void display() const override {
        ElectricCar::display();
        cout << " | Top Speed: " << topSpeed << " km/h";
    }
};

// Hierarchical Inheritance: Sedan from Car
class Sedan : public Car {
public:
    Sedan(int id, string mfg, string mdl, int yr, string fuel)
        : Car(id, mfg, mdl, yr, fuel) {}
    void display() const override {
        Car::display(); cout << " [Sedan]";
    }
};

// Hierarchical Inheritance: SUV from Car
class SUV : public Car {
public:
    SUV(int id, string mfg, string mdl, int yr, string fuel)
        : Car(id, mfg, mdl, yr, fuel) {}
    void display() const override {
        Car::display(); cout << " [SUV]";
    }
};

// 3. VehicleRegistry Class (Manages Array of Objects)
class VehicleRegistry {
private:
    vector<Vehicle*> registry; // Using vector to act as a dynamic array of pointers

public:
    void addVehicle(Vehicle* v) {
        registry.push_back(v);
        cout << "\nVehicle added successfully!\n";
    }

    void viewAll() const {
        if (registry.empty()) {
            cout << "\nRegistry is empty.\n";
            return;
        }
        cout << "\n--- Current Vehicle Registry (Total: " << Vehicle::totalVehicles << ") ---\n";
        for (const auto& v : registry) {
            v->display();
            cout << endl;
        }
    }

    void searchByID(int id) const {
        for (const auto& v : registry) {
            if (v->getID() == id) {
                cout << "\nVehicle Found: ";
                v->display();
                cout << endl;
                return;
            }
        }
        cout << "\nVehicle with ID " << id << " not found.\n";
    }

    ~VehicleRegistry() {
        for (auto v : registry) delete v;
    }
};

// 4. Main Function (Menu-driven)
int main() {
    VehicleRegistry myRegistry;
    int choice;

    do {
        cout << "\n=== Vehicle Registry System ===\n";
        cout << "1. Add a Vehicle\n";
        cout << "2. View All Vehicles\n";
        cout << "3. Search by ID\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int type, id, year;
                string mfg, mdl, fuel;
                cout << "\nSelect Type: 1. Sedan 2. SUV 3. Electric Car 4. Flying Car 5. Sports Car: ";
                cin >> type;
                cout << "Enter ID, Manufacturer, Model, Year, Fuel Type: ";
                cin >> id >> mfg >> mdl >> year >> fuel;

                if (type == 1) myRegistry.addVehicle(new Sedan(id, mfg, mdl, year, fuel));
                else if (type == 2) myRegistry.addVehicle(new SUV(id, mfg, mdl, year, fuel));
                else if (type == 3) {
                    int batt; cout << "Enter Battery Capacity: "; cin >> batt;
                    myRegistry.addVehicle(new ElectricCar(id, mfg, mdl, year, fuel, batt));
                }
                else if (type == 4) {
                    int range; cout << "Enter Flight Range: "; cin >> range;
                    myRegistry.addVehicle(new FlyingCar(id, mfg, mdl, year, fuel, range));
                }
                else if (type == 5) {
                    int batt, speed; cout << "Enter Battery & Top Speed: "; cin >> batt >> speed;
                    myRegistry.addVehicle(new SportsCar(id, mfg, mdl, year, fuel, batt, speed));
                }
                break;
            }
            case 2:
                myRegistry.viewAll();
                break;
            case 3: {
                int searchID;
                cout << "Enter ID to search: ";
                cin >> searchID;
                myRegistry.searchByID(searchID);
                break;
            }
            case 4:
                cout << "Exiting system...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

}
/*
output:
	=== Vehicle Registry System ===
	1. Add a Vehicle
	2. View All Vehicles
	3. Search by ID
	4. Exit
	Enter your choice: 1
	
	Select Type: 1. Sedan 2. SUV 3. Electric Car 4. Flying Car 5. Sports Car: 1
	Enter ID, Manufacturer, Model, Year, Fuel Type: 1
	dhyey
	mega
	2010
	ev
	
	Vehicle added successfully!
	
	=== Vehicle Registry System ===
	1. Add a Vehicle
	2. View All Vehicles
	3. Search by ID
	4. Exit
	Enter your choice: 2
	
	--- Current Vehicle Registry (Total: 1) ---
	ID: 1 | dhyey mega (2010) | Fuel: ev [Sedan]
	
	=== Vehicle Registry System ===
	1. Add a Vehicle
	2. View All Vehicles
	3. Search by ID
	4. Exit
	Enter your choice: 3
	Enter ID to search: 1
	
	Vehicle Found: ID: 1 | dhyey mega (2010) | Fuel: ev [Sedan]
	
	=== Vehicle Registry System ===
	1. Add a Vehicle
	2. View All Vehicles
	3. Search by ID
	4. Exit
	Enter your choice: 4
	Exiting system...
*/
