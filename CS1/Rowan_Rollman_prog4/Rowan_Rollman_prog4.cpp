#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int option, nquar, ndime, nnic, npen, bal;
    float deposit, withdrawal, currbal;

    currbal=0.00;
    cout << fixed << setprecision(2);
    
    do {
    cout << "***********************************" << endl;
    cout << "*         Piggy Bank Menu         *" << endl;
    cout << "*                                 *" << endl;
    cout << "*    Current Balance $ " << setw(6) << currbal << "     *" << endl;
    cout << "***********************************" << endl;
    cout << "*                                 *" << endl;
    cout << "* 1)  Make Deposit                *" << endl;
    cout << "* 2)  Make Withdrawal             *" << endl;
    cout << "* 3)  View Coins                  *" << endl;
    cout << "* 4)  Exit Program                *" << endl;
    cout << "*                                 *" << endl;
    cout << "***********************************" << endl;
    cout << endl;
   
        cout << "Enter choice: ";
        cin >> option;
        switch (option) {
            case 1:
                cout << "Enter the amount to be deposited: $ ";
                cin >> deposit;
                cout << endl;
                    if (deposit<0) {
                        cout << "Invalid amount -- Negative values are not allowed." << endl;
                        }
                    else if ((currbal+deposit)>900) {
                            cout << "The piggybank will not hold that much." << endl;
                            cout << "You may deposit up to $ " << 900-currbal << endl;
                       }
                    else
                        currbal += deposit;
                        break;
            case 2:
                cout << "Enter the amount to be withdrawn: $ ";
                cin >> withdrawal;
                cout << endl;
                    if (withdrawal<0) {
                        cout << "Invalid amount -- Negative values are not allowed." << endl;
                        }
                    else if (withdrawal>currbal){
                        cout << "The piggybank does not contain that much." << endl;
                        cout << "You may withdraw up to $ " << currbal << endl;
                        }
                    else
                        currbal -= withdrawal;
                        break;
                    case 3:
                        bal= currbal*100;
                        nquar=bal/25;
                        bal=bal%25;
                        ndime=bal/10;
                        bal=bal%10;
                        nnic=bal/5;
                        bal=bal%5;
                        npen=bal/1;
                
                
                
                        cout << "***********************************" << endl;
                        cout << "*            Statistics           *" << endl;
                        cout << "***********************************" << endl;
                        cout << "*                                 *" << endl;
                        cout << "*   Quarters" << setw(8) << nquar << "    $" << setw(7) << nquar*.25 << "  *" << endl;
                        cout << "*   Dimes" << setw(11) << ndime << "    $" << setw(7) << ndime*.1 << "  *" << endl;
                        cout << "*   Nickles" << setw(9) << nnic << "    $" << setw(7) << nnic*.05 << "  *" << endl;
                        cout << "*   Pennies" << setw(9) << npen << "    $" << setw(7) << npen*.01 << "  *" << endl;
                        cout << "*                                 *" << endl;
                        cout << "***********************************" << endl;
                            break;
                case 4:
                cout << "GOODBYE!" << endl;
                break;
                   default:
                        cout << "Invalid Option -- Try again" << endl;
            }
    } while (option!=4);
    
                
    return 0;
}


