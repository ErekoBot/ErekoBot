package com.digi.xbee.example;
 
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

import com.digi.xbee.api.XBeeDevice;
import com.digi.xbee.api.exceptions.XBeeException;
 
public class MainApp extends JFrame implements ActionListener {

    private static final String PORT = "COM3";
    
    private static final int BAUD_RATE = 9600;
     
    private static final String DATA_TO_SEND = "i";
    
    private static final String CONDICAO_DE_PARADA = "p";
    
    JButton iniciar;
    JButton parar;
    
    XBeeDevice myDevice = new XBeeDevice(PORT, BAUD_RATE);
    byte[] IniciarMovimento = DATA_TO_SEND.getBytes();
    byte[] PararMovimento = CONDICAO_DE_PARADA.getBytes(); 
    
    public MainApp (){
    	
    	super("Interface Gráfica");
    	setLayout( new FlowLayout() );
    	
    	iniciar = new JButton("Iniciar");
    	parar  = new JButton("Parar");
    	
    	add(iniciar);
    	add(parar);
    	
    	iniciar.setPreferredSize(new Dimension(100, 25)); 
    	parar.setPreferredSize(new Dimension(100, 25)); 
    	
		iniciar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ae) {
			     
				try {
	            myDevice.open();
	             
	            System.out.format("Sending broadcast data: '%s'", new String(IniciarMovimento));
	             
	            myDevice.sendBroadcastData(IniciarMovimento);
	             
	           System.out.println(" >> Success");
	             
	        } catch (XBeeException e) {
	            System.out.println(" >> Error");
	            e.printStackTrace();
	            System.exit(1);
	        } finally {
	            myDevice.close();
	        } 
				
			}

		});
		
		parar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ae) {
				
				try {
		            myDevice.open();
		             
		           System.out.format("Sending broadcast data: '%s'", new String(PararMovimento));
		             
		            myDevice.sendBroadcastData(PararMovimento);
		             
		           System.out.println(" >> Success");
		             
		        } catch (XBeeException e) {
		           System.out.println(" >> Error");
		            e.printStackTrace();
		            System.exit(1);
		        } finally {
		            myDevice.close();
		        } 
			}

		});
		
    	this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setSize(350, 100);
		this.setVisible(true);
		this.setLocationRelativeTo(null);
		this.setResizable(false);
    }
    
    public static void main(String[] args) {
    	
        MainApp In = new MainApp();

    } 

	@Override
	public void actionPerformed(ActionEvent arg0) {
		
	}
}