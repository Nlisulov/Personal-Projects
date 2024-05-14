import socket
 
def start_server(): 

    #create a server with a tcp connection
    server_s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    server_s.bind(("127.0.0.1", 51234))

    #accepting only two connections to allow to play the game
    server_s.listen(2)

    """
    Need to do: 
        insert code to accept the two connections to play the game
    """

    #setting the game over condition to false, till victory condition is met.
    game_over = False
    while not game_over:
        set_game_over = input("Would you like to terminate the game (enter Y or N):  ")
        set_game_over = (set_game_over.lower())[0]

        print(f"{set_game_over}\n")

        if set_game_over == "y":
            game_over = True
    
    #Print statement to verify end of function
    print("End of game")




if __name__ == "__main__":
    start_server()
