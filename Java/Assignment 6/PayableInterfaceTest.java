/*CSCI 470    Assignment 6   Fall 2018
 * 
 * Developer: Gary Butler
 * 
 * Section: 1
 * 
 * Due Date/Time: 10/19/18 11:59pm
 * 
 * Purpose: This program creates objects that impliment the payable class and outputs them. If the class if of the
 * type "BasePlusCommissionEmployee" the base salary is increased by 10%
 */

public class PayableInterfaceTest 
{
   public static void main(String[] args)
   {
      // create six-element Payable array
      Payable[] payableObjects = new Payable[6];
      
      // populate array with objects that implement Payable
      payableObjects[0] = new Invoice("01234", "seat", 2, 375.00);
      payableObjects[1] = new Invoice("56789", "tire", 4, 79.95);
      payableObjects[2] = 
         new SalariedEmployee("John", "Smith", "111-11-1111", 800.00);
      payableObjects[3] = 
         new HourlyEmployee("Lisa", "Barnes", "888-88-8888", 40.00,40);
      payableObjects[4] = 
         new CommissionEmployee("Homer", "Simpson", "123-45-6789", 4000,.9);
      payableObjects[5] = 
         new BasePlusCommissionEmployee("Montgomery", "Burns", "000-00-0002", 40000000.00,.9,1000000);
      

      System.out.println(
         "Invoices and Employees processed polymorphically:"); 

      // generically process each element in array payableObjects
      for (Payable currentPayable : payableObjects)
      {
        // output currentPayable and its appropriate payment amount
         System.out.println(currentPayable.toString());
         
        if(currentPayable instanceof BasePlusCommissionEmployee)   //check if this object is BasePlusCommissionEmployee
        {
          BasePlusCommissionEmployee current = (BasePlusCommissionEmployee) currentPayable; // cast current object to BasePlusCommissionEmployee
          
          current.setBaseSalary(1.10 * current.getBaseSalary());                        //increase base salary by 10 %
          System.out.println("Base salary + 10%: $" + current.getBaseSalary());
        }
        System.out.println("payment due $" + currentPayable.getPaymentAmount());      //output payment ammount
      } 
   } // end main
} // end class PayableInterfaceTest
