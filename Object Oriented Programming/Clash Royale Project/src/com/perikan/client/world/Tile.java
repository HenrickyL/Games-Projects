package com.perikan.client.world;

import java.awt.Graphics;
import java.awt.image.BufferedImage;

import com.perikan.client.main.*;

public class Tile { //são partes do mapa staticos, como mapa e solo
	public static int En_W_H = 64;
	public static BufferedImage TILE_FLOOR = Game.spritesheet.getSprite(2*En_W_H, 0, En_W_H, En_W_H);
	public static BufferedImage TILE_WATER = Game.spritesheet.getSprite(3*En_W_H, 0, En_W_H, En_W_H);
	public static BufferedImage TILE_STREET_H = Game.spritesheet.getSprite(1*En_W_H, En_W_H, En_W_H, En_W_H);
	public static BufferedImage TILE_STREET_V = Game.spritesheet.getSprite(0*En_W_H, En_W_H, En_W_H, En_W_H);
	public static BufferedImage TILE_STREET_SE = Game.spritesheet.getSprite(3*En_W_H, En_W_H, En_W_H, En_W_H);
	public static BufferedImage TILE_STREET_SD = Game.spritesheet.getSprite(2*En_W_H, En_W_H, En_W_H, En_W_H);
	public static BufferedImage TILE_STREET_ID = Game.spritesheet.getSprite(4*En_W_H, En_W_H, En_W_H, En_W_H);
	public static BufferedImage TILE_STREET_IE = Game.spritesheet.getSprite(5*En_W_H, En_W_H, En_W_H, En_W_H);
	public static BufferedImage TILE_BRIDGE = Game.spritesheet.getSprite(4*En_W_H, 0, En_W_H, En_W_H);
	//king
	public static BufferedImage TILE_TOWER = Game.spritesheet.getSprite(0*En_W_H, 8*En_W_H, En_W_H*2, En_W_H*2);
	//archer
	public static BufferedImage TILE_TOWERA_ARCHER = Game.spritesheet.getSprite(0*En_W_H, 6*En_W_H, En_W_H*2, En_W_H*2);
	public static BufferedImage TILE_TOWER_ARCHER_B = Game.spritesheet.getSprite(2*En_W_H, 6*En_W_H, En_W_H*2, En_W_H*2);
	//table
	public static BufferedImage TILE_TABLE = Game.spritesheet.getSprite(0*En_W_H, 0*En_W_H, En_W_H*2, En_W_H*1);
	//COROA
	public static BufferedImage TILE_CROWN_B = Game.spritesheet.getSprite(6*En_W_H, 0*En_W_H, En_W_H*1, En_W_H*1);
	public static BufferedImage TILE_CROWN_R = Game.spritesheet.getSprite(7*En_W_H, 0*En_W_H, En_W_H*1, En_W_H*1);
	public static BufferedImage TILE_CROWN_HP = Game.spritesheet.getSprite(8*En_W_H, 0*En_W_H, En_W_H*1, En_W_H*1);
	
	private BufferedImage sprite;        
	private double x,y;
	
	//construtor
	public Tile(double x, double y, BufferedImage sprite) {
		this.x = x;
		this.y = y;
		this.sprite = sprite;
	}
	public void render(Graphics g) {
	int x= (int)this.x , y= (int)this.y;
	g.drawImage(TILE_FLOOR, x, y, null);
	g.drawImage(sprite,x,y, null);
		
		
	}


}

