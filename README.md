# 🚀 Welcome to Project & Portfolio!

# Project & Portfolio 1

### Student First & Last Name

Hello my name is Jose Ruiz. I am a student from Chicago, Illinois. The purpose of this repository is to practice development using version control. This work will help me begin to build a portfolio of skills and accomplishment that can be shared in the future.

<br>

## 📢 &nbsp; Weekly Stand Up

Each week I will summarize my milestone activity and progress by writing a stand-up. A stand-up is meant to be a succinct update on how things are going. Use these prompts as a guide on what to write about:

⚙️ Overview - What I worked on this past week
<br>
🌵 Challenges - What problems did I have & how I'm addressing them
<br>
🏆 Accomplishments - What is something I "leveled up" on this week
<br>
🔮 Next Steps - What I plan to prioritize and do next

<br>

### Week 1

⚙️ Overview - What I worked on this past week creating a player and monster classes to make sure they can have variables such as names money type of character/monster and hp. I also worked on making a proper main menu and making sure that it could have proper user input such as being able to exit the program and at least go to settings.
<br>
🌵 Challenges - Trying to figure out which methods go on to which class but I'm addressing that problem by going through the code line by line and saying out loud to figure out the function of the code and to see if it belongs in that class. I also had the challenge of trying to implement the player and monster files into the menu but I will address that problem by planning out how to start the game and at least be able to use those classes by next week.
<br>
🏆 Accomplishments - I managed to write more meaningful comments in my commits as well to plan out more than I usually do. And being able to debug and figure out the problems with my code by going and saying each line out loud and trying to make sense of it, without any help whatsoever. 
<br>
🔮 Next Steps - Try to implement the player Class into the game when the user presses new game and maybe try to create a save file for the user to be able to save his progress. As well to create a proper settings menu and being and being able to go from settings back to main menu. Something I do want to add if I get the chance is to add comments to my code so I don't get lost on what I'm typing and helps me understand better on what im writing.

### Week 2

**⚙️ Overview**  
This week I finished the Explore feature  and added the Intro/Title card to the menu , building on top of the Player, Monster, and Main Menu classes from last week. The game now has a working intro/title sequence and an Explore option that actually does something instead of being an empty menu stub.

**🌵 Challenges**  
Some challenges I had was was the random event logic to trigger correctly, as well as structuring the Explore option so it could hook into the monster class later. I addressed it by breaking the feature into smaller sub-task and testing each event branch individually before combine it.

**🏆 Accomplishments**  
Getting the Explore feature fully working was the big level-up this week — it's the first system that ties together multiple classes (Player state, random events, and setting up for combat) instead of just being isolated menu screens.

**🔮 Next Steps**  
Before Week 3, I'm prioritizing:

- Creating a method to generate a "Random Monster" (#8)
- Building out the actual battle system (#9)
- Finishing the remaining random events (#11)
- Adding music and slow-scroll dialogue text (#10), lower priority in the Backlog


### Week 3

⚙️ Overview - This week I built out the combat system. A full turn-based battle loop with attack, power strike, healing, and monster stat-checking and finished all four random story events, three of which were previously empty stubs. Random encounters now pull from a pool of 5 monsters instead of nothing.
<br>
**🛠️ Improvements**  
Fixed a crash bug where typing a non-numeric character into any menu would throw an unhandled exception; menu input is now validated as digits-only before conversion. Also fixed a display bug in the stats screen where EXP and HP/MP numbers were printing with no separator.
<br>
🌵 Challenges - What problems did I have & how I'm addressing them
<br>
🏆 Accomplishments - Getting a complete combat loop working end-to-end turns, damage formulas, mana costs, win/loss states, and rewards was the biggest level-up this week, since it ties together the Player and Monster classes for the first time instead of them existing independently.
<br>
🔮 Next Steps - Before Week 4, I plan to:

- Reduce duplication between the two menu-display functions in `UI.cpp`
- Clean up `Monster::isAlive()` back to a simpler one-line return
- add a shop and inventory, as well as to add a final boss and an ending


### Week 4

My final stand up...
