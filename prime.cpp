//This Program discovers if a user's number is prime by dividing it by 2,
//then by every odd number up to 1/2 (rounded up) of the user's number.

//todo:
//timing
//prime factors
//find all the prime numbers below the user's number

//make a new instance of a class with every prime
//sum of primes
//prime factors

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

int main() {
    int userNum;
    char again = 'y';

    while(again == 'y'){
    cout << "Hello! Today we're going to calculate prime numbers.\n"
             "You'll specify a positive integer, and I'll find out if it is prime. Ready?\n"
             "Enter a number: ";
    cin >> userNum;
    cin.ignore(100, '\n');

    int lim = round(userNum/2);
    cout << "We start by dividing your number in half, because 2 is prime.\n";
    cout << lim << endl;
    int primes[20];

    /*finding primes the brute force way:
    Divide the number entered by each number in sequence, up to 50% of the total value
    */

    for (int i = 2; i <= lim; i++){
        if (i == lim){
            cout << userNum << " is prime!\n";
            break;
        } else if (i == 2 && userNum % i == 0) {
            cout << userNum << " is divisible by " << i << "! Not a prime number.\n";
            break;
        } else if (i % 2 == 0 && i > 2) {
            continue;
        } else if (i % 3 == 0 && i > 3) {
            continue;
        } else if (i % 5 == 0 && i > 5) {
            continue;
        } else if (i % 7 == 0 && i > 7) {
            continue;
        } else if (userNum % i == 0) {
            cout << userNum << " is divisible by " << i << "! Not a prime number.\n";
            break;
        } else {
            cout << "Dividing by: " << i << endl;
        }
    }
    cout << "Would you like to try another number? Press y to continue, or q to quit. ";
    cin >> again;
    cin.ignore(100, '\n');
    }
return 0;
}
