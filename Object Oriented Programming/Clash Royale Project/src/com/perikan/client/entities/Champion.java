package com.perikan.client.entities;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Rectangle;
import java.awt.image.BufferedImage;
import java.net.InterfaceAddress;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

import com.perikan.client.config.MatchController;
import com.perikan.client.entities.*;
import com.perikan.client.graphic.SpriteSheet;
import com.perikan.client.main.*;
import com.perikan.client.world.Tile;
import com.perikan.client.world.World;


public abstract class Champion extends Entity{
	public int midScream;
	protected boolean atackDistance = false;
	private BufferedImage[] spriteUp;
	protected Tower towerFocus= null;
	protected TowerKing kingFocus = null;
	protected Tower deadTower = null;
	protected Champion champFocus= null;
	protected List<Champion> champEnemy;
	protected List<Tower> towerEnemy;
	//Atack
	protected boolean atackingTower = false;
	protected boolean atackingChamp = false;
	protected Player player;
	
	
	//construtor
	
	public Champion(double x, double y, int width, int heigth,Player player) {
		super(x, y, width, heigth, null);
		this.HP_MAX = 100;
		this.HP = HP_MAX;
		this.defense = 5;
		this.damage = 100; 
		this.cooldown = 0.5;
		this.moved = true;
		
		this.player= player;
		champEnemy = new ArrayList<Champion>();
		speed =2;
		doAtacad = true;
		getAtacad = true;
		atackingChamp = false;
		atackingChamp = false;
		//Meio da tela *poderia ser na entitie
		midScream = (int)(Tile.En_W_H*6.5);
		//animation
		sprite = Game.spritesheet.getSprite(u*0, u*2, u ,u);
		
		maxFrame=6;
		maxIndex = 3;
		spriteUp = new BufferedImage[maxFrame];
		sprite = Game.spritesheet.getSprite(Tile.En_W_H*4, Tile.En_W_H*2, Tile.En_W_H ,Tile.En_W_H);
		for(int i=0;i<maxFrame;i++) {
			spriteUp[i] =Game.spritesheet.getSprite(Tile.En_W_H*i, Tile.En_W_H*2, Tile.En_W_H ,Tile.En_W_H);	
		}
		//Agros e Posições para colições
		pos = new Rectangle(getX()+(int)(u/5), getY()+(int)(u/2), maskX, maskY);
		agroAtk = new Rectangle((int)(getX()-getMaskX()/2)+(int)(u/5),(int)(getY()-getMaskY()/2)+(int)(u/2),getMaskW()*2,getMaskH()*2);
		if(player.getTowers().size()<3) {
			towerFocus = player.gettKing();
		}
	}
	public synchronized void tick() {
		super.tick();
		if(player.isRed) {
			towerEnemy = Game.match.getPlayerBlue().getTowers();
		}else{
			towerEnemy = Game.match.getPlayerRed().getTowers();
		}
		if(towerFocus == null || towerFocus.isDestroyed ) { 
			
			towerFocus(towerEnemy);
		}
		
		//animation
		if(isDestroyed == false) {
			frames++;
			if(frames >=maxFrame ) {
				frames = 0;
				index++;
				if(index > maxIndex) {
					index = 0;
				}
			}
		}
		tickIsLive();
		if(!isDestroyed) {
			//movimento
			
			champFocus(champEnemy);
			movimented();
			tickCanAtack();
		}else {
			Game.match.getEntities().remove(this);
		}
		
		
	}
	public void render(Graphics g) {
		if(!isDestroyed) {
			if(sprite == null) g.drawImage(spriteUp[index],getX(),getY(),null);
			else g.drawImage(sprite,getX(),getY(),null);
			
			g.setColor(new Color(255, 0, 0, 100));
			g.drawRect(agroAtk.x,agroAtk.y, agroAtk.width, agroAtk.height);
			g.setColor(new Color(0, 0, 255, 255));
			g.drawRect(pos.x, pos.y, pos.width, pos.height);
			renderHP(g);
		}
	}
	
/////////////////////////////////////////////////////////////////////////////////////////////////////	
	//Render HP champion
	public void renderHP(Graphics g) {
		
		Color cor = new Color(40,40,190);
		
		if(HP < HP_MAX && HP>0 ) {
			//HP_MAx
			g.setColor(new Color(0, 0, 0, 200));
			g.fillRect((int)(this.getX()-u*0.1),(int)( this.getY()+10), u, 12);
			//HP
			g.setColor(cor);
			g.fillRect((int)(this.getX()-u*0.1),(int)( this.getY()+10),(int)( u*((double)HP/HP_MAX)), 12);
			//Fonte 
			
			//g.setFont(new Font("Verdana",0,20));
			//g.setColor(Color.WHITE);
			//g.drawString(""+HP,(int)(getX()+u*(1-0.2))+10,(int)( getY())+5);
		}
	}
	
	//definir foco
	public void towerFocus(List<Tower> towers) {
		boolean towerIsLeft;
		boolean ChampIsLeft;
		//buscar a torre
		for(Tower t : towers) {
			if(t instanceof TowerKing) {
				kingFocus = (TowerKing) t;
			}else {
				deadTower = (TowerArcher) t;
			}
			towerIsLeft = t.getX() <= midScream;//*Game.getSCALE();
			//se o campeão está a esquerda da tela
			ChampIsLeft = this.getX() <= midScream;//*Game.getSCALE();
			if(t.isGetAtacad() && !t.isDestroyed) {
				
				//System.out.println("Mid"+Tile.En_W_H*6.5+", xC: "+this.getX()+"+ xT: "+t.getX());
				//se a torre está a esquerda da metade da tela
				
				
				if(towerIsLeft && ChampIsLeft) {
					towerFocus = t;
					
				}else if(!towerIsLeft && !ChampIsLeft){
					towerFocus = t;
					
				}else if(t instanceof TowerKing) {
					towerFocus = t;
				}
				//System.out.println("TF: "+towerFocus.getX());
			}
			//caso as arqueiras tenham morrido, olhar a que morreu que ele iria
			if( t instanceof TowerArcher && t.isDestroyed()){ 
				//boolean isMid = u*6 < t.getX() && t.getX()<u*7;//está no meio
				if(towerIsLeft && ChampIsLeft) {
					deadTower = (TowerArcher) t;
					
				}else if(!towerIsLeft && !ChampIsLeft){
					deadTower = (TowerArcher) t;
					
				}else {
					deadTower = t;
				}
				
			}
		}
		
	}
	//isLive - metodo para verificar  a vida
	public void tickIsLive() {
		if(HP<=0) {
			isDestroyed = true;
		}
	}
	//
	
	//Focar champion
	private void champFocus(List<Champion> champEnemy) {
		if(champFocus == null && atackingChamp!=true) {
			for(Champion c : champEnemy) {
				//Agro de atk do meu campião detectar um campião inimigo
				if(this.agroAtk.intersects(c.pos)) {
					champFocus = c;
					atackingChamp=true;
					break;
				}
			}
		}else if(champFocus.HP<=0) {//adicionar caso pressionado
			champFocus = null;
			atackingChamp=false;
		}
	}
	//atacar
	public void tickCanAtack() {
		if(atackingChamp == false && towerFocus != null && atackingTower == false) {
			if(this.agroAtk.intersects(towerFocus.pos)) {
				atackingTower = true;
				timeBeginAtack = Game.match.time; // salvo o tempo quando ele começou a aatacar
			}else atackingTower = false;
		}if(atackingTower && towerFocus.HP > 0 && !atackingChamp) { //* usar o estatus de atacking para alternar os mods
			if(Game.match.time == timeBeginAtack + cooldown) {
				towerFocus.HP += towerFocus.defense - this.damage;
				timeBeginAtack += cooldown;
				
			}if(towerFocus.HP<=0) {
				atackingTower = false;
				towerFocus = kingFocus;
			}
				
				//*chamar towerFocus, porém precisa tratar melhor, talvez fazer uma sobrecarga
		}else if(atackingTower && towerFocus.HP<0){
			player.getTowers().remove(this);
			atackingTower = false;
			
			
		}
		
	}
	
	//movimento
	public void movimented() {
		//É para mudar o foco para o rei?
		/*if(towerFocus instanceof TowerKing && getY()<u*5 ) {
			towerFocus = deadTower;
		}else*/ if(towerFocus instanceof TowerKing) {
			towerFocus = kingFocus;
		}
		
		
		/*if(towerFocus.isDestroyed() && getY()>deadTower.getY()) {
			towerFocus = deadTower;
		}else if(towerFocus.isDestroyed() && !(towerFocus instanceof TowerKing)&&
						getY()<u*10){
			towerFocus = kingFocus;
		}else if(towerFocus.isDestroyed() ){
			towerFocus = deadTower;
		}*/
		//ir para o champ caso
		Entity focus = (champFocus == null ? towerFocus : champFocus);
		
		if(doAtacad && focus != null && (atackingChamp == false && atackingTower == false ) 
				&& !kingFocus.isDestroyed()) {
			
			
				if((this.getX()+this.maskX) <=  (focus.getX()+focus.getMaskX()) 
						&& x< u*13 /*&& World.isFree((int)(x+speed),(int)( pos.y))*/) {
					x+=speed;
				}else if((this.getX()-this.maskX) > (focus.getX()-focus.getMaskX()) 
						&& x>=0 /*&& World.isFree((int)(x-speed),(int)(pos.y))*/){
					x-=speed;
					//foco acima do rio
				}
				/*if((int)this.getY()<towerFocus.getY()+towerFocus.getMaskY()) {
					y+=speed;
				}else */
				//int aux = -getY()*getY()+18*getY()-80; //ideia errada
				if((int)this.getY()-this.maskY >focus.getY()+focus.getMaskY()
									/*&& World.isFree((int)(x),(int)(pos.y-speed))*/){
					y-=speed;
				}
			
			}
		}
	//ajuste de movimento
	public void auxMiviment() {
		if(towerFocus instanceof TowerKing) {}
	}
	
	
	
	//colisão com torres
	public boolean isColiddingWithTower() {
		//Rectangle champCurrent = new Rectangle(this.getX()+maskX,this.getY()+maskY,maskW,maskH);
		
			
		return true;	
	}
	//colisão com campiões
	
	/*public boolean isColiddingChamp(int xNest, int yNext) {
		Rectangle champCurrent = new Rectangle(xNest,yNext,maskW,maskH);
		for(Champion c : Game.match.getChamps() ) {
			if(this == c) 
				continue;
			Rectangle targetEnemy = new Rectangle(c.getX(),c.getY(),maskW,maskH);
			if (champCurrent.intersects(targetEnemy)) {
				return true;
				
			}
		}return false;
	
	}*/
	//GETTER E SETTER
	public int getCost() {
		return cost;
	}
	public void setCost(int cost) {
		this.cost = cost;
	}
	
	
}
