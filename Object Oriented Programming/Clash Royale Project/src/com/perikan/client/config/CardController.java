package com.perikan.client.config;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.util.ArrayList;
import java.util.List;

import com.perikan.client.entities.Card;
import com.perikan.client.entities.Champion;
import com.perikan.client.entities.Deck;
import com.perikan.client.entities.Player;
import com.perikan.client.main.Game;
import com.perikan.client.world.Tile;

public class CardController {
	private static int u = Tile.En_W_H;
	private static int handsize = 4;
	private Player player;
	private Deck deck;
	private List<Card> hand;
	private Card next;
	//controle click
	private boolean isPressed = false;
	private double xTarget,yTarget;
	private boolean canSummor = true;
	private boolean invalidPosition = false;
	
	
	//Construtor
	public CardController(Player p) {
		this.player = p;
		hand = new ArrayList<Card>();
		deck = p.getDeck();
	}
	public void tick() {
		isPressed = Game.isPressed();
		xTarget = Game.Xtarget;
		yTarget = Game.yTarget;
		//xTarget = (int)(Game.Xtarget*Game.getSCALE());
		//yTarget = (int)(Game.yTarget*Game.getSCALE());
		//tickHand();
		tickClickController();
		
	}
	/*public void Render(Graphics g) {
		//renderHand(g);
	}*/
	
	
	
	
	
	
	
	
	
	
	
	////////////////////////////////////////////////////
	
	//Controle de clicks
	public void tickClickController() {
		//procurar uma carta selecionada
		Card  c= null;
		for(Card card : deck.getHand()) {
			if(card.isSelected()) {
				c = card;
			}
		}
		double xTarget = this.xTarget*(Game.getSCALE())-u/2;
		double yTarget = this.yTarget*(Game.getSCALE())-u/2;
		if(c != null&& c.getNumClick()==2  && c.isSelected()){
			Game.isPressed =false;
			c.setNumClick(0);
			System.out.println("add");
			//c.SummonChamp();
			//Champion champ = c.getChampion();
			Champion champ = c.SelectChamp();
			if(champ.getCost() > player.getElixir() ) {
				canSummor = false; //não pode invocar
				System.out.println("Não pode invocar!");
				champ.setDestroyed(true);
			}else {
				Game.match.getEntities().add(champ);
				player.getChampions().add(champ);
				canSummor = true;
				player.setElixir((player.getElixir()- champ.getCost()));
				c.setUsable(true);
				deck.getHand().remove(c);
			}
		}else if(c != null&& c.getNumClick()==2  && c.isSelected()&& (yTarget<4.5*u || yTarget> 7.5*u)){
			invalidPosition = true;
			
			isPressed = false;
			
		}
		
	}
	public static boolean isInvalid(double clickY) {
		if(Game.isPressed && (clickY>4.5*u &&  clickY<7.5*u) ) {
			return false;
		}
		return true;
	}
	
	/* Dead
	public void tickClickController() {
		invalidPosition = false;
		//System.out.print(".");
		Card  c= null;
		for(Card card : deck.getHand()) {
			if(card.isPressed()) {
				c = card;
			}
			//System.out.println(card.isSelected());
		}
		double xTarget = this.xTarget*(Game.getSCALE())-u/2;
		double yTarget = this.yTarget*(Game.getSCALE())-u/2;
		
			if(isPressed && c != null && (yTarget>4.5*u &&  yTarget<7.5*u) && c.isSelected()) {
				
				System.out.println("add");
				//isPressed = false;
				//Game.isPressed = false;
				
					c.SummonChamp();
					Champion champ = c.getChampion();
					if(champ.getCost() >player.getElixir() ) {
						canSummor = false; //não pode invocar
						System.out.println("Não pode invocar!");
						champ.setDestroyed(true);
					}else {
						Game.match.getEntities().add(champ);
						player.getChampions().add(champ);
						canSummor = true;
						player.setElixir((player.getElixir()- champ.getCost()));
					}if(c.isSummoner()) {
						hand.remove(c);
					}
				
				
			}
			else if(isPressed && c != null && (yTarget<4.5*u || yTarget> 7.5*u && c.isSelected() )){
				invalidPosition = true;
				
				isPressed = false;
				
			}
		
	}*/
	//Getter e Setter
	public Player getPlayer() {
		return player;
	}
	public void setPlayer(Player player) {
		this.player = player;
	}
	public Deck getDeck() {
		return deck;
	}
	public void setDeck(Deck deck) {
		this.deck = deck;
	}
	public List<Card> getHand() {
		return hand;
	}
	public void setHand(List<Card> hand) {
		this.hand = hand;
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
	public boolean isCanSummor() {
		return canSummor;
	}
	public void setCanSummor(boolean canSummor) {
		this.canSummor = canSummor;
	}
	public boolean isInvalidPosition() {
		return invalidPosition;
	}
	public void setInvalidPosition(boolean invalidPosition) {
		this.invalidPosition = invalidPosition;
	}
	
	
	
	
}
