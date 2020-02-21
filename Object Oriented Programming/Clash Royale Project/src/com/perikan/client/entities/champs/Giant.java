package com.perikan.client.entities.champs;

import java.awt.Graphics;

import com.perikan.client.entities.Champion;
import com.perikan.client.entities.Player;
import com.perikan.client.main.Game;

public class Giant extends Champion{

	public Giant(double x, double y, int width, int heigth,Player p) {
		super(x, y, width, heigth,p);
		this.cost = 5; 
		this.HP_MAX = 400;
		this.HP = HP_MAX;
		this.defense = 15;
		this.damage = 100; 
		this.cooldown = 1.5;
		this.speed = 1;
		this.sprite = Game.spritesheet.getSprite(8*u, 1*u, u, u);
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
