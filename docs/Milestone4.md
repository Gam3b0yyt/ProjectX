# Milestone 4 Changelog (Final)

## Final Features Added

- **Shop system**: implemented `Shop` class with a stock of potions, weapons, and armor. Weapons and armor apply their stat bonuses immediately on purchase; consumables are added to a new inventory system and can be used on the spot or saved.
- **Inventory system**: `Player` now tracks a `std::vector<InventorySlot>` with `addItem()`, `removeItem()`, and `hasItem()`, replacing the earlier stubbed-out "Use Item" combat option.
- **Save / Load system**: `Player::saveToFile()`/`loadFromFile()` persist the player's name, class, level, experience, stats, and `storyProgress` to a file; wired into `Events::saveGame()`/`loadGame()` from the main menu.
- **Final boss and three distinct endings**: added `finalBoss()`, `finalBossWithTrueEnding()`, and three branching endings (`trueEnding`, `neutralEnding`, `finalEnding`), gated by the player's accumulated `storyProgress` and morale from earlier story choices.
- **Typewriter dialogue effect**: added `UI::typeWriterEffect()` and `messageBoxWithCharacterName()` so dialogue now scrolls character-by-character with an attributed speaker name, instead of printing instantly.
- **Music system**: added an `Audio` class backed by `Tracks.h`, playing distinct themes for the title screen, exploration, each boss, and a randomized rotation of battle themes during combat.

## Refactoring / Improvements

- Consolidated all "used a consumable" logic into `Player`'s inventory methods rather than handling item effects inline inside combat, so both the shop and future features can reuse the same add/remove/has-item logic.
- Player starting stats were rebalanced (attack/defense) and starting morale was changed from 0 to 100, so morale swings from story choices feel meaningful in both directions instead of only ever going positive from a zero floor.

## Bug Fixes

- No new crash-level bugs were found this week; player input validation from Milestone 3 remains in place and unchanged.

## Known Issues / Not Addressed This Week

- **`std::rand()` is never seeded with `srand()`.** This means random monster selection, random story events, shop prices, and crit chance rolls follow the same deterministic sequence on every run of the program. This should be fixed by adding `srand(static_cast<unsigned>(time(nullptr)));` at the start of `main()`.
- The input-validation logic in `UI::DisplayMenuAndPromptUser` and `DisplayMenuAndPromptUserWithoutClearing` is still duplicated between the two functions, as noted in the Milestone 3 changelog. This remains a good candidate for a shared `getValidatedInt()` helper in future development.

## Screenshots

- `images/final-run` — program compiling and running successfully in the console
- `images/final-features` — key features in action (combat, shop, final boss/ending)
