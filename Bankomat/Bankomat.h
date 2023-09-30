#include <iostream>
#include <string>

using namespace std;
class Bankomat {
private:
    string idBank;
    int minSum;
    int maxSum;
    int balance;
    int nominals[7] = {10,20,50,100,200,500,1000};

    
public:
   
    Bankomat();
    Bankomat(string , int , int, int);
    int loadSum(int amount);
    int withdrawSum(int amount);
    string getIdBank() const;
    string convToString();

};