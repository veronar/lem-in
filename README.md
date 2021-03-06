# **Lem-in**
WeThinkCode_ Module  
Alogrithms - Project 2 (Group)  
This project is meant to make you code an ant farm manager

#### Group Members
- [Alistair Norman](https://github.com/anormanwtc)  
- [Vaughn Scott](https://github.com/VR-Scott)  
- [Bongani Nkosi](https://github.com/Salsa-socks)  

### **Description**

Some students of the School of Wizardry have created Hex, a thinking machine. It is composed of ants for calculus, bee-hives and bees for memory and a mouse for (.. Huh, right, what for already?) cheese (to feed the mouse) and a feather for writing.  
We are going to look in depth at its calculus bit. How does it work? Simple! We make an ant farm, with tunnels and rooms; we place the ants on one side; and we look at how they find the exit.  
How do we build an ant farm? We need tubes and rooms  
We join the rooms to one another with as many tubes as we need. A tube joins two rooms to each other. No more than that. A room can be linked to an infinite number of rooms and by as many tubes as deemed necessary. Then we must bury the ant farm (wherever you want). This is extremely important to ensure that ants don’t cheat and look at your design before before the game starts.  
Because arts and crafts with boxes, tape and ropes are not our greatest strength, we will create a digital version instead.  
The goal of this project is to create an “Hex” simulator.  

## **Objectives**
The program will receive the data describing the ant farm from the standard output in the following format:
```
number_of_ants
the_rooms
the_links
```
The ant farm is defined by the links in the following format:
```
##start 1 23 3
2 16 7 #comment 3 16 3
4 16 5 593 615
748 ##end 095 0-4 0-6
1-3
4-3
5-2
3-5
#another comment
4-2
2-1
7-6
7-2
7-4
6-5
#another comment
```

There are two parts
- The rooms, which are defined by: name coord_x coord_y
- The links, which are defined by: name1-name2
- All of it is broken by comments, which start with #
- Lines that start with ## are commands modifying the properties of the line that comes right after.
- For example, ##start signals the ant farm’s entrance and ##end its exit.
- Any non compliant or empty lines will automatically stop the ant farm’s reading as well as the orderly processing of the acquired data.
- If there isn’t enough data to process normally you must display ERROR

Also to consider:
- The rooms’ names won’t necessarily be numbers, and they won’t necessarily be in the right and continuous order (we will find rooms with names such as zdfg, qwerty, etc...)  But most importantly, a room will never start with the character L nor the character # 
- The rooms’ coordinates will always be integers.
- Any unknown command will be ignored.

Allowed functions:
- malloc
- free
- read
- write
- strerror
- perror
- exit

## **Mandatory**

- The goal of this project is to find the quickest way to get `n` ants across the farm. Quickest way means the solution with the least number of lines, respecting the output format requested.
Ants will need to take the shortest path (and that isn’t necessarily the simplest). They will also need to avoid traffic jams as well as walking all over their fellow ants.
- At the beginning of the game, all the ants are in the room `##start`. The goal is
to bring them to the room `##end` with as few turns as possible. Each room can
only contain one ant at a time. (except at ##start and ##end which can contain
as many ants as necessary.)
- We consider that all the ants are in the room `##start` at the beginning of the game.
- At each turn you will only display the ants that moved.
- At each turn you can move each ant only once and through a tube (the room at
the receiving end must be empty).
- You must to display your results on the standard output in the following format:
```
number_of_ants
the_rooms
the_links
Lx-y Lz-w Lr-o ...
```
x, z, r represents the ants’ numbers (going from 1 to number_of_ants) and y,
w, o represents the rooms’ names.

Example 1 :
`[0]-[2]-[3]-[1]`
```
zaz@blackjack /tmp/lem-in $ ./lem-in < subject.map
3
##start
0 1 0
##end
1 5 0
2 9 0
3 13 0
0-2
2-3
3-1
L1-2
L1-3 L2-2
L1-1 L2-3 L3-2
L2-1 L3-3
L3-1
zaz@blackjack /tmp/lem-in $
```

