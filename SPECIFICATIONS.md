The specifications outlines the project design specifications and project management plan. This is done BEFORE CODING!
#UML Class Diagrams showing classes, member variables, member functions, and relationships between classes.


#User Interface design showing menus and output expected.
* First, the user will be asked to pick a key and a length of the phrase.  
* The user will then be presented a list of the different species or styles of counterpoints that can be genereated and asked to select one of them
* The program will then output a line of counterpoint of the selected species for the given line of input
* If the user wants to add another phrase to the song, then they can go through the process again, until they feel done.
* Then the program will output a .ly file, which the user can open in a LilyPond editor. 
* It would be awesome if we could make it read in sheet music even if that part depends upon a third party program, but this may still be too ambitious. It would also be great if we can let the user write their base melody. 
* Optionally if time allows and we figure out a way to do it, we may have the program print out sheet music and or present the option to play the original music, the counterpoint, or both of those togeather

#Anticipated challenges and how you will you address them.
* It will probably be a challenge to figure out how we can read in music files, we could make it require each note and duration of each note explicitly written out following some defined outline format, or we might be able to make use of another program that would be able to translate sheet music into the information we need.
* Obiviously the actual counterpoint generation will involve a number of challenges as well, coding rules and a framwork for the computer to understand the rules. 
* It will also be a challenge to output a file with the created counterpoint file.

#Project Management Plan

    >Name individual group member tasks/responsibilities. Split up the tasks and implementation into portions for each group member.
        * Eliott Claus - will focus more on the functions involving more of the indepth music theory
        * Caleb Nelson - will focus more on the other code, like reading in files, writing music files at the end, counting half steps etc.

    >Timeline of individual and group delivery dates.
    This is quite rough here, becuase we will obviously be working together on most things probably quite a bit - Most noteable Caleb will be helping with the coding etc for the counterpoint generation stuff as well, so its not just Eliott
        * Caleb Nelson - music output (writing and or playing the generated counterpoint) - March 1
        * Caleb Nelson - music input - March 8
        * Eliott Claus - counterpoint generation for first species - March 1
        * Eliott Claus - counterpoint generation for second species - March 8
        * Eliott Claus - counterpoint generation for fourth species - March 15