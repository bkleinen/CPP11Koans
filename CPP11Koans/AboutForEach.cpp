#include "stdafx.h"
#include "AboutForEach.h"
#include "Assert.h"
#include <vector>
#include <algorithm>


AboutForEach::AboutForEach(void)
{
}
/*
Example from
http://msdn.microsoft.com/en-us/library/e5sk9w9k.aspx
*/
void aboutForEach(){
}

// example from http://msdn.microsoft.com/en-us/library/dd293603.aspx
int countEven() 
{
   // Create a vector object that contains 10 elements.
   vector<int> v;
   for (int i = 0; i < 10; ++i) 
   {
      v.push_back(i);
   }

   // Count the number of even numbers in the vector by 
   // using the for_each function and a lambda expression.
   int evenCount = 0;
   for_each(v.begin(), v.end(), [&evenCount] (int n) {
      
      if (n % 2 == 0) 
      {
         evenCount++;
      }
      else 
      {
      }
   });

   return evenCount;
}

 int countEven();
void aboutVectorApplication(){
	expectThat("the vector in the example has... even numbers",5,countEven());
}

void AboutForEach::meditate() {
  aboutForEach();
  aboutVectorApplication();
 

}