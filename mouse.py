import sys, pygame, serial
pygame.init()

size = width, height = 1920, 1080
screen = pygame.display.set_mode(size)

ser = serial.Serial('/dev/ttyACM0', 57600, timeout=1)

lb = False
rb = False
#pygame.display.toggle_fullscreen()

while 1:
    for event in pygame.event.get():
        if event.type == pygame.QUIT: sys.exit()

    x, y = pygame.mouse.get_pos()
    dx, dy = pygame.mouse.get_rel()
    
    lbo = lb
    rbo = rb
    
    lb, mb, rb = pygame.mouse.get_pressed()

    if lb and x==0 and y==0:
        sys.exit()

    #print dx, dy, lb
    
    if dx<0:
        ser.write("6\n")
        print "dx-"
    
    if dx>0:
        ser.write("5\n")
        print "dx+"
    
    if dy>0:
        ser.write("8\n")
        print "dy-"
    
    if dy<0:
        ser.write("7\n")
        print "dy+"

    if lb and lb != lbo:
        ser.write("1\n")
        print "lb+"
    else:
        if lb != lbo:
            ser.write("2\n")
            print "lb-"

    if rb and rb != rbo:
        ser.write("3\n")
        print "rb+"
    else:
        if rb != rbo:
            ser.write("4\n")
            print "rb-"
    
    screen.fill((0,0,0))
    pygame.display.flip()
