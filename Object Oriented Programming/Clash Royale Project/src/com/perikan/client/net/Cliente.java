package com.perikan.client.net;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

import com.perikan.client.config.InputHandler;
import com.perikan.client.entities.Player;


public class Cliente {
	private static Player p1;
	
	public static void main(String []args) {
	///EStabelecer Conexão 
	///Trocar Mensagens
		Random rand = new Random();
		int  i =rand.nextInt(5);
		p1= new Player(null, "player"+i);
	try {
		///ocket socket = new Socket("localhost", 5555);
		
		Socket socket = new Socket("localhost", 3434);
		ObjectOutputStream output = new ObjectOutputStream(socket.getOutputStream());
		ObjectInputStream input = new ObjectInputStream(socket.getInputStream());
		input.close();
		output.close();
		socket.close();
	}catch(IOException ex) {
		Logger.getLogger(Cliente.class.getName()).log(Level.SEVERE, null,ex);	
	}
	
	}
}