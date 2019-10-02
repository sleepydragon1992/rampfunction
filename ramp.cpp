#include <iostream>
#include <math.h>
using namespace std;




//generic physics function

double linear_acc_dist (double vel, double acc, double t){      
    //this function calculate the distance covered by a linear acceleration motion    
    return t*vel + 0.5*acc*t*t;
}
//**************************************************************************************



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
};

class double_Ramp {
    public: 
        double d1;
        double d2;
        double a1;
        double v1;
        double a2;
        double v2;
        double a3;
        double v3;
        double a4;
        double v4;
        double a5;
        double v5;
        double a6;

    public:
    double get_time();
};

double double_Ramp::get_time(){
    v5 = v3;

    double t1 = v1/a1;
    double t2 = (v2-v1)/a2;
    double t3 = (d1 - linear_acc_dist(0,a1,t1)-linear_acc_dist(v1,a2,t2))/v2;
    double t4 = (v3-v2)/a3;
    double t5 = (v4-v3)/a4;
    double t7 = (v5-v4)/a5;
    double t8 = (0-v5)/a6;   
    double t6 = (d2 - linear_acc_dist(v2,a3,t4) - linear_acc_dist(v3,a4,t5)
     - linear_acc_dist(v4,a5,t7) - linear_acc_dist(v5,a6,t8))/v4;

    cout << "t1 is: " << t1 << "\n";
    cout << "t2 is: " << t2 << "\n";
    cout << "t3 is: " << t3 << "\n";
    cout << "t4 is: " << t4 << "\n";
    cout << "t5 is: " << t5 << "\n";
    cout << "t6 is: " << t6 << "\n";
    cout << "t7 is: " << t7 << "\n";
    cout << "t8 is: " << t8 << "\n";

    cout<< "distance travelled in t4: " << linear_acc_dist(v2,a3,t4)<< "\n";
    cout<< "distance travelled in t5: " << linear_acc_dist(v3,a4,t5)<< "\n";
    cout<< "distance travelled in t7: " << linear_acc_dist(v4,a5,t7)<< "\n";
    cout<< "distance travelled in t8: " << linear_acc_dist(v5,a6,t8)<< "\n";


    if ( t6<0 or t3<0 ){
        return 0;
    }
    else{
    return t1 + t2 + t3 + t4 + t5 + t6 + t7 + t8; 
    }
}







int main () {
    /*
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
    */




    double_Ramp your_ramp ; 


    your_ramp.d1 = 275;
    your_ramp.d2 = 1650;
    your_ramp.a1 = 2;
    your_ramp.a2 = 1;
    your_ramp.a3 = 2;
    your_ramp.a4 = 1;
    your_ramp.a5 = -1;
    your_ramp.a6 = -2;
    your_ramp.v1 = 10;
    your_ramp.v2 = 20;
    your_ramp.v3 = 30;
    your_ramp.v4 = 40;
    your_ramp.v5 = 30;
    
    your_ramp.get_time();

    cout<<" total time is: " << your_ramp.get_time() << "s \n";  
   
    
    /*
    cout << "the following info please enter from the 1st_phase seperation: \n";
    
    cout << "Please enter distance: \n" ;
    cin >> your_ramp.d1;
    cout << "Please enter first Ramp Acceleration: \n" ;
    cin >> your_ramp.a1;
    cout << "Please enter first Ramp Velocity \n" ;
    cin >> your_ramp.v1;
    cout << "Please enter second Ramp Acceleration: \n";
    cin >> your_ramp.a2;
    cout << "Please enter target Velocity: \n\n";
    cin >> your_ramp.v2;

    cout<< "the following info please enter from the 2nd_phase seperation: \n";
    
    cout << "Please enter distance: \n" ;
    cin >> your_ramp.d2;
    cout << "Please enter first Ramp Acceleration: \n" ;
    cin >> your_ramp.a3;
    cout << "Please enter first Ramp Velocity \n" ;
    cin >> your_ramp.v3;
    cout << "Please enter second Ramp Acceleration: \n";
    cin >> your_ramp.a4;
    cout << "Please enter target Velocity: \n";
    cin >> your_ramp.v4;
    cout << "Please enter first Ramp Deceleration: \n";
    cin >> your_ramp.a5;
    cout << "Please enter second Ramp Deceleration: \n";
    cin >> your_ramp.a6;

    double t = your_ramp.get_time();
    if (t==0) {
        cout <<"Ramp equation invalid \n";
    }
    else{
    cout << "The total time taken is: " <<your_ramp.get_time() << "s \n";
    } 
    return 0;
    */
}