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

// ����� �� ����������
class BookingRequest {
private:
    string clientName;
    int roomCapacity; // ʳ������ ���� � �����
    string roomClass; // ���� ������
    int stayDuration; // ���������� �����������
    bool isConfirmed; // ϳ����������� ����������
    double prepayment; // �����������
    double totalCost; // �������� �������
    vector<Service> additionalServices; // �������� �������

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
    void confirmBooking(); // ϳ��������� ����������
    void cancelBooking(); // ³������� ����������
    void setPrepayment(double amount); // ���������� ����������
    void addService(const Service& service); // ������ �������
    void displayBookingInfo() const; // ³���������� ���������� ��� ����������
    string toFileFormat() const;  // ����� ����� ��� ������������ ���������� � ������ �����

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
    string getServiceName() const; // �������� ��'� �������
    double getPrice() const; // �������� ���� ������� 
    string getServiceType() const;  // ����� ��� ��������� ���� (�����) �������
};

class Room {
private:
    int roomCapacity; // ̳������ ������
    string roomClass; // ���� ������
    double pricePerNight; // ֳ�� �� ����
    bool isAvailable; // �����, ���� ������ �� � � �������� ���� ������

public:
    Room(int roomCapacity, string roomClass, double pricePerNight);
    bool checkAvailability() const; // ��������� ��������
    double calculateCost(int nights) const; // ���������� �������
    void bookRoom(); // 
    void releaseRoom();
    void displayRoomInfo() const; // ����� ��� ����������� ���������� ��� ������
};
#endif // HOTELBOOKINGSYSTEM_H