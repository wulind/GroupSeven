# The Great Escape (Group 7)
**Summary:** The puzzle game centers around a group of thieves stealing from different locations, trying to get the art from the your location to their getaway vehicle.

Build a route from your location and collect special abilities on the way to help ward off the officials. Steal from all locations to become the greatest band of thieves alive!

## About
**Team Lead:** Linda Wu

**Group Members:** Michael Darr, Alex Day, Zach Greenfield

**Genre:** Puzzle

**Platform:** Windows, Max OS, Linux

## Compiling
The Great Escape utilizes SFML and Box2D. While Box2D is provided, SFML is not. Make sure you download it before you compile. A cmake CMakeLists.txt is included to help you.

SFML: https://www.sfml-dev.org/download.php

## How To Play
The Great Escape is a physics-based puzzle game that requires the player to figure out a solution to get the stolen object from its original location into the getaway vehicle.

**Gameplay**

![title](/data/ReadMeGuide/TitleScreen.png)

Click play to go to level select screen.

![levelselect](/data/ReadMeGuide/LevelSelect.png)

Click on the glowing orb to select the level that you'd like to play. While levels are not numbered like a traditional level selection page, previous levels that the player has passed will dim to an orange color. The next level unlocked is always a bright yellow color.

![levelone](/data/ReadMeGuide/LevelOneSetup.png)

Click and drag a platform from the platform bank on the right to the desired location. You can use as many or as little of the platforms that you think you need to complete the level. Click play to lock in the platform locations and test your solution. Once you click play, you cannot change your platform's locations.

![levelone](/data/ReadMeGuide/LevelOnePlay.png)

If your solution is successful in getting the stolen object into the getaway van without losing all of the object's durability, then you have successfully compelted the level. The next level will not unlock until you have completed the previous level.

## More Information
For more information about The Great Escape, please refer to our design document [here](https://docs.google.com/document/d/1-G_kxFBZOB9qA2d1C6jzQYF8fPCAyNPuF-_koAcvBis/edit?usp=sharing).
