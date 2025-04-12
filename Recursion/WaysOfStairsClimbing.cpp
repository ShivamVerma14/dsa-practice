/*
You have been given a number of stairs. Initially, you are at the 0th stair, and you need to
reach the nth stair. Each time you can either climb one step or two steps. You are supposed
to return the number of distinct ways in which you can climb from the 0th step to nth step.
*/

#include <iostream>
using namespace std;

int count_ways(int stairs) {
    if (stairs < 0) 
        return 0;

    if (stairs == 0)
        return 1;

    return count_ways(stairs - 1) + count_ways(stairs - 2);
}

int main() {
    int stairs;
    cin >> stairs;

    int ways = count_ways(stairs);
    cout << ways;

    return 0;
}