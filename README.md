<h1>cub3D</h1>

<h2>Project Overview</h2>
<p>The <code>cub3D</code> project is inspired by the world-renowned game Wolfenstein 3D, the first FPS game ever created. This project will help you discover the concept of ray-casting. Your goal is to create a dynamic view inside a maze using a first-person perspective.</p>

<h2>Purpose</h2>
<p>The purpose of this project is to write a C program that generates a "realistic" 3D graphical representation of the inside of a maze from a first-person perspective using the ray-casting principle.</p>

<h2>What You Will Learn</h2>
<ul>
    <li>How to use MiniLibX for graphical programming.</li>
    <li>How to implement ray-casting for rendering 3D scenes.</li>
    <li>How to manage window events and user inputs in a graphical application.</li>
    <li>How to work with textures and color manipulation in C.</li>
</ul>

<h2>Project Contents</h2>

<h3>Mandatory Part</h3>
<p>You must implement the following requirements:</p>
<ul>
    <li>Write a program named <code>cub3D</code> that:
        <ul>
            <li>Uses MiniLibX to create a window and display graphics.</li>
            <li>Displays different wall textures based on the direction (North, South, East, West).</li>
            <li>Allows setting floor and ceiling colors to different values.</li>
            <li>Handles window events smoothly (e.g., switching focus, minimizing).</li>
            <li>Allows the player to look left and right using the left and right arrow keys.</li>
            <li>Allows the player to move forward, backward, left, and right using the W, A, S, and D keys.</li>
            <li>Closes the window and exits the program cleanly when the ESC key is pressed or the window's close button is clicked.</li>
        </ul>
    </li>
    <li>Program should take a map file with a .cub extension as the first argument.
        <ul>
            <li>The map should consist of 6 possible characters: '0' for empty spaces, '1' for walls, and 'N', 'S', 'E', or 'W' for the player's starting position and direction.</li>
            <li>The map must be closed or surrounded by walls, otherwise the program should output an error and exit cleanly.</li>
            <li>The map file should contain texture paths and color information in the following format:
                <pre>
NO ./path_to_the_north_texture
SO ./path_to_the_south_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
F 220,100,0
C 225,30,0
1111111111111111111111111
1000000000110000000000001
1011000001110000000000001
1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
                </pre>
            </li>
        </ul>
    </li>
    <li>If the map contains any misconfigurations, the program should exit cleanly and output an error message.</li>
</ul>

<h3>Bonus Part</h3>
<p>The bonus part includes additional features:</p>
<ul>
    <li>Implement wall collisions.</li>
    <li>Add a mini-map system.</li>
    <li>Implement doors that can open and close.</li>
    <li>Add animated sprites.</li>
    <li>Allow changing the view angle using the mouse.</li>
</ul>
<p>The bonus part will only be assessed if the mandatory part is perfect.</p>

<h2>Usage</h2>
<p>To use the <code>cub3D</code> program, compile it using the provided Makefile and run it with a valid .cub map file as an argument. The program will display a 3D representation of the maze in a window and allow the player to navigate through it.</p>

<h2>Conclusion</h2>
<p>The <code>cub3D</code> project is an excellent opportunity to learn about graphical programming, ray-casting, and 3D rendering techniques in C. By completing this project, you will gain valuable skills in creating interactive graphical applications and understanding the principles behind 3D graphics.</p>
