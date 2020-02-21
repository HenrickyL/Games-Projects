package com.perikan.client.config;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.util.ArrayList;
import java.util.List;
import java.awt.Font;

import com.perikan.client.entities.Champion;
//import com.perikan.client.entities.ChampionsController;
import com.perikan.client.entities.Entity;
import com.perikan.client.entities.Player;
import com.perikan.client.entities.Table;
import com.perikan.client.entities.Tower;
import com.perikan.client.graphic.SpriteSheet;
import com.perikan.client.graphic.UI;
import com.perikan.client.main.Game;
import com.perikan.client.world.Tile;
import com.perikan.client.world.World;



public class MatchController {
//controlador de partida(match)
	//verificadores
	private boolean begin =false;
	private static int u = Tile.En_W_H;
	private Player playerWinner;
	private Player playerRed,playerBlue; //azul e o de baixo e vermelho o de cima
	private int turns =0;
	//private UI uiRed,uiBlue; // UserInterface o *O jogo tem que ter a sua tambem com tempo e tudo mais
	//Torres Aliadas e inimigas
	//private List<Tower> towerAlly;
	//private List<Tower> towerEnemy;
	//lista
	//private List<Champion> champAlly;
	//private List<Champion> champEnemy;
	
	public List<Entity> entities ;
	//private List<Champion> champsAlly;
	//private List<Champion> champsEnemy;
	
	private SpriteSheet spriteSheet;
	private Table table;
	//contador de tempo
	private int timeError = 0; 
	
	//contador de tempo
	public double time=0;
	public int minute=0;
	private int count=0;
	
	//Criar a interfaca da partida / o mundo
	private World world;
	private CardController cCBlue;
	private CardController cCRed;
	//private ChampionsController champController;
	private boolean worldError= false;
	
	//posições e clicks
	private boolean isPressed = false;
	private double xTarget,yTarget;
	
	
	private boolean normalize = false;
	//Construtor ############################################################################
	public MatchController() {}
	public MatchController(Player blue,Player red) {
		//Atribuindo
		playerWinner= null;
		//* player red pode ser passado pelo servidor, esse MATCH ser so do player Client
		this.playerRed = red;
		this.playerBlue = blue;
		
		
		//criando
		spriteSheet = new SpriteSheet("/Table.png");
		entities = new ArrayList<Entity>();
		//champsAlly = new ArrayList<Champion>();
		//champsEnemy = new ArrayList<Champion>();
		//towerAlly = new ArrayList<Tower>();
		//towerEnemy = new ArrayList<Tower>();
		//champAlly = new ArrayList<Champion>();
		//champEnemy = new ArrayList<Champion>();
		//champController = new ChampionsController(0, 0, 0, 0, null);
		cCBlue = new CardController(playerBlue);
		cCRed = new CardController(playerRed);
		try {
		world = new World("/Map3.png");
		}catch (Exception e) {
			worldError = true;
		}
		this.turns =0;
		this.time=0;
		this.begin = true;
		System.out.println("Partida Iniciada");
		
		
	}//#######################################################################################
	
	public synchronized void tick() {  // * Com relação a posição dos campeões do jogador 
		//vermelho podemos inverter o Y e na hora de printar na tela do azul
		if(!normalize) tickNormalize();
		
		//winner?
		tickWinner();
		//mouse pressed
		tickPressed();
		//timer
		tickTime();
		tickScore();
		
		//
		
		//champController.tick(playerRed);
		playerBlue.tick();
		playerRed.tick();
		if(playerBlue.isNormalize() && playerRed.isNormalize()) {
			cCBlue.tick();
			cCRed.tick();
		}
		for(Entity e : entities) if(!e.isDestroyed())e.tick();
		
	}
	public synchronized void render(Graphics g) {
		//renderiza a tela World
		world.render(g);
		
		for(Entity e : entities) if(!e.isDestroyed())e.render(g);
		drawTable(g);
		//draw placart
		//draw card
		drawRedError(g);
		drawScore(g);
		int xPos = (int)(Game.WIDTH*Game.getSCALE()-110);
		int yPos = 30;
		//backgroud font
		g.setColor(new Color(0, 0, 0, 120));
		g.fillRect(xPos-25, 0, 130, 40);
		//font
		g.setFont(new  Font("Arial",Font.BOLD,30));
		g.setColor(Color.white);
		g.drawString(minute+" : "+(int)time, xPos, yPos);
		
		if(playerBlue.isNormalize() && playerRed.isNormalize()) {
			//pla.Render(g);
			playerBlue.getDeck().render(g);
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	////////////////////////////////////////////////////////////////////////////////////////
	//Tick normalized
	private void tickNormalize() {
		//mundo
		if(worldError) {
			
			worldError = false;
			world = new World("/Map3.png");
			//for(Tower t : towerAlly) t.setPlayer(playerBlue);
			//for(Tower t : towerEnemy) t.setPlayer(playerRed);
			
		}
		//jogadores
		//playerBlue.setTowers(towerAlly);
		//playerRed.setTowers(towerEnemy);
		//
		
		playerBlue.tickNormalize();
		playerRed.tickNormalize();
		
	}
	//Tick winner
	public void tickWinner() {
		if(playerBlue.isDestroyed()) {
			playerWinner = playerRed;
		}else if(playerRed.isDestroyed()) {
			playerWinner = playerBlue;
		}
		if(playerWinner != null ) {
			//Ganhou
		}
		
	}
	//tick pressionado
	private void tickPressed() {
		cCBlue.setPressed(this.isPressed);
		cCRed.setPressed(this.isPressed);
	}
	
	
	
	//Tick Controle de torre destruida
	private void tickScore() {
		int pBScore=0,pRScore=0;
		for(Tower t : playerBlue.getTowers()) {
			if(t.isDestroyed()) {
				pBScore++;
			}
		}for(Tower t : playerRed.getTowers()) {
			if(t.isDestroyed()) {
				pRScore++;
			}
		}
		playerBlue.setCrown(pBScore);
		playerRed.setCrown(pRScore);
	}
	//controle de tempo
		public void tickTime() {
			count++;
			if(count > 30/2) {
				count =0;
				if(begin == true) {
					time+=0.5;
					//incrementar os elixir dos players
					if(time%2==0) {
						elixirIncrement();
						
					}
				}if(time > 59) {
					minute++;
					time=0;
				}
			}
		}
	
	
	public void drawScore(Graphics g) {
		g.setColor(new Color(0, 0, 0, 100));
		g.fillRect(12*u, 6*u, 40, 60);
		g.setColor(new Color(0, 0, 0, 100));
		g.fillRect(12*u, 10*u, 40, 60);
		g.drawImage(Tile.TILE_CROWN_R,(int)( (12-0.2)*u),(int)( (6+0.6)*u ),null);
		g.drawImage(Tile.TILE_CROWN_B,(int)(1*((12-0.2))*u),(int)((9+0.39)*u),null);
		g.setFont(new Font("Arial",Font.BOLD,30));
		g.setColor(Color.red);
		g.drawString(""+playerRed.getCrown(),(int)((12+0.15)*u), (int)((6+0.5)*u));
		g.setColor(Color.blue);
		g.drawString(""+playerBlue.getCrown(),(int)((12+0.15)*u), (int)((10+0.8)*u));
		
	}
	
	//Error position
	public void drawRedError(Graphics g) {
		if(cCBlue.isInvalidPosition() && timeError<100) {
			timeError+=80;
			cCBlue.setInvalidPosition(false);
			
		}else if(timeError>0){
			Game.g.setColor(new Color(255, 0, 0, timeError));
			Game.g.fillRect(0, 0, 13*u, 8*u);
			timeError-=2; 
		}
	}
	//table
	public void drawTable(Graphics g) {
		int v=playerBlue.getElixir();
		g.setColor(new Color(16, 12, 1, 255));
		g.fillRect(3*u, 19*u, u*10, u*2);
		// barra roxa atras da caixa
		double k=1.5; //clareador tade cor
		g.setColor(new Color((int)(k*106),(int)(k*60),(int) (k*114)));
		g.fillRect(3*u, (int)((19+0.3)*u), u*(v), u*1);
		g.setColor(new Color((int)(k*85), (int)(k*40), (int)(k*92)));
		g.fillRect(3*u,(int)( (20+0.1)*u), u*(v), u*2);
		//caixa marrom
		BufferedImage spr = spriteSheet.getSprite(0*u, 0*u, u*10, u*5);
		Table tab = new Table(3*u, 16*u, u,u*2,spr);//, Tile.TILE_TABLE);
		tab.render(g);
		g.setFont(new  Font("Arial",Font.BOLD,30));
		g.setColor(Color.white);
		g.drawString(""+playerBlue.getElixir(),(int)(3*u)+13, 20*u +25);
		//-> falta as coroas, cartas e proximas cartas
	}
	
	
	
	public void elixirIncrement() {
		if(playerBlue.getElixir()< 10)
			playerBlue.setElixir(playerBlue.getElixir()+1);
		if(playerRed.getElixir()< 10)
			playerRed.setElixir(playerRed.getElixir()+1);
	} 
	//GETTER E SETTERc




	public List<Entity> getEntities() {
		return entities;
	}

	public void setEntities(List<Entity> entities) {
		this.entities = entities;
	}

	public double getTime() {
		return time;
	}

	public void setTime(double time) {
		this.time = time;
	}

	public boolean isPressed() {
		return isPressed;
	}

	public void setPressed(boolean isPressed) {
		this.isPressed = isPressed;
	}

	public double getxTarget() {
		return xTarget;
	}

	public void setxTarget(double xTarget) {
		this.xTarget = xTarget;
	}

	public double getyTarget() {
		return yTarget;
	}

	public void setyTarget(double yTarget) {
		this.yTarget = yTarget;
	}
	
	public Player getPlayerRed() {
		return playerRed;
	}
	public void setPlayerRed(Player playerRed) {
		this.playerRed = playerRed;
	}
	public Player getPlayerBlue() {
		return playerBlue;
	}
	public void setPlayerBlue(Player playerBlue) {
		this.playerBlue = playerBlue;
	}
	
	
	

	


	
	
	
	
}
