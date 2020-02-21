package com.perikan.client.entities;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;

import com.perikan.client.config.InputHandler;
import com.perikan.client.main.Game;

public class Player extends Entity{
	//server options
	private String userName = "player";
	private boolean normalize =false; //pos begin game
	public boolean isRed =false;// inicialmente pensa nele como azul
	private int elixir=0;
	private int crown=0;//coroas
	//guardar relacionados ao jogador
	private Deck deck; //guarda as cartas
	private List<Tower> towers; //guardar as 3 torres
	private Tower tKing,tArcLeft,tArcRigth;
	private List<Entity> entities; // guardar todas as entidades;
	private List<Champion> champions;//guardar os campeões
	//input
	private InputHandler input;
	
	//Construtor
	public Player(InputHandler input, String userName) {
		super(0, 0, 0, 0, null);
		//username
		this.input = input;
		this.userName = userName;
		this.deck = new Deck(this);
		this.elixir = 3;
		this.champions = new ArrayList<Champion>();
		this.towers = new ArrayList<Tower>();
		
	}
	//Metodos
	public void tick() {
		if(normalize) {
			tickCheck();
			deck.tick();
		}
	}
	///////////////////////////////////////////////////////////////////////////
	//se uma das arqueiras cair o rei pode ser atacado
	private void tickCheck() {
		if(tArcLeft!= null &&  tArcRigth != null){
			if(tArcLeft.isDestroyed() == true && tArcRigth.isDestroyed() == true) {
				tKing.setGetAtacad(true);
			}
			if(tKing.isDestroyed) {
				this.isDestroyed = true;
			}
		}
	}
	//tick normalizar o jagador
	public void tickNormalize() {
		for(Tower t : towers) {
			if(tArcLeft == null) tArcLeft = t;
			else if(tArcRigth == null) tArcRigth = t;
		}
		
		normalize = true;
	}
	public boolean SelectCard(Graphics g, boolean verificador) {
		if(verificador) {
			return true;
		}else {
			g.setColor(Color.DARK_GRAY);
			g.fillRect(0, 0,(int) (Game.WIDTH*Game.getSCALE()),(int)(Game.HEIGHT*Game.getSCALE()));
			//mensagem
			g.setColor(Color.white);
			g.setFont(new Font("Arial",Font.BOLD,40));
			g.drawString("Olá, "+userName,1*u,(int)1*u);
			g.drawString("Escolha suas Cartas:", 1*u, (int)2*u);
			//selecionados
			g.setColor(Color.white);
			g.setFont(new Font("Arial",Font.BOLD,35));
			int aux = deck.getDeckList().size();
			int max=(Deck.getDecksize()>Deck.getNumCards()?Deck.getNumCards():Deck.getDecksize() );
			if(aux == max) { Game.beggin = true;}
			g.drawString("Selecionou: "+aux+" / "+max,(int) 1.5*u, 16*u);
			//Renderizar as opções de cartas para o deck
			Deck.renderDeckOptions(g,this); 
			g.setColor(Color.black);
			g.setFont(new Font("Times",(int)(Font.BOLD),25));
			String str[] = {
					"Software Livre, todos os direitos reservados a",
					"SUPERCELL pelo jogo Clash Royale.",
					"Este é um trabalho de faculdade sem fins Lucrativos.",
					"Equipe:",
					"- Henricky Lima - Henrickyl1@gmail.com",
					"- Eliabe"
			};
			int i = 0;
			for(String s: str) { 
				g.drawString(s, u,(int)( (17.5+i*0.5)*u));
				i++;
				}
	
			
			return false;
		}
	}
	
	
	
	//				::::  GETTER E SETTER
	public int getElixir() {
		return elixir;
	}
	public void setElixir(int elixir) {
		this.elixir = elixir;
	}
	public List<Tower> getTowers() {
		return towers;
	}
	public void setTowers(List<Tower> towers) {
		this.towers = towers;
	}
	public int getCrown() {
		return crown;
	}
	public void setCrown(int crown) {
		this.crown = crown;
	}
	public List<Champion> getChampions() {
		return champions;
	}
	public void setChampions(List<Champion> champions) {
		this.champions = champions;
	}
	public Deck getDeck() {
		return deck;
	}
	public void setDeck(Deck deck) {
		this.deck = deck;
	}
	public boolean isNormalize() {
		return normalize;
	}
	public String getUserName() {
		return userName;
	}
	public void setUserName(String userName) {
		this.userName = userName;
	}
	public Tower gettKing() {
		return tKing;
	}
	public void settKing(Tower tKing) {
		this.tKing = tKing;
	}
	
	
	
	
	
	
}
