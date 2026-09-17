> Use this worksheet to plan the next phase of your project **before you begin coding**
> Be clear, specific, and intentional—this will guide your development this week.

---
## 📌 Project Overview

**Project Name:**
→   Project X: RPG
  
**What does your program currently do? (1–3 sentences)**   
→ Project X is a console-based text RPG. The player watches an intro story, creates a character by choosing a name and one of six classes (each with different starting HP/Attack/Defense/Mana), and then navigates a game menu where they can explore, check their stats, or return to the main menu. Exploring can trigger a random narrative event (currently only one is implemented: helping an old lady for gold and morale).

---
## 🔍 Current Progress Check  
  
**What is working right now?**   
→   The intro story sequence, title screen, main menu (New Game / Settings / Exit), full character creation flow with class-based stat assignment, the in-game loop (Explore / Shop / Save / Status / Return to Main Menu), the stats display screen, and one complete random explore event.
  
**What is NOT working or incomplete?**   
→   Shop, Save Game, and Load Game are all empty stubs. The Monster class is fully written (health, attack, defense, damage, experience reward) but is never actually instantiated or used — there's no combat system yet, even though 60% of explore rolls are meant to start a fight. Three of the four random-event cases in explore() are empty. storyProgress and finalBossCheck() are wired up but storyProgress is never incremented anywhere, so the final boss can never trigger.
  
**What feels confusing or messy in your code?**   
→ DisplayMenuAndPromptUser and DisplayMenuAndPromptUserWithoutClearing in UI are almost identical, duplicated code. std::stoi(tempChoice) is called twice in the same function, and it isn't wrapped in a try/catch, so typing a letter instead of a number will crash the program. The EXP line in showStats() also has a formatting bug ("EXP: " << exp << "" << level*100) that prints the numbers jammed together instead of something like "EXP: 0/100".

---
## 🚀 Feature Planning  
  
List the features you plan to add or improve this week.  
  
### Feature 1  
**Name:**   
→   Turn-Based Combat System
  
**What does this feature do?**   
→   Adds a real battle loop that triggers when the explore event roll lands under 60. The player picks a Monster from a small enemy pool, and player and monster take turns attacking (using existing attack/defense/health fields) until one side reaches 0 HP. On a win, the player gains the monster's experienceReward and possibly gold; on a loss, the game handles a "defeat" state instead of crashing.
  
**Why is this feature important?**   
→   Right now the Monster class exists but does nothing — combat is the core gameplay loop that's currently missing entirely, so nothing the player does in "Explore" actually creates risk or progression.
  
---
### Feature 2  
**Name:**   
→   Shop System
  
**What does this feature do?**   
→   Implements the empty Shop menu option so the player can spend the gold they earn (from events and combat) on simple upgrades or consumables — for example, healing items or small stat boosts.
  
**Why is this feature important?**   
→   The game already tracks and rewards money, but there's currently nowhere to spend it, so gold is a dead stat. A shop gives gold a purpose and creates a simple economy loop.
  
---
  
### Feature 3 (optional)  
**Name:**   
→   Save / Load Game
  
**What does this feature do?**   
→   Writes the player's current state (name, class, level, stats, gold, storyProgress) to a simple file on "Save Game," and reads it back on "Load Game" from the main menu.
  
**Why is this feature important?**   
→   Both menu options already exist in the UI but do nothing. Without save/load, every playtest has to restart from the intro each time, which will get in the way of testing the combat and shop systems.
  
---
## 🧩 System Design Updates  
  
**Will you need to create any new classes? If so, which ones?**   
→   A Battle (or Combat) class to hold the turn-based fight logic instead of cramming it into Events, and a small Item class for the shop (name, cost, effect) if time allows.
  
**Will you modify any existing classes? How?**   
→   Events will get new methods (combat(), shop(), saveGame(), loadGame()) and will need to actually increment storyProgress as the player progresses. Monster may need a constructor helper or a static list of preset monsters to pick from during explore events.
  
**What data structures will you use (vectors, 2D vectors, etc.)?**   
→   A `std::vector<Monster>` to hold the pool of possible enemies to randomly select from during combat, and a `std::vector<Item>` for the shop's inventory if the Item class gets built.
  
---
## 🔄 Program Flow  
  
**Describe how a user interacts with your program:**  
  
1. Program starts →   Intro story plays, then Title screen, then Main Menu
2. User chooses →   "New Game," creates a character (name + class), and lands in the Game Menu
3. Program responds →   Explore rolls an event: either combat, a story event, or (soon) nothing happens; Shop lets them spend gold; Status shows their stats
4. Loop/next step →   Player keeps choosing Explore/Shop/Status until they pick "Return to Main Menu," where they can start over, load a save, or exit
  
---
## 🎯 Usability Improvements  
  
How will you make your program easier to use this week?  
  
- Clearer prompts:   
→   Show current HP/gold before combat and shop prompts so the player knows what they're working with before choosing an action.
  
- Better error handling:   
→   Wrap the std::stoi menu input in a if-else statement so typing a non-number doesn't crash the program — just show "Invalid input" and re-prompt.
  
- Improved menu/navigation:   
→   Collapse DisplayMenuAndPromptUser and DisplayMenuAndPromptUserWithoutClearing into one function with a boolean parameter instead of duplicating the whole method.
  
---
## ⚠️ Potential Challenges  
  
**What do you think will be the hardest part this week?**   
→   Balancing the combat math (attack vs. defense vs. health) so fights feel fair across all six classes, since their starting stats are pretty different (Barbarian has 150 HP/20 Attack vs. Sorcerer's 80 HP/12 Attack).
  
**What is your plan if you get stuck?**   
→   Start with the simplest possible combat loop (flat damage, no crits/misses) to get something playable end-to-end, then layer in balance tweaks once it works. Ask in office hours if the turn logic gets tangled.
  
---
  
## 📈 Level Up Goal  
  
**What skill are you focusing on improving this week?**   
→   Reducing code duplication / cleaner class design.
  
**What will you do to improve it?**   
(e.g., tutorial, practice, debugging, office hours)   
→   Refactor the two nearly-identical UI menu functions into one, and pull combat logic into its own class instead of adding it directly into `Events`, to practice separating responsibilities between classes.
  
---
## 🗓️ Task Breakdown (GitHub Issues Planning)  
  
List the tasks you plan to create as GitHub Issues:  
  
- [ ]   Implement turn-based combat loop using the Monster class
- [ ]   Implement Shop menu and basic item purchasing
- [ ]   Add if-else around menu input to prevent crashes on bad input
- [ ]   Implement Save/Load Game to file
  
---
  
## 🔥 Final Check  
  
Before you start coding, ask yourself:  
  
- [x] Do I know what I’m building this week?   
- [x] Do I know where to start?   
- [x] Did I break my work into small tasks?   
  
If yes → start coding 🚀   
If no → refine your plan first   
  
---
## 😈 Final Thought  
  
> Plan it now… or debug it later.