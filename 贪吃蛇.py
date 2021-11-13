import pygame#导入pygame包
import random#这个包是用来产生随机数，偏于后面水果位置的变换
import pygame.font#显示分数时，所用的字体
import sys#退出时所需要的包
from game_state import GameStates
from pygame.math import Vector2#表示向量，用于蛇的身体以及方向的移动

#蛇的有关属性以及相关设置
class SNAKE:
    def __init__(self):
        self.body=[Vector2(5,10),Vector2(4,10),Vector2(3,10)]#初始蛇的身体
        self.direction=Vector2(1,0)#初始蛇移动的方向
        self.new_Block=False#没有吃到食物所以初始新身体就显示为False
        self.righthead = pygame.image.load("picture/headright.png")#导入所需要的图片，用作头部和身体，以下类似格式都为这个功能
        self.lefthead = pygame.image.load("picture/headleft.png")
        self.uphead = pygame.image.load("picture/headup.png")
        self.downhead = pygame.image.load("picture/headdown.png")
        self.bodyimage=pygame.image.load("picture/body (1).png")
        self.crunch_sound=pygame.mixer.Sound("Sound/EatFood.wav")#这个导入所需要的音频文件，这个时吃东西的音频


#画蛇的操作，包括蛇头的方向的设置
    def draw_sanke(self):
        self.update_head_graphics()
        for index, block in enumerate(self.body):#利用枚举方法判断索引以及身体
            x_pos=block.x*cell_size
            y_pos=block.y*cell_size
            block_rect=pygame.Rect(x_pos,y_pos,cell_size,cell_size)#处理矩形对象，这是pygamed的一种用法，
                                                                   # 能够象处理矩形一样来处理游戏元素

            if index==0:
                screen.blit(self.head,block_rect)#这是放入头部
            else:
                screen.blit(self.bodyimage,block_rect)#这是放入身体

    def update_head_graphics(self):#判断头部方向，使得我们导入的一些头部不同方向的图片显示在正确的位置
        head_relation=self.body[1]-self.body[0]
        if head_relation == Vector2(1,0):
            self.head=self.lefthead
        if head_relation == Vector2(-1,0):
            self.head=self.righthead
        if head_relation == Vector2(0,1):
            self.head=self.uphead
        if head_relation == Vector2(0,-1):
            self.head=self.downhead
#移动蛇身
    def move_snake(self):
        if self.new_Block==True:#如果有新增加的模块，那么就加进去
            body_copy = self.body[:]
            body_copy.insert(0, body_copy[0] + self.direction)
            self.body = body_copy[:]
            self.new_Block=False
        else:#如果没有就是正常的运动
            body_copy = self.body[:-1]
            body_copy.insert(0, body_copy[0] + self.direction)
            self.body = body_copy[:]

    def add_blocks(self):
        self.new_Block=True
    def eatSound(self):#吃东西声音的播放
        self.crunch_sound.play()
    def reset(self):
        self.body=[Vector2(5,10),Vector2(4,10),Vector2(3,10)];
        self.direction=Vector2(0,0)

#水果的类，包含了水果的显示以及相关属性
class FRUIT:
    def __init__(self):
        self.randomsize()#随机产生水果的一个位置

    def draw_fruit(self):#在屏幕上显示出苹果
        fruit_rect = pygame.Rect(self.pos.x * cell_size, self.pos.y * cell_size, cell_size, cell_size)
        screen.blit(littleapple, fruit_rect)


    def randomsize(self):#随机数产生的具体用法
        self.x = random.randint(0, cell_number - 1)
        self.y = random.randint(0, cell_number - 1)
        self.pos = Vector2(self.x, self.y)

#主模块，在这里对蛇的模块和水果的模块进行处理操作
class MAIN:
    def __init__(self):
        self.snake=SNAKE()#想初始化一个蛇类和下面的水果类
        self.fruit=FRUIT()


    def update(self):#更新操作
        self.snake.move_snake()
        self.check_collision()
        self.check_fail()


    def draw_elements(self):#画出屏幕所需的一些元素，草坪，水果，蛇等等
        self.draw_grass()
        self.fruit.draw_fruit()
        self.snake.draw_sanke()
        self.draw_score()




    def check_collision(self):#判断吃食物的函数
        if self.fruit.pos==self.snake.body[0]:
            self.fruit.randomsize()
            self.snake.add_blocks()
            self.snake.eatSound()


    def check_fail(self):#判断游戏是否失败，就是检测是否有碰撞事件
        if not 0<=self.snake.body[0].x<cell_number or not 0<=self.snake.body[0].y<cell_number:
            self.game_over()
        for block in self.snake.body[1:]:
            if block==self.snake.body[0]:
                self.game_over()

    def draw_grass(self):#画出草坪，交替画出草坪
        grass_color=(167,209,61)
        for row in range(cell_number):
            if row%2==0:
                for col in range(cell_number):
                    if col%2==0:
                        grass_rect=pygame.Rect(col*cell_size,row*cell_size,cell_size,cell_size)
                        pygame.draw.rect(screen,grass_color,grass_rect)
            else:
                for col in range(cell_number):
                    if col % 2 !=0:
                        grass_rect = pygame.Rect(col * cell_size, row * cell_size, cell_size, cell_size)
                        pygame.draw.rect(screen, grass_color, grass_rect)

    def draw_score(self):#分数的计算以及显示
        score=str(len(self.snake.body)-3)#分数的值
        score_surface=game_font.render(score,True,(56,74,12))#渲染
        score_x=cell_size*cell_number-60#现实的位置
        score_y=cell_size*cell_number-40
        score_rect=score_surface.get_rect(center=(score_x,score_y))
        apple_recct=littleapple.get_rect(midright=(score_rect.left,score_rect.centery))
        bg_rect=pygame.Rect(apple_recct.left,apple_recct.top,apple_recct.width+score_rect.width,apple_recct.height)
        pygame.draw.rect(screen,(167,209,61),bg_rect)
        screen.blit(score_surface, score_rect)
        screen.blit(littleapple, apple_recct)
        pygame.draw.rect(screen,(56,74,12),bg_rect,2)

    def game_over(self):#退出游戏
        self.snake.reset()
        # pygame.quit()
        # sys.exit()


#下面是几个颜色的rgb
YELLOWGREEN=154,205,50
LEMOGREEN=50,205,50
FORRESTGREEN=34,139,34
RED=255,0,0
BLACK=0,0,0
#初始化pygame这是每个游戏都有的一个步骤
pygame.init()
#字体的导入，这里用的是默认的pygame给的一个字体，若是需要其他的字体可以自行下载
game_font=pygame.font.Font(None,30)
#下面时格子的数量以及大小，用来显示屏幕，移动身体等等
cell_size=35
cell_number=20
#显示屏幕
screen=pygame.display.set_mode((cell_number*cell_size,cell_number*cell_size))
#显示名称
pygame.display.set_caption("贪吃蛇游戏🐍")
#时钟表示每秒多少帧的用法
clock = pygame.time.Clock()
state=GameStates()
#加载图片进来，以下相同格式均是此作用
littleapple=pygame.image.load("picture/apple.png").convert_alpha()
apple=pygame.image.load("picture/Apple.ico").convert_alpha()
WaterMelon=pygame.image.load("picture/Watermelon.ico").convert_alpha()
Blackberry=pygame.image.load("picture/Blackberry.ico").convert_alpha()
Cherries=pygame.image.load("picture/Cherries.ico").convert_alpha()
Strawberry=pygame.image.load("picture/Strawberry.ico").convert_alpha()
fruitarr=[apple,WaterMelon,Blackberry,Cherries,Strawberry]
bgsound=pygame.mixer.Sound("Sound/bg.mp3")
#隔一段时间就会更新一次
SCREEN_UPDATE=pygame.USEREVENT
pygame.time.set_timer(SCREEN_UPDATE,150)
main_game=MAIN()
#循环显示界面，这样使得界面一直处于显示的状态
while True:
    for event in pygame.event.get():
       if event.type==pygame.QUIT:
           pygame.quit()
           sys.exit()
       if event.type==SCREEN_UPDATE:
           main_game.update()
       if event.type==pygame.KEYDOWN:#这是上下左右键的事件的执行
           if event.key==pygame.K_UP:
               if main_game.snake.direction.y!=1:
                     main_game.snake.direction=Vector2(0,-1)
           if event.key == pygame.K_DOWN:
               if main_game.snake.direction.y != -1:
                     main_game.snake.direction = Vector2(0, 1)
           if event.key==pygame.K_LEFT:
               if main_game.snake.direction.x!= 1:
                    main_game.snake.direction=Vector2(-1,0)
           if event.key == pygame.K_RIGHT:
               if main_game.snake.direction.x != -1:
                    main_game.snake.direction = Vector2(1, 0)
           if event.key == pygame.K_SPACE:
               main_game.snake.direction=Vector2(0,0)
    #背景音乐的播放
    bgsound.play()
    #填充颜色
    screen.fill((107,142,35))
    #画出各种元素
    main_game.draw_elements()
    #画面更新
    pygame.display.update()
    #每秒显示60帧
    clock.tick(60)
