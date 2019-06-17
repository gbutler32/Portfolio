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

public interface Payable 
{    
   double getPaymentAmount(); // calculate payment; no implementation
   String toString();         // returns objects info, overridden in class declaration
}
