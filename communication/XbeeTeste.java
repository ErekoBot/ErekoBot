package com.digi.xbee.example;

import javax.swing.JFrame;
import javax.swing.JOptionPane;

import com.digi.xbee.api.XBeeDevice;

public class XbeeTeste {
		
		private static int contador = 0;
		private static String s;
		
		//Vari�veis da equa��o do movimento
		private static double a; //�ngulo de abertura
		private static float k;  //n�mero de ondula��es
		private static int M;	//n�mero de articula��es
	    
	    //Recolhe os par�metros e cria um objeto da classe XbeeInterface
	    public void Parametros(){
	    	
	    	s = JOptionPane.showInputDialog(null,"Insira o valor do �ngulo de abertura");
	    	a = Double.parseDouble(s);
	    	
	    	s = JOptionPane.showInputDialog(null,"Insira o n�mero de ondula��es");
	    	k = Float.parseFloat(s);
	    	
	    	s = JOptionPane.showInputDialog(null,"Insira o n�mero de articula��es");
	    	M = Integer.parseInt(s);
	    	
	    	for(contador = 0; contador < M; contador++){
	    		XbeeInterface XI = new XbeeInterface(a,k,M);
	    		
	    	}
	    }
}
