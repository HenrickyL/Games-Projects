package com.perikan.client.entities;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Rectangle;
import java.awt.image.BufferedImage;

import com.perikan.client.main.Game;
import com.perikan.client.world.Tile;

public class Projectiles extends Entity{
	protected static BufferedImage PROJECTILES = Game.spritesheet.getSprite(0*Tile.En_W_H, 0*Tile.En_W_H, Tile.En_W_H*1, Tile.En_W_H*1);
	protected boolean projInArea = false;
	protected Entity focus;
	
	
	//Construtor
	public Projectiles(double x, double y, int width, int heigth, Entity focus,double damage) {
		super(x, y, width, heigth, PROJECTILES);
		// TODO Auto-generated constructor stub
		this.focus = focus;
		this.speed = 5;
		this.damage = damage;
		//começa imaginando que não é em área
		this.maskX =(int) u/5;
		this.maskY = (int)u/5;
		this.maskW=(int)Tile.En_W_H/5; 
		this.maskH = (int)Tile.En_W_H/5;
		//this.pos = new Rectangle(getX(), getY()+(int)(u/2), maskX, maskY);
		if(projInArea) {
			agroAtk = new Rectangle((int)(getX()-getMaskX()/2)+(int)(u/5),(int)(getY()-getMaskY()/2)+(int)(u/2),getMaskW()*2,getMaskH()*2);
		}else  agroAtk = pos;
		System.out.println(".");
	}
	@Override
	public void tick() {
		super.tick();
		if(focus == null || focus.isDestroyed) this.isDestroyed = true;
		tickMoviment();
	}
	@Override
	public void render(Graphics g) {
		//super.render(g);
		if(!isDestroyed) {
			g.drawImage(PROJECTILES,getX(),getY(),null);
			/*
			g.setColor(new Color(255, 0, 0, 100));
			g.drawRect(agroAtk.x,agroAtk.y, agroAtk.width, agroAtk.height);
			g.setColor(new Color(0, 255, 255, 255));
			g.drawRect(pos.x, pos.y, pos.width, pos.height);
			*/
		}
	}
	//###########################################################################
	//foco
	public void tickMoviment() {
		if(this.agroAtk.intersects(focus.pos)) {
			focus.HP += focus.defense - this.damage;
			
			this.isDestroyed = true;
		}else {
			if(getX()<focus.getX()) {
				x += speed;
			}else {
				x -= speed;
			}
			if(getY()<focus.getY()) {
				y+=speed;
			}else {
				y-=speed;
			}
		}
	}
	
	
	
}
	
