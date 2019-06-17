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
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Rectangle;


  
public class Test extends JFrame
{
  
  private final JPanel left;              //three panels for the checkboxes, textfields, and buttons
  private final JPanel right;
  
  //////////left///////////////////////
  private JLabel normalMilesText;
  private JTextField normalMiles;
  
  private JLabel superMilesText;
  private JTextField superMiles;
  
  private JLabel upgradeText;
  private JTextField upgrade;
  
  private JLabel superDatesText;
  private JTextField superDates;
  
  private JList destinations;
  
  private String [] destList = {"Berlin", "Hong Kong", "Hyderabad", "Sidney", "Paris", "New York", "Tokyo", "Vienna", "Washington, D.C."};
  
  
  Test()
  {
  super("Mile Redemption App");                      //set the window header
    
  
  left = new JPanel();                 //panel declaration
  right = new JPanel();
  
  destinations = new JList(destList);
  
  //left.setLayout(new GridLayout(1,0));
  
  
  
  left.add(destinations, new Rectangle(0,0,1,1));
  
    normalMilesText = new JLabel("Normal Miles");
    left.add(normalMilesText, new Rectangle(2,0,1,1));
    
    normalMiles = new JTextField(5);
    left.add(normalMiles, new Rectangle(2,1,1,1));
    
    left.setBackground(Color.green);
  left.setPreferredSize(new Dimension(300,100));
  add(left,BorderLayout.LINE_START);   //,BorderLayout.LINE_START
  
  right.setBackground(Color.blue);
  right.setPreferredSize(new Dimension(300,100));
  add(right,BorderLayout.LINE_END);  //,BorderLayout.LINE_END
  }  
}
