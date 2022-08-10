import random
from turtle import width, window_height, window_width
import pygame


# Define some colors
white = (255, 255, 255)
red = (255, 0, 0)
black = (0, 0, 0)

# Window size
window_height = 600
window_width = 800
# Game Window
gameWindow = pygame.display.set_mode((window_width, window_height))
pygame.display.set_caption("Snake Game")

# Game Variables
exit_game = False
game_over = False
x = window_width/2
y = window_height/2
x_vel = 0
y_vel = 0
food_x = random.randint(window_width*0.1, window_width*0.9)
food_y = random.randint(window_height*0.1, window_height*0.9)
fps = 30
clock = pygame.time.Clock()
score = 0
snake_len=1
snake=[]
while not exit_game:
    # gameWindow.fill(0, 255, 255)

    for event in pygame.event.get():
        # print(event)
        if event.type == pygame.QUIT:
            exit_game = True
        if event.type == pygame.KEYUP:
            if event.key == pygame.K_ESCAPE:
                exit_game = True

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                x_vel = -10
                y_vel = 0
            if event.key == pygame.K_RIGHT:
                x_vel = 10
                y_vel = 0
            if event.key == pygame.K_UP:
                x_vel = 0
                y_vel = -10
            if event.key == pygame.K_DOWN:
                x_vel = 0
                y_vel = 10
    x += x_vel
    y += y_vel
    if x > window_width or x < 0 or y > window_height or y < 0:
        game_over = True
        exit_game = True
    
    # if x>window_width:
    #     x=0
    # if x<0:
    #     x=window_width
    # if y>window_height:
    #     y=0
    # if y<0:
    #     y=window_height
    
    
    
    
    if abs(x-food_x) < 15 and abs(y-food_y) < 15:
        score += 1
        snake_len += 5
        print(f"Score : {score}")
        food_x = random.randint(window_width*0.1, window_width*0.9)
        food_y = random.randint(window_height*0.1, window_height*0.9)
    gameWindow.fill(white)
    
    head=[]
    head.append(x)
    head.append(y)
    snake.append(head)
    if len(snake)>snake_len:
        snake.pop(0)
    if head in snake[:-1]:
        snake=snake[snake.index(head):]
        snake_len=len(snake)
    
    pygame.draw.circle(gameWindow, red, (food_x, food_y), 10)
    for item in snake:
        if item==snake[len(snake)-1]:
            color=red
        else:
            color=black    
        pygame.draw.rect(gameWindow, color, (item[0], item[1], 20, 20))
    pygame.display.update()
    clock.tick(fps)
pygame.quit()
quit()
# # print(x, y)
# # print(x_vel, y_vel)
# # print(food_x, food_y)
# # print(window_width, window_height)
# # print(gameWindow)
# # print(game_over)
# # print(exit_game)
# # print(pygame.display.get_init())
# # print(pygame.display.get_surface())
# # print(pygame.display.get_surface().get_width())
# # print(pygame.display.get_surface().get_height())
# # print(pygame.display.get_surface().get_size())
# # print(pygame.display.get_surface().get_bitsize())
# # print(pygame.display.get_surface().get_flags())
# # print(pygame.display.get_surface().get_pixel(0, 0))
# # print(pygame.display.get_surface().get_at((0, 0)))
# # print(pygame
#         if event.type == pygame.KEYDOWN:
#             if event.key == pygame.K_LEFT:
#                 x_vel = -5
#                 y_vel = 0
#             if event.key == pygame.K_RIGHT:
#                 x_vel = 5
#                 y_vel = 0

#             if event.key == pygame.K_UP:
#                 y_vel = -5
#                 x_vel = 0
#             if event.key == pygame.K_DOWN:
#                 y_vel = 5
#                 x_vel = 0


#     x = x+x_vel
#     y = y+y_vel

#     gameWindow.fill(white)
#     pygame.draw.rect(gameWindow, red, [food_x, food_y, 10, 10])
#     pygame.draw.rect(gameWindow, black, [x, y, 10, 10])
#     pygame.display.update()
#     clock.tick(fps)
#     # pygame.display.update()
#     # pygame.time.delay(100)
