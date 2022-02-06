import java.util.*;

class peakFindingMaxSearch{
    static int n;
    static int a[]=new int[n];
    static int peaks[]=new int[n];
    static int counter=0;
    static void peakFinder(int ele, int pos){
        if(pos>0&&pos<n-1){
        if(ele>a[pos-1]&&ele>a[pos+1])
        peaks[counter++]=ele;
        if(pos-2>=0&&ele>=a[pos-1])
        peakFinder(a[pos-2], pos-2);
        else if(pos-1>=0&&ele<a[pos-1])
        peakFinder(a[pos-1], pos-1);
        if(pos+2<=n-1&&pos+2>n/2&&ele>=a[pos+1])
        peakFinder(a[pos+2], pos+2);
        else if(pos+1<=n-1&&pos+1>n/2&&ele<a[pos+1])
        peakFinder(a[pos+1], pos+1);
        }
    }
    public static void main(String args[]){
    Scanner ob=new Scanner(System.in);
    System.out.println("Enter the number of elements");
    n=ob.nextInt();//n>2
    System.out.println("Enter the numbers");
    for(int i=0;i<n;i++){
        a[i]=ob.nextInt();
    }
    peakFinder(a[n/2], n/2);
    for(int i=0;i<counter;i++){
        if(i==counter-1)
        System.out.println("^"+peaks[i]+"^");
        else
        System.out.println("^"+peaks[i]);
    }

} 
}