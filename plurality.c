#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
//Declaring identifiers.
int max = 9;
int NumberOfVotes = 0;
int candidate_count;
int i = 0;
//Creating struct to connect the names of the candidates to their votes.
typedef struct
{
    string name;
    int votes;
}
candidate;
//Declaring an array of type candidate by which we connect each vote to its candidate and vice versa.
candidate candidates[9];

bool vote(string name);
void print_winner(void);
//The main function
int main(int argc, string argv[])
{
    candidate_count = argc - 1;
//Informing the user of the mistaked that he does while inputting values
    if (argc < 2)
    {
        printf("please enter at least 2 candidates\n");
        return 1;
    }
    else if (argc > 10)
    {
        printf("The Maximum number of candidates is 9\n");
        return 2;
    }
    //Declaring number of votes.
    NumberOfVotes = get_int("Number Of Votes: ");
    
    for (int z = 0 ; z < NumberOfVotes ; z++)
    {
        string name = get_string("Vote: ");
        if (!vote(name))
        {
            printf("invalid vote\n");
        }
    }
//Printing the winner's name out.
    print_winner();
}

bool vote(string name)
{
// Checking if the entered vote corresponds to an argv element or not.    
    for (i = 0 ; i < candidate_count ; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}
//The function that checks for the biggest number of votes which a candidate can have.
void print_winner(void)
{
    for (int k = 0 ; k < candidate_count ; k++)
    {
        if (candidates[0].votes < candidates[k].votes)
        {
            candidates[0].votes = candidates[k].votes;
            candidates[0].name = candidates[k].name;
            break;
        }
    }
    
    for (int k = 0 ; k < candidate_count ; k++)
    {
        if (candidates[1].votes < candidates[k].votes)
        {
            candidates[1].votes = candidates[k].votes;
            candidates[1].name = candidates[k].name;
            break;
        }
    }
    
    for (int k = 0 ; k < candidate_count ; k++)
    {
        if (candidates[2].votes < candidates[k].votes)
        {
            candidates[2].votes = candidates[k].votes;
            candidates[2].name = candidates[k].name;
            break;
        }
    }
    
    for (int k = 0 ; k < candidate_count ; k++)
    {
        if (candidates[3].votes < candidates[k].votes)
        {
            candidates[3].votes = candidates[k].votes;
            candidates[3].name = candidates[k].name;
            break;
        }
    }
    
    for (int k = 0 ; k < candidate_count ; k++)
    {
        if (candidates[4].votes < candidates[k].votes)
        {
            candidates[4].votes = candidates[k].votes;
            candidates[4].name = candidates[k].name;
            break;
        }
    }
//Printing each winner candidate name.
    printf("%s\n%s\n%s\n%s\n%s\n", candidates[0].name, candidates[1].name, candidates[2].name, candidates[3].name, candidates[4].name);
}







