#include <iostream>
#include <math.h>
using namespace std;


class Ramp {
    public:
        double distance;
        double a1;
        double v_mid;
        double a2;
        double v_max;
        double d1;
        double d2;

    public:
    double get_time();
    void get_graph();

};

double Ramp::get_time(){
    double t1 = v_mid/a1;                   // time taken to complete the first ramp up
    double t2 = (v_max-v_mid)/a2;           // time taken to complete the second ramp up
    double t4 = (v_max-v_mid)/d1;           // time taken to complete the first ramp down
    double t5 = (v_max-v_mid)/d2;           // time taken to complete the second ramp down
    double d_travelled = (0.5*a1*t1*t1) + v_mid*t2 + (0.5*a2*t2*t2) 
    + v_max*t4 - (0.5*d1*t4*t4) + v_mid*t5 - (0.5*d2*t5*t5);         // calculate the distance travelled in these region
    double t3 = (distance - d_travelled)/v_max;

    
    return t1+t2+t3+t4+t5;                  // total time for all the ramp to happen 
}

void Ramp::get_graph(){
    
}


int main () {
    Ramp myramp ;   
    cout << "Please enter distance: \n" ;
    cin >> myramp.distance;
    cout << "Please enter first Ramp Acceleration: \n" ;
    cin >> myramp.a1;
    cout << "Please enter first Ramp Velocity \n" ;
    cin >> myramp.v_mid;
    cout << "Please enter second Ramp Acceleration: \n";
    cin >> myramp.a2;
    cout << "Please enter target Velocity: \n";
    cin >> myramp.v_max;
    cout << "Please enter first Ramp Deceleration: \n";
    cin >> myramp.d1;
    cout << "Please enter second Ramp Deceleration: \n";
    cin >> myramp.d2;

    cout << "the total time taken is: " << myramp.get_time() << "s \n";
}