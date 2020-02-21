package com.perikan.client.entities;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.net.InterfaceAddress;

import com.perikan.client.config.CardController;
import com.perikan.client.entities.cards.CardArcher;
import com.perikan.client.entities.cards.CardBarbarian;
import com.perikan.client.entities.cards.CardGiant;
import com.perikan.client.entities.champs.Archer;
import com.perikan.client.entities.champs.Barbarian;
import com.perikan.client.entities.champs.Giant;
import com.perikan.client.graphic.SpriteSheet;
import com.perikan.client.main.Game;
import com.perikan.client.world.Tile;

public abstract class Card extends Entity{
	protected boolean isHand = false;
	protected boolean isPressed =false;
	protected boolean usable= false;
	protected boolean selected =false;
	protected boolean invalid= false;
	protected int numClick =0;
	protected boolean summoner = false;
	protected boolean renderSelected =false;
	protected String type;// magic Champion
	protected Champion champion;
	protected Deck deck;
	//posição de click
	protected int clickX = 2*u,clickY = 16*u;// 3*Tile.En_W_H, 16*Tile.En_W_H pos
	private boolean invalidPosition = false;
	
	
	//Sprites
	protected static int Width = 127,Heigth = 157;
	protected static SpriteSheet CardIMG = new SpriteSheet("/Cards.png");
		//exemple
	protected static BufferedImage CARD_BARBARIAN = CardIMG.getSprite(0*Width, 0*Heigth,Width ,Heigth );
	protected static BufferedImage CARD_GIANT = CardIMG.getSprite(2*Width, 0*Heigth,Width ,Heigth );
	protected static BufferedImage CARD_ARCHER = CardIMG.getSprite(1*Width, 0*Heigth,Width ,Heigth );
	protected static BufferedImage DROP = CardIMG.getSprite(0*Width, 2*Heigth,Width ,Heigth );
	
 	
	//Construtor
	
	public Card(Deck deck) {
		super(2*u,16*u, Width, Heigth, null);
		this.deck = deck;
		//deck.getDeckList().add(this);
	}
	@Override
	public void tick() {
		isPressed = Game.isPressed;
		clickX = (int)(Game.Xtarget*Game.getSCALE());
		clickY = (int)(Game.yTarget*Game.getSCALE());
		tickIsCardPressed();
		tickSelected();
		if(usable) {
			this.isDestroyed = true;
			deck.getDeck().remove(this);
		}
		
	}
	@Override
	public void render(Graphics g) {
		if(isHand) {
			g.drawImage(sprite,getX(),getY() , null);
			//desenhar a gota com preço
		}if(!renderSelected && !Game.beggin) {
			g.setColor(new Color(0,0,0,130));
			g.fillRect(getX(), getY(), Width, Heigth);
		}else if(selected && Game.beggin) {
			g.setColor(new Color(0,0,0,130));
			g.fillRect(getX(), getY(), Width, Heigth);
		}
		if(invalid) {
			g.setColor(new Color(255,0,0,125));
			g.fillRect(getX(), getY(), Width, Heigth);
		}
		renderPrice(g);
	}
	//////////////////////////////////////////////////////////
	//Verificar pressionamento
	private void tickIsCardPressed() {
		if(Game.match.getTime()%1==0) invalid = false;
		if(isPressed) {
			//Game.isPressed =false;
			
			if(clickX > getX() && clickX <= getX()+Width && 
			clickY> getY() && clickY <= getY()+Heigth) {
					
				if(!Game.beggin && !selected){
					selected = true;
					renderSelected =true;
				}else if(!selected) {
						selected = true;
						numClick=1;
						Game.isPressed =false;
						renderSelected = true;
				} else if(selected) {
						selected = false;
						renderSelected = false;
						numClick = 0;
						Game.isPressed =false;
					//Se não pode comprar
				}if(Game.beggin && deck.getPlayer().getElixir()-cost <0) {
					invalid = true;
					selected = false;
					renderSelected = false;
					Game.isPressed = false;
					
				}
			}else {
				if(Game.beggin) {
					numClick = 2;
					
					if(!CardController.isInvalid(this.clickY)) {
						numClick = -1;
						selected = false;
						renderSelected =false;
					}
					
					
					
					
				}
			}
		}
	}
	//Verificar seleção
	public void tickSelected() {
		if(selected && !Game.isBeggin()) { //Tela de seleção
			deck.getDeckList().add(this);
			Game.isPressed = false;
			selected = false;
			Game.isPressed = false;
		}else if(selected && Game.isBeggin()) {
			
		}
	}
	//Verificar se foi invocado
	public void SummonChamp() { //
		if(isPressed && selected && !verInvalidPosition() && deck != null && Game.isBeggin()) {
			isPressed = false;			
			Champion c = SelectChamp();
			//Game.match.getEntities().add(c);
			this.champion = c;
			//deck.getHand().remove(c);
			summoner = true;
			usable = true;
			isHand = false;
			
		}
	}
	//saber qual campeão invocar
	public Champion SelectChamp() {
		double xx = (int)(Game.Xtarget*Game.getSCALE()-u/2);
		double yy = (int)(Game.yTarget*Game.getSCALE()-u/2);
			if(this instanceof CardArcher) {
				return new Archer(xx, yy, Width, Heigth,deck.getPlayer());
			}else if(this instanceof CardGiant) {
				return new Giant(xx, yy, Width, Heigth,deck.getPlayer());
			}else if(this instanceof CardBarbarian) {
				return new Barbarian(xx, yy, Width, Heigth,deck.getPlayer());
			}//add more
			
			return null;
		}
	
	//verificar posição invalida de invocação
	private boolean verInvalidPosition() {
		invalid =false;
		if(isPressed && (clickY<4.5*u || clickY> 7.5*u)) {
			invalid =true;
			return true;
		}
		return false;
	}
	//Renderizar a gota com o preço
	private void renderPrice(Graphics g) {
		g.drawImage(DROP, getX()-(int)(0.8*u), getY()-(int)(1.2*u), null);
		g.setColor(Color.WHITE);
		g.setFont(new Font("Arial",Font.BOLD,23));
		g.drawString(""+cost, getX(), getY()+(int)(u*0.4));
	}
	
	
	
	//getter e Setter
	public boolean isPressed() {
		return isPressed;
	}
	public void setPressed(boolean isPressed) {
		this.isPressed = isPressed;
	}
	public boolean isUsable() {
		return usable;
	}
	public void setUsable(boolean usable) {
		this.usable = usable;
	}
	public boolean isSelected() {
		return selected;
	}
	public void setSelected(boolean selected) {
		this.selected = selected;
	}
	public String getType() {
		return type;
	}
	public void setType(String type) {
		this.type = type;
	}
	public Champion getChampion() {
		return champion;
	}
	public void setChampion(Champion champion) {
		this.champion = champion;
	}
	public int getClickX() {
		return clickX;
	}
	public void setClickX(int clickX) {
		this.clickX = clickX;
	}
	public int getClickY() {
		return clickY;
	}
	public void setClickY(int clickY) {
		this.clickY = clickY;
	}
	public boolean isInvalidPosition() {
		return invalidPosition;
	}
	public void setInvalidPosition(boolean invalidPosition) {
		this.invalidPosition = invalidPosition;
	}
	public boolean isHand() {
		return isHand;
	}
	public void setHand(boolean isHand) {
		this.isHand = isHand;
	}
	public boolean isSummoner() {
		return summoner;
	}
	public void setSummoner(boolean summoner) {
		this.summoner = summoner;
	}
	public int getNumClick() {
		return numClick;
	}
	public void setNumClick(int numClick) {
		this.numClick = numClick;
	}
	
	
}
