#include "HotelBookingSystem.h"

BookingRequest::BookingRequest() : clientName(""), roomCapacity(0), roomClass(""),
stayDuration(0), isConfirmed(false), prepayment(0.0), totalCost(0.0) {}
// Конструктори та методи BookingRequest
BookingRequest::BookingRequest(string clientName, int roomCapacity, string roomClass, int stayDuration, double totalCost)
    : clientName(clientName), roomCapacity(roomCapacity), roomClass(roomClass), stayDuration(stayDuration),
    isConfirmed(false), prepayment(0.0), totalCost(totalCost) {}

string BookingRequest::getClientName() const {
    return clientName;
}
int BookingRequest::getRoomCapacity() const {
    return roomCapacity;
}
string BookingRequest::getRoomClass() const {
    return roomClass;
}
int BookingRequest::getStayDuration() const {
    return stayDuration;
}
double BookingRequest::getPrepayment() const {
    return prepayment;
}
double BookingRequest::getTotalCost() const {
    return totalCost;
}
bool BookingRequest::getIsConfirmed() const {
    return isConfirmed;
}

void BookingRequest::confirmBooking() {
    isConfirmed = true;
}
void BookingRequest::cancelBooking() {
    isConfirmed = false;
}

void BookingRequest::setPrepayment(double amount) {
    if (amount <= totalCost) {
        prepayment = amount;
    }
}

void BookingRequest::addService(const Service& service) {
    additionalServices.push_back(service);
    totalCost += service.getPrice();
}

void BookingRequest::displayBookingInfo() const {
    cout << "Client: " << clientName << endl;
    cout << "Room Capacity: " << roomCapacity << ", Class: " << roomClass << endl;
    cout << "Stay Duration: " << stayDuration << " nights" << endl;
    cout << "Total Cost: $" << totalCost << ", Prepayment: $" << prepayment << endl;
    cout << "Confirmed: " << (isConfirmed ? "Yes" : "No") << endl;

    if (!additionalServices.empty()) {
        cout << "\n Additional Services: " << endl;
        for (const auto& service : additionalServices) {
            cout << " - " << service.getServiceName() << " ($" << service.getPrice() << ")" << endl;
        }
    }
    cout << endl;
}

string BookingRequest::toFileFormat() const {
    string result = clientName + "," + to_string(roomCapacity) + "," + roomClass + "," +
        to_string(stayDuration) + "," + to_string(totalCost) + "," +
        to_string(prepayment) + "," + (isConfirmed ? "Confirmed" : "Not Confirmed");
    for (const auto& service : additionalServices) {
        result += "," + service.getServiceName() + "($" + to_string(service.getPrice()) + ")";
    }
    return result;
}

void BookingRequest::loadClientsFromFile(BookingRequest clients[], int n, const string& filename) {
    ifstream readFile(filename);
    if (readFile.fail()) {
        cerr << "Помилка відкриття файлу!" << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        string clientName;
        int roomCapacity;
        string roomClass;
        int stayDuration;
        double totalCost;

        if (readFile >> clientName >> roomCapacity >> roomClass >> stayDuration >> totalCost) {
            clients[i] = BookingRequest(clientName, roomCapacity, roomClass, stayDuration, totalCost);
        }
    }

    readFile.close();
}

// Конструктори та методи Service
Service::Service() :serviceName(""), price(0.0) {}
Service::Service(string serviceName, double price) : serviceName(serviceName), price(price) {}

string Service::getServiceName() const {
    return serviceName;
}
double Service::getPrice() const {
    return price;
}
// Метод для отримання типу (назви) послуги
string Service::getServiceType() const {
    return serviceName; // Повертає назву послуги
}
// Конструктори та методи Room
Room::Room(int roomCapacity, string roomClass, double pricePerNight) : roomCapacity(roomCapacity), roomClass(roomClass), pricePerNight(pricePerNight), isAvailable(true) {}

bool Room::checkAvailability() const {
    return isAvailable;
}

double Room::calculateCost(int nights) const {
    return nights * pricePerNight;
}

void Room::bookRoom() {
    isAvailable = false;
}

void Room::releaseRoom() {
    isAvailable = true;
}

void Room::displayRoomInfo() const {
    cout << "Room Capacity: " << roomCapacity << ", Class: " << roomClass << endl;
    cout << "Price per Night: $" << pricePerNight << endl;
    cout << "Availability: " << (isAvailable ? "Available" : "Not Available") << endl;
    cout << endl;
}
