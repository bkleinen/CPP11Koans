// CPP11Koans.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StopMeditating.h"


#include <iostream>

#include "AboutLambdas.h"
#include "AboutForEach.h"
using namespace std;

/**
 * About the Koans.
 */

int main() {
	cout << "Running C++11 Koans. No further output should be produced." << endl;
	cout << "==========================================================" << endl;
	try {
		AboutLambdas::meditate();
		AboutForEach::meditate();
	} catch (const StopMeditating &e) {
		cout << "catched StopMeditating." << endl;
	}
}



