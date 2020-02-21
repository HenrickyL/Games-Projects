package com.perikan.client.entities;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Rectangle;
import java.awt.image.BufferedImage;

import com.perikan.client.main.Game;
import com.perikan.client.world.Tile;

public class TowerArcher extends Tower{
	private int u = Tile.En_W_H;
	private BufferedImage TOWER_ARCHER = Game.spritesheet.getSprite(0*Tile.En_W_H, 6*Tile.En_W_H, Tile.En_W_H*2, Tile.En_W_H*2);
	private BufferedImage TOWER_ARCHER_B = Game.spritesheet.getSprite(2*Tile.En_W_H, 6*Tile.En_W_H, Tile.En_W_H*2, Tile.En_W_H*2);
	//construtor
	public TowerArcher(int x, int y, int width, int heigth, BufferedImage sprite,Player p) {
		super(x, y, width, heigth, sprite,p);
		// TODO Auto-generated constructor stub
		getAtacad = true;
		doAtacad = true;
		this.HP_MAX = 1000;
		this.HP = HP_MAX;
		this.defense = 0;
		this.damage = 25;
		this.cooldown = 1;
		
		agroAtk = new Rectangle((int)(getX()-(5.5)*u),(int)(getY()-6*u),13*u,12*u);
		
	}
	@Override
	public void tick() {
		super.tick();
		
	}
	@Override
	public void render(Graphics g) {
		//super.render(g);
		renderTower(g);
		renderHP(g);
		g.setColor(new Color(0,255,0,255));
		g.drawRect(pos.x, pos.y, pos.width, pos.height);
		//g.setColor(new Color(255,255,0,255));
		//g.drawRect(agroAtk.x, agroAtk.y, agroAtk.width, agroAtk.height);
		
	}
	//########################################
	
	
	
	
	public void renderTower(Graphics g) {
		if(!isDestroyed) {
			if( isRed){
				g.drawImage(TOWER_ARCHER,(int)this.getX(),(int)this.getY(),null);
			}else {
				g.drawImage(TOWER_ARCHER_B,(int)this.getX(),(int)this.getY(),null);
			}
		}else {
			g.setColor(cor);
			g.fillRect((int)(getX()+0.5*u), (int)(getY()+u), u, u);
		}
	}
	//renderizar HP
	public void renderHP(Graphics g) {
		if(isRed) cor = new Color(190,40,40);
		else cor = new Color(40,40,190);
		
			
		if(HP < HP_MAX && HP>0 || (isRed && HP>0)) {
			//HP_MAx
			g.setColor(new Color(0, 0, 0, 200));
			g.fillRect((int)(getX()+u*0.5),(int)( getY()+10), u, 18);
			//HP
			g.setColor(cor);
			g.fillRect((int)(getX()+u*0.5)+1,(int)( getY()+10)+1,(int)( u*((double)HP/HP_MAX))-2, 15);
			//Fonte 
			
			g.setFont(new Font("Verdana",0,20));
			g.setColor(Color.WHITE);
			g.drawString(""+HP,(int)(getX()+u*(1-0.2))+10,(int)( getY())+5);
			//img Coroa
			g.drawImage(Tile.TILE_CROWN_HP, getX(), getY()-18, u,u, null);
		}
	}


}
