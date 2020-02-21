package com.perikan.client.entities;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import com.perikan.client.entities.cards.CardArcher;
import com.perikan.client.entities.cards.CardBarbarian;
import com.perikan.client.entities.cards.CardGiant;
import com.perikan.client.entities.champs.Archer;
import com.perikan.client.entities.champs.Barbarian;
import com.perikan.client.entities.champs.Giant;
import com.perikan.client.main.Game;
import com.perikan.client.world.Tile;

public class Deck {
	private static int u = Tile.En_W_H;
	private static int numCards =3;
	private static int decksize= 8;
	protected List<Card> deckList;
	protected Queue<Card> deck;
	protected static List<Card> AllCards;
	protected static boolean createCards;
	protected Player player;
	private List<Card> hand;
	private static int handsize = 4;
	private Card next;
	
	//Construtor
	public Deck(Player p) {
		deckList = new ArrayList<Card>();
		deck = new LinkedList<Card>();
		this.player = p;
		hand = new ArrayList<Card>();
		
	}
	
	public void tick() {
		if(!player.isRed) {
			tickDeckGenerate();
			tickNormalize();
			tickHand();
		//if(Game.match.time %3 ==0) {
			for(Card c : hand) {
				c.tick();
			}
		//}
		}
	}
	public void render(Graphics g) {
		renderHand(g);
	}
	/////////////////////////////////////////
	public void tickHand() {
		for(Card c : hand) {
			if(c.isUsable()) {
				System.out.println(".");
				hand.remove(c);
			}
		}
		if(hand.size()<handsize && getDeck().size()>=handsize) {
			Card c = null;
			if(next != null && hand.size() == 3 ) { 
				c = next;
				next = null;
			}
			else { 
				c = getDeck().poll();
			}
			hand.add(c);
			c.setHand(true);	
		}else if(hand.size() == handsize && next == null) {
			next = getDeck().poll();
			next.setHand(true);
			next.setX((0.5)*u);
			next.setY((17.5)*u);
		}
	
	}
	public void renderHand(Graphics g) { //3*Tile.En_W_H, 16*Tile.En_W_H pos
		for(int i =0;i< hand.size();i++) {
			Card c = hand.get(i);
			if(c.isHand()) {
				c.setX((3+0.5)*u+2.3*i*u);
				c.setY((16+0.6)*u);
				c.render(g);
			}
			if(next != null) { 
				next.render(g);
				g.setColor(Color.black);
				g.setFont(new Font("Arial",Font.BOLD,25));
				g.drawString("Próxima:", (int)(0.5*u), 17*u);
				}
		}
	}
	//Passar a lista para o deck
	private void tickDeckGenerate() {
		if(deck.size() < Deck.decksize) {
			
			for(Card c: deckList) {
				deck.add(SelectCard(c));
			}
		}
	}
	
	//Deixar o deck com suas 8 cartas
	public void tickNormalize() { //fazer com que o deck tenha as 8 cartas
		if(deck.size()<decksize) {
			while(deck.size()<decksize) {
				int k = Game.rand.nextInt(deckList.size());
				//deck.add(deckList.get(k));
				Card c = this.deckList.get(k);
				deck.add(SelectCard(c));
			}
		}
	}
	//Selecionar uma carta
	public Card SelectCard(Card c) {
			if(c instanceof CardArcher) {
				return new CardArcher(this);
			}else if(c instanceof CardGiant) {
				return new CardGiant(this);
			}else if(c instanceof CardBarbarian) {
				return new CardBarbarian(this);
			}//add more
			return null;
		}
	//Embaralhar
	public void shuffle() {
		tickNormalize();
		List<Card> aux = new ArrayList<Card>();
		for(Card c : deck) {
			aux.add(deck.poll());
		}
		Collections.shuffle(aux);
		for(Card c : aux) {
			deck.add(c);
		}
		
	}
	//função Statica que vai me retornar todas as cartas
	public static List<Card> renderDeckOptions(Graphics g, Player p) {
		//*posso criar todas as cartas aqui e mudar os donos no decorrer, reciclando as cartas
		if(!createCards) {
			
			CardBarbarian Barbarian = new CardBarbarian(p.getDeck());
			CardGiant Giant = new CardGiant(p.getDeck());
			CardArcher Archer = new CardArcher(p.getDeck());
			AllCards = new ArrayList<Card>();
			
			AllCards.add(Archer);
			AllCards.add(Giant);
			AllCards.add(Barbarian);
			Collections.shuffle(AllCards);
			createCards=true;
		}
		for(int i = 0; i< AllCards.size();i++ ) {
			int xx=0,yy=0;
			xx=i;
			if(i>4) { yy+=1;xx=0;}
			Card c = AllCards.get(i);
			c.setX((1)*u+ 2.2*xx*u);
			c.setY((4+0.5)*u+3*yy*u);
			c.setHand(true);
			c.render(g);
		}
		
		
		
		
		return AllCards;
		
		
		
		
	}
	
	
	
	//Getter e Setter

	public Queue<Card> getDeck() {
		return deck;
	}

	public void setDeck(Queue<Card> deck) {
		this.deck = deck;
	}

	public static int getNumCards() {
		return numCards;
	}

	public static void setNumCards(int numCards) {
		Deck.numCards = numCards;
	}

	public static int getDecksize() {
		return decksize;
	}

	public static void setDecksize(int decksize) {
		Deck.decksize = decksize;
	}

	public static List<Card> getAllCards() {
		return AllCards;
	}

	public static void setAllCards(List<Card> allCards) {
		AllCards = allCards;
	}

	public static boolean isCreateCards() {
		return createCards;
	}

	public static void setCreateCards(boolean createCards) {
		Deck.createCards = createCards;
	}

	public Player getPlayer() {
		return player;
	}

	public void setPlayer(Player player) {
		this.player = player;
	}

	public List<Card> getDeckList() {
		return deckList;
	}

	public void setDeckList(List<Card> deckList) {
		this.deckList = deckList;
	}

	public List<Card> getHand() {
		return hand;
	}

	public void setHand(List<Card> hand) {
		this.hand = hand;
	}

	public Card getNext() {
		return next;
	}

	public void setNext(Card next) {
		this.next = next;
	}
	
	
	
}
