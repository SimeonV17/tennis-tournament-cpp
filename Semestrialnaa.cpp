#include <iostream>
#include <cstring>
using namespace std;

struct Player {
    int tournamentID;
    int worldRanking;
    char firstName[30];
    char lastName[30];
    char country[30];
    int points;
    int titles;
    Player* next;
};

Player* head = nullptr;

const int MAX_PLAYERS = 100;

void addPlayer()
 {
    Player* newPlayer = new Player;
    cout << "Enter tournament ID: "; cin >> newPlayer->tournamentID;
    cout << "Enter world ranking: "; cin >> newPlayer->worldRanking;
    cout << "Enter first name: "; cin >> newPlayer->firstName;
    cout << "Enter last name: "; cin >> newPlayer->lastName;
    cout << "Enter country: "; cin >> newPlayer->country;
    cout << "Enter current points: "; cin >> newPlayer->points;
    cout << "Enter number of titles: "; cin >> newPlayer->titles;
    newPlayer->next = head;
    head = newPlayer;
}

void removePlayer()
{
    int num;
    cout << "Enter tournament number of player to remove: ";
    cin >> num;

    if (!head) {
        cout << "List is empty." << endl;
        return;
    }

    if (head->tournamentID == num) {
        Player* toDelete = head;
        head = head->next;
        delete toDelete;
        cout << "Player removed." << endl;
        return;
    }

    Player* temp = head;
    while (temp->next && temp->next->tournamentID != num)
        temp = temp->next;

    if (temp->next) {
        Player* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    } else {
        cout << "Player not found." << endl;
    }
}

void submenu_1()
{
    int choice;
    cout << endl;
    do {
        cout << " Submenu: " << endl;
        cout << "1. Add\n";
        cout << "2. Remove\n";
        cout << "0. Back to main menu\n";
        cout << "Enter your choice: "; cin >> choice;
        switch (choice) {
            case 1: addPlayer(); break;
            case 2: removePlayer(); break;
        }
    } while (choice != 0);
    cout << endl;
}

void displayPlayers()
 {
    Player* temp = head;
    while (temp) {
        cout << "Tournament ID: " << temp->tournamentID << ", World Ranking: " << temp->worldRanking
             << ", Name: " << temp->firstName << " " << temp->lastName
             << ", Country: " << temp->country << ", Points: " << temp->points
             << ", Titles: " << temp->titles << endl;
        temp = temp->next;
    }
}

int binarySearch(Player* arr[], int x, int low, int high)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid]->titles == x)
        return mid;
    else if (arr[mid]->titles < x)
        return binarySearch(arr, x, mid + 1, high);
    else
        return binarySearch(arr, x, low, mid - 1);
}

void findPlayersWithFewestTrophiess()
 {
    Player* players[MAX_PLAYERS];
    int count = 0;

    Player* temp = head;
    while (temp && count < MAX_PLAYERS)
        {
        players[count++] = temp;
        temp = temp->next;
    }

    if (count == 0) {
        cout << "No players available." << endl;
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < count; j++) {
            if (players[j]->titles < players[minIndex]->titles)
                minIndex = j;
        }
        if (minIndex != i) {
            Player* t = players[i];
            players[i] = players[minIndex];
            players[minIndex] = t;
        }
    }

    cout << "Player with the fewest trophies:\n";
    cout << players[0]->firstName << " " << players[0]->lastName
         << " - " << players[0]->titles << " trophies" << endl;

    int searchTrophies;
    cout << "Enter number of trophies to search: ";
    cin >> searchTrophies;

    int pos = binarySearch(players, searchTrophies, 0, count - 1);
    if (pos == -1)
        {
        cout << "No players found with " << searchTrophies << " trophies." << endl;
        return;
    }

    while (pos > 0 && players[pos - 1]->titles == searchTrophies)
        pos--;

    cout << "Players with " << searchTrophies << " trophies: " << endl;
    for (int i = pos; i < count && players[i]->titles == searchTrophies; i++)
        {
        cout << players[i]->firstName << " " << players[i]->lastName
             << " - " << players[i]->titles << " trophies" << endl;
    }
}


void findPlayersByCountry()
{
    char targetCountry[30];
    cout << "Enter country to search for: ";
    cin >> targetCountry;

    Player* players[MAX_PLAYERS];
    int count = 0;

    Player* temp = head;
    while (temp && count < MAX_PLAYERS) {
        players[count++] = temp;
        temp = temp->next;
    }

    if (count == 0) {
        cout << "No players available." << endl;
        return;
    }

    for (int i = 0; i < count - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < count; j++) {
            if (strcmp(players[j]->country, players[minIndex]->country) < 0)
                minIndex = j;
        }
        if (minIndex != i) {
            Player* t = players[i];
            players[i] = players[minIndex];
            players[minIndex] = t;
        }
    }

    int low = 0, high = count - 1;
    int pos = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(players[mid]->country, targetCountry);
        if (cmp == 0) {
            pos = mid;
            break;
        } else if (cmp < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (pos == -1) {
        cout << "No players from " << targetCountry << "." << endl;
        return;
    }

    while (pos > 0 && strcmp(players[pos - 1]->country, targetCountry) == 0)
        pos--;

    cout << "Players from " << targetCountry << ":" << endl;
    for (int i = pos; i < count && strcmp(players[i]->country, targetCountry) == 0; i++) {
        cout << players[i]->firstName << " " << players[i]->lastName
             << " (" << players[i]->country << "), Titles: " << players[i]->titles << endl;
    }
}


void submenu_2()
{
    int choice;
    cout << endl;
    do {
        cout << " Submenu: " << endl;
        cout << "1. Searchy by min trophies\n";
        cout << "2. Search by country\n";
        cout << "0. Back to main menu\n";
        cout << "Enter your choice: "; cin >> choice;
        switch (choice)
         {
            case 1: findPlayersWithFewestTrophiess();
            break;
            case 2:
            findPlayersByCountry();
            break;
        }
    } while (choice != 0);
    cout << endl;
}


void gnomeSort(Player* arr[], int n)
 {
    int index = 0;
    while (index < n) {
        if (index == 0) {
            index++;
        } else if (arr[index]->worldRanking >= arr[index - 1]->worldRanking) {
            index++;
        } else {
            swap(arr[index], arr[index - 1]);
            index--;
        }
    }
}

void bubbleSortLinkedList()
{
    if (!head || !head->next) return;

    bool swapped;
    do {
        swapped = false;
        Player* temp = head;
        while (temp && temp->next) {
            if (temp->worldRanking > temp->next->worldRanking)
                {
                swap(temp->tournamentID, temp->next->tournamentID);
                swap(temp->worldRanking, temp->next->worldRanking);
                swap(temp->firstName, temp->next->firstName);
                swap(temp->lastName, temp->next->lastName);
                swap(temp->country, temp->next->country);
                swap(temp->points, temp->next->points);
                swap(temp->titles, temp->next->titles);
                swapped = true;
            }
            temp = temp->next;
        }
    } while (swapped);
}

void sortByWorldRanking()
{

    if (!head) {
        cout << "No players available." << endl;
        return;
    }

    Player* sortedArr[10];
    int n = 0;
    Player* temp = head;
    while (temp && n < 10)
        {
        sortedArr[n++] = temp;
        temp = temp->next;
    }

    gnomeSort(sortedArr, n);
    cout << endl;
    cout << "Sorted players by World Ranking (for first 10 players):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Tournament ID: " << sortedArr[i]->tournamentID << ", World Ranking: " << sortedArr[i]->worldRanking
             << ", Name: " << sortedArr[i]->firstName << " " << sortedArr[i]->lastName
             << ", Country: " << sortedArr[i]->country << ", Points: " << sortedArr[i]->points
             << ", Titles: " << sortedArr[i]->titles << endl;
    }

    bubbleSortLinkedList();

    cout << "\nLinked list is sorted by World Ranking" << endl;
    cout << endl;
}


void displaySortedByTitles_SS()
{
    Player sorted[100];
    int n = 0;

    for (Player* temp = head; temp && n < 100; temp = temp->next) {
        sorted[n++] = *temp;
    }

    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if ((sorted[j].titles > sorted[maxIndex].titles) ||
                (sorted[j].titles == sorted[maxIndex].titles && sorted[j].worldRanking < sorted[maxIndex].worldRanking)) {
                maxIndex = j;
            }
        }

        swap(sorted[i], sorted[maxIndex]);
    }

    for (int i = 0; i < n; i++) {
        cout << "Tournament ID: " << sorted[i].tournamentID << ", World Ranking: " << sorted[i].worldRanking
             << ", Name: " << sorted[i].firstName << " " << sorted[i].lastName
             << ", Country: " << sorted[i].country << ", Points: " << sorted[i].points
             << ", Titles: " << sorted[i].titles << endl;
    }
}


void searchByCountryAndFirstName()
{
    char country[30], firstName[30];
    cout << "Enter country: "; cin >> country;
    cout << "Enter first name: "; cin >> firstName;
    bool found = false;
    for (Player* temp = head; temp; temp = temp->next) {
        if (strcmp(temp->country, country) == 0 && strcmp(temp->firstName, firstName) == 0) {
            cout << "Tournament ID: " << temp->tournamentID << ", World Ranking: " << temp->worldRanking
                 << ", Name: " << temp->firstName << " " << temp->lastName
                 << ", Country: " << temp->country << ", Points: " << temp->points
                 << ", Titles: " << temp->titles << endl;
            found = true;
        }
    }
    if (!found) cout << "No player found with the given country and first name.\n";
}

void submenu_3()
{
    int choice;
    cout << endl;
    do {
        cout << " Submenu: " << endl;
        cout << "1. Display players sorted by titles\n";
        cout << "2. Search by country and first name\n";
        cout << "0. Back to main menu\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1: displaySortedByTitles_SS();
            break;
            case 2: searchByCountryAndFirstName();
            break;
        }
    } while (choice != 0);
    cout << endl;
}



int main()
{
    int choice;
    do {
        cout << " Main Menu: " <<endl;
        cout << "1. Add/Remove player\n";
        cout << "2. Display all players\n";
        cout << "3. Search\n";
        cout << "4. Sorting\n";
        cout << "5. Submenu\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: "; cin >> choice;
        switch (choice) {
            case 1: submenu_1();
            break;
            case 2: displayPlayers();
            break;
            case 3: submenu_2();
            break;
            case 4: sortByWorldRanking();
            break;
            case 5: submenu_3();
            break;
        }
    } while (choice != 0);
    return 0;
}

