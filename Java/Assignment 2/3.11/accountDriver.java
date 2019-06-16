import java.util.Scanner;

public class accountDriver
{
  public static void main(String[] args)
  {
    Scanner scan = new Scanner(System.in);
    Account test = new Account("test",1000);
    
    int input=0;
    String strIn = "";
    double douIn = 0;
    boolean end = false;
    
    System.out.println("Enter a selection:\n1)Get balance\n2)Set name\n3)Get name\n4)Withdrawl\n5)Exit");
    
    
    while(end == false)
    {
      input = scan.nextInt();
      
    if(input == 1)//get balance
    {
      System.out.println(test.getName() + " account balance: $" + test.getBalance() + "\n");
    }
    if(input == 2)//set name
    {
      System.out.println("Previous account name: "+test.getName() + "\nEnter new account name: ");
      
      strIn = scan.next();
      test.setName(strIn);
      
      System.out.println("New account name: "+test.getName());
    }
    if(input == 3)//get name
    {
      System.out.println("Account name: "+test.getName());
    }
    if(input == 4)//withdrawl
    {
      System.out.println("Enter ammount to be withdrawn: ");
      douIn= scan.nextDouble();
      System.out.println(test.withdraw(douIn));
    }
    if(input == 5)//end
    {
      end = true;
    }
    }
  }
}
