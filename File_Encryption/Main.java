package com.encryption;

import javax.swing.*;

//import static com.encryption.Main1.createFrame;

public class Main {
        public static void main(String[] args) {
        System.out.println("this is testing");
        JFrame frame = new JFrame();//create a new frame
            GUI ob=new GUI();
        ob.createDropdown(frame);
        ob.createButton(frame);
        ob.createFrame(frame);




    }
}
