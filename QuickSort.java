import java.util.Arrays;
public class QuickSort {
	public static int partition(int a[],int low,int high){
	    int pivot=a[high];
	   int i=low-1;
	    for(int j=low;j<high;j++){
	        if(a[j]<pivot){
	            i++;
	            int temp=a[i];
	            a[i]=a[j];
	            a[j]=temp;
	            }
	           }
	           i++;
	           int temp=a[i];
	           a[i]=a[high];
	           a[high]=temp;
	           return i;
}
	public static void QuickSort(int a[],int low,int high){
	    if(low<high)
	    {
	        int pidx=partition(a,low,high);
	        QuickSort(a,low,pidx-1);
	        QuickSort(a,pidx+1,high);
	        }
	        }
	public static void main(String[] args) {
		int a[]={30,20,60,80,40,100,50,70,10,90};
		System.out.println("elements in array\n"+Arrays.toString(a));
		
		int n=a.length;
		QuickSort(a,0,n-1);
		System.out.println("elements are sorted");
		for(int i=0;i<n;i++){
		    System.out.println(a[i]);
		    }
		    System.out.println();
		
		
	}
}