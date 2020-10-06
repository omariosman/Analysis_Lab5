/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<ctime>
using namespace std;




int counter = 1;
int comp2 = 0;
void heapify(int arr[], int n, int i) 
{ 
   
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2;
    
    if (l < n) {
        comp2++;
        if ( arr[l] > arr[largest]) {
            largest = l; 
        
        }
    }  
  
    if (r < n){
        comp2++;
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

    build_heap(arr, n);
     
     

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

void reverseArray(int *myArr, int n){
    int *tempArr;
    tempArr = new int[n];
    int k = n - 1;
    for (int i = 0; i < n; i++){
        tempArr[i] = myArr[k];
        k--;
    }
    
    for (int i = 0; i < n; i++){
        myArr[i] = tempArr[i];
    }

}

int main()
{
    int *myArray1;
    myArray1 = new int[50];
    
    int *myArray2;
    myArray2 = new int[50];
    
    cout << "n" << "    " << "heap sort" << "    " << "insertion sort" << endl;
    //Sorted
    cout << "Sorted" << endl;
    for (int i = 1; i <= 50; i++){
        for (int j = 0; j < i; j++){
            myArray1[j] = j; 
        }
        
        comp2 = 0;
        heap_sort(myArray1, i);
        cout << i << ".   ";
        cout << comp2 << "                ";
        cout << insertion_sort_count_comparisons(myArray1, i) << endl;

    }
    cout << endl << endl;
    cout << "Inversely Sorted" << endl;
    cout << "n" << "    " << "heap sort" << "    " << "insertion sort" << endl;


    //inversely sorted
    for (int i = 1; i <= 50; i++){
        for (int j = 0; j < i; j++){
            myArray2[j] = j; 
            

        }
        reverseArray(myArray2, i);

        comp2 = 0;
        heap_sort(myArray2, i);
        cout << i << ".   ";
        cout << comp2 << "                ";
        reverseArray(myArray2, i);
        cout << insertion_sort_count_comparisons(myArray2, i) << endl;

        
    }   

    cout << endl << endl;
    cout << "Randomly Sorted" << endl;
    cout << "n" << "    " << "heap sort" << "    " << "insertion sort" << endl;
    //randomely sorted
    for (int i = 1; i <= 50; i++){
        for (int j = 0; j < i; j++){
            int random_num = (rand() % 50) + 1;

            myArray2[j] = random_num; 
            myArray1[j] = random_num;

        }

        comp2 = 0;
        heap_sort(myArray2, i);
        cout << i << ".   ";
        cout << comp2 << "                ";
        cout << insertion_sort_count_comparisons(myArray1, i) << endl;

        
    }   

}
