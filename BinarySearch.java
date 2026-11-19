public class BinerySearch {
	public static void main(String[] args) {
		int a[]={10,20,30,40,50,60,70,80,90,100};
		for(int i=0;i<a.length;i++){
		System.out.println(a[i]);
		}
		int key=90;
		System.out.println("key is "+key);
     System.out.println("key is present at "+Serchingkey(a,key)+" index");
		
	}

public static int Serchingkey(int a[],int key)
{
    int l=0,h=a.length-1;
   int mid=0;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==a[mid])
        {
            return mid;
            }
            else if(key <a[mid]){
            h=mid-1;
            }
            else{
            l=mid+1;
            }
              }
              return -1;
              
}
}