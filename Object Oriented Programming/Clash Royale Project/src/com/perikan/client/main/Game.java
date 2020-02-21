package com.perikan.client.main;

import java.awt.Canvas;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.image.BufferStrategy;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import javax.swing.JFrame;
import javax.swing.JOptionPane;

import com.perikan.client.config.InputHandler;
import com.perikan.client.config.MatchController;
import com.perikan.client.entities.*;
import com.perikan.client.graphic.*;
import com.perikan.client.world.*;

import javafx.concurrent.Worker;


public class Game extends Canvas implements Runnable,KeyListener,MouseListener{

	private static final long serialVersionUID = 1L;
	public static JFrame frame;
	private Thread thread;
	private boolean isRunning;
	private static final double SCALE_W = 1;
	public static  int WIDTH = 350;//350
	public static  int HEIGHT = 465;//465
	private static final double SCALE =2;
	private static final String InputHandler = null;
	private BufferedImage img;
	public static SpriteSheet spritesheet;
	//lista de entidades
	public static List<Entity> entities ;
	//public static List<Champion> champs;
	//public static List<Tower> towers;
	
	//Criando uma partida
	//public static World world;
	//background
	private Color backGround = Color.black;
	public static Random rand;
	//Gráficos / tella
	public static Graphics g;
	//UI
	public UI ui;
	public static MatchController match;
	//players
	private Player p1,p2;
	public static boolean beggin =false ;
	private InputHandler inputHand;
	public static boolean isPressed = false;
	public static int Xtarget,yTarget;
	//Servidor
	private Socket socket;
	private ObjectOutputStream output; 
	private ObjectInputStream input;
	

	//contrutor##############################################################
	public Game(){
		rand = new Random();
		addKeyListener(this);
		addMouseListener(this);
		//addMouseMotionListener(this);
		//Inicializando as listas 
		//Instâncias do Client
		/*
		try {
			socket = new Socket("localhost", 3434);
			output = new ObjectOutputStream(socket.getOutputStream());
			input = new ObjectInputStream(socket.getInputStream());
			//socket.close();
			//input.close();
		} catch (Exception e) {
			System.out.println(">>Error"+e.getMessage());
		}*/
		
		
		
		entities = new ArrayList<Entity>();
		
		//Inicializando as imagens e mundo
		spritesheet = new SpriteSheet("/spritesheet2.png");//word depois desse
		
		inputHand = new InputHandler(this);
		
		p1 = new Player(inputHand,JOptionPane.showInputDialog("Digite seu UserName:"));	
		p2 = new Player(inputHand, "Red");
		p2.isRed = true;
		
		match = new MatchController(p1,p2); //*deve ser criado depois
		//Gerando tela:
		WIDTH = (int)(World.MAP_Width*32*SCALE_W);
		HEIGHT = (int)(World.MAP_Hight*32*SCALE_W);
		this.setPreferredSize(new 
				Dimension(WIDTH,HEIGHT));
		initFrame();
		img = new BufferedImage((int)(WIDTH*SCALE), (int)(HEIGHT*SCALE) , BufferedImage.TYPE_INT_RGB);
		
		
		
	}
	public void initFrame() {
		frame = new JFrame("Smash Royale @Perikan");
		frame.add(this);
		frame.setResizable(false);//não pode redimensionar
		frame.pack();
		frame.setLocationRelativeTo(null);//centro
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setVisible(true);
		
	}
	public synchronized void start() {
		thread = new Thread(this);
		isRunning= true;
		thread.start();
	}
	public synchronized void stop() {
		isRunning = false;
		try {
			input.close();
			output.close();
			socket.close();
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		
		try {
			thread.join();
			
		}catch(InterruptedException e){
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) {
		Game g = new Game();
		 
		g.start();
		System.out.println("iniciou");
		//g.stop();
	}
	
	public void tick() {
		if(beggin) match.tick();
		if(Deck.isCreateCards()){	
			for(Card c: Deck.getAllCards()) {
				c.tick();
			}
		}
		/*
		try {
			output.writeObject(p1);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}*/
	
	}
	public void render() {	
		//otimizar renderização
		BufferStrategy bs = this.getBufferStrategy();
		if(bs == null) {
			this.createBufferStrategy(3);
			return;
		}
		g = img.getGraphics();	//apaga o anterior
		g.setColor(backGround);
		g.fillRect(0, 0, WIDTH, HEIGHT);
		
		//Renderizar objetos
		
	
		//ui.render(g);
		if(beggin) {
			match.render(g);
			for(Entity e : entities) e.render(g);
		}else {
			p1.SelectCard(g, beggin);
		}
		//g.setFont(new Font("Arial",Font.BOLD,12));
		//g.setColor(Color.RED);
		//g.drawString("FPS: ", 20, 20);
		
		
		g.dispose();//otimizaÇÃO
		g = bs.getDrawGraphics();
		g.drawImage(img,0,0,WIDTH,HEIGHT,null);
		bs.show();
	}
	
	@Override
	public void run() {
		//limitar loop parauma forma profissional
		long lastTime = System.nanoTime(); //tempo do pc
		double amountOfTicks = 60;
		double ns = 1000000000 / amountOfTicks; //seg por fps
	// ver os 60 frames	
		double delta = 0;
		int frames =0;
		//tempo atual menos preciso
		double timer = System.currentTimeMillis();
		requestFocus();
		while(isRunning) {
			long now = System.nanoTime();
			//intervalo do tick
			delta += (now-lastTime)/ns;
			lastTime = now;
			if(delta>=1) {
				tick();
				render();
				frames++;
				
				delta--;
					//passou 1 seg
			}if(System.currentTimeMillis() - timer >=1000) {
				//System.out.println("FPS: "+frames);
				
				frames = 0;
				
				timer +=1000; 
			}
		}stop();
	}
	
	//keyListener metodos
	
	@Override
	public void keyPressed(KeyEvent e) {
		if(e.getKeyCode() == KeyEvent.VK_RIGHT ||
				e.getKeyCode() == KeyEvent.VK_D) {
			//player.setRight(true);
		}else if(e.getKeyCode() == KeyEvent.VK_LEFT ||
				e.getKeyCode() == KeyEvent.VK_A) {
			//player.setLeft(true);
		}if(e.getKeyCode() == KeyEvent.VK_UP ||
				e.getKeyCode() == KeyEvent.VK_W) {
		//	player.setUp(true);
		}else if(e.getKeyCode() == KeyEvent.VK_DOWN ||
				e.getKeyCode() == KeyEvent.VK_S) {
			//player.setDown(true);
		}
		
	}
	@Override
	public void keyReleased(KeyEvent e) {
		if(e.getKeyCode() == KeyEvent.VK_RIGHT ||
				e.getKeyCode() == KeyEvent.VK_D) {
			//player.setRight(false);
		}else if(e.getKeyCode() == KeyEvent.VK_LEFT ||
				e.getKeyCode() == KeyEvent.VK_A) {
			//player.setLeft(false);
		}if(e.getKeyCode() == KeyEvent.VK_UP ||
				e.getKeyCode() == KeyEvent.VK_W) {
		//	player.setUp(false);
		}else if(e.getKeyCode() == KeyEvent.VK_DOWN ||
				e.getKeyCode() == KeyEvent.VK_S) {
		//	player.setDown(false);
		}
		
	} 
	@Override
	public void keyTyped(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}
	//::: MOUSE :::
	
	@Override
	public void mouseClicked(MouseEvent e) {
		// TODO Auto-generated method stub
		//System.out.println(e.getLocationOnScreen()); 
	}
	@Override
	public void mousePressed(MouseEvent e) {
		// TODO Auto-generated method stub
		this.isPressed = true;
		Xtarget = e.getX();
		yTarget = e.getY();
		match.setPressed(true);
		match.setxTarget(e.getX());
		match.setyTarget(e.getY());
		
		
	}
	@Override
	public void mouseReleased(MouseEvent e) {
		// TODO Auto-generated method stub
		//System.out.println("X: "+e.getX()+"Y: "+e.getY());
		
	}
	@Override
	public void mouseEntered(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}
	//  ::: GETTER E SETTER ::::
	public static double getSCALE() {
		return SCALE;
	}
	public static boolean isBeggin() {
		return beggin;
	}
	public static void setBeggin(boolean beggin) {
		Game.beggin = beggin;
	}
	public static Random getRand() {
		return rand;
	}
	public static void setRand(Random rand) {
		Game.rand = rand;
	}
	public static boolean isPressed() {
		return isPressed;
	}
	public static void setPressed(boolean isPressed) {
		Game.isPressed = isPressed;
	}
	
	
	
}
	

