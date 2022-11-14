#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
stack<char> leftstack;
stack<char> rightstack;

void Print(stack<char> x)
{
    stack<char>printstack;
    while(!x.empty())
    {
        printstack.push(x.top());
        
        x.pop();
    }
    cout<<"Current stack: ";
    while(!printstack.empty())
    {
        cout<<printstack.top();
        printstack.pop();

    }

}
void examineTop()
{
    if (leftstack.empty())
    {
        cout << "left stack:empty \t";
    }
    else
    {
        cout << "leftstack :" << leftstack.top() << "," << leftstack.size() << "\t \t";
        Print(leftstack);
        cout<<endl;
    }
    if (rightstack.empty())
    {
        cout << "right stack:empty \n";
    }
    else
    {
        cout << "right stack: " << rightstack.top() << ',' << rightstack.size() << "\t \t";
        Print(rightstack);
        cout<<endl;
        
        
    }
}

void insertcharacter(char character)
{
    leftstack.push(character);
}
void insertword(char word[])
{
    int i = 0;
    while (word[i] != '\0')
    {
        insertcharacter(word[i]);
        i++;
    }
}
bool delcharacter()
{
    if (rightstack.empty())
    {

        return false;
    }
    else
    {
        rightstack.pop();
        
        return true;
    }
}
bool backspacecharacter()
{
    if (leftstack.empty())
    {
        return false;
    }
    else
    {
        leftstack.pop();
        return true;
    }
}
void moveleft(int position)
{
    int leftsize ;
    leftsize= leftstack.size();
    while (position != leftsize)
    {
        rightstack.push(leftstack.top());
        leftstack.pop();
        leftsize = leftstack.size();
    }
}
void moveright(int count)
{
    int rightsize, i = 1;
    rightsize = rightstack.size();
    if (count > rightsize)
    {
        cout << "cannot move cursor to the specified position" << endl;
    }
    else
    {
        while (i <= count)
        {
            leftstack.push(rightstack.top());
            rightstack.pop();
            i++;
        }
    }
}
void moveCursor(int position)
{
    int leftsize, rightsize, count;
    leftsize = leftstack.size();
    rightsize = rightstack.size();
    // Data|Structures;leftsize=4;rightsize=10;
    //position=2

    if (position < leftsize)
    {
        moveleft(position);
    }
    //position=7
    else
    {
        count = position - leftsize;//7-4=3
        moveright(count);
    }
}
void find_replace(char find_what, char replace_with)
{
    if(rightstack.empty() && leftstack.empty())
    {
        cout<<"Nothing in the editor to replace"<<endl;
    }
    int count = 1, original_cursor = leftstack.size();
    bool found=false;
    
    moveCursor(0); // cursor goes at beginning
    while (!rightstack.empty())
    {
        if (rightstack.top() == find_what)
        {
            found=true;
            cout << "Replacing occurence of  " << find_what << "  with " << replace_with << endl;
            delcharacter();
            insertcharacter(replace_with);
        }
        else
        {
            moveCursor(count);
            count++;
        }
    }
    if(!found)
    {
        cout<<"Character not found "<<endl;
    }
    
    moveCursor(original_cursor);
}
void options()
{
    cout<<endl;
    cout << "1.Insert Word" << endl;
    cout << "2.Delete Using DEL" << endl;
    cout << "3.DELETE Using BackSpace" << endl;
    cout << "4.MoveCursor" << endl;
    cout << "5.Find And Replace" << endl;
    cout << "6.Exit" << endl;
}
int main()
{
    int ch, position, n;
    char text[80], find, replace;
    
    
    do
    {
        options();
        cout << "Enter Your choice" << endl;
        cin >> ch;
        
        switch (ch)
        {
        case 1:
        {
            cout << "Enter Word to be inserted" << endl;
            cin>>text;
            insertword(text);
            cout << "Current state :   ";
            examineTop();
            break;
        }
        case 2:
        {
            cout << "Enter How many character you want to delete" << endl;
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                if (!delcharacter())
                {
                    cout << "Nothing to Delete,move your cursor accordingly" << endl;
                }
                else
                {
                    cout << "deleting character using DEL : ";

                    examineTop();
                    cout<<endl;
                }
            }
            break;
        }
        case 3:
        {
            cout << "Enter How many character you want to delete" << endl;
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                if (!backspacecharacter())
                {
                    cout << "Nothing to Delete,move your cursor accordingly" << endl;
                }
                else
                {
                    cout << "deleting character using BACKSPACE";

                    examineTop();
                    cout<<endl;
                }
            }
            break;
        }
        case 4:
        {
            cout << "Enter position to move to: " << endl;
            cin >> position;
            cout << "Moving cursor to position " << position << endl;
            moveCursor(position);
            examineTop();
            cout<<endl;
            break;
        }
        case 5:
        {
            cout << "Enter character to find : ";
            cin >> find;
            cout << "Enter character to replace with : ";
            cin >> replace;
            find_replace(find, replace);
            
            examineTop();
            break;
        }
        case 6:
        {
            cout << "Exit" << endl;
            break;
        }
        default:
        {
            cout << "invalid choice" << endl;
        }
        }

    } while (ch != 6);
}