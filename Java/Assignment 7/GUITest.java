/*CSCI 470    Assignment 7(12.8)   Fall 2018
 * 
 * Developer: Gary Butler
 * 
 * Section: 1
 * 
 * Due Date/Time: 11/7/18 11:59pm
 * 
 * Purpose: This program uses a GUI to display two check boxes, two text input fields, and three buttons
 */

import javax.swing.JFrame;

public class GUI1Test
{
  public static void main(String[] args)
  {
    GUI1 test = new GUI1();                                 //delcare a GUI object
    test.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);    //allow the window to be closed with the 'x' button
    test.setSize(377,143);                                  //set default window size
    test.setVisible(true);                                  //allow the window to appear
  }
}
