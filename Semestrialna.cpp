#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

const int MAX=100;

struct People
{
 short tournament_number;
 short world_number;
 char name[30];
 char family[30];
 char country[30];
 short curr_points;
 short first_place;
};

void add(People data[],int &br)
 {
    int n;
     do {
        cout<<"Enter the number of players: ";
        cin>>n;

        if (n<=0)
        {
            cout<<"Invalid input! The number of players must be a positive integer"<<endl;
        }

    } while (n<=0);

    if(n+br>MAX)
    {
    cout<<"Cannot add "<<n<<" players. "<<"Maximum players to add is "<< MAX-br<<endl;
    return;
    }
    cout<<endl;
    for (int i = br; i < n+br; i++)
     {
        do {
            cout<<"Tournament number (1 to 100): ";
            cin>>data[i].tournament_number;
            if (data[i].tournament_number < 1 || data[i].tournament_number > 100)
                {
                cout<<"Invalid tournament number! Please enter a number between 1 and 100"<<endl;
            }
        } while (data[i].tournament_number < 1 || data[i].tournament_number > 100);

        do {
            cout<<"Enter a number of a player in the world rank list: ";
            cin>>data[i].world_number;
            if (data[i].world_number < 1 || data[i].world_number > 100)
                {
                cout<<"Invalid world rank number! Please enter a number between 1 and 100"<<endl;
            }
        } while (data[i].world_number < 1 || data[i].world_number > 100);

        cout<<"Enter the first name of the player: ";
        cin>>data[i].name;

        cout<<"Enter the family of the player: ";
        cin>>data[i].family;

        cout<<"Enter the country of the player: ";
        cin>>data[i].country;

        do {
            cout<<"Enter the current points of the player: ";
            cin>>data[i].curr_points;
            if (data[i].curr_points < 0)
                {
                cout<<"Invalid points! Points must be greater than or equal to 0"<<endl;
            }
        } while (data[i].curr_points < 0);

        do {
            cout<<"Enter the numbers of cups won: ";
            cin>>data[i].first_place;
            if (data[i].first_place < 0)
                {
                cout<<"Invalid number of cups! The number must be greater than or equal to 0"<<endl;
            }
        } while (data[i].first_place < 0);
        cout<<endl;
    }
    br+=n;
}

void display(People data[],int &br)
{
    if(br==0)
    {
        cout<<"No players added yet"<<endl;
        return;
    }
    for(int i=0;i<br;++i)
    {
        cout << "-----------------------" <<endl;
        cout << "Number in the tournament: "<<data[i].tournament_number<<endl;
        cout << "Rank: "<<data[i].world_number<<endl;
        cout << "Full name: "<<data[i].name<< " " <<data[i].family<<endl;
        cout << "Country: "<<data[i].country <<endl;
        cout << "Current points: "<<data[i].curr_points<< endl;
        cout << "Cups won N: "<<data[i].first_place<<endl;
        cout << "-----------------------" <<endl;
        cout << endl;
    }

}

void minCups(People data[],int br)
{
                if (br == 0)
                {
                    cout << "No players added yet" << endl;
                    return;
                }

                int Min = data[0].first_place;
                for (int i = 1; i < br; i++)
                    {
                    if (data[i].first_place < Min)
                     {
                        Min = data[i].first_place;
                     }
                    }

                for (int i = 0; i < br; i++)
                {
                    if (data[i].first_place == Min)
                     {
                        cout << "-----------------------" << endl;
                        cout << "Number in the tournament: " << data[i].tournament_number << endl;
                        cout << "Rank: " << data[i].world_number << endl;
                        cout << "Full name: " << data[i].name << " " << data[i].family << endl;
                        cout << "Current points: " << data[i].curr_points << endl;
                        cout << "Cups won N: " << data[i].first_place << endl;
                        cout << "-----------------------" << endl;
                        cout << endl;
                    }
                }
}

void country(People data[], int br)
{
    if (br == 0)
    {
        cout<<"No players added yet"<<endl;
        return;
    }

    char cntry[30];
    cout<<"Enter a country: ";
    cin>>cntry;
    cout<<endl;
    bool found = false;
    for (int i = 0; i < br; i++)
    {
        if (strcmp(data[i].country, cntry) == 0)
        {
            cout<<"-----------------------" <<endl;
            cout<<"Number in the tournament: "<<data[i].tournament_number<<endl;
            cout<<"Rank: " << data[i].world_number<<endl;
            cout<<"Full name: " << data[i].name<<" "<<data[i].family<<endl;
            cout<<"Country: " << data[i].country<<endl;
            cout<<"Current points: " << data[i].curr_points<<endl;
            cout<<"Cups won N: " << data[i].first_place<<endl;
            cout<<"-----------------------"<<endl;
            cout<< endl;
            found = true;
        }
    }

    if (!found)
    {
        cout<<"There is no player from this country"<<endl;
    }
}

void srch(People data[],int br)
{
     if(br==0)
    {
        cout<<"No players added yet"<<endl;
        return;
    }
    char choice;
    do {
        cout<<"a: Bringing out the players with the fewest won cups"<<endl;
        cout<<endl;
        cout<<"b: Removal of competitors from a certain country"<<endl;
        cout<<endl;
        cout<<"c: Back to main menu"<<endl;
        cout<<endl;
        cout<<"Choose an option: ";
        cin>>choice;

        switch(choice)
         {
            case 'a': cout<<endl;
                 minCups(data,br);
                break;

            case 'b': cout<<endl;
                country(data,br);
            break;

            case 'c': cout<<endl;
                cout<<"Returning to main menu"<<endl;
                        return;
                        break;

            default: cout<<endl;
                cout<<"Choose a valid option"<<endl;
                cout<<endl;
            break;

        }
    }while (choice != 'a' && choice != 'b' && choice != 'c');
}

void sorrt(People data[],int br)
{
     if(br==0)
    {
        cout<<"No players added yet"<<endl;
        return;
    }
    People temp;
    bool swaped=false;
    for(int i=0;i<br-1;i++)
    {
        swaped=false;
        for(int j=0;j<br-i-1;j++)
        {
            if(data[j].world_number>data[j+1].world_number)
            {
                temp=data[j];
                data[j]=data[j+1];
                data[j+1]=temp;
                swaped=true;
            }
        }
        if(swaped==false)
            break;
    }
    cout<<"Players are sorted"<<endl;
}

void saveToFile(People data[], int &br)
{

    ofstream outFile("playerss.dat", ios::binary);
    outFile.write((char*)&br, sizeof(br));
    outFile.write((char*)data, sizeof(People) * br);
    outFile.close();
    cout<<"Data saved to file"<<endl;
}

void loadFromFile(People data[], int &br)
{
    ifstream inFile("playerss.dat", ios::binary);
    if (inFile)
    {
        inFile.read((char*)&br, sizeof(br));
        inFile.read((char*)data, sizeof(People) * br);
        inFile.close();
        cout<<"Data loaded from file"<<endl;
    }
    else
    {
        cout<<"No existing data file found"<<endl;
    }
}

void fileManagement(People data[],int &br)
 {
    char choice;
    do {
        cout<<"File Management Menu"<<endl;
        cout<<endl;
        cout<<"a. Save data to file"<<endl;
        cout<<endl;
        cout<<"b. Load data from file"<<endl;;
        cout<<endl;
        cout<<"c. Back to main menu"<<endl;
        cout<<endl;
        cout<<"Choose an option: ";
        cin>>choice;
        cout<<endl;

        switch (choice)
         {
            case 'a': cout<<endl;
            saveToFile(data,br);
             break;

            case 'b': cout<<endl;
                loadFromFile(data,br);
             break;

            case 'c': cout<<endl;
                cout<<"Returning to main menu"<<endl;
             break;

            default: cout<<endl;
                 cout<<"Choose a valid option"<<endl;
             break;

        }
    } while (choice != 'a' && choice != 'b' && choice != 'c');
}

void sorrt2(People data[],int br)
{
     if(br==0)
    {
        cout<<"No players added yet"<<endl;
        return;
    }
    People temp;
    bool swaped=false;
    for(int i=0;i<br-1;i++)
    {
        swaped=false;
        for(int j=0;j<br-i-1;j++)
        {
            if(data[j].first_place<data[j+1].first_place)
            {
                temp=data[j];
                data[j]=data[j+1];
                data[j+1]=temp;
                swaped=true;
            }
        }
        if(swaped==false)
            break;
    }
    for(int i=0;i<br;i++)
    {
                        cout<<"-----------------------"<<endl;
                        cout<<"Number in the tournament: "<<data[i].tournament_number << endl;
                        cout<<"Rank: " << data[i].world_number<<endl;
                        cout<<"Full name: " << data[i].name<<" "<<data[i].family << endl;
                        cout<<"Country: " << data[i].country<<endl;
                        cout<<"Current points: " << data[i].curr_points<<endl;
                        cout<<"Cups won N: " << data[i].first_place<<endl;
                        cout<<"-----------------------"<<endl;
                        cout<<endl;
    }
}

void countryName(People data[],int br)
{
     if(br==0)
    {
        cout<<"No players added yet"<<endl;
        return;
    }
        char cntry[30],ime[30];
        cout<<"Enter a country"<<": "<< " ";
        cin>>cntry;
        cout<<"Enter first name"<<": "<< " ";
        cin>>ime;
        cout<<endl;

        bool found=false;

        for(int i=0;i<br;i++)
        {
            if(strcmp(data[i].country, cntry)==0 && strcmp(data[i].name, ime)==0)
            {
                        cout<<"-----------------------"<<endl;
                        cout<<"Number in the tournament: "<<data[i].tournament_number<<endl;
                        cout<<"Rank: "<<data[i].world_number<<endl;
                        cout<<"Full name: "<<data[i].name<<" "<<data[i].family<<endl;
                        cout<<"Country: "<<data[i].country<<endl;
                        cout<<"Current points: "<<data[i].curr_points<<endl;
                        cout<<"Cups won N: "<<data[i].first_place<<endl;
                        cout<<"-----------------------"<<endl;
                        cout<<endl;
                        found=true;
            }
        }
            if(!found)
            {
                cout<<"There is no player from this country and with this name"<<endl;
            }
}

void sortIsearch(People data[],int br)
{
     if(br==0)
    {
        cout<<"No players added yet"<<endl;
        return;
    }
    char choice;
    do {
        cout<<"a: Bringing athletes in decreasing order of titles won"<<endl;
        cout<<endl;
        cout<<"b: Search and display of a competitor by country and first name"<<endl;
        cout<<endl;
        cout<<"c: Back to main menu"<<endl;
        cout<<endl;
        cout<<"Choose an option: ";
        cin>>choice;

        switch(choice)
        {
            case 'a': cout<<endl;
                sorrt2(data,br);
                break;

            case 'b': cout<<endl;
                 countryName(data,br);
            break;

            case 'c': cout<<endl;
            cout<<"Returning to main menu"<<endl;
                        break;

            default: cout<<endl;
                cout<<"Choose a valid option"<<endl;
            break;

        }
    }while (choice != 'a' && choice != 'b' && choice != 'c');
}

void conductTournament(People data[], int br)
{
     if(br==0)
     {
        cout<<"No players added yet"<<endl;
        return;
     }

    int round=1;
    int remainingPlayers=br;
    int playerIndexes[br];

    for (int i = 0; i < br; i++)
        {
        playerIndexes[i]=i;
        }

    while(remainingPlayers>2)
        {
            cout<<"Round"<<round<<":"<<endl;
            cout<<endl;

            int winners=0;
            int byeIndex=-1;

            if (remainingPlayers%2 != 0)
                {
                    byeIndex = playerIndexes[0];
                    cout<<"Player "<<data[byeIndex].name<<" "<<data[byeIndex].family<<" gets a bye this round"<<endl;
                    cout<<endl;
                    winners++;
                }

            for (int i=0;i<remainingPlayers;i+= 2)
                {
                    if (i==0 && byeIndex != -1)
                        {
                            i++;
                        }

                if (i + 1 < remainingPlayers)
                    {
                    int player1 = playerIndexes[i];
                    int player2 = playerIndexes[i + 1];

                    cout<<"Match " << (i / 2 + 1)<<":"<<endl;
                    cout<<"Player 1: "<<data[player1].name<< " "<<data[player1].family<<endl;
                    cout<<"Player 2: "<< data[player2].name<< " "<<data[player2].family<<endl;

                    int winner;
                    bool validChoice = false;

                    while (!validChoice)
                        {
                        cout<<"Who will be the winner? Enter 1 for Player 1 or 2 for Player 2: ";
                        cin>>winner;
                        cout<<endl;
                            if(winner==1)
                                {
                                    cout<<"Winner: " <<data[player1].name<< " " <<data[player1].family<<endl;
                                    playerIndexes[winners]=player1;
                                    validChoice = true;

                                }
                                else if(winner == 2)
                                 {
                                    cout<<"Winner: " <<data[player2].name << " " <<data[player2].family<<endl;
                                    playerIndexes[winners] = player2;
                                    validChoice = true;

                                 }
                                 else
                                    {
                                        cout<< "Invalid choice! Please enter 1 or 2"<<endl;
                                    }
                        }

                        winners++;
                    }
                }

            remainingPlayers = winners;
            round++;
        }

    cout<<endl;
    cout<<"Final Match: "<<endl;
    cout<<endl;
    int player1 = playerIndexes[0];
    int player2 = playerIndexes[1];
    cout<<"Player 1: " <<data[player1].name << " " <<data[player1].family<<endl;
    cout<<"Player 2: " <<data[player2].name << " " <<data[player2].family<<endl;
    cout<<endl;
    int winner;
    bool validChoice = false;

    while(!validChoice)
        {
        cout<<"Who will be the winner? Enter 1 for Player 1 or 2 for Player 2: ";
        cin>>winner;
        cout<<endl;
        if (winner==1)
            {
            cout<<endl;
            cout<<"Winner: " <<data[player1].name<< " " <<data[player1].family<<endl;
            data[player1].first_place++;
            validChoice = true;
            }
            else if (winner == 2)
            {
            cout<<endl;
            cout<<"Winner: "<<data[player2].name<< " " <<data[player2].family<<endl;
            data[player2].first_place++;
            validChoice = true;
            }
            else
            {
            cout<<"Invalid choice! Please enter 1 or 2"<<endl;
        }
    }
}

void loadPlayersFromFile(People data[], int &br)
{
     ifstream inFile("players.txt");
    if (!inFile)
    {
        cout<<"The reading file cannot be opened"<<endl;
        return;
    }

    while (inFile >> data[br].tournament_number
           >> data[br].world_number
           >> data[br].name
           >> data[br].family
           >> data[br].country
           >> data[br].curr_points
           >> data[br].first_place)
    {
        br++;
        if (br >= MAX)
            break;
    }
    cout<<"Data is read successfully"<<endl;
    inFile.close();
}

void savePlayersToFile(People data[], int br)
{
    ofstream outFile("players.txt");

    if (!outFile)
    {
        cout<<"The save file cannot be opened"<<endl;
        return;
    }

    for (int i = 0; i < br; i++)
    {
        outFile << data[i].tournament_number << " "
                << data[i].world_number << " "
                << data[i].name << " "
                << data[i].family << " "
                << data[i].country << " "
                << data[i].curr_points << " "
                << data[i].first_place << endl;
    }

    outFile.close();
    cout<<"Data successfully written to the file"<<endl;
}

int main()
{
    int br=0;
    People data[MAX];
    char choice;
    loadPlayersFromFile(data,br);


    do {
        cout<<"---------------- MENU ------------------"<<endl;
        cout<<"1: Add to the players in the tournament"<< endl;
        cout<<"2: Display" << endl;
        cout<<"3: Search" <<endl;
        cout<<"4: Sort by Rank" <<endl;
        cout<<"5: Manage" <<endl;
        cout<<"6: Search" << endl;
        cout<<"7: Matches" << endl;
        cout<<"8: Exit" << endl;
        cout<<"---------- Choose form 1 to 8 ----------"<< endl;
        cout<<endl;
        cout<<"Your choice"<<": "<<" ";
        cin>>choice;
        switch(choice)
         {

            case '1':
                cout<<endl;
                add(data,br);
                cout<<endl;
                break;

            case '2': cout<<endl;
            display(data,br);
                cout<<endl;
                break;

            case '3':
                cout<<endl;
                srch(data,br);
                cout<<endl;
                break;

            case '4':
                cout<<endl;
                sorrt(data,br);
                cout<<endl;
                break;

            case '5':
                cout<<endl;
                fileManagement(data,br);
                cout<<endl;
                break;

            case '6':
                cout<<endl;
                sortIsearch(data,br);
                cout<<endl;
                break;

            case '7': cout<<endl;
            conductTournament(data,br);
                break;

            case '8': cout<<endl;
            cout<<"Good bye"<<endl;
            break;

                default: cout<<"Please choose a valid option form 1 to 8"<<endl;
        }
    } while (choice != '8');

savePlayersToFile(data,br);

    return 0;
}
