//turing machine to read palindrome strings with two distinct characters
import java.io.*;

class turingMachine1{
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s;
        int i=0,l=0;
        char a[]={'0', '1', '2', '3', '4', '5', '6', '7'};
        char p, k,g=0;
        p=a[0];
        char c[]=new char[4];
        System.out.println("Enter two string symbols and the end symbol");
        for(int j=0;j<3;j++)
        c[j]=(char)br.read();
        System.out.println("Enter the string");
        s=br.readLine();                 //ERROR code
        System.out.println(s);
           while(true){
            if(p==a[7]){
                System.out.println("Palindrome "+ s);
                System.exit(0);
            }
            else{   
            k=s.charAt(i);
               if(k==c[0]&&p==a[0]){
                   if(g==0){
s='c'+s.substring(i+1);
p=a[1];
g++;}
else{
s=s.substring(0,i)+'c'+s.substring(i+1);
p=a[1];
}
               }
               if(k=='c'&&p==a[3]){
                   l=0;
                   p=a[4];
               }
               if(k==c[2]&&p==a[1]){
p=a[2];
l=1;
               }
               if(k==c[0]&&p==a[2]){
                   p=a[3];
                   s=s.substring(0,i)+'c'+s.substring(i+1);
               }
               if(k==c[1]&&p==a[4]){
                   s=s.substring(0,i)+'d'+s.substring(i+1);
                   p=a[5];
               }
               if(k==c[0]&&p==a[5]){
                   l=1;
                   p=a[6];
               }
               if(k==c[1]&&p==a[6]){
                   s=s.substring(0,i)+'d'+s.substring(i+1);
                   p=a[1];
               }
               if(k=='d'&&p==a[1]){
                   l=0;
                   p=a[0];
               }
               if(k=='d'&&p==a[6]){
                   l=0;
                   p=a[0];
               }
               if(k==c[2]&&p==a[0]){
                   l=1;
                   p=a[7];
               }
               if(l==0)
               i++;
               else
               i--;}

           }
        }
    }
