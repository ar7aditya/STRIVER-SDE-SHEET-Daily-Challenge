class ParkingSystem {
public:
    int b , m , s;
    ParkingSystem(int big, int medium, int small) {
        b = big;
        m = medium;
        s = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
            if(b == 0) return false;
            b--;
            return true;
        }
        if(carType == 2){
            if(m == 0) return false;
            m--;
            return true;
        }
        if(s == 0) return false;
        s--;
        return true;
    }
};
