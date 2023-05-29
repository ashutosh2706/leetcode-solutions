class ParkingSystem {
public:
    int b,m,s;
    vector<int> B,M,S;
    ParkingSystem(int big, int medium, int small) {
        this->b=big;
        this->m=medium;
        this->s=small;
    }
    
    bool addCar(int carType) {
        if(carType == 1) {
            if(B.size() == b) return 0;
            B.push_back(1);
            return 1;
        }else if(carType == 2) {
            if(M.size() == m) return 0;
            M.push_back(2);
            return 1;
        }else {
            if(S.size() == s) return 0;
            S.push_back(3);
            return 1;
        }
    }
};