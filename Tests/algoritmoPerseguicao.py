import pygame as pg # biblioteca de jogos
from pygame.locals import *
import pygame.font #trabalhar com fontes
from time import sleep #pausar o sistema
from random import randint #gerar numeros aleatórios
import numpy as np #trabalhar com vetores e matemática em geral

'''PARA COMPILAR:
-é necessário usar as bibliotecas acimas, logo para instala-las é necessário usar o "pip install pygame"  no linux
- se não tem o pip, use "apt-get install python3 python3-pip"


'''





class Default: #Criada para deixar valores padrões.
    window=[800,600] #dimensões da janela
    title = "Simulation @HenrickyL"
    Game_area=[window[0],window[1]] #comprimento e largura maximos (salvando para que os objetos tenham referencia pera não sair da tela )

class APP:
    def __init__(self): # "metodo" construtor : vou colocar muitas variaveis inicializadoras ou verificadoras
        self.run=True;
        self.BG= None #background
        self.B=pg.Surface([10,10]) #objeto movel
        self.begin=False
        self.Key = False
        self.M=pg.Surface([15,15])
        self.Wd=Default.Game_area
        self.pos=[self.Wd[0]/2,self.Wd[1]/2]
        self.cont = 0
        self.x=self.Wd[0]/4
        self.y=self.Wd[1]/4
        self.Speed =False
        self.slow = False
        self.buff=False
        self.buff_c=0;
    def Quit_game(self): #função que encerra a "simulação"
        self.BG.fill([0,0,0]) #função fill aplicada no obejeto BG, ou seja pintar background de branco
        pg.display.update() #dar uma atualização na tela
        sleep(0.5)
        pg.quit() #encerrar
    def draw(self): #fazer os "prints" de tela
        x,y=self.x,self.y #posições
        B_pos=[x,y] #posição de B
        if(self.buff==True):speed=5  #buff de velocidade
        else: speed = 1.8
        
        #definindo a posição com base na anterior, e com as setas
        #cont para reduzir a interação do movimento, so perecebe o botão nos multiplos de 10
        if(self.cont%10==0 and self.begin==True and 0<=B_pos[0]<self.Wd[0] and 0<=B_pos[1]<self.Wd[1]):
            if pygame.key.get_pressed()[K_UP]: # se apertar a ceta para cima modifica y
                y-=speed
            elif pygame.key.get_pressed()[K_DOWN]:
                y+=speed
            if pygame.key.get_pressed()[K_LEFT]:
                x-=speed
            elif pygame.key.get_pressed()[K_RIGHT]:
                x+=speed
        elif(not(0<=B_pos[0]<self.Wd[0] and 0<=B_pos[1]<self.Wd[1])): x,y=self.Wd[0]/4,self.Wd[1]/4
        self.x,self.y=x,y
        #mouse     
        mouse=B_pos#pg.mouse.get_pos() #inicialmente estava fazendo par ao mouse, mas mudei para botões
        self.B.fill([255,0,0])#pintando B de vermelho
        B_pos=[x,y] # 2-upla com a posição
        self.BG.blit(self.B,B_pos)#(mouse[0],mouse[1]))
        
        #objeto
        dif=((mouse[0]-self.pos[0])**2+(mouse[1]-self.pos[1])**2)**0.5 #criando um raio usando (x^2+y^2= R^2)
        #se o objeto dinamico(que se move com as setas) estiver dentro do raio  (150) do outro objeto e dentro dos limites da tela, ele se movimenta
        if(dif<=150 and self.cont%10==0 and self.begin==True and 0<=self.pos[0]<self.Wd[0] and 0<=self.pos[1]<self.Wd[1]):
            sinalx=sinaly=0 #sinais do vetor algebrico que orienta o movimento do objeto estatico
            if(mouse[0]>self.pos[0]): sinalx =1
            elif(mouse[0]<self.pos[0]): sinalx=-1
            elif(mouse[0]==self.pos[0]): sinalx=0
            if(mouse[1]>self.pos[1]): sinaly=1
            elif(mouse[1]<self.pos[1]): sinaly=-1
            elif(mouse[1]==self.pos[1]): sinaly=0
            mod=((mouse[0]-self.pos[0])**2+(mouse[1]-self.pos[1])**2)**0.5 #o modulo do vetor, com base na distancia, logo é mais 
                                                                            #rapido quando está longe e devagar quando perto
            if (self.Speed==True and self.begin==True): # para quero ele rapido uso esse modulo
                #self.Speed=True
                self.slow=False
                V=[mod*sinalx,sinaly*mod]#[self.pos[0]-mouse[0],self.pos[1]-mouse[1]]
            elif(self.slow==True and self.begin==True): # se não ele tem velocidade fixa
                self.Speed=False
    
                V=[20*sinalx,20*sinaly]
            self.pos=[self.pos[0]+V[0]/10,self.pos[1]+V[1]/10]
            #if(mouse[0]==self.pos[] and mouse[1]==)
        else: V=[0,0] #se sair do raio (150) ele para de se mover
        self.M.fill([0,0,255])
        self.BG.blit(self.M,self.pos)
        pg.display.update()
        
    def main(self): #True,False,self.n)
        pg.init()
        #pg.font.init()
        self.BG=pg.display.set_mode(Default.window)
        pg.display.set_caption(Default.title)
        self.BG.fill([255,255,255])
        self.run=True     
        self.settings()
        self.Quit_game()
    
    def settings(self):
        
        while(self.run):
            self.cont+=1
            self.draw()
            self.BG.fill([255,255,255])
            for event in pg.event.get():
                
                if event.type == QUIT:
                    self.run=False 
                if pygame.key.get_pressed()[K_c] :  #BOTÃO QUE INICIA
                    self.begin=True
                    self.slow=True
                    self.Speed=False
                if pygame.key.get_pressed()[K_x]:    #BOTÃO QUE DA O BUFF DO ESTATICO
                    self.Speed = True
                    self.slow=False
                if pygame.key.get_pressed()[pg.K_z]: #BOTÃO QUE DA O BUFF DO DINÂMICO
                    if(self.buff_c==0):
                        self.buff = True
                        self.buff_c=1;
                    elif(self.buff_c!=0 or self.cont%10000==0):
                        self.buff=False
                        self.buff_c=0
appgame=APP()
appgame.main()