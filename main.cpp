#include <graphics.h>
#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

#define MAX 1000

int array_size;
int array_range;
int page=0;
int LEFT;
int comparison;

	


void visual(int arr[],int fIndex, int sIndex,int dTime,string sortname,int comp)
{
	settextstyle(SANS_SERIF_FONT, 0,2);
	
	char *cc = &*sortname.begin();
	outtextxy(50,35,cc);
	
	std::string s0;
	std::stringstream ss0;
	ss0 << array_size;
	s0 = ss0.str();
	string d0 = "No. of Elements = "+s0;
	char *c0 = &*d0.begin();
	outtextxy(50,60,c0);

	std::string s1;
	std::stringstream ss1;
	ss1 << comp;
	s1 = ss1.str();
	string d1 = "No. of Comparisons = "+s1;
	char *c1 = &*d1.begin();
	outtextxy(50,85,c1);

		
	std::string s2;
	std::stringstream ss2;
	ss2 << dTime;
	s2 = ss2.str();
	string d2 = "Delay(in ms) = "+s2;
	char *c2 = &*d2.begin();
	outtextxy(50,110,c2);
	
	setactivepage(page);
	setvisualpage(1-page);
	cleardevice();
	for(int it=0;it<array_size;it++)
	{
		int width = LEFT/array_size;
		int left = 200 + it*width;
		int right = left+width;
		int bottom = array_range+50;
		int top = bottom-arr[it];	
		if(it==fIndex)
		{
			setfillstyle(SOLID_FILL,RED);
			bar(left,top,right,bottom);		
		}else if(it==sIndex)
		{
			setfillstyle(SOLID_FILL,BLUE);
			bar(left,top,right,bottom);		
		}else
		{
			setfillstyle(SOLID_FILL,WHITE);
			bar(left,top,right,bottom);
		}
		
	}
	page = 1-page;
	delay(dTime);
}


void swap(int *xp,int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void BubbleSort(int arr[])
{
	for(int i=0;i<array_size-1;i++)
	{
		for(int j=0;j<array_size-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
			}
			comparison++;
			visual(arr,j,j+1,1,"Bubble Sort",comparison);
		}
	}
	cout<<comparison<<endl;
}

void SelectionSort(int arr[])
{
	int min_idx;
	for(int i=0;i<array_size-1;i++)
	{
		min_idx=i;
		for(int j=i+1;j<array_size;j++)
		{
			if(arr[j]<arr[min_idx])
			{
				min_idx=j;
			}
			comparison++;
			visual(arr,min_idx,j,1,"Selection Sort",comparison);
		}
		swap(&arr[min_idx],&arr[i]);
	}
}

void InsertionSort(int arr[]) 
{ 
	int n = array_size;
    int i, key, j; 
    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
            comparison++;
            visual(arr,i,j,1,"Insertion Sort",comparison);
        } 
        arr[j + 1] = key;
		 
    } 
} 

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m;
	
	visual(arr,l,r,1,"Merge Sort",comparison); 
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0; 
    j = 0;
    k = l;
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++;
        comparison++;
		visual(arr,l+i,m+j,1,"Merge Sort",comparison); 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    	visual(arr,l+i,k,1,"Merge Sort",comparison); 
    }
	 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    	visual(arr,m+j,k,1,"Merge Sort",comparison); 
    } 
} 
  
void MergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2;
        MergeSort(arr, l, m); 
        MergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 
} 

int partition(int arr[], int low, int high) 
{ 
    int pivot = arr[high];
	int i = (low - 1);
	
    for (int j = low; j <= high- 1; j++) 
    { 
        if (arr[j] <= pivot) 
        { 
            i++;
            comparison++;
            swap(&arr[i], &arr[j]); 
        }
		visual(arr,pivot,j,1,"Quick Sort",comparison); 
    } 
    visual(arr,i+1,high,1,"Quick Sort",comparison);
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
void QuickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high);   
        QuickSort(arr, low, pi - 1); 
        QuickSort(arr, pi + 1, high); 
    } 
} 


void heapify(int arr[], int n, int i) 
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
  
    
    if (l < n && arr[l] > arr[largest]) 
        largest = l;
    
    if (r < n && arr[r] > arr[largest]) 
        largest = r;
    
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
        heapify(arr, n, largest); 
        comparison++;
        visual(arr,i,largest,1,"Heap Sort",comparison);
    } 
} 
  
void HeapSort(int arr[]) 
{ 
	int n = array_size;
    for (int i = n / 2 - 1; i >= 0; i--) 
    {
        heapify(arr, n, i); 
	}
  
    for (int i=n-1; i>=0; i--) 
    { 
        swap(arr[0], arr[i]); 
  
        heapify(arr, i, 0); 
    } 
} 
  
int getMax(int arr[], int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > mx) 
            mx = arr[i]; 
	}
    return mx; 
} 
  
void countSort(int arr[], int n, int exp) 
{ 
    int output[n]; 
    
    int i, count[10] = {0}; 
  
    for (i = 0; i < n; i++) 
        count[ (arr[i]/exp)%10 ]++,comparison++;
  
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1],comparison++;
  
    for (i = n - 1; i >= 0; i--) 
    { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
        comparison++;
    } 
  
    for (i = 0; i < n; i++) 
    {
        arr[i] = output[i];
        comparison++;
		visual(arr,-1,-1,2,"Radix Sort",comparison); 
    	
	}
} 
  
void RadixSort(int arr[]) 
{ 
	int n = array_size;
    int m = getMax(arr, n); 
  
    for (int exp = 1; m/exp > 0; exp *= 10) 
        countSort(arr, n, exp),visual(arr,-1,-1,1,"Radix Sort",comparison);
} 


void oddEvenSort(int arr[]) 
{ 
	int n = array_size;
    bool isSorted = false;
	
    while (!isSorted) 
    { 
        isSorted = true; 
  
        // Perform Bubble sort on odd indexed element 
        for (int i=1; i<=n-2; i=i+2) 
        { 
            if (arr[i] > arr[i+1]) 
             { 
                swap(arr[i], arr[i+1]); 
                isSorted = false; 
             }
			 comparison++;
			 visual(arr,i,i+1,1,"Odd/Even Sort",comparison); 
        } 
  
        // Perform Bubble sort on even indexed element 
        for (int i=0; i<=n-2; i=i+2) 
        { 
            if (arr[i] > arr[i+1]) 
            { 
                swap(arr[i], arr[i+1]); 
                isSorted = false; 
            } 
			 comparison++;
			 visual(arr,i,i+1,1,"Odd/Even Sort",comparison);
        } 
    } 
    return; 
} 

void stoogesort(int arr[], int l, int h) 
{
	 
    if (l >= h) 
        return; 
  
    if (arr[l] > arr[h]) 
        swap(arr[l], arr[h]); 
    comparison++;
    visual(arr,l,h,1,"Stooge Sort",comparison);
  
    if (h - l + 1 > 2) { 
        int t = (h - l + 1) / 3; 
  
        stoogesort(arr, l, h - t); 
        stoogesort(arr, l + t, h); 
        stoogesort(arr, l, h - t); 
    } 
} 


void gnomeSort(int arr[]) 
{ 
	int n = array_size;
    int index = 0; 
  
    while (index < n) { 
        if (index == 0) 
            index++; 
        if (arr[index] >= arr[index - 1]) 
            index++; 
        else { 
            swap(arr[index], arr[index - 1]); 
            index--; 
        }
		comparison++;
		visual(arr,index,index-1,1,"Gnome Sort",comparison);
    } 
    return; 
} 

main()
{
	
	DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
	
	initwindow(screenWidth,screenHeight,"Sorting");	
	
	delay(5000);
	
	array_range = screenHeight-100;
	LEFT = screenWidth-300;
	array_size = 450;
	
	int main_array[MAX];
	
	for(int i=0;i<array_size;i++)
	{
		main_array[i] = rand()%array_range;
	}
	int array[MAX];
	
	copy(main_array,main_array+array_size,array);
	array_size = 60;
	comparison=0;
	visual(array,-1,-1,1,"Bubble Sort",comparison);
	BubbleSort(array);
	
	copy(main_array,main_array+array_size,array);
	array_size = 60;
	comparison=0;
	visual(array,-1,-1,1,"Selection Sort",comparison);
	SelectionSort(array);
	
	copy(main_array,main_array+array_size,array);
	array_size = 80;
	comparison=0;
	visual(array,-1,-1,1,"Insertion Sort",comparison);
	InsertionSort(array);
	
	array_size=300;
	
	copy(main_array,main_array+array_size,array);
	comparison=0;
	visual(array,-1,-1,1,"Merge Sort",comparison);
	MergeSort(array,0,array_size-1);
	
	copy(main_array,main_array+array_size,array);
	comparison=0;
	visual(array,-1,-1,1,"Quick Sort",comparison);
	QuickSort(array,0,array_size-1);
	
	copy(main_array,main_array+array_size,array);
	comparison=0;
	visual(array,-1,-1,1,"Heap Sort",comparison);
	HeapSort(array);
	
	copy(main_array,main_array+array_size,array);
	comparison=0;
	visual(array,-1,-1,1,"Radix Sort",comparison);
	RadixSort(array);
	
	array_size = 60;
	copy(main_array,main_array+array_size,array);
	comparison=0;
	visual(array,-1,-1,1,"Odd/Even Sort",comparison);
	oddEvenSort(array);
	
	array_size = 60;
	copy(main_array,main_array+array_size,array);
	comparison=0;
	visual(array,-1,-1,1,"Gnome Sort",comparison);
	gnomeSort(array);
	
	
	
	
	
	
	
	getch();

}
