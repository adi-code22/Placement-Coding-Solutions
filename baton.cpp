#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Apartments{
private:
    int id;
    int ratiox;
    int ratioy;
    int totalLitres = 0;
    int totalCost = 0;
    int numGuests = 0;
public:
    Apartments(int aid, int ratx, int raty){
        id = aid;
        ratiox = ratx;
        ratioy = raty;
    }
    bool isGuestZero(){
        return numGuests == 0;
    }
    void basic(){
        if(id == 2 || id == 3){
            int basicLitres;
            int corporationLitres, borewellLitres;
            int corporationCost, borewellCost;
            int ratioSum = ratiox + ratioy;

            if(id == 2) basicLitres = 3 * 10 * 30;
            else basicLitres = 5 * 10 * 30;
            
            corporationLitres = (basicLitres/ratioSum) * ratiox;
            borewellLitres = (basicLitres/ratioSum) * ratioy;
            
            corporationCost = corporationLitres;
            borewellCost = borewellLitres * 1.5;

            totalLitres += corporationLitres + borewellLitres;
            totalCost += corporationCost + borewellCost;
        }else{
            cout<<"Sorry!, Wrong Apartment Type. Valid Types are 2 or 3"<<endl;
        }
    }

    void addGuests(int n){
        numGuests += n;
    }

    void guests(){
        int guestLitres = numGuests * 10 * 30;
        int guestCost = 0;
        totalLitres += guestLitres;

        if(guestLitres > 500){
            guestCost += (500 * 2);
        }else{
            guestCost += ((guestLitres) * 2);
        }
        if(guestLitres > 1500){
            guestCost += (1000 * 3);
        }else{
            guestCost += ((guestLitres-500) * 3);
        }
        if(guestLitres > 3000){
            guestCost += (1500 * 5);
        }else{
            guestCost += ((guestLitres-1500) * 5);
        }
        if(guestLitres > 3000){
            guestCost += (guestLitres * 8);
        }

        totalCost += guestCost;
    }

    int retTotalCost(){
        return totalCost;
    }
    int retTotalLitres(){
        return totalLitres;
    }

};

int main(){
    string allot, ratio;
    int apartment_type;
    cin>>allot>>apartment_type>>ratio;

    Apartments baton(apartment_type, stoi(ratio.substr(0, 1)), stoi(ratio.substr(2, 1)));

    string next;
    cin>>next;
    while(next != "BILL"){
        int guestNum;
        cin>>guestNum>>next;
        baton.addGuests(guestNum);
    }
    
    baton.basic();
    if(!baton.isGuestZero()) baton.guests();
    
    cout<<"Total Litres = "<<baton.retTotalLitres()<<endl;
    cout<<"Total Cost = "<<baton.retTotalCost()<<endl;
    return 0;
}