#include <iostream>
using namespace std;

// Function declarations (prototypes)
void Calculate(float *km, float *time, float *cash, float *gas_price, float *price_per_hour, float *car_consumption, float *ride_gas_value, float *ride_time_value, float *equivalent_60minutes_value, char *answer);
void Information(float *km, float *time, float *cash, float *gas_price, float *price_per_hour, float *car_consumption, float *ride_gas_value, float *ride_time_value, float *equivalent_60minutes_value, char *answer);
void Body(float *km, float *time, float *cash, float *gas_price, float *price_per_hour, float *car_consumption, float *ride_gas_value, float *ride_time_value, float *equivalent_60minutes_value, char *answer);

int main(){
    
	//Intro
    cout << "      Uber Info\n";

    //Declarations
    float km, time, cash;
    float gas_price = 5.69;
    float price_per_hour;
    float car_consumption = 8.5;
    float ride_gas_value;
    float ride_time_value;
    float equivalent_60minutes_value;
    char answer;

    Body(&km, &time, &cash, &gas_price, &price_per_hour, &car_consumption, &ride_gas_value, &ride_time_value, &equivalent_60minutes_value, &answer);
    return 0;
}

void Calculate(float *km, float *time, float *cash, float *gas_price, float *price_per_hour, float *car_consumption, float *ride_gas_value, float *ride_time_value, float *equivalent_60minutes_value, char *answer){
	
	//Inputs
    cout << "Insert total kms: ";
    cin >> *km;
    cout << "Insert total minutes: ";
    cin >> *time;
    cout << "Insert price per hour: ";
    cin >> *price_per_hour;
    cout << endl;
    
	//Calculations
    *ride_gas_value = ((*km) / (*car_consumption)) * (*gas_price);
    *ride_time_value = ((*time) / 60) * (*price_per_hour);
    *cash = *ride_time_value + *ride_gas_value;
    cout << "Value of gas: " << "R$" << *ride_gas_value << endl;
    cout << "Value of time: " << "R$" << *ride_time_value << endl;
    cout << "Total: " << "R$" << *cash << endl;

    //Ask if the user wants to repeat the entire program
    do {
        cout << "\nDo you want to repeat the entire program? ('y' or 'n'): ";
        cin >> *answer;
        if (*answer != 'y' && *answer != 'n') {
            cout << "Invalid answer. Please enter 'y' or 'n'." << endl;
        }
    } while (*answer != 'y' && *answer != 'n');

    if (*answer == 'y' || *answer == 'Y'){
        Body(km, time, cash, gas_price, price_per_hour, car_consumption, ride_gas_value, ride_time_value, equivalent_60minutes_value, answer);
    }
}

void Information(float *km, float *time, float *cash, float *gas_price, float *price_per_hour, float *car_consumption, float *ride_gas_value, float *ride_time_value, float *equivalent_60minutes_value, char *answer){

    //Inputs
    cout << "Insert ride price: ";
    cin >> *cash;
    cout << "Insert total kms: ";
    cin >> *km;
    cout << "Insert total minutes: ";
    cin >> *time;
    cout << endl;
    
	//Calculations
    *ride_gas_value = (*km / (*car_consumption)) * (*gas_price);
    *ride_time_value = *cash - ((*km / (*car_consumption)) * (*gas_price));
    *equivalent_60minutes_value = (*ride_time_value) * 60 / *time;
    cout << "Value of gas: " << "R$" << *ride_gas_value << endl;
    cout << "Value of time: " << "R$" << *ride_time_value << endl;
    cout << "Equivalent 60 minutes value: " << "R$" << *equivalent_60minutes_value << endl;

    //Ask if the user wants to repeat the entire program
    do {
        cout << "\nDo you want to repeat the entire program? ('y' or 'n'): ";
        cin >> *answer;
        if (*answer != 'y' && *answer != 'n') {
            cout << "Invalid answer. Please enter 'y' or 'n'." << endl;
        }
    } while (*answer != 'y' && *answer != 'n');

    if (*answer == 'y' || *answer == 'Y'){
        Body(km, time, cash, gas_price, price_per_hour, car_consumption, ride_gas_value, ride_time_value, equivalent_60minutes_value, answer);
    }
}

void Body(float *km, float *time, float *cash, float *gas_price, float *price_per_hour, float *car_consumption, float *ride_gas_value, float *ride_time_value, float *equivalent_60minutes_value, char *answer){
    cout << endl; // Single empty line before asking for user choice

    //Inputs
    cout << "a) Calculate using this software\n";
    cout << "b) Know how much is worth the price offered\n";
    cout << "\nAnswer: ";
    cin >> *answer;
    cout << endl; // Single empty line

    //Situations according to the answer
    if (*answer == 'a' || *answer == 'A'){
        Calculate(km, time, cash, gas_price, price_per_hour, car_consumption, ride_gas_value, ride_time_value, equivalent_60minutes_value, answer);
    } else if (*answer == 'b' || *answer == 'B'){
        Information(km, time, cash, gas_price, price_per_hour, car_consumption, ride_gas_value, ride_time_value, equivalent_60minutes_value, answer);
    } else{
        cout << "Invalid option. Please select 'a' for Calculate or 'b' for Information." << endl;
        Body(km, time, cash, gas_price, price_per_hour, car_consumption, ride_gas_value, ride_time_value, equivalent_60minutes_value, answer);
    }
}

