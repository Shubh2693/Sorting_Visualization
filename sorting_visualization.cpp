#include <graphics.h>
#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

#define MAX 1000

int page=0;
int LEFT;
int array_range;
int main_array[1000]={0};

	
class Sorting
{
	public:
		int array_size;
		int comparison = 0;
		int arr[1000];
		Sorting(int a1): array_size(a1)
		{
			copy(main_array,main_array+array_size,arr);
		}
		
		~Sorting()
		{
			cout<<"Object Deleted";
		}
			
		// Member Functions
		
		void visual(int fIndex, int sIndex,int dTime,string sortname);
		void swap(int *xp,int *yp);
		void BubbleSort();
		void SelectionSort();
		void InsertionSort();		
		void merge(int l, int m, int r); 
		void MergeSort(int l, int r) ;
		int partition(int low, int high); 
		void QuickSort(int low, int high); 
		void heapify(int n, int i); 
		void HeapSort();
		int getMax(int n); 
		void countSort(int n, int exp); 
		void RadixSort(); 
		void oddEvenSort();
		void gnomeSort();

};


void Sorting::visual(int fIndex, int sIndex,int dTime,string sortname)
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
	ss1 << comparison;
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
				
void Sorting::swap(int *xp,int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
		
void Sorting::BubbleSort()
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
			visual(j,j+1,1,"Bubble Sort");
		}
	}
}
			
void Sorting::SelectionSort()
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
			visual(min_idx,j,1,"Selection Sort");
		}
		swap(&arr[min_idx],&arr[i]);
	}

}

void Sorting::InsertionSort() 
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
            visual(i,j,1,"Insertion Sort");
        } 
        arr[j + 1] = key;		 
    } 
} 

void Sorting::merge(int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m;
	
	visual(l,r,1,"Merge Sort"); 
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
		visual(l+i,m+j,1,"Merge Sort"); 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    	visual(l+i,k,1,"Merge Sort"); 
    }
	 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    	visual(m+j,k,1,"Merge Sort"); 
    } 
} 

	  
void Sorting::MergeSort(int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2;
        MergeSort(l, m); 
        MergeSort(m+1, r); 
        merge(l, m, r); 
    } 
} 
		
int Sorting::partition(int low, int high) 
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
		visual(pivot,j,1,"Quick Sort"); 
    } 
    visual(i+1,high,1,"Quick Sort");
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

		  
void Sorting::QuickSort(int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(low, high);   
        QuickSort(low, pi - 1); 
        QuickSort(pi + 1, high); 
    } 
} 


void Sorting::heapify(int n, int i) 
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
        swap(&arr[i], &arr[largest]); 
        heapify(n, largest); 
        comparison++;
        visual(i,largest,1,"Heap Sort");
    } 
} 
  
void Sorting::HeapSort() 
{ 
	int n = array_size;
    for (int i = n / 2 - 1; i >= 0; i--) 
    {
        heapify(n, i); 
	}
  
    for (int i=n-1; i>=0; i--) 
    { 
        swap(&arr[0],&arr[i]); 
  
        heapify(i, 0); 
    } 
}

 
int Sorting::getMax(int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > mx) 
            mx = arr[i]; 
		comparison++;
	}
    return mx; 
} 
  
void Sorting::countSort(int n, int exp) 
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
		visual(-1,-1,2,"Radix Sort"); 
    	
	}
} 
  
void Sorting::RadixSort() 
{ 
	int n = array_size;
    int m = getMax(n); 
  
    for (int exp = 1; m/exp > 0; exp *= 10) 
        countSort(n, exp),visual(-1,-1,1,"Radix Sort");
} 
		

void Sorting::oddEvenSort() 
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
                swap(&arr[i], &arr[i+1]); 
                isSorted = false; 
             }
			 comparison++;
			 visual(i,i+1,1,"Odd/Even Sort"); 
        } 
  
        // Perform Bubble sort on even indexed element 
        for (int i=0; i<=n-2; i=i+2) 
        { 
            if (arr[i] > arr[i+1]) 
            { 
                swap(&arr[i], &arr[i+1]); 
                isSorted = false; 
            } 
			 comparison++;
			 visual(i,i+1,1,"Odd/Even Sort");
        } 
    } 
    return; 
} 

		
void Sorting::gnomeSort() 
{ 
	int n = array_size;
    int index = 0; 
  
    while (index < n) { 
        if (index == 0) 
            index++; 
        if (arr[index] >= arr[index - 1]) 
            index++; 
        else { 
            swap(&arr[index], &arr[index - 1]); 
            index--; 
        }
		comparison++;
		visual(index,index-1,1,"Gnome Sort");
    } 
    return; 
} 
		

int main()
{
	
	DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
	DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
	
	initwindow(screenWidth,screenHeight,"Sorting");	
	
	delay(2000);
	
	array_range = screenHeight-100;
	LEFT = screenWidth-300;
	
	for(int i=0;i<900;i++)
	{
		main_array[i] = rand()%array_range;
	}
	
	
	Sorting Obj1(60);
	Obj1.visual(-1,-1,1,"Bubble Sort");
	Obj1.BubbleSort();
	
	Sorting Obj2(60);
	Obj2.visual(-1,-1,1,"Selection Sort");
	Obj2.SelectionSort();
	
	Sorting Obj3(80);
	Obj3.visual(-1,-1,1,"Insertion Sort");
	Obj3.InsertionSort();
	
	Sorting Obj4(300);
	Obj4.visual(-1,-1,1,"Merge Sort");
	Obj4.MergeSort(0,299);
	
	Sorting Obj5(300);
	Obj5.visual(-1,-1,1,"Quick Sort");
	Obj5.QuickSort(0,299);
	
	Sorting Obj6(300);
	Obj6.visual(-1,-1,1,"Heap Sort");
	Obj6.HeapSort();
	
	Sorting Obj7(300);
	Obj7.visual(-1,-1,1,"Radix Sort");
	Obj7.RadixSort();
	
	Sorting Obj8(60);
	Obj8.visual(-1,-1,1,"Odd/Even Sort");
	Obj8.oddEvenSort();
	
	Sorting Obj9(60);
	Obj9.visual(-1,-1,1,"Gnome Sort");
	Obj9.gnomeSort();

	getch();

	return 0;
}

