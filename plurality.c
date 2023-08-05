#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage.
    // There should be at least 2 candidates
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;

    // Check if user entered more than MAX number of candidates, which is 9 in this case
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    // Populate candidates[MAX].name array with argv entered by user
    // All candidates' votes are set to 0
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // Get user input for the TOTAL number of voters
    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    // Loop each vote and ask for the candidate who was voted for
    // The loop ends when the total number of voter (voter_count) is reached
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO

    /* PSEUDOCODE
    name is taken from the main function
    - check if name matches any of the candidate name in the candidates[MAX] array
        - if matches
            - +1 to candidates[].vote
            - return true
        - if no match
            - return false
    */

    for (int i = 0; i < candidate_count; i++)
    {
        // Use strcmp function as you cannot compare two string directly
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            printf("%i\n", candidates[i].votes);
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO

    // Find the highest number of votes in the candidates array
    int max = candidates[0].votes;
    for (int i = 1; i < candidate_count; i++)
    {
        if (max < candidates[i].votes)
        {
            max = candidates[i].votes;
        }
    }

    // Print candidates with the highest number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}