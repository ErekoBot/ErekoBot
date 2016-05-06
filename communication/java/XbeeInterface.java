package com.digi.xbee.example;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener; 

import javax.swing.SwingConstants; 
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

import com.digi.xbee.api.RemoteXBeeDevice;
import com.digi.xbee.api.XBeeDevice;
import com.digi.xbee.api.exceptions.TimeoutException;
import com.digi.xbee.api.exceptions.XBeeException;
import com.digi.xbee.api.models.XBee64BitAddress;
   
public class XbeeInterface extends JFrame implements ActionListener {
	 
	private static float d0;  // (??)
	private static float d; //distância entre articulações (??)
	private static double pi = 3.141592;
	private static int i;  //número da articulação
	public static double anguloMotor;
	private static float psi = 0;  //Valor inicial (??)
	private static String s;
	private static String DATA_TO_SEND;
	private static final String PORT = "COM3";
	private static final int BAUD_RATE = 9600;
	
	private static JButton button;
	private static JLabel label;
	private static JLabel label2;
	private static JLabel label3;
	private static JLabel label4;
	private static JLabel label5;
	private static JLabel label6;
	private static JLabel label7;
	private static JLabel label8;
	private static JLabel label9;
	private static TextField text1;
	private static TextField text2;
	private static TextField text3;
	
	public XbeeInterface(double alpha, float k, int M){
		
		super("XbeeInterface módulo"); 
		
		button = new JButton("Mandar parâmetros");
		label = new JLabel("INSIRA OS PARÂMETROS A SEREM ENVIADOS");
		label2 = new JLabel("distância base-eixo(cm) ");
		label3 = new JLabel("tamanho do módulo(cm)    ");
		label4 = new JLabel("Número do módulo     ");
		label5 = new JLabel("                                                             ");
		label6 = new JLabel("            ");
		label7 = new JLabel("                           ");
		label8 = new JLabel("                           ");
		label9 = new JLabel("                           ");
		text1 = new TextField();
		text2 = new TextField();
		text3 = new TextField();
		
		text1.setColumns(50);
		text2.setColumns(50);
		text3.setColumns(50);
		
		this.getContentPane().setLayout(new FlowLayout());
		this.getContentPane().add(label6);
		this.getContentPane().add(label);
		this.getContentPane().add(label5);
		this.getContentPane().add(label2);
		this.getContentPane().add(text1);
		this.getContentPane().add(label7);
		this.getContentPane().add(label3);
		this.getContentPane().add(text2);
		this.getContentPane().add(label8);
		this.getContentPane().add(label4);
		this.getContentPane().add(text3);
		this.getContentPane().add(label9);
		this.getContentPane().add(button); 
		
		
    	this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
		this.setSize(500, 300);
		this.setVisible(true);
		this.setLocationRelativeTo(null);
		this.setResizable(false);
		
		button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent ae) {
				
				 s = text1.getText();
				 d0 = Float.parseFloat(s.trim());
				 s = text2.getText();
				 d = Float.parseFloat(s.trim());
				 s = text3.getText();
				 i = Integer.parseInt(s.trim()); 
				 
				 anguloMotor = (2*alpha*Math.sin(pi*k/M)*Math.sin(psi + ((2*pi*k/M)*(i-1+d0/d)))*180/pi)+90;
				 
				 DATA_TO_SEND = String.valueOf(anguloMotor);
				 byte[] data = DATA_TO_SEND.getBytes();
				  
				 XBeeDevice myLocalDevice = new XBeeDevice(PORT, BAUD_RATE);
				 
			     RemoteXBeeDevice myRemoteDevice1 = new RemoteXBeeDevice(myLocalDevice,new XBee64BitAddress("0013A20040C193D1"));
				 RemoteXBeeDevice myRemoteDevice2 = new RemoteXBeeDevice(myLocalDevice,new XBee64BitAddress("0013A20040AB9B4C"));
				 RemoteXBeeDevice myRemoteDevice3 = new RemoteXBeeDevice(myLocalDevice,new XBee64BitAddress("0013A20040C192F6"));
				 RemoteXBeeDevice myRemoteDevice4 = new RemoteXBeeDevice(myLocalDevice,new XBee64BitAddress("0013A20040C193D0"));
				 RemoteXBeeDevice myRemoteDevice5 = new RemoteXBeeDevice(myLocalDevice,new XBee64BitAddress("0013A20040AB9973"));
				 RemoteXBeeDevice myRemoteDevice6 = new RemoteXBeeDevice(myLocalDevice,new XBee64BitAddress("0013A20040C19421"));
				 
				 //Endereço do Host - 0013A20040C193FC;  
				 
				 if(i == 1){
				   
					 try {
						myLocalDevice.open();
						myLocalDevice.sendData(myRemoteDevice1, data);
						System.out.format("Enviando para o módulo %d ângulo do motor: %s\n",i, new String(data));
						
					} catch (TimeoutException e) {
						
						e.printStackTrace();
					} catch (XBeeException e) {
						
						e.printStackTrace();
					} finally {
						myLocalDevice.close();
						
					}
					 
				  }
				  else if(i == 2){
					 
					 try {
						myLocalDevice.open();
						myLocalDevice.sendData(myRemoteDevice2, data);
						System.out.format("Enviando para o módulo %d ângulo do motor: %s\n",i, new String(data));
						
					} catch (TimeoutException e) {
						
						e.printStackTrace();
					} catch (XBeeException e) {
						
						e.printStackTrace();
					} finally {
						myLocalDevice.close();
						
					}
				  }
				  else if(i == 3){
					 
					 try {
						myLocalDevice.open();
						myLocalDevice.sendData(myRemoteDevice3, data);
						System.out.format("Enviando para o módulo %d ângulo do motor: %s\n",i, new String(data));
						
					} catch (TimeoutException e) {
						
						e.printStackTrace();
					} catch (XBeeException e) {
						
						e.printStackTrace();
					} finally {
						myLocalDevice.close();
						
					}
				  }
				  else if(i == 4){
					 
					 try {
						myLocalDevice.open();
						myLocalDevice.sendData(myRemoteDevice4, data);
						System.out.format("Enviando para o módulo %d ângulo do motor: %s\n",i, new String(data));
						
					} catch (TimeoutException e) {
						
						e.printStackTrace();
					} catch (XBeeException e) {
						
						e.printStackTrace();
					} finally {
						myLocalDevice.close();
						
					}
				  }
				  else if(i == 5){
					 
					 try {
						myLocalDevice.open();
						myLocalDevice.sendData(myRemoteDevice5, data);
						System.out.format("Enviando para o módulo %d ângulo do motor: %s\n",i, new String(data));
						
					} catch (TimeoutException e) {
						
						e.printStackTrace();
					} catch (XBeeException e) {
						
						e.printStackTrace();
					} finally {
						myLocalDevice.close();
						
					}
				  }
				  else if(i == 6){
					  
					 try {
						myLocalDevice.open();
						myLocalDevice.sendData(myRemoteDevice6, data);
						System.out.format("Enviando para o módulo %d ângulo do motor: %s\n",i, new String(data));
						
					} catch (TimeoutException e) {
						
						e.printStackTrace();
					} catch (XBeeException e) {
						
						e.printStackTrace();
					} finally {
						myLocalDevice.close();
						
					}
				 }
			}
		});
	}
	
	@Override
	public void actionPerformed(ActionEvent arg0) {}

}
