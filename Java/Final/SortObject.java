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

import java.awt.event.ActionListener;
import java.awt.event.ItemListener;
import java.awt.event.ItemEvent;
import java.awt.event.ActionEvent;
import java.awt.BorderLayout;
import java.awt.GridLayout;
import javax.swing.JFrame;
import javax.swing.JComboBox;
import javax.swing.JButton;
import javax.swing.JPanel;
import java.awt.Graphics;
import java.awt.Color;
import java.util.Random;
import java.util.concurrent.Executors;
import java.util.concurrent.ExecutorService;

public class SortObject extends JPanel
{
  private final JPanel panel;
  
  private final JButton populate;
  private final JButton sort;
  private final JComboBox<String> algo;
  private static final String[] names = {"Bubble", "Selection", "Insertion"};
  private SortPanelAnimation main;
  private ExecutorService executorService;
  
  public SortObject()
  {
        setLayout(new BorderLayout());
        executorService = Executors.newCachedThreadPool();

        panel = new JPanel();                                  //create panel and buttons
        populate = new JButton("Populate Array");              //
        sort = new JButton("Sort");                            //
        algo = new JComboBox<String>(names);                   //

        main = new SortPanelAnimation();                       //create animation

        ButtonHandler handler = new ButtonHandler();           //create handlers for button actions
        populate.addActionListener(handler);                   //add listeners for each button
        sort.addActionListener(handler);                       //
        
        algo.addItemListener(                                  //add listener for jcombobox
          new ItemListener()
          {
          @Override
          public void itemStateChanged(ItemEvent event)
          {
            if(event.getStateChange() == ItemEvent.SELECTED)
            {
              main.setMethod(algo.getSelectedIndex());
            }
          }
          }
           );

        sort.setEnabled(false);

        add(main,BorderLayout.CENTER);                           //format and add buttons and animation
        main.setVisible(false);                                  //
        JPanel grid = new JPanel(new GridLayout(1,3));           //create new jpanel for buttons
        grid.add(populate);                                      //
        grid.add(sort);                                          // 
        grid.add(algo);                                          //
        add(grid,BorderLayout.SOUTH);                            //
        
        
  }
  
  private class ButtonHandler implements ActionListener               //handler for buttons
  {
    @Override
    public void actionPerformed(ActionEvent event)
    {
      if(event.getSource() == populate)
      {
        main.reRoll();
        sort.setEnabled(true);
        populate.setEnabled(false);
        main.setVisible(true);
      }
      if(event.getSource() == sort)
      {
        
            executorService.execute(main);
            sort.setEnabled(false);
            populate.setEnabled(true);
            executorService.shutdown();
            
      }
    }
  }
  
  public class SortPanelAnimation extends JPanel implements Runnable
{
  private int[] width;
  private Random random;
  private int temp;
  private int w;
  private int h;
  private int method;
  
  public SortPanelAnimation()                   //constructor
  {
    method = 0;
    w =360;
    h =360;
    
    random = new Random();
  
    width = new int[w];
    for(int i =0; i < w; i++)
    {
      width[i] = random.nextInt(1+h);
    }
  }
  
  @Override                                     //run method that impliments each algorithm based off jcombobox selection
  public void run()
  {
    if(method == 0)                      //bubble sort
    {
    try
    {
    repaint();
    boolean again = true;
    for(int k = 0;k< width.length -1 && again; k++)
    {
      again = false;
      for(int b = 0;b < width.length-1;b++)
      {
        repaint();
        if(width[b] > width[b+1])
        {
          temp = width[b];
          width[b] = width[b+1];
          width[b+1] = temp;
          repaint();
          Thread.sleep(4);
          again = true;
        }
      }
      repaint();
    }
  }
    catch(InterruptedException e)
    {
    e.printStackTrace();
    }
    }
    
    if(method == 1)                                 //selection sort
    {
      try
      {
        for(int i = 0;i< width.length -1;i++)
        {
          int currentMin = i;
          for(int j = i+1;j<width.length;j++)
          {
            repaint();
            if(width[currentMin]>width[j])
            {
              currentMin = j;
              repaint();
            }
          }
          
          if(currentMin != i)
          {
            int temp = width[currentMin];
            width[currentMin] = width[i];
            width[i] = temp;
            repaint();
            Thread.sleep(4);
          }
        }
      }
      catch(InterruptedException e)
      {
        e.printStackTrace();
      }
      
    }
    
    if(method == 2)                                     //insertion sort
    {
      try
      {
        for(int i =1; i< width.length;i++)
        {
          int k;
          for(k = i-1; k >= 0 && width[k] > width[k+1];k--)
          {
            Thread.sleep(4);
            repaint();
            int temp = width[k+1];
            width[k+1] = width[k];
            width[k] = temp;
          }
        }
        repaint();
      }
      catch(InterruptedException e)
      {
        e.printStackTrace();
      }
    }
  }
  
@Override                                            //populate animation with lines
public void paintComponent(Graphics g)
  {
    super.paintComponent(g);
    g.setColor(Color.BLUE);
    
    
  
    for(int a =0; a < w; a++)
    {
      g.drawLine(a,h-width[a]-1,a,h-1);
    }
  
  }

public void setMethod(int in)                          //change algorithm based off of jcombobox selection
{
  method = in;
}

public void reRoll()
{
  random = new Random();
  
    width = new int[w];
    for(int i =0; i < w; i++)
    {
      width[i] = random.nextInt(1+h);
    }
    
    repaint();
}
  }
}
