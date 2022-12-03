class ParkingSystem {
public:
    int bigs,b,smalls,s,meds,m;
    ParkingSystem(int big, int medium, int small) {
        bigs=big;
        smalls=small;
        meds=medium;
        b=0;s=0;m=0;
    }
    
    bool addCar(int carType) {
        if(carType==1){
            b++;
            return b<=bigs;
        }
        if(carType==2){
            m++;
            return m<=meds;
        }
        if(carType==3){
            s++;
            return s<=smalls;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
