/*
	Assignment 2, Question 2 code
	Author: Adrian Harminto
	SSID: 861-07-4419
	Output message: AN EYE FOR AN EYE ONLY ENDS UP MAKING THE WHOLE WORLD BLIND
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main(){
	// P = (e, n) = (11,85)
	// 85 -> 5*17, so p*q will be 4*16 = 64
	int x[60], //bc we will have 60 pieces of data
	powerof = 35, //d = e^(-1)(mod 72) = 64^(-1)(mod 72) = 35
	mod = 85; // value of n
	
	//the given table that we need to encrypt
	int data [] =
	{	45, 52, 8, 49, 74, 49,
		8, 20, 59, 28, 8, 45,
		52, 8, 49, 74, 49, 8,
		59, 52, 16, 74, 8, 49,
		52, 2, 22, 8, 70, 75,
		8, 68, 45, 60, 72, 52,
		46, 8, 14, 23, 49, 8,
		3, 23, 59, 16, 49, 8,
		3, 59, 28, 16, 2, 8,
		56, 16, 72, 52, 2, 64 }; //60 pieces
	
	//To tell the program that 2 is blank, 3 is comma, 4 is dot, 5 is A, etc
	string conversion [] = { "", "", //first empty 0th and 1st array
		" ", ",", ".", "A", "B", "C", "D", "E","F","G","H","I",
		"J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
	
	//Converting each data
	for (int i=0; i<60; i++) {
		x[i] = 1;
		while(powerof != 1) {
			if (powerof%2 ==1) //means odd
			{
				x[i]*=data[i]; powerof--;
				x[i] = x[i]%mod;
			}
			else if (powerof%2 ==0) {//means even
				data[i]*=data[i]; powerof/=2;
				data[i]=data[i]%mod;
			}
		}
		powerof = 35;
	}
	
	//Now we match the decrypted message to conversion array
	for (int i=0; i<60;i++) {
		cout<<conversion[x[i]];
	}
	//result: AN EYE FOR AN EYE ONLY ENDS UP MAKING THE WHOLE WORLD BLIND
	
	return 0;
}