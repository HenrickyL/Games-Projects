
package com.perikan.client.entities.champs;

import java.awt.Graphics;
import java.awt.Rectangle;

import com.perikan.client.entities.Champion;
import com.perikan.client.entities.Player;
import com.perikan.client.main.Game;

public class Archer extends Champion{
	private int area;
	public Archer(double x, double y, int width, int heigth,Player p) {
		super(x, y, width, heigth,p);
		// TODO Auto-generated constructor stub
		this.cost = 2;
		this.HP_MAX = 100;
		this.HP = HP_MAX;
		this.defense = 5;
		this.damage = 65; 
		this.cooldown = 0.5;
		this.speed = 1.5;
		this.moved = true;
		this.atackDistance = true;
		this.area = 3;
		agroAtk = new Rectangle((int)(pos.x-maskW*area/2),(int)(pos.y-maskH*area/2 ),getMaskW()*area,getMaskH()*area);
		this.sprite = Game.spritesheet.getSprite(7*u, 1*u, u, u);
	}
	@Override
	public void tick() {
		super.tick();
		agroAtk.x =(int)(pos.x-maskW*area/2);
		agroAtk.y = (int)(pos.y-maskH*area/2);
	}
	@Override
	public void render(Graphics g) {
		super.render(g);
	}
}
