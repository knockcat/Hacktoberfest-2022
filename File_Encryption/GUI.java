package com.encryption;

import javax.swing.*;
import java.awt.*;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;


public class GUI {
    Font font;
    JButton Openbutton,encryptButton,decryptButton;
    JComboBox<String> dropDown;
    File file;
    byte fileBytes[],resultBytes[];
    JTextField textField;

    void createDropdown(JFrame frame){
        String[] optionsToChoose = {"AES", "XOR", "TDES"};
        dropDown = new JComboBox<>(optionsToChoose);

        dropDown.setBounds(80, 50, 140, 20);
        frame.add(dropDown);
    }
    void createFrame(JFrame frame){

        frame.setTitle("Encryption"); //set the title of the frame
        frame.setSize(700,700); //set the size of the frame
        frame.setLocationRelativeTo(null); //set the location of the frame
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //set the default close operation of the frame
        frame.setVisible(true); //set the frame to visible
    }
    void createButton(JFrame frame){
        font= new Font("roboto", Font.BOLD, 20);
        frame.setLayout(new FlowLayout());

//        creating open file button
        Openbutton = new JButton("Open image");
        Openbutton.setFont(font);
        Openbutton.setBounds(100,10,70,50);
        Openbutton.setSize(10,10);

        //        creating text field
        textField = new JTextField(10);
        textField.setFont(font);
        textField.setBounds(150,10,100,50);

        //ActionListner to get file
        Openbutton.addActionListener(e->{
            getFile();
        });


        encryptButton=new JButton("Encrypt");
        encryptButton.setFont(font);
        encryptButton.setBounds(130,100,80,50);

        encryptButton.addActionListener(e -> {
            getFileData();
            String privateKey=textField.getText();


            String selectedAlgo =dropDown.getItemAt(dropDown.getSelectedIndex());

            if(selectedAlgo.equals("XOR")) {
                int key=0;
                try {
                    key=Integer.parseInt(privateKey);
                }catch (Exception exception)
                {
                    exception.printStackTrace();
                }

                resultBytes = XOR.operateXOR(key, fileBytes);
            }
            if(selectedAlgo.equals("AES")){
                try {
                    resultBytes=AES.encryptData(privateKey,fileBytes);
                } catch (Exception ex) {
                    throw new RuntimeException(ex);
                }
            }
            if(selectedAlgo.equals("TDES"))
            {
                try {
                    resultBytes=TDES.encrypt(fileBytes);
                } catch (Exception ex) {
                    throw new RuntimeException(ex);
                }

            }

            storeResultData("Encrypted");

        });
        decryptButton=new JButton("Decrypt");
        decryptButton.setFont(font);
        decryptButton.setBounds(130,100,80,50);

        decryptButton.addActionListener(e -> {
            getFileData();
            String privateKey=textField.getText();


            String selectedAlgo =dropDown.getItemAt(dropDown.getSelectedIndex());

            if(selectedAlgo.equals("XOR")) {
                int key=0;
                try{
                    key=Integer.parseInt(privateKey);
                }
                catch (Exception exception) {
                    exception.printStackTrace();
                    resultBytes = XOR.operateXOR(key, fileBytes);
                }

            }
            if(selectedAlgo.equals("AES")){
                try {
                    resultBytes=AES.decryptData(privateKey,fileBytes);
                } catch (Exception ex) {
                    throw new RuntimeException(ex);
                }
            }

            if(selectedAlgo.equals("TDES"))
            {
                try {
                    resultBytes=TDES.decrypt(fileBytes);
                } catch (Exception ex) {
                    throw new RuntimeException(ex);
                }

            }
            storeResultData("Decrytped");
        });


        frame.add(Openbutton);
        frame.add(textField);
        frame.add(encryptButton);
        frame.add(decryptButton);

    }

    private void getFileData() {
        try {
            FileInputStream fis=new FileInputStream(file);
            fileBytes=new byte[fis.available()];
            System.out.println(fileBytes.length);
            fis.read(fileBytes);
            fis.close();
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    private void storeResultData(String message)
    {
        try {
        FileOutputStream fileOutputStream=new FileOutputStream(file);
        fileOutputStream.write(resultBytes);
        fileOutputStream.close();
        JOptionPane.showMessageDialog(null,message);
    }catch (Exception e){
        e.printStackTrace();
    }
    }

    private void getFile() {

        JFileChooser fileChooser =new JFileChooser();
        fileChooser.showOpenDialog(null);
         file =fileChooser.getSelectedFile();
        JOptionPane.showMessageDialog(null,"File chosen : "+file.getName());
    }
}
