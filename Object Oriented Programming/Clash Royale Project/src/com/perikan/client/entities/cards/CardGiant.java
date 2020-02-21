package com.perikan.client.entities.cards;

import java.awt.Graphics;
import java.awt.image.BufferedImage;

import com.perikan.client.entities.Card;
import com.perikan.client.entities.Deck;

public class CardGiant extends Card{
	
	public CardGiant() {
		super(null);
		this.sprite = Card.CARD_GIANT;
		this.type = "Giant";
		this.cost = 5;
	}
	
	public CardGiant(Deck deck) {
		super(deck);
		this.sprite = Card.CARD_GIANT;
		this.type = "Giant";
		this.cost = 5;
	}
	@Override
	public void tick() {
		super.tick();
	}
	@Override
	public void render(Graphics g) {
		super.render(g);
	}
}
