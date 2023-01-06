//This Program discovers if a user's number is prime by dividing it by 2,
//then by every odd number up to 1/2 (rounded up) of the user's number.
//Additional logic was needed to manage prime 2, as dividing the users Number
//by 2 initially caused overlap for 4.

//Correcting the lim logic too high caused 5 % 4 to return 0, causing
//the script to think 5 was divisible by 4 and not prime.

//todo:
//find all the prime numbers below the user's number
//prime factors

//make a new instance of a class with every prime
//sum of primes
//multiple of primes

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;

void primeTime(int lim, int userNum);

int main() {
    int userNum;
    char again = 'y';

    while(again == 'y'){
    cout << "Hello! Today we're going to calculate prime numbers.\n"
             "You'll specify a positive integer, and I'll find out if it is prime. Ready?\n"
             "Enter a number: ";
    cin >> userNum;
    cin.ignore(100, '\n');

    //int lim = round(userNum/2);
    int lim = 0;
    if (userNum > 4) {
           lim = round(userNum/2);
    } else {
        lim = userNum;
    }

    cout << "We start by dividing your number in half, because 2 is prime.\n";
    cout << "This means the max number of times we will have to divide is: " << lim << endl;
    int primes[20];

    /*finding primes the brute force way:
    Divide the number entered by each odd number in sequence, up to 50% of the total value
    */

    auto start = high_resolution_clock::now();
    primeTime(lim, userNum);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Finding your primes took " << duration.count()*10e-6 << " seconds!" << endl;

    cout << "Would you like to try another number? Press y to continue, or q to quit. ";
    cin >> again;
    cin.ignore(100, '\n');
    }
return 0;
}

void primeTime(int lim, int userNum){
    if (userNum == 1) {
            cout << "1 is not a prime number. A prime number is divisible by 1 AND itself.\n"
            "1 is the SAME as itself in this case, not a separate number.\n";
    } else {
        for (int i = 2; i <= lim+1; i++){
            cout << "i: " << i << endl;
            cout << "Dividing by: " << i << endl;
            if (i == lim && lim != 4){  //userNum == 4 / 2 means lim == 2, which means i == lim and the function returns prime
                cout << userNum << " is prime!\n";
                break;
            } else if (i == 2 && userNum % i == 0) {
                cout << userNum << " is divisible by " << i << "! Not a prime number.\n";
                break;
            } else if (i % 2 == 0 && i > 2) {
                //cout << userNum << " is divisible by " << i << "! Not a prime number.\n";
                continue;
            } else if (i % 3 == 0 && i > 3) {
                //cout << userNum << " is divisible by " << i << "! Not a prime number.\n";
                continue;
            } else if (i % 5 == 0 && i > 5) {
                //cout << userNum << " is divisible by " << i << "! Not a prime number.\n";
                continue;
            } else if (i % 7 == 0 && i > 7) {
                //cout << userNum << " is divisible by " << i << "! Not a prime number.\n";
                continue;
            } else if (userNum % i == 0) {
                cout << userNum << " is divisible by " << i << "! Not a prime number.\n";
                break;
            } else {
                //cout << "Dividing by: " << i << endl;
                continue;
            }
    }
    }
    return;
}
