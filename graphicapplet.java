import java.applet.*;
import java.awt.*;

import sun.java2d.loops.DrawPolygons;

public class graphicapplet extends Applet{
    
     public void paint(Graphics g){
        Font f =  new Font("Product Sans",Font.PLAIN,50);
        g.setFont(f);
        g.setColor(Color.CYAN);
        String s = f.toString();
        System.out.println(s);
        g.fillArc(150, 150, 200, 200, 45, 270);
        g.drawString("Hello ", 5, 30);
        g.setColor(Color.LIGHT_GRAY);
        g.fillRoundRect(200, 200, 50, 50, 34, 34);
        int x[] = {10,30,160,10};
        int y[] = {20,220,200,20};
        int n = x.length;
        g.drawPolygon(x, y, n);

    }
}