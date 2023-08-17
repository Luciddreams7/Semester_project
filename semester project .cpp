


#include <iostream>
#include <vector>
using namespace std;

class Room {
private:
    int roomNumber;
    bool isAvailable;
public:
    Room(int number) : roomNumber(number), isAvailable(true) {}
    int getRoomNumber() const { return roomNumber; }
    bool getAvailability() const { return isAvailable; }
    void setAvailability(bool availability) { isAvailable = availability; }
};

class Customer {
private:
    string name;
    int customerId;
public:
    Customer(string customerName, int id) : name(customerName), customerId(id) {}
    string getName() const { return name; }
    int getCustomerId() const { return customerId; }
};

class Booking {
private:
    int bookingId;
    int roomId;
    int customerId;
    string checkInDate;
    string checkOutDate;
public:
    Booking(int id, int room, int customer, string checkIn, string checkOut) : 
        bookingId(id), roomId(room), customerId(customer), checkInDate(checkIn), checkOutDate(checkOut) {}
    int getBookingId() const { return bookingId; }
    int getRoomId() const { return roomId; }
    int getCustomerId() const { return customerId; }
    string getCheckInDate() const { return checkInDate; }
    string getCheckOutDate() const { return checkOutDate; }
};

class Hotel {
private:
    vector<Room> rooms;
    vector<Customer> customers;
    vector<Booking> bookings;
    int nextBookingId;

public:
    Hotel() : nextBookingId(1) {}

    void addRoom(int roomNumber) {
        Room newRoom(roomNumber);
        rooms.push_back(newRoom);
    }

    void addCustomer(string name, int customerId) {
        Customer newCustomer(name, customerId);
        customers.push_back(newCustomer);
    }

    void makeBooking(int roomNumber, int customerId, string checkInDate, string checkOutDate) {
        for (Room& room : rooms) {
            if (room.getRoomNumber() == roomNumber) {
                room.setAvailability(false);
                Booking newBooking(nextBookingId, roomNumber, customerId, checkInDate, checkOutDate);
                bookings.push_back(newBooking);
                nextBookingId++;
                cout << "Booking successful. Booking ID: " << newBooking.getBookingId() << endl;
                return;
            }
        }
        cout << "Room not found." << endl;
    }

    void displayAvailableRooms() const {
        cout << "Available rooms:" << endl;
        for (const Room& room : rooms) {
            if (room.getAvailability()) {
                cout << "Room " << room.getRoomNumber() << endl;
            }
        }
    }

    void checkOut(int bookingId) {
        for (Booking& booking : bookings) {
            if (booking.getBookingId() == bookingId) {
                for (Room& room : rooms) {
                    if (room.getRoomNumber() == booking.getRoomId()) {
                        room.setAvailability(true);
                        cout << "Check-out successful." << endl;
                        return;
                    }
                }
            }
        }
        cout << "Booking not found." << endl;
    }
};

int main() {
    Hotel hotel;

    hotel.addRoom(101);
    hotel.addRoom(102);
    hotel.addRoom(103);

    hotel.addCustomer("John Doe", 1);
    hotel.addCustomer("Jane Smith", 2);

    hotel.displayAvailableRooms();

    hotel.makeBooking(101, 1, "2023-08-01", "2023-08-05");
    hotel.makeBooking(102, 2, "2023-08-03", "2023-08-07");

    hotel.displayAvailableRooms();

    hotel.checkOut(1);

    hotel.displayAvailableRooms();

    return 0;
}


