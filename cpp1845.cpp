
class SeatManager {
private:
    std::set<int> seats; // Use a set to store available seats.

public:
    SeatManager(int n) {
        if (n <= 0) {
            cout<<"Invalid value of n.";
        }

        for (int i = 1; i <= n; ++i) seats.insert(i);
    }

    int reserve() {
        if (seats.empty()) return -1;
        
        int reservedSeat = *seats.begin();
        seats.erase(reservedSeat); 
        return reservedSeat;
    }

    void unreserve(int seatNumber) {
        if (seatNumber > 0) seats.insert(seatNumber);
    }
};
