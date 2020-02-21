package com.perikan.client.entities.cards;

import java.awt.Graphics;
import java.awt.image.BufferedImage;

import com.perikan.client.entities.Card;
import com.perikan.client.entities.Deck;
import com.perikan.client.main.Game;
import com.perikan.client.world.Tile;

public class CardArcher extends Card{
	
	public CardArcher() {
		super(null);
		this.cost = 2; 
		this.sprite = Card.CARD_ARCHER;
		this.type = "Archer";
	}
	public CardArcher(Deck deck) {
		super(deck);
		this.cost = 2;
		this.sprite = Card.CARD_ARCHER;
		this.type = "Archer";
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
