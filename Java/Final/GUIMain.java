/*CSCI 470    Assignment 9   Fall 2018
 * 
 * Developer: Gary Butler
 * 
 * Section: 1
 * 
 * Due Date/Time: 12/10/2018 2:00pm
 * 
 * Purpose: This program creates two animations that display sorting algorithms
 */

import javax.swing.JFrame;
import java.awt.GridLayout;

public class GUIMain
{
  public static void main(String[] args)
  {
    JFrame main = new JFrame("Sorting Animation");               //main jframe
    main.setLayout(new GridLayout(1,2));                         
    SortObject left = new SortObject();                          //
    SortObject right = new SortObject();                         //create both panels
    
    main.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    main.setSize(740,427);
    
    main.add(left);                                              //
    main.add(right);                                             //add panels to jframe
    
    main.setVisible(true);

  }
}
