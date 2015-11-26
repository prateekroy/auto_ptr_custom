#include <iostream>
#include "auto_ptr_custom.h"

#define TRACE std::cout <<  __PRETTY_FUNCTION__  << ":"<<  __LINE__ <<  "\n"
#define TEST std::cout << "-------------------------------------"<<  "\n";
#define TEST_END std::cout << "================================ "<<  "\n";

class Foo{
public:
	Foo(){
		TRACE;	
	}
	~Foo(){
		TRACE;	
	}
	
	void hello(){
		TRACE;
		
	}
};

class FooDeleter{
public:
	void operator()( Foo*obj){
		TRACE;
		delete obj;
	}		
};


int main(){

	
	TEST
	{	
		typedef stdxx::auto_ptr_custom<Foo> FooPtr;

		FooPtr fooPtr( new Foo);
		fooPtr->hello();
	}
	
	TEST
	{	
		typedef stdxx::auto_ptr_custom<Foo> FooPtr;

		FooPtr  fooPtr( new Foo);
		FooPtr  fooPtr2( fooPtr);
		
		
		FooPtr fooPtr = FooPtr( new Foo);  
		
		fooPtr2->hello();
	}
	TEST
	{
		typedef stdxx::auto_ptr_custom<Foo, FooDeleter> FooPtr;

		FooPtr fooPtr( new Foo);
		fooPtr->hello();
	}
	
	TEST
	{
		typedef stdxx::auto_ptr_custom<Foo, FooDeleter> FooPtr;

		FooPtr  fooPtr( new Foo);
		FooPtr  fooPtr2( fooPtr);
		
		
		FooPtr fooPtr = FooPtr( new Foo);  
		
		fooPtr2->hello();
	}	
		
	TEST_END;
	
	return 0;	
}
