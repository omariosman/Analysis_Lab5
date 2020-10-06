/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;



int counter = 1;
void heapify(int arr[], int n, int i) 
{ 
   
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2;
    
    if (l < n) {
        cout << counter << ". ";
        counter++;
        cout << arr[largest] << " < " << arr[l] << endl;
        if ( arr[l] > arr[largest]) {
            largest = l; 
        
        }
    }  
  
    if (r < n){
        cout << counter << ". ";
        counter++;
        cout << arr[largest] << " < " << arr[r] << endl;
        if (arr[r] > arr[largest]) {
            largest = r; 
        }
    }
   
    if (largest != i) { 
        swap(arr[i], arr[largest]); 
        heapify(arr, n, largest); 
        } 
}


void build_heap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i);
}
  
int heap_sort(int arr[], int n) 
{
    cout << "Comparisons of build heap: " << endl;
    
    build_heap(arr, n);
     
     
    cout << "Comparisons after build heap: " << endl;

    for (int i = n - 1; i >= 0; i--) { 
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0); 
    } 
    
    
} 



int insertion_sort_count_comparisons(int* arr, int n)  
{  
    int comp = 0;
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
      do {
          comp++;
          if (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }
      } while(j >= 0 && arr[j] > key);
   
        arr[j + 1] = key;  
    }  
    return comp;
} 

int main()
{
    int arr [10] = {4,1,3,2,16,9,10,14,8,7};
    int n = 10; //size of array
    heap_sort(arr, n);
    
    
}
