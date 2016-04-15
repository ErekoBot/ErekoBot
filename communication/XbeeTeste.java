package com.digi.xbee.example;

import javax.swing.JFrame;
import javax.swing.JOptionPane;

import com.digi.xbee.api.XBeeDevice;

public class XbeeTeste {
		
		private static int contador = 0;
		private static String s;
		
		//Variáveis da equação do movimento
		private static double a; //ângulo de abertura
		private static float k;  //número de ondulações
		private static int M;	//número de articulações
	    
	    //Recolhe os parâmetros e cria um objeto da classe XbeeInterface
	    public void Parametros(){
	    	
	    	s = JOptionPane.showInputDialog(null,"Insira o valor do ângulo de abertura");
	    	a = Double.parseDouble(s);
	    	
	    	s = JOptionPane.showInputDialog(null,"Insira o número de ondulações");
	    	k = Float.parseFloat(s);
	    	
	    	s = JOptionPane.showInputDialog(null,"Insira o número de articulações");
	    	M = Integer.parseInt(s);
	    	
	    	for(contador = 0; contador < M; contador++){
	    		XbeeInterface XI = new XbeeInterface(a,k,M);
	    		
	    	}
	    }
}
