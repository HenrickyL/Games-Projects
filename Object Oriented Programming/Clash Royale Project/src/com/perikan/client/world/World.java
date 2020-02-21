package com.perikan.client.world;

import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.io.IOException;
import java.lang.reflect.WildcardType;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import javax.imageio.ImageIO;
import javax.swing.text.html.HTMLDocument.HTMLReader.HiddenAction;

import com.perikan.client.entities.*;
import com.perikan.client.main.Game;
import com.sun.javafx.embed.HostInterface;
/* LEitura de pixels para colocar objetos em cima
 * 
 * 
 * */
public class World {
	public static Tile[] tiles;
	private static int WIDTH, HEIGTH;
	public static final int TILE_SIZE = Tile.En_W_H;
	public static int MAP_Width,MAP_Hight;
	private int W_index;
	//SmashRoyale
	public World() {}
	//Construtor
	public World(String path) {
		try {
			BufferedImage map = ImageIO.read(getClass().getResource(path));
			int[] pixel = new int[map.getWidth()*map.getHeight()];
			WIDTH = map.getWidth();
			HEIGTH = map.getHeight();
 			map.getRGB(0, 0, map.getWidth(),map.getHeight(), pixel	, 0,map.getWidth() );
			//inicalizando tile do mesmo tamanho do vetor
			tiles = new Tile[map.getWidth()*map.getHeight()];
			//varrer os pixels
			int cont=0;
			MAP_Hight = map.getHeight();
			MAP_Width = map.getWidth();
			
			
			for(int xx =map.getWidth()-1;xx>=0;xx--) {
				for(int yy =map.getHeight()-1;yy>=0;yy--) {
			//for(int xx =0;xx<map.getWidth();xx++) {
			//	for(int yy =0;yy<map.getHeight();yy++) {
					W_index = xx+yy*WIDTH;
					tiles[W_index] = new TileFloor(xx*Tile.En_W_H, yy*Tile.En_W_H, Tile.TILE_FLOOR);
					Player pRed = Game.match.getPlayerRed();
					Player pBlue = Game.match.getPlayerBlue();
					switch(pixel[W_index]) {
					//recebendo players para alocar as torres
						
					
					
					
						/*case(0xFF000000): //preto
							//chão
							tiles[W_index] = new TileFloor(xx*16, yy*16, Tile.TILE_FLOOR);
							break;*/
						case(0xFF0057ff): // azul
							//parede
							tiles[W_index] = new TileWater(xx*Tile.En_W_H, yy*Tile.En_W_H, Tile.TILE_WATER);
							break;
						
						case(0xFFf3ff00): //amarelo
							tiles[W_index] = new TileStreet(xx*Tile.En_W_H, yy*Tile.En_W_H, Tile.TILE_STREET_V);
							break;
						case(0xFF97f800): //verde
	
							tiles[W_index] = new TileStreet((xx)*Tile.En_W_H, yy*Tile.En_W_H, Tile.TILE_STREET_H);
						
							break;
						case(0xFFff00f6): //roxo1
							tiles[W_index] = new TileStreet(xx*Tile.En_W_H, yy*Tile.En_W_H, Tile.TILE_STREET_SD);
							break;
						case(0xFFbb0638): //roxo2
							tiles[W_index] = new TileStreet(xx*Tile.En_W_H, yy*Tile.En_W_H, Tile.TILE_STREET_SE);
							break;
						case(0xFFc200ff): //roxo3
							tiles[W_index] = new TileStreet(xx*Tile.En_W_H, yy*Tile.En_W_H, Tile.TILE_STREET_ID);
							break;
						case(0xFF804695): //roxo4
							tiles[W_index] = new TileStreet(xx*Tile.En_W_H, yy*Tile.En_W_H, Tile.TILE_STREET_IE);
							break;
						case(0xFFff8c00): //amarelo
							tiles[W_index] = new TileBridge(xx*Tile.En_W_H, yy*Tile.En_W_H, Tile.TILE_BRIDGE);
							break;
							
							
						case(0xFFff0000): //torre Rei Inimigo
							
							TowerKing tKing = new TowerKing((int)((xx-0.5)*Tile.En_W_H), (int)((yy-1)*Tile.En_W_H),
									Tile.En_W_H*2, Tile.En_W_H*2, null,pRed);
							pRed.settKing(tKing);
							pRed.getTowers().add(tKing);
							Game.match.getEntities().add(tKing);
							
							//tiles[W_index] = new TileTower((xx-0.55)*Tile.En_W_H , (yy-1)*Tile.En_W_H, Tile.TILE_TOWER);
							break;
							//00f1ff
						case(0xFF00f1ff): //torre Arqueira Inimigo

							TowerArcher tArcher = new TowerArcher((int)((xx-0.5)*Tile.En_W_H),(int)( (yy-1)*Tile.En_W_H),
									Tile.En_W_H, Tile.En_W_H, null,pRed);
							//adicionando a lista de entidades para serem compilados depois
							Game.match.getPlayerRed().getTowers().add(tArcher);	
							Game.match.getEntities().add(tArcher);							
							
							//tiles[W_index] = new TileTower((xx-0.5)*Tile.En_W_H , (yy-1)*Tile.En_W_H,Tile.TILE_TOWERA_ARCHER);
							break;
						
							//Vegetação: verde  1b5b01
						case(0xFFe6cbff):// Arqueira Azul
							TowerArcher tArcherB = new TowerArcher((int)((xx-0.5)*Tile.En_W_H),(int)( (yy-1)*Tile.En_W_H),
									Tile.En_W_H, Tile.En_W_H,null,pBlue);
							Game.match.getPlayerBlue().getTowers().add(tArcherB);
							Game.match.getEntities().add(tArcherB);
							break;
						case(0xFFf0381c):// Torre rei azul
							TowerKing tKingB = new TowerKing((int)((xx-0.5)*Tile.En_W_H), (int)((yy-1)*Tile.En_W_H),
									Tile.En_W_H*2, Tile.En_W_H*2, null,pBlue);
							Game.match.getPlayerBlue().settKing(tKingB);
							Game.match.getPlayerBlue().getTowers().add(tKingB);
							Game.match.getEntities().add(tKingB);
							break;
						default:
							//tiles[W_index] = new TileFloor(xx*16, yy*16, Tile.TILE_FLOOR);						
					}
					
				}
			}
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	//colisões - ppde ir?
	
	public static boolean isFree(int xNext, int yNext) {
		int x1 = xNext / TILE_SIZE;
		int y1 = yNext /TILE_SIZE;
		
		int x2 = (xNext+TILE_SIZE-1 )/ TILE_SIZE;
		int y2 = yNext /TILE_SIZE;
		
		int x3 = xNext / TILE_SIZE;
		int y3 = (yNext +TILE_SIZE-1 )/TILE_SIZE;
		
		int x4 = (xNext+TILE_SIZE -1)/ TILE_SIZE;
		int y4 = yNext /TILE_SIZE;
		
		
		return !(tiles[x1+(y1*World.WIDTH)] instanceof TileWater ||
				tiles[x2+(y2*World.WIDTH)] instanceof TileWater ||
				tiles[x3+(y3*World.WIDTH)] instanceof TileWater ||
				tiles[x4+(y4*World.WIDTH)] instanceof TileWater
				
				
				);
	}
	
	
	//render
	public void render(Graphics g) {
		//Otimizar renderização
			//onde começa a renderizar lado direito da tela
		//int xStart = Camera.getX() >> 4; //Estamos usando o tamanho dos Tiles(16) da pra deixar mais otimizado
		//int yStart = Camera.getY() >> 4;// Otimização de velocidade    Camera.getY()/16; 
			//outro lado da tela
		//int xFinal = xStart + (Game.WIDTH>>4) +1;
		//int yFinal = yStart + (Game.HEIGHT>>4) +1; 
		//renderizar
		/*
		for(int xx xStart;xx<=xFinal;xx++) {
			for(int yy=0yStart;yy<=yFinal;yy++) {
				if(xx<0 || yy<0 ||xx>=WIDTH || yy>=HEIGTH)
					continue;
				Tile t = tiles[W_index];
				t.render(g);
			}
				
		}*/
		for(Tile t: tiles) t.render(g);
		/*
		for(Tile t : tiles) {
			t.render(g);
			
		}*/
	}

	public static int getWIDTH() {
		return WIDTH;
	}

	public static void setWIDTH(int wIDTH) {
		WIDTH = wIDTH;
	}

	public static int getHEIGTH() {
		return HEIGTH;
	}

	public static void setHEIGTH(int hEIGTH) {
		HEIGTH = hEIGTH;
	}


	
	
	
}
