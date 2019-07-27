import java.awt.*;
import java.awt.event.*;
import java.applet.*;

public class appletevent extends Applet implements ActionListener{
    TextField t1,t2,t3,t4,t5,t;
    Label l1,l2,l3,l4,l5,l,l6;
    Button b;
    float y;
    public void init()
    {
        t = new TextField(8);
        t1 = new TextField(8);
        t2 = new TextField(8);
        t3 = new TextField(8);
        t4 = new TextField(8);
        t5 = new TextField(8);
        l = new Label("Enter your name");
        l1 = new Label("Enter mark");
        l2 = new Label("Enter mark");
        l3 = new Label("Enter mark");
        l4 = new Label("Enter mark");
        l5 = new Label("Enter mark");

        b = new Button("Calculate");
        add(l);
        add(t);
        add(l1);
        add(t1);
        add(l2);
        add(t2); 
        add(l3);
        add(t3);
        add(l4);
        add(t4);
        add(l5);
        add(t5);
        add(b);
        
        t1.setText("");
        t2.setText("");
        t3.setText("");
        t4.setText("");
        t5.setText("");
        b.addActionListener(this);
    }
    public void actionPerformed(ActionEvent ae){
        int x = Integer.parseInt(t1.getText());
        x = x + Integer.parseInt(t2.getText());
        x = x + Integer.parseInt(t3.getText());
        x = x + Integer.parseInt(t4.getText());
        x = x + Integer.parseInt(t5.getText());
        y = x/5;
        repaint();
    }
    public void paint(Graphics g){
        g.drawString("The avg mark is ", 40, 300);
        g.drawString(y + "", 40, 350);
    }
}