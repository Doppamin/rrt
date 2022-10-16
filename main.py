import sys, pygame as pg
pg.init()

size = width, height = 800, 600
screen = pg.display.set_mode(size)
screen.fill((0,0,255))
pg.display.set_caption('rrt_homework')
time = pg.time.Clock()
count = 0

FONT = pg.font.SysFont('Tahoma', 25, bold = True)
temp = FONT.render('uzun yazı', 0, (255, 255, 0), (0, 0, 1))
screen.blit(temp, (800 - temp.get_width(), FONT.get_height()))
while True:
	for event in pg.event.get():
		if event.type == pg.QUIT:
			pg.quit()
			exit()
		if event.type == pg.MOUSEBUTTONDOWN:
			if count == 0:
				pg.draw.circle(screen,(0,255,0),(pg.mouse.get_pos()[0],pg.mouse.get_pos()[1]),20)
				count+=1
			elif count == 1:
				pg.draw.circle(screen,(255,0,0),(pg.mouse.get_pos()[0],pg.mouse.get_pos()[1]),20)
				count+= 1
	pg.display.update()
	time.tick(60)