# Pong 2 (3DS Edition) - Ver. 1.1.0
A Nintendo 3DS Homebrew version of the Fairchild Channel F video game "Hockey".

"Hockey" is a clone of the classic game "Pong" which uses the typical main paddle and introduces a second paddle that acts like a goalie. The main paddle has some unique mechanics in "Hockey" which include 2D movement (rather than just one-axis movement) and center-pivot rotation.

This game is a variation of the original game from the Fairchild Channel F for the Nintendo 3DS, modified so that local online multiplayer is possible. There is no game engine involved, and only C programming is used (for the most part).

This game is open-source, so if you wanted to modify the game in some way (i.e change the colors of the assets, add a background image, etc.), that is perfectly fine.
NOTE: You will need devKitPro, any text-editting software, and either a modded 3DS (Not recommended for testing software) OR a 3DS emulator (recommended when testing).

# Q&A
# Why Though?
The purpose of this project was so that I can introduce myself to the general idea of game development without using a game engine.

# Is it available yet?
At the moment, the game is still a work-in-progress, and it requires a lot of development before the game is fully complete.

# Who are You?
As of the creation of this repository, I am a first-year CS Major at the University of North Carolina at Charlotte with the status of junior. I am planning on having a concentration in Cyber Security.

# How can I play?
To play Channel Fun 'Hockey', you will need to get an original 3DS or newer with CFW (Custom Firmware) OR a 3DS emulator (not recommended for multiplayer). From there, download the .3dsx file above. Depending on whether you use a 3DS with custom firmware (CFW) or the Citra emulator:
 - Citra emulator: Click File > Load File > Find and click your ChF-Hockey.3dsx file > Open.
      - You may see some errors in the citra-qt console depending on the version you use, but you should be able to ignore these.   
 - 3DS w/ CFW (if you don't have a 3DS with custom firmware, visit the 3DS Hacks Guide website):
      - Place ChF-Hockey.3dsx into your sdmc:/3ds/ folder
      - Turn on your modded 3DS with the SD card inside.
      - Open Homebrew Launcher and open the /3ds/ folder.
      - Press A when you are on the ChF-Hockey.3dsx file.
      - The game will automatically start.

# What Tools did you use?
VSCode, devkitPro, Citra Nightly, and GitHub Desktop. Also, ChatGPT helped explain certain things.

# Where's Singleplayer mode?
Singleplayer will automatically load up, just press B to unpause the game and start playing!

# Where's Multiplayer mode?
Multiplayer mode is still a WIP.

As of the most recent commit, I plan to include two services for multiplayer. There will be either an online or a local multiplayer service and what I call the MIR service. MIR (Multiplayer Infrared) has two modes, Host (MIR-H, pronounced Murray) and Client (MIR-C, pronounced Mercy), and is center around using the IR sensor.
