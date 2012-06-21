#include "stdafx.h"
#include "AboutLambdas.h"
#include "Assert.h"

#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;


AboutLambdas::AboutLambdas(void)
{
}
void aboutSimplestLambda(){
	auto func = [] {return 2;};
	expectThat("this simply returns 2",2,func());
}
void aboutLambdaHelloWorld(){
	// todo: replace cout
	auto func = [] () { cout << "Hello world" << endl; };
    func(); // now call the function
}


void aboutCapturingLocalVariables1()
{
	int i = 13;
	function<int(void)> ff = [&] (void) -> int { return ++i;};
	expectThat("this increases i by one",14,ff());
	expectThat("and one more",15,ff());
	expectThat("i indeed has changed",15,i);

}

function<int ()> createCounter1(int initialValue){
	int n1 = initialValue;
	auto func = [&] () -> int{ return ++n1;};
	return func;
}
function<int ()> createCounter2(int initialValue){
	int n1 = initialValue;
	int *n = &n1;

	auto func = [n] () -> int{ return ++(*n);};
	return func;
}
void aboutCapturingLocalVariables2()
{
    auto counter = createCounter1(24);
	expectThatNot("the local variable is out of scope and not existent anymore!",25,counter());
    auto counter2 = createCounter2(24);
	expectThatNot("using pointer's doesn't help",25,counter());
	};



void AboutLambdas::meditate() {
	aboutSimplestLambda();
	aboutLambdaHelloWorld();
	aboutCapturingLocalVariables1();
	aboutCapturingLocalVariables2();

}


// 


