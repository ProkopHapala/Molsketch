
#ifndef  prokop_utils_h
#define  prokop_utils_h

#include <cstdlib>
#include <stdio.h>

#define _template_Func   template<typename Func>
#define _template_T      template<typename T>
#define _template_N      template<size_t N>
#define _template_TN     template<typename T,size_t N>
#define _inline_T        template<typename T> inline

#define SWAP( a, b, TYPE ) { TYPE t = a; a = b; b = t; }
_inline_T void _swap  (T& a, T& b) { T t=a; a=b; b=t;   }
_inline_T void _order (T& a, T& b) { if(a>b){T t=a; a=b; b=t; }; }
//_inline_T void _order (T& a, T& b) { if(a>b)_swap(a,b); }



_inline_T bool _allocIfNull(T*& arr, int n){ if(arr==0){ arr=new T[n]; return true; } return false; }
_inline_T void _alloc  (T*& arr, int n){ arr=new T[n]; }
_inline_T void _realloc(T*& arr, int n){ if(arr){ delete [] arr; } arr=new T[n]; }
_inline_T void _dealloc(T*& arr       ){ if(arr){ delete [] arr; } arr=0;        }
_inline_T bool _bindOrRealloc(int n, T* from, T*& arr ){ if(from){ arr=from; return false; }else{ _realloc(arr,n); return true; } }

_inline_T void _realloc0(T*& arr, int n, const T& v0){  _realloc(arr,n); for(int i=0;i<n;i++){ arr[i]=v0; } }

struct int4   { int x,y,z,w; };


const  float INV_RAND_MAX = 1.0f/RAND_MAX;
inline float randf(){
    // int r = rand(); 
    // printf( "RAND_MAX[%i] %i \n", irand, r );  
    // irand++;  
    // return INV_RAND_MAX*r; 
    return INV_RAND_MAX*rand(); 
}
inline float randf( float min, float max ){ return randf()*( max - min ) + min; }

#endif


