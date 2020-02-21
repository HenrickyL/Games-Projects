package com.perikan.client.entities.cards;

import java.awt.Graphics;
import java.awt.image.BufferedImage;

import com.perikan.client.entities.Card;
import com.perikan.client.entities.Deck;

public class CardBarbarian extends Card {

	public CardBarbarian() {
		super(null);
		this.cost = 3;
		this.sprite = Card.CARD_BARBARIAN;
		this.type = "Barbarian";
		
	}
	public CardBarbarian(Deck deck) {
		super(deck);
		this.cost = 3;
		this.sprite = Card.CARD_BARBARIAN;
		this.type = "Barbarian";
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
