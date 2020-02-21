package com.perikan.client.entities;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Rectangle;
import java.awt.image.BufferedImage;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import com.perikan.client.main.Game;
import com.perikan.client.world.Tile;

public abstract class Tower extends Entity{
	protected Queue<Champion> EnemiQueue;
	protected int maskX=Tile.En_W_H,
			maskY=Tile.En_W_H,
			maskW=Tile.En_W_H,
			maskH = Tile.En_W_H;
	protected boolean isRed;
	protected Color cor;
	//atacar Inimigos
	protected List<Champion> Enemys;
	protected Champion focus;
	protected Player player;
	
		//construtor
		public Tower(int x, int y, int width, int heigth, BufferedImage sprite,Player p) {
			super(x, y, width, heigth, sprite);
			this.isRed = p.isRed;
			this.player = p;
			
			EnemiQueue = new LinkedList<Champion>();
			
			isDestroyed = false;
			pos = new Rectangle(getX()+(int)(u/2), getY()+(int)(u), maskX, maskY);
			agroAtk = new Rectangle((int)(getX()-(5.5)*u),(int)(getY()-6*u),13*u,12*u);
			
		}
		@Override
		public void tick() {
			tickLive();
			 // atualiza listas de inimigos
			if(isRed) {
				Enemys = Game.match.getPlayerBlue().getChampions();
			}else {
				Enemys = Game.match.getPlayerRed().getChampions();
			}
			tickFocusChamp();
			tickAtack();
		}
		@Override
		public void render(Graphics g) {
			//super.render(g);
			g.setColor(new Color(255, 0, 0, 100));
			g.drawRect(agroAtk.x,agroAtk.y, agroAtk.width, agroAtk.height);
		}
		//??????????????????????????????????????????????????????????
		//HP
		public void tickLive() {
			if(this.HP<=0) this.isDestroyed = true;
		}
		//Metodos tick -
		public void tickFocusChamp() {
			
			if(Enemys != null) {
				
				/*Enemys.remove(focus);
				if(isRed) {
					Game.match.getPlayerBlue().getChampions().remove(focus);
				}else {
					Game.match.getPlayerRed().getChampions().remove(focus);
				}*/
				if(focus == null || focus.isDestroyed) {
					for(Champion c : Enemys) {
						if(this.agroAtk.intersects(c.pos)){
							EnemiQueue.add(c);
						}
						
						if(this.agroAtk.intersects(c.pos) && !EnemiQueue.isEmpty()) {
							focus = EnemiQueue.poll();
							this.atacking = true;
							timeBeginAtack = Game.match.time;
							
						}
					}	
				}
			}
		}
		
		//Tick Ataque Campiões
		public void tickAtack() {
			if(this.atacking && focus!= null && focus.HP>0 && !this.isDestroyed) {
				if(Game.match.time == timeBeginAtack + cooldown) {
					focus.HP += focus.defense - this.damage;
					//lanço um projetil
					//Projectiles p = new Projectiles((int)(pos.x),(int)(pos.y)+5 , u/3, u/3, focus,this.damage);
					//Game.match.entities.add(p);
					timeBeginAtack += cooldown;
					
				}if(focus.HP<=0) {
					atacking = false;
					focus.setDestroyed(true);
				}
			}
					
		}
		//Métodos Render
		
		
		
		// Getter e Setter
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
		public Player getPlayer() {
			return player;
		}
		public void setPlayer(Player player) {
			this.player = player;
		}
	
		
	}


