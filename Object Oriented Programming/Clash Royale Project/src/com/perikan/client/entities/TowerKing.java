package com.perikan.client.entities;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Rectangle;
import java.awt.image.BufferedImage;

import com.perikan.client.main.Game;
import com.perikan.client.world.Tile;

public class TowerKing extends Tower{
	private int u = Tile.En_W_H;
	private static BufferedImage TOWER_KING = Game.spritesheet.getSprite(0*Tile.En_W_H, 8*Tile.En_W_H, Tile.En_W_H*2, Tile.En_W_H*2);
	private static BufferedImage TOWER_KING_B = Game.spritesheet.getSprite(4*Tile.En_W_H, 8*Tile.En_W_H, Tile.En_W_H*2, Tile.En_W_H*2);
	
	//construtor
	public TowerKing(int x, int y, int width, int heigth, BufferedImage sprite,Player p) {
		super(x, y, width, heigth, TOWER_KING,p);
		// TODO Auto-generated constructor stub
		getAtacad = false;
		doAtacad = false;
		this.HP_MAX = 1500;
		this.HP = HP_MAX;
		
		agroAtk = new Rectangle((int)(getX()-(5.5)*u),(int)(getY()-1*u),13*u,5*u);
	}
	public void tick() {
		//animação de poder ou não receber ataque
		if(HP<=0) {
			isDestroyed = true;
		}if(HP<HP_MAX) doAtacad = true;
		
		if(getAtacad || HP<HP_MAX) {
			//passivo
			this.sprite = Game.spritesheet.getSprite(Tile.En_W_H*2, Tile.En_W_H*8, Tile.En_W_H*2 ,Tile.En_W_H*2);
			
		}else {
			//Ativo
			this.sprite = Game.spritesheet.getSprite(Tile.En_W_H*0, Tile.En_W_H*8, Tile.En_W_H*2 ,Tile.En_W_H*2);
		}
	}
	
	@Override
	public void render(Graphics g) {
		if(isRed) {
			g.drawImage(sprite,(int)this.getX(),(int)this.getY(),null);
		}else {
			g.drawImage(TOWER_KING_B,(int)this.getX(),(int)this.getY(),null);
		}
		renderHP(g);
		renderUsername(g);
		
		//verificação do agro
		g.setColor(new Color(0,255,0,255));
		g.drawRect(pos.x, pos.y, pos.width, pos.height);
		/*g.setColor(new Color(255,255,255,255));
		g.drawRect(agroAtk.x, agroAtk.y, agroAtk.width, agroAtk.height);*/
		
	}
	//////////////////////////
	//render Username
	public void renderUsername(Graphics g) {
		if(player != null) {
			if(isRed) g.setColor(Color.red);
			else g.setColor(new Color(100,100,255));
			g.setFont(new Font("Arial", Font.BOLD, 25));
			g.drawString(""+player.getUserName(), pos.x, pos.y-(int)(u*1.2));
		}
	}
	//renderizar HP
	public void renderHP(Graphics g) {
		
		if(isRed) cor = new Color(190,40,40);
		else cor = new Color(40,40,190);
		
			
		if(HP < HP_MAX && HP>0) {
			//HP_MAx
			g.setColor(new Color(0, 0, 0, 200));
			g.fillRect((int)(getX()+u*0.2),(int)( getY()), (int)(u*(1.5)), 18);
			//HP
			g.setColor(cor);
			g.fillRect((int)(getX()+u*0.2)+1,(int)( getY())+1,(int)( u*(1.5)*((double)HP/HP_MAX))-2, 15);
			//Fonte 
			
			g.setFont(new Font("Verdana",0,25));
			g.setColor(Color.WHITE);
			g.drawString(""+HP,(int)(getX()+u*(1-0.3)),(int)( getY()));
			//img Coroa
			g.drawImage(Tile.TILE_CROWN_HP, (int)(getX()-u*0.3), getY()-28, u,u, null);
		}
	}


	

}
