#ifndef _auto_ptr_cust_h_
#define _auto_ptr_cust_h_


namespace stdxx{

template<typename T>
class default_del{
public:
	void operator()(T* obj){
		delete obj;
	}
};	

template<typename T, typename Deleter=default_del<T> >
class auto_ptr_custom{
public:		
	auto_ptr_custom(T* ptr):_ptr(ptr){
	}	
	
	auto_ptr_custom(auto_ptr_custom& copyMe) : _ptr( copyMe.release() ) { 
	}
	
	auto_ptr_custom& operator=(auto_ptr_custom<T,Deleter>& rhs) { 
		_ptr = rhs.release();
   		return *this;
	}
	
        ~auto_ptr_custom() { 
		if(_ptr){
			Deleter deleter;
			deleter(_ptr);
		}
	}
       
    T&  operator*(){
		return *_ptr; 
    }
       
    T* operator->() {
		return _ptr; 
    }
       
    T* get() { return _ptr; }
       

    T* release(){
		T* tmp = _ptr;
		_ptr = 0;
		return tmp;
    }
       
private:
	T* _ptr;
};
	
}

#endif
