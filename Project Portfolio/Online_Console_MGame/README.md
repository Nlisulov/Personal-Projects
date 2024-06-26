# Musketeer Game

# Table of contents
1. [Objective](#Objective)
2. [How to play](#How-to-play)

## Objective
Online console game to play the Musketeer game between two players on two different computers.

## How to play
Musketeer Game: 
    The game consists of two types of pieces: Guards and Musketeers.
    The game starts of with the following board overlayed on a coordinate system:

        A B C D E
    1   O O O O X
    2   O O O O O
    3   O O X O O
    4   O O O O O
    5   X O O O O

    Legend:
    X - Musketeer
    O - Guard

    Each coordinate location such as B1, C2, and E5 constitutes a CELL.

    The game starts off with the player playing as the Musketeers making the first move, proceeded by
    the player as the Guards going next.

    Depending on the type of piece the type of moves varies:

    Musketeer: 
        Can move into an adjacent cell, not diagonally, only if there is a guard present thereby
        getting rid of the guard.

    Guard: 
        Can move into an adjacent cell, not diagonally, only if there is an empty cell thereby
        moving the guard from one cell to another.


    The game is over under these two conditions:

        The Musketeers get rid of all the Guards on the board OR the Musketeers having no available 
        moves to continue the game and don't violate the second win condition.

        The Musketeers are all in the same row or column resulting in the Guards winning the game.



