#include <string>
#include <iostream>
#include <ctime>
using namespace std;

void PrintIntroduction(int Difficulty)
{
    cout << "You forgot the pass code to access your "<<6 - Difficulty<<" water bottle(s)!"<<endl;
    cout<<"You need to enter the correct 3 digit permutation(s) to quench your thirst!"<<endl;
    cout<<"The level difficulty is: "<<Difficulty<<endl;
}

bool PlayGame(int Difficulty)
{
    /*
    Expression statements have semicolons at the end
    Declaration statements is code that declares a variable
    Variables can be fixed by using const
    */
    int Alpha, Beta, Gamma;
    PrintIntroduction(Difficulty);
    if(Difficulty == 1)
    {
        Alpha = rand()%3 +1, Beta = rand()%3 +1, Gamma = rand()%3 +1;
    }
    else if(Difficulty == 2)
    {
        Alpha = rand()%5 +1, Beta = rand()%5 +1, Gamma = rand()%5 +1;
    }
    else if(Difficulty == 3)
    {
        Alpha = rand()%7 +1, Beta = rand()%7 +1, Gamma = rand()%7 +1;
    }
    else if(Difficulty == 4)
    {
        Alpha = rand()%9 +1, Beta = rand()%9 +1, Gamma = rand()%9 +1;
    }
    else
    {
        Alpha = rand()%11 +1, Beta = rand()%11 +1, Gamma = rand()%11 +1;
    }
    
   
    int Sum = Alpha + Beta + Gamma;
    int Product = Alpha*Beta*Gamma;
    
    cout<<""<<endl;
    cout<< "For some reason you remember that the sum of the digits in the code is: "<<Sum<<endl;
    cout<<"From memory you also remember that the product of these digits is: "<<Product<<endl;

    int GuessA, GuessB, GuessC;
    cin>>GuessA>>GuessB>>GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA*GuessB*GuessC;

    if(GuessSum == Sum && GuessProduct == Product)
        {
            cout<<"Good job, you have entered the correct numbers!"<<endl;
            return true;
        }
    else
        {
            cout<<"Unfortunately you were incorrect.\n";
            cout<<"The correct combination was: "<<Alpha<<Beta<<Gamma<<endl;
            cout<<"Quick hide! The police are coming!"<<endl;
            return false;  
        }
         
}

int main()
{
    cout<<"Welcome to the triple unknown guessing game, you are tasked with guessing three numbers that give a particular sum & product!"<<endl;
    srand(time(NULL));
    char Play = 'y';
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5; 

    while (LevelDifficulty <= MaxDifficulty)
    {
        //std::cout<<rand()%10 +1<<std::endl;
        bool blevelcomplete = PlayGame(LevelDifficulty);
        cin.clear();
        cin.ignore();
        if (blevelcomplete)
        {
            ++LevelDifficulty;
        }
        else
        {
            break;
            
        }
    }
    if (LevelDifficulty == 6)
    {
        cout<<"Congratulations you have successfully collected all five water bottles!";
    }
    else
    {
        cout<<"Better luck next time traveller!";
    }
    
    return 0; 
}