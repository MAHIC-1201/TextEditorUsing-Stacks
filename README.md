# TextEditorUsing-Stacks
This project consists of a simple and novel way by which we have implemented a text editor application using a 2 Stack Model.
<img width="390" alt="image" src="https://user-images.githubusercontent.com/98683515/201733503-87a12bcd-c0a4-4464-87b7-36ae8ac9fdb0.png">


SOME BASIC POINTS FOR UNDERSTANDING OF THE CODE:

1.)Here we consider that the cursor acts as a divider between the left side and the right side portions of a word.
   For eg.)in the word Data|Structures ;cursor acts as a divider between 'Data' and 'Structures'.
   We consider elements on left side of the cursor to be pushed onto the left stack and elements on right of the cursor to be pushed onto the right    stack.
   
2.)Whenever we write an character it is pushed to the left side of the cursor.
   For eg.)DataStructures|
   
3.)Elements to the left on the cursor are pushed onto the left stack 
   For eg .)DataStructures|
   Leftstack:DataStructures
   Rightstack:empty
   
4.)Whenever we delete an element using DEL key ,the character on the RIGHT side of the cursor gets deleted.
   For eg.)Data|Structures-->DELKEY-->Data|tructures
 
5.)Whenever we delete an element using BACKSPACE key ,the character on the LEFT side of the cursor gets deleted.
   For eg.)Data|Structures-->Backspace-->Dat|Structures
   
6.)Whenever we move our cursor towards left,we pop an element from leftstack and push it onto the right stack.
   For eg.)Data|Structures
   LeftStack:Data
   RightStack:serutcurtS
   
   -->|DataStructures
   LeftStack:empty
   RightStack:serutcurtSataD
   
7.)Whenever we move our cursor towards right,we pop an element from rightstack and push it onto the left stack.
   For eg.)Data|Structures
   LeftStack:Data
   RightStack:serutcurtS
   
   -->DataStru|ctures
   LeftStack:DataStru
   RightStack:serutc
   
   
   
   
   


