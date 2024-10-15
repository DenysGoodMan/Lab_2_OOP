#pragma once
#ifndef HOTELBOOKINGSYSTEM_H
#define HOTELBOOKINGSYSTEM_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Room;
class Service;

// Запит на бронювання
class BookingRequest {
private:
    string clientName;
    int roomCapacity; // Кількість місць у кімнаті
    string roomClass; // Клас кімнати
    int stayDuration; // Тривальсть перебування
    bool isConfirmed; // Підтвердження бронювання
    double prepayment; // Передоплата
    double totalCost; // Загальна вартість
    vector<Service> additionalServices; // Додаткові послуги

public:
    BookingRequest();
    BookingRequest(string clientName, int roomCapacity, string roomClass, int stayDuration, double totalCost);

    string getClientName() const;
    int getRoomCapacity() const;
    string getRoomClass() const;
    int getStayDuration() const;
    double getPrepayment() const;
    double getTotalCost() const;
    bool  getIsConfirmed() const;
    void confirmBooking(); // Підтвердити бронювання
    void cancelBooking(); // Відхилити бронювання
    void setPrepayment(double amount); // Встановити предоплату
    void addService(const Service& service); // Додати послугу
    void displayBookingInfo() const; // Відображення інформації про бронювання
    string toFileFormat() const;  // Новий метод для форматування інформації у вигляді рядка

    /* void loadClientsFromFile(BookingRequest clients[], int n, const string& filename);*/
    static void loadClientsFromFile(BookingRequest clients[], int size, const string& filename);
};

class Service {
private:
    string serviceName;
    double price;

public:
    Service();
    Service(string serviceName, double price);
    string getServiceName() const; // Отримати ім'я послуги
    double getPrice() const; // Отримати ціну послуги 
    string getServiceType() const;  // Метод для отримання типу (назви) послуги
};

class Room {
private:
    int roomCapacity; // Місткість кімнати
    string roomClass; // Клас кімнати
    double pricePerNight; // Ціна за добу
    bool isAvailable; // Метод, який показує чи є в наявності така кімната

public:
    Room(int roomCapacity, string roomClass, double pricePerNight);
    bool checkAvailability() const; // Перевірити наявність
    double calculateCost(int nights) const; // Розрахунок вартості
    void bookRoom(); // 
    void releaseRoom();
    void displayRoomInfo() const; // Метод для відображення інформації про кімнату
};
#endif // HOTELBOOKINGSYSTEM_H