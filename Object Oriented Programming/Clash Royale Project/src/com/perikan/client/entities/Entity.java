package com.perikan.client.entities;

import java.awt.Graphics;
import java.awt.Rectangle;
import java.awt.image.BufferedImage;

import com.perikan.client.main.*;
import com.perikan.client.world.Tile;

public abstract class Entity {
	
	protected static int u = Tile.En_W_H;
	protected int HP,HP_MAX;
	protected double cooldown;
	protected double damage;
	protected int defense;
	protected int hits = 0;
	protected int cost=1;
	protected boolean atacking = false;
	protected double timeBeginAtack=0;
	//protected Entity focus;
	//mascara
	protected int maskX=Tile.En_W_H/2,
			maskY=Tile.En_W_H/2,
			maskW=Tile.En_W_H/2,
			maskH = Tile.En_W_H/2;
	
	//Colisões
	protected Rectangle agroAtk;
	protected Rectangle pos;
	protected boolean isDestroyed = false; // foi destruido
	protected boolean getAtacad = false; //pode ser atacado
	protected boolean doAtacad = false; // pode atacar
	//animation, sprite & position
	protected int frames=0,maxFrame; //animação
	protected int index=0, maxIndex;//animaçaõ
	protected boolean moved=false;
	//posição 
	protected double x,y;
	protected static int width;
	protected int heigth;
	protected BufferedImage sprite;
	//movimento
	protected double speed=1;
	
	
	
	//construtor
	public Entity(double x, double y, int width, int heigth,BufferedImage sprite) {
		this.x = x;
		this.y = y;
		this.width = width;
		this.heigth = heigth;
		this.sprite = sprite;
		pos = new Rectangle(getX()+(int)(u/5), getY()+(int)(u/2), maskX, maskY);
		agroAtk = new Rectangle((int)(getX()-getMaskX()/2)+(int)(u/5),(int)(getY()-getMaskY()/2)+(int)(u/2),getMaskW()*2,getMaskH()*2);
	}
	public void render(Graphics g) {
		//com relação ao jogador
		g.drawImage(sprite,(int)this.getX(),(int)this.getY(),null);
	}
	public void tick() {
		//moved= false;
		pos.x =   getX()+(int)(u/5);
		pos.y = getY()+(int)(u/2);
		agroAtk.x =(int)(getX()-getMaskX()/2)+(int)(u/5);
		agroAtk.y = (int)(getY()-getMaskY()/2)+(int)(u/2);
		//tickIsDestroyed();
	}
	//destruido?
	public void tickIsDestroyed() {
		if(HP<=0) {
			isDestroyed=true;
		}
	}
	
	
	
	
	
	//getter e setter
	public int getX() {
		return (int) x;
	}
	public void setX(double x) {
		this.x = x;
	}
	public int getY() {
		return (int) y;
	}
	public void setY(double y) {
		this.y = y;
	}
	public int getWidth() {
		return width;
	}
	public void setWidth(int width) {
		this.width = width;
	}
	public int getHeigth() {
		return heigth;
	}
	public void setHeigth(int heigth) {
		this.heigth = heigth;
	}
	public boolean isGetAtacad() {
		return getAtacad;
	}
	public void setGetAtacad(boolean getAtacad) {
		this.getAtacad = getAtacad;
	}
	public boolean isDestroyed() {
		return isDestroyed;
	}
	public void setDestroyed(boolean isDestroyed) {
		this.isDestroyed = isDestroyed;
	}
	public void tick(Player p) {
		// TODO Auto-generated method stub
		
	}
	public Rectangle getAgroAtk() {
		return agroAtk;
	}
	public void setAgroAtk(Rectangle agroAtk) {
		this.agroAtk = agroAtk;
	}
	public Rectangle getPos() {
		return pos;
	}
	public void setPos(Rectangle pos) {
		this.pos = pos;
	}
	public int getMaskX() {
		return maskX;
	}
	public void setMaskX(int maskX) {
		this.maskX = maskX;
	}
	public int getMaskY() {
		return maskY;
	}
	public void setMaskY(int maskY) {
		this.maskY = maskY;
	}
	public int getMaskW() {
		return maskW;
	}
	public void setMaskW(int maskW) {
		this.maskW = maskW;
	}
	public int getMaskH() {
		return maskH;
	}
	public void setMaskH(int maskH) {
		this.maskH = maskH;
	}
	public int getHP_MAX() {
		return HP_MAX;
	}
	public void setHP_MAX(int hP_MAX) {
		HP_MAX = hP_MAX;
	}
	public double getCooldown() {
		return cooldown;
	}
	public void setCooldown(double cooldown) {
		this.cooldown = cooldown;
	}
	public double getDamage() {
		return damage;
	}
	public void setDamage(double damage) {
		this.damage = damage;
	}
	public int getDefense() {
		return defense;
	}
	public void setDefense(int defense) {
		this.defense = defense;
	}
	public int getCost() {
		return cost;
	}
	public void setCost(int cost) {
		this.cost = cost;
	}
	
	

	
}
