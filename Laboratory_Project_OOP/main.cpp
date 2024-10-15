#include "HotelBookingSystem.h"

void saveClientsToFile(const BookingRequest clients[], int size, const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (int i = 0; i < size; i++) {
            outFile << clients[i].toFileFormat() << endl;
        }
        outFile.close();
        cout << "\n Clients saved to " << filename << "\n" << endl;
    }
    else {
        cerr << "Unable to open file " << filename << endl;
    }
}

int main() {

    // Створення об'єкта послуги
    Service breakfast("Breakfast in room", 15.0);
    // Отримання інформації про послугу
    cout << "Service Name: " << breakfast.getServiceName() << endl;
    cout << "Service Price: $" << breakfast.getPrice() << endl;
    cout << "Service Type: " << breakfast.getServiceType() << "\n" << endl;

    // Додаємо інформацію про кімнати
    Room room1(2, "Standard", 50.0);
    Room room2(3, "Deluxe", 80.0);
    Room room3(4, "Suite", 120.0);

    Service* services = new Service[5];
    services[0] = Service("Breakfast in room", 15.0);
    services[1] = Service("Transfer", 30.0);
    services[2] = Service("Pool Access", 20.0);
    services[3] = Service("Spa Treatment", 50.0);
    services[4] = Service("Dinner Package", 40.0);

    // Створюємо масив із 5 клієнтів
    BookingRequest static  clients[5] = {
        BookingRequest("Alice Smith", 2, "Standard", 3, room1.calculateCost(3)),
        BookingRequest("Bob Johnson", 3, "Deluxe", 4, room2.calculateCost(4)),
        BookingRequest("Charlie Brown", 2, "Standard", 2, room1.calculateCost(2)),
        BookingRequest("David Williams", 4, "Suite", 1, room3.calculateCost(1)),
        BookingRequest("Eve Miller", 3, "Deluxe", 5, room2.calculateCost(5))
    };

    // Виведення інформації про кожного клієнта до підтвердження бронювання
    cout << "Booking Requests Before Confirmation:" << endl;
    for (int i = 0; i < 5; i++) {
        clients[i].displayBookingInfo();
    }
    cout << endl;

    // Випадкове додавання послуг для кожного клієнта
    for (int i = 0; i < 5; i++) {
        int randomServiceCount = rand() % 5; // Випадкове число від 0 до 2 (кількість послуг для клієнта)

        if (randomServiceCount > 0) clients[i].addService(services[0]); // Додаємо breakfast, якщо > 0
        if (randomServiceCount > 1) clients[i].addService(services[1]); // Додаємо transfer, якщо > 1
        if (randomServiceCount > 3) clients[i].addService(services[3]); // Додаємо Spa Treatment якщо > 3
        if (randomServiceCount > 1) clients[i].addService(services[4]); // Додаємо Dinner Package якщо > 1
        if (rand() % 2 == 0) clients[i].addService(services[2]);        // Додаємо poolAccess випадково (50% шанс)
    }


    // Підтвердження бронювання для всіх клієнтів та виведення інформації після підтвердження
    cout << "Booking Requests After Confirmation:" << endl;
    for (int i = 0; i < 5; i++) {
        clients[i].confirmBooking();
    }

    // Збереження інформації у файл
    saveClientsToFile(clients, 5, "clients.txt");

    // Завантаження клієнтів з файлу та виведення інформації
    cout << "Loaded Booking Requests:" << endl;
    BookingRequest::loadClientsFromFile(clients, 5, "clients.txt");
    for (int i = 0; i < 5; i++) {
        clients[i].displayBookingInfo();
    }

    return 0;
}
