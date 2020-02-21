package com.perikan.server;

import com.perikan.client.entities.Player;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;


public class Server {
	///ARRAY-LIST DE PLAYERS;
	private static List<Player> players;
	private ServerSocket serverSocket;
	//Metodos
	private void criarServerSocket(int porta) throws IOException {
		serverSocket = new ServerSocket(porta);
	}
	private Socket esperaConexao()throws IOException {
		Socket socket = serverSocket.accept();
		new Thread(new ListenerSocket(socket)).start();
		return socket;
	}
	private void closeSocket(Socket socket) throws IOException {
		socket.close();
	}
	private void trataConexao(Socket socket) throws IOException, ClassNotFoundException{
		////protocolo aplicacao
		try {
			ObjectOutputStream output = new ObjectOutputStream (socket.getOutputStream());
			ObjectInputStream input = new ObjectInputStream (socket.getInputStream());
			Player msg = (Player) input.readObject();
			System.out.println("Objeto Recebido ...");
			Server.getPlayers().add(msg);
			output.flush();
			input.close();
			output.close();
		}catch(IOException e){
			//tratar falaha na concexão 
			System.out.println("Erro_ > Progama Sera Finalizado");
			System.out.println("Error :"+e.getMessage());
			System.exit(1);
		}finally {
			//fECHANDO sOCKET
			closeSocket(socket);
		}
	}
	
	public static List<Player> getPlayers() {
		return players;
	}
	public static void setPlayers(List<Player> players) {
		Server.players = players;
	}
	//Listener
	private class ListenerSocket implements Runnable {
		private ObjectOutputStream output;
		private ObjectInputStream input;
		public  ListenerSocket(Socket socket) {
			try {
				this.output = new ObjectOutputStream(socket.getOutputStream());
				this.input = new ObjectInputStream(socket.getInputStream());
			} catch (Exception e) {
				// TODO: handle exception
			}
			
		}
		@Override
		public void run() {
			//throw new UnsupportedOperationException("Não suportado");
			
		}

	}
	
	
	public static void main(String []argvs) throws ClassNotFoundException {
		
		try {
			boolean ativo = false;
			Server server = new Server();
			ativo = true;
			//players = new ArrayList<Player>();
			System.out.println("Aguardando Conexão");
			server.criarServerSocket(3434);
			while(ativo) {
				Socket socket = server.esperaConexao();
				System.out.println("Cliente Conectado"+" | "+Server.getPlayers().size()+" Conectados");
				server.trataConexao(socket);	
			}
			System.out.println("Finalizado");
		}
		catch(IOException e) {
			//trata execption 
		}
	}


	
	
}

