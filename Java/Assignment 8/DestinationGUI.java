/*CSCI 470    Assignment 8   Fall 2018
 * 
 * Developer: Gary Butler
 * 
 * Section: 1
 * 
 * Due Date/Time: 11/30/18 11:59pm
 * 
 * Purpose: This program uses a GUI to display a list of destinations from an input file and determine how many destinations a client
 * can travel in economy or first class
 */

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.GridLayout;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JCheckBox;
import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JList;
import java.awt.BorderLayout;
import javax.swing.JOptionPane;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.FlowLayout;
import java.awt.GridBagLayout;
import java.awt.GridBagConstraints;

public class DestinationGUI extends JFrame
{
   
  ////////////left//////////////////////
  private JList destinations;
  
  private JLabel normalMilesText;
  private JTextField normalMiles;
  
  private JLabel superMilesText;
  private JTextField superMiles;
  
  private JLabel upgradeText;
  private JTextField upgrade;
  
  private JLabel superDatesText;
  private JTextField superDates;
  
  /////////////////right////////////////////////
  
  private JLabel enterMilesText;
  private JTextField enterMiles;
  
  private JLabel selectMonthText;
  private JTextField holder;
  
  private final JPanel left;              //three panels for the checkboxes, textfields, and buttons
  private final JPanel right;
  
  private String [] destList = {"Berlin", "Hong Kong", "Hyderabad", "Sidney", "Paris", "New York", "Tokyo", "Vienna", "Washington, D.C."};
  
  DestinationGUI()
  {  
    super("Mile Redemption App");                      //set the window header
    
    left = new JPanel();                 //panel declaration
    right = new JPanel();
     
    
    
    //////////////////left////////////////////////
    
    setLayout( new GridBagLayout());        //set grid pattern for Destinations panel
    //setLayout(new FlowLayout());
    GridBagConstraints constraint = new GridBagConstraints();
    
    destinations = new JList(destList);
    //constraint.fill = GridBagConstraints.HORIZONTAL;
    constraint.gridx = 0;
    constraint.gridy = 0;
    left.add(destinations, constraint);
    /*destinations.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
    destinations.setSelectedIndex(0);*/
    
    normalMilesText = new JLabel("Normal Miles");
    constraint.gridx = 1;
    constraint.gridy = 1;
    left.add(normalMilesText, constraint);
    
    normalMiles = new JTextField(5);
    constraint.gridx = 1;
    constraint.gridy = 2;
    left.add(normalMiles, constraint);
    
    superMilesText = new JLabel("Supersaver Miles");
    constraint.gridx = 2;
    constraint.gridy = 1;
    left.add(superMilesText, constraint);
    
    superMiles = new JTextField(5);
    constraint.gridx = 2;
    constraint.gridy = 2;
    left.add(superMiles, constraint);
    
    upgradeText = new JLabel("Upgrade Cost");
    constraint.gridx = 3;
    constraint.gridy = 1;
    left.add(upgradeText, constraint);
    
    upgrade = new JTextField(5);
    constraint.gridx = 3;
    constraint.gridy = 2;
    left.add(upgrade, constraint);
    
    superDatesText = new JLabel("Supersaver Dates");
    constraint.gridx = 4;
    constraint.gridy = 1;
    left.add(superDatesText, constraint);
    
    superDates = new JTextField(5);
    constraint.gridx = 4;
    constraint.gridy = 2;
    left.add(superDates, constraint);
    
    ///////////////////right///////////////////////////
    
    //layout2 = new GridLayout(1,2,5,5);          //second grid pattern for text input fields
    //setLayout(layout2);
    
      enterMilesText = new JLabel("Enter your miles");
      enterMiles = new JTextField(5);
    
      right.add(enterMilesText);
      right.add(enterMiles);
    
    add(left,BorderLayout.LINE_START);            //add panels to main JFrame
    add(right,BorderLayout.LINE_END);
    
    TextFieldHandler tHandle = new TextFieldHandler();  //delcare listeners for text input
    
    
  }
  private class TextFieldHandler implements ActionListener   //allow a popup window for entered string to be output
  {
    @Override
    public void actionPerformed(ActionEvent event)
    {
      String output = "";
      
      /*if(event.getSource() == xInput)
      {
        output = ("xInput: " + event.getActionCommand());
      }
      
      if(event.getSource() == yInput)
      {
        output = ("yInput: " + event.getActionCommand());
      }*/
      
      JOptionPane.showMessageDialog(null,output);
    }
  }
}
