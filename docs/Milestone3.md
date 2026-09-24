# Milestone 3 Changelog

## Features Added

- **Turn-based battle system**: implemented `battle()` for random wandering encounters and a separate `battleEvent()` for story-driven boss fights. Each turn, the player chooses from Attack, Power Strike (costs 15 MP for double damage), Heal (costs 10 MP), Check Monster Stats, or Use Item.
- **Random monster generation**: `createRandomMonster()` picks from a pool of 5 preset monsters (Forest Slime, Goblin, Dark Plant, Fire Elemental, Fallen Celestial) instead of always fighting the same enemy.
- **Completed all four random story events**: previously only the "help the old lady" event was written; the wolf-in-a-trap, corrupted grove guardian, and ember shrine encounters were empty stubs. All four now have real choices, consequences (morale, gold, stat changes, `storyProgress`), and can escalate into a full battle depending on the player's choice.
- **Level-up system**: `Player::levelUP()` increases max HP/MP, attack, and defense when the player crosses the experience threshold, and fully restores the player on level-up.
- **Crit chance**: both player and monster attacks have a chance (1 in 100 roll) to land a critical hit for double damage.

## System Design Updates

- `Player` now tracks `maxHealth` and `maxMana` separately from current `health`/`mana`, enabling proper "current/max" stat display and a `fullRestore()` helper used after leveling up or waking up from a defeat.
- Added `Player::isAlive()`, `spendMana()`, and `heal()` to centralize state checks and mana/HP changes instead of manipulating the raw fields directly from `Events`.
- `storyProgress` is now actually incremented and decremented by story events instead of being declared but never touched, which is what will eventually allow the final boss check to trigger correctly.
- Split combat into two entry points — `battle()` for regular explore encounters and `battleEvent()` for story-driven fights — since story fights need to affect `storyProgress` and regular ones don't.

## Refactoring / Improvements

- **Fixed a crash bug in menu input**: `UI::DisplayMenuAndPromptUser` and `DisplayMenuAndPromptUserWithoutClearing` previously called `std::stoi()` directly on user input, which threw an uncaught exception (crashing the program) if the player typed a letter instead of a number. Both functions now check that the input is all digits before converting it, and treat anything else as an invalid choice that gets re-prompted.
- **Fixed the stats display formatting bug**: `showStats()` was printing EXP and level-up threshold with no separator (e.g. "050"); it now prints "EXP / needed" and "HP: current/max" clearly.

### Known tech debt (not yet addressed)
- The input-validation logic added to `UI.cpp` this week is duplicated across both `DisplayMenuAndPromptUser` and `DisplayMenuAndPromptUserWithoutClearing`. These two functions are still nearly identical overall and are a strong candidate for merging into one function with a boolean "clear screen" parameter in a future milestone.
- `Monster::isAlive()` was changed from a single-line return into a longer if/else that behaves identically — this should probably be reverted for clarity.
