package com.perikan.client.entities.champs;

import java.awt.Graphics;

import com.perikan.client.entities.Champion;
import com.perikan.client.entities.Player;
import com.perikan.client.main.Game;

public class Barbarian extends Champion{

	public Barbarian(double x, double y, int width, int heigth,Player p) {
		super(x, y, width, heigth,p);
		this.cost = 3; 
		this.HP_MAX = 150;
		this.HP = HP_MAX;
		this.defense = 10;
		this.damage = 50; 
		this.cooldown = 1;
		this.speed = 2;
		//this.sprite = Game.spritesheet.getSprite(6*u, 1*u, u, u);
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
